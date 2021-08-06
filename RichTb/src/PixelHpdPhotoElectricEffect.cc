// Include files 

#include "globals.hh"
#include <math.h>
#include <vector>
#include "PixelHpdPhotoElectricEffect.hh"
#include "RichTbGeometryParameters.hh"
#include "G4TransportationManager.hh"
#include "Randomize.hh"
#include "RichTbRunConfig.hh"
#include "RichTbMaterialParameters.hh"
#include "G4TouchableHistory.hh"
#include "RichTbPhotoElectron.hh"
#include "RichTbPeUserInfoAttach.hh"


// local

//-----------------------------------------------------------------------------
// Implementation file for class : PixelHpdPhotoElectricEffect
//
// 2015-05-10 : Sajan Easo
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
PixelHpdPhotoElectricEffect::PixelHpdPhotoElectricEffect
 (const G4String& processName):G4VDiscreteProcess(processName),
                               NumHpdTot(NumHpds),NumDemagParam(NumDemagnificationParam),NumQEbins(HpdQENumBins),
                               DemagnificationFactor( NumHpds, std::vector<G4double>(NumDemagnificationParam )),
                               HpdQE( NumHpds, std::vector<G4double>( NumQEbins) ),
                               HpdWabin( NumHpds, std::vector<G4double>( NumQEbins) )
{
  RichTbRunConfig* rConfig = RichTbRunConfig::getRunConfigInstance();
  PrePhotoElectricVolName = HpdQuartzWMaterialName;
  PostPhotoElectricVolName = HpdPhCathodeMaterialName;
  HpdPhElectronMomentum = ( rConfig->getHpdPEMomInit() ) * CLHEP::keV;
  PhCathodeToSilDetDist = RichTbHpdSiDetDistZFromPhCathode;
  HpdPhCathodeRInner = RichTbHpdPhCathodeInnerRad;
  PSFsigma = PixelHpdPSFSigma;
  for(G4int ihpd=0; ihpd<NumHpdTot; ihpd++) {
      DemagnificationFactor[ihpd][0]= PixelHpdDemagLinearFactor;
      DemagnificationFactor[ihpd][1]=  PixelHpdDemagQuadraticFactor;
      std::vector<G4double>qeCurHpd =  InitializeHpdQE(ihpd);
      std::vector<G4double>waCurHpd =  InitializeHpdWaveL(ihpd);
      if( ((int)  qeCurHpd.size() != (int) waCurHpd.size()) ||((int) qeCurHpd.size() !=  (int) HpdQE[ihpd].size())  ){
	          G4cout<<"PhotElectEffect: Wrong size for Hpd QE "<<ihpd<<" "<<(int) qeCurHpd.size()
             		<<"  "<< (int) waCurHpd.size()
	            	<<"  "<<(int)  HpdQE[ihpd].size() <<G4endl;
      }else{
	
        for(G4int iqbin=0; iqbin < (int) qeCurHpd.size(); iqbin++){
	        // in the following the 100 is to convert from percent to
	        // regular fraction.
	      
	      HpdQE[ihpd][iqbin]=qeCurHpd[iqbin]/100;
	      HpdWabin[ihpd][iqbin]=waCurHpd[iqbin];
	      
	        //        G4cout<<" PhotElect hpdnum ibin Hpd Wlen HpdQE   "
	        //      << ihpd<<"   "<< iqbin<<"   "<< HpdWabin[ihpd][iqbin]
	        //      <<"    "<<  HpdQE[ihpd][iqbin]<<G4endl;
	      
       }


      }
      
  }
  
  
  
   G4cout<<GetProcessName() <<" is created "<<G4endl;

}
//=============================================================================
// Destructor
//=============================================================================
PixelHpdPhotoElectricEffect::~PixelHpdPhotoElectricEffect() {} 

//=============================================================================
G4bool PixelHpdPhotoElectricEffect::IsApplicable(const G4ParticleDefinition& aParticleType)
{
  return ( &aParticleType == G4OpticalPhoton::OpticalPhoton() );
}


