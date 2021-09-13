// $Id: $
#ifndef INCLUDE_RICHTBPHOTONPRODHISTO_HH 
#define INCLUDE_RICHTBPHOTONPRODHISTO_HH 1

// Include files
#include "globals.hh"
#include "G4Track.hh"

extern void RichTbPhotonProductionHisto( const  G4Track& aChTrack,
                                      const G4Track* aPhotTrack,
                                        const G4double CkvCosTh, 
                                        const G4double CkvPhi,
                                        const G4double  CkvPhEner);

#endif // INCLUDE_RICHTBPHOTONPRODHISTO_HH
