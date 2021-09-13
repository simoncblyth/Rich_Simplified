#ifndef RichTbLHCbUtil_h
#define RichTbLHCbUtil_h 1

#include "globals.hh"
#include <vector>
#include <cmath>
#include "G4ThreeVector.hh"
#include "CLHEP/Units/PhysicalConstants.h"

class RichTbLHCbUtil {
public:
  virtual ~RichTbLHCbUtil();
  static RichTbLHCbUtil* getRichTbLHCbUtilInstance();
  G4int getModuleNumFromPmtNum(int aP );
  G4int getPmtNumInModuleFromPmtNum (int aP);

private:
  RichTbLHCbUtil();
  static RichTbLHCbUtil* RichTbLHCbUtilInstance ;



};


#endif                          /*RichTbLHCbUtil_h */
