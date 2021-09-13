// Include files
// local
#include "RichTbLHCbROGeometry.hh"
#include "RichTbOpticksDetectorConstruction.hh"
#include "RichTbRunConfig.hh"
#include "RichTbGeometryParameters.hh"

#include "RichTbLHCbExptHall.hh"
#include "RichTbLHCbRich1Master.hh"
#include "RichTbLHCbRich1SubMaster.hh"
#include "RichTbLHCbR1MagShRegion.hh"
#include "RichTbLHCbR1PhDetSupFrame.hh"
#include "RichTbLHCbR1Module.hh"
#include "RichTbLHCbR1EC.hh"
#include "RichTbLHCbR1Pmt.hh"
#include "RichTbLHCbR1PmtComponents.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbLHCbROGeometry
//
// Created 2003-12-11 : Sajan EASO
// Update  2021-08-07 : SE
//-----------------------------------------------------------------------------
//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbLHCbROGeometry::RichTbLHCbROGeometry(G4String RoNameString,
		RichTbOpticksDetectorConstruction* aDet  )
: G4VReadOutGeometry(RoNameString){

	CurDet = aDet;

}
//=============================================================================
G4VPhysicalVolume* RichTbLHCbROGeometry::Build()
{
	RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
	G4int aRadiatorConfiguration = aConfig ->getRadiatorConfiguration();

     // now construct the readout geometry.
     RichTbLHCbExptHall*  rTbLHCbExptHallRO    = new RichTbLHCbExptHall();
     if(aRadiatorConfiguration >= 40 && aRadiatorConfiguration < 50 ) {
      RichTbLHCbRich1Master* rTbRich1MasterRO     = 
                 new RichTbLHCbRich1Master(rTbLHCbExptHallRO );

      RichTbLHCbRich1SubMaster * rTbRich1SubMasterRO = 
                 new RichTbLHCbRich1SubMaster(rTbRich1MasterRO);

      RichTbLHCbR1MagShRegion * rTbR1MagShRegionRO   = 
                 new  RichTbLHCbR1MagShRegion(rTbRich1SubMasterRO);

      RichTbLHCbR1PhDetSupFrame* rTbR1PhDetSupFrameRO = 
	new  RichTbLHCbR1PhDetSupFrame(rTbR1MagShRegionRO);

      RichTbLHCbR1Module * rTbR1ModuleRO       = 
                 new  RichTbLHCbR1Module(rTbR1PhDetSupFrameRO);

      RichTbLHCbR1EC* rTbR1ECRO           = 
                 new  RichTbLHCbR1EC(rTbR1ModuleRO);

      RichTbLHCbR1Pmt * rTbR1PmtRO          = 
                 new  RichTbLHCbR1Pmt( rTbR1ECRO);

      RichTbLHCbR1PmtComponents* rTbR1PmtComponentsRO  = 
	new  RichTbLHCbR1PmtComponents(rTbR1PmtRO );
	rTbR1PmtComponentsRO->constructR1PmtAnodePixel();
        G4cout<<" End of building ROGeometry "<<G4endl;
     }
     return rTbLHCbExptHallRO-> getRichTbLHCbExptHallPhysicalVolume();
}

//=============================================================================
// Destructor
//=============================================================================
RichTbLHCbROGeometry::~RichTbLHCbROGeometry() {}

//=============================================================================
