#ifndef INCLUDE_RICHTBQUARTZRADIATOR_HH 
#define INCLUDE_RICHTBQUARTZRADIATOR_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"

#include "RichTbContainerVesselBox.hh"

/** @class RichTbQuartzRadiator RichTbQuartzRadiator.hh include/RichTbQuartzRadiator.hh
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-04-10
 */
class RichTbQuartzRadiator {
public: 
  /// Standard constructor
  RichTbQuartzRadiator(RichTbContainerVesselBox* aVessel ); 

  virtual ~RichTbQuartzRadiator( ); ///< Destructor

  void constructQuartzRadiatorGeometry();
  void constructQuartzRadiatorCoverGeometry();
  

  G4LogicalVolume* getRichTbQuartzRadiatorLVol() 
  {  return RichTbQuartzRadiatorLVol;}
  
  G4VPhysicalVolume *  getRichTbQuartzRadiatorPVol() 
  {  return  RichTbQuartzRadiatorPVol;}
  
  G4LogicalVolume * getRichTbQuartzRadiatorDnsCoverLVol() 
  {    return  RichTbQuartzRadiatorDnsCoverLVol;}
  G4LogicalVolume * getRichTbQuartzRadiatorUpsCoverLVol() 
  {    return  RichTbQuartzRadiatorUpsCoverLVol;}

  G4VPhysicalVolume * getRichTbQuartzRadiatorDnsCoverPVol() 
  {  return RichTbQuartzRadiatorDnsCoverPVol;}
  G4VPhysicalVolume * getRichTbQuartzRadiatorUpsCoverPVol() 
  {  return RichTbQuartzRadiatorUpsCoverPVol;}
  
  


protected:

private:

  RichTbContainerVesselBox* aCVessel;
  
  G4LogicalVolume   *   RichTbQuartzRadiatorLVol;
  G4VPhysicalVolume *   RichTbQuartzRadiatorPVol;
 
  G4LogicalVolume   *   RichTbQuartzRadiatorDnsCoverLVol;
  G4LogicalVolume   *   RichTbQuartzRadiatorUpsCoverLVol;

  G4VPhysicalVolume *   RichTbQuartzRadiatorDnsCoverPVol;
  G4VPhysicalVolume *   RichTbQuartzRadiatorUpsCoverPVol;  
  
  

};
#endif // INCLUDE_RICHTBQUARTZRADIATOR_HH
