// $Id: $
#ifndef INCLUDE_RICHTBHPDGEOMETRYPARAMETERS_HH
#define INCLUDE_RICHTBHPDGEOMETRYPARAMETERS_HH 1

#include <cmath>
#include "CLHEP/Units/PhysicalConstants.h"



//#include "RichTbRunConfig.hh"

/*class RichTbPMTGeometryParameters {
public:
	void setNumPmts(G4int pmts) {
		NumPmts = pmts;
	}
	void setNumPmtsUpgrade(G4int pmts) {
		NumPmtsUpgrade15 = pmts;
	}
	G4int getNumPmts() {
		return NumPmts;
	}
	G4int getNumPmtsUpgrade() {
		return NumPmtsUpgrade15;
	}
private:
	G4int NumPmts= 8;
	G4int NumPmtsUpgrade15 = 16;
};*/

//envelope size and position


//static G4int NumPmtsUpgrade15 = RichTbPMTGeometryParameters::getNumPmtsUpgrade();
static const G4int NumPmtsUpgrade15 = 16;
static const G4int NumPmtsUpgrade16 =32;
static const G4int NumPmtsUpgrade17 =16;

static const G4int NumPmts = NumPmtsUpgrade16;
static const G4int NumPmtsOld = 8;
static const G4int NumPmtsIn2014TB = NumPmtsOld;

//static G4int NumPmts = RichTbPMTGeometryParameters::getNumPmts();
static const G4int NumPmtsWithHpd = 4;


static const G4int NumPmtsInAnEC=4;
static const G4int MaxPmtNumInEC0 = 3;
static const G4int MaxPmtNumInEC1 = 7;
static const G4int MaxPmtNumInEC2 = 11;
static const G4int MaxPmtNumInEC3 = 15;


const G4double PMTMasterBoxXSize = 26.15* CLHEP::mm;
const G4double PMTMasterBoxYSize = 26.15* CLHEP::mm;
const G4double PMTMasterBoxZSize = 19.4 * CLHEP::mm;
const G4double PMTLateralTolerence=0.05 * CLHEP::mm;
const G4double PMTZTolerence=0.25 * CLHEP::mm;

const G4double PMTSMasterBoxXSize = PMTMasterBoxXSize;
const G4double PMTSMasterBoxYSize = PMTMasterBoxYSize;
const G4double PMTSMasterBoxZSize = PMTMasterBoxZSize;
const G4double PMTSMasterBoxXPos=0.0 * CLHEP::mm;
const G4double PMTSMasterBoxYPos=0.0 * CLHEP::mm;
const G4double PMTSMasterBoxZPos=0.0 * CLHEP::mm;


const G4double PMTEnvelopeBoxXSize = PMTMasterBoxXSize - PMTLateralTolerence;
const G4double PMTEnvelopeBoxYSize = PMTMasterBoxYSize - PMTLateralTolerence;
const G4double PMTEnvelopeBoxZSize = 14.0 * CLHEP::mm;


const G4double PMTEndToQuartzOuterSurface=2.7 * CLHEP::mm;
const G4double PMTEnvelopeThickness  = 1.0 * CLHEP::mm;
const G4double PMTGapInComponents =0.2 * CLHEP::mm;
const G4double PMTQuartzToAnodeSurfaceDistance = 10.0 * CLHEP::mm;

const G4double PMTEnvelopeSubPartXSize = PMTEnvelopeBoxXSize - 2.0 * PMTEnvelopeThickness;
const G4double PMTEnvelopeSubPartYSize = PMTEnvelopeBoxYSize - 2.0 * PMTEnvelopeThickness;
const G4double PMTEnvelopeSubPartZSize = 100.0 * CLHEP::mm;

const G4double PMTEnvelopeSubPartXLocation = 0.0 * CLHEP::mm;
const G4double PMTEnvelopeSubPartYLocation = 0.0 * CLHEP::mm;
const G4double PMTEnvelopeSubPartZLocation = 0.5 * (PMTEnvelopeBoxXSize - PMTEnvelopeSubPartZSize) - PMTEnvelopeThickness;

const G4double RichTbPMTEnvBoxXLocation = 0;
const G4double RichTbPMTEnvBoxYLocation = 0;
//const G4double RichTbPMTEnvBoxZLocation = 10.2 * CLHEP::mm - 0.5 * PMTEnvelopeBoxZSize - 1.0 * CLHEP::mm;

