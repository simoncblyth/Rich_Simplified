// $Id: $
// Include files



// local
#include "RichTbCounter.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbCounter
//
// 2004-01-12 : Sajan EASO
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbCounter* RichTbCounter::RichTbCounterInstance = 0;

RichTbCounter::RichTbCounter(  ) {
  resetRichTbCounter();

}
//=============================================================================
// Destructor
//=============================================================================
RichTbCounter::~RichTbCounter() {}

//=============================================================================
RichTbCounter* RichTbCounter::getRichTbCounterInstance()
{
  if( RichTbCounterInstance == 0 ) {
    RichTbCounterInstance = new RichTbCounter(  );

  }
  return  RichTbCounterInstance;
}

void RichTbCounter::resetRichTbCounter()
{
  numHitTotProd=0;
  numhitTotEv=0;
  numhitTotEvCentralPmt=0;
  numhitTotEvCentralPmtJura=0;
  numhitTotEvCentralPmtSaleve=0;

  numhitPMT0=0;
  numhitPMT1=0;
  numhitPMT2=0;
  numhitPMT3=0;
  numhitPMT4=0;
  numhitPMT5=0;
  numhitPMT6=0;
  numhitPMT7=0;
  numhitPMT9=0;
  numhitPMT8=0;
  numhitPMT10=0;
  numhitPMT11=0;
  numhitPMT12=0;
  numhitPMT13=0;
  numhitPMT14=0;
  numhitPMT15=0;


  numPhEnterMirror=0;
  numPhEnterPhSupFrame=0;
  numPhEnterPMT0QW=0;
  numPhEnterPMT1QW=0;
  numPhEnterPMT2QW=0;
  numPhEnterPMT3QW=0;
  numPhEnterPMT4QW=0;
  numPhEnterPMT5QW=0;
  numPhEnterAnPMTQW=0;
  numPhElecPMT0=0;
  numPhElecPMT1=0;
  numPhElecPMT2=0;
  numPhElecPMT3=0;
  numPhElecPMT4=0;
  numPhElecPMT5=0;

  numHitTotHpd0=0;
  numHitSignalHpd0=0;


}
