#include "G4Timer.hh"
#include "RichTbAnalysisManager.hh"
#include "globals.hh"
#include  <fstream>
#include  <memory>
#include <ctype.h>
#include <cstdlib>
#include "G4ios.hh"
#include "G4Run.hh"
#include "G4Event.hh"
#include "G4Track.hh"
#include "G4VVisManager.hh"
#include "G4TrajectoryContainer.hh"
#include "G4Trajectory.hh"
#include "G4SteppingManager.hh"
#include "G4SDManager.hh"
#include "G4HCofThisEvent.hh"
#include "RichTbRunConfig.hh"
#include "G4VHitsCollection.hh"
#include "RichTbHit.hh"
#include "RichTbCounter.hh"
#include "RichTbMiscNames.hh"
#include "RichTbGeometryParameters.hh"
#include <TH1D.h>
#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>

//#include <CLHEP/Units/SystemOfUnits.h>
#include <math.h>
#include "RichTbMaterialParameters.hh"
#include "RichTbRunConfig.hh"

RichTbAnalysisManager *RichTbAnalysisManager::RichTbAnalysisInstance = 0;

RichTbAnalysisManager::RichTbAnalysisManager()
{
	//  : analysisFactory(0), tree(0),treeNt(0), hfactory(0),nfactory(0)

	fRootFile=0;
	for (G4int k=0; k<MaxHisto; k++) fHisto[k] = 0;
	fNtuple1=0;
	fPhotonXCoord=0;
	fPhotonYCoord=0;
	fPhotonZCoord=0;
	fPhotonXYCoord=0;
	fPhotonXYCoord15=0;
	fPhotonWidthProfile=0;
	fPhotonXYCoordProfile=0;
	fPhotonXYCoordProfileCut=0;
	fPhotonZCoord=0;
	fPhotonZAngle=0;
	fCherenkovAngle=0;
	fCherenkovAngleCut=0;
	fRadiusVsWLProfile=0;
	fRadiusVsWL=0;
	fSpectrum=0;
	fSpectrumPostMirror=0;
	fSpectrumPreMirror=0;

	//  RichTbRunConfig* rConfig = RichTbRunConfig::getRunConfigInstance();

	//  G4String outputFileName= "testHistoFile";

	//    G4String dirName = rConfig->getOutputHistoDirName();
	// G4String aHistoFileName = "histofile";

	//G4String outputHistoFileName= aHistoFileName;

	//G4String outputHistoFileName = aHistoFileName;
	// G4String outputHistoFileName = dirName + aHistoFileName;

	// analysisFactory =  AIDA_createAnalysisFactory();

	//std::auto_ptr<AIDA::IAnalysisFactory> af( AIDA_createAnalysisFactory() );

	//  analysisFactory = af;

	// if (analysisFactory) {
	//   AIDA::ITreeFactory * treeFactory = analysisFactory->createTreeFactory();
	//  if (treeFactory) {
	//    tree = treeFactory->
	//create(outputHistoFileName, "hbook", false, true);
	//            tree = treeFactory->create(outputHistoFileName,"hbook",
	//          false,true,"");

	//     treeNt = treeFactory->
	//create(OutputNtFileName,"hbook",false,true);

	//  delete treeFactory; // Will not delete the ITree.
	//     hfactory = analysisFactory->createHistogramFactory(*tree);
	//  nfactory =analysisFactory->createTupleFactory(*treeNt);

	//    }
	//  }
}




RichTbAnalysisManager *RichTbAnalysisManager::getInstance()
{
	if (RichTbAnalysisInstance == 0) {
		RichTbAnalysisInstance = new RichTbAnalysisManager();
	}
	return RichTbAnalysisInstance;

}


void RichTbAnalysisManager::InitializeCounters()
{
	iTimer = new G4Timer;

}
void RichTbAnalysisManager::SetOutputHistoFile(){
	RichTbRunConfig* rConfig = RichTbRunConfig::getRunConfigInstance();

	G4String outputHistoFileName =
			rConfig->getOutputHistoFileName();
	// G4String    OutputNtFileName=  rConfig->getOutputNtupleFileName();
	fRootFile = new TFile(outputHistoFileName,"RECREATE");
	if(!fRootFile) {
	  //	G4cout << " RichTBAnalysis Manager::book :"
	  //	<< " problem creating the ROOT TFile "<< outputHistoFileName
	  //			<< G4endl;
	}

  


}


