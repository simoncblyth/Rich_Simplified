// $Id: $
#ifndef INCLUDE_RICHTBPHOTONUSERINFOATTACH_HH 
#define INCLUDE_RICHTBPHOTONUSERINFOATTACH_HH 1
#include "G4Track.hh"

extern void RichTbPMTQWIncidenceInfoAttach(G4Track* aPhTrack, 
                                       G4ThreeVector aQWPos);
extern void RichTbRadiatorBoundaryInfoAttach(G4Track* aPhTrack, G4ThreeVector aBoundaryPos, G4int RFROption );

extern void RichTbRayleighInfoAttach( const G4Track& aPhotonTrack);
extern G4Track* RichTbCkvProdInfoAttach(const G4Track& aChTrack,
                                    G4Track* aPhotTrack,
                                    const G4double CkvCosTheta,
                                    const G4double CkvPhi,
                                    const G4double CkvPhotEnergy);


#endif // INCLUDE_RICHTBPHOTONUSERINFOATTACH_HH
