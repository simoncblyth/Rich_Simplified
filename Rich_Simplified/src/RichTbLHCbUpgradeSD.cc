// $Id: $
// Include files



// local
#include "RichTbLHCbUpgradeSD.hh"
#include "RichTbHit.hh"
#include "RichTbGeometryParameters.hh"
#include "globals.hh"
#include "Randomize.hh"
#include "G4Step.hh"
#include "G4HCofThisEvent.hh"
#include "G4Track.hh"
#include "G4SDManager.hh"
#include "G4ios.hh"
#include "G4TouchableHistory.hh"
#include "RichTbRunConfig.hh"
#include "RichTbUserTrackInfo.hh"
#include "RichTbPhotoElectron.hh"
#include "G4TransportationManager.hh"
#include "G4Navigator.hh"
#include "RichTbUserTrackInfo.hh"
#include "G4VProcess.hh"
#include "RichTbMiscNames.hh"
#include "RichTbLHCbUtil.hh"

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbLHCbUpgradeSD::RichTbLHCbUpgradeSD(G4String DetName  )
:G4VSensitiveDetector(DetName), HCID(-1) {
  // Here collectionList 0 is set for hits produced from G4 process
  //      collectionList 1 is set for hits produiced through opticks process

  ResetPmtSDID ();
  collectionName.clear();
  collectionName.reserve(2);
  collectionName.push_back(RichTbLHCbR1G4HColname);
  collectionName.push_back(RichTbLHCbR1OpticksHColname);
  RichTbHitG4CollIndex = 0;
  RichTbHitOpticksCollIndex = 1;
  RichTbLHCbSensDetName = DetName;
  RichTbLHCbCurrNominalPixelEff=1.0;

  // G4cout<<"constructing the sensitive detector "<< RichTbLHCbSensDetName <<G4endl;

}
//=============================================================================
// Destructor
//=============================================================================
RichTbLHCbUpgradeSD::~RichTbLHCbUpgradeSD() {}
//=============================================================================
void RichTbLHCbUpgradeSD::Initialize(G4HCofThisEvent*  HCE )
{

  //	  G4cout<<" Now init  RichTbLHCbUpgradeSD "<<collectionName[0]<<  G4endl;
  //  for now only the hits from G4proc are setup to be collected. 

	RichTbHitCollection = new RichTbHitsCollection(SensitiveDetectorName,collectionName[0]);

	//G4cout<<" In  RichTbLHCbUpgradeSD SensitiveDetectorName "<< SensitiveDetectorName <<G4endl;

	if( HCID < 0 ){
		HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
                // G4cout<<" In  RichTbLHCbUpgradeSD HCID "<< HCID <<G4endl;
	}
	HCE->AddHitsCollection( HCID, RichTbHitCollection );
        //G4cout<<" In  RichTbLHCbUpgradeSD HCID RichTbHitCollection "
        //<< HCID <<"  "<<RichTbHitCollection<< G4endl;
	ResetPmtSDID () ;
        RichTbRunConfig* aRunConfig =  RichTbRunConfig::getRunConfigInstance();
        CurrentHitCreationOption= aRunConfig->getHitCreationOption();
        CurrentPmtPixelGap = RichLbPMTPixelGap;

}

