// $Id: $
// Include files

// local
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbUpgradeDarkCover.hh"
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
#include "G4Sphere.hh"
#include "G4Tubs.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbVessel
//
// 2003-11-05 : Sajan EASO
// 2005-02-20:  SE Modifed for the 2004 testbeam.
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbUpgradeDarkCover::RichTbUpgradeDarkCover(RichTbUpgradeRadiator* arTbRadiator ) {

	aRTbUpgradeRadiator = arTbRadiator;

  //	RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
  //	G4int aRadiatorConfiguration = aConfig ->getRadiatorConfiguration();
  

}
RichTbUpgradeDarkCover::~RichTbUpgradeDarkCover(  )
{
}

void RichTbUpgradeDarkCover::constructRichTbUpgradeDarkCover()
{
	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
	//RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();

	G4Box * RichTbUpgradeDarkCoverBox
	= new G4Box("RichTbUpgradeDarkCoverBox", 0.5*RichTbUpgradeDarkCoverXSize,
			0.5*RichTbUpgradeDarkCoverYSize, 0.5*RichTbUpgradeDarkCoverZSize);

	G4ThreeVector DarkCoverPos(RichTbUpgradeDarkCoverXLocation,
			RichTbUpgradeDarkCoverYLocation,
			RichTbUpgradeDarkCoverZLocation);

	G4RotationMatrix DarkCoverRotX, DarkCoverRotY;

	G4Transform3D DarkCoverTransform(  DarkCoverRotX * DarkCoverRotY, DarkCoverPos);

	/* G4SubtractionSolid* VesselUpsSub =
      new G4SubtractionSolid("VesselUpsSub",  RichTbVesselBoxOverall ,
                             RichTbVesselUpsSubBox,VesselUpsSubTransform);

	 */
	G4LogicalVolume* DarkCoverLog;



	DarkCoverLog =
			new G4LogicalVolume(RichTbUpgradeDarkCoverBox,
					aMaterial->getCarbon(), "DarkCoverLog",0,0,0);


	G4VPhysicalVolume* DarkCoverPhys =
			new G4PVPlacement(DarkCoverTransform, DarkCoverPhysName, DarkCoverLog ,
					aRTbUpgradeRadiator->getRichTbUpgradeRadiatorPVol(),
					false,0);

	RichTbUpgradeDarkCoverLVol =  DarkCoverLog;
	RichTbUpgradeDarkCoverPVol =  DarkCoverPhys;



}
void RichTbUpgradeDarkCover::constructRichTbUpgradeUpsDarkCoverEnvelope(RichTbUpgradeCrystalMaster* aMaster  )
{
	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

	G4double DarkPhiStart = 0.0* CLHEP::rad;
	G4double DarkPhiSize=2*CLHEP::pi*CLHEP::rad;
	G4double DarkThetaStart = 0.0*CLHEP::rad;
	G4double DarkThetaSize= CLHEP::pi / 5 * CLHEP::rad;

	G4Sphere* UpsDarkFull =  new G4Sphere("MirrorFull", RichTbDarkUpsInnerRadius,
			RichTbDarkUpsOuterRadius,DarkPhiStart ,
			DarkPhiSize , DarkThetaStart,
			DarkThetaSize);

	G4Box * BoxU
	= new G4Box("DarkBoxSub", 0.5* MirrorSubBoxLargeXSize,
			0.5* MirrorSubBoxLargeYSize , 0.5*MirrorSubBoxLargeZSize );

	G4RotationMatrix BoxTopRot, BoxBotRot;
	G4ThreeVector Box2PosTop (0.0, MirrorSubBoxYPosTop,0.0);
	G4ThreeVector Box2PosBot (0.0, MirrorSubBoxYPosBot,0.0);
	G4Transform3D BoxTopTransform(BoxTopRot, Box2PosTop );
	G4Transform3D BoxBotTransform(BoxBotRot, Box2PosBot );


	G4SubtractionSolid* DarkHA =
			new G4SubtractionSolid("DarkHA",UpsDarkFull  ,
					BoxU , BoxTopTransform );

	G4SubtractionSolid* UpsDarkSphe =
			new G4SubtractionSolid("UpsDarkSphe",DarkHA  ,
					BoxU , BoxBotTransform );

	G4RotationMatrix UpsDarkRotationX, UpsDarkRotationY;
	UpsDarkRotationY.rotateY(180 * CLHEP::degree);
	G4ThreeVector UpsDarkPos ( MirrorPosX , MirrorPosY, MirrorPosZ);


	G4Transform3D UpsDarkTransform(  UpsDarkRotationX * UpsDarkRotationY, UpsDarkPos);

	G4LogicalVolume* UpsDarkLog =
			new G4LogicalVolume( UpsDarkSphe,aMaterial->getCarbon(),
					"UpsDarkSpheLog",0,0,0);

	G4VPhysicalVolume* UpsDarkPhys=
			new  G4PVPlacement( UpsDarkTransform, "UpsDarkSphePhys",
					UpsDarkLog,aMaster->getRichTbUpgradeCrystalMasterPVol(),false,0);


	RichTbUpgradeUpsDarkCoverLVol =  UpsDarkLog;
	RichTbUpgradeUpsDarkCoverPVol =  UpsDarkPhys;






}
void RichTbUpgradeDarkCover::constructRichTbUpgradeSideDarkCoverEnvelope(RichTbUpgradeCrystalMaster* aMasterC  )
{
	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

	G4Box * BoxT
	= new G4Box("DarkBoxSide", 0.5* RichTbDarkSideXSize ,
			0.5* RichTbDarkSideYSize  , 0.5*RichTbDarkSideZSize  );
	G4RotationMatrix BoxTopRot, BoxBotRot;
	G4ThreeVector BoxTPosTop ( RichTbDarkSideXLocation,RichTbDarkSideYTopLocation ,RichTbDarkSideZLocation );
	G4ThreeVector BoxTPosBot ( RichTbDarkSideXLocation,RichTbDarkSideYBotLocation ,RichTbDarkSideZLocation);
	G4Transform3D BoxTTopTransform(BoxTopRot, BoxTPosTop );
	G4Transform3D BoxTBotTransform(BoxBotRot, BoxTPosBot );
	G4LogicalVolume* SideDarkLog =
			new G4LogicalVolume( BoxT,aMaterial->getCarbon(),
					"SideDarkLog",0,0,0);
	G4VPhysicalVolume* SideDarkTopPhys=
			new  G4PVPlacement( BoxTTopTransform, "SideDarkTopPhys",
					SideDarkLog,aMasterC->getRichTbUpgradeCrystalMasterPVol(),false,0);
	G4VPhysicalVolume* SideDarkBotPhys=
			new  G4PVPlacement( BoxTBotTransform, "SideDarkBotPhys",
					SideDarkLog,aMasterC->getRichTbUpgradeCrystalMasterPVol(),false,0);

	RichTbUpgradeSideDarkCoverLVol =  SideDarkLog;
	RichTbUpgradeSideTopDarkCoverPVol = SideDarkTopPhys;
	RichTbUpgradeSideBotDarkCoverPVol = SideDarkBotPhys;

}

