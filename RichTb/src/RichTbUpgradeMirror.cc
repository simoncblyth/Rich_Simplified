// $Id: $
// Include files

#include "RichTbGeometryParameters.hh"
#include "globals.hh"
#include "RichTbRunConfig.hh"
#include "G4Sphere.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4Box.hh"
#include "G4SubtractionSolid.hh"

// local
#include "RichTbUpgradeMirror.hh"
#include "RichTbMaterial.hh"
#include "RichTbMiscNames.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbUpgradeMirror
//
// 2003-11-07 : Sajan EASO
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
//RichTbUpgradeMirror* RichTbUpgradeMirror::RichTbUpgradeMirrorInstance=0;

RichTbUpgradeMirror::RichTbUpgradeMirror( RichTbUpgradeCrystalMaster* aMaster, RichTbUpgradeRadiator* aRadiator) {
	RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
	G4int aRadiatorConfiguration = aConfig ->getRadiatorConfiguration();

	if((aRadiatorConfiguration == 3)||(aRadiatorConfiguration == 6)||(aRadiatorConfiguration == 7))    { 
      aRTbUpgradeRadiator = aRadiator;
  }else {
    motherMaster =  aMaster;
  }
  

	if(aRadiatorConfiguration == 3||(aRadiatorConfiguration == 7)) {
     constructRichTbUpgradeMirror15();
  } else if ( aRadiatorConfiguration !=6){ 
     constructRichTbUpgradeMirror();
  }
  

}
RichTbUpgradeMirror::~RichTbUpgradeMirror(  ) {
}
void RichTbUpgradeMirror::constructRichTbUpgradeMirror()
{
	//  RichTbRunConfig* RConfig = RichTbRunConfig::getRunConfigInstance();
	RichTbMaterial* aMaterial =  RichTbMaterial::getRichTbMaterialInstance();
	// G4int CurMirrorOrientationCode= RConfig -> getMirrorOrientCode();


	// in the following theta is for the horizontal extent of the
	// mirror and phi for the vertical extent of the mirror.

	// G4double MirrThetaSize = CLHEP::pi / 5 * CLHEP::rad;

	G4double MirrPhiSize  = 2 * CLHEP::pi * CLHEP::rad;

	// G4double MirrThetaStart = 0.0*rad;
	G4double MirrThetaStart = MirrorMinThetaExtent;
	G4double MirrThetaSize  = MirrorMaxThetaExtent-MirrorMinThetaExtent;


	G4double MirrPhiStart = 0.0 * CLHEP::rad;


	G4Sphere* MirrorFull =  new G4Sphere("MirrorFull",MirrorInnerRadius,
			MirrorOuterRadius,MirrPhiStart,
			MirrPhiSize,MirrThetaStart,
			MirrThetaSize);
	G4Box * BoxS
	= new G4Box("MirrBoxSub", 0.5* MirrorSubBoxLargeXSize,
			0.5* MirrorSubBoxLargeYSize , 0.5*MirrorSubBoxLargeZSize );


	G4RotationMatrix BoxTopRot, BoxBotRot;
	G4ThreeVector Box2PosTop (0.0, MirrorSubBoxYPosTop,0.0);
	G4ThreeVector Box2PosBot (0.0, MirrorSubBoxYPosBot,0.0);


	G4Transform3D BoxTopTransform(BoxTopRot, Box2PosTop );
	G4Transform3D BoxBotTransform(BoxBotRot, Box2PosBot );


	G4SubtractionSolid* MirrorHA =
			new G4SubtractionSolid("MirrorHA",MirrorFull  ,
					BoxS , BoxTopTransform );
	G4SubtractionSolid* MirrorSphe =
			new G4SubtractionSolid("MirrorSphe",MirrorHA  ,
					BoxS , BoxBotTransform );


	G4RotationMatrix MirrorRotationX, MirrorRotationY;
	MirrorRotationY.rotateY(180 * CLHEP::degree);

	G4ThreeVector MirrorPos ( MirrorPosX , MirrorPosY, MirrorPosZ);

	G4Transform3D MirrorTransform(  MirrorRotationX * MirrorRotationY,
			MirrorPos);

	G4LogicalVolume* MirrorLog =
			new G4LogicalVolume( MirrorSphe,aMaterial->getMirrorQuartz(),
					"MirrSpheLog",0,0,0);

	G4VPhysicalVolume* MirrorPhys=
			new  G4PVPlacement( MirrorTransform, MirrorPhysName,
					MirrorLog,
					motherMaster->getRichTbUpgradeCrystalMasterPVol(),false,0);

	RichTbUpgradeMirrorLVol =  MirrorLog;
	RichTbUpgradeMirrorPVol =   MirrorPhys;


}


