// $Id: $
// Include files


#include "globals.hh"
#include "G4Tubs.hh"
#include "G4Box.hh"
#include "G4Sphere.hh"
// local
#include "RichTbMaterial.hh"
#include "RichTbPMT.hh"
#include "RichTbUpgradeMaster.hh"
#include "RichTbUpgradePhDFrame.hh"
#include "RichTbGeometryParameters.hh"
#include "RichTbMaterialParameters.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SubtractionSolid.hh"
#include "G4SDManager.hh"
//#include "RichTbSD.hh"
#include "RichTbRODummySD.hh"
#include "RichTbMiscNames.hh"
#include "RichTbRunConfig.hh"


//-----------------------------------------------------------------------------
// Implementation file for class : RichTbPMT
//
// 2003-11-19 : Sajan EASO
// 2015-06-12: Michele BLAGO modified for the 2015 testbeam.
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbPMT::RichTbPMT( RichTbUpgradeEC* aECMaster )
{  PmtECFrame = aECMaster;
m_TrackingSwitch=true;
m_PMTQwLogVolName=PMTQwLogVolName;
m_PMTPhCathLogVolName= PMTPhCathLogVolName ;
m_PMTAnodeLogVolName=PMTANNamesLog[0];
RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();
G4int aRadiatorConfiguration = aConfig ->getRadiatorConfiguration();
CurNumPmts = NumPmtsIn2014TB;

//CurNumPmts = RichTbPMTGeometryParameters::getNumPmts(); // TESTnumPmts
 if (aRadiatorConfiguration == 2) {

   CurNumPmts = NumPmtsWithHpd;

 } else if (aRadiatorConfiguration == 3) {
   
   CurNumPmts = NumPmtsUpgrade15;

 } else if (aRadiatorConfiguration == 6) {

   // CurNumPmts =  NumPmtsUpgrade16;
   CurNumPmts =  NumPmtsUpgrade16;

 }
  else if (aRadiatorConfiguration == 7) {

   CurNumPmts =  NumPmtsUpgrade17;

 }
 

}

RichTbPMT::~RichTbPMT(  ) {
}

void  RichTbPMT::buildPMTGeometry()
{

	RichTbPMTMasterLVol.resize(CurNumPmts);
	RichTbPMTSMasterLVol.resize(CurNumPmts);
	RichTbPMTAnodeLVol.resize(CurNumPmts);
	RichTbPMTMasterPVol.resize(CurNumPmts);
	RichTbPMTSMasterPVol.resize(CurNumPmts);
	RichTbPMTAnodePVol.resize(CurNumPmts);

	for (int ipmt=0; ipmt <CurNumPmts; ++ipmt ){
		constructPMTMasterTree(ipmt);
	}

	if(m_TrackingSwitch) {
		constructPMTComponentsLVol();
		RichTbPMTEnvelopePVol.resize(CurNumPmts);
		RichTbPMTQuartzWPVol.resize(CurNumPmts);
		RichTbPMTPhCathodePVol.resize(CurNumPmts);
		RichTbPMTFrontRingPVol.resize(CurNumPmts);

		for (int jpmt=0; jpmt <CurNumPmts; ++jpmt ){
			constructPMTComponentsPVol(jpmt) ;
    }

    
	}else {
		constructPMTAnode();
	}







}