void RichTbAnalysisManager::BookHisto()
{
	//RichTbRunConfig* rConfig = RichTbRunConfig::getRunConfigInstance();

  //	G4String outputHistoFileName =
  //			rConfig->getOutputHistoFileName();
  //	// G4String    OutputNtFileName=  rConfig->getOutputNtupleFileName();
  //	fRootFile = new TFile(outputHistoFileName,"RECREATE");
  //	if(!fRootFile) {
  //		G4cout << " RichTBAnalysis Manager::book :"
  //				<< " problem creating the ROOT TFile "<< outputHistoFileName
	//			<< G4endl;
  //	}

	fHisto[0] = new TH1D("1", "Example random number histo ", 100, 0., 100.0);
	if (!fHisto[0]) G4cout << "\n can't create histo 1" << G4endl;


	//const double p = 2.78;

	fRadiatorRefIndex = new TH2D("RadiatorRefIndex", "RefIndex - 1 vs Wavelength ", 80, 200, 800.0, 120, 0.3, 0.9);
	fRadiatorRefIndex->SetXTitle("#lambda [nm]");
	fRadiatorRefIndex->SetYTitle("n-1");
	fRadiatorRefIndex->SetMarkerStyle(8);
	fRadiatorRefIndex->SetMarkerColor(kBlue);



	fRadiatorRefIndexHits = new TProfile("RadiatorRefIndexHits", "RefIndex -1 vs Wavelength for photons creating hits",
			80, 200, 800.0, 0.3, 0.9);

	fPhotonXCoord =  new TH1D("100", "Photon X location on frame " , 100,-350.0, 350.0);
	fPhotonYCoord =  new TH1D("101", "Photon Y location on frame " , 100,-350.0, +350.0);
	fPhotonZCoord =  new TH1D("102", "Photon Z location on frame " , 100, -400.0, -50.0);

	//  fPhotonXYCoord =  new TH2D("103", "Photon location on frame " , 150, -208.5, 208.5, 150, -208.5, 208.5);
	fPhotonXYCoord =  new TH2D("103", "Photon location on frame " , 200, -70.0, 70.0, 200, -70.0, 70.0);


	fPhotonWidthProfile = new TH1D("104", "Cherenkov ring radius", 100, 45., 63.5);
	fPhotonXYCoordProfile = new TProfile("105", "Profile Photon location on frame", 100, -60.0, 60.0, -60.0, -20.0);
	fPhotonXYCoordProfileCut = new TProfile("106", "Profile Photon location on frame - cut", 100, -30.0, 30.0, -60.0, -20.0);

	fPhotonZAngle =  new TH1D("200", "Photon Z angle on Photon frame " , 100, -2, 2);
	fCherenkovAngle =  new TH1D("201", "Cherenkov Angle " , 100, 0.75, 0.93);
	fCherenkovAngleCut =  new TH1D("202", "Cherenkov Angle - cut " , 100, 0.80, 0.90);

	fRadiusVsWL =  new TH2D("300", "WaveLenght vs Radius " , 400, 200., 3000., 100, 56., 59.);
	fRadiusVsWLProfile = new TProfile("301", "WaveLenght Profile vs Radius", 200, 200., 3000., 56.0, 59.0);
	fSpectrum =  new TH1D("302", "Photons spectrum on PMTs frame " , 200, 300.0, 3000.0);
	fSpectrumPostMirror =  new TH1D("303", "Photons spectrum post Mirror " , 200, 300.0, 3000.0);
	fSpectrumPreMirror =  new TH1D("304", "Photons spectrum pre Mirror " , 200, 300.0, 3000.0);

	fCkvRadiusVsEmisPtPhoton = new TProfile ("310","CherenkovRadius vs Emission Point for photons", 80, -260.0,-220.0,50.0, 70.0);
	fEmisPtPhoton = new  TH1D("312","Emission point for  photons", 80,-260.0,-220.0);
	fEmisPtPhoton->SetXTitle("z [mm]");
	fEmisPtPrimaryTrackPhoton = new  TH1D("314","Emission point for  photons from PrimaryTrack ", 80,-260.0,-220.0);
	fEmisPtPrimaryTrackPhoton->SetXTitle("z [mm]");

	fGeneratedCkvPhoton = new TH1D("320", "Generated Cherenkov angle for Photons", 60, 0.75, 0.95);

	fTIRXYLocationPhoton = new TH2D("TIRXYLocationPhoton","TIR Location for Photons which reached pmt plane",
			80,-80.0,80.0,40,-40.0,40.0);

	fXYRadiatorDnsPhoton = new TH2D("fXYRadiatorDnsPhoton", "Dns XY location for photons",
			80, -80.0, 80.0,40, -40.0,40.0);

	fXYRadiatorTIRDnsPhoton = new TH2D("fXYRadiatorTIRDnsPhoton", "TIR Dns XY location for photons",
			80, -80.0, 80.0,40, -40.0,40.0);
	fXYRadiatorRFRDnsPhoton = new TH2D("fXYRadiatorRFRDnsPhoton", "RFR Dns XY location for photons",
			80, -80.0, 80.0,40, -40.0,40.0);
	fMIRXYLocationPhoton = new TH2D("fMIRXYLocationPhoton", "Mirror  XY location for photons which reached pmt plane",
			80, -80.0, 80.0,40, -40.0,40.0);

	fRFRXYLocationPhoton = new TH2D("fRFRXYLocationPhoton","Exit plane location for photons which reached pmt plane",
			80, -80.0, 80.0,40, -40.0,40.0);

  //	fGlobalHitXYCoordPeOrigin =  new TH2D("500", "GlobalHitPeOriginXYCoord", 220 , -110.0,110.0,80,-40.0,40.0);
  //	fGlobalHitXYCoord =  new TH2D("510", "GlobalHitXYCoord", 220 , -110.0,110.0, 80,-40.0,40.0);

  //	fGlobalPixelCenterXYCoord =  new TH2D("515", "GlobalPixelCenterXYCoord", 220 , -110.0,110.0,80,-40.0,40.0);


	fGlobalHitXYCoordPeOrigin =  new TH2D("500", "GlobalHitPeOriginXYCoord", 220 , -110.0,110.0,240,-120.0,120.0);
	fGlobalHitXYCoord =  new TH2D("510", "GlobalHitXYCoord", 220 , -110.0,110.0, 120,-60.0,60.0);
	fGlobalPixelCenterXYCoord =  new TH2D("515", "GlobalPixelCenterXYCoord", 220 , -110.0,110.0,240,-120.0,120.0);



	fNumHitInEvent  = new TH1D ("600"," Number of Hits per event ", 40, 0.0, 40.0);

	fNumHitInEventSmall  = new TH1D ("600A"," Number of Hits per event for small yield", 100, 0.0, 5.0);

	fNumHitInEventCentralPMT  = new TH1D ("602",
			"Number of Hits per event (in the 8 PMTs near the beamline)", 90, 0.0, 90.0);
	fNumHitInEventCentralPMT->SetXTitle("Hits per Event");

	fNumHitInEventCentralPMTJura  = new TH1D ("604",
				" Number of Hits per event (in the 2 PMTs near the beamline on Jura side)", 60, 0.0, 60.0);
	fNumHitInEventCentralPMTSaleve  = new TH1D ("606",
				" Number of Hits per event (in the 2 PMTs near the beamline on Saleve side)", 60, 0.0, 60.0);


	fNumHitInPMT0   = new TH1D ("HtPMT0","Number of Hits per event in PMT0 (correspond to EC0_PMT_2)" , 20, 0.0,20.0);
	fNumHitInPMT1   = new TH1D ("HtPMT1","Number of Hits per event in PMT1 (correspond to EC0_PMT_1)" , 20, 0.0,20.0);
	fNumHitInPMT2   = new TH1D ("HtPMT2","Number of Hits per event in PMT2 (correspond to EC0_PMT_3)" , 20, 0.0,20.0);
	fNumHitInPMT3   = new TH1D ("HtPMT3","Number of Hits per event in PMT3 (correspond to EC0_PMT_0)" , 20, 0.0,20.0);
	fNumHitInPMT4   = new TH1D ("HtPMT4","Number of Hits per event in PMT4 (correspond to EC1_PMT_2)" , 20, 0.0,20.0);
	fNumHitInPMT5   = new TH1D ("HtPMT5","Number of Hits per event in PMT5 (correspond to EC1_PMT_1)" , 20, 0.0,20.0);
	fNumHitInPMT6   = new TH1D ("HtPMT6","Number of Hits per event in PMT6 (correspond to EC1_PMT_3)" , 20, 0.0,20.0);
	fNumHitInPMT7   = new TH1D ("HtPMT7","Number of Hits per event in PMT7 (correspond to EC1_PMT_0)" , 20, 0.0,20.0);
	fNumHitInPMT8   = new TH1D ("HtPMT8","Number of Hits per event in PMT8 (correspond to EC2_PMT_2)" , 20, 0.0,20.0);
	fNumHitInPMT9   = new TH1D ("HtPMT9","Number of Hits per event in PMT9 (correspond to EC2_PMT_1)" , 20, 0.0,20.0);
	fNumHitInPMT10   = new TH1D ("HtPMT10","Number of Hits per event in PMT10 (correspond to EC2_PMT_3)" , 20, 0.0,20.0);
	fNumHitInPMT11   = new TH1D ("HtPMT11","Number of Hits per event in PMT11 (correspond to EC2_PMT_0)" , 20, 0.0,20.0);
	fNumHitInPMT12   = new TH1D ("HtPMT12","Number of Hits per event in PMT12 (correspond to EC3_PMT_2)" , 20, 0.0,20.0);
	fNumHitInPMT13   = new TH1D ("HtPMT13","Number of Hits per event in PMT13 (correspond to EC3_PMT_1)" , 20, 0.0,20.0);
	fNumHitInPMT14   = new TH1D ("HtPMT14","Number of Hits per event in PMT14 (correspond to EC3_PMT_3)" , 20, 0.0,20.0);
	fNumHitInPMT15   = new TH1D ("HtPMT15","Number of Hits per event in PMT15 (correspond to EC3_PMT_0)" , 20, 0.0,20.0);

	//Total map

	TCanvas *TotMap = new TCanvas("TotMap","");
	TotMap->Divide(2,8);
	TotMap->cd(650);
	TotMap->cd(651);
	TotMap->cd(652);


	G4double radMax = 70.0;
	G4double radMin = 50.0;
	G4double radNBins = 150;
	radiusInPMT0   = new TH1D ("rIn0","Hit Coordinate Radius on PMT Plane (PMT0)" , radNBins, radMin,radMax);
	radiusInPMT1   = new TH1D ("rIn1","Hit Coordinate Radius on PMT Plane (PMT1)" , radNBins, radMin,radMax);
	radiusInPMT2   = new TH1D ("rIn2","Hit Coordinate Radius on PMT Plane (PMT2)" , radNBins, radMin,radMax);
	radiusInPMT3   = new TH1D ("rIn3","Hit Coordinate Radius on PMT Plane (PMT3)" , radNBins, radMin,radMax);
	radiusInPMT4   = new TH1D ("rIn4","Hit Coordinate Radius on PMT Plane (PMT4)" , radNBins, radMin,radMax);
	radiusInPMT5   = new TH1D ("rIn5","Hit Coordinate Radius on PMT Plane (PMT5)" , radNBins, radMin,radMax);
	radiusInPMT6   = new TH1D ("rIn6","Hit Coordinate Radius on PMT Plane (PMT6)" , radNBins, radMin,radMax);
	radiusInPMT7   = new TH1D ("rIn7","Hit Coordinate Radius on PMT Plane (PMT7)" , radNBins, radMin,radMax);
	radiusInPMT8   = new TH1D ("rIn8","Hit Coordinate Radius on PMT Plane (PMT8)" , radNBins, radMin,radMax);
	radiusInPMT9   = new TH1D ("rIn9","Hit Coordinate Radius on PMT Plane (PMT9)" , radNBins, radMin,radMax);
	radiusInPMT10   = new TH1D ("rIn10","Hit Coordinate Radius on PMT Plane (PMT10)" , radNBins, radMin,radMax);
	radiusInPMT11   = new TH1D ("rIn11","Hit Coordinate Radius on PMT Plane (PMT11)" , radNBins, radMin,radMax);
	radiusInPMT12   = new TH1D ("rIn12","Hit Coordinate Radius on PMT Plane (PMT12)" , radNBins, radMin,radMax);
	radiusInPMT13   = new TH1D ("rIn13","Hit Coordinate Radius on PMT Plane (PMT13)" , radNBins, radMin,radMax);
	radiusInPMT14   = new TH1D ("rIn14","Hit Coordinate Radius on PMT Plane (PMT14)" , radNBins, radMin,radMax);
	radiusInPMT15   = new TH1D ("rIn15","Hit Coordinate Radius on PMT Plane (PMT15)" , radNBins, radMin,radMax);
	radiusInPMT0->SetXTitle("r [mm]");
	radiusInPMT1->SetXTitle("r [mm]");
	radiusInPMT2->SetXTitle("r [mm]");
	radiusInPMT3->SetXTitle("r [mm]");
	radiusInPMT4->SetXTitle("r [mm]");
	radiusInPMT5->SetXTitle("r [mm]");
	radiusInPMT6->SetXTitle("r [mm]");
	radiusInPMT7->SetXTitle("r [mm]");
	radiusInPMT8->SetXTitle("r [mm]");
	radiusInPMT9->SetXTitle("r [mm]");
	radiusInPMT10->SetXTitle("r [mm]");
	radiusInPMT11->SetXTitle("r [mm]");
	radiusInPMT12->SetXTitle("r [mm]");
	radiusInPMT13->SetXTitle("r [mm]");
	radiusInPMT14->SetXTitle("r [mm]");
	radiusInPMT15->SetXTitle("r [mm]");

	fGlobalHitXYCoord15 =  new TH2D("GlobalHitXYCoordinate", "Global Hit XY-Coordinate", 220 , -110.0,110.0, 240,-120.0,120.0);
	fGlobalHitXYCoord15->SetXTitle("x [mm]");
	fGlobalHitXYCoord15->SetYTitle("y [mm]");


	fNtuple1 = new TTree("10", "RichTbNtup");
	fNtuple1->Branch("NtupVar1", &fNtupVar1, "NtupVar1/D");
	fNtuple1->Branch("NtupVar2", &fNtupVar2, "NtupVar2/D");


	BookHistoHpd();

	//	G4cout<<" Histogram file created "<<G4endl;

}

