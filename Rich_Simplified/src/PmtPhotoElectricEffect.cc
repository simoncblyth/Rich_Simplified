#include "globals.hh"
#include <math.h>
#include <vector>
#include "PmtPhotoElectricEffect.hh"
#include "RichTbGeometryParameters.hh"
#include "G4TransportationManager.hh"
#include "Randomize.hh"
#include "RichTbRunConfig.hh"
#include "RichTbMaterialParameters.hh"
#include "G4TouchableHistory.hh"
#include "RichTbPhotoElectron.hh"
#include "RichTbPeUserInfoAttach.hh"
#include "RichTbMiscNames.hh"


PmtPhotoElectricEffect::PmtPhotoElectricEffect(const G4String& processName):
G4VDiscreteProcess(processName),
NumPmtTot(NumPmts),
//NumPmtTot(RichTbPMTGeometryParameters::getNumPmts()), // TESTNumPmts
NumQEbins(PmtQENumBins),
PmtQE( NumPmts, std::vector<G4double>( NumQEbins) ),
PmtWabin( NumPmts, std::vector<G4double>( NumQEbins) )
//PmtQE( RichTbPMTGeometryParameters::getNumPmts(), std::vector<G4double>( NumQEbins) ), // TESTNumPmts
//PmtWabin( RichTbPMTGeometryParameters::getNumPmts(), std::vector<G4double>( NumQEbins) ) // TESTNumPmts
{
  	RichTbRunConfig* rConfig = RichTbRunConfig::getRunConfigInstance();
  //	G4int aRadiatorConfiguration = rConfig->getRadiatorConfiguration();

//	if(aRadiatorConfiguration == 3) {
//		NumPmtTot = NumPmtsUpgrade15;
////		PmtQE.reserve(NumPmtTot);
////		PmtWabin.reserve(NumPmtTot);
//	} else NumPmtTot = NumPmts;


     if( rConfig ->getRadiatorConfiguration() == 6) {
        NumPmtTot = NumPmtsUpgrade16;
        PmtQE.resize( NumPmtTot);
        PmtWabin.resize( NumPmtTot);
      
     } else if (rConfig ->getRadiatorConfiguration() == 7 ){
      NumPmtTot = NumPmtsUpgrade17;
      PmtQE.resize( NumPmtTot);
      PmtWabin.resize( NumPmtTot);
      
     }
    

	PrePhotoElectricVolName = PMTQwLogVolName;
	PostPhotoElectricVolName = PMTPhCathLogVolName;
	//PmtPhElectronMomentum = 2 * GeV;
	PmtPhElectronMomentum = ( rConfig->getPMTPEMomInit() ) * CLHEP::keV;
	PhCathodeToSilDetDist = PMTQuartzToAnodeSurfaceDistance;

	for (int ipmt=0; ipmt < NumPmtTot; ++ipmt ) {

		std::vector<G4double>qeCurPmt =  InitializePMTQE(ipmt);
		std::vector<G4double>waCurPmt =  InitializePMTWaveL(ipmt);
		for(G4int iqbin=0;  iqbin < (int) qeCurPmt.size(); iqbin++)
		{

			PmtQE[ipmt][iqbin]=qeCurPmt[iqbin]/100;
			PmtWabin[ipmt][iqbin]=waCurPmt[iqbin];
			//	G4cout<< "PmtQE :" << 	PmtQE[ipmt][iqbin] << G4endl;
		}

	}

	//	G4cout<<"PMT Photoelectic process created "<<G4endl;

}

PmtPhotoElectricEffect::~PmtPhotoElectricEffect(){}


G4bool PmtPhotoElectricEffect::IsApplicable(const G4ParticleDefinition& aParticleType)
{
	return ( &aParticleType == G4OpticalPhoton::OpticalPhoton() );
}

G4double PmtPhotoElectricEffect::GetMeanFreePath(const G4Track& ,
		G4double ,
		G4ForceCondition* condition)
{
	*condition = Forced;

	return DBL_MAX;
}