void RichTbPMT::constructPMTComponentsLVol()
{
	RichTbMaterial* aMaterial =  RichTbMaterial::getRichTbMaterialInstance();



	// evelope = substraction of boxes


	G4Box* PMTEnvelopeBox
	= new G4Box( "PMTEnvelopeBox",
			0.5 * PMTEnvelopeBoxXSize,
			0.5 * PMTEnvelopeBoxYSize,
			0.5 * PMTEnvelopeBoxZSize );

	// G4cout<<"test Envelope size "<<PMTEnvelopeBoxXSize <<G4endl;

	G4Box* PMTEnvelopeSubBox
	= new G4Box("PMTEnvelopeSubBox",
			0.5*PMTEnvelopeSubPartXSize,
			0.5*PMTEnvelopeSubPartYSize,
			0.5*PMTEnvelopeSubPartZSize);

	G4ThreeVector PMTEnvelopeSubPos( PMTEnvelopeSubPartXLocation,
			PMTEnvelopeSubPartYLocation,
			PMTEnvelopeSubPartZLocation );

	G4RotationMatrix  PMTEnvelopeSubRotX, PMTEnvelopeSubRotY;

	G4Transform3D PMTEnvelopeSubTransform(PMTEnvelopeSubRotX * PMTEnvelopeSubRotY,
			PMTEnvelopeSubPos);

	G4SubtractionSolid* PMTEnvelope = new G4SubtractionSolid("PMTEnvelope",
			PMTEnvelopeBox,
			PMTEnvelopeSubBox,
			PMTEnvelopeSubTransform);



	//quartz window
	G4Box* PMTQuartzWindow
	= new G4Box( "PMTQuartzWindow",
			0.5 * PMTQuartzWindowSupXSize,
			0.5 * PMTQuartzWindowSupYSize,
			0.5 * PMTQuartzWindowSupZSize );

	//cathode
	G4Box* PMTPhCathode=
			new G4Box("PMTPhCathode",
					0.5 * PMTPhCathodeSupXSize,
					0.5 * PMTPhCathodeSupYSize,
					0.5 * PMTPhCathodeSupZSize );


	//front ring
	G4Box* PMTFrontRingOuterBox =
			new G4Box("PMTFrontRingOuterBox" ,
					0.5*RichTbPMTFrontRingLateralXSize,
					0.5*RichTbPMTFrontRingLateralYSize,
					0.5*  RichTbPMTFrontRingZSize);

	G4Box* PMTFrontRingInnerSubBox =
			new G4Box("PMTFrontRingInnerSubBox" ,
					0.5*RichTbPMTFrontRingSubHoleXSize,
					0.5*RichTbPMTFrontRingSubHoleYSize,
					0.5*RichTbPMTFrontRingSubHoleZSize);


	G4ThreeVector PMTFrontRingSubPos( RichTbPMTFrontRingSubHoleXLocation ,
			RichTbPMTFrontRingSubHoleYLocation,
			RichTbPMTFrontRingSubHoleZLocation );

	G4RotationMatrix  PMTFrontRingSubRotX, PMTFrontRingSubRotY;

	G4Transform3D PMTFrontRingSubTransform(PMTFrontRingSubRotX * PMTFrontRingSubRotY,
			PMTFrontRingSubPos);

	G4SubtractionSolid* PMTFrontRing = new G4SubtractionSolid("PMTFrontRing",
			PMTFrontRingOuterBox,
			PMTFrontRingInnerSubBox,
			PMTFrontRingSubTransform);

	//logical volumes



	G4LogicalVolume*  PMTEnvelopeLog =
			new G4LogicalVolume( PMTEnvelope,
					aMaterial->getPMTTubeEnvelopeMaterial(),
					"PMTEnvelopeLog",0,0,0);

	G4LogicalVolume* PMTQuartzWLog=
			new  G4LogicalVolume( PMTQuartzWindow,
					aMaterial->getPMTQuartzWindowMaterial(),
					m_PMTQwLogVolName ,0,0,0);
	G4LogicalVolume* PMTPhCathodeLog =
			new G4LogicalVolume( PMTPhCathode,
					aMaterial->getPMTPhCathodeMaterial() ,
					m_PMTPhCathLogVolName ,0,0,0);


	G4LogicalVolume*  PMTFrontRingLog =
			new G4LogicalVolume( PMTFrontRing,
					aMaterial->getPMTTubeEnvelopeMaterial(),
					"PMTFrontRingLog",0,0,0);

	RichTbPMTEnvelopeLVol=PMTEnvelopeLog;
	RichTbPMTQuartzWLVol= PMTQuartzWLog;
	RichTbPMTPhCathodeLVol=PMTPhCathodeLog;
	RichTbPMTFrontRingLVol = PMTFrontRingLog;



}