void RichTbUpgradeDarkCover::constructRichTbUpgradeDarkCover15()
{

  // This is for the dark cover downstream of the spherical radaitor.

	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
	//RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();

//	G4Box * RichTbUpgradeDarkCoverBox = new G4Box("RichTbUpgradeDarkCoverBox",
//			0.5*RichTbUpgradeDarkCoverXSize15,
//			0.5*RichTbUpgradeDarkCoverYSize15,
//			0.5*RichTbUpgradeDarkCoverZSize15);

	G4Tubs * RichTbUpgradeDarkCoverSubTubs = new G4Tubs("RichTbUpgradeDarkCoverCyl", cylDarkRmin,
             cylDarkRmax, cylDarkHalfLength, cylSPhi, cylDPhi);


	G4ThreeVector DarkCoverPos(RichTbUpgradeDarkCoverXLocation15,
			RichTbUpgradeDarkCoverYLocation15,
			RichTbUpgradeDarkCoverZLocation15);

	G4RotationMatrix DarkCoverRotX,DarkCoverRotY;
	G4Transform3D DarkCoverTransform(DarkCoverRotX * DarkCoverRotY, DarkCoverPos);

	/* G4SubtractionSolid* VesselUpsSub =
      new G4SubtractionSolid("VesselUpsSub",  RichTbVesselBoxOverall ,
                             RichTbVesselUpsSubBox,VesselUpsSubTransform);
	 */

	G4LogicalVolume* DarkCoverLog;
	DarkCoverLog = new G4LogicalVolume(RichTbUpgradeDarkCoverSubTubs,
			aMaterial->getCarbon(), "DarkCoverLog",0,0,0);


	G4VPhysicalVolume* DarkCoverPhys = new G4PVPlacement(DarkCoverTransform,
			DarkCoverPhysName, DarkCoverLog ,
			aRTbUpgradeRadiator->getRichTbUpgradeRadiatorPVol(),
			false,0);

	RichTbUpgradeDarkCoverLVol =  DarkCoverLog;
	RichTbUpgradeDarkCoverPVol =  DarkCoverPhys;
}

