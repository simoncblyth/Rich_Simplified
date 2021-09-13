#ifndef INCLUDE_RICHTBLHCBECMODULEGEOMETRYPARAMETERS_HH
#define INCLUDE_RICHTBLHCBECMODULEGEOMETRYPARAMETERS_HH 1  

const G4double RichTbLbECXSize = 55.6 * CLHEP::mm;
const G4double RichTbLbECYSize = RichTbLbECXSize;
const G4double RichTbLbECZSize = 30.0 * CLHEP::mm;

const G4double RichTbLbECGap = 0.4 * CLHEP::mm;

const G4double RichTbLbECXPitch = RichTbLbECXSize + RichTbLbECGap ;

const G4double RichTbLbModuleXSize = 223.8 * CLHEP::mm;
const G4double RichTbLbModuleYSize = 56.0 * CLHEP::mm;
const G4double RichTbLbModuleZSize = 60.0 * CLHEP::mm;
const G4double RichTbLbModuleXGap = 0.2 * CLHEP::mm;
const G4double RichTbLbModuleYGap = 0.5 * CLHEP::mm;
const G4double RichTbLbModuleXPitch = RichTbLbModuleXSize + RichTbLbModuleXGap ;
const G4double RichTbLbModuleYPitch = RichTbLbModuleYSize + RichTbLbModuleYGap ;

#endif // INCLUDE_RICHTBLHCBPMTGEOMETRYPARAMETERS_HH
