// $Id: $
// Include files



// local
#include "RichTbUpgradeSD.hh"
#include "RichTbHit.hh"
#include "RichTbGeometryParameters.hh"
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
#include "RichTbPmtPixelEfficiency.hh"

#include "OpHit.hh"
#include "CLHEP/Units/PhysicalConstants.h"
#ifdef WITH_OPTICKS
#include "G4Opticks.hh"
#endif
//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbUpgradeSD::RichTbUpgradeSD(G4String DetName  )
:G4VSensitiveDetector(DetName),
 PmtSDID(std::vector<G4int>( NumPmts*NumPixelTotInPmt,-1)),HCID(-1) {
//	 PmtSDID(std::vector<G4int>( RichTbPMTGeometryParameters::getNumPmts()*NumPixelTotInPmt,-1)),HCID(-1) { //TESTnumPmts

	collectionName.clear();
	collectionName.reserve(1);
	collectionName.push_back(RichTbHColname);
	//collectionName.push_back(RichTbHColnameHpd);
	RichTbHitCollIndex=0;
	RichTbSensDetName= DetName;

	//	G4cout<<"constructing the sensitive detector "<< RichTbSensDetName << G4endl;
}

//=============================================================================
// Destructor
//=============================================================================
RichTbUpgradeSD::~RichTbUpgradeSD() {}
//=============================================================================

