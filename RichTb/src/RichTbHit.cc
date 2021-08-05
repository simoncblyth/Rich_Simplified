// $Id: $
// Include files 



// local
#include "RichTbHit.hh"
#include "G4VVisManager.hh"
#include "G4Circle.hh"
#include "G4Colour.hh"
#include "G4VisAttributes.hh"
#include "G4Transform3D.hh"
#include "G4LogicalVolume.hh"
#include "RichTbVisManager.hh"
G4Allocator<RichTbHit> RichTbHitAllocator;

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbHit
//
// 2003-12-12 : Sajan EASO
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbHit::RichTbHit(  ) {

}
//=============================================================================
// Destructor
//=============================================================================
RichTbHit::~RichTbHit() {} 
RichTbHit::RichTbHit(const RichTbHit &right):G4VHit(right)
{
  edep = right.edep;
  pos = right.pos;
  CurPMTNum = right.CurPMTNum;
  CurPixelNum=right.CurPixelNum;

  mLocalPos=right.mLocalPos;
  mPeOrigin=right.mPeOrigin;
  mPhotonOrigin=right.mPhotonOrigin;
  mRayleighScatFlag=right.mRayleighScatFlag;
  mPhotonIncidenceOnPMTQW=right. mPhotonIncidenceOnPMTQW;
  mCkvCosThetaProd=right.mCkvCosThetaProd;
  mCkvPhiProd=right.mCkvPhiProd;
  mCkvEnergyProd=right.mCkvEnergyProd;
  mPhotonMultIncidenceQW=right.mPhotonMultIncidenceQW;
  mPeOriginInPhSupport = right.mPeOriginInPhSupport;
  mPhEmissionDir = right.mPhEmissionDir;
  mPixelLocalCenter = right.mPixelLocalCenter;
  mPixelGlobalCenter = right.mPixelGlobalCenter;
  mTIRRadiatorCoord  = right.mTIRRadiatorCoord;
  mMIRRadiatorCoord  = right.mMIRRadiatorCoord;
  mRFRRadiatorCoord  = right.mRFRRadiatorCoord;
  mMultipleReflFlag = right.mMultipleReflFlag;
  mChTrackTotMom  = right.mChTrackTotMom;
  mChTrackThreeMom = right.mChTrackThreeMom;
  mHitInPixelGapFlag = right.mHitInPixelGapFlag;
  
}
const RichTbHit& RichTbHit::operator=(const RichTbHit &right)
{
  edep = right.edep;
  pos = right.pos;
  CurPMTNum = right.CurPMTNum;
  CurPixelNum=right.CurPixelNum;

  mLocalPos=right.mLocalPos;
  mPeOrigin=right.mPeOrigin;
  mPhotonOrigin=right.mPhotonOrigin;
  mRayleighScatFlag=right.mRayleighScatFlag;
  mPhotonIncidenceOnPMTQW=right. mPhotonIncidenceOnPMTQW;
  mCkvCosThetaProd=right.mCkvCosThetaProd;
  mCkvPhiProd=right.mCkvPhiProd;
  mCkvEnergyProd=right.mCkvEnergyProd;
  mPhotonMultIncidenceQW=right.mPhotonMultIncidenceQW;
  mPeOriginInPhSupport = right.mPeOriginInPhSupport;
  mPhEmissionDir = right.mPhEmissionDir;
  mPixelLocalCenter = right.mPixelLocalCenter;
  mPixelGlobalCenter = right.mPixelGlobalCenter;
  mTIRRadiatorCoord  = right.mTIRRadiatorCoord;
  mMIRRadiatorCoord  = right.mMIRRadiatorCoord;
  mRFRRadiatorCoord  = right.mRFRRadiatorCoord;
  mMultipleReflFlag = right.mMultipleReflFlag;
  mChTrackTotMom  = right.mChTrackTotMom;
  mChTrackThreeMom = right.mChTrackThreeMom;
  mHitInPixelGapFlag = right.mHitInPixelGapFlag;
  


  return *this;
 
}
int RichTbHit::operator==(const RichTbHit & /*right*/ ) const
{
  return 0;
}

