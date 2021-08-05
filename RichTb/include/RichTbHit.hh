// $Id: $
#ifndef INCLUDE_RICHTBHIT_HH 
#define INCLUDE_RICHTBHIT_HH 1

// Include files
#include "globals.hh"
#include "G4VHit.hh"
#include "G4THitsCollection.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
class RichTbVisManager;

/** @class RichTbHit RichTbHit.hh include/RichTbHit.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2003-12-12
 */
class RichTbHit : public G4VHit {
public: 
  /// Standard constructor
  RichTbHit( ); 

  virtual ~RichTbHit( ); ///< Destructor

  RichTbHit(const RichTbHit &right);
  const RichTbHit& operator=(const RichTbHit &right);
  int operator==(const RichTbHit &right) const;
  inline void *operator new(size_t);
  inline void operator delete(void *aHit);
  void Draw() override;
  void DrawWithVisM(RichTbVisManager* );
  void Print() override;

protected:

private:
  G4double edep;      // energy deposited by PE.
  G4ThreeVector pos; //  Global Hit coord on Silicon
  G4int CurPMTNum;  //   PMT Number
  G4int CurPixelNum; //  Pixelnumber 

  G4ThreeVector mLocalPos; // local Hit coord on Silicon.
  G4ThreeVector mPeOrigin; // Global Origin of Photoelectron.  
  G4ThreeVector mPhotonOrigin;  // Global Emission Point of Photon.
  G4int mRayleighScatFlag;  // number of times rayleigh scattered. 0 means no scat.
  G4ThreeVector mPhotonIncidenceOnPMTQW;  // Global Photon incidence coord on hpd QW. 
  G4int mPhotonMultIncidenceQW;  // number of times the photon hits the PMT QW external surface.
  G4double mCkvCosThetaProd; // Cos theta of photon for Cherenkov production.
  G4double mCkvPhiProd;     // Phi for Cherenkov Production.
  G4double mCkvEnergyProd;  // Energy of Photon at Cherenkov production.
  G4ThreeVector mPeOriginInPhSupport; // photoelectron origin photodetector
                                // support frame coord system.

  G4ThreeVector mPhEmissionDir; // Global Direction of the photon at its origin.
  
  G4ThreeVector mPixelLocalCenter;
  G4ThreeVector mPixelGlobalCenter;
  G4ThreeVector mTIRRadiatorCoord;  // Coordinate of Total Internal reflection from the radiator.
  G4ThreeVector mMIRRadiatorCoord;  // Coordinate of reflection from the mirror
  G4ThreeVector mRFRRadiatorCoord;  // Coordinate where refraction happened, before exiting the radiator.
  G4int mMultipleReflFlag;     // Number of times the photon reflected in the radiator. Nominal value=3
  G4double mChTrackTotMom;     // Total momentum of the charged track which created the photons. 
  G4ThreeVector mChTrackThreeMom; // Three vector momentum of the charged track which created photons.
  G4int mHitInPixelGapFlag;  // if 0 the pixel is in the active region of the pixel. If 1, it is in the gap between pixels. 
  

  public:
  inline void SetEdep(G4double de)      { edep = de; };
  inline G4double GetEdep()      { return edep; };
  inline void SetPos(G4ThreeVector xyz)      { pos = xyz; };
  inline G4ThreeVector GetPos()      { return pos; };
  inline void SetCurPMTNum (G4int ihp ) { CurPMTNum = ihp; } ;
  inline void SetCurHPDNum (G4int ihp ) { CurPMTNum = ihp; } ;
  inline G4int GetCurPMTNum()           { return CurPMTNum ; };
  inline G4int GetCurHPDNum()           { return CurPMTNum ; };
  inline void SetCurPixNum (G4int ipx ) { CurPixelNum = ipx; };
  inline G4int GetCurPixNum()           { return CurPixelNum; };
  inline void AddEdep( G4double addenergy ) { edep += addenergy; }  
  inline void SetLocalPos( G4ThreeVector aLocalPos ) 
  {    mLocalPos=  aLocalPos;}
  inline G4ThreeVector GetLocalPos() 
  {    return  mLocalPos;}

  inline void SetPeOrigin(G4ThreeVector aPeOrigin) 
  {    mPeOrigin= aPeOrigin;}
  inline G4ThreeVector GetPeOrigin() 
  {    return  mPeOrigin;  }