G4bool RichTbLHCbUpgradeSD::ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist) {
 
        //G4cout<<" In  RichTbLHCbUpgradeSD ProceesHits "<<G4endl;

	 if(!ROhist) return false;
       
	G4double edep = aStep->GetTotalEnergyDeposit();
	if(edep < 0.0001) return false;
	// G4cout<<" Now in RichTbLHCbUpgradeSD ProcessHits "<< edep <<G4endl;

	G4StepPoint* pPreStepPoint =  aStep->GetPreStepPoint();
	G4TouchableHistory* CurTT =	(G4TouchableHistory*)(pPreStepPoint->GetTouchable());
	CurTT -> MoveUpHistory(2);
	G4String curnameVol =  CurTT -> GetVolume()->GetName();
	G4int CurrentPmtNumber= CurTT -> GetVolume() -> GetCopyNo();
	G4VPhysicalVolume* ROphysVol = ROhist->GetVolume();
	G4int CurrentPixelNumber = ROphysVol->GetCopyNo();
	//G4int CopyId = CurrentPixelNumber + CurrentPmtNumber * NumPixelTotInPmt;
	//Now for basic setup for pixel efficiency. May be improved inthe future.
        G4double RandPx =  G4UniformRand();
        G4bool aEffOKFlag = (RandPx > RichTbLHCbCurrNominalPixelEff) ? false : true;
        if(!(aEffOKFlag)) return false;
	// End of basic setup for pixel efficiency
        RichTbLHCbUtil* aRichTbLHCbUtil = RichTbLHCbUtil::getRichTbLHCbUtilInstance();
        G4int aModuleNum = aRichTbLHCbUtil -> getModuleNumFromPmtNum(CurrentPmtNumber );
        G4int aPmtNumInModule =    aRichTbLHCbUtil -> getPmtNumInModuleFromPmtNum(  CurrentPmtNumber );
	// G4cout<<" SD Process Hits Module pmt HitCreateOption  "<<  aModuleNum <<"  "<<   aPmtNumInModule 
	//	      << "  "<< CurrentHitCreationOption <<   G4endl; 

	if( (CurrentHitCreationOption==0 && 
             (!(RetrievePmtSDIDBit(aModuleNum,aPmtNumInModule, CurrentPixelNumber)))) ||
	    (CurrentHitCreationOption==1 )) {

		G4ThreeVector CurGlobalPos =aStep->GetPreStepPoint()->GetPosition();
		G4Navigator* theNavigator =
			G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking();

		G4ThreeVector CurLocalPos = 
                         theNavigator->GetGlobalToLocalTransform().TransformPoint(CurGlobalPos );
		G4ThreeVector CurLocalPixelCenter = ROphysVol ->GetTranslation() ;            
		G4ThreeVector CurGlobalPixelCenter =
                   theNavigator ->GetLocalToGlobalTransform().TransformPoint(CurLocalPixelCenter) ;

		G4ThreeVector CurLocalPosWrtLocalPixelCenter =  CurLocalPos - CurLocalPixelCenter;
		G4bool CurHitInPixelGapFlag = false;

		if( fabs((CurLocalPosWrtLocalPixelCenter.x()) > (0.5*(RichLbPMTPixelXSize-CurrentPmtPixelGap)) ) ||
		    fabs((CurLocalPosWrtLocalPixelCenter.y()) > (0.5*(RichLbPMTPixelYSize-CurrentPmtPixelGap)) ) ) 
                    CurHitInPixelGapFlag=true;



		G4Track* aTrack = aStep->GetTrack();
		G4ThreeVector aPeOrigin;
		G4ThreeVector aPhOrigin;
		G4double aCkvCosTh=0.0;
		G4double aCkvPhi=0.0;
		G4double aPhEner=0.0;
		G4ThreeVector aPeOrginInPhSup;
		G4ThreeVector aPhEmisDir;
		G4int  aMultReflFlag =0;
		G4double aChTrackMom = 0.0;
		G4ThreeVector aChTrackThreeMom;
		G4int aHitInPixelGapFlag=  CurHitInPixelGapFlag ? 1  : 0   ;
		G4String aCreatorProcessName = "NullProcess";

		const G4VProcess* aProcess = aTrack->GetCreatorProcess();
		if(aProcess) aCreatorProcessName = aProcess->GetProcessName();
                // G4cout<<" SD Creator proc "<< aCreatorProcessName <<G4endl;
		if((aTrack->GetDefinition() == RichTbPhotoElectron::PhotoElectron()) &&
				(aCreatorProcessName  == PmtLHCbPhotElectProc )) {


			aPeOrigin=aTrack->GetVertexPosition();


			G4VUserTrackInformation* aUserTrackinfo=aTrack->GetUserInformation();
                        // G4cout<<"SD User track info " <<aUserTrackinfo <<G4endl;

			if(  aUserTrackinfo )
			{
				RichTbUserTrackInfo* aPeTrackUserInfo=  (RichTbUserTrackInfo*) aUserTrackinfo ;
				if(aPeTrackUserInfo && aPeTrackUserInfo->HasUserPEInfo()){

					// G4cout<<" Now get pe user track info " <<aPeTrackUserInfo<<G4endl;

					RichTbPEInfo* aPeInfo = aPeTrackUserInfo->getRichTbPEInfo();

					if(aPeInfo){
						aPhOrigin= aPeInfo -> PhOrigin();
						aPeOrginInPhSup=aPeInfo -> PeOriginInHpdSupFrame();
						aPhEmisDir=  aPeInfo-> getPhotEmisDir();

						RichTbPhotonInfo* aPhotonInfo = aPeInfo ->  MotherPhotonInfo();
						if( aPhotonInfo ){
							aCkvCosTh = aPhotonInfo->CkvCosThetaAtProd();
							aCkvPhi   = aPhotonInfo->CkvPhiAtProd();
							aPhEner   = aPhotonInfo->CkvPhotonEnergyAtProd() ;
							aMultReflFlag =  aPhotonInfo->PhotonRadiatorMultipleIncidenceFlag();
							aChTrackMom = aPhotonInfo-> ParentChTrackMomentum();
							aChTrackThreeMom = aPhotonInfo->ParentChTrackThreeMom();


						}



					}



				}
			
			}
		}

		RichTbHit* newHit = new RichTbHit();
		newHit->SetEdep( edep );
		newHit->SetPos(CurGlobalPos  );
		newHit->SetCurPMTNum ( CurrentPmtNumber );
		newHit->SetCurPixNum (CurrentPixelNumber   );
		newHit -> SetLocalPos(  CurLocalPos);
		newHit->SetPeOrigin( aPeOrigin );
		newHit->SetPhotonOrigin( aPhOrigin );
		newHit->SetCkvCosThetaProd( aCkvCosTh );
		newHit->SetCkvPhiProd( aCkvPhi );
		newHit->SetCkvEnergyProd( aPhEner );
		newHit->SetPeOriginInPhSupport( aPeOrginInPhSup );
		newHit->SetPhEmissionDir( aPhEmisDir );
		newHit->SetPixelLocalCenter(CurLocalPixelCenter);
		newHit->SetPixelGlobalCenter(CurGlobalPixelCenter);
		newHit->SetMultipleReflFlag(aMultReflFlag);
		newHit->SetChTrackTotMom(aChTrackMom);
		newHit->SetChTrackThreeMom(aChTrackThreeMom);
		newHit->SetHitInPixelGapFlag(aHitInPixelGapFlag );

		//G4int NumHits = RichTbHitCollection->insert( newHit );
		RichTbHitCollection->insert( newHit );
                SetPmtSDIDBit(aModuleNum,aPmtNumInModule,CurrentPixelNumber );
		// G4cout <<" RichTbLHCbUpgradeSD New hit stored " <<G4endl;


		}

	return true;

}
void  RichTbLHCbUpgradeSD::EndOfEvent(G4HCofThisEvent* /* HCE  */){

}
void RichTbLHCbUpgradeSD::ResetPmtSDID () {
  RichTbR1PmtSDID.clear();
  RichTbR1PmtSDID.resize(RichTbLbNumModules,
			 std::vector<int64_t> (RichTbLbNumPmtInModule,0));
}
void RichTbLHCbUpgradeSD::SetPmtSDIDBit( int aM, int aP, int aPix ) {
  (RichTbR1PmtSDID [aM] [aP]) |= (1LL << aPix );

}

bool RichTbLHCbUpgradeSD::RetrievePmtSDIDBit( int aM, int aP , int aPix ) {
  return ( (RichTbR1PmtSDID [aM] [aP]) & (1LL << aPix )  );
}

void  RichTbLHCbUpgradeSD::clear(){}

void   RichTbLHCbUpgradeSD::DrawAll(){ }

void   RichTbLHCbUpgradeSD::PrintAll(){ }