G4VParticleChange* PmtPhotoElectricEffect::PostStepDoIt(const G4Track& aTrack,const G4Step& aStep) {
	aParticleChange.Initialize(aTrack);

	G4StepPoint* pPreStepPoint  = aStep.GetPreStepPoint();
	G4StepPoint* pPostStepPoint = aStep.GetPostStepPoint();

	if (pPostStepPoint->GetStepStatus() != fGeomBoundary)
		return G4VDiscreteProcess::PostStepDoIt(aTrack, aStep);

	G4String PrePhName = pPreStepPoint -> GetPhysicalVolume() ->
			GetLogicalVolume() ->GetName();
	G4String PostPhName= pPostStepPoint -> GetPhysicalVolume() ->
			GetLogicalVolume() ->GetName();

	//  G4cout<<"PMTPhElec effect PreVol Post Vol "<<PrePhName
	//		           <<"   "<<PostPhName<<G4endl;


	if(( PrePhName == PrePhotoElectricVolName &&
			PostPhName == PostPhotoElectricVolName) ||
			( PostPhName == PrePhotoElectricVolName &&
					PrePhName == PostPhotoElectricVolName) )
	{
		//   G4cout<<"PMTPhElec effect PreVol Post Vol "<<PrePhName
		//      <<"   "<<PostPhName<<G4endl;


	}  else  {
		return G4VDiscreteProcess::PostStepDoIt(aTrack, aStep);
	}

	//  if (aTrack.GetStepLength()<=kCarTolerance/2)
	// return G4VDiscreteProcess::PostStepDoIt(aTrack, aStep);

	const G4DynamicParticle* aDynamicPhoton = aTrack.GetDynamicParticle();
	G4double PhotonEnergy = aDynamicPhoton->GetKineticEnergy();
	if(PhotonEnergy <= 0.0 )
	{
		return G4VDiscreteProcess::PostStepDoIt(aTrack, aStep);
	}
	G4TouchableHistory* CurTT =
			(G4TouchableHistory*)(pPreStepPoint->GetTouchable());

	// CurTT -> MoveUpHistory(2);
	G4int currentPmtNumber= CurTT -> GetReplicaNumber(2);

	if(currentPmtNumber >= NumPmtTot ||currentPmtNumber < 0   )
		return G4VDiscreteProcess::PostStepDoIt(aTrack, aStep);
	G4double PhotWLength=PhotMomToWaveLength/PhotonEnergy;
  //G4double PhotWLengthNano =   PhotWLength/(CLHEP::nanometer);
	 //  G4cout<<"PhotElect pmtnum PhEn Wlen  "<<currentPmtNumber
	 //   <<"    "<<PhotonEnergy<<"   "
	 //   << PhotWLength<<G4endl;
	G4double PhCathodeQE = getPmtQEff(currentPmtNumber, PhotWLength);
	// G4cout<<"PhotElect pmtnum PhEn Wlen QE "<<currentPmtNumber
	//   <<"    "<<PhotonEnergy<<"   "
	//    << PhotWLength<< "  "<< PhCathodeQE<< G4endl;


	G4double randomnum = G4UniformRand();
	// G4cout<<"PhotElect random num "<< randomnum <<G4endl;
  
	if(randomnum <  PhCathodeQE ) {
		// create photoelectron
		G4double aPhotonTime= aTrack.GetGlobalTime();
		G4ThreeVector GlobalElectronOrigin= pPostStepPoint->GetPosition();
		G4Navigator* theNavigator =
				G4TransportationManager::GetTransportationManager()->
				GetNavigatorForTracking();
		G4ThreeVector LocalElectronOriginInit = theNavigator->
				GetGlobalToLocalTransform().
				TransformPoint(GlobalElectronOrigin);
		G4double ElecOriginTolerence= 0.004 * CLHEP::mm;
		G4ThreeVector LocalElectronOrigin (LocalElectronOriginInit.x(),
				LocalElectronOriginInit.y(),
				LocalElectronOriginInit.z()- ElecOriginTolerence );
		G4ThreeVector LocalElectronDirection(0,0,+1);
		LocalElectronDirection = LocalElectronDirection.unit();
		const G4ThreeVector GlobalElectronDirection = theNavigator->
				GetLocalToGlobalTransform().
				TransformAxis(LocalElectronDirection);
		G4double ElecKineEnergy= 100000*PmtPhElectronMomentum;

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
		// G4cout<<" PMTPh electric: created photoelectron "<<G4endl;
		aSecPETrack->SetTouchableHandle((G4VTouchable*)0);
		aSecPETrack->SetParentID(aTrack.GetTrackID());
		aSecPETrack->SetGoodForTrackingFlag(true);
		G4Track* aTaggedSecPETrack = RichTbPeInfoAttach(aTrack,aSecPETrack,  ElnOrgInPhDet);
		aParticleChange.AddSecondary(aTaggedSecPETrack);

		//	 G4cout<<" added a sec tagged track in photoelectric "<<G4endl;


		//aParticleChange.AddSecondary(aTaggedSecPETrack);
		//aParticleChange.AddSecondary(aSecPETrack);

		aParticleChange.ProposeTrackStatus(fStopAndKill);
		aParticleChange.ProposeLocalEnergyDeposit(PhotonEnergy);


	}else {
		//photon is not killed if it is not converted to photoelectron

	}
	return G4VDiscreteProcess::PostStepDoIt(aTrack, aStep);
}
G4double PmtPhotoElectricEffect::getPmtQEff(G4int PmtNum,
		G4double PhotonWLength){

	G4double hq1=0.0;    G4double hq2=0.0;
	G4double wa1=0.0; G4double wa2=0.0; G4double aslope=0.0;
	// G4double aintc=0.0;
	//  G4cout<<"Now in Hpd QE Finder hpdnum PhWlen   "
	//      <<HpdNum<<"    "<<PhotonWLength<<G4endl;
	G4double qeff=0.0;

	if( PhotonWLength ==  PmtWabin[PmtNum][ PmtQENumBins-1] ) {
		qeff =  PmtQE[PmtNum] [PmtQENumBins-1] ;
	}else if (  PhotonWLength ==  PmtWabin[PmtNum][ 0] ) {
		qeff = PmtQE[PmtNum] [0];
	} else if( ( PhotonWLength >= PmtWabin[PmtNum][0]) &&
			( PhotonWLength < PmtWabin[PmtNum][PmtQENumBins-1]) ) {
		G4int ibinq=0;
		G4bool BinFound=false;
		while (ibinq< (NumQEbins-1)  && (! (BinFound))  ){
			wa1 = PmtWabin[PmtNum][ibinq];
			wa2 = PmtWabin[PmtNum][ibinq+1];
			if( PhotonWLength >= wa1 && PhotonWLength < wa2 ) {
				hq1 =   PmtQE[PmtNum][ibinq];
				hq2 =   PmtQE[PmtNum][ibinq+1];
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
