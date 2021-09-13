#include <iostream>
#include "RichTbGeometryParameters.hh"
#include "RichTbMaterial.hh"
#include "RichTbGraphicsLbR.hh"
#include "G4LogicalVolume.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "RichTbRunConfig.hh"

RichTbGraphicsLbR::RichTbGraphicsLbR()
{ ; }
RichTbGraphicsLbR::RichTbGraphicsLbR(RichTbOpticksDetectorConstruction* aD ) {
  curDetector = aD ;
  RichTbRunConfig* aRunConfig=  RichTbRunConfig::getRunConfigInstance();
  G4int aRadiatorConfiguration =  aRunConfig ->getRadiatorConfiguration();
  G4int aGraphicsConfig =  aRunConfig -> getBatchModeFlag();
  if(aGraphicsConfig == 0 ){
    if(  aRadiatorConfiguration >= 40 ) {

      setGraphicsLbRAttributes();


    }

  }



}
RichTbGraphicsLbR::~RichTbGraphicsLbR(){  }
void RichTbGraphicsLbR::setGraphicsLbRAttributes() {
 RichTbRunConfig* aRunConfig=  RichTbRunConfig::getRunConfigInstance();

        // For Following variables on visibility
        //  0 means make the volume invisible;
        //                        1 means make it visible as a solid.
        //                        2 means make it visible as a wireframe.
  if(curDetector ) {
  RichTbLHCbExptHall* aLHCbExptHall = curDetector->getRichTbLHCbExptHall ();
  
  RichTbLHCbRich1Master* aRich1Master = curDetector->getRichTbLHCbRich1Master () ;
  RichTbLHCbRich1SubMaster*  aRich1SubMaster = curDetector->getRichTbLHCbRich1SubMaster();
  RichTbLHCbR1SphMirror* aR1SphMirror = curDetector->getRichTbLHCbR1SphMirror();
  RichTbLHCbR1FlatMirror* aR1FlatMirror = curDetector->getRichTbLHCbR1FlatMirror();
  RichTbLHCbR1MagShRegion* aR1MagShRegion =curDetector-> getRichTbLHCbR1MagShRegion() ;
  RichTbLHCbR1QW* aR1QW = curDetector->getRichTbLHCbR1QW();
  RichTbLHCbR1PhDetSupFrame* aR1PhDetSupFrame=curDetector->getRichTbLHCbR1PhDetSupFrame();
  RichTbLHCbR1Module * aR1Module = curDetector->getRichTbLHCbR1Module();
  RichTbLHCbR1EC * aR1EC = curDetector->getRichTbLHCbR1EC();
  RichTbLHCbR1Pmt * aR1Pmt =   curDetector->getRichTbLHCbR1Pmt() ;
  RichTbLHCbR1PmtComponents * aR1PmtComp = curDetector -> getRichTbLHCbR1PmtComponents();



  std::vector<G4LogicalVolume*> aR1_LV = {
    (aLHCbExptHall ? aLHCbExptHall->getRichTbLHCbExptHallLogicalVolume() : 0) ,
    (aRich1Master ?  aRich1Master->getRichTbLHCbRich1MasterLogicalVolume() : 0),
    (aRich1SubMaster ?  aRich1SubMaster->getRichTbLHCbRich1SubMasterLogicalVolume() : 0),
    (aR1SphMirror ? aR1SphMirror->getRichTbLHCbR1SphMirrorLogicalVolume() : 0),
    (aR1FlatMirror ? aR1FlatMirror->getRichTbLHCbR1FlatMirrorLogicalVolume() : 0),
    (aR1MagShRegion ? aR1MagShRegion->getRichTbLHCbR1MagShRegionLogicalVolume() : 0 ),
    (aR1QW ? aR1QW->getRichTbLHCbR1QWLogicalVolume() : 0 ),
    (aR1PhDetSupFrame ? aR1PhDetSupFrame->getRichTbLHCbR1PhDetSupFrameLogicalVolume() : 0 ),
    (  aR1Module ? aR1Module->getRichTbLbR1ModuleLogicalVolume(0) : 0 ),
    (  aR1EC  ? aR1EC-> getRichTbLbR1ECLogicalVolume(0,0) : 0 ), 
    (  aR1Pmt ? aR1Pmt -> getRichTbLbR1PmtLogicalVolume()  : 0 ),
    ( aR1PmtComp ? aR1PmtComp -> getRichTbLbR1PmtSubMasterLogicalVolume() : 0),
    ( aR1PmtComp ? aR1PmtComp ->  getRichTbLbR1PmtAnodeLogicalVolume(): 0),
    ( aR1PmtComp ? aR1PmtComp ->  getRichTbLbR1PmtQuartzLogicalVolume() : 0),
    ( aR1PmtComp ? aR1PmtComp ->   getRichTbLbR1PmtPhCathLogicalVolume() : 0),
    ( aR1PmtComp ? aR1PmtComp ->   getRichTbLbR1PmtSideEnvelopeLogicalVolume() : 0),
    ( aR1PmtComp ? aR1PmtComp ->   getRichTbLbR1PmtFrontRingLogicalVolume(): 0),
    ( aR1PhDetSupFrame  ? aR1PhDetSupFrame-> getRichTbLbR1ModuleBackPlLVol () : 0 )

  };

  //  (  aR1Pmt ? aR1Pmt -> getRichTbLbR1PmtLogicalVolume (0,0,0) : 0 ),

  // Use existing R1Module,R1EC and R1Pmt for the above vector

  std::vector<G4LogicalVolume*> aR1_LV_MEP = {  
    (  aR1Module ? aR1Module->getRichTbLbR1ModuleLogicalVolume(0) : 0 ),
    (  aR1EC  ? aR1EC-> getRichTbLbR1ECLogicalVolume(0,0) : 0 ) ,
    (  aR1Pmt ? aR1Pmt -> getRichTbLbR1PmtLogicalVolume() :0 )
  };


  //    (  aR1Pmt ? aR1Pmt -> getRichTbLbR1PmtLogicalVolume(0,0,0) :0 ),

  std::vector<G4int> aR1_vis = { aRunConfig -> getaLHCbExptHall_visib(),
				 aRunConfig ->getaRich1Master_visib(),aRunConfig->getaRich1SubMaster_visib(),
                                 aRunConfig ->getaR1SphMirror_visib(),aRunConfig ->getaR1FlatMirror_visib(),
                                 aRunConfig ->getaR1MagShRegion_visib(),aRunConfig ->getaR1QW_visib(),
                                 aRunConfig -> getaR1PhDetSupFrame_visib(),
                                 aRunConfig -> getaRichTbR1Module_visib(), 
                                 aRunConfig -> getaRichTbR1EC_visib(), 
                                 aRunConfig -> getaRichTbR1PmtMaster_visib(),
                                 aRunConfig -> getaRichTbR1PmtSMaser_visib(),
                                 aRunConfig -> getaRichTbR1PmtAnode_visib (),
                                 aRunConfig -> getaRichTbR1PmtQuartz_visib(),
                                 aRunConfig -> getaRichTbR1PmtPhCath_visib(),
                                 aRunConfig -> getaRichTbR1PmtSideWin_visib(),
                                 aRunConfig -> getaRichTbR1PmtFrontRing_visib(),
                                 aRunConfig -> getaRichTbR1ModuleBackPl_visib()
  };
  G4int aNumGrElm = (G4int) aR1_LV.size();
  //std::vector<std::vector<G4double> > aR1_vis_colour(aNumGrElm,std::vector<G4double>(3));
  std::vector<std::vector<G4double> > aR1_vis_colour { {0.,0.,1.}, 
      {0.6,0.3, 0.2},{0.8,0.1,0.3}, {0.2,0.4,0.9}, {0.5,0.2,0.3}, 
      {0.8,0.1,0.4}, {0.6,0.8,0.2}, {0.7,0.1,0.2},
				      {0.9,0.1, 0.5}, {0.2,0.9, 0.3}, {0.4,0.1, 0.7},
      {0.3,0.2,0.4}, {0.7,0.1,0.9}, {0.3,0.5,0.3},  {0.7,0.6,0.2}, {0.3,0.3,0.8}, {0.2,0.7,0.8},
      {0.2,0.2,0.5}
        };



  if( aNumGrElm != ( (G4int) (aR1_vis.size() ) ) || ( (G4int) (aR1_vis_colour.size()) )) 
                               G4cout<<" Inconsistent Graphics flag setting for R1 geom"<<G4endl;


  for (int ia=0 ; ia <   aNumGrElm; ia++ ) {
       
    if( aR1_LV[ia] != 0 ) {
      if( aR1_vis[ia] == 0 ) {
            aR1_LV[ia]->SetVisAttributes(G4VisAttributes::Invisible);
      }else {
	G4VisAttributes * aR1_vis_attr = new G4VisAttributes(G4Colour(aR1_vis_colour[ia][0],
                                                                      aR1_vis_colour[ia][1],
                                                                      aR1_vis_colour[ia][2]));
        if(aR1_vis[ia] == 2 ) {
           aR1_vis_attr->SetForceSolid(false);
           aR1_vis_attr->SetForceWireframe(true);
	}else if(aR1_vis[ia] == 1 ) {
           aR1_vis_attr->SetForceWireframe(false);
           aR1_vis_attr->SetForceSolid(true);
	}
        aR1_vis_attr->SetVisibility(true);
        aR1_LV[ia]->SetVisAttributes(aR1_vis_attr);
      }
    }
  }

     for (int iM=0; iM < RichTbLbNumModules; iM ++ ) {
          G4LogicalVolume* aM_LV = aR1Module-> getRichTbLbR1ModuleLogicalVolume(iM);
          if(aM_LV && aR1_LV_MEP[0] )  aM_LV -> SetVisAttributes(aR1_LV_MEP[0] ->GetVisAttributes() );
	  for (int iec=0; iec <  RichTbLbNumECInModule ; iec++ ) {
            G4LogicalVolume* aE_LV =  aR1EC -> getRichTbLbR1ECLogicalVolume(iec,iM) ;
	    if(aE_LV && aR1_LV_MEP[1] ) aE_LV-> SetVisAttributes( aR1_LV_MEP[1] ->GetVisAttributes() );


	    //  for (int ip=0; ip <  RichTbLbNumPmtInEC ; ip++ ) {

	    //  G4LogicalVolume* aP_LV = aR1Pmt -> getRichTbLbR1PmtLogicalVolume(ip, iec,iM);
            //  if(aP_LV && aR1_LV_MEP[2] ) aP_LV -> SetVisAttributes( aR1_LV_MEP[2] ->GetVisAttributes() );
	    //  }
	  }
          
     } 
  

  }


}