G4double PixelHpdPhotoElectricEffect::GetMeanFreePath(const G4Track& ,
                                                      G4double ,
                                                      G4ForceCondition* condition)
{
  *condition = Forced;

  return DBL_MAX;
}
G4VParticleChange* PixelHpdPhotoElectricEffect::PostStepDoIt(const G4Track& aTrack,const G4Step& aStep)
{
  aParticleChange.Initialize(aTrack);

  G4StepPoint* pPreStepPoint  = aStep.GetPreStepPoint();
  G4StepPoint* pPostStepPoint = aStep.GetPostStepPoint();

  if (pPostStepPoint->GetStepStatus() != fGeomBoundary)
    return G4VDiscreteProcess::PostStepDoIt(aTrack, aStep);

  G4String PrePhName = pPreStepPoint -> GetPhysicalVolume() ->
    GetLogicalVolume() -> GetMaterial()->GetName();
  G4String PostPhName= pPostStepPoint -> GetPhysicalVolume() ->
    GetLogicalVolume() -> GetMaterial() ->GetName();

  if(( PrePhName == PrePhotoElectricVolName &&
       PostPhName == PostPhotoElectricVolName) ||
     ( PostPhName == PrePhotoElectricVolName &&
       PrePhName == PostPhotoElectricVolName) )
    {

      //    G4cout<<"PadHpdPhElec effect PreVol Post Vol "<<PrePhName
      //      <<"   "<<PostPhName<<G4endl;
    }else {
      return G4VDiscreteProcess::PostStepDoIt(aTrack, aStep);
    }

  // if (aTrack.GetStepLength()<=kCarTolerance/2)
  //   return G4VDiscreteProcess::PostStepDoIt(aTrack, aStep);


  const G4DynamicParticle* aDynamicPhoton = aTrack.GetDynamicParticle();
  G4double PhotonEnergy = aDynamicPhoton->GetKineticEnergy();

  if(PhotonEnergy <= 0.0 ){
      return G4VDiscreteProcess::PostStepDoIt(aTrack, aStep);
  }
  

  //Now use the QE for the current HPD to determine if a
  // photoelectron should be produced or not.

  G4TouchableHistory* CurTT =
    (G4TouchableHistory*)(pPreStepPoint->GetTouchable());
  G4int currentHpdNumber= CurTT -> GetReplicaNumber(2);
  if(currentHpdNumber >= NumHpdTot ||currentHpdNumber < 0   )
    return G4VDiscreteProcess::PostStepDoIt(aTrack, aStep);

  G4double PhotWLength=PhotMomToWaveLength/PhotonEnergy;
  //  G4double PhotWLengthNano =   PhotWLength/(nanometer);
  G4double PhCathodeQE = getHpdQEff(currentHpdNumber, PhotWLength);
  G4double randomnum = G4UniformRand();
  if(randomnum <  PhCathodeQE ) {
     G4double aPhotonTime= aTrack.GetGlobalTime();
 
  G4ThreeVector GlobalElectronOrigin= pPostStepPoint->GetPosition();

  G4Navigator* theNavigator = G4TransportationManager::GetTransportationManager()->GetNavigatorForTracking();
  G4ThreeVector LocalElectronOrigin = theNavigator->GetGlobalToLocalTransform().TransformPoint(GlobalElectronOrigin);

      G4double CurDemagFactor=DemagnificationFactor[currentHpdNumber][0];
      G4double CurDemagQuadFactor=DemagnificationFactor[currentHpdNumber][1];
      G4double PsfRandomAzimuth = CLHEP::twopi*G4UniformRand();
      G4double PsfRandomRad= G4RandGauss::shoot(0.0,PSFsigma);
      G4double PsfX= PsfRandomRad*cos( PsfRandomAzimuth);
      G4double PsfY= PsfRandomRad*sin( PsfRandomAzimuth);
      G4double ElectronCathodeRadius = sqrt( pow(LocalElectronOrigin.x(), 2) +
                                             pow(LocalElectronOrigin.y(), 2) );
      G4double ElectronAnodeRadius = ((CurDemagQuadFactor*ElectronCathodeRadius) + 
                                       CurDemagFactor) * ElectronCathodeRadius;

      G4double scale = -1;
      if(ElectronCathodeRadius != 0)
        { scale = (ElectronAnodeRadius/ElectronCathodeRadius) - 1; }

      G4ThreeVector LocalElectronDirection(LocalElectronOrigin.x()*scale + PsfX,
                                           LocalElectronOrigin.y()*scale + PsfY,
                                           -(PhCathodeToSilDetDist-
                                             (HpdPhCathodeRInner-
                                              LocalElectronOrigin.z())));
  LocalElectronDirection = LocalElectronDirection.unit();

  const G4ThreeVector GlobalElectronDirection = theNavigator->
                                GetLocalToGlobalTransform().
                                TransformAxis(LocalElectronDirection);
 
  G4double ElecKineEnergy= getHpdPhElectronMomentum();

  G4TouchableHistory* CurTTP = (G4TouchableHistory*) (pPreStepPoint->GetTouchable());
  CurTTP -> MoveUpHistory(2);
  G4int   CurTTPDepth=  CurTTP->GetHistoryDepth();
  G4ThreeVector ElnOrgInPhDet =  CurTTP->GetHistory()->GetTransform(CurTTPDepth).TransformPoint(GlobalElectronOrigin);



  G4DynamicParticle* aElectron=
    new G4DynamicParticle (RichTbPhotoElectron::PhotoElectron(),
                                GlobalElectronDirection, ElecKineEnergy) ;

   aParticleChange.SetNumberOfSecondaries(1) ;

   G4Track* aSecPETrack =
               new G4Track(aElectron,aPhotonTime,GlobalElectronOrigin);

      aSecPETrack->SetTouchableHandle((G4VTouchable*)0);
      aSecPETrack->SetParentID(aTrack.GetTrackID());
      aSecPETrack->SetGoodForTrackingFlag(true);
      G4Track* aTaggedSecPETrack = RichTbPeInfoAttach(aTrack,aSecPETrack,
                                                          ElnOrgInPhDet);
      //  G4cout<<" Now created a  secondary track from pixel hpd photoelectric effect "<<G4endl;
      
      aParticleChange.AddSecondary(aTaggedSecPETrack);
    aParticleChange.ProposeTrackStatus(fStopAndKill);
    aParticleChange.ProposeEnergy(0.0);
  
    } else {

    //photon is not killed if it is not converted to photoelectron

    }
  
return G4VDiscreteProcess::PostStepDoIt(aTrack, aStep);

}
G4double PixelHpdPhotoElectricEffect::getHpdQEff(G4int HpdNum,
  G4double PhotonWLength){

    G4double hq1=0.0;    G4double hq2=0.0;
    G4double wa1=0.0; G4double wa2=0.0; G4double aslope=0.0;
    // G4double aintc=0.0;
  //  G4cout<<"Now in Hpd QE Finder hpdnum PhWlen   "
  //      <<HpdNum<<"    "<<PhotonWLength<<G4endl;
    G4double qeff=0.0;

  if( PhotonWLength ==  HpdWabin[HpdNum][ HpdQENumBins-1] ) {
    qeff =  HpdQE[HpdNum] [HpdQENumBins-1] ;
  }else if (  PhotonWLength ==  HpdWabin[HpdNum][ 0] ) {
    qeff = HpdQE[HpdNum] [0];
  } else if( ( PhotonWLength >= HpdWabin[HpdNum][0]) &&
      ( PhotonWLength < HpdWabin[HpdNum][HpdQENumBins-1]) ) {
  G4int ibinq=0;
  G4bool BinFound=false;
  while (ibinq< (NumQEbins-1)  && (! (BinFound))  ){
  wa1 = HpdWabin[HpdNum][ibinq];
  wa2 = HpdWabin[HpdNum][ibinq+1];
  if( PhotonWLength >= wa1 && PhotonWLength < wa2 ) {
   hq1 =   HpdQE[HpdNum][ibinq];
   hq2 =   HpdQE[HpdNum][ibinq+1];
   aslope = (hq2-hq1)/(wa2-wa1);
   // aintc =  hq1 - (aslope * wa1 );
   //   qeff= aintc + aslope * PhotonWLength ;
   qeff= hq1 + aslope * (PhotonWLength-wa1) ;
   BinFound=true;

  }
  ibinq++;
  }

  }


  return qeff;

}
