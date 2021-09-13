// $Id: $
#ifndef INCLUDE_RICHTBCOUNTER_HH
#define INCLUDE_RICHTBCOUNTER_HH 1

// Include files
#include "globals.hh"

/** @class RichTbCounter RichTbCounter.hh include/RichTbCounter.hh
 *
 *
 *  @author Sajan EASO
 *  @date   2004-01-12
 */
class RichTbCounter {
public:
  static RichTbCounter* getRichTbCounterInstance();

  void bumpnumHitTotProd() {
    numHitTotProd ++;}
  void bumpnumhitTotEv()
  {    numhitTotEv++;  }
  void bumpnumhitTotEvCentralPmt()
  { numhitTotEvCentralPmt++;}
  void bumpnumhitTotEvCentralPmtJura()
  { numhitTotEvCentralPmtJura++;}
  void bumpnumhitTotEvCentralPmtSaleve()
  { numhitTotEvCentralPmtSaleve++;}


  void bumpnumhitPMT0()
  {    numhitPMT0++;  }
  void bumpnumhitPMT1()
  {    numhitPMT1++;  }
  void bumpnumhitPMT2()
  {    numhitPMT2++;  }
  void bumpnumhitPMT3()
  {    numhitPMT3++;  }
  void bumpnumhitPMT4()
  {    numhitPMT4++;  }
  void bumpnumhitPMT5()
  {    numhitPMT5++;  }
  void bumpnumhitPMT6()
  {    numhitPMT6++;  }
  void bumpnumhitPMT7()
  {    numhitPMT7++;  }
  void bumpnumhitPMT8()
  {    numhitPMT8++;  }
  void bumpnumhitPMT9()
  {    numhitPMT9++;  }
  void bumpnumhitPMT10()
  {    numhitPMT10++;  }
  void bumpnumhitPMT11()
  {    numhitPMT11++;  }
  void bumpnumhitPMT12()
  {    numhitPMT12++;  }
  void bumpnumhitPMT13()
  {    numhitPMT13++;  }
  void bumpnumhitPMT14()
  {    numhitPMT14++;  }
  void bumpnumhitPMT15()
  {    numhitPMT15++;  }



  void bumpnumPhEnterMirror()
  {    numPhEnterMirror++;}
  void bumpnumPhEnterPhSupFrame()
  {    numPhEnterPhSupFrame++;}
  void bumpnumExitGasQuWin() { numExitGasQuWin++;}
  void bumpnumPhElecPMT0()
  {    numPhElecPMT0++;}
  void bumpnumPhElecPMT1()
  {    numPhElecPMT1++;}
  void bumpnumPhElecPMT2()
  {    numPhElecPMT2++;}
  void bumpnumPhElecPMT3()
  {    numPhElecPMT3++;}
  void bumpnumPhElecPMT4()
  {    numPhElecPMT4++;}
  void bumpnumPhElecPMT5()
  {    numPhElecPMT5++;}
  void bumpnumPhElecPMT6()
  {    numPhElecPMT6++;}
  void bumpnumPhElecPMT7()
  {    numPhElecPMT7++;}
  void bumpnumPhElecPMT8()
  {    numPhElecPMT8++;}
  void bumpnumPhElecPMT9()
  {    numPhElecPMT9++;}
  void bumpnumPhElecPMT10()
  {    numPhElecPMT10++;}
  void bumpnumPhElecPMT11()
  {    numPhElecPMT11++;}
  void bumpnumPhElecPMT12()
  {    numPhElecPMT12++;}
  void bumpnumPhElecPMT13()
  {    numPhElecPMT13++;}
  void bumpnumPhElecPMT14()
  {    numPhElecPMT14++;}
  void bumpnumPhElecPMT15()
  {    numPhElecPMT15++;}
  void bumpnumPhEnterPMT0QW()
  {numPhEnterPMT0QW++;}
  void bumpnumPhEnterPMT1QW()
  {numPhEnterPMT1QW++;}
  void bumpnumPhEnterPMT2QW()
  {numPhEnterPMT2QW++;}
  void bumpnumPhEnterPMT3QW()
  {numPhEnterPMT3QW++;}
  void bumpnumPhEnterPMT4QW()
  {numPhEnterPMT4QW++;}
  void bumpnumPhEnterPMT5QW()
  {numPhEnterPMT5QW++;}
  void bumpnumPhEnterPMT6QW()
  {numPhEnterPMT6QW++;}
  void bumpnumPhEnterPMT7QW()
  {numPhEnterPMT7QW++;}
  void bumpnumPhEnterPMT8QW()
  {numPhEnterPMT8QW++;}
  void bumpnumPhEnterPMT9QW()
  {numPhEnterPMT9QW++;}
  void bumpnumPhEnterPMT10QW()
  {numPhEnterPMT10QW++;}
  void bumpnumPhEnterPMT11QW()
  {numPhEnterPMT11QW++;}
  void bumpnumPhEnterPMT12QW()
  {numPhEnterPMT12QW++;}
  void bumpnumPhEnterPMT13QW()
  {numPhEnterPMT13QW++;}
  void bumpnumPhEnterPMT14QW()
  {numPhEnterPMT14QW++;}
  void bumpnumPhEnterPMT15QW()
  {numPhEnterPMT15QW++;}
  void bumpnumPhEnterAnPMTQW()
  {  numPhEnterAnPMTQW++; }