//RichTbUpgradeMirror* RichTbUpgradeMirror::getRichTbUpgradeMirrorInstance()
//{
//  if( RichTbUpgradeMirrorInstance == 0 ) {
//    RichTbUpgradeMirrorInstance = new RichTbUpgradeMirror(RichTbCrystalMaster* aMaster  );
//
//  }
//  return RichTbUpgradeMirrorInstance;
//}


/*
RichTbUpgradeMirror* RichTbUpgradeMirror::getRichTbUpgradeMirrorInstance()
{
  if( RichTbUpgradeMirrorInstance == 0 )
    {
      G4cout << "ERROR - MIRROR NOT CONSTRUCTED" << G4endl;
    }
  return RichTbUpgradeMirrorInstance;
}
 */
// END OF CHANGE


void RichTbUpgradeMirror::constructRichTbUpgradeMirror15()
{
	//  RichTbRunConfig* RConfig = RichTbRunConfig::getRunConfigInstance();
	RichTbMaterial* aMaterial =  RichTbMaterial::getRichTbMaterialInstance();
	// G4int CurMirrorOrientationCode= RConfig -> getMirrorOrientCode();

	// in the following theta is for the horizontal extent of the
	// mirror and phi for the vertical extent of the mirror.

	// G4double MirrThetaSize = CLHEP::pi/5*rad;

	G4double MirrPhiSize = 2* CLHEP::pi / CLHEP::rad ;

	// G4double MirrThetaStart = 0.0* CLHEP::rad;
	G4double MirrThetaStart = MirrorMinThetaExtent15;
	G4double MirrThetaSize = MirrorMaxThetaExtent15-MirrorMinThetaExtent15;

	G4double MirrPhiStart = 0.0 * CLHEP::rad;

	G4Sphere* MirrorFull =  new G4Sphere("MirrorFull",MirrorInnerRadius15,
			MirrorOuterRadius15,MirrPhiStart,
			MirrPhiSize,MirrThetaStart,
			MirrThetaSize);

//	G4Box * BoxS = new G4Box("MirrBoxSub", 0.5* MirrorSubBoxLargeXSize,
//			0.5* MirrorSubBoxLargeYSize , 0.5*MirrorSubBoxLargeZSize );
//
//	G4RotationMatrix BoxTopRot, BoxBotRot;
//	G4ThreeVector Box2PosTop(0.0,MirrorSubBoxYPosTop,0.0);
//	G4ThreeVector Box2PosBot(0.0,MirrorSubBoxYPosBot,0.0);
//
//	G4Transform3D BoxTopTransform(BoxTopRot, Box2PosTop);
//	G4Transform3D BoxBotTransform(BoxBotRot, Box2PosBot);
//
//	G4SubtractionSolid* MirrorHA = new G4SubtractionSolid("MirrorHA",MirrorFull,
//			BoxS, BoxTopTransform);
//
//	G4SubtractionSolid* MirrorSphe = new G4SubtractionSolid("MirrorSphe",MirrorHA,
//			BoxS, BoxBotTransform);

	G4RotationMatrix MirrorRotationX, MirrorRotationY;
	MirrorRotationY.rotateY(180 * CLHEP::degree);

	G4ThreeVector MirrorPos(MirrorPosX15, MirrorPosY15, MirrorVolPosZ15);

	G4Transform3D MirrorTransform(MirrorRotationX * MirrorRotationY,
			MirrorPos);

//	G4LogicalVolume* MirrorLog = new G4LogicalVolume(MirrorSphe,
//			aMaterial->getMirrorQuartz(),
//			"MirrSpheLog",0,0,0);
	G4LogicalVolume* MirrorLog = new G4LogicalVolume(MirrorFull,
			aMaterial->getMirrorQuartz(),
			"MirrSpheLog",0,0,0);

	G4VPhysicalVolume* MirrorPhys= new G4PVPlacement(MirrorTransform,
			MirrorPhysName,
			MirrorLog,
//			motherMaster->getRichTbUpgradeCrystalMasterPVol(),false,0);
			aRTbUpgradeRadiator->getRichTbUpgradeRadiatorPVol(),false,0);


	RichTbUpgradeMirrorLVol = MirrorLog;
	RichTbUpgradeMirrorPVol = MirrorPhys;
}

//=============================================================================
