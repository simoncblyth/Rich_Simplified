
#include "RichTbPhotonInfo.hh"
#include "globals.hh"
#include "RichTbUserTrackInfo.hh"
#include "RichTbPhotonUserInfoAttach.hh"

void RichTbPMTQWIncidenceInfoAttach(G4Track* aPhTrack, G4ThreeVector aQWPos) 
{
  G4VUserTrackInformation* aUserTrackInfo = aPhTrack->GetUserInformation();
  
  RichTbUserTrackInfo* aRichTbUserTrackInfoPhoton =
    (RichTbUserTrackInfo * ) aUserTrackInfo;

  // G4cout << "in RichTbPMTQW...\t" << aUserTrackInfo 
// 	 << "\t" << aRichTbUserTrackInfoPhoton<< G4endl;
 
  if(aRichTbUserTrackInfoPhoton) 
    {
      if(aRichTbUserTrackInfoPhoton->HasUserPhotonInfo() ) 
	{
	  RichTbPhotonInfo* aRichTbPhotonInfo = 
	    aRichTbUserTrackInfoPhoton->getRichTbPhotonInfo();
	  
	  if( aRichTbPhotonInfo ) 
	    {
	      
	      aRichTbPhotonInfo->setPhotonCoordPMTQWExternal(aQWPos);
	      //G4cout << "Setting HPDQuartz ipmact vector" << G4endl;
	      aRichTbPhotonInfo->BumpPhotonPMTQWMultipleIncidenceFlag();
	      
	    }
	}
    }   
}

void RichTbRadiatorBoundaryInfoAttach(G4Track* aPhTrack, G4ThreeVector aBoundaryPos, G4int RFROption ){
  
  //  RFROption = 0 means total internal reflection happened at this boundary
  //   RFROption = 1 means normal refraction happened at this boundary.
  //    RFROption = 2 means normal reflection happend at this boundary  (mirror reflection)

  //   For nominal signal photons the MultipleIncidenceFlag is bumped three times so that its value=3


  G4VUserTrackInformation* aUserTrackInfo = aPhTrack->GetUserInformation();
  
  RichTbUserTrackInfo* aRichTbUserTrackInfoPhoton =
    (RichTbUserTrackInfo * ) aUserTrackInfo;

  // G4cout << "in RichTbTIR...\t" << aUserTrackInfo 
// 	 << "\t" << aRichTbUserTrackInfoPhoton<< G4endl;
 
  if(aRichTbUserTrackInfoPhoton) 
    {
      if(aRichTbUserTrackInfoPhoton->HasUserPhotonInfo() ){
	  RichTbPhotonInfo* aRichTbPhotonInfo = 
	    aRichTbUserTrackInfoPhoton->getRichTbPhotonInfo();
	  
	  if( aRichTbPhotonInfo ){
      if( RFROption == 0 ){
	      aRichTbPhotonInfo->setPhotonCrystalDnsTIRCoord(aBoundaryPos);
      }else if (RFROption == 1 ) {
	      aRichTbPhotonInfo-> setPhotonCrystalDnsExitCoord (aBoundaryPos);
      } else if ( RFROption == 2 ) {
        aRichTbPhotonInfo-> setPhotonSphMirrReflCoord(aBoundaryPos);
      }
      
	      aRichTbPhotonInfo->BumpPhotonRadiatorMultipleIncidenceFlag();      
        //G4cout<<" RichTbPhotinfo attach RFR option  flag "<< RFROption <<"  "
        //      <<aRichTbPhotonInfo->PhotonRadiatorMultipleIncidenceFlag()<<G4endl;
        
	    }
    
      } 
      
    } 

}



void RichTbRayleighInfoAttach (const G4Track& aPhotonTrack) 
{

   G4VUserTrackInformation* aUserTrackInfo=aPhotonTrack.GetUserInformation();
   RichTbUserTrackInfo* aRichTbUserTrackInfoPhoton =
     (RichTbUserTrackInfo * ) aUserTrackInfo;
   
   if(aRichTbUserTrackInfoPhoton) {

     if(aRichTbUserTrackInfoPhoton->HasUserPhotonInfo() ) {
       RichTbPhotonInfo* aRichTbPhotonInfo = 
         aRichTbUserTrackInfoPhoton->getRichTbPhotonInfo();
       
       if( aRichTbPhotonInfo ) {
         aRichTbPhotonInfo-> BumpNumRaylieghScat();
         
       }       
       
     }
     
     
   }   
   
}

G4Track* RichTbCkvProdInfoAttach(const G4Track& aChTrack,
                                    G4Track* aPhotTrack,
                                    const G4double CkvCosTheta,
                                    const G4double CkvPhi,
                             const G4double CkvPhotEnergy)
{
  //const G4DynamicParticle* aChTrackParticle 
  //             = aChTrack.GetDynamicParticle(); 
  
  RichTbPhotonInfo* aRichTbPhotonInfo = new RichTbPhotonInfo();
  aRichTbPhotonInfo-> setCkvCosThetaAtProd(CkvCosTheta);
  aRichTbPhotonInfo->  setCkvPhiAtProd( CkvPhi);
  aRichTbPhotonInfo->   setCkvPhotonEnergyAtProd(CkvPhotEnergy);
  aRichTbPhotonInfo-> setParentChTrackMomentum(aChTrack.GetDynamicParticle()-> GetTotalMomentum());
  aRichTbPhotonInfo-> setParentChTrackThreeMom(aChTrack.GetMomentum());
  RichTbUserTrackInfo* aRichTbUserTrackInfo =
     new RichTbUserTrackInfo(aRichTbPhotonInfo );
   aPhotTrack->SetUserInformation( aRichTbUserTrackInfo);

   
   //  G4double Lambda = 1243.125*(nanometer*eV)/CkvPhotEnergy*1000000;
   //   G4cout<<" CkvprodInfoAttach Lambda Photonenergy "
   //     <<Lambda<<"   "<<CkvPhotEnergy<<G4endl;
   return  aPhotTrack;
}