  void bumpnumHitTotHpd0()
  { numHitTotHpd0++; }

  void bumpnumHitSignalHpd0(){numHitSignalHpd0++;}



  void resetRichTbCounter();
  G4int getnumHitTotProd() {return numHitTotProd;}
  G4int getnumhitTotEv()
  {  return numhitTotEv; }

  G4int getnumhitTotEvCentralPmt()
  {  return numhitTotEvCentralPmt;}

  G4int getnumhitTotEvCentralPmtJura()
  {  return numhitTotEvCentralPmtJura;}
  G4int getnumhitTotEvCentralPmtSaleve()
  {  return numhitTotEvCentralPmtSaleve;}

  G4int getnumhitPMT0()
  { return numhitPMT0;}
  G4int getnumhitPMT1()
  { return numhitPMT1;}
  G4int getnumhitPMT2()
  { return numhitPMT2;}
  G4int getnumhitPMT3()
  { return numhitPMT3;}
  G4int getnumhitPMT4()
  { return numhitPMT4;}
  G4int getnumhitPMT5()
  { return numhitPMT5;}
  G4int getnumhitPMT6()
  { return numhitPMT6;}
  G4int getnumhitPMT7()
  { return numhitPMT7;}
  G4int getnumhitPMT8()
  { return numhitPMT8;}
  G4int getnumhitPMT9()
  { return numhitPMT9;}
  G4int getnumhitPMT10()
  { return numhitPMT10;}
  G4int getnumhitPMT11()
  { return numhitPMT11;}
  G4int getnumhitPMT12()
  { return numhitPMT12;}
  G4int getnumhitPMT13()
  { return numhitPMT13;}
  G4int getnumhitPMT14()
  { return numhitPMT14;}
  G4int getnumhitPMT15()
  { return numhitPMT15;}
  G4int getnumPhEnterMirror()
  {    return numPhEnterMirror;}
  G4int getnumPhEnterPhSupFrame()
  {    return numPhEnterPhSupFrame;}
  G4int getnumExitGasQuWin() {return numExitGasQuWin;}

  G4int getnumPhElecPMT0()
  {    return  numPhElecPMT0;}
  G4int getnumPhElecPMT1()
  {    return  numPhElecPMT1;}
  G4int getnumPhElecPMT2()
  {    return  numPhElecPMT2;}
  G4int getnumPhElecPMT3()
  {    return  numPhElecPMT3;}
  G4int getnumPhElecPMT4()
  {    return  numPhElecPMT4;}
  G4int getnumPhElecPMT5()
  {    return  numPhElecPMT5;}
  G4int getnumPhElecPMT6()
  {    return  numPhElecPMT6;}
  G4int getnumPhElecPMT7()
  {    return  numPhElecPMT7;}
  G4int getnumPhElecPMT8()
  {    return  numPhElecPMT8;}
  G4int getnumPhElecPMT9()
  {    return  numPhElecPMT9;}
  G4int getnumPhElecPMT10()
  {    return  numPhElecPMT10;}
  G4int getnumPhElecPMT11()
  {    return  numPhElecPMT11;}
  G4int getnumPhElecPMT12()
  {    return  numPhElecPMT12;}
  G4int getnumPhElecPMT13()
  {    return  numPhElecPMT13;}
  G4int getnumPhElecPMT14()
  {    return  numPhElecPMT14;}
  G4int getnumPhElecPMT15()
  {    return  numPhElecPMT15;}



