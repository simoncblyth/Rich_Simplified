// Geant4 headers
#include "G4Box.hh"
#include "G4ThreeVector.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4SystemOfUnits.hh"
//#include "Geant4/G4SDManager.hh"

// STL etc
#include <iostream>

// local headers
#include "RichTbMiscNames.hh"
#include "RichTbGeometryParameters.hh"
#include "RichTbOpticksDetectorConstruction.hh"
#include "RichTbSurfaceDefinition.hh"
#include "RichTbLHCbSurface.hh"
#include "RichTbGraphicsLbR.hh"
#include "RichTbLHCbUpgradeSD.hh"
#include "SensitiveDetector.hh"

RichTbOpticksDetectorConstruction::RichTbOpticksDetectorConstruction() { ;}


RichTbOpticksDetectorConstruction::~RichTbOpticksDetectorConstruction()
{;}

G4VPhysicalVolume * RichTbOpticksDetectorConstruction::Construct() {
	// now create all the materials and surface properties.
	// RichTbMaterial* rMaterial = RichTbMaterial::getRichTbMaterialInstance();
  //
      

	RichTbRunConfig* aConfig = RichTbRunConfig::getRunConfigInstance();

        rTbLHCbExptHall    = new RichTbLHCbExptHall();

        int aRadiatorConfiguration = aConfig ->getRadiatorConfiguration();
        if( aRadiatorConfiguration >= 40 && aRadiatorConfiguration < 50 ) {

	  // This is for the test beam version of the simplified Rich1 geometry 
          
	  RichTbSurfaceDefinition* rSurfaceDef=
	  		RichTbSurfaceDefinition::getRichTbSurfaceDefinitionInstance();

           ResetStdVol();


           rTbRich1Master     = new RichTbLHCbRich1Master(rTbLHCbExptHall );
           rTbRich1SubMaster  = new RichTbLHCbRich1SubMaster(rTbRich1Master);
           rTbR1SphMirror     = new RichTbLHCbR1SphMirror(rTbRich1SubMaster);
           rTbR1FlatMirror    = new  RichTbLHCbR1FlatMirror(rTbRich1SubMaster);
           rTbR1MagShRegion   = new  RichTbLHCbR1MagShRegion(rTbRich1SubMaster);
           rTbR1QW            = new  RichTbLHCbR1QW(rTbR1MagShRegion);
	   rTbR1PhDetSupFrame = new  RichTbLHCbR1PhDetSupFrame(rTbR1MagShRegion);
	   rTbR1Module       = new  RichTbLHCbR1Module(rTbR1PhDetSupFrame);
           rTbR1EC           = new  RichTbLHCbR1EC(rTbR1Module);
           rTbR1Pmt          = new  RichTbLHCbR1Pmt( rTbR1EC);
           rTbR1PmtComponents  = new  RichTbLHCbR1PmtComponents(rTbR1Pmt );     
           rTbR1PmtComponents-> constructR1PmtComp();

           // Creation of surfaces

	   rTbR1Surface  = new RichTbLHCbSurface(this);
           // test print 
           G4cout<< " RichTb Surfaces are defined "<< rSurfaceDef 
                 <<"   "<<rTbR1Surface <<G4endl;
           // end test print 

           //sensitive detector creation
 
           G4SDManager* SDman = G4SDManager::GetSDMpointer();

           //RichTbLHCbUpgradeSD * LbPMTSD = new RichTbLHCbUpgradeSD(PMTLHCbSDname);
           SensitiveDetector * PMTSD = new SensitiveDetector(PMTLHCbSDname);

           //Readout Geometry
           //rTbR1ROGeometry = new RichTbLHCbROGeometry( ROgeometryLbR1Name, this );
           //rTbR1ROGeometry->BuildROGeometry() ;
	   //LbPMTSD -> SetROgeometry(rTbR1ROGeometry);
           //SDman ->AddNewDetector(LbPMTSD);
           SDman ->AddNewDetector(PMTSD);
	   
           //G4LogicalVolume* RichTbLbPmt_LV = rTbR1Pmt->getRichTbLbR1PmtLogicalVolume();
           //RichTbLbPmt_LV ->SetSensitiveDetector( LbPMTSD );
           G4LogicalVolume* RichTbLbPmtQuartz_LV = rTbR1PmtComponents->getRichTbLbR1PmtQuartzLogicalVolume();
           RichTbLbPmtQuartz_LV->SetSensitiveDetector( PMTSD );

	   //Add border surface
	   /*
	   G4OpticalSurface* PmtWrap = new G4OpticalSurface("PmtWrap");
	   new G4LogicalBorderSurface("PmtWrap", rTbR1MagShRegion->getRichTbLHCbR1MagShRegionPhysicalVolume(), rTbR1PhDetSupFrame->getRichTbLHCbR1PhDetSupFramePhysicalVolume(), PmtWrap);
	   PmtWrap->SetType(dielectric_metal);
	   PmtWrap->SetFinish(polished);
	   PmtWrap->SetModel(glisur);
	   G4double pp[] = {2.0*CLHEP::eV, 3.5*CLHEP::eV};
	   const G4int num = sizeof(pp)/sizeof(G4double);
	   G4double reflectivity[] = {0.0, 0.0};
	   G4double efficiency[] = {1.0, 1.0};
	   G4MaterialPropertiesTable* PmtWrapProperty = new G4MaterialPropertiesTable();
	   PmtWrapProperty->AddProperty("REFLECTIVITY", pp, reflectivity, num);
	   PmtWrapProperty->AddProperty("EFFICIENCY", pp, efficiency, num);
	   PmtWrap->SetMaterialPropertiesTable(PmtWrapProperty);
	   */
           //begin test
            G4int HCID = G4SDManager::GetSDMpointer()->GetCollectionID (RichTbLHCbR1G4HColname);
            G4cout<< " Now associate sensdet to geometry in Pmt "<< HCID <<  G4endl;

           // end test
           // Now for the graphics setups.
           RichTbGraphicsLbR* rTbGraphicsLbR = new RichTbGraphicsLbR(this);
           if( rTbGraphicsLbR) G4cout<<" Graphics definitions created for RicbTb R1 Opticks"<<G4endl;

	}

	return rTbLHCbExptHall-> getRichTbLHCbExptHallPhysicalVolume();
}
void RichTbOpticksDetectorConstruction::ResetStdVol() {


  rTbRich1Master =0;
  rTbRich1SubMaster=0;
  rTbR1SphMirror =0;
  rTbR1FlatMirror=0;
  rTbR1MagShRegion=0;
  rTbR1QW =0;
  rTbR1PhDetSupFrame=0;
  rTbR1Module = 0;
  rTbR1EC = 0 ;
  rTbR1Pmt  = 0;
  rTbR1PmtComponents =0 ;

    

}
