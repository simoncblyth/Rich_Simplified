// Include files 



// local
#include "RichTbUpgradeHpdSD.hh"
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

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbUpgradeHpdSD
//
// 2015-05-15 : Sajan Easo
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbUpgradeHpdSD::RichTbUpgradeHpdSD(G4String DetName):G4VSensitiveDetector(DetName),
                                                         HpdSDID(std::vector<G4int>(NumHpds*NumPixelTotInSingleHpd , -1)),HCID(-1)
{

  //  if ((int) collectionName.size() == 0) { 
  //  collectionName.clear();
  //  collectionName.reserve(2);
  // collectionName.push_back(RichTbHColname);
   collectionName.push_back(RichTbHColnameHpd);
   // }
   // G4cout<<" Collection name size in hpdsd "<< (int) collectionName.size()<<G4endl;
   
  RichTbHitCollIndex=0;
  RichTbSDHpdName=DetName;
  


}

//=============================================================================
// Destructor
//=============================================================================
RichTbUpgradeHpdSD::~RichTbUpgradeHpdSD() {} 

//=============================================================================
void RichTbUpgradeHpdSD::Initialize(G4HCofThisEvent*  HCE   ) {
  //   G4cout<<" Now init  RichTbUpgradeSD Hpd "<<G4endl;

     RichTbHitCollectionHpd = new RichTbHitsCollection(SensitiveDetectorName,collectionName[RichTbHitCollIndex]); 

   // RichTbHitCollectionHpd = new RichTbHitsCollection(RichTbSDHpdName,collectionName[RichTbHitCollIndex]);
 
     // G4cout<<" RichTbUpgradeSD : Created RichTbHitCollection with "<< collectionName[RichTbHitCollIndex]  <<G4endl;
  if( HCID < 0 ){
    HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[RichTbHitCollIndex]); 
  }
  
    HCE->AddHitsCollection( HCID, RichTbHitCollectionHpd );    

  for(G4int ipx = 0; ipx < (int) HpdSDID.size(); ipx++){
      HpdSDID[ipx]=-1;
  }
  
  RichTbRunConfig* aRunConfig =  RichTbRunConfig::getRunConfigInstance();
  CurrentHitCreationOption= aRunConfig->getHitCreationOption();

  //   G4cout<<" Now end init  RichTbUpgradeSD Hpd "<<G4endl;


}
                                             
void  RichTbUpgradeHpdSD::EndOfEvent(G4HCofThisEvent*  /* HCE  */){
  //  if( HCID < 0 ){
  //  HCID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[RichTbHitCollIndex]); }
  //  HCE->AddHitsCollection( HCID, RichTbHitCollectionHpd );    

}

G4bool RichTbUpgradeHpdSD::ProcessHits(G4Step*aStep,G4TouchableHistory*ROhist) {

  //  G4cout<<" Now in hpd SD process hits   "<< ROhist <<G4endl;
  
  if(!ROhist) return false;
  G4double edep = aStep->GetTotalEnergyDeposit();
  if(edep < 0.0001) return false;

  G4StepPoint* pPreStepPoint =  aStep->GetPreStepPoint();
  G4TouchableHistory* CurTT =  
    (G4TouchableHistory*)(pPreStepPoint->GetTouchable());
   CurTT -> MoveUpHistory(2);
   G4String curnameVol =  CurTT -> GetVolume()->GetName();
   G4int CurrentHpdNumber= CurTT -> GetVolume() -> GetCopyNo();
   // G4cout<< " RichTbUpgradeSD: Hpd Number name "<<  CurrentHpdNumber <<"  "<<curnameVol<<G4endl;
   G4VPhysicalVolume* ROphysVol = ROhist->GetVolume();
   G4int CurrentPixelNumber = ROphysVol->GetCopyNo();
   G4int CopyId = CurrentPixelNumber + ( CurrentHpdNumber * NumPixelTotInSingleHpd ) ;
  if( (CurrentHitCreationOption==0 &&  HpdSDID[CopyId ] == -1) || 
      (CurrentHitCreationOption==1 )) {

     G4ThreeVector CurGlobalPos =aStep->GetPreStepPoint()->GetPosition();
     G4Navigator* theNavigator =
           G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking();
    
     G4ThreeVector CurLocalPos = theNavigator->GetGlobalToLocalTransform().TransformPoint(CurGlobalPos );
     G4ThreeVector CurLocalPixelCenter = ROphysVol ->GetTranslation() ;
     G4ThreeVector CurGlobalPixelCenter =theNavigator ->GetLocalToGlobalTransform().TransformPoint(CurLocalPixelCenter) ;
     G4ThreeVector CurLocalPosWrtLocalPixelCenter =  CurLocalPos - CurLocalPixelCenter;
     G4bool CurHitInPixelGapFlag = false;
     


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
    if((aTrack->GetDefinition() == RichTbPhotoElectron::PhotoElectron()) &&
       (aCreatorProcessName  == HpdPhotElectProc )) {
    
         aPeOrigin=aTrack->GetVertexPosition();
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
    
    
      RichTbHit* newHit = new RichTbHit();
      newHit->SetEdep( edep );
      newHit->SetPos(CurGlobalPos  );
      newHit->SetCurHPDNum ( CurrentHpdNumber );
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
      
 
      G4int NumHits = RichTbHitCollectionHpd->insert( newHit );
      HpdSDID[CopyId]= NumHits -1 ;
      // newHit->Print();
      
      int verboseLevel=0;
      if( verboseLevel > 0 ) G4cout << "Num hpd Hits stored in this event "<<NumHits<<G4endl;
    

  }
  
  
  return true;  
  
}
                                             
                                             
                                             



void  RichTbUpgradeHpdSD::clear(){} 

void   RichTbUpgradeHpdSD::DrawAll(){ } 

void   RichTbUpgradeHpdSD::PrintAll(){ } 
