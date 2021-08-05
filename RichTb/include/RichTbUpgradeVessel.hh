// $Id: $
#ifndef INCLUDE_RICHTBUPGRADEVESSEL_HH 
#define INCLUDE_RICHTBUPGRADEVESSEL_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbHall.hh"

/** @class RichTbUpgradeVessel RichTbUpgradeVessel.hh include/RichTbUpgradeVessel.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-11-05
 */
class RichTbUpgradeVessel {
public:
  /// Standard constructor
  RichTbUpgradeVessel(RichTbHall* rTbHall ); 

  virtual ~RichTbUpgradeVessel( ); ///< Destructor

  void  constructRichTbGasVessel();
  void  constructRichTbUpgradeVesselEnvelope();
  
  G4LogicalVolume* getRichTbGasVesselLVol() 
  {
    return RichTbGasVesselLVol;
  }
  G4LogicalVolume* getRichTbUpgradeVesselEnvelopeBottomLVol()
  {
    return RichTbUpgradeVesselEnvelopeBottomLVol;
    
  }

  G4VPhysicalVolume* getRichTbGasVesselPVol() 
  {
    return RichTbGasVesselPVol;
  }
  G4VPhysicalVolume* getRichTbUpgradeVesselEnvelopeBottomPVol()
  {
    return RichTbUpgradeVesselEnvelopeBottomPVol;
  }
  RichTbHall* getaRTbHall() 
  { 
    return aRTbHall;
  
  }
  
protected:

private:
  RichTbHall* aRTbHall;
  
  G4LogicalVolume* RichTbGasVesselLVol;
  G4LogicalVolume*  RichTbUpgradeVesselEnvelopeBottomLVol;
  

  G4VPhysicalVolume* RichTbGasVesselPVol;
  G4VPhysicalVolume* RichTbUpgradeVesselEnvelopeBottomPVol; 

 
};
#endif // INCLUDE_RICHTBUPGRADEVESSEL_HH
