// $Id: $
#ifndef INCLUDE_RICHTBUSERTRACKINFO_HH 
#define INCLUDE_RICHTBUSERTRACKINFO_HH 1

// Include files
#include "G4VUserTrackInformation.hh"
#include "RichTbPEInfo.hh"
#include "RichTbPhotonInfo.hh"

/** @class RichTbUserTrackInfo RichTbUserTrackInfo.hh include/RichTbUserTrackInfo.hh
 *  
 *
 *  @author Sajan EASO
 *  @date   2004-01-20
 */
class RichTbUserTrackInfo:public G4VUserTrackInformation {
public: 
  /// Standard constructor
  RichTbUserTrackInfo( ); 
  RichTbUserTrackInfo(RichTbPhotonInfo* );
  RichTbUserTrackInfo(RichTbPEInfo* );
  

  virtual ~RichTbUserTrackInfo( ); ///< Destructor

  RichTbPhotonInfo* getRichTbPhotonInfo(){    return mRichTbPhotonInfo; }
  void setRichTbPhotonInfo(RichTbPhotonInfo* aRichTbPhotonInfo)
  {mRichTbPhotonInfo=aRichTbPhotonInfo;}

  RichTbPEInfo* getRichTbPEInfo(){    return mRichTbPEInfo;}
  void setRichTbPEInfo(RichTbPEInfo* aRichTbPEInfo)
  {mRichTbPEInfo=aRichTbPEInfo;   }
  
  bool HasUserPhotonInfo(){return  mHasUserPhotonInfo;}
  void setUserPhotonInfo(bool abPhValue)  {mHasUserPhotonInfo=abPhValue;}  
    
  bool HasUserPEInfo(){return mHasUserPEInfo;}
  void setUserPEInfo(bool abPeValue )  {mHasUserPEInfo = abPeValue;}

  virtual void Print () const override {} ;
  
  
    
protected:

private:
  RichTbPhotonInfo* mRichTbPhotonInfo;
  RichTbPEInfo* mRichTbPEInfo;
  
  bool mHasUserPhotonInfo;
  bool mHasUserPEInfo;
  
 
};
#endif // INCLUDE_RICHTBUSERTRACKINFO_HH
