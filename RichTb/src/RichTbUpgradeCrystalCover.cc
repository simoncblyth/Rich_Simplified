// $Id: $
// Include files 

// local
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbUpgradeCrystalCover.hh"
#include "RichTbUpgradeCrystalMaster.hh"
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
// Implementation file for class : RichTbVessel
//
// 2003-11-05 : Sajan EASO
// 2005-02-20:  SE Modifed for the 2004 testbeam.
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbCrystalCover::RichTbCrystalCover(RichTbUpgradeCrystalMaster* rTbCrystalMaster) {

  aRTbCrystalMaster = rTbCrystalMaster;
  
  constructRichTbCrystalCover();
  
}
RichTbCrystalCover::~RichTbCrystalCover(  )
{
}
void RichTbCrystalCover::constructRichTbCrystalCover()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  // RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();
  
  G4Box * RichTbCrystalCoverBox 
    = new G4Box("RichTbCrystalCoverBox", 0.5*RichTbCrystalCoverXSize,
                0.5*RichTbCrystalCoverYSize, 0.5*RichTbCrystalCoverZSize);
 
  //volume substraction
  
  G4Box* RichTbCrystalCoverSubBox 
   = new G4Box("RichTbCrystalCoverSubBox", 
              0.5*RichTbCrystalCoverSubPartXSize,
              0.5*RichTbCrystalCoverSubPartYSize,
              0.5*RichTbCrystalCoverSubPartZSize);
  

  G4ThreeVector CrystalCoverSubPos(RichTbCrystalCoverSubPartXLocation , //!posizioni relative!
				   RichTbCrystalCoverSubPartYLocation,
				   RichTbCrystalCoverSubPartZLocation );

  G4ThreeVector CrystalCoverPos(RichTbCrystalCoverXLocation,
				RichTbCrystalCoverYLocation,
				RichTbCrystalCoverZLocation);
 
  G4RotationMatrix CrystalCoverSubRotX, CrystalCoverSubRotY, CrystalCoverRotX, CrystalCoverRotY;
  /*
  G4int aSpecialStudyCrystalCoverRotFlag =  
      aConfig ->getSpecialStudyCrystalRotation();

  if( aSpecialStudyCrystalCoverRotFlag != 1 ) {

    G4double CrystalRotX = aConfig ->getSpecialStudyCrystalRotationX();
    G4double CrystalRotY = aConfig ->getSpecialStudyCrystalRotationY();

    //now rotating the cover

    G4double CrystalCoverRadius = 0.5 * (RichTbCrystalCoverZSize 
					 - RichTbCrystalZSize);
    
    G4ThreeVector CrystalCoverPos(RichTbCrystalCoverXLocation 
				  - CrystalCoverRadius*sin(CrystalRotY),
				  RichTbCrystalCoverYLocation
				  + CrystalCoverRadius*sin(CrystalRotX) ,
				  RichTbCrystalCoverZLocation
				  + CrystalCoverRadius*(2+cos(CrystalRotY)+cos(CrystalRotX)));
    
    CrystalCoverRotX.rotateX(CrystalRotX);
    CrystalCoverRotY.rotateY(CrystalRotY);
  
    
    //now rotating the inner volume
    
     G4double CrystalCoverInnerRadius = 0.5 * (RichTbCrystalCoverSubPartZSize 
					 - RichTbCrystalZSize);

     G4ThreeVector CrystalCoverSubPos(RichTbCrystalCoverSubPartXLocation 
				  + CrystalCoverInnerRadius*sin(CrystalRotY),
				  RichTbCrystalCoverSubPartYLocation
				  - CrystalCoverInnerRadius*sin(CrystalRotX) ,
				  RichTbCrystalCoverSubPartZLocation
				  + CrystalCoverInnerRadius*(2+cos(CrystalRotY)+cos(CrystalRotX)));
    
     CrystalCoverSubRotX.rotateX(CrystalRotX);
     CrystalCoverSubRotY.rotateY(CrystalRotY);
    
     

  }
  */
  //
  // G4cout<<" Vessel XRot Yrot "<<RichTbVesselXRotation<<"   "
  //      <<RichTbVesselYRotation<<G4endl;

  G4Transform3D CrystalCoverTransform(CrystalCoverRotX * CrystalCoverRotY,
					 CrystalCoverPos);

  G4Transform3D CrystalCoverSubTransform(CrystalCoverSubRotX * CrystalCoverSubRotY,
					 CrystalCoverSubPos);
  
   G4SubtractionSolid* CrystalCover = 
      new G4SubtractionSolid("CrystalCover",  RichTbCrystalCoverBox,
                             RichTbCrystalCoverSubBox, CrystalCoverSubTransform);
  
  
    G4LogicalVolume* CrystalCoverLog;
    
     
    //air in the cover
     CrystalCoverLog = 
       new G4LogicalVolume(CrystalCover,
                           aMaterial->getCarbon(), "CrystalCoverLog",0,0,0);

     //location of the cover  
     G4VPhysicalVolume* CrystalCoverPhys =
       new G4PVPlacement(CrystalCoverTransform, CrystalCoverPhysName, CrystalCoverLog ,
                         aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),
                         false,0);
     
     RichTbCrystalCoverLVol =  CrystalCoverLog;
     RichTbCrystalCoverPVol =  CrystalCoverPhys;
     

} 
void RichTbCrystalCover::constructRichTbCrystalCoverEnvelope()
{
  
}


//=============================================================================