void RichTbAnalysisManager::BookHistoHpd() {




	fNumHitInHPD0   = new TH1D ("2650","Number of Hits per event in HPD0" , 80, 0.0,20.0);
	fNumHitSignalInHPD0   = new TH1D ("2652","Number of Hits per event in signal region in HPD0" , 80, 0.0,20.0);

	fRFRXYLocationPhotonHpd = new TH2D("fRFRXYLocationPhotonHpd","Exit plane location for photons which reached Hpd plane",
			80, -80.0, 80.0,40, -40.0,40.0);

	fGlobalHitXYCoordPeOriginHpd =  new TH2D("2500", "GlobalHitPeOriginXYCoordHpd", 320 , -160.0,0.0,80,-40.0,40.0);
	fGlobalHitXYCoordHpd =  new TH2D("2510", "GlobalHitXYCoordHpd", 320 , -160.0,0.0, 80,-40.0,40.0);

	fGlobalPixelCenterXYCoordHpd =  new TH2D("2515", "GlobalPixelCenterXYCoordHpd", 320 , -160.0,0.0,80,-40.0,40.0);


	fGlobalHitXYCoordPeOriginHpdPmt = new TH2D("2520", "GlobalHitPeOriginXYCoordHpdPmt", 320 , -160.0,160.0,80,-40.0,40.0);
	fGlobalHitXYCoordPixPhcathHpd =  new TH2D("2525", "GlobalHitXYCoordHpdPhCathode", 320 , -160.0,0.0,80,-40.0,40.0);

}

