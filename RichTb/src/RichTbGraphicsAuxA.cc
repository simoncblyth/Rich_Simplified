// Include files 
#include <iostream>
#include "RichTbGeometryParameters.hh"
#include "RichTbMaterial.hh"
#include "RichTbGraphics.hh"
#include "G4LogicalVolume.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "RichTbRunConfig.hh"
#include "RichTbPMT.hh"



// local
#include "RichTbGraphicsAuxA.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbGraphicsAuxA
//
// 2017-03-14 : Sajan Easo
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbGraphicsAuxA::RichTbGraphicsAuxA(RichTbDetectorConstruction* aDetector   ) {
    curDetector =  aDetector ;

}

//=============================================================================
// Destructor
//=============================================================================
RichTbGraphicsAuxA::~RichTbGraphicsAuxA() {} 

//=============================================================================

void RichTbGraphicsAuxA::setGraphicsAuxAttributes() {


	// For Following variables on visibility
	//  0 means make the volume invisible;
	//                        1 means make it visible as a solid.
	//                        2 means make it visible as a wireframe.

	RichTbRunConfig* aRunConfig=  RichTbRunConfig::getRunConfigInstance();
  //	G4int aRadiatorConfiguration =  aRunConfig ->getRadiatorConfiguration();
  


 	// now for the container vessel in 2017 for the photonic crystal samples

	G4int RichTbUpgradeCVessel_vis = aRunConfig->getRichTbUpgradeVessel_visib();

	 G4cout<<"container vessel visib flag  "<<RichTbUpgradeCVessel_vis<<G4endl;
 
	if(  (curDetector != 0)  && (curDetector-> getRichTbContainerVessel() != 0)) {

		    G4cout<<"now setting Cvessel visib options  "<<RichTbUpgradeCVessel_vis<<G4endl;

		G4LogicalVolume * RichTbUpgradeCVessel_LV =curDetector->
				 getRichTbContainerVessel() -> getRichTbContainerVesselBoxLVol();

    if(RichTbUpgradeCVessel_LV != 0 ){

      
			if(RichTbUpgradeCVessel_vis == 0 ) {
				RichTbUpgradeCVessel_LV ->SetVisAttributes(G4VisAttributes::Invisible);
			} else {
				G4VisAttributes * RichTbUpgradeCVessel_LogVisAtt =
						new G4VisAttributes(G4Colour(0.5,0.5,0.0));
				if(RichTbUpgradeCVessel_vis == 2 ) {
					RichTbUpgradeCVessel_LogVisAtt ->SetForceSolid(false);
					RichTbUpgradeCVessel_LogVisAtt ->SetForceWireframe(true);
				}
				if(RichTbUpgradeCVessel_vis == 1 ) {
					RichTbUpgradeCVessel_LogVisAtt ->SetForceSolid(true);
				}
				RichTbUpgradeCVessel_LogVisAtt->SetVisibility(true);
				RichTbUpgradeCVessel_LV -> SetVisAttributes(RichTbUpgradeCVessel_LogVisAtt);

			}
    }
  }

  // end of Container vessel visib attr


  // Now for polymerplus radiator

		G4int RichTbUpgradePolymerPlus_vis = aRunConfig->getRichTbUpgradeRadiator_visib();

	 G4cout<<"Polymer radiator visib flag  "<< RichTbUpgradePolymerPlus_vis   <<G4endl;
 
	if(  (curDetector != 0)  && (curDetector-> getRichTbPolymerPlusRadiator() != 0)) {

		    G4cout<<"now setting polymerplus visib options  "<< RichTbUpgradePolymerPlus_vis<<G4endl;

		G4LogicalVolume * RichTbUpgradePolymerPlus_LV =curDetector->
          getRichTbPolymerPlusRadiator() ->  getRichTbPolymerPlusLVol();

		    G4cout<<"now setting polymerplus visib options LV  "<< RichTbUpgradePolymerPlus_vis<< "  " 
              << RichTbUpgradePolymerPlus_LV <<G4endl;

    if(RichTbUpgradePolymerPlus_LV != 0 ){

      
			if(RichTbUpgradePolymerPlus_vis == 0 ) {
				RichTbUpgradePolymerPlus_LV ->SetVisAttributes(G4VisAttributes::Invisible);
			} else {

				G4VisAttributes * RichTbUpgradePolymerPlus_LogVisAtt =
						new G4VisAttributes(G4Colour(0.9,0.1,0.3));

        // G4cout<<"now setting polymerplus visib options LV  Att "<< RichTbUpgradePolymerPlus_vis<< "  " 
        //      << RichTbUpgradePolymerPlus_LV <<"   "<< RichTbUpgradePolymerPlus_LogVisAtt<<  G4endl;

				if(RichTbUpgradePolymerPlus_vis == 2 ) {
					RichTbUpgradePolymerPlus_LogVisAtt ->SetForceSolid(false);
					RichTbUpgradePolymerPlus_LogVisAtt ->SetForceWireframe(true);
				}
				if(RichTbUpgradePolymerPlus_vis == 1 ) {
					RichTbUpgradePolymerPlus_LogVisAtt ->SetForceSolid(true);
				}
				RichTbUpgradePolymerPlus_LogVisAtt->SetVisibility(true);
				RichTbUpgradePolymerPlus_LV -> SetVisAttributes(RichTbUpgradePolymerPlus_LogVisAtt);

      }
      
    }
    
  }
  
  

  // end of PolymerPlus radiator visib attr

  // Now for the  quartz radiator

		G4int RichTbUpgradeQuartzRadiator_vis = aRunConfig-> getRichTbQuartzRadiator_visib();


	 G4cout<<"Quartz radiator visib flag  "<< RichTbUpgradeQuartzRadiator_vis   <<G4endl;
 
	if(  (curDetector != 0)  && (curDetector-> getRichTbQuartzRadiator() != 0)) {

		    G4cout<<"now setting quartz radiator visib options  "<< RichTbUpgradeQuartzRadiator_vis<<G4endl;

		G4LogicalVolume * RichTbUpgradeQuartzEadiator_LV =curDetector->
          getRichTbQuartzRadiator() -> getRichTbQuartzRadiatorLVol ();

		    G4cout<<"now setting quartz radiator  visib options LV  "<< RichTbUpgradeQuartzRadiator_vis  << "  " 
              << RichTbUpgradeQuartzEadiator_LV  <<G4endl;

    if( RichTbUpgradeQuartzEadiator_LV  != 0 ){
          
			if(  RichTbUpgradeQuartzRadiator_vis == 0 ) {

				RichTbUpgradeQuartzEadiator_LV ->SetVisAttributes(G4VisAttributes::Invisible);
			} else {

				G4VisAttributes * RichTbUpgradeQuartzRadiator_LogVisAtt =
						new G4VisAttributes(G4Colour(0.2,0.2,0.3));


				if(RichTbUpgradeQuartzRadiator_vis == 2 ) {
					RichTbUpgradeQuartzRadiator_LogVisAtt ->SetForceSolid(false);
					RichTbUpgradeQuartzRadiator_LogVisAtt ->SetForceWireframe(true);
				}
				if(RichTbUpgradeQuartzRadiator_vis == 1 ) {
					RichTbUpgradeQuartzRadiator_LogVisAtt ->SetForceSolid(true);
				}
				RichTbUpgradeQuartzRadiator_LogVisAtt->SetVisibility(true);
				RichTbUpgradeQuartzEadiator_LV -> SetVisAttributes(RichTbUpgradeQuartzRadiator_LogVisAtt);

      }

    }
  }




// end quartx radiator visib
// now for quartz radiator cover visib


		G4int RichTbUpgradeQuartzRadiatorCover_vis = aRunConfig-> getRichTbQuartzRadiatorCover_visib();


	 G4cout<<"Quartz radiator cover visib flag  "<< RichTbUpgradeQuartzRadiatorCover_vis   <<G4endl;
 
	if(  (curDetector != 0)  && (curDetector-> getRichTbQuartzRadiator() != 0)) {

		    G4cout<<"now setting quartz radiator cover visib options  "<< RichTbUpgradeQuartzRadiatorCover_vis<<G4endl;

		G4LogicalVolume * RichTbUpgradeQuartzEadiatorDnsCover_LV =curDetector->
          getRichTbQuartzRadiator() -> getRichTbQuartzRadiatorDnsCoverLVol ();
		G4LogicalVolume * RichTbUpgradeQuartzEadiatorUpsCover_LV =curDetector->
          getRichTbQuartzRadiator() -> getRichTbQuartzRadiatorUpsCoverLVol ();

		    G4cout<<"now setting quartz radiator cover  visib options LV  "<< RichTbUpgradeQuartzRadiatorCover_vis  << "  " 
              << RichTbUpgradeQuartzEadiatorDnsCover_LV  <<"  "<<RichTbUpgradeQuartzEadiatorUpsCover_LV <<      G4endl;

        if( (RichTbUpgradeQuartzEadiatorDnsCover_LV  != 0) &&  (RichTbUpgradeQuartzEadiatorUpsCover_LV != 0 )    ){
          
			if(  RichTbUpgradeQuartzRadiatorCover_vis == 0 ) {

				RichTbUpgradeQuartzEadiatorDnsCover_LV ->SetVisAttributes(G4VisAttributes::Invisible);
				RichTbUpgradeQuartzEadiatorUpsCover_LV ->SetVisAttributes(G4VisAttributes::Invisible);

			} else {

				G4VisAttributes * RichTbUpgradeQuartzRadiatorCover_LogVisAtt =
						new G4VisAttributes(G4Colour(0.7,0.2,0.2));


				if(RichTbUpgradeQuartzRadiatorCover_vis == 2 ) {
					RichTbUpgradeQuartzRadiatorCover_LogVisAtt ->SetForceSolid(false);
					RichTbUpgradeQuartzRadiatorCover_LogVisAtt ->SetForceWireframe(true);
				}
				if(RichTbUpgradeQuartzRadiatorCover_vis == 1 ) {
					RichTbUpgradeQuartzRadiatorCover_LogVisAtt ->SetForceSolid(true);
				}
				RichTbUpgradeQuartzRadiatorCover_LogVisAtt->SetVisibility(true);
				RichTbUpgradeQuartzEadiatorDnsCover_LV -> SetVisAttributes(RichTbUpgradeQuartzRadiatorCover_LogVisAtt);
				RichTbUpgradeQuartzEadiatorUpsCover_LV -> SetVisAttributes(RichTbUpgradeQuartzRadiatorCover_LogVisAtt);

      }

    }
  }

  // now for the parabolic mirror

		G4int RichTbMirrorParab_vis = aRunConfig->getRichTbMirrParabola_visib();
    G4cout <<" Mirror parab visib flag "<< RichTbMirrorParab_vis <<G4endl;
  	if(  (curDetector != 0)  && (curDetector-> getRichTbMirrParabola() != 0)) {

      G4LogicalVolume *  RichTbUpgradeMirrParab_LV =  curDetector-> 
                         getRichTbMirrParabola()->getRichTbMirrParabolaLVol();
      if(  RichTbUpgradeMirrParab_LV  != 0 ) {
        
        if( RichTbMirrorParab_vis == 0 ) {
           RichTbUpgradeMirrParab_LV ->SetVisAttributes(G4VisAttributes::Invisible);
        }else {
          
			     	G4VisAttributes * RichTbUpgradeMirrParab_LogVisAtt =
						new G4VisAttributes(G4Colour(0.3,0.3,0.7));
            if(  RichTbMirrorParab_vis == 2 ) {
               RichTbUpgradeMirrParab_LogVisAtt->SetForceSolid(false);
               RichTbUpgradeMirrParab_LogVisAtt->SetForceWireframe(true);
                
            }
            if(RichTbMirrorParab_vis == 1 ) {
              RichTbUpgradeMirrParab_LogVisAtt->SetForceSolid(true);
            }
            RichTbUpgradeMirrParab_LogVisAtt->SetVisibility(true);
            
            RichTbUpgradeMirrParab_LV  -> SetVisAttributes(RichTbUpgradeMirrParab_LogVisAtt);    

        }
      }      
     
    }
    
    
    // end Mirr paraboloid graphics

    // Now for sph mirror
    
		G4int RichTbMirrorSph_vis = aRunConfig->getRichTbUpgradeMirror_visib();
    G4cout <<" Mirror Sph or large Parab visib flag "<< RichTbMirrorSph_vis <<G4endl;
    G4int aMirrGeomFlag =  aRunConfig->getRichTbMirrorGeomFlag();
    
    if(aMirrGeomFlag == 0 ){
      
  	if(  (curDetector != 0)  && (curDetector->getRichTbMirrorSph() != 0)) {

      G4LogicalVolume *  RichTbUpgradeMirrSph_LV =  
       curDetector->getRichTbMirrorSph()->getRichTbMirrSphLVol();
      if(  RichTbUpgradeMirrSph_LV  != 0 ) {
        
        if( RichTbMirrorSph_vis == 0 ) {
           RichTbUpgradeMirrSph_LV ->SetVisAttributes(G4VisAttributes::Invisible);
        }else {
          
			     	G4VisAttributes * RichTbUpgradeMirrSph_LogVisAtt =
						new G4VisAttributes(G4Colour(0.7,0.2,0.4));
            if(  RichTbMirrorSph_vis == 2 ) {
               RichTbUpgradeMirrSph_LogVisAtt->SetForceSolid(false);
               RichTbUpgradeMirrSph_LogVisAtt->SetForceWireframe(true);
                
            }
            if(RichTbMirrorSph_vis == 1 ) {
              RichTbUpgradeMirrSph_LogVisAtt->SetForceSolid(true);
            }
            RichTbUpgradeMirrSph_LogVisAtt->SetVisibility(true);
            
            RichTbUpgradeMirrSph_LV  -> SetVisAttributes(RichTbUpgradeMirrSph_LogVisAtt);    

        }
      }      
     
    }

    }
    
    

    // end sph mirror graphics

    // Now for the large parabolic mirror

    if( aMirrGeomFlag  == 1 ) {

      if(  (curDetector != 0)  && (curDetector->getRichTbLargeMirrorParabola() != 0)) {

        G4LogicalVolume *  RichTbUpgradeLargeMirrParab_LV = 
          curDetector->getRichTbLargeMirrorParabola()-> getRichTbLargeMirrorParabolaLVol() ;

        if( RichTbUpgradeLargeMirrParab_LV != 0 ) 
        {
          

        if( RichTbMirrorSph_vis == 0 ) {
              RichTbUpgradeLargeMirrParab_LV->SetVisAttributes(G4VisAttributes::Invisible);
           

        }else {
            G4VisAttributes * RichTbUpgradeMirrLargeParab_LogVisAtt = 
                      new G4VisAttributes(G4Colour(0.7,0.2,0.4));
            if(RichTbMirrorSph_vis == 2 ) {
                RichTbUpgradeMirrLargeParab_LogVisAtt->SetForceSolid(false);
                RichTbUpgradeMirrLargeParab_LogVisAtt->SetForceWireframe(true);

            }
            if(RichTbMirrorSph_vis == 1 ){
              RichTbUpgradeMirrLargeParab_LogVisAtt->SetForceSolid(true);
            }
             RichTbUpgradeMirrLargeParab_LogVisAtt ->SetVisibility(true);
             RichTbUpgradeLargeMirrParab_LV ->SetVisAttributes(RichTbUpgradeMirrLargeParab_LogVisAtt);
             
        }
      }
      }
      

    }
    
    


    // end large parabolic mirror


    // Now for PhCPHDetSupFrame
    G4int RichTbPhCDetSupFrame_vis = aRunConfig->getRichTbPhDFrame_visib();
    G4cout <<"PhDet frame visib "<< RichTbPhCDetSupFrame_vis <<G4endl;
    if(  (curDetector != 0)  && (curDetector->getRichTbPhCPhDetSupFrame()) ){
    
          G4LogicalVolume *  RichTbPhCPhDetSupFrame_LV = 
            curDetector->getRichTbPhCPhDetSupFrame()->  getRichTbPhCSupFrameLVol();
          if(RichTbPhCPhDetSupFrame_LV !=0 ){
            if(RichTbPhCDetSupFrame_vis == 0 ){
              RichTbPhCPhDetSupFrame_LV ->SetVisAttributes(G4VisAttributes::Invisible);
            }else{
              G4VisAttributes * RichTbUpgradePhCPhDet_LogVisAtt =
                 new G4VisAttributes(G4Colour(0.4,0.2,0.9));
              if( RichTbPhCDetSupFrame_vis == 2 ){
                 RichTbUpgradePhCPhDet_LogVisAtt ->SetForceSolid(false);
                 RichTbUpgradePhCPhDet_LogVisAtt ->SetForceWireframe(true);
              }
              if( RichTbPhCDetSupFrame_vis == 1 ){
                 RichTbUpgradePhCPhDet_LogVisAtt ->SetForceSolid(true);
              }
              RichTbUpgradePhCPhDet_LogVisAtt ->SetVisibility(true);
              RichTbPhCPhDetSupFrame_LV -> SetVisAttributes(RichTbUpgradePhCPhDet_LogVisAtt);  
             
            }
          }
    }
    
    // end  PhDet frame graphics
    // now for PhDet plane

    G4int RichTbPhCDetPlaneSeg_vis = aRunConfig->getRichTbPhCDetPlane_visib();
    G4cout <<"PhDet PlaneSeg visib "<< RichTbPhCDetPlaneSeg_vis <<G4endl;
    if(  (curDetector != 0)  && (curDetector->getRichTbPhCPhDetSupFrame()) ){
    
          G4LogicalVolume *  RichTbPhCPhDetPlaneSeg_LV = 
            curDetector->getRichTbPhCPhDetSupFrame()-> getRichTbPhCDetPlaneSegmentLVol();
          if(RichTbPhCPhDetPlaneSeg_LV !=0 ){
            if(RichTbPhCDetPlaneSeg_vis == 0 ){
              RichTbPhCPhDetPlaneSeg_LV ->SetVisAttributes(G4VisAttributes::Invisible);
            }else{
              G4VisAttributes * RichTbUpgradePhCDetPlane_LogVisAtt =
                 new G4VisAttributes(G4Colour(0.5,0.1,0.4));
              if( RichTbPhCDetPlaneSeg_vis == 2 ){
                 RichTbUpgradePhCDetPlane_LogVisAtt ->SetForceSolid(false);
                 RichTbUpgradePhCDetPlane_LogVisAtt ->SetForceWireframe(true);
              }
              if( RichTbPhCDetPlaneSeg_vis == 1 ){
                 RichTbUpgradePhCDetPlane_LogVisAtt ->SetForceSolid(true);
              }
              RichTbUpgradePhCDetPlane_LogVisAtt ->SetVisibility(true);
              RichTbPhCPhDetPlaneSeg_LV -> SetVisAttributes(RichTbUpgradePhCDetPlane_LogVisAtt);  
             
            }
          }
    }
    
    // end  PhDet plane graphics

            
            
            

          
          

    
    
      




    //
    
  G4cout <<"End Graphics with CVessel " <<G4endl;
 

 
  
}
  
  