void RichTbPMT::constructPMTComponentsPVol(int CurPMTNum)
{

	G4RotationMatrix  PMTEnvelopeBoxRot, PMTFrontRingBoxRot;

	G4RotationMatrix PMTQuartzWindowRot, PMTPhCathodeRot;



	G4ThreeVector PMTEnvelopeBoxPos( RichTbPMTEnvBoxXLocation,
			RichTbPMTEnvBoxYLocation,
			RichTbPMTEnvBoxZLocation);

	G4Transform3D   PMTEnvelopeBoxTransform( PMTEnvelopeBoxRot,
			PMTEnvelopeBoxPos);

	G4ThreeVector PMTFrontRingBoxPos( RichTbPMTFrontRingXLocation,
			RichTbPMTFrontRingYLocation,
			RichTbPMTFrontRingZLocation);

	G4Transform3D   PMTFrontRingBoxTransform( PMTFrontRingBoxRot,
			PMTFrontRingBoxPos);

	G4ThreeVector PMTQuartzWindowPos(  RichTbPMTQuartzWindowXLocation,
			RichTbPMTQuartzWindowYLocation,
			RichTbPMTQuartzWindowZLocation);

	G4Transform3D  PMTQuartzWindowTransform( PMTQuartzWindowRot,
			PMTQuartzWindowPos);

	G4ThreeVector   PMTPhCathodePos(RichTbPMTPhCathodeXLocation,
			RichTbPMTPhCathodeYLocation,
			RichTbPMTPhCathodeZLocation);

	G4Transform3D PMTPhCathodeTransform( PMTPhCathodeRot, PMTPhCathodePos);



	G4VPhysicalVolume*  CurMPhys =
			RichTbPMTSMasterPVol[CurPMTNum];


	G4VPhysicalVolume*   PMTEnvelopePhys =
			new G4PVPlacement(  PMTEnvelopeBoxTransform, PMTEnvelopeBoxPhysName+PMTNumberName[CurPMTNum],
					RichTbPMTEnvelopeLVol  , CurMPhys,
					false,0);

	G4VPhysicalVolume*   PMTFrontRingPhys =
			new G4PVPlacement(  PMTFrontRingBoxTransform, PMTFrontRingBoxPhysName+PMTNumberName[CurPMTNum],
					RichTbPMTFrontRingLVol  , CurMPhys,
					false,0);

	G4VPhysicalVolume*   PMTQuartzWPhys=
			new G4PVPlacement(  PMTQuartzWindowTransform, PMTQuartzWPhysName+PMTNumberName[CurPMTNum],
					RichTbPMTQuartzWLVol ,
					CurMPhys , false,0);

	G4VPhysicalVolume*   PMTPhCathodePhys=
			new G4PVPlacement(  PMTPhCathodeTransform, PMTPhCathodePhysName +PMTNumberName[CurPMTNum],
					RichTbPMTPhCathodeLVol,
					CurMPhys,false,0);



	RichTbPMTEnvelopePVol[CurPMTNum] = PMTEnvelopePhys;
	RichTbPMTQuartzWPVol[CurPMTNum]= PMTQuartzWPhys;
	RichTbPMTPhCathodePVol[CurPMTNum]= PMTPhCathodePhys;
	RichTbPMTFrontRingPVol[CurPMTNum] =  PMTFrontRingPhys;


}



