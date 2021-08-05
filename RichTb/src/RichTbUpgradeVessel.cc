// $Id: $
// Include files 



// local
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbHall.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbUpgradeVessel
//
// 2003-11-05 : Sajan EASO
// 2005-02-20:  SE Modifed for the 2004 testbeam.
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbUpgradeVessel::RichTbUpgradeVessel(RichTbHall* rTbHall  ) {

  aRTbHall = rTbHall;
  
  constructRichTbGasVessel();
  
}
RichTbUpgradeVessel::~RichTbUpgradeVessel(  )
{
}
void RichTbUpgradeVessel::constructRichTbGasVessel()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
  
  G4Box * RichTbVesselBox 
    = new G4Box("RichTbVesselBox", 0.5*RichTbVesselXSize,
                0.5*RichTbVesselYSize, 0.5*RichTbVesselZSize);
 
  //volume substraction
  /*
  G4Box* RichTbVesselUpsSubBox 
   = new G4Box("RichTbVesselUpsSubBox", 
              0.5*RichTbVesselUpsExternalPartXSize,
              0.5*RichTbVesselUpsExternalPartYLargeSize,
              0.5*RichTbVesselUpsExternalPartZLargeSize);
  

  G4ThreeVector VesselUpsSubPos(RichTbVesselUpsExternalPartXShift ,
                                RichTbVesselUpsExternalPartYShift,
                                RichTbVesselUpsExternalPartZShift);
  */

  G4ThreeVector VesselPos(RichTbVesselXLocation,
                          RichTbVesselYLocation,
                          RichTbVesselZLocation);
 
  G4RotationMatrix VesselUpsSubRot, VesselRotX,VesselRotY;

  G4int aSpeicalStudyVesselRotFlag =  
      aConfig ->getSpecialStudyVesselRotation();

  if( aSpeicalStudyVesselRotFlag != 1 ) {
    
  VesselRotX.rotateX(RichTbVesselXRotation);
  VesselRotY.rotateY(RichTbVesselYRotation);

  }
  
  //
  // G4cout<<" Vessel XRot Yrot "<<RichTbVesselXRotation<<"   "
  //      <<RichTbVesselYRotation<<G4endl;
  
  //G4Transform3D VesselUpsSubTransform(VesselUpsSubRot,VesselUpsSubPos);

  G4Transform3D VesselTransform(  VesselRotX * VesselRotY, VesselPos);
  
  /* G4SubtractionSolid* VesselUpsSub = 
      new G4SubtractionSolid("VesselUpsSub",  RichTbVesselBoxOverall ,
                             RichTbVesselUpsSubBox,VesselUpsSubTransform);
  
  */
    G4LogicalVolume* VesselLog;
    
     
    //air in the vessel
     VesselLog = 
       new G4LogicalVolume(RichTbVesselBox,
                           aMaterial->getNitrogenGas(), "VesselLog",0,0,0);

     //location of the vessel   
     G4VPhysicalVolume* VesselPhys =
       new G4PVPlacement(VesselTransform,VesselPhysName, VesselLog ,
                         aRTbHall->getRichTbHallPhysicalVolume(),
                         false,0);
     
     RichTbGasVesselLVol =  VesselLog;
     RichTbGasVesselPVol =  VesselPhys;
     

} 
void RichTbUpgradeVessel::constructRichTbUpgradeVesselEnvelope()
{
  
}


//=============================================================================