//quartz window size and position

const G4double PMTQuartzWindowSupXSize = 25.8 * CLHEP::mm;
const G4double PMTQuartzWindowSupYSize = 25.8 * CLHEP::mm;
//const G4double PMTQuartzWindowSupZSize = 6.0 * CLHEP::mm;
const G4double PMTQuartzWindowSupZSize = 0.8 * CLHEP::mm;

const G4double RichTbPMTQuartzWindowXLocation = 0;
const G4double RichTbPMTQuartzWindowYLocation = 0;
//const G4double RichTbPMTQuartzWindowZLocation = -4.9 * CLHEP::mm - 0.5 * PMTQuartzWindowSupZSize;

const G4double RichTbPMTQuartzWindowZLocation = -0.5*PMTMasterBoxZSize +
		PMTEndToQuartzOuterSurface + 0.5 * PMTQuartzWindowSupZSize;


const G4double RichTbPMTEdgeToQuartzInsideEdgeDeltaZ= PMTEndToQuartzOuterSurface + PMTQuartzWindowSupZSize;


const G4double RichTbPMTEnvBoxZLocation = RichTbPMTQuartzWindowZLocation + PMTGapInComponents +
		0.5 * (PMTQuartzWindowSupZSize + PMTEnvelopeBoxZSize) ;


//const G4double RichTbGasQuartzWindowThickness= 6.0 * CLHEP::mm; // unused param

//photocathode size and position

const G4double PMTPhCathodeSupXSize = PMTQuartzWindowSupXSize;
const G4double PMTPhCathodeSupYSize = PMTQuartzWindowSupYSize;
const G4double PMTPhCathodeSupZSize = 0.1 * CLHEP::mm;

const G4double RichTbPMTPhCathodeXLocation = 0.0;
const G4double RichTbPMTPhCathodeYLocation = 0.0;
const G4double RichTbPMTPhCathodeThickness= 0.1 * CLHEP::mm;
//const G4double RichTbPMTPhCathodeZLocation = -4.8 * CLHEP::mm - 0.05 * CLHEP::mm;
const G4double RichTbPMTPhCathodeZLocation = RichTbPMTQuartzWindowZLocation +
		0.5 * (PMTQuartzWindowSupZSize + PMTPhCathodeSupZSize );



//anode size and position

const G4double PMTAnodeSupXSize = 23.0 * CLHEP::mm;
const G4double PMTAnodeSupYSize = 23.0 * CLHEP::mm;
const G4double PMTAnodeSupZSize = 0.5 * CLHEP::mm;

const G4double RichTbPMTAnodeXLocation = 0.0;
const G4double RichTbPMTAnodeYLocation = 0.0;
//const G4double RichTbPMTAnodeZLocation = 6.2 * CLHEP::mm;
const G4double RichTbPMTAnodeZLocation = RichTbPMTQuartzWindowZLocation + PMTQuartzToAnodeSurfaceDistance+
		0.5 * (PMTQuartzWindowSupZSize +PMTAnodeSupZSize );

// front ring

const G4double RichTbPMTFrontRingLateralXSize = PMTMasterBoxXSize - PMTLateralTolerence;
const G4double RichTbPMTFrontRingLateralYSize = PMTMasterBoxYSize - PMTLateralTolerence;
const G4double RichTbPMTFrontRingZSize = 0.5 * CLHEP::mm;

const G4double RichTbPMTFrontRingXLocation =0.0 * CLHEP::mm;
const G4double RichTbPMTFrontRingYLocation =0.0 * CLHEP::mm;
const G4double RichTbPMTFrontRingZLocation = RichTbPMTQuartzWindowZLocation -
		0.5* (PMTQuartzWindowSupZSize + RichTbPMTFrontRingZSize);


const G4double RichTbPMTFrontRingSubHoleThickness = 1.4 * CLHEP::mm;
const G4double RichTbPMTFrontRingSubHoleZSize=100 * CLHEP::mm;
const G4double RichTbPMTFrontRingSubHoleXSize = RichTbPMTFrontRingLateralXSize -
		2.0*RichTbPMTFrontRingSubHoleThickness;