void RichTbUpgradeDarkCover::constructRichTbUpgradeUpsDarkCoverEnvelope15(RichTbUpgradeCrystalMaster* aMaster)
{
	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

	G4double DarkPhiStart = 0.0 * CLHEP::rad;
	G4double DarkPhiSize=2 * CLHEP::pi * CLHEP::rad;
	G4double DarkThetaStart = 0.0 * CLHEP::rad;
	G4double DarkThetaSize= CLHEP::pi / 5 * CLHEP::rad;

	G4Sphere* UpsDarkFull =  new G4Sphere("MirrorFull", RichTbDarkUpsInnerRadius15,
			RichTbDarkUpsOuterRadius15,DarkPhiStart,
			DarkPhiSize, DarkThetaStart,
			DarkThetaSize);
	//
	//	G4Box * BoxU = new G4Box("DarkBoxSub", 0.5*MirrorSubBoxLargeXSize,
	//			0.5*MirrorSubBoxLargeYSize, 0.5*MirrorSubBoxLargeZSize);
	//
	//	G4RotationMatrix BoxTopRot, BoxBotRot;
	//	G4ThreeVector Box2PosTop (0.0, MirrorSubBoxYPosTop,0.0);
	//	G4ThreeVector Box2PosBot (0.0, MirrorSubBoxYPosBot,0.0);
	//	G4Transform3D BoxTopTransform(BoxTopRot, Box2PosTop);
	//	G4Transform3D BoxBotTransform(BoxBotRot, Box2PosBot);
	//
	//	G4SubtractionSolid* DarkHA = new G4SubtractionSolid("DarkHA",UpsDarkFull,
	//			BoxU, BoxTopTransform);
	//
	//	G4SubtractionSolid* UpsDarkSphe = new G4SubtractionSolid("UpsDarkSphe",DarkHA,
	//			BoxU, BoxBotTransform);

	G4RotationMatrix UpsDarkRotationX, UpsDarkRotationY;
	UpsDarkRotationY.rotateY(180 * CLHEP::degree);
	G4ThreeVector UpsDarkPos(MirrorPosX15, MirrorPosY15, MirrorPosZ15);

	G4Transform3D UpsDarkTransform(UpsDarkRotationX * UpsDarkRotationY, UpsDarkPos);

	//	G4LogicalVolume* UpsDarkLog = new G4LogicalVolume(UpsDarkSphe,aMaterial->getCarbon(),
	//					"UpsDarkSpheLog",0,0,0);
	G4LogicalVolume* UpsDarkLog = new G4LogicalVolume(UpsDarkFull,aMaterial->getCarbon(),
			"UpsDarkSpheLog",0,0,0);

	G4VPhysicalVolume* UpsDarkPhys= new  G4PVPlacement(UpsDarkTransform, "UpsDarkSphePhys",
			UpsDarkLog,aMaster->getRichTbUpgradeCrystalMasterPVol(),false,0);


	RichTbUpgradeUpsDarkCoverLVol =  UpsDarkLog;
	RichTbUpgradeUpsDarkCoverPVol =  UpsDarkPhys;
}

void RichTbUpgradeDarkCover::constructRichTbUpgradeSideDarkCoverEnvelope15(RichTbUpgradeCrystalMaster* aMasterC)
{
	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

	G4Box * BoxOut = new G4Box("BoxOut",
			0.5 * RichTbDarkSideXSize15,
			0.5 * RichTbDarkSideYSize15,
			0.5 * RichTbDarkSideZSize15);

	G4Box * BoxInn = new G4Box("BoxInn",
			0.5 * BoxInnXSize15,
			0.5 * BoxInnYSize15,
			0.5 * BoxInnZSize15);

	G4RotationMatrix BoxOutRot, BoxInnRot;
	G4ThreeVector BoxTPosOut(RichTbDarkSideXLocation15,RichTbDarkSideYLocation15,RichTbDarkSideZLocation15);
	//	G4ThreeVector BoxTPosInn(RichTbDarkSideXLocation15,RichTbDarkSideYLocation15,RichTbDarkSideZLocation15);
	G4Transform3D BoxTOutTransform(BoxOutRot, BoxTPosOut);
	//	G4Transform3D BoxTInnTransform(BoxInnRot, BoxTPosInn);

	G4SubtractionSolid * DarkBox = new G4SubtractionSolid("DarkBox", BoxOut, BoxInn);

	G4LogicalVolume* SideDarkLog = new G4LogicalVolume(DarkBox,aMaterial->getCarbon(),
			"SideDarkLog",0,0,0);

	G4VPhysicalVolume* SideDarkPhys = new G4PVPlacement(BoxTOutTransform,"SideDarkTopPhys",
			SideDarkLog,aMasterC->getRichTbUpgradeCrystalMasterPVol(),false,0);

//	G4LogicalVolume* SideDarkLog = new G4LogicalVolume(BoxT,aMaterial->getCarbon(),
//			"SideDarkLog",0,0,0);
//	G4VPhysicalVolume* SideDarkTopPhys = new G4PVPlacement(BoxTTopTransform,"SideDarkTopPhys",
//			SideDarkLog,aMasterC->getRichTbUpgradeCrystalMasterPVol(),false,0);
//	G4VPhysicalVolume* SideDarkBotPhys=	new G4PVPlacement(BoxTBotTransform, "SideDarkBotPhys",
//			SideDarkLog,aMasterC->getRichTbUpgradeCrystalMasterPVol(),false,0);

	RichTbUpgradeSideDarkCoverLVol =  SideDarkLog;
	RichTbUpgradeSideTopDarkCoverPVol = SideDarkPhys;
//	RichTbUpgradeSideTopDarkCoverPVol = SideDarkTopPhys;
//	RichTbUpgradeSideBotDarkCoverPVol = SideDarkBotPhys;
}

