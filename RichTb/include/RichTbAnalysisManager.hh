#ifndef RichTbAnalysisManager_h
#define RichTbAnalysisManager_h 1


//#include "G4VAnalysisManager.hh"
#include "globals.hh"
//#include "g4std/vector"
//#include "g4std/fstream"
#include "G4ThreeVector.hh"
//#include "AIDA/AIDA.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TProfile.h"
//#ifdef G4ANALYSIS_USE_JAS
//#include "G4JasSystem.hh"
//#include "JasHistogram1D.h"
//#include "JasHistogram2D.h"
//#include "JasHistogramFactory.h"
//#endif

//#ifdef G4ANALYSIS_USE_LAB
//#include "G4LabSystem.hh"
//#endif

//#include <AIDA/AIDA.h>
//#include <AIDA/IAnalysisFactory.h>
//#include <AIDA/IHistogramFactory.h>
//#include <AIDA/ITupleFactory.h>
//#include <AIDA/ITuple.h>
//#include <AIDA/IHistogram1D.h>
//#include <AIDA/IHistogram2D.h>

//#ifdef G4ANALYSIS_USE_LIZARD//
//#include <IPlotter.h>
//#include <IVector.h>
//#include <IVectorFactory.h>
//#include "G4LizardSystem.hh"
//#endif

#include <vector>

class G4Run;
class G4Event;
class G4Step;
class G4Timer;
class G4SteppingManager;
class RichTbRunConfig;


 class TFile;
 class TTree;
// class TH1D;

  const G4int MaxHisto = 5;


//namespace AIDA {
  //class IAnalysisFactory;
//class IHistogramFactory;
//class ITree;
//class ITupleFactory;
//class ITuple;
//};



class RichTbAnalysisManager {
public:

  virtual ~RichTbAnalysisManager();

  void InitializeCounters();
  void BookHisto();
  void BookHistoHpd();

  void BeginOfRunAnalysis();
  void EndOfRunAnalysis();
  void BeginOfEventAnalysis(const G4Event*);
  void EndOfEventAnalysis(const G4Event*);
  void StepAnalysis(const G4SteppingManager* );
  void EndOfEventHisto(const G4Event*);
  void EndOfEventHistoHpd(const G4Event*);

  void EndOfEventCountersHisto(const G4Event* );

  void  BookHistoPhCAnalysis();
  void  SetOutputHistoFile();


  static  RichTbAnalysisManager* getInstance();

  TH1D * getPhotonXCoord() {return fPhotonXCoord;}
  TH1D * getPhotonYCoord() {return fPhotonYCoord;}
  TH1D * getPhotonZCoord() {return fPhotonZCoord;}

  TH2D * getPhotonXYCoord() {return fPhotonXYCoord;}

  TH1D * getPhotonWidthProfile() {return fPhotonWidthProfile;}
  TProfile * getPhotonXYCoordProfile() {return fPhotonXYCoordProfile;}
  TProfile * getPhotonXYCoordProfileCut() {return fPhotonXYCoordProfileCut;}
  TH1D * getSpectrum() {return fSpectrum;}
  TH1D * getSpectrumPreMirror() {return fSpectrumPreMirror;}
  TH1D * getSpectrumPostMirror() {return fSpectrumPostMirror;}
  TH1D * getPhotonZAngle() {return fPhotonZAngle;}
  TH1D * getCherenkovAngle() {return fCherenkovAngle;}
  TH1D * getCherenkovAngleCut() {return fCherenkovAngleCut;}

  TH2D * getRadiusVsWL() {return fRadiusVsWL;}
  TProfile * getRadiusVsWLProfile() {return fRadiusVsWLProfile;}
  TH2D * getfGlobalPixelCenterXYCoord() {  return fGlobalPixelCenterXYCoord;}
  TProfile * getfCkvRadiusVsEmisPtPhoton() {  return  fCkvRadiusVsEmisPtPhoton;}
  TH1D * getfEmisPtPhoton()  {  return fEmisPtPhoton; }
  TH1D * getfEmisPtPrimaryTrackPhoton()  {  return fEmisPtPrimaryTrackPhoton; }


  TH2D * getfGlobalHitXYCoordPeOrigin()
  {  return fGlobalHitXYCoordPeOrigin;}
  TH2D * getfGlobalHitXYCoord()
  {  return fGlobalHitXYCoord ;}
  TH1D * getfNumHitInEvent()
  {  return fNumHitInEvent;  }

