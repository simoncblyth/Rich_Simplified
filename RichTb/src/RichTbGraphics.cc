#include <iostream>
#include "RichTbGeometryParameters.hh"
#include "RichTbMaterial.hh"
#include "RichTbGraphics.hh"
#include "G4LogicalVolume.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "RichTbRunConfig.hh"
#include "RichTbPMT.hh"

RichTbGraphics::RichTbGraphics()
{
	;
}


RichTbGraphics::RichTbGraphics(RichTbDetectorConstruction* aDetector ){



	curDetector = aDetector;
  curRichTbGraphicsAuxA= new  RichTbGraphicsAuxA(aDetector);
  
 	RichTbRunConfig* aRunConfig=  RichTbRunConfig::getRunConfigInstance();
	G4int aRadiatorConfiguration =  aRunConfig ->getRadiatorConfiguration();
  G4int aGraphicsConfig =  aRunConfig -> getBatchModeFlag();
  if(aGraphicsConfig == 0 ){
    
	//now for the RichTbHall.

	  setRichTbHallGraphicsAttibutes();


    if( aRadiatorConfiguration  == 10 ){

    // for the 2017 crystal geometry

      curRichTbGraphicsAuxA -> setGraphicsAuxAttributes();
    
    
   } else {

  	  setAllGraphicsAttributes();
   }

  }
  
  
}


RichTbGraphics::~RichTbGraphics(){ }

void RichTbGraphics::setAllGraphicsAttributes(){

	//now for the RichTbHall.

  //	setRichTbHallGraphicsAttibutes();


  // now for the rest of the geometry until 2016 data

  setRichTbDetectorGeometryGraphicsAttributes();
  setRichTbDetectorGeometryPhDetGraphicsAttributes();



}






void RichTbGraphics::setRichTbHallGraphicsAttibutes()
{

	// For Following variables on visibility
	//  0 means make the volume invisible;
	//                        1 means make it visible as a solid.
	//                        2 means make it visible as a wireframe.

	RichTbRunConfig* aRunConfig=  RichTbRunConfig::getRunConfigInstance();
	//G4int aRadiatorConfiguration =  aRunConfig ->getRadiatorConfiguration();


	G4int RichTbHall_vis = aRunConfig->getRichTbHall_visib();

	if(  (curDetector != 0)  && (curDetector->getRichTbHall() != 0) ) {

		G4LogicalVolume *RichTbHall_LV =curDetector->getRichTbHall()
                    				 ->getRichTbHallLogicalVolume();

		if( RichTbHall_LV != 0 ) {

			if (RichTbHall_vis == 0) {
				RichTbHall_LV->SetVisAttributes(G4VisAttributes::Invisible);
			} else {
				G4VisAttributes *RichTbHall_LogVisAtt =
						new G4VisAttributes(G4Colour(0., 1., 1.));
				if (RichTbHall_vis == 2) {
					RichTbHall_LogVisAtt->SetForceSolid(false);
					RichTbHall_LogVisAtt->SetForceWireframe(true);
				}
				if (RichTbHall_vis == 1) {
					RichTbHall_LogVisAtt->SetForceSolid(true);
				}
				RichTbHall_LogVisAtt->SetVisibility(true);
				RichTbHall_LV->SetVisAttributes(RichTbHall_LogVisAtt);
				//
			}
		}

	}
}




