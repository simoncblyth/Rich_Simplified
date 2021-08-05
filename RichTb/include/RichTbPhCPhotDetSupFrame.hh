#ifndef INCLUDE_RICHTBPHCPHOTDETSUPFRAME_H 
#define INCLUDE_RICHTBPHCPHOTDETSUPFRAME_H 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbContainerVesselBox.hh"


/** @class RichTbPhCPhotDetSupFrame RichTbPhCPhotDetSupFrame.h include/RichTbPhCPhotDetSupFrame.h
 *  
 *
 *  @author Sajan Easo
 *  @date   2017-03-25
 */
class RichTbPhCPhotDetSupFrame {
public: 
  /// Standard constructor
  RichTbPhCPhotDetSupFrame(RichTbContainerVesselBox* aBox ); 

  virtual ~RichTbPhCPhotDetSupFrame( ); ///< Destructor

  void constructRichTbPhCSupFrame();

  void constructRichTbPhCDetPlaneSegment();
  G4LogicalVolume * getRichTbPhCSupFrameLVol() 
  {  return RichTbPhCSupFrameLVol;}
  G4VPhysicalVolume    * getRichTbPhCSupFramePVol() 
  {  return RichTbPhCSupFramePVol;}

  
  G4LogicalVolume * getRichTbPhCDetPlaneSegmentLVol()
  {  return RichTbPhCDetPlaneSegmentLVol;}
  
  G4VPhysicalVolume   *  getRichTbPhCDetPlaneSegmentPVol()
  {  return RichTbPhCDetPlaneSegmentPVol;}
  

  
  
protected:

private:
  RichTbContainerVesselBox* aCVessel;
  G4LogicalVolume      *  RichTbPhCSupFrameLVol;
  G4VPhysicalVolume    *  RichTbPhCSupFramePVol;
  
  G4LogicalVolume     *  RichTbPhCDetPlaneSegmentLVol;
  G4VPhysicalVolume   *  RichTbPhCDetPlaneSegmentPVol;
  

 };
#endif // INCLUDE_RICHTBPHCPHOTDETSUPFRAME_H