void RichTbAnalysisManager::BookHistoPhCAnalysis() {
  fDetPlaneXYCoord = new TH2D("XYCoordDetPlane", "Det Plane XY Coord ",  100, -30.0, 30.0,100, -30.0, 30.0);
  fDetPlaneNumHits = new TH1D("DetPlaneNumPhot", "Det Plane Num Phot", 100, 0.0, 40.0 );
  

}


RichTbAnalysisManager::~RichTbAnalysisManager()
{

	//    delete hfactory;
	//    hfactory = 0;

	//  delete analysisFactory;
	//   analysisFactory = 0;

	// delete tree;
	//if(fRootFile) delete fRootFile;

	if(RichTbAnalysisInstance !=0 ) delete  RichTbAnalysisInstance;


	//	G4cout << "RichTbAnalysisManager Deleted" << G4endl;

}


void RichTbAnalysisManager::BeginOfRunAnalysis()
{
	// G4cout << "### Run " << aRun->GetRunID() << " start." << G4endl;
	RichTbRunConfig* rConfig = RichTbRunConfig::getRunConfigInstance();
  G4int aRadiatorConfiguration = rConfig ->getRadiatorConfiguration();


	InitializeCounters();

  

  SetOutputHistoFile();
  
  if( aRadiatorConfiguration != 10 ){
    
    BookHisto();
  }else {
    BookHistoPhCAnalysis();
  }
  
  
  
}


void RichTbAnalysisManager::EndOfRunAnalysis()
{

	//  if (tree) {
	//    G4cout<<" Now writing histos out "<<G4endl;

	//      tree->commit();         // Write histos and tuple in file.
	//      tree->close();
	//  }
	//  if(treeNt) {
	//    G4cout<<" Now writing ntuples out "<<G4endl;
	//      treeNt->commit();         // Write  tuple in file.
	//      treeNt->close();
	//
	//  }

	if (fRootFile) {
		fRootFile->Write();       // Writing the histograms to the file
		fRootFile->Close();        // and closing the tree (and the file)
		//	G4cout << "\n----> Histogram Tree is saved \n" << G4endl;

	}

}



void RichTbAnalysisManager::BeginOfEventAnalysis(const G4Event * /* evt */)
{

	//RichCollId is already defined in LHCbRichSimEventAction.cc
	// Hence its extraction is not repeated here.
	iTimer->Start();

}


void RichTbAnalysisManager::EndOfEventAnalysis(const G4Event * /* evt */)
{
	iTimer->Stop();



}