void RichTbUpgradeSD::Initialize(G4HCofThisEvent*  HCE )
{

        G4cout<<" Now init  RichTbUpgradeSD "<< " HCE " << HCE << " HCE.Capacity  " << HCE->GetCapacity() << " SensitiveDetectorName " << RichTbSensDetName << " collectionName " << collectionName[0]<<  G4endl;


	//RichTbHitCollection = new RichTbHitsCollection(SensitiveDetectorName,collectionName[0]);
	RichTbHitCollection = new OpHitCollection(SensitiveDetectorName,collectionName[0]);

	// RichTbHitCollection = new RichTbHitsCollection(RichTbSensDetName,collectionName[0]);

	//	 G4cout<<" RichTbUpgradeSD : Created RichTbHitCollection with "<< collectionName[0]  <<G4endl;

	if( HCID < 0 ){
		HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);
	}
	//  G4cout<<" RichTbUpgradeSD : HCID "<<HCID<<G4endl;

	HCE->AddHitsCollection( HCID, RichTbHitCollection );

	// G4cout<<" RichTbUpgradeSD : HCID hitcolladded "<<HCID<<G4endl;


	for(G4int ipx = 0; ipx < (int) PmtSDID.size(); ipx++)
	{
		PmtSDID[ipx]=-1;
	}

	RichTbRunConfig* aRunConfig =  RichTbRunConfig::getRunConfigInstance();
	CurrentHitCreationOption= aRunConfig->getHitCreationOption();
	// CurrentPmtPixelGap = aRunConfig-> getMapmtPixelGap();
	CurrentPmtPixelGap = RichTbPmtPixelGap;

	G4cout<<" Now end init  RichTbUpgradeSD "<<G4endl;

}
void  RichTbUpgradeSD::EndOfEvent(G4HCofThisEvent* /* HCE  */){
	//  if( HCID < 0 ){
	//  HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]); }
	//  HCE->AddHitsCollection( HCID, RichTbHitCollection );


}
G4bool RichTbUpgradeSD::ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist)
{

        G4cout<<" Now in Process Hits Pmt SD "<<G4endl;

	if(!ROhist) return false;




	G4double edep = aStep->GetTotalEnergyDeposit();
	if(edep < 0.0001) return false;
	G4StepPoint* pPreStepPoint =  aStep->GetPreStepPoint();
	G4TouchableHistory* CurTT =	(G4TouchableHistory*)(pPreStepPoint->GetTouchable());
	CurTT -> MoveUpHistory(2);
	G4String curnameVol =  CurTT -> GetVolume()->GetName();
	G4int CurrentPmtNumber= CurTT -> GetVolume() -> GetCopyNo();
	
        G4cout<< " RichTbUpgradeSD: PMT Number name "<<  CurrentPmtNumber <<"  "<<curnameVol<<G4endl;
	
        G4VPhysicalVolume* ROphysVol = ROhist->GetVolume();
	G4int CurrentPixelNumber = ROphysVol->GetCopyNo();
	G4int CopyId = CurrentPixelNumber + CurrentPmtNumber * NumPixelTotInPmt;

	// now apply pixel efficiency when the flag to activate this efficiency is set to true.

	RichTbPmtPixelEfficiency* aPixelEff = RichTbPmtPixelEfficiency::getRichTbPmtPixelEfficiencyInstance();
	if(!(  aPixelEff -> PmtPixelEffOK (CurrentPmtNumber,CurrentPixelNumber )) ) return false;

	// end apply pixel eff

	if( (CurrentHitCreationOption==0 &&  PmtSDID[CopyId ] == -1) ||
			(CurrentHitCreationOption==1 ))
	{
		G4ThreeVector CurGlobalPos =aStep->GetPreStepPoint()->GetPosition();
		G4Navigator* theNavigator =
				G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking();

		G4ThreeVector CurLocalPos = theNavigator->GetGlobalToLocalTransform().TransformPoint(CurGlobalPos );
		// G4int CopyId =  CurrentPmtNumber;

		G4ThreeVector CurLocalPixelCenter = ROphysVol ->GetTranslation() ;
		G4ThreeVector CurGlobalPixelCenter =theNavigator ->GetLocalToGlobalTransform().TransformPoint(CurLocalPixelCenter) ;

		G4ThreeVector CurLocalPosWrtLocalPixelCenter =  CurLocalPos - CurLocalPixelCenter;
		G4bool CurHitInPixelGapFlag = false;

		if( fabs((CurLocalPosWrtLocalPixelCenter.x()) > (0.5*(PmtAnodePixelXSize-CurrentPmtPixelGap)) ) ||
				fabs((CurLocalPosWrtLocalPixelCenter.y()) > (0.5*(PmtAnodePixelYSize-CurrentPmtPixelGap)) ) ) CurHitInPixelGapFlag=true;



		
     // test print start
		//  G4cout<<" Sensdet pmt num pixel num copyid "<< CurrentPmtNumber <<"  "
		//   <<  CurrentPixelNumber  <<" "<<CopyId<<G4endl;

		// G4cout<<" Sensdet pixelcenter global local globalpixelcenter pos "<< CurLocalPixelCenter <<"  "<<CurGlobalPos <<"  "
		//  <<CurLocalPos<<" "<<CurGlobalPixelCenter<< "   "<<CurLocalPosWrtLocalPixelCenter<<   G4endl;

		//    G4cout<<" Sensdet pixelcenter global local globalpixelcenter pos differtpixel  gapflag  "<< CurLocalPixelCenter <<"  "<<CurGlobalPos <<"  "
		// <<CurLocalPos<<" "<<CurGlobalPixelCenter<< "   "<<CurLocalPosWrtLocalPixelCenter<<"  "
		//  << CurHitInPixelGapFlag<< G4endl;

    // test print end
		 

		G4Track* aTrack = aStep->GetTrack();
		G4ThreeVector aPeOrigin;
		G4ThreeVector aPhOrigin;
		G4double aCkvCosTh=0.0;
		G4double aCkvPhi=0.0;
		G4double aPhEner=0.0;
		G4ThreeVector aPeOrginInPhSup;
		G4ThreeVector aPhEmisDir;
		G4ThreeVector aTIRCoord ;
		G4ThreeVector aMIRCoord ;
		G4ThreeVector aRFRCoord ;
		G4int  aMultReflFlag =0;
		G4double aChTrackMom = 0.0;
		G4ThreeVector aChTrackThreeMom;
		G4int aHitInPixelGapFlag=  CurHitInPixelGapFlag ? 1  : 0   ;

		G4String aCreatorProcessName = "NullProcess";

		const G4VProcess* aProcess = aTrack->GetCreatorProcess();
		if(aProcess) aCreatorProcessName = aProcess->GetProcessName();
		// G4cout<<" Upgrade SD creator proc "<<aCreatorProcessName <<G4endl;


		if((aTrack->GetDefinition() == RichTbPhotoElectron::PhotoElectron()) &&
				(aCreatorProcessName  == PmtPhotElectProc )) {


			aPeOrigin=aTrack->GetVertexPosition();
			//G4cout<<" Upgrade SD Now get pe origin "<<  aPeOrigin <<G4endl;


			G4VUserTrackInformation* aUserTrackinfo=aTrack->GetUserInformation();
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
							aTIRCoord = aPhotonInfo-> PhotonCrystalDnsTIRCoord();
							aMIRCoord = aPhotonInfo-> PhotonSphMirrReflCoord();
							aRFRCoord = aPhotonInfo-> PhotonCrystalDnsExitCoord();
							aMultReflFlag =  aPhotonInfo->PhotonRadiatorMultipleIncidenceFlag();
							aChTrackMom = aPhotonInfo-> ParentChTrackMomentum();
							aChTrackThreeMom = aPhotonInfo->ParentChTrackThreeMom();


						}



					}



				}




			}



		}


		/*
    G4cout<<" Upgrade SD PeOrgin aPeOrginInPhSup CkvTh  aPhOrigin phener "<<  aPeOrigin <<"   "
          << aPeOrginInPhSup <<"   "<<aCkvCosTh<<"  "<< aPhOrigin<<"  "<<  aPhEner<<G4endl;
		 */
		//G4cout<<" RichTbSD : Mulrefl flag "<< aMultReflFlag <<G4endl;


		/* RichTbHit* newHit = new RichTbHit();
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
		newHit->SetTIRRadiatorCoord(aTIRCoord);
		newHit->SetMIRRadiatorCoord(aMIRCoord);
		newHit->SetRFRRadiatorCoord(aRFRCoord);
		newHit->SetMultipleReflFlag(aMultReflFlag);
		newHit->SetChTrackTotMom(aChTrackMom);
		newHit->SetChTrackThreeMom(aChTrackThreeMom);
		newHit->SetHitInPixelGapFlag(aHitInPixelGapFlag );


		G4int NumHits = RichTbHitCollection->insert( newHit );

		PmtSDID[CopyId]= NumHits -1 ;
		*/
                //int verboseLevel=0;
		//	if( verboseLevel > 0 ) G4cout << "NumHits from pmt stored in this event "<<NumHits<<G4endl;
		//	if( verboseLevel = 0 ) G4cout << "NumHits from pmt stored in this event "<<NumHits<<G4endl;
	}

