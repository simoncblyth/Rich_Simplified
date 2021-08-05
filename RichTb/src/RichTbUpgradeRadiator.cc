// $Id: $
// Include files

// local
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbUpgradeCrystal.hh"
#include "RichTbUpgradeRadiator.hh"
#include "RichTbUpgradeCrystalMaster.hh"
#include "RichTbUpgradeLTPhC.hh"
#include "RichTbHall.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4UnionSolid.hh"
#include "G4Box.hh"
#include "G4Orb.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbVessel
//
// 2003-11-05 : Sajan EASO
// 2005-02-20:  SE Modifed for the 2004 testbeam.
// 2015-06-12: Michele BLAGO modified for the 2015 testbeam.
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbUpgradeRadiator::RichTbUpgradeRadiator(RichTbUpgradeCrystalMaster* rTbCrystalMaster ) {

	aRTbCrystalMaster = rTbCrystalMaster;

	RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
	G4int aRadiatorConfiguration = aConfig ->getRadiatorConfiguration();

  rRichTbUpgradeLTPhC =0;
  
	if(aRadiatorConfiguration == 3  ) { 
          constructRichTbUpgradeRadiator15();
  }else if (aRadiatorConfiguration == 7) {
      constructRichTbUpgradeRadiator15();
   
	}
    else if (aRadiatorConfiguration == 6) {
     
    rRichTbUpgradeLTPhC = new  RichTbUpgradeLTPhC(rTbCrystalMaster );
    
 
  }else { constructRichTbUpgradeRadiator();
  } 

}

RichTbUpgradeRadiator::~RichTbUpgradeRadiator(  )
{
}

void RichTbUpgradeRadiator::constructRichTbUpgradeRadiator()
{
	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
	// RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();



	G4Box * Box1
	= new G4Box("Box1", 0.5*Box1XSize,
			0.5*Box1YSize, 0.5*Box1ZSize);

	G4Box * Box2
	= new G4Box("Box2", 0.5*Box2XSize,
			0.5*Box2YSize, 0.5*Box2ZSize);

	G4ThreeVector Box2Pos(Box2XLocation,
			Box2YLocation,
			Box2ZLocation);

	G4RotationMatrix Box2RotX,Box2RotY;

	G4Transform3D Box2Transform(Box2RotX * Box2RotY, Box2Pos);

	G4SubtractionSolid* SubBoxA =
			new G4SubtractionSolid("SubBoxA", Box1 ,
					Box2, Box2Transform);


	G4Box * RichTbUpgradeDarkCoverSubBox
	= new G4Box("RichTbUpgradeDarkCoverSubBox", 0.5*RichTbUpgradeDarkCoverXSize,
			0.5*RichTbUpgradeDarkCoverYSize, 0.5*RichTbUpgradeDarkCoverZSize);

	G4ThreeVector DarkCoverSubPos(RichTbUpgradeDarkCoverXLocation,
			RichTbUpgradeDarkCoverYLocation,
			RichTbUpgradeDarkCoverZLocation);

	G4RotationMatrix DarkCoverSubRotX, DarkCoverSubRotY;

	G4Transform3D DarkCoverSubTransform(DarkCoverSubRotX * DarkCoverSubRotY, DarkCoverSubPos);



	G4SubtractionSolid* BigBox =
			new G4SubtractionSolid("BigBox", SubBoxA ,
					RichTbUpgradeDarkCoverSubBox, DarkCoverSubTransform);


	G4Orb* Sphere = new G4Orb("Sphere", SphereRadius);

	G4ThreeVector BigBoxPos(BigBoxXLocation,
			BigBoxYLocation,
			BigBoxZLocation);

	G4RotationMatrix BigBoxRotX,BigBoxRotY;

	G4Transform3D BigBoxTransform(BigBoxRotX * BigBoxRotY, BigBoxPos);

	G4SubtractionSolid* RichTbUpgradeRadiator =
			new G4SubtractionSolid("Radiator", Sphere ,
					BigBox, BigBoxTransform);

	G4ThreeVector RadiatorPos(RichTbUpgradeRadiatorXLocation,
			RichTbUpgradeRadiatorYLocation,
			RichTbUpgradeRadiatorZLocation);

	G4RotationMatrix RadiatorRotX,RadiatorRotY;


	// RadiatorRotY.rotateY(acos(-1));

	G4Transform3D RadiatorTransform( RadiatorRotX * RadiatorRotY, RadiatorPos);


	G4LogicalVolume* RadiatorLog;


	//crystal material
	RadiatorLog =
			new G4LogicalVolume(RichTbUpgradeRadiator,
					aMaterial->getCrystalMaterial(), "RadiatorLog",0,0,0);

	//crystal location
	G4VPhysicalVolume* RadiatorPhys =
			new G4PVPlacement(RadiatorTransform, RadiatorPhysName, RadiatorLog ,
					aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),
					false,0);

	RichTbUpgradeRadiatorLVol =  RadiatorLog;
	RichTbUpgradeRadiatorPVol =  RadiatorPhys;


}

