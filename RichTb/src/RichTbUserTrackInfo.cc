// $Id: $
// Include files 



// local
#include "RichTbUserTrackInfo.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbUserTrackInfo
//
// 2004-01-20 : Sajan EASO
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbUserTrackInfo::RichTbUserTrackInfo(  ):  mRichTbPhotonInfo(0),
 mRichTbPEInfo(0),mHasUserPhotonInfo(false),mHasUserPEInfo(false) {

}
RichTbUserTrackInfo::RichTbUserTrackInfo(RichTbPhotonInfo* aRichTbPhotonInfo): 
 mRichTbPEInfo(0),mHasUserPEInfo(false){ 
  mRichTbPhotonInfo= aRichTbPhotonInfo;
  mHasUserPhotonInfo=true;
  
}
RichTbUserTrackInfo::RichTbUserTrackInfo(RichTbPEInfo* aRichTbPEInfo): 
mRichTbPhotonInfo(0), mHasUserPhotonInfo(false){
  mRichTbPEInfo=aRichTbPEInfo;
  mHasUserPEInfo=true;
  
}


//=============================================================================
// Destructor
//=============================================================================
RichTbUserTrackInfo::~RichTbUserTrackInfo() {} 

//=============================================================================