void RichTbHit::Draw()
{

  // The folowing does not work anymore .. SE 26-04-01
  G4VVisManager* pVVisManager = G4VVisManager::GetConcreteInstance();

  if(pVVisManager)
   {

     //  G4Circle circle(pos);
     // circle.SetScreenSize(0.04);
     // circle.SetFillStyle(G4Circle::filled);
     // G4Colour colour(1.0,0.0,0.0);
     // G4VisAttributes attribs(colour);
     // circle.SetVisAttributes(attribs);
     //pVVisManager->Draw(circle);
  }
}
void RichTbHit::DrawWithVisM(RichTbVisManager* pVisManager)
{

  G4VisManager* pVVisManager = pVisManager;
  if(pVVisManager)
   {

     //  G4Circle circle(pos);
     // circle.SetScreenSize(0.04);
     //  circle.SetFillStyle(G4Circle::filled);
     // G4Colour colour(1.0,0.0,0.0);
     // G4VisAttributes attribs(colour);
     // circle.SetVisAttributes(attribs);
     // const  G4Circle aCircle=  circle;
     // const G4Transform3D aTransform;
  
     // pVVisManager->Draw(aCircle, aTransform);
  }
}
void RichTbHit::Print()
{
  // To print the info in the G4hit class.
  G4cout<<" RichTbHit: Now Printing the info for a Hit "<<G4endl;
  G4cout<<"RichTbHit: PMT Pix edep  "<<  CurPMTNum <<"  "<< CurPixelNum
        <<"   "<<  edep<<G4endl;
  G4cout<<"RichTbHit:XYZ  GlobalPos   "
        << pos.x()<<"  "<<pos.y()<<"  "<<pos.z() <<" LocalPos "
        <<mLocalPos.x()<<"  " <<mLocalPos.y()<<"  "<<mLocalPos.z()<<G4endl;
  G4cout<<"RichTbHit:XYZ PeOrigin  "<<mPeOrigin.x() <<"   "
        <<mPeOrigin.y()<<"   "<<mPeOrigin.z()<<" QWIncidence "
        << mPhotonIncidenceOnPMTQW.x()<<"   "
         << mPhotonIncidenceOnPMTQW.y()<<"   "
        << mPhotonIncidenceOnPMTQW.z()<<G4endl;
  G4cout<<" PeOrigin in Ph Support XYZ   "<<
    mPeOriginInPhSupport.x()<<"   "<<mPeOriginInPhSupport.y()
        <<"   "<<mPeOriginInPhSupport.z()<<G4endl;
  
  
  G4cout<<"RichTbHit: NumPMTQWIncidence CosCkv Phi PhotEnergy  "
        << mPhotonMultIncidenceQW<<"   "<<mCkvCosThetaProd
        <<"    "<< mCkvPhiProd<<"   "<<mCkvEnergyProd<<G4endl;

  G4cout<<" Global Photon dir XYZ at its origin   " <<mPhEmissionDir.x()
	<<"  "<<mPhEmissionDir.y()<<"   "<<mPhEmissionDir.z()<<G4endl;

  G4cout<<" RichTbHit Local Global pixel center "<< mPixelLocalCenter <<"  "
        << mPixelGlobalCenter << G4endl; 

  G4cout<<"RichTbHit: End of Printing the info for a Hit "<<G4endl;
  
  G4cout<<" RichTbHit TIR MIR RFR coord "<<mTIRRadiatorCoord<<"   "
        <<mMIRRadiatorCoord<<"   "<<mRFRRadiatorCoord<<G4endl;
  
  G4cout<<" RichTbHit: Multrefl flag "<< mMultipleReflFlag <<G4endl;
  G4cout<< "RichTbHit: Ch Track tot MOm ThreeMom " << mChTrackTotMom
        <<"   "<< mChTrackThreeMom <<G4endl;
  
}
// This is a forward declarations of an instantiated G4Allocator<Type> object.
// It has been added in order to make code portable for the GNU g++ 
// (release 2.7.2) compiler. 
// Whenever a new Type is instantiated via G4Allocator, it has to be forward
// declared to make object code (compiled with GNU g++) link successfully. 
// 
#ifdef GNU_GCC
  template class G4Allocator<RichTbHit>;
#endif


//=============================================================================
