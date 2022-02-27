// Include files
#include "RichTbGeometryParameters.hh"
#include "RichTbMiscNames.hh"
#include "RichTbMaterial.hh"
#include "RichTbLHCbR1FlatMirror.hh"
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
// Implementation file for class : RichTbLHCbR1FlatMirror
// SE 22-07-2021
//--------------------------------------------------------
RichTbLHCbR1FlatMirror::RichTbLHCbR1FlatMirror(RichTbLHCbRich1SubMaster* rTbLHCbR1SubMaster, bool tinyFlatMirror) {
  mTbLHCbR1SubMaster = rTbLHCbR1SubMaster;
  m_tinyFlatMirror = tinyFlatMirror;
  constructLbR1FlatMirror();
}

RichTbLHCbR1FlatMirror::~RichTbLHCbR1FlatMirror() {; }

void RichTbLHCbR1FlatMirror::constructLbR1FlatMirror() {
  RichTbMaterial* aMaterial = RichTbMaterial::getRichTbMaterialInstance();
  
    
  G4Sphere* RichTbR1FlatFull = new G4Sphere ("RichTbR1FlatFull",RichTbR1FlatMirrInnerRadius,
                                           RichTbR1FlatMirrOuterRadius,RichTbR1FlatMirrStartPhi,
                                           RichTbR1FlatMirrDeltaPhi, RichTbR1FlatMirrStartTheta,
                                           RichTbR1FlatMirrDeltaTheta);

  G4VSolid* solid = RichTbR1FlatFull ;  


  //////////// SCB  ////////////////////////////////////////////////////////////////////////

  const char* envkey = "RichTbLHCbR1FlatMirror_mode" ; 
  int mode = U::getenvint(envkey, 0); 

  if( mode == 1 )
  {
      const G4double& InnerRadius  = RichTbR1FlatMirrInnerRadius ; 
      const G4double& OuterRadius  = RichTbR1FlatMirrOuterRadius ; 
      const G4double& Thickness    = RichTbR1FlatMirrThickness ; 
      const G4double& SegmentSizeY = RichTbR1FlatMirrSegmentSizeY ; 
      const G4double& SegmentSizeZ = RichTbR1FlatMirrSegmentSizeX ;   // the SizeX is misnamed, should be SizeZ 

      const G4double SagittaMax = 1.*CLHEP::mm ;  // see ~/opticks/extg4/X4SolidMaker.cc X4SolidMaker::LHCbRichFlatMirr
      const G4double FullDepthX =  Thickness + SagittaMax ;  
      const G4double MiddleRadius = (InnerRadius + OuterRadius)/2. ; 

      std::cout 
          << "RichTbLHCbR1FlatMirror::constructLbR1FlatMirror"
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
      G4String rootname = "RichTbR1FlatFull" ; 
      rootname += "_CSG_EXBB" ; 
      G4VSolid* alt = new G4IntersectionSolid( rootname, shell, box, 0, G4ThreeVector( MiddleRadius, 0., 0. ));    

      solid = alt ; 
  }

  std::cout 
      << "RichTbLHCbR1FlatMirror::constructLbR1FlatMirror"
      << " envkey " << envkey 
      << " mode " << mode 
      << " solid.GetName " << solid->GetName()
      << std::endl 
      ; 

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////


   G4RotationMatrix MirrFlatRotationX,MirrFlatRotationY;
   MirrFlatRotationX.rotateX(RichTbR1FlatMirrRotX);
   MirrFlatRotationY.rotateY(RichTbR1FlatMirrRotY);
   G4ThreeVector  MirrFlatPos (RichTbR1FlatMirrPosX,RichTbR1FlatMirrPosY,RichTbR1FlatMirrPosZ);

   
   G4Transform3D MirrFlatTransform (MirrFlatRotationX * MirrFlatRotationY, MirrFlatPos  ) ;
   rTbR1FlatMirrorLVol = 
        new G4LogicalVolume(solid, aMaterial->getMirrorQuartz(),RichTbR1FlatMirrorLogName,0,0,0);
   rTbR1FlatMirrorPVol = new G4PVPlacement(MirrFlatTransform,RichTbR1FlatMirrorPhysName,rTbR1FlatMirrorLVol,
					   mTbLHCbR1SubMaster->getRichTbLHCbRich1SubMasterPhysicalVolume(),false,1);

}                                          

