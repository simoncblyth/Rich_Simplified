// Include files 

#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4IntersectionSolid.hh"

#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"


// local
#include "RichTbQuartzRadiator.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbQuartzRadiator
//
// 2017-04-10 : Sajan Easo
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbQuartzRadiator::RichTbQuartzRadiator(RichTbContainerVesselBox* aVessel   ) {
 aCVessel = aVessel ;
 constructQuartzRadiatorGeometry();
 constructQuartzRadiatorCoverGeometry();

}
//=============================================================================
// Destructor
//=============================================================================
RichTbQuartzRadiator::~RichTbQuartzRadiator() {} 

//=============================================================================
void RichTbQuartzRadiator::constructQuartzRadiatorGeometry() {

  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  // RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();

  //  G4Tubs *  RichTbQuartzTub = new G4Tubs ("RichTbQuartzTubs",QuartzRadiatorInnerRadius ,
  //                                       QuartzRadiatorRadius,0.5*QuartzRadiatorZSize, 
  //                                       QuartzRadiatorZStartPhi, QuartzRadiatorZDeltaPhi);

  G4Sphere * RichTbQuartzSphA = new G4Sphere("RichTbQuartzSphA", QuartzRadiatorInnerRadius,QuartzRadiatorRadius,
                                            QuartzRadiatorZStartPhi,QuartzRadiatorZDeltaPhi,
                                            QuartzRadiatorZStartTheta,QuartzRadiatorZDeltaTheta);
  

  G4Sphere * RichTbQuartzSphB = new G4Sphere("RichTbQuartzSphB", QuartzRadiatorInnerRadius,QuartzRadiatorRadius,
                                            QuartzRadiatorZStartPhi,QuartzRadiatorZDeltaPhi,
                                            QuartzRadiatorZStartTheta,QuartzRadiatorZDeltaTheta);

  G4ThreeVector SphBPos (0.0, 0.0, QuartzRadiatorSubZShift);
  G4RotationMatrix SphBRotX;
  G4Transform3D SphBTransform( SphBRotX,SphBPos);
  

  //  G4SubtractionSolid* RichTbQuartzSphSubP = new G4SubtractionSolid("SphSubP",RichTbQuartzSphA, 
  //                   RichTbQuartzSphB, SphBTransform  );


  //  G4ThreeVector SphSPos (0.0, 0.0, 0.0);
  //G4RotationMatrix SphSRotX;
  // G4Transform3D SphSTransform( SphSRotX,SphSPos);

  // G4SubtractionSolid* RichTbQuartzSphSubQ = new G4SubtractionSolid("SphSubQ",RichTbQuartzSphA, 
  //                  RichTbQuartzSphSubP , SphSTransform  );


  G4IntersectionSolid* RichTbQuartzSphInt = new  G4IntersectionSolid("SphInt",  RichTbQuartzSphA, RichTbQuartzSphB, SphBTransform);
  

  G4LogicalVolume* aQuartzRadLog = new G4LogicalVolume(  RichTbQuartzSphInt , aMaterial->  getQuartzRadiatorMaterial(),
                                                        RichTbQuartzRadiatorLogName, 0,0,0);
  G4ThreeVector QuartzRadPos(QuartzRadiatorXLocation,QuartzRadiatorYLocation,QuartzRadiatorZLocation);
  
  G4RotationMatrix QuartzRadiatorRotX,QuartzRadiatorRotY;
  QuartzRadiatorRotX.rotateX( QuartzRadiatorXRotation);
  QuartzRadiatorRotY.rotateY(QuartzRadiatorYRotation);
  G4Transform3D QuartzRadiatorTransform(QuartzRadiatorRotX*QuartzRadiatorRotY, QuartzRadPos);
  

  G4VPhysicalVolume* aQuartzRadPhys = 
    new G4PVPlacement (QuartzRadiatorTransform,RichTbQuartzRadiatorPhysName,aQuartzRadLog, 
                       aCVessel ->getRichTbContainerVesselBoxPVol() , false, 0); 
  
                                     
  RichTbQuartzRadiatorLVol  = aQuartzRadLog ;
  RichTbQuartzRadiatorPVol  = aQuartzRadPhys;

}

void RichTbQuartzRadiator::constructQuartzRadiatorCoverGeometry() {

   RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

   G4Tubs *  RichTbDnsQuartzCoverTub = new G4Tubs ("RichTbDnsQuartzCoverTubs",QuartzRadiatorInnerRadius ,
                                         QuartzDnsBlackCoverRadius,0.5*QuartzBlackCoverZSize, 
                                         QuartzRadiatorZStartPhi, QuartzRadiatorZDeltaPhi);
  
   G4LogicalVolume* aQuartzRadDnsCoverLog =  new G4LogicalVolume( RichTbDnsQuartzCoverTub, aMaterial->getCarbon(), 
                                     RichTbQuartzRadiatorDnsCoverLogName, 0,0,0);


   G4Tubs *  RichTbUpsQuartzCoverTub = new G4Tubs ("RichTbUpsQuartzCoverTubs",QuartzRadiatorInnerRadius ,
                                         QuartzUpsBlackCoverRadius,0.5*QuartzBlackCoverZSize, 
                                         QuartzRadiatorZStartPhi, QuartzRadiatorZDeltaPhi);
  
   G4LogicalVolume* aQuartzRadUpsCoverLog =  new G4LogicalVolume( RichTbUpsQuartzCoverTub, aMaterial->getCarbon(), 
                                     RichTbQuartzRadiatorUpsCoverLogName, 0,0,0);


   G4ThreeVector QuartzRadCoverDnsPos(0.0,0.0, QuartzBlackCoverDnsZPos);
   G4RotationMatrix QuartzRadiatorCoverRotX;
   G4Transform3D QuartzRadCoverDnsTransform( QuartzRadiatorCoverRotX, QuartzRadCoverDnsPos);
   

   G4VPhysicalVolume* aQuartzRadCoverDnsPhys =  new G4PVPlacement(QuartzRadCoverDnsTransform, 
                                                       RichTbQuartzRadiatorCoverDnsPhysName,
                                aQuartzRadDnsCoverLog,aCVessel ->getRichTbContainerVesselBoxPVol() ,false, 0);

   
   G4ThreeVector QuartzRadCoverUpsPos(0.0,0.0, QuartzBlackCoverUpsZPos);

   G4Transform3D QuartzRadCoverUpsTransform( QuartzRadiatorCoverRotX, QuartzRadCoverUpsPos);
   
   G4VPhysicalVolume* aQuartzRadCoverUpsPhys = new G4PVPlacement( QuartzRadCoverUpsTransform,
                                      RichTbQuartzRadiatorCoverUpsPhysName, 
                                     aQuartzRadUpsCoverLog,aCVessel ->getRichTbContainerVesselBoxPVol() ,false, 0);
   
   RichTbQuartzRadiatorDnsCoverLVol = aQuartzRadDnsCoverLog;
   RichTbQuartzRadiatorUpsCoverLVol = aQuartzRadUpsCoverLog;
   RichTbQuartzRadiatorDnsCoverPVol = aQuartzRadCoverDnsPhys;
   RichTbQuartzRadiatorUpsCoverPVol = aQuartzRadCoverUpsPhys;   

}
