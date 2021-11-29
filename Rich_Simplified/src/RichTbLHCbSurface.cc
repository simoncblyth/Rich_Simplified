// $Id: $
// Include files 



// local
#include "RichTbLHCbSurface.hh"
#include "G4LogicalBorderSurface.hh"
#include "RichTbSurfaceDefinition.hh"
#include "RichTbOpticksDetectorConstruction.hh"


//-----------------------------------------------------------------------------
// Implementation file for class : RichTbSurface
//
// 2021-08-01 : Sajan EASO
//-----------------------------------------------------------------------------
RichTbLHCbSurface::RichTbLHCbSurface(
  RichTbOpticksDetectorConstruction* aDet  ) {

  curDet= aDet;
  createLHCbBorderSurfaces();
  
}
RichTbLHCbSurface::~RichTbLHCbSurface(  ) {;}
void RichTbLHCbSurface::createLHCbBorderSurfaces() {
  RichTbSurfaceDefinition* aSurfaceDef=
     RichTbSurfaceDefinition::getRichTbSurfaceDefinitionInstance();
 
  G4cout << "creating RichTB LHCb mirror surfaces " << G4endl; 
 
  G4LogicalBorderSurface* R1SphMirrorBorderSurface =
     new G4LogicalBorderSurface("RichTbR1SphMirrorSphSurface",
	   curDet-> getRichTbLHCbRich1SubMaster() -> getRichTbLHCbRich1SubMasterPhysicalVolume(),
           curDet->getRichTbLHCbR1SphMirror()->getRichTbLHCbR1SphMirrorPhysicalVolume(), 
           aSurfaceDef->getRichTbSphMirrorSurface());

    if(R1SphMirrorBorderSurface) G4cout<<" R1 Sph Mirror surface created "<<G4endl;

  if( !curDet->isNoFlatMirror() ){
    G4LogicalBorderSurface* R1FlatMirrorBorderSurface =
      new G4LogicalBorderSurface("RichTbR1FlatMirrorSphSurface",
	   curDet-> getRichTbLHCbRich1SubMaster() -> getRichTbLHCbRich1SubMasterPhysicalVolume(),
           curDet->getRichTbLHCbR1FlatMirror()-> getRichTbLHCbR1FlatMirrorPhysicalVolume(), 
           aSurfaceDef->getRichTbSphMirrorSurface());

    if(R1FlatMirrorBorderSurface) G4cout<<" R1 Flat Mirror surface created "<<G4endl;
  }

    G4cout << "creating RichTB R1 Submaster surface " << G4endl; 
 
    G4LogicalBorderSurface* R1SubMasterBorderSurface =
      new G4LogicalBorderSurface("RichTbR1SubMasterSurface",
	   curDet-> getRichTbLHCbRich1SubMaster() -> getRichTbLHCbRich1SubMasterPhysicalVolume(),
           curDet->  getRichTbLHCbRich1Master ()->  getRichTbLHCbRich1MasterPhysicalVolume(), 
           aSurfaceDef-> getRichTbVesselSurface() );


    if(R1SubMasterBorderSurface) G4cout<<" R1 SubMaster surface created "<<G4endl;
  

}
