#ifndef RichTbGeometryParameters_h
#define RichTbGeometryParameters_h 1

#include "globals.hh"
#include <math.h>

extern void InitializeRichTbGeometry();
//
//

static const G4double sqroot3 = pow(3.0, 0.5);

#include "RichTbHallGeometryParameters.hh"
#include "RichTbVesselGeometryParameters.hh"

#include "RichTbContainerVesselBoxGeometryParameters.hh"
#include "RichTbMirrorParaGeometryParameters.hh"
#include "RichTbPolymerRadiatorGeometryParameters.hh"
#include "RichTbMirrorSphGeometryParameters.hh"
#include "RichTbLargeMirrorParabolaGeometryParameters.hh"


#include "RichTbPhCPhotDetSupFrameGeometryParameters.hh"


#include "RichTbCrystalGeometryParameters.hh"
#include "RichTbCrystalMasterGeometryParameters.hh"
#include "RichTbRadiatorGeometryParameters.hh"
#include "RichTbLensGeometryParameters.hh"
#include "RichTbMasterGeometryParameters.hh"




#include "RichTbCrystalCoverGeometryParameters.hh"
#include "RichTbMirrorGeometryParameters.hh"
#include "RichTbDarkCoverGeometryParameters.hh"



#include "RichTbPMTGeometryParameters.hh"

#include "RichTbUpgradePMTGeometryNumbering.hh"
#include "RichTbUpgradePMTSupportFrameGeometrySizes.hh"



#include "RichTbPMTSupportFrameGeometryParameters.hh"
#include "RichTbUpgradePMTSupportFrameGeometryParametersLT.hh"

#include "RichTbLTPhCGeometryParameters.hh"

#include "RichTbHpdGeometryParameters.hh"


#include "RichTbExtHpdGeometryParameters.hh"
#include "RichTbHpdSupportFrameGeometryParameters.hh"


#include "RichTbPhDFrameGeometryParameters.hh"

#include "RichTbBeamGeometryParameters.hh"

#include "RichTbQuartzRadiatorGeometryParameters.hh"

//#include "RichTbScintillatorRadiatorGeometryParameters.hh"

//
// Now for the files needed for Opticks test 

#include "RichTbLHCbExptHallGeometryParameters.hh"
#include "RichTbRich1MasterGeometryParameters.hh"
#include "RichTbR1SphMirrorGeometryParameters.hh"
#include "RichTbR1FlatMirrorGeometryParameters.hh"
#include "RichTbLHCbR1MagShRegionGeometryParameters.hh"


#include "RichTbLHCbECModuleGeometryParameters.hh"
#include "RichTbLHCbPmtGeometryParameters.hh"
#include "RichTbLHCbPmtArrayGeometryParameters.hh"
#include "RichTbLHCbR1PhDetSupFrameGeometryParameters.hh"

#include "RichTbLHCbR1QWGeometryParameters.hh"

#endif                          /*RichTbGeometryParameters_h */
