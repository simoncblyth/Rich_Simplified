// $Id: $
#ifndef INCLUDE_RICHTBPEUSERINFOATTACH_HH 
#define INCLUDE_RICHTBPEUSERINFOATTACH_HH 1

// Include files
#include "G4Track.hh"
#include "G4ThreeVector.hh"

extern G4Track* RichTbPeInfoAttach( const G4Track& aPhotonTk, G4Track* aPETk,
                                   G4ThreeVector aPeOriginInPhSup);

extern  G4Track* RichTbPeBckAttach( const G4Track& aphotontk, G4Track* aSecPETrack ) ;

#endif // INCLUDE_RICHTBPEUSERINFOATTACH_HH
