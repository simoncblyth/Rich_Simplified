#include "RichTbLHCbUtil.hh"
#include "RichTbLHCbPmtGeometryParameters.hh"
#include "RichTbLHCbECModuleGeometryParameters.hh"
#include "RichTbLHCbPmtArrayGeometryParameters.hh"
using namespace std;
//==============================================
//Utility class for RichTbLHCb                 //
// Created SE 2021-08-05                       // 
//==============================================

RichTbLHCbUtil * RichTbLHCbUtil::RichTbLHCbUtilInstance=0;

RichTbLHCbUtil::RichTbLHCbUtil() {; }
G4int RichTbLHCbUtil::getModuleNumFromPmtNum(int aP ) {

  return ((G4int) aP / RichTbLbNumPmtInModule );     

}
//==============================================
G4int RichTbLHCbUtil::getPmtNumInModuleFromPmtNum(int aP ) { 
  return ( (G4int)  aP % RichTbLbNumPmtInModule ); 
}
//==============================================
RichTbLHCbUtil::~RichTbLHCbUtil() {; }
RichTbLHCbUtil* RichTbLHCbUtil::getRichTbLHCbUtilInstance() {
  if(RichTbLHCbUtilInstance  == 0 ) {
    RichTbLHCbUtilInstance = new RichTbLHCbUtil() ;
  }
  return RichTbLHCbUtilInstance;

}
