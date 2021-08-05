// $Id: $
#ifndef INCLUDE_RICHTBPEINFO_HH 
#define INCLUDE_RICHTBPEINFO_HH 1

// Include files
#include "globals.hh"
#include "G4ThreeVector.hh"
#include "RichTbPhotonInfo.hh"

/** @class RichTbPEInfo RichTbPEInfo.hh include/RichTbPEInfo.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2004-01-20
 */
class RichTbPEInfo {
public: 
  /// Standard constructor
  RichTbPEInfo( ); 

  virtual ~RichTbPEInfo( ); ///< Destructor

  G4ThreeVector  PhOrigin(){return mPhOrigin;}
  RichTbPhotonInfo* MotherPhotonInfo(){return mMotherPhotonInfo;}
  G4ThreeVector  PeOriginInHpdSupFrame(){return mPeOriginInHpdSupFrame;}
  

  void setPhOrigin(G4ThreeVector aPhOrigin){mPhOrigin= aPhOrigin;}
  
  void setMotherPhotonInfo(RichTbPhotonInfo* aPhotonInfo ) 
  {    mMotherPhotonInfo=aPhotonInfo;}

  void setPeOriginInHpdSupFrame( G4ThreeVector aPOrInPhSup ) 
  {mPeOriginInHpdSupFrame=aPOrInPhSup;}
  
  void setPhotEmisDir(G4ThreeVector aEmisDir) 
  {    mPhotEmisDir=aEmisDir;}
  G4ThreeVector getPhotEmisDir() {return  mPhotEmisDir;}
    
protected:

private:

  G4ThreeVector mPhOrigin;
  RichTbPhotonInfo* mMotherPhotonInfo;  
  G4ThreeVector mPeOriginInHpdSupFrame;
  G4ThreeVector mPhotEmisDir;
  
  
};
#endif // INCLUDE_RICHTBPEINFO_HH
