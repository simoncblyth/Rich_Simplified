// Include files
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1SphMirror.hh"
#include "G4RotationMatrix.hh"
#include "G4ThreeVector.hh"
#include "G4Transform3D.hh"
#include "G4SubtractionSolid.hh"
#include "G4Box.hh"
#include "G4Sphere.hh"

#include "U.hh"
#include "G4IntersectionSolid.hh"
#include "G4Orb.hh"

#include "G4PVPlacement.hh"
#include "RichTbRunConfig.hh"
#include "RichTbMaterial.hh"


#include <iostream>

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbLHCbR1SphMirror
// SE 22-07-2021
//--------------------------------------------------------
RichTbLHCbR1SphMirror::RichTbLHCbR1SphMirror(RichTbLHCbRich1SubMaster* rTbLHCbR1SubMaster) {
  mTbLHCbR1SubMaster = rTbLHCbR1SubMaster;
  constructLbR1SphMirror();
} 
RichTbLHCbR1SphMirror::~RichTbLHCbR1SphMirror() {; }
void RichTbLHCbR1SphMirror::constructLbR1SphMirror() {
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();

  G4Sphere* RichTbR1SphFullSph = new G4Sphere ("RichTbR1SphFullSph",RichTbR1SphMirrInnerRadius,
					   RichTbR1SphMirrOuterRadius,RichTbR1SphMirrPhiStart,
                                           RichTbR1SphMirrDeltaPhi, RichTbR1SphMirrThetaStart,
                                           RichTbR1SphMirrDeltaTheta);
  G4Box * RichTbR1SphSubBox = new G4Box("RichTbR1SphSubBox",RichTbR1SphMirrSubHalfSizeX,
					RichTbR1SphMirrSubHalfSizeY, RichTbR1SphMirrSubHalfSizeZ);
  G4RotationMatrix RichTbR1SubBoxRot;
  G4ThreeVector  RichTbR1SubBoxTPos ( RichTbR1SphMirrSubPosX,RichTbR1SphMirrSubUpPosY,RichTbR1SphMirrSubPosZ);  
  G4ThreeVector  RichTbR1SubBoxBPos ( RichTbR1SphMirrSubPosX,RichTbR1SphMirrSubDownPosY,RichTbR1SphMirrSubPosZ);  
  G4ThreeVector  RichTbR1SubBoxLPos ( RichTbR1SphMirrSubPosX,RichTbR1SphMirrSubPosY,RichTbR1SphMirrSubLeftPosZ);  
  G4ThreeVector  RichTbR1SubBoxRPos ( RichTbR1SphMirrSubPosX,RichTbR1SphMirrSubPosY,RichTbR1SphMirrSubRightPosZ);  
  G4Transform3D  RichTbR1SubBoxTTrans(  RichTbR1SubBoxRot, RichTbR1SubBoxTPos);
  G4Transform3D  RichTbR1SubBoxBTrans(  RichTbR1SubBoxRot, RichTbR1SubBoxBPos);
  G4Transform3D  RichTbR1SubBoxLTrans(  RichTbR1SubBoxRot, RichTbR1SubBoxLPos);
  G4Transform3D  RichTbR1SubBoxRTrans(  RichTbR1SubBoxRot, RichTbR1SubBoxRPos);
  G4SubtractionSolid* RichTbR1TSph = new G4SubtractionSolid("RichTbR1SphTSph",RichTbR1SphFullSph,
                                            RichTbR1SphSubBox , RichTbR1SubBoxTTrans);
  G4SubtractionSolid* RichTbR1BSph = new G4SubtractionSolid("RichTbR1SphBSphBox",RichTbR1TSph,
                                            RichTbR1SphSubBox , RichTbR1SubBoxBTrans);
  G4SubtractionSolid* RichTbR1LSph = new G4SubtractionSolid("RichTbR1SphLSphBox",RichTbR1BSph,
                                            RichTbR1SphSubBox , RichTbR1SubBoxLTrans);
  G4SubtractionSolid* RichTbR1RSph = new G4SubtractionSolid("RichTbR1SphRSphBox",RichTbR1LSph,
                                            RichTbR1SphSubBox , RichTbR1SubBoxRTrans);

  G4VSolid* solid = RichTbR1RSph ;  

  //////////// SCB  ////////////////////////////////////////////////////////////////////////

  const char* envkey = "RichTbLHCbR1SphMirror_mode" ; 
  int mode = U::getenvint(envkey, 0); 

  if( mode == 1 )
  {
      const G4double& InnerRadius  = RichTbR1SphMirrInnerRadius ; 
      const G4double& OuterRadius  = RichTbR1SphMirrOuterRadius ; 
      const G4double& Thickness    = RichTbR1SphMirrThickness ; 
      const G4double& SegmentSizeY = RichTbR1SphMirrSegmentSizeY ; 
      const G4double& SegmentSizeZ = RichTbR1SphMirrSegmentSizeX ;   // the SizeX is misnamed, should be SizeZ 

      const G4double SagittaMax = 80.*CLHEP::mm ;  // see ~/opticks/extg4/X4SolidMaker.cc X4SolidMaker::LHCbRichSphMirr
      const G4double FullDepthX =  Thickness + SagittaMax ;  
      const G4double MiddleRadius = (InnerRadius + OuterRadius)/2. ; 

      std::cout 
          << "RichTbLHCbR1SphMirror::constructLbR1SphMirror"
          << " mode " << mode 
          << " InnerRadius " << InnerRadius  
          << " OuterRadius " << OuterRadius  
          << " MiddleRadius " << MiddleRadius  
          << " Thickness " << Thickness 
          << " FullDepthX " << FullDepthX 
          << " SegmentSizeY " << SegmentSizeY
          << " SegmentSizeZ " << SegmentSizeZ
          << std::endl 
          ; 

      G4Orb* inner = new G4Orb("inner",InnerRadius); 
      G4Orb* outer = new G4Orb("outer",OuterRadius); 
      G4SubtractionSolid* shell = new G4SubtractionSolid("shell", outer, inner ); 
      G4Box* box = new G4Box("box", FullDepthX/2. , SegmentSizeY/2. , SegmentSizeZ/2. );   
      G4String rootname = "RichTbR1SphRSphBox" ; 
      rootname += "_CSG_EXBB" ; 
      G4VSolid* alt = new G4IntersectionSolid( rootname, shell, box, 0, G4ThreeVector( MiddleRadius, 0., 0. ));    

      solid = alt ; 
  }

  std::cout 
      << "RichTbLHCbR1SphMirror::constructLbR1SphMirror"
      << " envkey " << envkey 
      << " mode " << mode 
      << " solid.GetName " << solid->GetName()
      << std::endl 
      ; 

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////


  G4RotationMatrix MirrSphRotationY,MirrSphRotationZ;
  MirrSphRotationY.rotateY(RichTbR1SphMirrRotY);
  MirrSphRotationZ.rotateZ(RichTbR1SphMirrRotZ);

  G4ThreeVector MirrSphPos (RichTbR1SphMirrPosX,RichTbR1SphMirrPosY,RichTbR1SphMirrPosZ);
  G4Transform3D MirrSphTransform ( MirrSphRotationY * MirrSphRotationZ, MirrSphPos);
  rTbR1SphMirrorLVol = new G4LogicalVolume(solid,aMaterial->getRichTbCarbonFibreMaterial(),
                                 RichTbR1SphMirrorLogName,0,0,0);

  rTbR1SphMirrorPVol = new G4PVPlacement(MirrSphTransform,RichTbR1SphMirrorPhysName,rTbR1SphMirrorLVol,
					 mTbLHCbR1SubMaster->getRichTbLHCbRich1SubMasterPhysicalVolume(),false,1);

}
