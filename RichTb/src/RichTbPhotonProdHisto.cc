#include "RichTbMaterialParameters.hh"
#include "RichTbPhotonProdHisto.hh"
#include "RichTbGeometryParameters.hh"
#include "RichTbCounter.hh"


void  RichTbPhotonProductionHisto (const  G4Track& /* aChTrack */,
                                    const G4Track* aPhotTrack,
                                   const G4double /* CkvCosTh */, 
                                   const G4double /* CkvPhi */,
                                        const G4double  CkvPhEner) {


  //  G4cout<<"begin RichTbPhotonProductionHisto "<<G4endl;
  
  //  RichTbCounter* rCounter = RichTbCounter::getRichTbCounterInstance();

  // G4double PhotWLength=0.0;
  //  G4double PhotWLengthNano=0.0;
  
  if(  CkvPhEner != 0.0 ) {
    
    // PhotWLength=PhotMomToWaveLength/ CkvPhEner ;
  // PhotWLengthNano =   PhotWLength/(nanometer);
  }
  // G4double CkvTh = acos( CkvCosTh);

 // G4cout<<" RichTbPhotonProductionHisto Photwlen Phener ckvth ckv phi "
 //     <<  PhotWLengthNano<<"  "<< CkvTh<<"  "<<CkvPhi
 //     <<G4endl;
 

 // G4String curVolName= aChTrack.GetVolume()->GetName();
 // G4String curMatName= aChTrack.GetMaterial()->GetName();
 //G4String curVolFirstPart =
 //           (curVolName.length() >= 7) ? curVolName(0,7):curVolName;

 //  G4cout<<" RichTbPhotonProductionHisto Cur Vol "
 //       <<  curVolName <<"  "<<  curVolFirstPart <<G4endl;
  
 G4ThreeVector avPos= aPhotTrack->GetVertexPosition() ;
 // if( avPos.z() >= 0.0  && avPos.z() <= MirrrorNominalPivotZLocationInGlobal ) {
 // rCounter->bumpnumHitTotProd();
   
 // }
 



 //  }

      
 

  //  G4cout<<"end RichTbPhotonProductionHisto "<<G4endl;
     
}