  inline void SetPhotonOrigin(G4ThreeVector aOrigin) 
  {    mPhotonOrigin= aOrigin;}
  inline G4ThreeVector GetPhotonOrigin() 
  {    return  mPhotonOrigin;  }
  inline void SetRayleighScatFlag( G4int aFlag) 
  {    mRayleighScatFlag=aFlag;}
  inline G4int GetRayleighScatFlag() 
  {    return mRayleighScatFlag;  }
  inline void SetPhotonIncidenceOnPMTQW(G4ThreeVector aIncidence) 
  {    mPhotonIncidenceOnPMTQW=aIncidence;}
  inline G4ThreeVector GetPhotonIncidenceOnPMTQW() 
  {    return mPhotonIncidenceOnPMTQW;  }
  inline void SetPhotonMultIncidenceQW(G4int aMultIncFlag) 
  {    mPhotonMultIncidenceQW=aMultIncFlag;  }
  inline G4int GetPhotonMultIncidenceQW() 
  {    return mPhotonMultIncidenceQW;  }
  inline void SetCkvCosThetaProd(G4double aTheta ) 
  {    mCkvCosThetaProd=aTheta;  }
  inline G4double GetCkvCosThetaProd() 
  {return mCkvCosThetaProd; }
  inline void SetCkvPhiProd( G4double aPhi) 
  {mCkvPhiProd=aPhi;}
  inline G4double GetCkvPhiProd() 
  {    return mCkvPhiProd;}
  inline void SetCkvEnergyProd( G4double aEnergy) 
  {mCkvEnergyProd=aEnergy;}
  inline G4double GetCkvEnergyProd() 
  {return mCkvEnergyProd;  }
  inline void SetPeOriginInPhSupport(G4ThreeVector aPeOriginInPhSupport)
  { mPeOriginInPhSupport =  aPeOriginInPhSupport;}
  inline G4ThreeVector GetPeOriginInPhSupport() 
  {    return  mPeOriginInPhSupport;}
  
  inline void SetPhEmissionDir(G4ThreeVector aPhEmissionDir) {
    mPhEmissionDir= aPhEmissionDir;}

  inline G4ThreeVector GetPhEmissionDir() {return mPhEmissionDir;}

  inline void SetPixelLocalCenter( G4ThreeVector aP ) 
  {mPixelLocalCenter =aP   ;}
  inline void SetPixelGlobalCenter( G4ThreeVector aG) 
  {mPixelGlobalCenter = aG  ;}
  inline void SetTIRRadiatorCoord(G4ThreeVector aT ) 
  {  mTIRRadiatorCoord = aT;}
  inline void SetMIRRadiatorCoord(G4ThreeVector aM ) 
  {  mMIRRadiatorCoord = aM;}
  inline void SetRFRRadiatorCoord(G4ThreeVector aF ) 
  {  mRFRRadiatorCoord = aF;}

  inline void SetMultipleReflFlag (G4int aFlag) 
  {mMultipleReflFlag = aFlag;}
  inline void SetChTrackTotMom (G4double aMom) 
  {mChTrackTotMom = aMom;}
  inline void SetChTrackThreeMom(G4ThreeVector aThMom)
  {  mChTrackThreeMom =aThMom;}
  inline void SetHitInPixelGapFlag(G4int aGapFlag) 
  { mHitInPixelGapFlag = aGapFlag;}
  

  inline G4ThreeVector getPixelLocalCenter() 
  {return mPixelLocalCenter;}
  inline G4ThreeVector getPixelGlobalCenter() 
  {return mPixelGlobalCenter;}

  inline G4ThreeVector getTIRRadiatorCoord() 
  {  return mTIRRadiatorCoord;}
  inline G4ThreeVector getMIRRadiatorCoord()
  {  return  mMIRRadiatorCoord;}
  inline G4ThreeVector getRFRRadiatorCoord()
  {  return  mRFRRadiatorCoord;}
  inline  G4int getMultipleReflFlag()
  {  return mMultipleReflFlag;}
  inline G4double getChTrackTotMom ()
  {  return mChTrackTotMom;}
  inline  G4ThreeVector getChTrackThreeMom ()
  {  return  mChTrackThreeMom;}
  inline G4int getHitInPixelGapFlag() 
  {  return mHitInPixelGapFlag;}
  


};
typedef G4THitsCollection<RichTbHit> RichTbHitsCollection;

extern G4Allocator<RichTbHit> RichTbHitAllocator;
inline void* RichTbHit::operator new(size_t)
{
  void *aHit;
  aHit = (void *) RichTbHitAllocator.MallocSingle();
  return aHit;
}

inline void RichTbHit::operator delete(void *aHit)
{
  RichTbHitAllocator.FreeSingle((RichTbHit*) aHit);
}



#endif // INCLUDE_RICHTBHIT_HH