void RichTbUpgradeDarkCover::constructRichTbUpgradeSideDarkCoverEnvelopePhC(RichTbUpgradeCrystalMaster* aMasterC){
	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

	G4Box * DarkSideBoxOutPhC = new G4Box("DarkBoxBoxOutPhC",
			0.5 * RichTbDarkSideXSizePhC,
			0.5 * RichTbDarkSideYSizePhC,
			0.5 * RichTbDarkSideZSizePhC);

	G4Box * DarkSideBoxInnPhC = new G4Box("DarkBoxInnPhC",
			0.5 * RichTbDarkSideBoxInnXSizePhC,
			0.5 * RichTbDarkSideBoxInnYSizePhC,
			0.5 * RichTbDarkSideBoxInnZSizePhC);

	G4RotationMatrix DarkSideBoxOutRotPhC;
	G4ThreeVector DarkSideBoxTPosOutPhC( RichTbDarkSideZPhCXLocation, RichTbDarkSideZPhCYLocation,RichTbDarkSideZPhCZLocation);
	G4Transform3D  DarkSideEnvBoxPhCTransform(DarkSideBoxOutRotPhC, DarkSideBoxTPosOutPhC);


	G4SubtractionSolid * DarkSideBoxPhC = new G4SubtractionSolid("DarkSideBoxPhC", DarkSideBoxOutPhC, DarkSideBoxInnPhC);

	G4LogicalVolume* DarkSideEnvPhCLog = new G4LogicalVolume(DarkSideBoxPhC,aMaterial->getCarbon(),
			"DarkSideEnvPhCLog",0,0,0);

	G4VPhysicalVolume* DarkSideEnvPhCPhys = new G4PVPlacement(DarkSideEnvBoxPhCTransform,"DarkSideEnvPhCPhys",
			DarkSideEnvPhCLog,aMasterC->getRichTbUpgradeCrystalMasterPVol(),false,0);


	RichTbUpgradeSideDarkCoverEnvPhCLVol =   DarkSideEnvPhCLog;
	RichTbUpgradeSideDarkCoverEnvPhCPVol =  DarkSideEnvPhCPhys;

}

void RichTbUpgradeDarkCover::constructRichTbUpgradeUpsDarkCoverEnvelopePhC(RichTbUpgradeCrystalMaster* aMasterC){
	RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

	G4Box * RichTbDarkUpsEnvPhC = new G4Box("DarkBoxBoxUpsEnvPhC",
			0.5 * RichTbDarkUpsXSizePhC,
			0.5 * RichTbDarkUpsYSizePhC,
			0.5 * RichTbDarkUpsZSizePhC);
  
	G4RotationMatrix DarkUpsBoxOutRotPhC;
	G4ThreeVector DarkUpsBoxTPosOutPhC( RichTbDarkUpsPhCXLocation, RichTbDarkUpsPhCYLocation ,  RichTbDarkUpsPhCZLocation);

	G4Transform3D  DarkUpsEnvBoxPhCTransform(DarkUpsBoxOutRotPhC, DarkUpsBoxTPosOutPhC);

	G4LogicalVolume* DarkUpsEnvPhCLog = new G4LogicalVolume(RichTbDarkUpsEnvPhC,aMaterial->getCarbon(),
			"DarkUpsEnvPhCLog",0,0,0);

	G4VPhysicalVolume* DarkUpsEnvPhCPhys = new G4PVPlacement(DarkUpsEnvBoxPhCTransform,"DarkUpsEnvPhCPhys",
			DarkUpsEnvPhCLog,aMasterC->getRichTbUpgradeCrystalMasterPVol(),false,0);

	RichTbUpgradeUpsDarkCoverEnvPhCLVol =  DarkUpsEnvPhCLog;
	RichTbUpgradeUpsDarkCoverEnvPhCPVol =  DarkUpsEnvPhCPhys;


}



//=============================================================================
