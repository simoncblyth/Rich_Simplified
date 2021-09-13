#ifndef INCLUDE_RICHTBLHCBR1PMTARRAYGEOMETRYPARAMETERS_HH
#define INCLUDE_RICHTBLHCBR1PMTARRAYGEOMETRYPARAMETERS_HH 1

const G4int RichTbLbNumPmtInEC = 4;
const G4int RichTbLbNumPmtRowInEC = 2;
const G4int RichTbLbNumPmtColInEC = 2;
const G4int RichTbLbNumECInModule = 4;
const G4int RichTbLbNumPmtInModule = RichTbLbNumECInModule * RichTbLbNumPmtInEC;
const G4int RichTbLbNumModuleCol = 6 ;
const G4int RichTbLbNumModuleRow = 11 ;
const G4int RichTbLbNumModules   = RichTbLbNumModuleCol * RichTbLbNumModuleRow;
const G4int RichTbLbNumPmtECs    = RichTbLbNumModules * RichTbLbNumECInModule ;
const G4int RichTbLbNumPmts      = RichTbLbNumPmtECs * RichTbLbNumPmtInEC ;
const G4int RichTbLbNumPmtPixels = RichTbLbNumPmts * RichLbNumPixelsInPmt;

//====================================================
const G4double RichLbPmtMasterGap = 1.6 * CLHEP::mm;

const G4double RichLbPmtMasterPitch = RichLbPMTMasterLateralSize + RichLbPmtMasterGap;
const G4double RichLbPmtMasterXPitch = RichLbPmtMasterPitch;
const G4double RichLbPmtMasterYPitch = RichLbPmtMasterPitch;

const std::vector<G4double> RichLbPmtMasterInECXPos = {-0.5 * RichLbPmtMasterXPitch , 
						       0.5 * RichLbPmtMasterXPitch , 
                                                       -0.5 * RichLbPmtMasterXPitch ,
                                                       0.5* RichLbPmtMasterXPitch };

const std::vector<G4double> RichLbPmtMasterInECYPos = {-0.5 * RichLbPmtMasterYPitch , 
						       -0.5 * RichLbPmtMasterYPitch , 
                                                       0.5 * RichLbPmtMasterYPitch ,
                                                       0.5* RichLbPmtMasterYPitch };

const G4double RichLbPmtMasterInECRotY = CLHEP::pi * CLHEP::rad;

const std::vector<G4double>  RichLbPmtMasterInECRotZ = { CLHEP::pi * CLHEP::rad, 
							 -0.5 * CLHEP::pi * CLHEP::rad, 
							 0.5 * CLHEP::pi * CLHEP::rad, 0.0 * CLHEP::rad};

const G4double RichLbPmtMasterInECZPos = 5.0 * CLHEP::mm;


//===================================
const G4double RichTbLbECYPos  = 0.0 * CLHEP::mm;
const G4double RichTbLbECZPos  = -5.0 * CLHEP::mm;
const std::vector<G4double> RichTbLbECXPos = {-1.5 * RichTbLbECXPitch , -0.5 * RichTbLbECXPitch,
					    0.5 * RichTbLbECXPitch , 1.5 * RichTbLbECXPitch };


const G4double RichTbLbECRotZ = -0.5 * CLHEP::pi * CLHEP::rad;

//===================================

// The following two parameters defined in RichTbLHCbR1PhDetSupFrameGeometryParameters.hh
//const G4double RichTbR1PhDetSupFrameTolerence = 1.0 * CLHEP::mm ;

//const G4double RichTbLbModuleZPos = -RichTbR1PhDetSupFrameHalfSizeZ + 
//                                    0.5 * RichTbLbModuleZSize + RichTbR1PhDetSupFrameTolerence; 

const std::vector<G4double> RichTbLbModuleXPos = { 2.5 * RichTbLbModuleXPitch, 1.5 * RichTbLbModuleXPitch,
						   0.5 * RichTbLbModuleXPitch, -0.5 * RichTbLbModuleXPitch, 
                                                    -1.5 * RichTbLbModuleXPitch, -2.5 * RichTbLbModuleXPitch};

const std::vector<G4double> RichTbLbModuleYPos = {5.0 * RichTbLbModuleYPitch, 4.0 * RichTbLbModuleYPitch,
						  3.0 * RichTbLbModuleYPitch, 2.0 * RichTbLbModuleYPitch,  
                                                  1.0 * RichTbLbModuleYPitch, 0.0 * RichTbLbModuleYPitch,
                                                  -1.0 * RichTbLbModuleYPitch, -2.0 * RichTbLbModuleYPitch,
                                                  -3.0 * RichTbLbModuleYPitch, -4.0 * RichTbLbModuleYPitch,
                                                  -5.0 * RichTbLbModuleYPitch};
const G4double RichTbLbModuleRotZ = CLHEP::pi * CLHEP::rad;
//===================================================================

#endif // INCLUDE_RICHTBLHCBR1PMTARRAYGEOMETRYPARAMETERS_HH