  TH1D * getfNumHitInEventSmall()
  {  return fNumHitInEventSmall;  }

  TH1D*  getfNumHitInEventCentralPMT()
  {  return fNumHitInEventCentralPMT;}

  TH1D*  getfNumHitInEventCentralPMTJura() {return    fNumHitInEventCentralPMTJura ;}
  TH1D*  getfNumHitInEventCentralPMTSaleve() {return    fNumHitInEventCentralPMTSaleve ;}


  TH1D * getfNumHitInPMT0()
  {   return fNumHitInPMT0; }
  TH1D * getfNumHitInPMT1()
  {   return fNumHitInPMT1; }
  TH1D * getfNumHitInPMT2()
  {   return fNumHitInPMT2; }
  TH1D * getfNumHitInPMT3()
  {   return fNumHitInPMT3; }
  TH1D * getfNumHitInPMT4()
  {   return fNumHitInPMT4; }
  TH1D * getfNumHitInPMT5()
  {   return fNumHitInPMT5; }
  TH1D * getfNumHitInPMT6()
  {   return fNumHitInPMT6; }
  TH1D * getfNumHitInPMT7()
  {   return fNumHitInPMT7; }
  TH1D * getfNumHitInPMT8()
  {   return fNumHitInPMT8; }
  TH1D * getfNumHitInPMT9()
  {   return fNumHitInPMT9; }
  TH1D * getfNumHitInPMT10()
  {   return fNumHitInPMT10; }
  TH1D * getfNumHitInPMT11()
  {   return fNumHitInPMT11; }
  TH1D * getfNumHitInPMT12()
  {   return fNumHitInPMT12; }
  TH1D * getfNumHitInPMT13()
  {   return fNumHitInPMT13; }
  TH1D * getfNumHitInPMT14()
  {   return fNumHitInPMT14; }
  TH1D * getfNumHitInPMT15()
  {   return fNumHitInPMT15; }
  TH1D * getfGeneratedCkvPhoton()
  {  return fGeneratedCkvPhoton;}

  TH2D * getfTIRXYLocationPhoton()
  {  return fTIRXYLocationPhoton;}
  TH2D* getfXYRadiatorDnsPhoton()
  {  return  fXYRadiatorDnsPhoton;}
  TH2D* getfXYRadiatorTIRDnsPhoton()
  {  return  fXYRadiatorTIRDnsPhoton;}

  TH2D* getfXYRadiatorRFRDnsPhoton()
  {  return fXYRadiatorRFRDnsPhoton;}

  TH2D* getfMIRXYLocationPhoton()
  {  return fMIRXYLocationPhoton;}

  TH2D*  getfRFRXYLocationPhoton()
  {  return fRFRXYLocationPhoton;}


  TH1D* getfNumHitInHPD0()  {  return fNumHitInHPD0; }

  TH2D* getfRFRXYLocationPhotonHpd() {return   fRFRXYLocationPhotonHpd; }

  TH2D* getfGlobalHitXYCoordPeOriginHpd() {return   fGlobalHitXYCoordPeOriginHpd; }

  TH2D* getfGlobalHitXYCoordHpd() {return   fGlobalHitXYCoordHpd; }

  TH2D* getfGlobalPixelCenterXYCoordHpd() {return   fGlobalPixelCenterXYCoordHpd ;}

  TH2D*  getfGlobalHitXYCoordPeOriginHpdPmt()  {  return fGlobalHitXYCoordPeOriginHpdPmt;}

  TH2D* getfRadiatorRefIndex()  {  return fRadiatorRefIndex;}
  TProfile * getfRadiatorRefIndexHits()  {  return fRadiatorRefIndexHits;}

  TH2D * getfGlobalHitXYCoordPixPhcathHpd() {return fGlobalHitXYCoordPixPhcathHpd;}

  TH1D* getfNumHitSignalInHPD0() {return fNumHitSignalInHPD0  ;}

  TH2D* getDetPlaneXYCoord()  {  return fDetPlaneXYCoord;}
  TH1D* getDetPlaneNumHits()  {  return fDetPlaneNumHits;}


private:
  //private constructor in order to create a singleton

  RichTbAnalysisManager ();

  static  RichTbAnalysisManager* RichTbAnalysisInstance;