void RichTbAnalysisManager::StepAnalysis
(const G4SteppingManager * /* aSteppingManager */)
{

	// if(!aSteppingManager) return;
	//  G4Track* track = aSteppingManager->GetTrack();
	// G4ThreeVector pos = track->GetPosition();

}
void RichTbAnalysisManager::EndOfEventCountersHisto(const G4Event * /* evt */)
{
	// RichTbCounter* aRichCounter= RichTbCounter::getRichTbCounterInstance();

	//  G4cout<<" Filling histo of counters "<<G4endl;

	// G4int NRadiatorProduced= aRichCounter->getnumHitTotProd();
	// G4int NEnterMirror= aRichCounter->getnumPhEnterMirror();
	// G4int NEnterPhFrame = aRichCounter->getnumPhEnterPhSupFrame();
	// G4int NExitGasQuWin = aRichCounter->getnumExitGasQuWin();
	// G4int NEnterPMT0QW =  aRichCounter->getnumPhEnterPMT0QW();
	//  G4int NEnterPMT1QW =  aRichCounter->getnumPhEnterPMT1QW();
	// G4int NEnterPMT2QW =  aRichCounter->getnumPhEnterPMT2QW();
	// G4int NEnterPMT3QW =  aRichCounter->getnumPhEnterPMT3QW();
	//  G4int NEnterPMT4QW =  aRichCounter->getnumPhEnterPMT4QW();
	// G4int NEnterPMT5QW =  aRichCounter->getnumPhEnterPMT5QW();
	//  G4int NEnterAnPMTQW = aRichCounter->getnumPhEnterAnPMTQW();


	//  if( fhistoNProduced) fhistoNProduced->fill(1.0* NRadiatorProduced);
	//  if( fhistoNEnterMirror) fhistoNEnterMirror->fill(1.0* NEnterMirror);
	// if(fhistoNEnterPhSupframe) fhistoNEnterPhSupframe->fill(1.0* NEnterPhFrame);
	// if(fhistoNExitGasQuWin) fhistoNExitGasQuWin->fill(1.0*  NExitGasQuWin);
	// if(  fhistoNEnterPMT0QW)  fhistoNEnterPMT0QW->fill(1.0* NEnterPMT0QW);
	// if(  fhistoNEnterPMT1QW)  fhistoNEnterPMT1QW->fill(1.0* NEnterPMT1QW);
	// if(  fhistoNEnterPMT2QW)  fhistoNEnterPMT2QW->fill(1.0* NEnterPMT2QW);
	// if(  fhistoNEnterPMT3QW)  fhistoNEnterPMT3QW->fill(1.0* NEnterPMT3QW);
	// if(  fhistoNEnterPMT4QW)  fhistoNEnterPMT4QW->fill(1.0* NEnterPMT4QW);
	// if(  fhistoNEnterPMT5QW)  fhistoNEnterPMT5QW->fill(1.0* NEnterPMT5QW);
	// if( fhistoNEnterAnPMTQW) fhistoNEnterAnPMTQW->fill(1.0*  NEnterAnPMTQW);
	//  G4cout<<"end of  Filling histo of counters "<<G4endl;

}


