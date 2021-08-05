//This is the definition of the LHCb RICH Testbeam Detector Construction
//Author SE  1-3-2001
//
#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "globals.hh"
#include "RichTbMaterial.hh"
#include "RichTbHall.hh"
#include "RichTbUpgradeVessel.hh"
#include "RichTbContainerVesselBox.hh"
#include "RichTbPolymerRadiator.hh"
#include "RichTbQuartzRadiator.hh"

#include "RichTbMirrorParabola.hh"
#include "RichTbMirrorSph.hh"
#include "RichTbPhCPhotDetSupFrame.hh"

//#include "RichTbUpgradeMaster.hh"
#include "RichTbUpgradeCrystal.hh"
#include "RichTbUpgradeRadiator.hh"
#include "RichTbUpgradeLTPhC.hh"
#include "RichTbUpgradeCrystalMaster.hh"
#include "RichTbUpgradeLens.hh"
#include "RichTbUpgradeCrystalCover.hh"
#include "RichTbUpgradeDarkCover.hh"
#include "RichTbUpgradePhDFrame.hh"
#include "RichTbUpgradePhDetSupFrame.hh"
#include "RichTbUpgradeEC.hh"
#include "RichTbPMT.hh"
#include "RichTbUpgradeMirror.hh"
#include "RichTbLargeMirrorParabola.hh"

#include "RichTbHpd.hh"

//#include "RichTbPhDetSupFrame.hh"
#include "RichTbSurface.hh"
#include "RichTbRunConfig.hh"
#include "RichTbROGeometry.hh"
#include "RichTbROGeometryHpd.hh"
//#include "RichTbSD.hh"

#include "RichTbGraphics.hh"

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4SDManager.hh"
class RichTbDetectorConstruction:public G4VUserDetectorConstruction {

  public:
    RichTbDetectorConstruction();
    virtual ~ RichTbDetectorConstruction();
    G4VPhysicalVolume *Construct() override;

    RichTbHall *getRichTbHall() {
        return rTbHall;
    }
  RichTbUpgradeVessel* getRichTbUpgradeVessel() 
  {
    return  rTbVessel;
  }

  void ResetStdVol();
  

  /*
  RichTbMaster* getRichTbMaster1() 
  {
    return  rTbMaster1;
  }
  RichTbMaster* getRichTbMaster2() 
  {
    return  rTbMaster2;
  }
  RichTbMaster* getRichTbMaster3() 
  {
    return  rTbMaster3;
  }
  RichTbMaster* getRichTbMaster4() 
  {
    return  rTbMaster4;
  }

  */


  RichTbLens* getRichTbLens() 
  {
    return  rTbLens;
  }
  RichTbCrystal* getRichTbCrystal() 
  {
    return  rTbCrystal;
  }
 RichTbUpgradeRadiator* getRichTbUpgradeRadiator() 
  {
    return  rTbUpgradeRadiator;
  }

 RichTbUpgradeCrystalMaster* getRichTbUpgradeCrystalMaster() 
  {
    return  rTbCrystalMaster;
  }
  RichTbCrystalCover* getRichTbCrystalCover() 
  {
    return  rTbCrystalCover;
  }

 RichTbUpgradeDarkCover* getRichTbUpgradeDarkCover() 
  {
    return  rTbUpgradeDarkCover;
  }

  RichTbPhDFrame* getRichTbPhDFrame() 
  {
    return  rTbPhDFrame;
  }

 RichTbPMT* getRichTbPMT() 
  {
    return  rTbPMT;
  }


  RichTbUpgradeMirror* getRichTbUpgradeMirror() 
  {
    return rTbUpgradeMirror;
    
  }
 
  RichTbUpgradePhDetSupFrame* getRichTbUpgradePhDetSupFrame() 
  {  return   rTbUpgradePhotSupFrame;  }
  
  RichTbUpgradeEC* getRichTbEC() 
  {
    return rTbEC;
  }
  

  /*  
  RichTbPhDetSupFrame* getRichTbPhDetSupFrame() 
  {
    return  rTbPhotSupFrame;
  }
  */
  RichTbSurface* getRichTbSurface() 
  {
    return rTbSurface;
  }
  
   RichTbROGeometry *getROGeometry() { return rTbROGeom;}
  RichTbROGeometryHpd *getROGeometryHpd( ){return rTbROGeomHpd;}
  
       
   /* RichTbSD* getRichTbSD()
  { return  PMTSD;
  }
  */

  RichTbHpd* getRichTbHpd() {return  rTbHpd; }
  
 
  RichTbContainerVesselBox*   getRichTbContainerVessel(){
   return rTbContainerVessel ;
  }
  RichTbPolymerRadiator * getRichTbPolymerPlusRadiator() 
  {
    return rTbPolymerPlusRadiator;
  }
  RichTbMirrorParabola* getRichTbMirrParabola() 
  {  return rTbMirrParabola;}
  
  RichTbMirrorSph * getRichTbMirrorSph() 
  {  return rTbMirrSph;}
  
  RichTbPhCPhotDetSupFrame * getRichTbPhCPhDetSupFrame(){
    return  rTbPhCPhDetSupFrame;
  }
  
  
  RichTbLargeMirrorParabola * getRichTbLargeMirrorParabola() 
  {  return rTbLargeMirrorParab;}
  


  RichTbQuartzRadiator * getRichTbQuartzRadiator() 
  {return   rTbQWRadiator;}
  

  private:

  RichTbHall *rTbHall;
  RichTbUpgradeVessel* rTbVessel;

  RichTbContainerVesselBox* rTbContainerVessel ;
  RichTbPolymerRadiator * rTbPolymerPlusRadiator;
  RichTbQuartzRadiator * rTbQWRadiator;
  

  RichTbMirrorParabola * rTbMirrParabola;
  RichTbMirrorSph  *  rTbMirrSph;
  RichTbPhCPhotDetSupFrame * rTbPhCPhDetSupFrame;
  RichTbLargeMirrorParabola * rTbLargeMirrorParab;
  

  /*
  RichTbMaster* rTbMaster1;
  RichTbMaster* rTbMaster2;
  RichTbMaster* rTbMaster3;
  RichTbMaster* rTbMaster4;
  */

  RichTbCrystal* rTbCrystal;
  RichTbUpgradeRadiator* rTbUpgradeRadiator;
  RichTbUpgradeCrystalMaster* rTbCrystalMaster;
  RichTbCrystalCover* rTbCrystalCover;
  RichTbUpgradeDarkCover* rTbUpgradeDarkCover;
  RichTbPhDFrame* rTbPhDFrame;
  RichTbPMT* rTbPMT;
  RichTbUpgradeMirror* rTbUpgradeMirror;
  RichTbLens* rTbLens;
 

  // RichTbGraphics* rTbGraphics ;
  
  // RichTbPhDetSupFrame* rTbPhotSupFrame;

  RichTbUpgradePhDetSupFrame* rTbUpgradePhotSupFrame;
  RichTbUpgradeEC* rTbEC;
  RichTbHpd* rTbHpd;
  


  RichTbSurface* rTbSurface;

  // RichTbSD* PMTSD;
  
  RichTbROGeometry *rTbROGeom;
  RichTbROGeometryHpd *rTbROGeomHpd;

};

#endif                          /*RichTbDetectorConstruction_h */
