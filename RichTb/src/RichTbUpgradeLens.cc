// $Id: $
// Include files

// local
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbUpgradeLens.hh"
#include "RichTbHall.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4Box.hh"
#include "G4Orb.hh"
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
RichTbLens::RichTbLens(RichTbUpgradeCrystalMaster* rTbCrystalMaster ) {

  aRTbCrystalMaster = rTbCrystalMaster;

  constructRichTbLens();

}
RichTbLens::~RichTbLens(  )
{
}
void RichTbLens::constructRichTbLens()
{
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  // RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();


  G4Orb * Sph1 = new G4Orb("Sph1", SphRadius1);

  G4Orb * Sph2 = new G4Orb("Sph2", SphRadius2);

  //   G4int aSpecialStudyCrystalRotFlag =
  //    aConfig ->getSpecialStudyCrystalRotation();





  G4double RichTbSph2XLocation, RichTbSph2YLocation, RichTbSph2ZLocation;

  RichTbSph2XLocation = 0.0 * CLHEP::mm;
  RichTbSph2YLocation = 0.0 * CLHEP::mm;
  RichTbSph2ZLocation = DistanceSph;
  G4cout << "distance " << RichTbSph2ZLocation  << G4endl;

  G4ThreeVector Sph2Pos(RichTbSph2XLocation,
                        RichTbSph2YLocation,
                        RichTbSph2ZLocation);

  G4RotationMatrix Sph2RotX, Sph2RotY;



  G4Transform3D Sph2Transform(Sph2RotX * Sph2RotY,Sph2Pos);

  G4SubtractionSolid* A =
      new G4SubtractionSolid("A", Sph1, Sph2, Sph2Transform);

  G4ThreeVector APos( 0.0 * CLHEP::mm,
                      0.0 * CLHEP::mm,
                      0.0 * CLHEP::mm);

  G4RotationMatrix ARotX, ARotY;

  G4Transform3D ATransform(ARotX * ARotY, APos);

  G4SubtractionSolid* Lens =
      new G4SubtractionSolid("Lens", Sph2, A, ATransform);
  /*
  G4Box* C = new G4Box("CBox", 0.5*CBoxXSize,
                0.5*CBoxYSize, 0.5*CBoxZSize);
  G4RotationMatrix CRotX, CRotY;
  G4ThreeVector CPos( 0.0 * CLHEP::mm,
                      0.0 * CLHEP::mm,
                     -0.5*CBoxZSize + SphRadius1 - 55.0 * CLHEP::mm  );

  G4Transform3D CTransform(CRotX * CRotY, CPos);

  G4SubtractionSolid* Lens =
      new G4SubtractionSolid("Lens", B, C, ATransform);
  */

  G4ThreeVector LensPos(RichTbLensXLocation,
                          RichTbLensYLocation,
                          RichTbLensZLocation);

  G4RotationMatrix LensRotX, LensRotY;
  /*
 if( aSpecialStudyCrystalRotFlag != 1 ) {

    LensRotX.rotateX(aConfig ->getSpecialStudyCrystalRotationX());
    LensRotY.rotateY(aConfig ->getSpecialStudyCrystalRotationY());

  }

  */

  G4Transform3D LensTransform(  LensRotX * LensRotY, LensPos);


  G4LogicalVolume* LensLog;


    //lens logical volume
     LensLog =
       new G4LogicalVolume(Lens,
                           aMaterial->getPMTQuartzWindowMaterial(), "LensLog",0,0,0);

     //lens physical volume
     G4VPhysicalVolume* LensPhys =
       new G4PVPlacement(LensTransform, LensPhysName, LensLog ,
                         aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),
                         false,0);

     RichTbLensLVol =  LensLog;
     RichTbLensPVol =  LensPhys;


}
void RichTbLens::constructRichTbLensEnvelope()
{

}


//=============================================================================