  G4int getnumPhEnterPMT0QW()
  {  return  numPhEnterPMT0QW;}
  G4int getnumPhEnterPMT1QW()
  {  return  numPhEnterPMT1QW;}
  G4int getnumPhEnterPMT2QW()
  {  return  numPhEnterPMT2QW;}
  G4int getnumPhEnterPMT3QW()
  {  return  numPhEnterPMT3QW;}
  G4int getnumPhEnterPMT4QW()
  {  return  numPhEnterPMT4QW;}
  G4int getnumPhEnterPMT5QW()
  {  return  numPhEnterPMT5QW;}
  G4int getnumPhEnterPMT6QW()
  {  return  numPhEnterPMT6QW;}
  G4int getnumPhEnterPMT7QW()
  {  return  numPhEnterPMT7QW;}
  G4int getnumPhEnterPMT8QW()
  {  return  numPhEnterPMT8QW;}
  G4int getnumPhEnterPMT9QW()
  {  return  numPhEnterPMT9QW;}
  G4int getnumPhEnterPMT10QW()
  {  return  numPhEnterPMT10QW;}
  G4int getnumPhEnterPMT11QW()
  {  return  numPhEnterPMT11QW;}
  G4int getnumPhEnterPMT12QW()
  {  return  numPhEnterPMT12QW;}
  G4int getnumPhEnterPMT13QW()
  {  return  numPhEnterPMT13QW;}
  G4int getnumPhEnterPMT14QW()
  {  return  numPhEnterPMT14QW;}
  G4int getnumPhEnterPMT15QW()
  {  return  numPhEnterPMT15QW;}


  G4int getnumPhEnterAnPMTQW()
  {    return numPhEnterAnPMTQW;}

  G4int getnumHitTotHpd0()  {  return numHitTotHpd0;}
  G4int  getnumHitSignalHpd0() {  return numHitSignalHpd0;}


  virtual ~RichTbCounter( ); ///< Destructor

protected:

private:

  /// Standard constructor
  RichTbCounter( );
  static  RichTbCounter*  RichTbCounterInstance;

  G4int numHitTotProd;
  G4int numhitTotEv;
  G4int numhitTotEvCentralPmt;
  G4int numhitTotEvCentralPmtJura;
  G4int numhitTotEvCentralPmtSaleve;


  G4int numhitPMT0;
  G4int numhitPMT1;
  G4int numhitPMT2;
  G4int numhitPMT3;
  G4int numhitPMT4;
  G4int numhitPMT5;
  G4int numhitPMT6;
  G4int numhitPMT7;
  G4int numhitPMT8;
  G4int numhitPMT9;
  G4int numhitPMT10;
  G4int numhitPMT11;
  G4int numhitPMT12;
  G4int numhitPMT13;
  G4int numhitPMT14;
  G4int numhitPMT15;

  G4int numPhEnterMirror;
  G4int numPhEnterPhSupFrame;
  G4int numExitGasQuWin;
  G4int numPhEnterPMT0QW;
  G4int numPhEnterPMT1QW;
  G4int numPhEnterPMT2QW;
  G4int numPhEnterPMT3QW;
  G4int numPhEnterPMT4QW;
  G4int numPhEnterPMT5QW;
  G4int numPhEnterPMT6QW;
  G4int numPhEnterPMT7QW;
  G4int numPhEnterPMT8QW;
  G4int numPhEnterPMT9QW;
  G4int numPhEnterPMT10QW;
  G4int numPhEnterPMT11QW;
  G4int numPhEnterPMT12QW;
  G4int numPhEnterPMT13QW;
  G4int numPhEnterPMT14QW;
  G4int numPhEnterPMT15QW;
  G4int numPhEnterAnPMTQW;
  G4int numPhElecPMT0;
  G4int numPhElecPMT1;
  G4int numPhElecPMT2;
  G4int numPhElecPMT3;
  G4int numPhElecPMT4;
  G4int numPhElecPMT5;
  G4int numPhElecPMT6;
  G4int numPhElecPMT7;
  G4int numPhElecPMT8;
  G4int numPhElecPMT9;
  G4int numPhElecPMT10;
  G4int numPhElecPMT11;
  G4int numPhElecPMT12;
  G4int numPhElecPMT13;
  G4int numPhElecPMT14;
  G4int numPhElecPMT15;



  G4int numHitTotHpd0;
  G4int numHitSignalHpd0;

};
#endif // INCLUDE_RICHTBCOUNTER_HH
