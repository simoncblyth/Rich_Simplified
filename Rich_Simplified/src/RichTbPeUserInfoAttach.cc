// $Id: $
// Include files 



// local
#include "RichTbUserTrackInfo.hh"
#include "RichTbPeUserInfoAttach.hh"
G4Track*  RichTbPeInfoAttach( const G4Track& aPhotonTk, G4Track* aPETk,
   G4ThreeVector aPeOriginInPhSup) 
{
   G4VUserTrackInformation* aTkInfo=aPhotonTk.GetUserInformation();
   RichTbUserTrackInfo* curPhotTrackUserInfo=
                  (RichTbUserTrackInfo*)  aTkInfo;

   G4ThreeVector CurPhotonOrigin = aPhotonTk.GetVertexPosition();
   G4ThreeVector CurPhotonEmisDir = aPhotonTk.GetVertexMomentumDirection();
   RichTbPEInfo* aRichTbPEInfo =new RichTbPEInfo();
   
   if(curPhotTrackUserInfo && curPhotTrackUserInfo->HasUserPhotonInfo() ) {
       RichTbPhotonInfo* aRichTbPhotonInfo = 
         curPhotTrackUserInfo->getRichTbPhotonInfo();
   aRichTbPEInfo-> setPhOrigin(CurPhotonOrigin);
   aRichTbPEInfo-> setPhotEmisDir(CurPhotonEmisDir);
   aRichTbPEInfo->setMotherPhotonInfo(aRichTbPhotonInfo);
   aRichTbPEInfo->setPeOriginInHpdSupFrame(aPeOriginInPhSup);
   
  }

   RichTbUserTrackInfo* curPeTrackUserInfo=
     new  RichTbUserTrackInfo( aRichTbPEInfo);
   
   aPETk->SetUserInformation(curPeTrackUserInfo);
   
   return  aPETk;
   
}

G4Track* RichTbPeBckAttach( const G4Track& aPhotonTk, G4Track* aSecPETrack ) {
  
   G4VUserTrackInformation* aTkInfo=aPhotonTk.GetUserInformation();
   RichTbUserTrackInfo* curPhotTrackUserInfo=
                  (RichTbUserTrackInfo*)  aTkInfo;

   G4ThreeVector CurPhotonOrigin = aPhotonTk.GetVertexPosition();
   G4ThreeVector CurPhotonEmisDir = aPhotonTk.GetVertexMomentumDirection();
   RichTbPEInfo* aRichTbPEInfo =new RichTbPEInfo();
   
   if(curPhotTrackUserInfo && curPhotTrackUserInfo->HasUserPhotonInfo() ) {
       RichTbPhotonInfo* aRichTbPhotonInfo = 
         curPhotTrackUserInfo->getRichTbPhotonInfo();
   aRichTbPEInfo-> setPhOrigin(CurPhotonOrigin);
   aRichTbPEInfo-> setPhotEmisDir(CurPhotonEmisDir);
   aRichTbPEInfo->setMotherPhotonInfo(aRichTbPhotonInfo);
   //aRichTbPEInfo->setPeOriginInHpdSupFrame(aPeOriginInPhSup);
   
  }

   RichTbUserTrackInfo* curPeTrackUserInfo=
     new  RichTbUserTrackInfo( aRichTbPEInfo);
   
   aSecPETrack ->SetUserInformation(curPeTrackUserInfo);
   
   return  aSecPETrack ;



}
