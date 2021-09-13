// $Id: $
// Include files 



// local
#include "RichTbPhotonInfo.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbPhotonInfo
//
// 2004-01-20 : Sajan EASO
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbPhotonInfo::RichTbPhotonInfo(  ): mNumRayleighScat(0),
                                        mPhotonCoordPMTQWExternal(0),
                                        mPhotonPMTQWMultipleIncidenceFlag(0),
                                        mCkvCosThetaAtProd(0.0),
                                        mCkvPhiAtProd(-10.0),
                                        mCkvPhotonEnergyAtProd(-1.0),
                                        mParentChTrackMomentum(0.0),
                                        mParentChTrackThreeMom(0),
                                        mPhotonCrystalDnsTIRCoord(0),
                                        mPhotonSphMirrReflCoord(0),
                                        mPhotonCrystalDnsExitCoord(0),
                                        mPhotonRadiatorMultipleIncidenceFlag(0)  
 {}
//=============================================================================
// Destructor
//=============================================================================
RichTbPhotonInfo::~RichTbPhotonInfo() {} 

//=============================================================================