void RichTbUpgradeRadiator::constructRichTbUpgradeRadiator15()
{
	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
	// RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();

	G4Box * Box1 = new G4Box("Box1", 0.5*Box1XSize,	0.5*Box1YSize, 0.5*Box1ZSize);

	//	G4Box * Box2 = new G4Box("Box2", 0.5*Box2XSize15,	0.5*Box2YSize15, 0.5*Box2ZSize15);
	G4Tubs * Cyl1 = new G4Tubs("Cyl1", cylRmin, cylRmax, cylHalfLength, cylSPhi, cylDPhi);

	//	G4ThreeVector Box2Pos(Box2XLocation, Box2YLocation, Box2ZLocation);
	G4ThreeVector Cyl1Pos(Cyl1XLocation, Cyl1YLocation, Cyl1ZLocation);

	//	G4RotationMatrix Box2RotX,Box2RotY;
	G4RotationMatrix Cyl1RotX, Cyl1RotY;

	//	G4Transform3D Box2Transform(Box2RotX * Box2RotY, Box2Pos);
	G4Transform3D Cyl1Transform(Cyl1RotX * Cyl1RotY, Cyl1Pos);

	G4SubtractionSolid* SubBoxA = new G4SubtractionSolid("SubBoxA", Box1, Cyl1, Cyl1Transform);

//	G4Box * RichTbUpgradeDarkCoverSubBox = new G4Box("RichTbUpgradeDarkCoverSubBox",
//			0.5*RichTbUpgradeDarkCoverXSize15,
//			0.5*RichTbUpgradeDarkCoverYSize15,
//			0.5*RichTbUpgradeDarkCoverZSize15);
	G4Tubs * RichTbUpgradeDarkCoverSubTubs = new G4Tubs("Cyl2", cylDarkRmin, cylDarkRmax, cylDarkHalfLength, cylSPhi, cylDPhi);


	G4ThreeVector DarkCoverSubPos(RichTbUpgradeDarkCoverXLocation15,
			RichTbUpgradeDarkCoverYLocation15,
			RichTbUpgradeDarkCoverZLocation15);

	G4RotationMatrix DarkCoverSubRotX, DarkCoverSubRotY;

	G4Transform3D DarkCoverSubTransform(DarkCoverSubRotX * DarkCoverSubRotY, DarkCoverSubPos);

	G4SubtractionSolid* BigBox = new G4SubtractionSolid("BigBox", SubBoxA ,
			RichTbUpgradeDarkCoverSubTubs, DarkCoverSubTransform);



	//mirror subvolume
	G4double MirrPhiSize = 2 * CLHEP::pi * CLHEP::rad;

	// G4double MirrThetaStart = 0.0*rad;
	G4double MirrThetaStart = MirrorMinThetaExtent15;
	G4double MirrThetaSize = MirrorMaxThetaExtent15-MirrorMinThetaExtent15;

	G4double MirrPhiStart = 0.0 * CLHEP::rad;

	G4Sphere* MirrorFull =  new G4Sphere("MirrorFull",MirrorInnerRadius15,
			MirrorOuterRadius15,MirrPhiStart,
			MirrPhiSize,MirrThetaStart,
			MirrThetaSize);

	G4RotationMatrix MirrorRotationX, MirrorRotationY;
	MirrorRotationY.rotateY(180 * CLHEP::degree);

	G4ThreeVector MirrorPos(MirrorPosX15, MirrorPosY15, MirrorVolPosZ15);

	G4Transform3D MirrorTransform(MirrorRotationX * MirrorRotationY,
			MirrorPos);

//	G4SubtractionSolid* BigBox2 = new G4SubtractionSolid("BigBox2", BigBox ,
//			MirrorFull, MirrorTransform);
	//end mirror subvolume



	G4Orb* Sphere = new G4Orb("Sphere", SphereRadius15);

	G4UnionSolid * SpherePlusMirror = new G4UnionSolid("SpherePlusMirror", Sphere, MirrorFull, MirrorTransform);

	G4ThreeVector BigBoxPos(BigBoxXLocation, BigBoxYLocation, BigBoxZLocation);

	G4RotationMatrix BigBoxRotX,BigBoxRotY;

	G4Transform3D BigBoxTransform(BigBoxRotX * BigBoxRotY, BigBoxPos);

	G4SubtractionSolid* RichTbUpgradeRadiator = new G4SubtractionSolid("Radiator", SpherePlusMirror,
			BigBox, BigBoxTransform);

	G4ThreeVector RadiatorPos(RichTbUpgradeRadiatorXLocation15,
			RichTbUpgradeRadiatorYLocation15,
			RichTbUpgradeRadiatorZLocation15);

	G4RotationMatrix RadiatorRotX,RadiatorRotY;

	// RadiatorRotY.rotateY(acos(-1));

	G4Transform3D RadiatorTransform( RadiatorRotX * RadiatorRotY, RadiatorPos);

	G4LogicalVolume* RadiatorLog;

	//crystal material
	RadiatorLog = new G4LogicalVolume(RichTbUpgradeRadiator, aMaterial->getCrystalMaterial(), "RadiatorLog",0,0,0);

	//crystal location
	G4VPhysicalVolume* RadiatorPhys = new G4PVPlacement(RadiatorTransform,
			RadiatorPhysName, RadiatorLog,
			aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),
			false,0);

	RichTbUpgradeRadiatorLVol =  RadiatorLog;
	RichTbUpgradeRadiatorPVol =  RadiatorPhys;
//
//	G4Transform3D * testTrans;
//	G4Box * testbox = new G4Box("testbox", 0.5*10,	0.5*10, 0.5*10);
//	G4LogicalVolume * testL = new G4LogicalVolume(testbox, aMaterial->getCrystalMaterial(), "testL",0,0,0);
//	G4VPhysicalVolume * testP = new G4VPhysicalVolume(testTrans, "testP", testL, aRTbCrystalMaster->getRichTbUpgradeCrystalMasterPVol(),false,0);
//
//	testLvol = testL;
//	testPvol = testP;

}

void RichTbUpgradeRadiator::constructRichTbUpgradeRadiatorEnvelope() {}


//=============================================================================
