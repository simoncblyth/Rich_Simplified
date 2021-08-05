// $Id: $
// Include files 



// local
#include "RichTbSurface.hh"
#include "G4LogicalBorderSurface.hh"
#include "RichTbSurfaceDefinition.hh"
#include "RichTbUpgradeDetectorConstruction.hh"
#include "RichTbPMT.hh"


//-----------------------------------------------------------------------------
// Implementation file for class : RichTbSurface
//
// 2003-11-25 : Sajan EASO
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbSurface::RichTbSurface(
  RichTbDetectorConstruction* aDet  ) {

  curDet= aDet;
  createBorderSurfaces();
  
}

RichTbSurface::~RichTbSurface(  ) {}

void RichTbSurface::createBorderSurfaces() 
{

  RichTbSurfaceDefinition* aSurfaceDef=
     RichTbSurfaceDefinition::getRichTbSurfaceDefinitionInstance();
 

  G4cout << "creating mirror surface" << G4endl; 
 	RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
	G4int aRadiatorConfiguration = aConfig ->getRadiatorConfiguration();
  G4int aMirrConfig =  aConfig ->  getRichTbMirrorGeomFlag();
  

  G4cout << "Radiator config in Surface " <<  aRadiatorConfiguration <<  G4endl; 
   
  if( aRadiatorConfiguration !=10   ){

   if( aRadiatorConfiguration !=6  ){
    

    G4LogicalBorderSurface* MirrorBorderSurface =
    new G4LogicalBorderSurface("RichTbMirrorSurface",
      curDet->getRichTbUpgradeRadiator()->getRichTbUpgradeRadiatorPVol(), 
      curDet-> getRichTbUpgradeMirror()-> getRichTbUpgradeMirrorPVol(),
      aSurfaceDef->getRichTbSphMirrorSurface());
    if( MirrorBorderSurface ) G4cout<<" Mirror Surface created " <<G4endl;
    
   }
  
  //      curDet->getRichTbUpgradeCrystalMaster()->getRichTbUpgradeCrystalMasterPVol(), 


   G4LogicalBorderSurface* VesselOuterSurface=
     new  G4LogicalBorderSurface("VesselOuterSurface",
     curDet-> getRichTbHall()-> getRichTbHallPhysicalVolume(),
      curDet->getRichTbUpgradeVessel()->getRichTbGasVesselPVol(), 
      aSurfaceDef-> getRichTbVesselSurface());

   G4LogicalBorderSurface* VesselOuterBackSurface =
     new  G4LogicalBorderSurface     ("VesselOuterBackSurface",
      curDet->getRichTbUpgradeVessel()->getRichTbGasVesselPVol(), 
      curDet-> getRichTbHall()-> getRichTbHallPhysicalVolume(),
      aSurfaceDef-> getRichTbVesselSurface());

   if(VesselOuterSurface && VesselOuterBackSurface) 
            G4cout<<"Vessel surfaces created" <<G4endl;
   
  }else  {

    // now for the geometry in 2017 with mirrors


    G4LogicalBorderSurface* MirrorParabolaBorderSurface =
    new G4LogicalBorderSurface("RichTbMirrorParabolaSurface",
       curDet->  getRichTbContainerVessel()-> getRichTbContainerVesselBoxPVol(),
       curDet->  getRichTbMirrParabola() -> getRichTbMirrParabolaPVol(), 
      aSurfaceDef->getRichTbSphMirrorSurface() );
    if(MirrorParabolaBorderSurface) 
       G4cout<<"Mirror parabola surface created"<<G4endl;
    
    
    if(aMirrConfig ==0 ) 
    {
      
        G4LogicalBorderSurface* MirrorSphBorderSurface =
        new G4LogicalBorderSurface("RichTbMirrorSphSurface",
        curDet->  getRichTbContainerVessel()-> getRichTbContainerVesselBoxPVol(),
        curDet->  getRichTbMirrorSph() -> getRichTbMirrSphPVol(), 
                               aSurfaceDef->getRichTbSphMirrorSurface() );

        if(MirrorSphBorderSurface) G4cout<<" Mirror Sph surface created "<<G4endl;
        
    }else if (aMirrConfig ==1 ) {
       G4LogicalBorderSurface*   LargeMirrorParabolaBorderSurface = 
          new G4LogicalBorderSurface("RichTbLargeMirrorParabolaSurface",        
          curDet->  getRichTbContainerVessel() ->  getRichTbContainerVesselBoxPVol(),
          curDet-> getRichTbLargeMirrorParabola() -> getRichTbLargeMirrorParabolaPVol(),
                                     aSurfaceDef->getRichTbSphMirrorSurface());
       
       if( LargeMirrorParabolaBorderSurface) G4cout<<" Mirror parabola surface created "<<G4endl;
       
    }
    
    
    

  }
  
  
  
  
   /*   for(G4int ih=0; ih<curDet->getRichTbPhDetSupFrame()-> getNumPMTVol();ih++){
     

   G4LogicalBorderSurface* PMTMasterToQuartzWSurface =
     new  G4LogicalBorderSurface("PMTMasterToQuartzWSurface",
      curDet->getRichTbPhDetSupFrame()-> 
       getSinglePMTVolume(ih)-> getRichTbPMTSMasterPVol(),
      curDet->getRichTbPhDetSupFrame()-> 
      getSinglePMTVolume(ih)-> getRichTbPMTQuartzWPVol(),
      aSurfaceDef->getRichTbPMTMasterQuartzWSurface());

   G4LogicalBorderSurface* PMTQuartzWToMasterSurface =
     new  G4LogicalBorderSurface("PMTQuartzWToMasterSurface",
      curDet->getRichTbPhDetSupFrame()-> 
      getSinglePMTVolume(ih)-> getRichTbPMTQuartzWPVol(),
      curDet->getRichTbPhDetSupFrame()-> 
       getSinglePMTVolume(ih)-> getRichTbPMTSMasterPVol(),
      aSurfaceDef->getRichTbPMTMasterQuartzWSurface());

   G4LogicalBorderSurface* PMTQuartzWToPhCathodeSurface =
     new     G4LogicalBorderSurface("PMTQuartzWToPhCathodeSurface",
      curDet->getRichTbPhDetSupFrame()-> 
      getSinglePMTVolume(ih)-> getRichTbPMTQuartzWPVol(),
      curDet->getRichTbPhDetSupFrame()->
      getSinglePMTVolume(ih)-> getRichTbPMTPhCathodePVol(),
      aSurfaceDef-> getRichTbPMTQuartzWPhCathodeSurface());
   
   G4LogicalBorderSurface* PMTPhCathodeToQuartzSurface =
     new     G4LogicalBorderSurface("PMTPhCathodeToQuartzSurface",
      curDet->getRichTbPhDetSupFrame()->
      getSinglePMTVolume(ih)-> getRichTbPMTPhCathodePVol(),
      curDet->getRichTbPhDetSupFrame()-> 
      getSinglePMTVolume(ih)-> getRichTbPMTQuartzWPVol(),
      aSurfaceDef-> getRichTbPMTQuartzWPhCathodeSurface());   

    G4LogicalBorderSurface* PMTKovarEnvelopeTubeSurface =
      new     G4LogicalBorderSurface("PMTKovarEnvelopeTubeSurface",
      curDet->getRichTbPhDetSupFrame()->
      getSinglePMTVolume(ih)-> getRichTbPMTSMasterPVol(),   
      curDet->getRichTbPhDetSupFrame()->
      getSinglePMTVolume(ih)->  getRichTbPMTEnvelopeTubePVol(),
      aSurfaceDef-> getRichTbKovarSurface());

    G4LogicalBorderSurface* PMTKovarEnvelopeEndCapSurface =
      new     G4LogicalBorderSurface("PMTKovarEnvelopeEndCapSurface",
      curDet->getRichTbPhDetSupFrame()->
      getSinglePMTVolume(ih)-> getRichTbPMTSMasterPVol(),   
      curDet->getRichTbPhDetSupFrame()->
      getSinglePMTVolume(ih)-> getRichTbPMTEnvelopeEndCapPVol(),
      aSurfaceDef-> getRichTbKovarSurface());

    G4LogicalBorderSurface* PMTSiDetSurface =
      new   G4LogicalBorderSurface("PMTSiDetSurface",
      curDet->getRichTbPhDetSupFrame()->
      getSinglePMTVolume(ih)-> getRichTbPMTSMasterPVol(),   
      curDet->getRichTbPhDetSupFrame()->
      getSinglePMTVolume(ih)-> getRichTbPMTSiDetPVol(),
      aSurfaceDef-> getRichTbSiDetSurface());

  
   }
   */   
      
}


//=============================================================================