void RichTbGraphics::setRichTbDetectorGeometryGraphicsAttributes() {

	// For Following variables on visibility
	//  0 means make the volume invisible;
	//                        1 means make it visible as a solid.
	//                        2 means make it visible as a wireframe.

	RichTbRunConfig* aRunConfig=  RichTbRunConfig::getRunConfigInstance();
	G4int aRadiatorConfiguration =  aRunConfig ->getRadiatorConfiguration();


	// now for the vessel

	G4int RichTbUpgradeVessel_vis = aRunConfig->getRichTbUpgradeVessel_visib();
	// G4cout<<"vessel visib flag  "<<RichTbUpgradeVessel_vis<<G4endl;

	if(  (curDetector != 0)  && (curDetector-> getRichTbUpgradeVessel() != 0))
	{
		//    G4cout<<"now setting vessel visb options  "<<RichTbUpgradeVessel_vis<<G4endl;

		G4LogicalVolume * RichTbUpgradeVessel_LV =curDetector->
				getRichTbUpgradeVessel()-> getRichTbGasVesselLVol();
		if(RichTbUpgradeVessel_LV != 0 ) {
			if(RichTbUpgradeVessel_vis == 0 ) {
				RichTbUpgradeVessel_LV ->SetVisAttributes(G4VisAttributes::Invisible);
			} else {
				G4VisAttributes * RichTbUpgradeVessel_LogVisAtt =
						new G4VisAttributes(G4Colour(0.5,0.5,0.0));
				if(RichTbUpgradeVessel_vis == 2 ) {
					RichTbUpgradeVessel_LogVisAtt ->SetForceSolid(false);
					RichTbUpgradeVessel_LogVisAtt ->SetForceWireframe(true);
				}
				if(RichTbUpgradeVessel_vis == 1 ) {
					RichTbUpgradeVessel_LogVisAtt ->SetForceSolid(true);
				}
				RichTbUpgradeVessel_LogVisAtt->SetVisibility(true);
				RichTbUpgradeVessel_LV -> SetVisAttributes(RichTbUpgradeVessel_LogVisAtt);

			}

		}

	}
  

	//G4int aRadiatorConfiguration =
	//  aRunConfig ->getRadiatorConfiguration();

	if(aRadiatorConfiguration == 0){


		// now for the crystal

		G4int RichTbCrystal_vis = aRunConfig->getRichTbCrystal_visib();
		G4cout<<"Crystal visib flag  "<<RichTbCrystal_vis<<G4endl;

		if(  (curDetector != 0)  && (curDetector-> getRichTbCrystal() != 0))
		{
			G4cout<<"now setting crystal visib options  "<<RichTbCrystal_vis<<G4endl;

			G4LogicalVolume * RichTbCrystal_LV =curDetector->
					getRichTbCrystal()-> getRichTbCrystalLVol();
			if(RichTbCrystal_LV != 0 ) {
				if(RichTbCrystal_vis == 0 ) {
					RichTbCrystal_LV ->SetVisAttributes(G4VisAttributes::Invisible);
				} else {
					G4VisAttributes * RichTbCrystal_LogVisAtt =
							new G4VisAttributes(G4Colour(1.,0.0,0.0));
					if(RichTbCrystal_vis == 2 ) {
						RichTbCrystal_LogVisAtt ->SetForceSolid(false);
						RichTbCrystal_LogVisAtt ->SetForceWireframe(true);
						G4cout<<"test crystal vis "<<RichTbCrystal_vis<<G4endl;
					}
					if(RichTbCrystal_vis == 1 ) {
						RichTbCrystal_LogVisAtt ->SetForceSolid(true);
					}
					RichTbCrystal_LogVisAtt->SetVisibility(true);
					RichTbCrystal_LV -> SetVisAttributes(RichTbCrystal_LogVisAtt);

				}

			}

		}
    

		// now for the crystal cover

		G4int RichTbCrystalCover_vis = aRunConfig->getRichTbCrystalCover_visib();
		G4cout<<"Crystal cover visib flag  "<<RichTbCrystalCover_vis<<G4endl;

		if(  (curDetector != 0)  && (curDetector-> getRichTbCrystalCover() != 0))
		{
			G4cout<<"now setting crystal visb options  "<<RichTbCrystalCover_vis<<G4endl;

			G4LogicalVolume * RichTbCrystalCover_LV =curDetector->
					getRichTbCrystalCover()-> getRichTbCrystalCoverLVol();
			if(RichTbCrystalCover_LV != 0 ) {
				if(RichTbCrystalCover_vis == 0 ) {
					RichTbCrystalCover_LV ->SetVisAttributes(G4VisAttributes::Invisible);
				} else {
					G4VisAttributes * RichTbCrystalCover_LogVisAtt =
							new G4VisAttributes(G4Colour(0.0,0.0,1.0));
					if(RichTbCrystalCover_vis == 2 ) {
						RichTbCrystalCover_LogVisAtt ->SetForceSolid(false);
						RichTbCrystalCover_LogVisAtt ->SetForceWireframe(true);
						G4cout<<"test crystal cover vis "<<RichTbCrystalCover_vis<<G4endl;
					}
					if(RichTbCrystalCover_vis == 1 ) {
						RichTbCrystalCover_LogVisAtt ->SetForceSolid(true);
					}
					RichTbCrystalCover_LogVisAtt->SetVisibility(true);
					RichTbCrystalCover_LV -> SetVisAttributes(RichTbCrystalCover_LogVisAtt);

				}

			}

		}
    

		// now for the lens

		G4int RichTbLens_vis = aRunConfig->getRichTbLens_visib();
		G4cout<<"Lens visib flag  "<<RichTbLens_vis<<G4endl;

		if(  (curDetector != 0)  && (curDetector-> getRichTbLens() != 0))
		{
			G4cout<<"now setting lens visb options  "<<RichTbLens_vis<<G4endl;

			G4LogicalVolume * RichTbLens_LV =curDetector->
					getRichTbLens()-> getRichTbLensLVol();
			if(RichTbLens_LV != 0 ) {
				if(RichTbLens_vis == 0 ) {
					RichTbLens_LV ->SetVisAttributes(G4VisAttributes::Invisible);
				} else {
					G4VisAttributes * RichTbLens_LogVisAtt =
							new G4VisAttributes(G4Colour(1.,0.0,0.0));
					if(RichTbLens_vis == 2 ) {
						RichTbLens_LogVisAtt ->SetForceSolid(false);
						RichTbLens_LogVisAtt ->SetForceWireframe(true);
						G4cout<<"test lens vis "<<RichTbLens_vis<<G4endl;
					}
					if(RichTbLens_vis == 1 ) {
						RichTbLens_LogVisAtt ->SetForceSolid(true);
					}
					RichTbLens_LogVisAtt->SetVisibility(true);
					RichTbLens_LV -> SetVisAttributes(RichTbLens_LogVisAtt);

				}

			}

		}

	}
	else{

		// now for the radiator

		G4int RichTbUpgradeRadiator_vis = aRunConfig->getRichTbUpgradeRadiator_visib();
		G4cout<<"Radiator visib flag  "<<RichTbUpgradeRadiator_vis<<G4endl;

		if(  (curDetector != 0)  && (curDetector-> getRichTbUpgradeRadiator() != 0))
		{
			G4cout<<"now setting radiator visb options  "<<RichTbUpgradeRadiator_vis<<G4endl;

			G4LogicalVolume * RichTbUpgradeRadiator_LV =curDetector->
					getRichTbUpgradeRadiator()-> getRichTbUpgradeRadiatorLVol();
			if(RichTbUpgradeRadiator_LV != 0 ) {
				if(RichTbUpgradeRadiator_vis == 0 ) {
					RichTbUpgradeRadiator_LV ->SetVisAttributes(G4VisAttributes::Invisible);
				} else {
					G4VisAttributes * RichTbUpgradeRadiator_LogVisAtt =
							new G4VisAttributes(G4Colour(0.7,0.1,0.4));
					if(RichTbUpgradeRadiator_vis == 2 ) {
						RichTbUpgradeRadiator_LogVisAtt ->SetForceSolid(false);
						RichTbUpgradeRadiator_LogVisAtt ->SetForceWireframe(true);
						G4cout<<"test radiator vis "<<RichTbUpgradeRadiator_vis<<G4endl;
					}
					if(RichTbUpgradeRadiator_vis == 1 ) {
						RichTbUpgradeRadiator_LogVisAtt ->SetForceSolid(true);
					}
					RichTbUpgradeRadiator_LogVisAtt->SetVisibility(true);
					RichTbUpgradeRadiator_LV -> SetVisAttributes(RichTbUpgradeRadiator_LogVisAtt);

				}

			}

		}
    

		// now for the dark cover

		G4int RichTbUpgradeDarkCover_vis = aRunConfig->getRichTbUpgradeDarkCover_visib();
		G4cout<<"Dark cover visib flag  "<<RichTbUpgradeDarkCover_vis<<G4endl;

		if(  (curDetector != 0)  && (curDetector-> getRichTbUpgradeDarkCover() != 0) 
             && (aRadiatorConfiguration != 6) )
		{
			G4cout<<"now setting dark cover visib options  "<<RichTbUpgradeDarkCover_vis<<G4endl;

			G4LogicalVolume * RichTbUpgradeDarkCover_LV =curDetector->
					getRichTbUpgradeDarkCover()-> getRichTbUpgradeDarkCoverLVol();

			if(RichTbUpgradeDarkCover_LV != 0 ) {
				if(RichTbUpgradeDarkCover_vis == 0 ) {
					RichTbUpgradeDarkCover_LV ->SetVisAttributes(G4VisAttributes::Invisible);
				} else {
					G4VisAttributes * RichTbUpgradeDarkCover_LogVisAtt =
							new G4VisAttributes(G4Colour(0.0,0.1,0.05));
					if(RichTbUpgradeDarkCover_vis == 2 ) {
						RichTbUpgradeDarkCover_LogVisAtt ->SetForceSolid(false);
						RichTbUpgradeDarkCover_LogVisAtt ->SetForceWireframe(true);
						G4cout<<"test dark cover vis "<<RichTbUpgradeDarkCover_vis<<G4endl;
					}
					if(RichTbUpgradeDarkCover_vis == 1 ) {
						RichTbUpgradeDarkCover_LogVisAtt ->SetForceSolid(true);
					}
					RichTbUpgradeDarkCover_LogVisAtt->SetVisibility(true);
					RichTbUpgradeDarkCover_LV -> SetVisAttributes(RichTbUpgradeDarkCover_LogVisAtt);

				}

			}

		}


		G4int RichTbUpgradeUpsDarkCover_vis = aRunConfig->getRichTbUpgradeUpsDarkCover_visib();
		G4cout<<"Ups Dark cover visib flag  "<<RichTbUpgradeUpsDarkCover_vis<<G4endl;

		if(  (curDetector != 0)  && (curDetector-> getRichTbUpgradeDarkCover() != 0))
		{
			G4cout<<"now setting ups dark cover visib options  "<<RichTbUpgradeUpsDarkCover_vis<<G4endl;

			G4LogicalVolume * RichTbUpgradeUpsDarkCover_LV =curDetector->
					getRichTbUpgradeDarkCover()-> getRichTbUpgradeUpsDarkCoverLVol() ;
      if(aRadiatorConfiguration == 6 )RichTbUpgradeUpsDarkCover_LV =curDetector->
                                        getRichTbUpgradeDarkCover()-> getRichTbUpgradeUpsDarkCoverEnvPhCLVol();
      



			if(RichTbUpgradeUpsDarkCover_LV != 0 ) {
				if(RichTbUpgradeUpsDarkCover_vis == 0 ) {
					RichTbUpgradeUpsDarkCover_LV ->SetVisAttributes(G4VisAttributes::Invisible);
				} else {
					G4VisAttributes * RichTbUpgradeUpsDarkCover_LogVisAtt =
							new G4VisAttributes(G4Colour(0.0,0.1,0.05));
					if(RichTbUpgradeUpsDarkCover_vis == 2 ) {
						RichTbUpgradeUpsDarkCover_LogVisAtt ->SetForceSolid(false);
						RichTbUpgradeUpsDarkCover_LogVisAtt ->SetForceWireframe(true);
						G4cout<<"test dark cover vis "<<RichTbUpgradeUpsDarkCover_vis<<G4endl;
					}
					if(RichTbUpgradeUpsDarkCover_vis == 1 ) {
						RichTbUpgradeUpsDarkCover_LogVisAtt ->SetForceSolid(true);
					}
					RichTbUpgradeUpsDarkCover_LogVisAtt->SetVisibility(true);
					RichTbUpgradeUpsDarkCover_LV -> SetVisAttributes(RichTbUpgradeUpsDarkCover_LogVisAtt);

				}

			}

		}
    


		G4int RichTbUpgradeSideDarkCover_vis = aRunConfig->getRichTbUpgradeSideDarkCover_visib();
		G4cout<<"Side Dark cover visib flag  "<<RichTbUpgradeSideDarkCover_vis<<G4endl;

		if(  (curDetector != 0)  && (curDetector-> getRichTbUpgradeDarkCover() != 0))
		{
			G4cout<<"now setting side dark cover visib options  "<<RichTbUpgradeSideDarkCover_vis<<G4endl;


			G4LogicalVolume * RichTbUpgradeSideDarkCover_LV =curDetector->
					getRichTbUpgradeDarkCover()-> getRichTbUpgradeSideDarkCoverLVol() ;

      if(aRadiatorConfiguration == 6 )RichTbUpgradeSideDarkCover_LV = curDetector->
                                        getRichTbUpgradeDarkCover()-> getRichTbUpgradeSideDarkCoverEnvPhCLVol();
      

      G4cout << "RichTbGr Side dark cover LV "<< RichTbUpgradeSideDarkCover_LV <<G4endl;
      

			if(RichTbUpgradeSideDarkCover_LV != 0 ) {
				if(RichTbUpgradeSideDarkCover_vis == 0 ) {
					RichTbUpgradeSideDarkCover_LV ->SetVisAttributes(G4VisAttributes::Invisible);
				} else {
					G4VisAttributes * RichTbUpgradeSideDarkCover_LogVisAtt =
							new G4VisAttributes(G4Colour(0.4,0.4,0.05));
					if(RichTbUpgradeSideDarkCover_vis == 2 ) {
						RichTbUpgradeSideDarkCover_LogVisAtt ->SetForceSolid(false);
						RichTbUpgradeSideDarkCover_LogVisAtt ->SetForceWireframe(true);
						G4cout<<"test dark cover vis "<<RichTbUpgradeSideDarkCover_vis<<G4endl;
					}
					if(RichTbUpgradeSideDarkCover_vis == 1 ) {
						RichTbUpgradeSideDarkCover_LogVisAtt ->SetForceSolid(true);
					}
					RichTbUpgradeSideDarkCover_LogVisAtt->SetVisibility(true);
					RichTbUpgradeSideDarkCover_LV -> SetVisAttributes(RichTbUpgradeSideDarkCover_LogVisAtt);

				}
        

			}
      
      
      

		}
    

		G4int RichTbUpgradeDnsDarkCover_vis = aRunConfig->getRichTbUpgradeDnsDarkCover_visib();
		G4cout<<"Dns Dark cover visib flag  "<<RichTbUpgradeDnsDarkCover_vis<<G4endl;

		if(  (curDetector != 0)  && (curDetector-> getRichTbEC()  != 0))
		{
			G4cout<<"now setting dns dark cover (dns of EC ) visib options  "<<RichTbUpgradeDnsDarkCover_vis<<G4endl;
      G4LogicalVolume * RichTbUpgradeDnsDarkCover_LV=0;
      G4int NumECCell16=NumElementaryCell16;

    std::vector<G4LogicalVolume *> RichTbECSup_LV( NumECCell16 );
   
   
      if( aRadiatorConfiguration <=3 ) 
      {
        
			   RichTbUpgradeDnsDarkCover_LV =curDetector->
					       getRichTbEC()->getRichTbECSupLVol () ;
      }else if ( aRadiatorConfiguration ==6 ) {
        
        for (G4int iec=0; iec < NumECCell16  ; iec++){
          RichTbECSup_LV[iec]= curDetector->getRichTbEC()->getRichTbECSupportLVol(iec);
        
        }
      }
	else if(aRadiatorConfiguration == 7){ //2017
	  RichTbUpgradeDnsDarkCover_LV =curDetector->
					       getRichTbEC()->getRichTbECSupLVol () ;
	}

      
      
      
				if(RichTbUpgradeDnsDarkCover_vis == 0 ) {
          if(aRadiatorConfiguration <= 3) 
          {
            
           if(RichTbUpgradeDnsDarkCover_LV != 0 ) {

					   RichTbUpgradeDnsDarkCover_LV ->SetVisAttributes(G4VisAttributes::Invisible);
           }
          }else if (aRadiatorConfiguration ==6 ){

           for (G4int iec=0; iec < NumECCell16 ; iec++){
             RichTbECSup_LV[iec]-> SetVisAttributes(G4VisAttributes::Invisible); 
           }
	  }
            
           else if (aRadiatorConfiguration == 7 ){ 
	      if(RichTbUpgradeDnsDarkCover_LV != 0 ) {
		RichTbUpgradeDnsDarkCover_LV ->SetVisAttributes(G4VisAttributes::Invisible);
	      }
	   }
          
          

				} else {
					G4VisAttributes * RichTbUpgradeDnsDarkCover_LogVisAtt =
							new G4VisAttributes(G4Colour(0.5,0.6,0.05));
					if(RichTbUpgradeDnsDarkCover_vis == 2 ) {
						RichTbUpgradeDnsDarkCover_LogVisAtt ->SetForceSolid(false);
						RichTbUpgradeDnsDarkCover_LogVisAtt ->SetForceWireframe(true);
						G4cout<<"test dark cover vis "<<RichTbUpgradeDnsDarkCover_vis<<G4endl;
					}
					if(RichTbUpgradeDnsDarkCover_vis == 1 ) {
						RichTbUpgradeDnsDarkCover_LogVisAtt ->SetForceSolid(true);
					}
					RichTbUpgradeDnsDarkCover_LogVisAtt->SetVisibility(true);
          if( aRadiatorConfiguration <= 3){
 					  RichTbUpgradeDnsDarkCover_LV -> SetVisAttributes(RichTbUpgradeDnsDarkCover_LogVisAtt);
          }else if (  aRadiatorConfiguration == 6){

           for (G4int iec=0; iec < NumElementaryCell16 ; iec++){
            RichTbECSup_LV[iec]->SetVisAttributes(RichTbUpgradeDnsDarkCover_LogVisAtt); 
           }
 
          }
          else if (  aRadiatorConfiguration == 7){//2017
	    RichTbUpgradeDnsDarkCover_LV -> SetVisAttributes(RichTbUpgradeDnsDarkCover_LogVisAtt);
	  }
          
				}

			
      

		}

    


		G4int RichTbUpgradeLTCover_vis = aRunConfig->getRichTbUpgradeLTCover_visib();
    G4int RichTbLTSampleCoverType=  aRunConfig->getLTRadiatorSampleType();

		G4cout<<"LT Master cover visib flag  "<<RichTbUpgradeLTCover_vis<<G4endl;
    if(  aRadiatorConfiguration == 6){    
  
     if( (curDetector != 0) && (curDetector -> getRichTbUpgradeRadiator())) {
        if( curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()){
      
         G4LogicalVolume *  RichTbUpgradeLTMasterCover_LV = (RichTbLTSampleCoverType == 0) ? 
             curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()->getRichTbUpgradeLTSampleAMasterLVol() :
             curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()->getRichTbUpgradeLTSampleBMasterLVol();
         if(  RichTbUpgradeLTMasterCover_LV != 0 ) {
           if( RichTbUpgradeLTCover_vis == 0 ){
              RichTbUpgradeLTMasterCover_LV ->SetVisAttributes(G4VisAttributes::Invisible);
           }else{
              G4VisAttributes *  RichTbUpgradeLTCov_LogVisAtt = new G4VisAttributes(G4Colour(0.6,0.1,0.8));
              if(  RichTbUpgradeLTCover_vis == 2 ) {
                 RichTbUpgradeLTCov_LogVisAtt ->SetForceSolid(false);
                  RichTbUpgradeLTCov_LogVisAtt -> SetForceWireframe(true);
                
              }
              if( RichTbUpgradeLTCover_vis == 1 ) {
                  RichTbUpgradeLTCov_LogVisAtt ->SetForceSolid(true);                 

              }
     					RichTbUpgradeLTCov_LogVisAtt ->SetVisibility(true);
              RichTbUpgradeLTMasterCover_LV -> SetVisAttributes( RichTbUpgradeLTCov_LogVisAtt);

              
           } 
           

         }


        }
        
        
    
     }
     
     
     

    }
    
    
    



		// now for the mirror

		G4int RichTbUpgradeMirror_vis =   aRunConfig->getRichTbUpgradeMirror_visib();
		if(  (curDetector != 0)  && (curDetector-> getRichTbUpgradeMirror() != 0)){
			G4cout<<"now setting mirror visb options  "<<RichTbUpgradeMirror_vis<<G4endl;
			G4LogicalVolume * RichTbUpgradeMirror_LV =   curDetector->
					getRichTbUpgradeMirror()->getRichTbUpgradeMirrorLVol();

			if(  RichTbUpgradeMirror_LV != 0 ) {
				// G4cout<<" mirror log vol "<<RichTbUpgradeMirror_LV<<G4endl;

				if(RichTbUpgradeMirror_vis == 0) {
					RichTbUpgradeMirror_LV ->SetVisAttributes(G4VisAttributes::Invisible);
				} else {

					G4VisAttributes *  RichTbUpgradeMirror_LogVisAtt =
							new G4VisAttributes(G4Colour(0.1,0.8,0.8));

					if( RichTbUpgradeMirror_vis == 2 ) {
						RichTbUpgradeMirror_LogVisAtt ->SetForceSolid(false);
						RichTbUpgradeMirror_LogVisAtt ->SetForceWireframe(true);
						G4cout<<"test mirror vis "<<RichTbUpgradeMirror_vis<<G4endl;
					}
					if( RichTbUpgradeMirror_vis == 1 ) {
						RichTbUpgradeMirror_LogVisAtt ->SetForceSolid(true);
					}

					RichTbUpgradeMirror_LogVisAtt ->SetVisibility(true);
					RichTbUpgradeMirror_LV -> SetVisAttributes( RichTbUpgradeMirror_LogVisAtt);
				}

			}


		}

	}
  


	// now for the crystal master

	G4int RichTbCrystal_vis = aRunConfig->getRichTbCrystal_visib();
	//  G4cout<<"Crystal visib flag  "<<RichTbCrystal_vis<<G4endl;

	if(  (curDetector != 0)  && (curDetector-> getRichTbUpgradeCrystalMaster() != 0))
	{
		G4cout<<"now setting crystal master visib options  "<<G4endl;

		G4LogicalVolume * RichTbUpgradeCrystalMaster_LV =curDetector->
				getRichTbUpgradeCrystalMaster()-> getRichTbUpgradeCrystalMasterLVol();
		if(RichTbUpgradeCrystalMaster_LV != 0 ) {

			if(RichTbCrystal_vis == 0 )
			{

				RichTbUpgradeCrystalMaster_LV ->SetVisAttributes(G4VisAttributes::Invisible);
			}else{




				G4VisAttributes * RichTbUpgradeCrystalMaster_LogVisAtt =
						new G4VisAttributes(G4Colour(0.2,0.3,0.0));

				//              RichTbUpgradeCrystalMaster_LogVisAtt ->SetForceSolid(false);
				//     RichTbUpgradeCrystalMaster_LogVisAtt ->SetForceWireframe(true);


				/*
	else {
				 */
				//G4VisAttributes * RichTbCrystal_LogVisAtt =
				//                 new G4VisAttributes(G4Colour(1.,0.0,0.0));
				if(RichTbCrystal_vis == 2 ) {
					RichTbUpgradeCrystalMaster_LogVisAtt ->SetForceSolid(false);
					RichTbUpgradeCrystalMaster_LogVisAtt ->SetForceWireframe(true);
					// G4cout<<"test crystal vis "<<RichTbCrystal_vis<<G4endl;
				}
				if(RichTbCrystal_vis == 1 ) {
					RichTbUpgradeCrystalMaster_LogVisAtt ->SetForceSolid(true);
				}
				RichTbUpgradeCrystalMaster_LogVisAtt->SetVisibility(true);
				RichTbUpgradeCrystalMaster_LV -> SetVisAttributes(RichTbUpgradeCrystalMaster_LogVisAtt);

			}


		}


	}
  

  // Now for the layertec sample
		G4cout<<"now setting layer tec visib options  "<<G4endl;

  G4int RichTbLTSubstrate_vis = aRunConfig-> getRichTbLTSubstrate_visib() ;
  G4int RichTbLTSampleType=  aRunConfig->getLTRadiatorSampleType();
  
  if( (curDetector != 0) && (curDetector -> getRichTbUpgradeRadiator())) {
    if( curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()){
      
      
      G4LogicalVolume *  RichTbUpgradeSubstrate_LV = (RichTbLTSampleType == 0) ? 
        curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()->getRichTbUpgradeLTPhCSampleALVol() :
        curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()->getRichTbUpgradeLTPhCSampleBLVol();
      

        if(  RichTbUpgradeSubstrate_LV != 0 ) {
          
          if( RichTbLTSubstrate_vis == 0 ){
             RichTbUpgradeSubstrate_LV ->SetVisAttributes(G4VisAttributes::Invisible); 

          }else{
            G4VisAttributes *  RichTbLTSubstrate_LogVisAtt =
                   new G4VisAttributes(G4Colour(0.7,0.1,0.2));

            if(  RichTbLTSubstrate_vis == 2 ){
               RichTbLTSubstrate_LogVisAtt  -> SetForceSolid(false);
               RichTbLTSubstrate_LogVisAtt  -> SetForceWireframe(true);
            }
            if( RichTbLTSubstrate_vis == 1 ){
               RichTbLTSubstrate_LogVisAtt ->SetForceSolid(true);
            }
            RichTbLTSubstrate_LogVisAtt ->SetVisibility(true);
            RichTbUpgradeSubstrate_LV ->  SetVisAttributes( RichTbLTSubstrate_LogVisAtt);
          } 

        }

    }    
  }

 G4int  RichTbLTPhC_vis = aRunConfig->  getRichTbLTPhC_visib() ;
  
 if( (curDetector != 0) && (curDetector -> getRichTbUpgradeRadiator())) {
    if( curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()){
        G4LogicalVolume *  RichTbUpgradePhCLayer_LV = (RichTbLTSampleType == 0) ?
          curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()-> getRichTbUpgradeLTPhCLayerALVol() :
          curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()->  getRichTbUpgradeLTPhCLayerBLVol();
        if(  RichTbUpgradePhCLayer_LV != 0 ){
          if(  RichTbLTPhC_vis == 0 ) {
             RichTbUpgradePhCLayer_LV -> SetVisAttributes(G4VisAttributes::Invisible); 

          }else{
             G4VisAttributes *  RichTbLTPhC_LogVisAtt = 
                  new  G4VisAttributes(G4Colour(0.3,0.7,0.2));

             if( RichTbLTPhC_vis == 2 ){
               RichTbLTPhC_LogVisAtt -> SetForceSolid(false);
               RichTbLTPhC_LogVisAtt -> SetForceWireframe(true);
             }
             if(RichTbLTPhC_vis == 1 ){  
               RichTbLTPhC_LogVisAtt ->SetForceSolid(true);  
             }
              RichTbLTPhC_LogVisAtt  -> SetVisibility(true);
              RichTbUpgradePhCLayer_LV -> SetVisAttributes( RichTbLTPhC_LogVisAtt);
          } 

        }

    }    

 }


 
 
 G4int RichTbLTFilter_vis = aRunConfig-> getRichTbLTFilter_visib();
  if( (curDetector != 0) && (curDetector -> getRichTbUpgradeRadiator())) {
    if( curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()){
        G4LogicalVolume * RichTbUpgradeLTFilter_LV = (RichTbLTSampleType == 0) ?
          curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()->  getRichTbUpgradeLTFilterALVol() :
          curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()->  getRichTbUpgradeLTFilterBLVol();

        G4LogicalVolume * RichTbUpgradeLTFilterGlass_LV = (RichTbLTSampleType == 0) ?
          curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()->  getRichTbUpgradeLTFilterGlassALVol() :
          curDetector -> getRichTbUpgradeRadiator()->getRichTbUpgradeLTPhC()->  getRichTbUpgradeLTFilterGlassBLVol();


        G4cout<< "Test of filter visib " <<  RichTbUpgradeLTFilter_LV <<G4endl;
        
        if( RichTbUpgradeLTFilter_LV != 0 ){
          if( RichTbLTFilter_vis == 0 ){
            RichTbUpgradeLTFilter_LV -> SetVisAttributes(G4VisAttributes::Invisible); 
            RichTbUpgradeLTFilterGlass_LV -> SetVisAttributes(G4VisAttributes::Invisible); 

          }else{
             G4VisAttributes * RichTbUpgradeLTFilter_VisAtt =
                new G4VisAttributes(G4Colour(0.4,0.2,0.7)); 
            
             if(RichTbLTFilter_vis == 2 ){
               RichTbUpgradeLTFilter_VisAtt ->  SetForceSolid(false);
               RichTbUpgradeLTFilter_VisAtt ->  SetForceWireframe(true); 
             }
             if( RichTbLTFilter_vis == 1 ){
                RichTbUpgradeLTFilter_VisAtt -> SetForceSolid(true);
             }
             
             RichTbUpgradeLTFilter_VisAtt -> SetVisibility(true);
             RichTbUpgradeLTFilter_LV -> SetVisAttributes(RichTbUpgradeLTFilter_VisAtt);
             RichTbUpgradeLTFilterGlass_LV -> SetVisAttributes(RichTbUpgradeLTFilter_VisAtt);
             
          }

        }
        
    }
  }


}
void RichTbGraphics::setRichTbDetectorGeometryPhDetGraphicsAttributes() {


	RichTbRunConfig* aRunConfig=  RichTbRunConfig::getRunConfigInstance();
	G4int aRadiatorConfiguration =  aRunConfig ->getRadiatorConfiguration();

	// now for the upgrade phdet frame
	G4int RichTbPhdet_vis = aRunConfig->getRichTbPhDetSupFrame_visib();


	if( (curDetector != 0)  && (curDetector-> getRichTbUpgradePhDetSupFrame() != 0)) {
		G4cout<<" Now setting PhDetFrame visib options " <<G4endl;

    //	G4LogicalVolume * RichTbPhDetLeft_LV =curDetector->
    //			getRichTbUpgradePhDetSupFrame() -> getRichTbPhDetSupFrameLeftLVol();
    //	G4LogicalVolume * RichTbPhDetRight_LV =curDetector->
    //			getRichTbUpgradePhDetSupFrame() -> getRichTbPhDetSupFrameRightLVol();

    G4LogicalVolume * RichTbPhDetLeft_LV=0;
    G4LogicalVolume * RichTbPhDetRight_LV=0;
    
		G4LogicalVolume * RichTbPhDetBottomLeft_LV=0;
		G4LogicalVolume * RichTbPhDetBottomRight_LV=0;

G4LogicalVolume * RichTbPhDet2017_LV=0;
    G4int NumPhDet= NumPhDetSupFrames16;
    
    std::vector<G4LogicalVolume *> RichTbPhDetList(NumPhDet);
    
    
    G4bool phDetExist=false;
    
		if( ( aRadiatorConfiguration == 3  ) ||  ( aRadiatorConfiguration < 3 ) )   {
		  RichTbPhDetLeft_LV =curDetector->
				getRichTbUpgradePhDetSupFrame() -> getRichTbPhDetSupFrameLeftLVol();
		  RichTbPhDetRight_LV =curDetector->
				getRichTbUpgradePhDetSupFrame() -> getRichTbPhDetSupFrameRightLVol();
		  if( (RichTbPhDetLeft_LV !=0)  &&  (RichTbPhDetRight_LV  !=0 )) phDetExist=true;}
		else if(aRadiatorConfiguration == 7  ){
        
		    	RichTbPhDet2017_LV =curDetector->
				 	   getRichTbUpgradePhDetSupFrame()->getRichTbPhDetSupFrame2017LVol();
      }
      
		else if ( aRadiatorConfiguration == 6 ) {
      for (G4int iph=0; iph<NumPhDet; iph++){
         RichTbPhDetList[iph]= curDetector->
           getRichTbUpgradePhDetSupFrame() ->getRichTbPhDetGrandSupFrameLVol(iph);
      
         if(RichTbPhDetList[iph] !=0  ){
            phDetExist=true; 
         }else{
            phDetExist=false; 
         }
         
         
      }    
      
    }

		if( phDetExist) {
			if(RichTbPhdet_vis == 0){
        if( aRadiatorConfiguration <= 3 ) {
          
			   	RichTbPhDetLeft_LV ->SetVisAttributes(G4VisAttributes::Invisible);
			  	RichTbPhDetRight_LV  ->SetVisAttributes(G4VisAttributes::Invisible);
          if(aRadiatorConfiguration == 3) {
  				   if( (RichTbPhDetBottomLeft_LV !=0) && (RichTbPhDetBottomRight_LV != 0)) {
  				   	 RichTbPhDetBottomLeft_LV->SetVisAttributes(G4VisAttributes::Invisible);
	  				   RichTbPhDetBottomRight_LV->SetVisAttributes(G4VisAttributes::Invisible);
				   }
	  }}

             else if(aRadiatorConfiguration == 7) {
  				   if( (RichTbPhDet2017_LV !=0)) {
  				   	 RichTbPhDet2017_LV->SetVisAttributes(G4VisAttributes::Invisible);
	  			
             }
 
	      }
          
	  else if ( aRadiatorConfiguration == 6 ) {
                     
          for (G4int iph=0; iph<NumPhDet; iph++){
            RichTbPhDetList[iph] -> SetVisAttributes(G4VisAttributes::Invisible);
          }
          
        }
        
        
        
        
	}else {
				G4VisAttributes * RichTbPhDetSupFrame_LogVisAtt =
						new G4VisAttributes(G4Colour(0.3,0.3,0.7));

				if(RichTbPhdet_vis == 2)
				{
					RichTbPhDetSupFrame_LogVisAtt->SetForceSolid(false);
					RichTbPhDetSupFrame_LogVisAtt->SetForceWireframe(true);
				}
				if(RichTbPhdet_vis == 1)
				{
					RichTbPhDetSupFrame_LogVisAtt->SetForceSolid(true);
				}
				RichTbPhDetSupFrame_LogVisAtt->SetVisibility(true);

        if( aRadiatorConfiguration <= 3 ){
          
				  RichTbPhDetLeft_LV->SetVisAttributes(RichTbPhDetSupFrame_LogVisAtt);
				  RichTbPhDetRight_LV->SetVisAttributes(RichTbPhDetSupFrame_LogVisAtt);
           if( (aRadiatorConfiguration == 3) )    {
          
				      if( (RichTbPhDetBottomLeft_LV !=0) && (RichTbPhDetBottomRight_LV != 0)) {
					       RichTbPhDetBottomLeft_LV->SetVisAttributes(RichTbPhDetSupFrame_LogVisAtt);
					       RichTbPhDetBottomRight_LV->SetVisAttributes(RichTbPhDetSupFrame_LogVisAtt);
				      }
           }
        }else if ( aRadiatorConfiguration == 6 ){

           for (G4int iph=0; iph<NumPhDet; iph++){
              RichTbPhDetList[iph] -> SetVisAttributes(RichTbPhDetSupFrame_LogVisAtt);
           }

        }
        else if ( aRadiatorConfiguration == 7 ){

	  if( (RichTbPhDet2017_LV !=0)) {
					       RichTbPhDet2017_LV->SetVisAttributes(RichTbPhDetSupFrame_LogVisAtt);
					    
				      }
          

        }
        
        
        
			}
      
		}
    
	}

	// now for the upgrade EC
	G4int RichTbEC_vis = aRunConfig->getRichTbEC_visib();
	if( (curDetector != 0)  && (curDetector-> getRichTbEC() != 0))
	{
		G4cout<<" Now setting EC visib options " <<G4endl;

    G4LogicalVolume * RichTbECLeft_LV =0;
    G4LogicalVolume * RichTbECRight_LV=0;
		G4LogicalVolume * RichTbECBottomLeft_LV=0;
		G4LogicalVolume * RichTbECBottomRight_LV=0;
    G4int NumCurEC= NumElementaryCell16;
    std::vector<G4LogicalVolume *> RichTbEC_LV(NumCurEC);

    G4LogicalVolume * RichTbECBottom_LV  =0;
    G4LogicalVolume * RichTbECBottomMedium_LV=0;
		G4LogicalVolume * RichTbECHightMedium_LV=0;
		G4LogicalVolume * RichTbECHight_LV=0;

    

    if( aRadiatorConfiguration <=3 ){

		    RichTbECLeft_LV =curDetector->
				    getRichTbEC()-> getRichTbECLeftLVol();
		    RichTbECLeft_LV =curDetector->
				    getRichTbEC()-> getRichTbECLeftLVol();

		    RichTbECRight_LV =
				   (aRadiatorConfiguration == 2) ? 0 : curDetector-> getRichTbEC()-> getRichTbECRightLVol();

        if( aRadiatorConfiguration == 3 ) {
     			RichTbECBottomLeft_LV = curDetector->getRichTbEC()->getRichTbECBottomLeftLVol();
			    RichTbECBottomRight_LV = curDetector->getRichTbEC()->getRichTbECBottomRightLVol();          
        }
        
        
    }else if (aRadiatorConfiguration ==6 ) {

      for (G4int iec=0; iec < NumCurEC ; iec++){
        RichTbEC_LV[iec]= curDetector->getRichTbEC()->getRichTbECLVol(iec);
        
      }
      
    }

    else if (aRadiatorConfiguration == 7 ) {

      	RichTbECBottom_LV = curDetector->getRichTbEC()->getRichTbECBottomLVol();
      	RichTbECBottomMedium_LV = curDetector->getRichTbEC()->getRichTbECBottomMediumLVol();
    	RichTbECHightMedium_LV = curDetector->getRichTbEC()->getRichTbECHightMediumLVol();
	RichTbECHight_LV = curDetector->getRichTbEC()->getRichTbECHightLVol();
    }


		G4VisAttributes * RichTbEC_LogVisAtt = new G4VisAttributes(G4Colour(0.7,0.3,0.7));

		
			 if(RichTbEC_vis == 0 ){
         if(	RichTbECLeft_LV !=0 )RichTbECLeft_LV->SetVisAttributes(G4VisAttributes::Invisible);
         if(	RichTbECRight_LV !=0 )RichTbECRight_LV->SetVisAttributes(G4VisAttributes::Invisible);
         
         if(aRadiatorConfiguration == 3){
				  if(  (RichTbECBottomLeft_LV!=0) && (RichTbECBottomRight_LV!=0)){
				  	RichTbECBottomLeft_LV->SetVisAttributes(G4VisAttributes::Invisible);
				  	RichTbECBottomRight_LV->SetVisAttributes(G4VisAttributes::Invisible);
				  }
          
         }else if (aRadiatorConfiguration == 6){

           for (G4int iec=0; iec < NumCurEC ; iec++){
             RichTbEC_LV[iec]-> SetVisAttributes(G4VisAttributes::Invisible);
           }
            
           
         }

         else if (aRadiatorConfiguration == 7){

            if(  (RichTbECBottom_LV!=0) && (RichTbECBottomMedium_LV!=0) && (RichTbECHight_LV!=0) && (RichTbECHightMedium_LV!=0)){
				  	RichTbECBottom_LV->SetVisAttributes(G4VisAttributes::Invisible);
				  	RichTbECHight_LV->SetVisAttributes(G4VisAttributes::Invisible);	
					RichTbECBottomMedium_LV->SetVisAttributes(G4VisAttributes::Invisible);
				  	RichTbECHightMedium_LV->SetVisAttributes(G4VisAttributes::Invisible);
            
           
	    }
	 }
        
			}else {

				if(RichTbEC_vis == 2 ) {
					RichTbEC_LogVisAtt->SetForceSolid(false);
					RichTbEC_LogVisAtt->SetForceWireframe(true);
				}
				if(RichTbEC_vis == 1 ) RichTbEC_LogVisAtt->SetForceSolid(true);
				RichTbEC_LogVisAtt->SetVisibility(true);


        if(	RichTbECLeft_LV !=0 )RichTbECLeft_LV-> SetVisAttributes(RichTbEC_LogVisAtt);
        if(	RichTbECRight_LV !=0 )RichTbECRight_LV-> SetVisAttributes(RichTbEC_LogVisAtt);
        if(aRadiatorConfiguration == 3){
				if( (RichTbECBottomLeft_LV!=0) && (RichTbECBottomRight_LV!=0)){
					RichTbECBottomLeft_LV->SetVisAttributes(RichTbEC_LogVisAtt);
					RichTbECBottomRight_LV->SetVisAttributes(RichTbEC_LogVisAtt);
				}
        
        }else if ( aRadiatorConfiguration == 6 ){
          
           for (G4int iec=0; iec < NumCurEC ; iec++){
             RichTbEC_LV[iec]-> SetVisAttributes(RichTbEC_LogVisAtt);
           }
        }        
        
        
       }
       
       
    

	}




	// now for the upgrade PMTmaster
	// TESTnumPmts
	G4int CurNumPmts = NumPmtsOld;
//	G4int CurNumPmts = RichTbPMTGeometryParameters::getNumPmts();
	if (aRadiatorConfiguration == 2) { 
   CurNumPmts = NumPmtsWithHpd;
  } else if (aRadiatorConfiguration == 3) {
   CurNumPmts = NumPmtsUpgrade15;
  }else if (aRadiatorConfiguration == 6) {
  
    //   CurNumPmts = NumPmtsUpgrade16;
   CurNumPmts = NumPmtsUpgrade16;
    
  }
  else if (aRadiatorConfiguration == 7) {
  
   CurNumPmts = NumPmtsUpgrade17;
    
  }
  
//	else if (aRadiatorConfiguration == 3) CurNumPmts = RichTbPMTGeometryParameters::getNumPmtsUpgrade();
	// CurNumPmts = (aRadiatorConfiguration==3) ? NumPmtsUpgrade15 : NumPmts;

	G4int RichTbPMTMaster_vis = aRunConfig->getRichTbPMTMaster_visib();
	G4cout<<"RichTb PMT Master visib flag  "<<RichTbPMTMaster_vis<<G4endl;

	if(  (curDetector != 0)  && (curDetector-> getRichTbPMT() != 0)){
		G4cout<<"now setting PMT master visb options  "<<RichTbPMTMaster_vis<<G4endl;

		std::vector<G4LogicalVolume *> RichTbPMTMaster_LV =curDetector->
				getRichTbPMT()-> getRichTbPMTMasterLVol() ;

		if((int) RichTbPMTMaster_LV.size() != 0 ) {
			if(RichTbPMTMaster_vis == 0 ) {
				for (int i=0; i<CurNumPmts; i++){
					RichTbPMTMaster_LV[i] ->SetVisAttributes(G4VisAttributes::Invisible);
				}

			} else {
				G4VisAttributes * RichTbPMTMaster_LogVisAtt =
						new G4VisAttributes(G4Colour(0.0,0.2,0.5));
				if(RichTbPMTMaster_vis == 2 ) {
					RichTbPMTMaster_LogVisAtt ->SetForceSolid(false);
					RichTbPMTMaster_LogVisAtt ->SetForceWireframe(true);
				}
				if(RichTbPMTMaster_vis == 1 ) {
					RichTbPMTMaster_LogVisAtt ->SetForceSolid(true);
				}
				RichTbPMTMaster_LogVisAtt->SetVisibility(true);

				for (int i=0; i<CurNumPmts; i++){
					RichTbPMTMaster_LV [i] -> SetVisAttributes(RichTbPMTMaster_LogVisAtt);
				}
			}
		}
	}
  
  


	G4int RichTbPMTSMaster_vis = aRunConfig->getRichTbPMTSMaster_visib();
	G4cout<<"RichTb PMT SMaster visib flag  "<<RichTbPMTSMaster_vis<<G4endl;

	if((curDetector != 0) && (curDetector-> getRichTbPMT() != 0)){
		G4cout<<"now setting PMT SMaster visib options  "<<RichTbPMTSMaster_vis<<G4endl;

		std::vector<G4LogicalVolume *>  RichTbPMTSMaster_LV = curDetector->
				getRichTbPMT()-> getRichTbPMTSMasterLVol() ;

		if((int) RichTbPMTSMaster_LV.size() != 0 ) {
			if(RichTbPMTSMaster_vis == 0 ) {
				for (int i=0; i<CurNumPmts; i++){
					RichTbPMTSMaster_LV[i]->SetVisAttributes(G4VisAttributes::Invisible);
				}
			} else {
				G4VisAttributes * RichTbPMTSMaster_LogVisAtt =
						new G4VisAttributes(G4Colour(0.0,0.2,0.5));
				if(RichTbPMTSMaster_vis == 2 ) {
					RichTbPMTSMaster_LogVisAtt->SetForceSolid(false);
					RichTbPMTSMaster_LogVisAtt->SetForceWireframe(true);
				}
				if(RichTbPMTSMaster_vis == 1 ) {
					RichTbPMTSMaster_LogVisAtt->SetForceSolid(true);
				}
				RichTbPMTSMaster_LogVisAtt->SetVisibility(true);
				for (int i=0; i<CurNumPmts; i++){
					RichTbPMTSMaster_LV [i] -> SetVisAttributes(RichTbPMTSMaster_LogVisAtt);
				}
			}
		}
	}
  



	G4int RichTbPMTAnode_vis = aRunConfig->getRichTbPMTAnode_visib();
	G4cout<<"RichTb PMT Anode visib flag  "<<RichTbPMTAnode_vis<<G4endl;

	if(  (curDetector != 0)  && (curDetector-> getRichTbPMT() != 0)){
		G4cout<<"now setting PMT Anode visib options  "<<RichTbPMTAnode_vis<<G4endl;

		std::vector<G4LogicalVolume *>  RichTbPMTAnode_LV =curDetector->
				getRichTbPMT()-> getRichTbPMTAnodeLVol() ;

		if((int) RichTbPMTAnode_LV.size() != 0 ) {
			if(RichTbPMTAnode_vis == 0 ) {
				for (int i=0; i<CurNumPmts; i++){
					RichTbPMTAnode_LV[i] ->SetVisAttributes(G4VisAttributes::Invisible);
				}

			} else {
				G4VisAttributes * RichTbPMTAnode_LogVisAtt =
						new G4VisAttributes(G4Colour(0.0,0.2,0.5));
				if(RichTbPMTAnode_vis == 2 ) {
					RichTbPMTAnode_LogVisAtt ->SetForceSolid(false);
					RichTbPMTAnode_LogVisAtt ->SetForceWireframe(true);

				}
				if(RichTbPMTAnode_vis == 1 ) {
					RichTbPMTAnode_LogVisAtt ->SetForceSolid(true);
				}
				RichTbPMTAnode_LogVisAtt->SetVisibility(true);
				for (int i=0; i<CurNumPmts; i++){
					RichTbPMTAnode_LV [i] -> SetVisAttributes(RichTbPMTAnode_LogVisAtt);
				}

			}


		}
	}




	G4int RichTbPMTEnvelope_vis = aRunConfig->getRichTbPMTEnvelope_visib();
	G4cout<<"PMT Envelope visib flag  "<<RichTbPMTEnvelope_vis<<G4endl;

	if(  (curDetector != 0)  && (curDetector-> getRichTbPMT() != 0))
	{
		G4cout<<"now setting pmt envelope visb options  "<<RichTbPMTEnvelope_vis<<G4endl;

		G4LogicalVolume * RichTbPMTEnvelope_LV =curDetector->
				getRichTbPMT()-> getRichTbPMTEnvelopeLVol();
		G4cout<<"test PMT Envelope LV "<<RichTbPMTEnvelope_LV<<G4endl;
		if(RichTbPMTEnvelope_LV != 0 ) {
			if(RichTbPMTEnvelope_vis == 0 ) {
				RichTbPMTEnvelope_LV ->SetVisAttributes(G4VisAttributes::Invisible);
			} else {
				G4VisAttributes * RichTbPMTEnvelope_LogVisAtt =
						new G4VisAttributes(G4Colour(0.0,0.8,0.2));
				if(RichTbPMTEnvelope_vis == 2 ) {
					RichTbPMTEnvelope_LogVisAtt ->SetForceSolid(false);
					RichTbPMTEnvelope_LogVisAtt ->SetForceWireframe(true);
				}
				if(RichTbPMTEnvelope_vis == 1 ) {
					RichTbPMTEnvelope_LogVisAtt ->SetForceSolid(true);
				}
				RichTbPMTEnvelope_LogVisAtt->SetVisibility(true);
				RichTbPMTEnvelope_LV -> SetVisAttributes(RichTbPMTEnvelope_LogVisAtt);

			}

		}

	}
  



	G4int RichTbPMTQuartzW_vis = aRunConfig->getRichTbPMTQuartzW_visib();
	G4cout<<"PMT QW window visib flag  "<<RichTbPMTQuartzW_vis<<G4endl;

	if(  (curDetector != 0)  && (curDetector-> getRichTbPMT() != 0))
	{
		G4cout<<"now setting qw window  visb options  "<<RichTbPMTQuartzW_vis<<G4endl;

		G4LogicalVolume * RichTbPMTQuartzW_LV =curDetector->getRichTbPMT()-> getRichTbPMTQuartzWLVol();


		if(RichTbPMTQuartzW_LV != 0 ) {
			if(RichTbPMTQuartzW_vis == 0 ) {
				RichTbPMTQuartzW_LV ->SetVisAttributes(G4VisAttributes::Invisible);
			} else {
				G4VisAttributes * RichTbPMTQuartzW_LogVisAtt =
						new G4VisAttributes(G4Colour(0.2,0.0,0.8));
				if(RichTbPMTQuartzW_vis == 2 ) {
					RichTbPMTQuartzW_LogVisAtt ->SetForceSolid(false);
					RichTbPMTQuartzW_LogVisAtt ->SetForceWireframe(true);
				}
				if(RichTbPMTQuartzW_vis == 1 ) {
					RichTbPMTQuartzW_LogVisAtt ->SetForceSolid(true);
				}
				RichTbPMTQuartzW_LogVisAtt->SetVisibility(true);
				RichTbPMTQuartzW_LV -> SetVisAttributes(RichTbPMTQuartzW_LogVisAtt);

			}

		}

	}
  
  
  



	G4int RichTbPMTCathode_vis = aRunConfig->getRichTbPMTPhCathode_visib();
	G4cout<<"PMT cathod visib flag  "<<RichTbPMTCathode_vis<<G4endl;

	if(  (curDetector != 0)  && (curDetector-> getRichTbPMT() != 0))
	{
		G4cout<<"now setting cathode visib options  "<<RichTbPMTCathode_vis<<G4endl;

		G4LogicalVolume * RichTbPMTCathode_LV =curDetector->
				getRichTbPMT()-> getRichTbPMTPhCathodeLVol();
		if(RichTbPMTCathode_LV != 0 ) {
			if(RichTbPMTCathode_vis == 0 ) {
				RichTbPMTCathode_LV ->SetVisAttributes(G4VisAttributes::Invisible);
			} else {
				G4VisAttributes * RichTbPMTCathode_LogVisAtt =
						new G4VisAttributes(G4Colour(1.0,0.0,0.0));
				if(RichTbPMTCathode_vis == 2 ) {
					RichTbPMTCathode_LogVisAtt ->SetForceSolid(false);
					RichTbPMTCathode_LogVisAtt ->SetForceWireframe(true);
				}
				if(RichTbPMTCathode_vis == 1 ) {
					RichTbPMTCathode_LogVisAtt ->SetForceSolid(true);
				}
				RichTbPMTCathode_LogVisAtt->SetVisibility(true);
				RichTbPMTCathode_LV -> SetVisAttributes(RichTbPMTCathode_LogVisAtt);


			}

		}

	}
  




	G4int RichTbPMTFrontRing_vis = aRunConfig->getRichTbPMTFrontRing_visib();
	G4cout<<"PMT front ring visib flag  "<<RichTbPMTFrontRing_vis<<G4endl;

	if(  (curDetector != 0)  && (curDetector-> getRichTbPMT() != 0)){

		G4cout<<"now setting front ring visib options  "<<RichTbPMTFrontRing_vis<<G4endl;

		G4LogicalVolume * RichTbPMTFrontRing_LV =curDetector->
				getRichTbPMT()-> getRichTbPMTFrontRingLVol();
		if(RichTbPMTFrontRing_LV != 0 ) {
			if(RichTbPMTFrontRing_vis == 0 ) {
				RichTbPMTFrontRing_LV ->SetVisAttributes(G4VisAttributes::Invisible);
			} else {
				G4VisAttributes * RichTbPMTFrontRing_LogVisAtt =
						new G4VisAttributes(G4Colour(1.0,0.0,0.0));
				if(RichTbPMTFrontRing_vis == 2 ) {
					RichTbPMTFrontRing_LogVisAtt ->SetForceSolid(false);
					RichTbPMTFrontRing_LogVisAtt ->SetForceWireframe(true);
				}
				if(RichTbPMTFrontRing_vis == 1 ) {
					RichTbPMTFrontRing_LogVisAtt ->SetForceSolid(true);
				}
				RichTbPMTFrontRing_LogVisAtt->SetVisibility(true);
				RichTbPMTFrontRing_LV -> SetVisAttributes(RichTbPMTFrontRing_LogVisAtt);


			}

		}

	}
  




	if( aRadiatorConfiguration == 2 ) {

		G4int  RichTbHpdQW_vis =  aRunConfig->getRichTbHpdQW_visib();
		if( (curDetector != 0) &&  (curDetector-> getRichTbHpd() != 0  ) ) {

			G4cout<<"now setting HPD QW visib options  "<< RichTbHpdQW_vis <<G4endl;

			G4LogicalVolume * RichTbHpdQW_LV =curDetector->getRichTbHpd()-> getRichTbHpdQuartzWLVol();
			if( RichTbHpdQW_LV != 0 ) {

				if( RichTbHpdQW_vis == 0 ){
					RichTbHpdQW_LV -> SetVisAttributes(G4VisAttributes::Invisible);
				} else {

					G4VisAttributes * RichTbHpdQW_LogVisAtt =
							new G4VisAttributes(G4Colour(1.0,0.6,0.0));
					if(  RichTbHpdQW_vis == 2 ) {
						RichTbHpdQW_LogVisAtt -> SetForceSolid(false);
						RichTbHpdQW_LogVisAtt -> SetForceWireframe(true);
					}
					if(  RichTbHpdQW_vis == 1 ) {
						RichTbHpdQW_LogVisAtt -> SetForceSolid(true);
					}
					RichTbHpdQW_LogVisAtt ->SetVisibility(true);
					RichTbHpdQW_LV ->  SetVisAttributes(RichTbHpdQW_LogVisAtt);


				}

			}

		}
    

		G4int  RichTbHpdPHC_vis =  aRunConfig->getRichTbHpdPHC_visib();
		if( (curDetector != 0) &&  (curDetector-> getRichTbHpd() != 0  ) ) {

			G4cout<<"now setting HPD PHC visib options  "<< RichTbHpdPHC_vis <<G4endl;

			G4LogicalVolume * RichTbHpdPHC_LV =curDetector->getRichTbHpd()->  getRichTbHpdPhCathodeLVol();
			if( RichTbHpdPHC_LV != 0 ) {

				if( RichTbHpdPHC_vis == 0 ){
					RichTbHpdPHC_LV -> SetVisAttributes(G4VisAttributes::Invisible);
				} else {

					G4VisAttributes * RichTbHpdPHC_LogVisAtt =
							new G4VisAttributes(G4Colour(0.3,0.6,0.8));
					if(  RichTbHpdPHC_vis == 2 ) {
						RichTbHpdPHC_LogVisAtt -> SetForceSolid(false);
						RichTbHpdPHC_LogVisAtt -> SetForceWireframe(true);
					}
					if(  RichTbHpdPHC_vis == 1 ) {
						RichTbHpdPHC_LogVisAtt -> SetForceSolid(true);
					}
					RichTbHpdPHC_LogVisAtt ->SetVisibility(true);
					RichTbHpdPHC_LV ->  SetVisAttributes(RichTbHpdPHC_LogVisAtt);


				}

			}

		}
    

		G4int  RichTbHpdSID_vis =  aRunConfig->getRichTbHpdSID_visib();
		if( (curDetector != 0) &&  (curDetector-> getRichTbHpd() != 0  ) ) {

			G4cout<<"now setting HPD SiDet visib options  "<< RichTbHpdSID_vis <<G4endl;

			G4LogicalVolume * RichTbHpdSID_LV =curDetector->getRichTbHpd()->  getRichTbHpdSiDetLVol ();
			if( RichTbHpdSID_LV != 0 ) {

				if( RichTbHpdSID_vis == 0 ){
					RichTbHpdSID_LV -> SetVisAttributes(G4VisAttributes::Invisible);
				} else {

					G4VisAttributes * RichTbHpdSID_LogVisAtt =
							new G4VisAttributes(G4Colour(0.3,0.6,0.8));
					if(  RichTbHpdSID_vis == 2 ) {
						RichTbHpdSID_LogVisAtt -> SetForceSolid(false);
						RichTbHpdSID_LogVisAtt -> SetForceWireframe(true);
					}
					if(  RichTbHpdSID_vis == 1 ) {
						RichTbHpdSID_LogVisAtt -> SetForceSolid(true);
					}
					RichTbHpdSID_LogVisAtt ->SetVisibility(true);
					RichTbHpdSID_LV ->  SetVisAttributes(RichTbHpdSID_LogVisAtt);


				}

			}

		}
    
    


		G4int  RichTbHpdENV_vis =  aRunConfig->getRichTbHpdENV_visib();
		if( (curDetector != 0) &&  (curDetector-> getRichTbHpd() != 0  ) ) {

			G4cout<<"now setting HPD Envelope tube  visib options  "<< RichTbHpdENV_vis <<G4endl;

			G4LogicalVolume * RichTbHpdENV_LV =curDetector->getRichTbHpd()->  getRichTbHpdEnvelopeTubeLVol  ();

			if( RichTbHpdENV_LV != 0 ) {

				if( RichTbHpdENV_vis == 0 ){
					RichTbHpdENV_LV -> SetVisAttributes(G4VisAttributes::Invisible);
				} else {

					G4VisAttributes * RichTbHpdENV_LogVisAtt =
							new G4VisAttributes(G4Colour(0.2,0.2,0.5));
					if(  RichTbHpdENV_vis == 2 ) {
						RichTbHpdENV_LogVisAtt -> SetForceSolid(false);
						RichTbHpdENV_LogVisAtt -> SetForceWireframe(true);
					}
					if(  RichTbHpdENV_vis == 1 ) {
						RichTbHpdENV_LogVisAtt -> SetForceSolid(true);
					}
					RichTbHpdENV_LogVisAtt ->SetVisibility(true);
					RichTbHpdENV_LV ->  SetVisAttributes(RichTbHpdENV_LogVisAtt);


				}

			}

		}

		G4int  RichTbHpdENVCAP_vis =  aRunConfig->getRichTbHpdENVCAP_visib();
		if( (curDetector != 0) &&  (curDetector-> getRichTbHpd() != 0  ) ) {

			G4cout<<"now setting HPD Envelope endcap visib options  "<< RichTbHpdENVCAP_vis <<G4endl;

			G4LogicalVolume * RichTbHpdENVCAP_LV =curDetector->getRichTbHpd()->  getRichTbHpdEnvelopeEndCapLVol();

			if( RichTbHpdENVCAP_LV != 0 ) {

				if( RichTbHpdENVCAP_vis == 0 ){
					RichTbHpdENVCAP_LV -> SetVisAttributes(G4VisAttributes::Invisible);
				} else {

					G4VisAttributes * RichTbHpdENVCAP_LogVisAtt =
							new G4VisAttributes(G4Colour(0.2,0.2,0.5));
					if(  RichTbHpdENVCAP_vis == 2 ) {
						RichTbHpdENVCAP_LogVisAtt -> SetForceSolid(false);
						RichTbHpdENVCAP_LogVisAtt -> SetForceWireframe(true);
					}
					if(  RichTbHpdENVCAP_vis == 1 ) {
						RichTbHpdENVCAP_LogVisAtt -> SetForceSolid(true);
					}
					RichTbHpdENVCAP_LogVisAtt ->SetVisibility(true);
					RichTbHpdENVCAP_LV ->  SetVisAttributes(RichTbHpdENVCAP_LogVisAtt);


				}

			}

		}


		G4int  RichTbHpdSM_vis =  aRunConfig->getRichTbHpdSM_visib();
		if( (curDetector != 0) &&  (curDetector-> getRichTbHpd() != 0  ) ) {

			G4cout<<"now setting HPD Smaster visib options  "<< RichTbHpdSM_vis <<G4endl;

			G4LogicalVolume * RichTbHpdSM_LV =curDetector->getRichTbHpd()-> getRichTbHpdSMasterLVol ();

			if( RichTbHpdSM_LV != 0 ) {

				if( RichTbHpdSM_vis == 0 ){
					RichTbHpdSM_LV -> SetVisAttributes(G4VisAttributes::Invisible);
				} else {

					G4VisAttributes * RichTbHpdSM_LogVisAtt =
							new G4VisAttributes(G4Colour(0.7,0.4,0.1));
					if(  RichTbHpdSM_vis == 2 ) {
						RichTbHpdSM_LogVisAtt -> SetForceSolid(false);
						RichTbHpdSM_LogVisAtt -> SetForceWireframe(true);
					}
					if(  RichTbHpdSM_vis == 1 ) {
						RichTbHpdSM_LogVisAtt -> SetForceSolid(true);
					}
					RichTbHpdSM_LogVisAtt ->SetVisibility(true);
					RichTbHpdSM_LV ->  SetVisAttributes(RichTbHpdSM_LogVisAtt);


				}

			}

		}

		G4int  RichTbHpdMas_vis =  aRunConfig->getRichTbHpdMas_visib();
		if( (curDetector != 0) &&  (curDetector-> getRichTbHpd() != 0  ) ) {

			G4cout<<"now setting HPD master visib options  "<< RichTbHpdMas_vis <<G4endl;

			G4LogicalVolume * RichTbHpdMas_LV =curDetector->getRichTbHpd()-> getRichTbHpdMasterLVol ();

			if( RichTbHpdMas_LV != 0 ) {

				if( RichTbHpdMas_vis == 0 ){
					RichTbHpdMas_LV -> SetVisAttributes(G4VisAttributes::Invisible);
				} else {

					G4VisAttributes * RichTbHpdMas_LogVisAtt =
							new G4VisAttributes(G4Colour(0.3,0.7,0.5));
					if(  RichTbHpdMas_vis == 2 ) {
						RichTbHpdMas_LogVisAtt -> SetForceSolid(false);
						RichTbHpdMas_LogVisAtt -> SetForceWireframe(true);
					}
					if(  RichTbHpdMas_vis == 1 ) {
						RichTbHpdMas_LogVisAtt -> SetForceSolid(true);
					}
					RichTbHpdMas_LogVisAtt ->SetVisibility(true);
					RichTbHpdMas_LV ->  SetVisAttributes(RichTbHpdMas_LogVisAtt);


				}

			}

		}

		G4int  RichTbHpdPix_vis =  aRunConfig->getRichTbHpdSiPix_visib();
		if( RichTbHpdPix_vis > 5 ) {

			if( (curDetector != 0) &&  (curDetector-> getRichTbHpd() != 0  ) ) {

				G4cout<<"now setting HPD si pixel  visib options  "<< RichTbHpdPix_vis <<G4endl;

				G4LogicalVolume * RichTbHpdPix_LV =curDetector->getRichTbHpd()-> getRichTbSiPixelLVol() ;
				if(  RichTbHpdPix_vis  == 10 ) {

					RichTbHpdPix_LV  -> SetVisAttributes(G4VisAttributes::Invisible);

				}else {

					G4VisAttributes * RichTbHpdPix_LogVisAtt =
							new G4VisAttributes(G4Colour(0.2,0.4,0.7));

					if(  RichTbHpdPix_vis == 12 ) {
						RichTbHpdPix_LogVisAtt -> SetForceSolid(false);
						RichTbHpdPix_LogVisAtt -> SetForceWireframe(true);
					}
					if(  RichTbHpdPix_vis == 11 ) {
						RichTbHpdPix_LogVisAtt -> SetForceSolid(true);
					}
					RichTbHpdPix_LogVisAtt  ->SetVisibility(true);
					RichTbHpdPix_LV ->  SetVisAttributes( RichTbHpdPix_LogVisAtt );


				}
			}
		}
	}
  

}



 