#ifdef WITH_OPTICKS
    {
        G4double time = pPreStepPoint->GetGlobalTime();
        const G4ThreeVector& pos = pPreStepPoint->GetPosition();
        const G4ThreeVector& dir = pPreStepPoint->GetMomentumDirection();
        const G4ThreeVector& pol = pPreStepPoint->GetPolarization();

        G4double energy = pPreStepPoint->GetKineticEnergy();
        G4double wavelength = CLHEP::h_Planck*CLHEP::c_light/energy;
        G4double weight = 1.0 ;
        G4int flags_x = 0 ;
        G4int flags_y = 0 ;
        G4int flags_z = 0 ;
        G4int flags_w = 0 ;

        G4Opticks::Get()->collectHit(
             pos.x()/CLHEP::mm,
             pos.y()/CLHEP::mm,
             pos.z()/CLHEP::mm,
             time/CLHEP::ns,

             dir.x(),
             dir.y(),
             dir.z(),
             weight,

             pol.x(),
             pol.y(),
             pol.z(),
             wavelength/CLHEP::nm,

             flags_x,
             flags_y,
             flags_z,
             flags_w
        );
    
    OpHit* hit = new OpHit ;
    hit->ene = edep ;
    hit->tim = time ;
    hit->pos = pos ;
    hit->dir = dir ;
    hit->pol = pol ;

    OpHitCollection* hc = RichTbHitCollection ;
    hc->insert(hit);
    G4cout << " edep " << edep << " time " << time << " pos " << pos << G4endl;
    }
#endif


    return true;
}


void  RichTbUpgradeSD::clear(){}

void   RichTbUpgradeSD::DrawAll(){ }

void   RichTbUpgradeSD::PrintAll(){ }

