#ifndef INCLUDE_RICHTBPMTPIXELEFFICIENCY_HH
#define INCLUDE_RICHTBPMTPIXELEFFICIENCY_HH 1

// Include files
#include "globals.hh"
#include <vector>
#include <cmath>
#include <map>



/** @class RichTbPmtPixelEfficiency RichTbPmtPixelEfficiency.hh include/RichTbPmtPixelEfficiency.hh
 *
 *
 *  @author Sajan Easo
 *  @date   2015-03-11
 */
class RichTbPmtPixelEfficiency {
public:
  /// Standard constructor
  // RichTbPmtPixelEfficiency( );
  static RichTbPmtPixelEfficiency* getRichTbPmtPixelEfficiencyInstance();

  virtual ~RichTbPmtPixelEfficiency( ); ///< Destructor

  void PmtPixelEffInitialize();
  G4double getPixelEff(G4int aPmt, G4int aPixel)
  {  return  mPmtPixelEff [aPmt] [aPixel]; }
  G4bool PmtPixelEffOK (G4int aPmtNum, G4int aPixelNum);
  void ReadPixelEfficiency();
  void ReadAndCopyPixelEffFromFile(G4String aInpFileName  );
  void FillPixelEfficiency();


protected:

private:
  RichTbPmtPixelEfficiency( );
  static RichTbPmtPixelEfficiency* RichTbPmtPixelEfficiencyInstance;

  std::vector <std::vector <G4double> >  mPmtPixelEff;
  std::vector <std::vector <G4String> >  mPmtPixelLabel;

  std::multimap<G4String,G4double> mPmtAnodeEffMap;

  G4int RichTbTotNumPmtFinal = 0;

};
#endif // INCLUDE_RICHTBPMTPIXELEFFICIENCY_HH
