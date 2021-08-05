#ifndef INCLUDE_RICHTBUPGRADEPMTGEOMETRYNUMBERING_HH 
#define INCLUDE_RICHTBUPGRADEPMTGEOMETRYNUMBERING_HH 1

const G4int NumPhDetSupFrames = 2;
const G4int NumElementaryCell =2;
const G4int NumPhDetSupFrames15 = 4;
const G4int NumElementaryCell15 =4;
const G4int NumPmtsInEC = 4;

const G4int RichTbTotNumPmt = NumElementaryCell * NumPmtsInEC;
const G4int RichTbTotNumPmt15 = NumElementaryCell15 * NumPmtsInEC;




const G4int NumPhDetSupFrames16 =2;
const G4int NumElementaryCell16 =8;
const G4int NumElementaryCell16InPF=4;
const G4int RichTbTotNumPmt16 = NumElementaryCell16 * NumPmtsInEC;
#endif // INCLUDE_RICHTBUPGRADEPMTGEOMETRYNUMBERING_HH