const G4double RichTbPMTFrontRingSubHoleYSize = RichTbPMTFrontRingLateralYSize -
		2.0*RichTbPMTFrontRingSubHoleThickness;
const G4double RichTbPMTFrontRingSubHoleXLocation= 0.0 * CLHEP::mm;
const G4double RichTbPMTFrontRingSubHoleYLocation= 0.0 * CLHEP::mm;
const G4double RichTbPMTFrontRingSubHoleZLocation= 0.0 * CLHEP::mm;

// now for PMT Locations

const G4String PMTNamesBox[]=
{"PMT0Box","PMT1Box","PMT2Box","PMT3Box","PMT4Box","PMT5Box","PMT6Box","PMT7Box",
 "PMT8Box","PMT9Box","PMT10Box","PMT11Box","PMT12Box","PMT13Box","PMT14Box","PMT15Box" ,
 "PMT16Box","PMT17Box","PMT18Box","PMT19Box","PMT20Box","PMT21Box","PMT22Box","PMT23Box",
  "PMT24Box","PMT25Box","PMT26Box","PMT27Box","PMT28Box", "PMT29Box","PMT30Box","PMT31Box"};


const G4String PMTNamesLog[]=
{"PMT0Log","PMT1Log","PMT2Log","PMT3Log","PMT4Log","PMT5Log","PMT6Log","PMT7Log",
 "PMT8Log","PMT9Log","PMT10Log","PMT11Log","PMT12Log","PMT13Log","PMT14Log","PMT15Log",
"PMT16Log","PMT17Log","PMT18Log","PMT19Log","PMT20Log","PMT21Log","PMT22Log","PMT23Log",
"PMT24Log","PMT25Log","PMT26Log","PMT27Log","PMT28Log","PMT29Log","PMT30Log","PMT31Log"
};

const G4String PMTNamesPhys[]=
{"PMT0Phys","PMT1Phys","PMT2Phys","PMT3Phys","PMT4Phys","PMT5Phys","PMT6Phys","PMT7Phys",
 "PMT8Phys","PMT9Phys","PMT10Phys","PMT11Phys","PMT12Phys","PMT13Phys","PMT14Phys","PMT15Phys",
 "PMT16Phys","PMT17Phys","PMT18Phys","PMT19Phys","PMT20Phys","PMT21Phys","PMT22Phys","PMT23Phys",
		"PMT24Phys","PMT25Phys","PMT26Phys","PMT27Phys","PMT28Phys","PMT29Phys","PMT30Phys","PMT31Phys"};


const G4String PMTSMNamesBox[]=
{"PMTSM0Box","PMTSM1Box","PMTSM2Box","PMTSM3Box","PMTSM4Box","PMTSM5Box","PMTSM6Box","PMTSM7Box",
 "PMTSM8Box","PMTSM9Box","PMTSM10Box","PMTSM11Box","PMTSM12Box","PMTSM13Box","PMTSM14Box","PMTSM15Box",
 "PMTSM16Box","PMTSM17Box","PMTSM18Box","PMTSM19Box","PMTSM20Box","PMTSM21Box","PMTSM22Box","PMTSM23Box",
		"PMTSM24Box","PMTSM25Box","PMTSM26Box","PMTSM27Box","PMTSM28Box","PMTSM29Box","PMTSM30Box","PMTSM31Box"};
const G4String PMTSMNamesLog[]=
{"PMTSM0Log","PMTSM1Log","PMTSM2Log","PMTSM3Log","PMTSM4Log","PMTSM5Log","PMTSM6Log","PMTSM7Log",
 "PMTSM8Log","PMTSM9Log","PMTSM10Log","PMTSM11Log","PMTSM12Log","PMTSM13Log","PMTSM14Log","PMTSM15Log",
 "PMTSM16Log","PMTSM17Log","PMTSM18Log","PMTSM19Log","PMTSM20Log","PMTSM21Log","PMTSM22Log","PMTSM23Log",
		"PMTSM24Log","PMTSM25Log","PMTSM26Log","PMTSM27Log","PMTSM28Log","PMTSM29Log","PMTSM30Log","PMTSM31Log"};