void RichTbAnalysisManager::EndOfEventHisto(const G4Event * evt)
{

	RichTbRunConfig* rConfig = RichTbRunConfig::getRunConfigInstance();
	G4int aRadiatorConfiguration = rConfig ->getRadiatorConfiguration();


	RichTbCounter* aRichCounter= RichTbCounter::getRichTbCounterInstance();

	G4SDManager * SDman = G4SDManager::GetSDMpointer();
	G4String colNam= RichTbHColname;
	G4int RichTbCollID = SDman->GetCollectionID(colNam);
	G4int aVerboseFlag =  rConfig-> VerboseInfoFlag() ;


	G4HCofThisEvent * HCE = evt->GetHCofThisEvent();
	RichTbHitsCollection* RHC = NULL;
	if(HCE)
	{
		RHC = (RichTbHitsCollection*)(HCE->GetHC(RichTbCollID));
	}

	if(RHC)
	{
		G4int n_hit = RHC->entries();
		//G4cout<<"now in the bumpnumhit loop "<<G4endl;

		for(G4int ih=0; ih<n_hit; ih++) {
			RichTbHit* aHit = (*RHC)[ih];

			// Now for printing
			if( aVerboseFlag >=5 ) {
				aHit->Print();
			}

			G4int curPMTNum =  aHit->GetCurPMTNum() ;
			G4ThreeVector curHitCoord=  aHit-> GetPos();
			G4int curHitInGapFlag = aHit-> getHitInPixelGapFlag() ;

			//   G4cout<<"Hit PMT Number: "<<curPMTNum<<", coordinate: "<<curHitCoord<<G4endl;

			//G4cout<<" Gap flag :  "<<curHitInGapFlag<<G4endl;

			if(curHitInGapFlag == 0 ) {

				aRichCounter->bumpnumhitTotEv();
				if( curPMTNum == 0 ) aRichCounter->bumpnumhitPMT0();
				if( curPMTNum == 1 ) aRichCounter->bumpnumhitPMT1();
				if( curPMTNum == 2 ) aRichCounter->bumpnumhitPMT2();
				if( curPMTNum == 3 ) aRichCounter->bumpnumhitPMT3();
				if( curPMTNum == 4 ) aRichCounter->bumpnumhitPMT4();
				if( curPMTNum == 5 ) aRichCounter->bumpnumhitPMT5();
				if( curPMTNum == 6 ) aRichCounter->bumpnumhitPMT6();
				if( curPMTNum == 7 ) aRichCounter->bumpnumhitPMT7();
				if( curPMTNum == 8 ) aRichCounter->bumpnumhitPMT8();
				if( curPMTNum == 9 ) aRichCounter->bumpnumhitPMT9();
				if( curPMTNum == 10 ) aRichCounter->bumpnumhitPMT10();
				if( curPMTNum == 11 ) aRichCounter->bumpnumhitPMT11();
				if( curPMTNum == 12 ) aRichCounter->bumpnumhitPMT12();
				if( curPMTNum == 13 ) aRichCounter->bumpnumhitPMT13();
				if( curPMTNum == 14 ) aRichCounter->bumpnumhitPMT14();
				if( curPMTNum == 15 ) aRichCounter->bumpnumhitPMT15();
				if(  ( curPMTNum == 0 ) || ( curPMTNum == 2 ) ||
						( curPMTNum == 5 ) || ( curPMTNum == 7 ) ||
						( curPMTNum == 8 ) || ( curPMTNum == 10 ) ||
						( curPMTNum == 13 ) || ( curPMTNum == 15 )) aRichCounter->bumpnumhitTotEvCentralPmt();

				if(  ( curPMTNum == 0 ) || ( curPMTNum == 2 ) ||
						(curPMTNum == 8) || ( curPMTNum == 10 )) aRichCounter->bumpnumhitTotEvCentralPmtJura();

				if(  ( curPMTNum == 5 ) || ( curPMTNum == 7 ) ||
						(curPMTNum == 13) || ( curPMTNum == 15 )) aRichCounter->bumpnumhitTotEvCentralPmtSaleve();


				// if(  fHistoCkvTruePhiHits)
					//  fHistoCkvTruePhiHits->fill( aHit->GetCkvPhiProd());

				// now fill the pixel  col row in a histogram.

				//  G4int aPixelNum = aHit-> GetCurPixNum();
				// G4int aPixelRow = aPixelNum/RichTbPMTSiDetNumPixelAlongX;
				// G4int aPixelCol = aPixelNum- aPixelRow*RichTbPMTSiDetNumPixelAlongX;

				// if(   (curPMTNum == 0)  && (fHistoPixelColRowPMT0) )
				//  fHistoPixelColRowPMT0->fill(1.0*aPixelCol,1.0* aPixelRow);
				//  if(   (curPMTNum == 1)  && (fHistoPixelColRowPMT1) )
				//  fHistoPixelColRowPMT1->fill(1.0*aPixelCol,1.0* aPixelRow);
				// if(   (curPMTNum == 2)  && (fHistoPixelColRowPMT2) )
				//  fHistoPixelColRowPMT2->fill(1.0*aPixelCol,1.0*aPixelRow);
				// if(   (curPMTNum == 3)  && (fHistoPixelColRowPMT3) )
				//  fHistoPixelColRowPMT3->fill(1.0*aPixelCol,1.0*aPixelRow);
				// if(   (curPMTNum == 4)  && (fHistoPixelColRowPMT4) )
				//  fHistoPixelColRowPMT4->fill(1.0*aPixelCol,1.0*aPixelRow);
				//  if(   (curPMTNum == 5)  && (fHistoPixelColRowPMT5) )
				//  fHistoPixelColRowPMT5->fill(1.0*aPixelCol,1.0*aPixelRow);

				G4ThreeVector aPeOrigin = aHit->GetPeOrigin();
				G4ThreeVector aGlobalXYHitC = aHit->GetPos();
				G4ThreeVector aPixelCenterC =  aHit->getPixelGlobalCenter() ;


				if(fGlobalHitXYCoord15) fGlobalHitXYCoord15->Fill(aGlobalXYHitC.x(),aGlobalXYHitC.y());

				//G4cout<<"hit in pmt : "<<curPMTNum<<" in pixel : "<<G4endl;

				G4double pmtRad = sqrt(pow(aGlobalXYHitC.x(),2) + pow(aGlobalXYHitC.y(),2));
				if(curPMTNum == 0) radiusInPMT0->Fill(pmtRad);
				if(curPMTNum == 1) radiusInPMT1->Fill(pmtRad);
				if(curPMTNum == 2) radiusInPMT2->Fill(pmtRad);
				if(curPMTNum == 3) radiusInPMT3->Fill(pmtRad);
				if(curPMTNum == 4) radiusInPMT4->Fill(pmtRad);
				if(curPMTNum == 5) radiusInPMT5->Fill(pmtRad);
				if(curPMTNum == 6) radiusInPMT6->Fill(pmtRad);
				if(curPMTNum == 7) radiusInPMT7->Fill(pmtRad);
				if(curPMTNum == 8) radiusInPMT8->Fill(pmtRad);
				if(curPMTNum == 9) radiusInPMT9->Fill(pmtRad);
				if(curPMTNum == 10) radiusInPMT10->Fill(pmtRad);
				if(curPMTNum == 11) radiusInPMT11->Fill(pmtRad);
				if(curPMTNum == 12) radiusInPMT12->Fill(pmtRad);
				if(curPMTNum == 13) radiusInPMT13->Fill(pmtRad);
				if(curPMTNum == 14) radiusInPMT14->Fill(pmtRad);
				if(curPMTNum == 15) radiusInPMT15->Fill(pmtRad);

//				G4cout<<pmtRad<<G4endl;

				if( fGlobalHitXYCoordPeOrigin) fGlobalHitXYCoordPeOrigin->Fill( aPeOrigin.x(),aPeOrigin.y());
				if(fGlobalHitXYCoord) fGlobalHitXYCoord->Fill(aGlobalXYHitC.x(),aGlobalXYHitC.y());
				if(fGlobalPixelCenterXYCoord)fGlobalPixelCenterXYCoord ->Fill(aPixelCenterC.x(), aPixelCenterC.y());
				if(curPMTNum == 0 || curPMTNum == 2 ) {
					if(fGlobalHitXYCoordPeOriginHpdPmt)  fGlobalHitXYCoordPeOriginHpdPmt->Fill(aPeOrigin.x(),aPeOrigin.y() );
				}
			}
		}


		G4int numTotHitInEv =  aRichCounter->getnumhitTotEv();
		G4int numTotHitInEvCentralPmt = aRichCounter->getnumhitTotEvCentralPmt();
		G4int numTotHitInEvCentralPmtJura = aRichCounter->getnumhitTotEvCentralPmtJura();
		G4int numTotHitInEvCentralPmtSaleve = aRichCounter->getnumhitTotEvCentralPmtSaleve();

		G4int numTotHitInPMT0=   aRichCounter->getnumhitPMT0();
		G4int numTotHitInPMT1=   aRichCounter->getnumhitPMT1();
		G4int numTotHitInPMT2=   aRichCounter->getnumhitPMT2();
		G4int numTotHitInPMT3=   aRichCounter->getnumhitPMT3();
		G4int numTotHitInPMT4=   aRichCounter->getnumhitPMT4();
		G4int numTotHitInPMT5=   aRichCounter->getnumhitPMT5();
		G4int numTotHitInPMT6=   aRichCounter->getnumhitPMT6();
		G4int numTotHitInPMT7=   aRichCounter->getnumhitPMT7();
		G4int numTotHitInPMT8=   aRichCounter->getnumhitPMT8();
		G4int numTotHitInPMT9=   aRichCounter->getnumhitPMT9();
		G4int numTotHitInPMT10=   aRichCounter->getnumhitPMT10();
		G4int numTotHitInPMT11=   aRichCounter->getnumhitPMT11();
		G4int numTotHitInPMT12=   aRichCounter->getnumhitPMT12();
		G4int numTotHitInPMT13=   aRichCounter->getnumhitPMT13();
		G4int numTotHitInPMT14=   aRichCounter->getnumhitPMT14();
		G4int numTotHitInPMT15=   aRichCounter->getnumhitPMT15();

		//  G4cout<<" Number of hits in this event "<<n_hit<<G4endl;

		/*
      G4cout<<"NumHits Tot pmt01234567 "<<
      numTotHitInEv <<"  "<<(numTotHitInEvCentralPmt<<"  "<< numTotHitInPMT0<<"  "
          <<  numTotHitInPMT1<<"   "<< numTotHitInPMT2<<"   "
          << numTotHitInPMT3<<"   "<< numTotHitInPMT4<<"   "
          <<  numTotHitInPMT5<<"   "<< numTotHitInPMT6<<"  "<<  numTotHitInPMT7<<  G4endl;

		 */
	 // G4cout<<" Now we're writing"<<G4endl;
		if(fNumHitInEvent) fNumHitInEvent ->Fill( numTotHitInEv*1.0);
		if(fNumHitInEventSmall) fNumHitInEventSmall ->Fill( numTotHitInEv*1.0);
		if(fNumHitInEventCentralPMT) fNumHitInEventCentralPMT->Fill(numTotHitInEvCentralPmt*1.0);

		if(fNumHitInPMT0)fNumHitInPMT0->Fill(numTotHitInPMT0*1.0);
		if(fNumHitInPMT1)fNumHitInPMT1->Fill(numTotHitInPMT1*1.0);
		if(fNumHitInPMT2)fNumHitInPMT2->Fill(numTotHitInPMT2*1.0);
		if(fNumHitInPMT3)fNumHitInPMT3->Fill(numTotHitInPMT3*1.0);
		if(fNumHitInPMT4)fNumHitInPMT4->Fill(numTotHitInPMT4*1.0);
		if(fNumHitInPMT5)fNumHitInPMT5->Fill(numTotHitInPMT5*1.0);
		if(fNumHitInPMT6)fNumHitInPMT6->Fill(numTotHitInPMT6*1.0);
		if(fNumHitInPMT7)fNumHitInPMT7->Fill(numTotHitInPMT7*1.0);
		if(fNumHitInPMT8)fNumHitInPMT8->Fill(numTotHitInPMT8*1.0);
		if(fNumHitInPMT9)fNumHitInPMT9->Fill(numTotHitInPMT9*1.0);
		if(fNumHitInPMT10)fNumHitInPMT10->Fill(numTotHitInPMT10*1.0);
		if(fNumHitInPMT11)fNumHitInPMT11->Fill(numTotHitInPMT11*1.0);
		if(fNumHitInPMT12)fNumHitInPMT12->Fill(numTotHitInPMT12*1.0);
		if(fNumHitInPMT13)fNumHitInPMT13->Fill(numTotHitInPMT13*1.0);
		if(fNumHitInPMT14)fNumHitInPMT14->Fill(numTotHitInPMT14*1.0);
		if(fNumHitInPMT15)fNumHitInPMT15->Fill(numTotHitInPMT15*1.0);


		if(fNumHitInEventCentralPMTJura) fNumHitInEventCentralPMTJura->Fill ( numTotHitInEvCentralPmtJura );
		if(fNumHitInEventCentralPMTSaleve) fNumHitInEventCentralPMTSaleve->Fill ( numTotHitInEvCentralPmtSaleve );



		//    if(fhistoNrPhotAll) {
			//      G4cout<<"Now filling histoNrPhotAll"<<G4endl;

		//   fhistoNrPhotAll->fill(1.0*numTotHitInEv);

		// G4cout<<"Test print histo mean rms  "<<
		//  fhistoNrPhotAll->mean()<<"  "<<fhistoNrPhotAll->rms()<<G4endl;

		//  }else {
		//  G4cout<<" histoNrPhotAll Not available for filling"<<G4endl;

		//  }


		//  if(fhistoNrPhotPMT0) {
		//  fhistoNrPhotPMT0->fill(1.0*numTotHitInPMT0);
		//  }else {

		//  G4cout<<" histoNrPhotPMT0 Not available for filling"<<G4endl;
		//  }


		// if(fhistoNrPhotPMT1) fhistoNrPhotPMT1->fill(1.0*numTotHitInPMT1);
		// if(fhistoNrPhotPMT2) fhistoNrPhotPMT2->fill(1.0*numTotHitInPMT2);
		// if(fhistoNrPhotPMT3) fhistoNrPhotPMT3->fill(1.0*numTotHitInPMT3);
		// if(fhistoNrPhotPMT4) fhistoNrPhotPMT4->fill(1.0*numTotHitInPMT4);
		// if(fhistoNrPhotPMT5) fhistoNrPhotPMT5->fill(1.0*numTotHitInPMT5);




	}

	// test histo and ntuple

	G4double aRNum1=  G4RandGauss::shoot(50.0,10.0);

	G4double aRNum2 = G4RandGauss::shoot(1.0,0.2);

	G4double aRNum3  =  G4UniformRand() ;
	if(fHisto[0] )fHisto[0] ->Fill( aRNum1 );

	fNtupVar1 = aRNum2;
	fNtupVar2 = aRNum3;
	if (fNtuple1) fNtuple1->Fill();

	// end test histo and ntuple

	// now for the hpd

	if( aRadiatorConfiguration == 2 ) {
		EndOfEventHistoHpd(evt);
	}



}

