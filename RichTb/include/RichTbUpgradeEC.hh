#ifndef INCLUDE_RICHTBUPGRADEEC_HH
#define INCLUDE_RICHTBUPGRADEEC_HH 1

// Include files
#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "RichTbUpgradePhDetSupFrame.hh"


/** @class RichTbUpgradeEC RichTbUpgradeEC.hh include/RichTbUpgradeEC.hh
 *
 *
 *  @author Sajan Easo
 *  @date   2014-10-23
 */
class RichTbUpgradeEC {
public:
  /// Standard constructor
  RichTbUpgradeEC( RichTbUpgradePhDetSupFrame * rTbPhotSupFrame  );

  virtual ~RichTbUpgradeEC( ); ///< Destructor
  void constructRichTbUpgradeEC();
  void constructRichTbUpgradeECSupport ();
  void constructRichTbUpgradeSingleEC ();
  void constructRichTbUpgradeSingleECSupport ();
  void constructRichTbUpgradeEC15();
  void constructRichTbUpgradeECSupport15();
  void constructRichTbUpgradeEC16LT(G4int aSide);
  void constructRichTbUpgradeECSupport16LT(G4int aSide  );
  void constructRichTbUpgradeEC17();
  void constructRichTbUpgradeECSupport17();
  


  G4LogicalVolume* getRichTbECLeftLVol()
  {  return RichTbECLeftLVol; }
  G4LogicalVolume* getRichTbECRightLVol()
  {  return  RichTbECRightLVol;}
  G4VPhysicalVolume* getRichTbECLeftPVol()
  {  return RichTbECLeftPVol;}
  G4VPhysicalVolume* getRichTbECRightPVol()
  {  return RichTbECRightPVol;}

  //Upgrade 2015
  G4LogicalVolume* getRichTbECBottomLeftLVol()
  {  return RichTbECBottomLeftLVol; }
  G4LogicalVolume* getRichTbECBottomRightLVol()
  {  return  RichTbECBottomRightLVol;}
  G4VPhysicalVolume* getRichTbECBottomLeftPVol()
  {  return RichTbECBottomLeftPVol;}
  G4VPhysicalVolume* getRichTbECBottomRightPVol()
  {  return RichTbECBottomRightPVol;}

  RichTbUpgradePhDetSupFrame * getRTbPhotSupFrame()
  {  return aRTbPhotSupFrame;}

  G4LogicalVolume*  getRichTbECSupLVol()
  {    return  RichTbECSupLVol;}

  
  // upgrade 2016 with LT
  G4LogicalVolume* getRichTbECLVol(G4int iEC) 
  { return RichTbECLVol[iEC];}
  G4VPhysicalVolume* getRichTbECPVol(G4int iECA) 
  {  return RichTbECPVol[iECA];}
  
  G4LogicalVolume* getRichTbECSupportLVol (G4int iEC)
  {return RichTbECSupportLVol [iEC];}
  

  G4VPhysicalVolume* getRichTbECSupportPVol  (G4int iEB)
  {return RichTbECSupportPVol[iEB];}
  
  //upgrade 2017
 G4LogicalVolume* getRichTbECBottomLVol()
  {  return RichTbECBottomLVol; }
  G4LogicalVolume* getRichTbECBottomMediumLVol()
  {  return  RichTbECBottomMediumLVol;}
 G4LogicalVolume* getRichTbECHightMediumLVol()
  {  return RichTbECHightMediumLVol; }
  G4LogicalVolume* getRichTbECHightLVol()
  {  return  RichTbECHightLVol;}

  G4VPhysicalVolume* getRichTbECBottomPVol()
  {  return RichTbECBottomPVol;}
  G4VPhysicalVolume* getRichTbECBottomMediumPVol()
  {  return RichTbECBottomMediumPVol;}
  G4VPhysicalVolume* getRichTbECHightMediumPVol()
  {  return RichTbECHightMediumPVol;}
  G4VPhysicalVolume* getRichTbECHightPVol()
  {  return RichTbECHightPVol;}
    
  
protected:

private:

  G4LogicalVolume*    RichTbECLeftLVol;
  G4LogicalVolume*    RichTbECRightLVol;
  G4VPhysicalVolume*  RichTbECLeftPVol;
  G4VPhysicalVolume*  RichTbECRightPVol;

  //Upgrade 2015
  G4LogicalVolume*    RichTbECBottomLeftLVol;
  G4LogicalVolume*    RichTbECBottomRightLVol;
  G4VPhysicalVolume*  RichTbECBottomLeftPVol;
  G4VPhysicalVolume*  RichTbECBottomRightPVol;

  RichTbUpgradePhDetSupFrame* aRTbPhotSupFrame;
  G4LogicalVolume* RichTbECSupLVol;

  G4VPhysicalVolume* RichTbECSupLeftPVol ;
  G4VPhysicalVolume* RichTbECSupRightPVol ;
  G4VPhysicalVolume* RichTbECSupBottomLeftPVol ;
  G4VPhysicalVolume* RichTbECSupBottomRightPVol ;

  //upgarde 2017
  G4LogicalVolume*    RichTbECBottomLVol;
  G4LogicalVolume*    RichTbECBottomMediumLVol;
  G4LogicalVolume*    RichTbECHightMediumLVol;
  G4LogicalVolume*    RichTbECHightLVol;

  G4VPhysicalVolume*  RichTbECBottomPVol;
  G4VPhysicalVolume*  RichTbECBottomMediumPVol;
  G4VPhysicalVolume*  RichTbECHightMediumPVol;
  G4VPhysicalVolume*  RichTbECHightPVol;

  
  G4VPhysicalVolume* RichTbECSupBottomPVol ;
  G4VPhysicalVolume* RichTbECSupBottomMediumPVol ;
  G4VPhysicalVolume* RichTbECSupHightMediumPVol ;
  G4VPhysicalVolume* RichTbECSupHightPVol ;

  std::vector<G4LogicalVolume*>RichTbECLVol;
  std::vector<G4VPhysicalVolume*>RichTbECPVol;
  
  std::vector<G4LogicalVolume*> RichTbECSupportLVol;
  std::vector<G4VPhysicalVolume*> RichTbECSupportPVol;
  

};
#endif // INCLUDE_RICHTBUPGRADEEC_HH