const G4String PMTSMNamesPhys[]=
{"PMTSM0Phys","PMTSM1Phys","PMTSM2Phys","PMTSM3Phys","PMTSM4Phys","PMTSM5Phys","PMTSM6Phys","PMTSM7Phys",
 "PMTSM8Phys","PMTSM9Phys","PMTSM10Phys","PMTSM11Phys","PMTSM12Phys","PMTSM13Phys","PMTSM14Phys","PMTSM15Phys",
 "PMTSM16Phys","PMTSM17Phys","PMTSM18Phys","PMTSM19Phys","PMTSM20Phys","PMTSM21Phys","PMTSM22Phys","PMTSM23Phys",
		"PMTSM24Phys","PMTSM25Phys","PMTSM26Phys","PMTSM27Phys","PMTSM28Phys","PMTSM29Phys","PMTSM30Phys","PMTSM31Phys"};

const G4String PMTANNamesBox[]=
{"PMTAN0Box","PMTAN1Box","PMTAN2Box","PMTAN3Box","PMTAN4Box","PMTAN5Box","PMTAN6Box","PMTAN7Box",
 "PMTAN8Box","PMTAN9Box","PMTAN10Box","PMTAN11Box","PMTAN12Box","PMTAN13Box","PMTAN14Box","PMTAN15Box",
 "PMTAN16Box","PMTAN17Box","PMTAN18Box","PMTAN19Box","PMTAN20Box","PMTAN21Box","PMTAN22Box","PMTAN23Box",
		"PMTAN24Box","PMTAN25Box","PMTAN26Box","PMTAN27Box","PMTAN28Box","PMTAN29Box","PMTAN30Box","PMTAN31Box"};

const G4String PMTANNamesLog[]=
{"PMTAN0Log","PMTAN1Log","PMTAN2Log","PMTAN3Log","PMTAN4Log","PMTAN5Log","PMTAN6Log","PMTAN7Log",
 "PMTAN8Log","PMTAN9Log","PMTAN10Log","PMTAN11Log","PMTAN12Log","PMTAN13Log","PMTAN14Log","PMTAN15Log",
 "PMTAN16Log","PMTAN17Log","PMTAN18Log","PMTAN19Log","PMTAN20Log","PMTAN21Log","PMTAN22Log","PMTAN23Log",
		"PMTAN24Log","PMTAN25Log","PMTAN26Log","PMTAN27Log","PMTAN28Log","PMTAN29Log","PMTAN30Log","PMTAN31Log"};
const G4String PMTANNamesPhys[]=
{"PMTAN0Phys","PMTAN1Phys","PMTAN2Phys","PMTAN3Phys","PMTAN4Phys","PMTAN5Phys","PMTAN6Phys","PMTAN7Phys",
 "PMTAN8Phys","PMTAN9Phys","PMTAN10Phys","PMTAN11Phys","PMTAN12Phys","PMTAN13Phys","PMTAN14Phys","PMTAN15Phys",
 "PMTAN16Phys","PMTAN17Phys","PMTAN18Phys","PMTAN19Phys","PMTAN20Phys","PMTAN21Phys","PMTAN22Phys","PMTAN23Phys",
		"PMTAN24Phys","PMTAN25Phys","PMTAN26Phys","PMTAN27Phys","PMTAN28Phys","PMTAN29Phys","PMTAN30Phys","PMTAN31Phys"};


const G4int NumPixelInPmtRow=8;
const G4int NumPixelInPmtCol=8;
const G4int NumPixelTotInPmt = NumPixelInPmtRow*NumPixelInPmtCol;


const G4double PmtAnodePixelXSize=PMTAnodeSupXSize/NumPixelInPmtRow;
const G4double PmtAnodePixelYSize=PMTAnodeSupYSize/NumPixelInPmtCol;

const G4double  RichTbPMTAnodePixelZSize =PMTAnodeSupZSize;
const G4double  RichTbPMTAnodePixelPosZ=0.0 * CLHEP::mm;


// Now for the gap between adjacent pixels.
// The gaps changed to 0.2 mm following some discussions.
//const G4double RichTbPmtPixelGap = 0.1 * CLHEP::mm;

const G4double RichTbPmtPixelGap = 0.2 * CLHEP::mm;


#endif // INCLUDE_RICHTBHPDGEOMETRYPARAMETERS_HH