void RichTbAnalysisManager::EndOfEventHistoHpd(const G4Event * evt) {
	//RichTbRunConfig* rConfig = RichTbRunConfig::getRunConfigInstance();
  //	G4int aRadiatorConfiguration = rConfig ->getRadiatorConfiguration();
	RichTbCounter* aRichCounter= RichTbCounter::getRichTbCounterInstance();

	G4SDManager * SDman = G4SDManager::GetSDMpointer();
	G4String colNam=RichTbHColnameHpd;
	G4int RichTbCollID = SDman->GetCollectionID(colNam);
	//G4int aVerboseFlag =  rConfig-> VerboseInfoFlag() ;


	G4HCofThisEvent * HCE = evt->GetHCofThisEvent();
	RichTbHitsCollection* RHC = NULL;
	if(HCE)
	{
		RHC = (RichTbHitsCollection*)(HCE->GetHC(RichTbCollID));
	}

	if(RHC)
	{
		G4int n_hit = RHC->entries();


		for(G4int ih=0; ih<n_hit; ih++) {
			RichTbHit* aHit = (*RHC)[ih];

			//G4int curHPDNum =  aHit->GetCurHPDNum() ;
			G4ThreeVector curHitCoord=  aHit-> GetPos();

			G4ThreeVector aPeOrigin = aHit-> GetPeOrigin();
			G4ThreeVector aPixelCenterC =  aHit->getPixelGlobalCenter() ;
			G4double aRefIndexHit = (aHit-> GetCkvCosThetaProd()) != 0.0 ? 1.0/(aHit-> GetCkvCosThetaProd()) : 1.0;
			G4double aWavelenHit =  ( aHit->GetCkvEnergyProd()) != 0.0 ?
					1243.125 /((aHit->GetCkvEnergyProd())*1000000) : 0.0;
			G4ThreeVector aLocalPixelCenterC = aHit->getPixelLocalCenter();
			G4double ax=aLocalPixelCenterC.x();
			G4double ay=aLocalPixelCenterC.y();
			G4double aDX = ax*( (1.0 /PixelPMTDemagLinearFactor)  -1.0);
			G4double aDY = ay*( (1.0 /PixelPMTDemagLinearFactor)   - 1.0);
			G4double rdsq = -sqrt(ax*ax + ay*ay )/PixelPMTDemagLinearFactor;
			G4double rPh = RichTbHpdPhCathodeInnerRad;

			G4double aDZ = -RichTbHpdSiDetDistZFromPhCathode + rPh * (1- sqrt(1-(rdsq)/(rPh*rPh)));
			G4ThreeVector aGlobalPixelCenterPhcath = aPixelCenterC + G4ThreeVector(aDX,aDY,aDZ) ;


			// G4cout <<" hpd hits  ih  refindex energy wavelen "<< ih
					//       <<"  "<<aRefIndexHit <<"   "<< aHit->GetCkvEnergyProd()<<"  "<<aWavelenHit<<G4endl;
			//	G4cout <<" hpd hits  ih  refindex energy wavelen "<< ih
					//       <<"  "<<aRefIndexHit <<"   "<< aHit->GetCkvEnergyProd()<<"  "<<aWavelenHit<<G4endl;



			aRichCounter->bumpnumHitTotHpd0();
			//  G4cout<<" a Peorigin X Y "<<ih <<"  "<<aPeOrigin.x() << "  "<< aPeOrigin.y()<<G4endl;
			if( aPeOrigin.x() < -0.1 ) {  // avoid unphysical ccord.

				if(aPeOrigin.x() > -80.0 &&  aPeOrigin.x() < -55.0) {

					aRichCounter->bumpnumHitSignalHpd0();

				}

				if(fGlobalHitXYCoordPeOriginHpd)fGlobalHitXYCoordPeOriginHpd ->Fill(aPeOrigin.x(),aPeOrigin.y());
				if(fGlobalHitXYCoordHpd) fGlobalHitXYCoordHpd ->Fill(curHitCoord.x(), curHitCoord.y());
				if(fGlobalPixelCenterXYCoordHpd) fGlobalPixelCenterXYCoordHpd -> Fill(aPixelCenterC.x(), aPixelCenterC.y());
				if(fGlobalHitXYCoordPeOriginHpdPmt)  fGlobalHitXYCoordPeOriginHpdPmt->Fill(aPeOrigin.x(),aPeOrigin.y());
				if(fRadiatorRefIndexHits) fRadiatorRefIndexHits ->Fill(aWavelenHit, (aRefIndexHit-1) );
				if( fGlobalHitXYCoordPixPhcathHpd)
					fGlobalHitXYCoordPixPhcathHpd->Fill(aGlobalPixelCenterPhcath.x(),aGlobalPixelCenterPhcath.y());

			}

		}
	}

	G4int numTotHitInHpd0 =  aRichCounter->getnumHitTotHpd0();

	G4int  numTotSignalInHpd0 =  aRichCounter->getnumHitSignalHpd0();
	// G4cout <<" Num hit signal hpd0 "<< numTotHitInHpd0<<"   "<<numTotSignalInHpd0<<G4endl;

	if(fNumHitInHPD0) fNumHitInHPD0 ->Fill( numTotHitInHpd0 * 1.0);
	if(fNumHitSignalInHPD0) fNumHitSignalInHPD0 ->Fill( numTotSignalInHpd0 * 1.0);


}