  G4Timer* iTimer;

    TFile*   fRootFile;
    TH1D*    fHisto[MaxHisto];
    TTree*   fNtuple1;
    TH1D *   fPhotonZCoord;
    TH1D *   fPhotonYCoord;
    TH1D *   fPhotonXCoord;
    TH1D *   fSpectrum;
    TH1D *   fSpectrumPreMirror;
    TH1D *   fSpectrumPostMirror;

    TH2D * fRadiatorRefIndex;
    TProfile * fRadiatorRefIndexHits;

    TH2D *   fPhotonXYCoord;
    TH2D *   fPhotonXYCoord15;


    TH2D *   fRadiusVsWL;
    TProfile * fRadiusVsWLProfile;
    TH1D *   fPhotonWidthProfile;
    TProfile *   fPhotonXYCoordProfile;
    TProfile *   fPhotonXYCoordProfileCut;
    TH1D *   fPhotonZAngle;
    TH1D *   fCherenkovAngle;
    TH1D *   fCherenkovAngleCut;

  TH2D*  fGlobalHitXYCoordPeOrigin;
  TH2D*  fGlobalHitXYCoord;
  TH2D*  fGlobalHitXYCoord15;
  TH2D*  fGlobalPixelCenterXYCoord ;
  TH1D*  fNumHitInEvent;
  TH1D*  fNumHitInEventSmall;
  TH1D*  fNumHitInEventCentralPMT;
  TH1D*  fNumHitInEventCentralPMTJura ;
  TH1D*  fNumHitInEventCentralPMTSaleve;

  TH1D*  fNumHitInPMT0;
  TH1D*  fNumHitInPMT1;
  TH1D*  fNumHitInPMT2;
  TH1D*  fNumHitInPMT3;
  TH1D*  fNumHitInPMT4;
  TH1D*  fNumHitInPMT5;
  TH1D*  fNumHitInPMT6;
  TH1D*  fNumHitInPMT7;
  TH1D*  fNumHitInPMT8;
  TH1D*  fNumHitInPMT9;
  TH1D*  fNumHitInPMT10;
  TH1D*  fNumHitInPMT11;
  TH1D*  fNumHitInPMT12;
  TH1D*  fNumHitInPMT13;
  TH1D*  fNumHitInPMT14;
  TH1D*  fNumHitInPMT15;

  TH1D*  radiusInPMT0;
  TH1D*  radiusInPMT1;
  TH1D*  radiusInPMT2;
  TH1D*  radiusInPMT3;
  TH1D*  radiusInPMT4;
  TH1D*  radiusInPMT5;
  TH1D*  radiusInPMT6;
  TH1D*  radiusInPMT7;
  TH1D*  radiusInPMT8;
  TH1D*  radiusInPMT9;
  TH1D*  radiusInPMT10;
  TH1D*  radiusInPMT11;
  TH1D*  radiusInPMT12;
  TH1D*  radiusInPMT13;
  TH1D*  radiusInPMT14;
  TH1D*  radiusInPMT15;

  TProfile * fCkvRadiusVsEmisPtPhoton;
  TH1D* fEmisPtPhoton;
  TH1D* fEmisPtPrimaryTrackPhoton;

    G4double fNtupVar1;
    G4double fNtupVar2;

  TH1D*  fGeneratedCkvPhoton;

  TH2D* fTIRXYLocationPhoton;
  TH2D* fXYRadiatorDnsPhoton;
   TH2D* fXYRadiatorTIRDnsPhoton;
  TH2D* fXYRadiatorRFRDnsPhoton;

  TH2D* fMIRXYLocationPhoton;
  TH2D* fRFRXYLocationPhoton;



  TH1D* fNumHitInHPD0;
  TH1D* fNumHitSignalInHPD0 ;

  TH2D* fRFRXYLocationPhotonHpd;
  TH2D* fGlobalHitXYCoordPeOriginHpd;
  TH2D* fGlobalHitXYCoordHpd;
  TH2D* fGlobalPixelCenterXYCoordHpd ;

  TH2D*  fGlobalHitXYCoordPeOriginHpdPmt;

  TH2D * fGlobalHitXYCoordPixPhcathHpd;




  // for phC analysis

  TH2D* fDetPlaneXYCoord;
  TH1D* fDetPlaneNumHits;
  
  

};


#endif






