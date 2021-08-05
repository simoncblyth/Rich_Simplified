// $Id: $
#ifndef INCLUDE_RICHTBPHOTONINFO_HH 
#define INCLUDE_RICHTBPHOTONINFO_HH 1

// Include files
#include "globals.hh"
#include "G4ThreeVector.hh"

/** @class RichTbPhotonInfo RichTbPhotonInfo.hh include/RichTbPhotonInfo.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2004-01-20
 */
class RichTbPhotonInfo {
public: 
  /// Standard constructor
  RichTbPhotonInfo( ); 

  virtual ~RichTbPhotonInfo( ); ///< Destructor
  G4int NumRayleighScat(){return mNumRayleighScat;}
  G4ThreeVector PhotonCoordPMTQWExternal() 
  {    return mPhotonCoordPMTQWExternal;}
  G4double CkvCosThetaAtProd() 
  {    return mCkvCosThetaAtProd;}
  G4double CkvPhiAtProd() 
  {    return mCkvPhiAtProd;}
  G4double CkvPhotonEnergyAtProd() 
  {    return mCkvPhotonEnergyAtProd;}

  G4int   PhotonPMTQWMultipleIncidenceFlag() 
  {    return mPhotonPMTQWMultipleIncidenceFlag;}

  
  G4double ParentChTrackMomentum() 
  {  return mParentChTrackMomentum;}
  G4ThreeVector ParentChTrackThreeMom() 
  {  return  mParentChTrackThreeMom;}
  G4ThreeVector PhotonCrystalDnsTIRCoord() 
  {  return mPhotonCrystalDnsTIRCoord;}
  G4ThreeVector PhotonSphMirrReflCoord() 
  {  return mPhotonSphMirrReflCoord;}
  G4ThreeVector PhotonCrystalDnsExitCoord()
  {  return mPhotonCrystalDnsExitCoord;}


  G4int   PhotonRadiatorMultipleIncidenceFlag() 
  {    return mPhotonRadiatorMultipleIncidenceFlag;}

 


  void BumpNumRaylieghScat()  {mNumRayleighScat++;}
  void setNumRaylieghScat(G4int aNum)  {mNumRayleighScat=aNum;}
  void setPhotonCoordPMTQWExternal(G4ThreeVector aCoorde )
                    {mPhotonCoordPMTQWExternal=aCoorde;}
  void setCkvCosThetaAtProd(G4double aCosTheta ) 
                     {mCkvCosThetaAtProd=aCosTheta;}
  void setCkvPhiAtProd(G4double aPhi) 
  {    mCkvPhiAtProd=aPhi;}
  void setCkvPhotonEnergyAtProd(G4double aEnergy) 
  {    mCkvPhotonEnergyAtProd=aEnergy;}    
  
  void BumpPhotonPMTQWMultipleIncidenceFlag() 
  {mPhotonPMTQWMultipleIncidenceFlag++;}
    
  void setPhotonPMTQWMultipleIncidenceFlag( G4int amFlag ) 
  {mPhotonPMTQWMultipleIncidenceFlag=amFlag;}

  void setParentChTrackMomentum( G4double aMom ) 
  {mParentChTrackMomentum= aMom;}
  void setParentChTrackThreeMom(G4ThreeVector aTMom) 
  {  mParentChTrackThreeMom=aTMom;}
  void setPhotonCrystalDnsTIRCoord(G4ThreeVector aTC) 
  { mPhotonCrystalDnsTIRCoord= aTC;}
  void setPhotonSphMirrReflCoord(G4ThreeVector aMiC) 
  { mPhotonSphMirrReflCoord = aMiC;}
  void setPhotonCrystalDnsExitCoord(G4ThreeVector aDC) 
  {mPhotonCrystalDnsExitCoord = aDC;}
  
 void  BumpPhotonRadiatorMultipleIncidenceFlag()   
  {    mPhotonRadiatorMultipleIncidenceFlag++;}
  
    
    

protected:

private:

  G4int mNumRayleighScat;
  G4ThreeVector mPhotonCoordPMTQWExternal;
  G4int mPhotonPMTQWMultipleIncidenceFlag;
  G4double mCkvCosThetaAtProd;
  G4double mCkvPhiAtProd;
  G4double mCkvPhotonEnergyAtProd;
  G4double mParentChTrackMomentum;
  G4ThreeVector mParentChTrackThreeMom;
  G4ThreeVector mPhotonCrystalDnsTIRCoord;
  G4ThreeVector mPhotonSphMirrReflCoord;
  G4ThreeVector mPhotonCrystalDnsExitCoord;
  G4int mPhotonRadiatorMultipleIncidenceFlag;
  
};
#endif // INCLUDE_RICHTBPHOTONINFO_HH