void RichTbPMT::constructPMTMasterTree(int CurPMTNum)
{

	RichTbMaterial* aMaterial =  RichTbMaterial::getRichTbMaterialInstance();
	//   RichTbRunConfig* aRunConfig= RichTbRunConfig::getRunConfigInstance();
	RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();
	G4int aRadiatorConfiguration = aConfig->getRadiatorConfiguration();



	G4RotationMatrix  PMTSMasterRot, PMTAnodeRot;
	G4ThreeVector PMTSMasterPos(PMTSMasterBoxXPos,PMTSMasterBoxYPos,PMTSMasterBoxZPos);
	G4Transform3D PMTSMasterTransform( PMTSMasterRot,PMTSMasterPos);


	G4ThreeVector PMTAnodePos(RichTbPMTAnodeXLocation,
			RichTbPMTAnodeYLocation,
			RichTbPMTAnodeZLocation);

	G4Transform3D PMTAnodeTransform( PMTAnodeRot, PMTAnodePos);


	G4String PMTMasterBoxName = PMTNamesBox[ CurPMTNum ];
	G4String PMTMasterLogVolName= PMTNamesLog[CurPMTNum ];
	G4String PMTMasterPhysVolName = PMTNamesPhys[ CurPMTNum ];


	G4Box* PMTMasterBox
	= new G4Box( PMTMasterBoxName,
			0.5 * PMTMasterBoxXSize,
			0.5 * PMTMasterBoxYSize,
			0.5 * PMTMasterBoxZSize );
	G4Box* PMTSMasterBox
	= new G4Box( PMTSMNamesBox[CurPMTNum],
			0.5 * PMTMasterBoxXSize,
			0.5 * PMTMasterBoxYSize,
			0.5 * PMTMasterBoxZSize );
	//anode
	G4Box* PMTAnode=
			new G4Box(PMTANNamesBox[CurPMTNum],
					0.5 * PMTAnodeSupXSize,
					0.5 * PMTAnodeSupYSize,
					0.5 * PMTAnodeSupZSize );

	G4double RichTbPMTMasterXPosFinal=  RichTbPmtPosXInEC[CurPMTNum] ;
	G4double  RichTbPMTMasterYPosFinal= RichTbPmtPosYInEC[CurPMTNum];
	G4double  RichTbPMTMasterZPosFinal = RichTbPmtPosZInEC ;
	G4ThreeVector PMTMasterPos(RichTbPMTMasterXPosFinal,
			RichTbPMTMasterYPosFinal,
			RichTbPMTMasterZPosFinal);

	//  G4RotationMatrix  PMTMasterRotY;
	//G4Transform3D PMTMasterTransform(PMTMasterRotY*PMTMasterRotZ,
	//                      PMTMasterPos);

	G4RotationMatrix PMTMasterRotZ;
	PMTMasterRotZ.rotateZ(RichTbPmtRotZInEC[CurPMTNum]);



	G4Transform3D PMTMasterTransform(PMTMasterRotZ,PMTMasterPos);

	G4LogicalVolume* PMTMasterLog=
			new G4LogicalVolume(PMTMasterBox,aMaterial-> getRichTbVaccum(),
					PMTMasterLogVolName ,0,0,0);

	G4VPhysicalVolume* PMTMasterPhys=0;

  if(aRadiatorConfiguration==6) {
    // 2016 configuration with LT
    // get the EC Number from pmt number


  	G4RotationMatrix PMTMasterRotZIn2016LT;
  	PMTMasterRotZIn2016LT.rotateZ(RichTbPmtRotZInEC16LT[CurPMTNum]);
  	G4Transform3D PMTMasterTransformIn2016LT (PMTMasterRotZIn2016LT,PMTMasterPos);


    G4int curECNum =   RichTbEcNumFromPmtNum [CurPMTNum];
    PMTMasterPhys = new G4PVPlacement(PMTMasterTransformIn2016LT,PMTMasterPhysVolName,
                                       PMTMasterLog, PmtECFrame->getRichTbECPVol( curECNum ),false, CurPMTNum);
 

  }else if(aRadiatorConfiguration==3){
    //2015 configuration
		    if(CurPMTNum<=MaxPmtNumInEC0) {
		       	PMTMasterPhys = new G4PVPlacement(PMTMasterTransform,PMTMasterPhysVolName,
				  	PMTMasterLog,
					  PmtECFrame->getRichTbECLeftPVol(),false, CurPMTNum);
    		}else if(CurPMTNum<=MaxPmtNumInEC1) {
		       	PMTMasterPhys = new G4PVPlacement(PMTMasterTransform,PMTMasterPhysVolName,
				  	PMTMasterLog,
				  	PmtECFrame->getRichTbECRightPVol(),false, CurPMTNum);
    		}else if(CurPMTNum<=MaxPmtNumInEC2) {
      			PMTMasterPhys = new G4PVPlacement(PMTMasterTransform,PMTMasterPhysVolName,
			  		PMTMasterLog,
				  	PmtECFrame->getRichTbECBottomLeftPVol(),false, CurPMTNum);
    		}else if(CurPMTNum<=MaxPmtNumInEC3) {
      			PMTMasterPhys = new G4PVPlacement(PMTMasterTransform,PMTMasterPhysVolName,
			  		PMTMasterLog,PmtECFrame->getRichTbECBottomRightPVol(),false, CurPMTNum);
		    }
  }
    else if(aRadiatorConfiguration==7){
    //2017 configuration
		    if(CurPMTNum<=MaxPmtNumInEC0) {
		       	PMTMasterPhys = new G4PVPlacement(PMTMasterTransform,PMTMasterPhysVolName,
				  	PMTMasterLog,
					  PmtECFrame->getRichTbECBottomPVol(),false, CurPMTNum);
    		}else if(CurPMTNum<=MaxPmtNumInEC1) {
		       	PMTMasterPhys = new G4PVPlacement(PMTMasterTransform,PMTMasterPhysVolName,
				  	PMTMasterLog,
				  	PmtECFrame->getRichTbECBottomMediumPVol(),false, CurPMTNum);
    		}else if(CurPMTNum<=MaxPmtNumInEC2) {
      			PMTMasterPhys = new G4PVPlacement(PMTMasterTransform,PMTMasterPhysVolName,
			  		PMTMasterLog,
				  	PmtECFrame->getRichTbECHightMediumPVol(),false, CurPMTNum);
    		}else if(CurPMTNum<=MaxPmtNumInEC3) {
      			PMTMasterPhys = new G4PVPlacement(PMTMasterTransform,PMTMasterPhysVolName,
			  		PMTMasterLog,PmtECFrame->getRichTbECHightPVol(),false, CurPMTNum);
		    }    
    }else{

    //2014 configuration

		PMTMasterPhys = (CurPMTNum <= MaxPmtNumInEC0) ?
				( new G4PVPlacement(PMTMasterTransform,PMTMasterPhysVolName,
						PMTMasterLog,
						PmtECFrame->getRichTbECLeftPVol(),false, CurPMTNum)) :
						( new G4PVPlacement(PMTMasterTransform,PMTMasterPhysVolName,
								PMTMasterLog,
								PmtECFrame->getRichTbECRightPVol(),false, CurPMTNum)) ;
	}

	G4LogicalVolume* PMTSMasterLog=
			new G4LogicalVolume(PMTSMasterBox,aMaterial-> getRichTbVaccum(),
					PMTSMNamesLog[CurPMTNum] ,0,0,0);

	G4LogicalVolume* PMTAnodeLog =
			new G4LogicalVolume(PMTAnode ,aMaterial->getPMTAnodeMaterial() ,
					PMTANNamesLog[CurPMTNum] ,0,0,0);

	G4VPhysicalVolume* PMTSMasterPhys =
			new G4PVPlacement(PMTSMasterTransform, PMTSMNamesPhys [CurPMTNum],
					PMTSMasterLog,PMTMasterPhys,false, 0);

	G4VPhysicalVolume* PMTAnodePhys =
			new G4PVPlacement(PMTAnodeTransform,PMTANNamesPhys [CurPMTNum],
					PMTAnodeLog, PMTSMasterPhys,false, 0);

	RichTbPMTMasterLVol[CurPMTNum]=PMTMasterLog;
	RichTbPMTMasterPVol[CurPMTNum]=PMTMasterPhys;
	RichTbPMTSMasterLVol[CurPMTNum]=PMTSMasterLog;
	RichTbPMTSMasterPVol[CurPMTNum]=PMTSMasterPhys;
	RichTbPMTAnodeLVol[CurPMTNum]=PMTAnodeLog;
	RichTbPMTAnodePVol[CurPMTNum]=PMTAnodePhys;




}
void  RichTbPMT::constructPMTAnode()
{

	RichTbAnodePxPVol.resize( CurNumPmts);
	for (G4int jpmt =0; jpmt < CurNumPmts ; jpmt++ ){
		RichTbAnodePxPVol[jpmt].reserve( NumPixelInPmtCol*NumPixelInPmtRow);
	}

	RichTbMaterial* aMaterial =  RichTbMaterial::getRichTbMaterialInstance();


	G4Box* PMTSiPxBox =
			new G4Box("PMTAnodePxBox",0.5*PmtAnodePixelXSize,0.5*PmtAnodePixelYSize,
					0.5* RichTbPMTAnodePixelZSize);

	G4LogicalVolume* PMTAnodePxLog =
			new G4LogicalVolume( PMTSiPxBox,
					aMaterial->getPMTAnodeMaterial(),
					"PMTAnodePxLog",0,0,0);

	//Now for the readout dummy sensitive detector
	// This just flags the pixel as active.
	// for now all pixels are set active. To deactivate
	// specific pixels, the log vol must be created for each
	// given pixel and the set to be active as done below. This means
	// a separate log vol must be created for every pixel.

	G4bool thisPixelisAlive=true;
	if(thisPixelisAlive){
		RichTbRODummySD * DummySensi = new RichTbRODummySD;
		PMTAnodePxLog->SetSensitiveDetector(DummySensi);
	}


	// now positioning the pixels in the Silicon Det.

	G4RotationMatrix  PMTAnodeRot;



	G4double aPixelColStartX = -0.5*(NumPixelInPmtRow-1)*PmtAnodePixelXSize;
	G4double aPixelColStartY = -0.5*(NumPixelInPmtCol-1)*PmtAnodePixelYSize;


	for(G4int iPixelRowY = 0; iPixelRowY < NumPixelInPmtCol ; iPixelRowY++){
		for (G4int iPixelColX = 0; iPixelColX < NumPixelInPmtRow ; iPixelColX++){

			G4int PixelCopyNumber = iPixelColX + iPixelRowY*NumPixelInPmtRow;

			G4double curPixelPosX =   aPixelColStartX +  iPixelColX*PmtAnodePixelXSize ;

			G4double curPixelPosY =   aPixelColStartY +  iPixelRowY*PmtAnodePixelYSize;

			G4ThreeVector PMTAnodePxPos(curPixelPosX, curPixelPosY, RichTbPMTAnodePixelPosZ);
			G4Transform3D PMTAnodeTransform(PMTAnodeRot, PMTAnodePxPos);

			for (G4int ipmt =0; ipmt < CurNumPmts ; ipmt++ ){

				G4VPhysicalVolume*  PMTAnodePxPhys =
						new G4PVPlacement(  PMTAnodeTransform,"PMTAnodePxPhys"+PMTNumberName[ipmt],
								PMTAnodePxLog, RichTbPMTAnodePVol[ipmt], false, PixelCopyNumber);
				RichTbAnodePxPVol[ipmt].push_back(PMTAnodePxPhys);
			}


		}



	}

	RichTbAnodePxLVol=PMTAnodePxLog;

}



//=============================================================================
