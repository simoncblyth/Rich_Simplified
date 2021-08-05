// CLHEP
//#include "CLHEP/Units/PhysicalConstants.h"

// Geant 4
#include "globals.hh"
#include "G4Isotope.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"
#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4UnitsTable.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4OpBoundaryProcess.hh"

// STL etc
#include <iostream>
#include <vector>
// local
#include "RichTbMaterial.hh"
#include "RichTbMaterialParameters.hh"
#include "RichTbRunConfig.hh"
//#include "RichTbGasQuWinProperty.hh"


RichTbMaterial* RichTbMaterial::RichTbMaterialInstance =0;

RichTbMaterial::RichTbMaterial( ){

  InitializeRichTbMaterial();
  
  RichTbRunConfig* aRunConfig= RichTbRunConfig::getRunConfigInstance();
  G4int aRadiatorActivateFlag = aRunConfig ->getLTSelectRadiatorActivate();
  G4int aNitrogenRadiatorSwitchoffFlag = aRunConfig ->getGasCherenkovSwitchOffFlag() ;
  
  
  //  RichTbGasQuWinProperty* aRichTbGasQuWinProperty= RichTbGasQuWinProperty::getRichTbGasQuWinPropertyInstance();

  HistoRichMaterialProperty();

    G4double a, z, density;     //a=mass of a mole;
    // z=mean number of protons;
    G4String name, symbol;
    //  G4int isz, isn;             //isz= number of protons in an isotope;
    //isn= number of nucleons in an isotope;

    G4int numel, natoms;        //numel=Number of elements constituting a material.
    //   G4double abundance;
    G4double fractionmass;
    G4double temperature, pressure;
    G4State aStateGas =  kStateGas;
    // G4double FactorOne = 1.0;
    G4UnitDefinition::BuildUnitsTable();

    //PhotonEnergy

        G4double PhotonEnergyStep = 
       (PhotonMaxEnergy - PhotonMinEnergy) / NumPhotWaveLengthBins;
       G4double *PhotonMomentum = new G4double[NumPhotWaveLengthBins];
       for (G4int ibin = 0; ibin < NumPhotWaveLengthBins; ibin++) {
        PhotonMomentum[ibin] = PhotonMinEnergy + PhotonEnergyStep * ibin;
     }
     G4int IbMinForCkv= PhotEnerBinEdgeForSafety;
     G4int IbMaxForCkv= NumPhotWaveLengthBins-PhotEnerBinEdgeForSafety;
     //     G4double PhotEneryStepForCkvProd=
     //  ( PhotonCkvProdMaxEnergy- PhotonCkvProdMinEnergy)/
     //  CkvProdNumPhotWaveLengthBins;     

       G4double* PhotonMomentumCkvProd = 
           new G4double[CkvProdNumPhotWaveLengthBins];
       for(G4int ibinc=IbMinForCkv;  ibinc<IbMaxForCkv; ibinc++){
         G4int ibp= ibinc- PhotEnerBinEdgeForSafety;
         PhotonMomentumCkvProd[ibp]=PhotonMomentum[ibinc];         
       }
       
       

    G4cout << "\nNow Define Elements ..\n" << G4endl;

    // Nitrogen

    a = 14.01 * CLHEP::g / CLHEP::mole;
    G4Element *elN = new G4Element(name = "Nitrogen",
                                   symbol = "N", z = 7., a);

    //Oxygen

    a = 16.00 * CLHEP::g / CLHEP::mole;
    G4Element *elO = new G4Element(name = "Oxygen",
                                   symbol = "O", z = 8., a);

    //Hydrogen

    a = 1.01 * CLHEP::g / CLHEP::mole;
    G4Element *elH = new G4Element(name = "Hydrogen",
                                   symbol = "H", z = 1., a);

    //Carbon

    a = 12.01 * CLHEP::g / CLHEP::mole;
    G4Element *elC = new G4Element(name = "Carbon",
                                   symbol = "C", z = 6., a);

    //Silicon

    a = 28.09 * CLHEP::g / CLHEP::mole;
    G4Element *elSi = new G4Element(name = "Silicon",
                                    symbol = "Si", z = 14., a);
    //Fluorine
    a = 18.998 * CLHEP::g / CLHEP::mole;
    G4Element *elF = new G4Element(name = "Fluorine",
                                   symbol = "F", z = 9., a);
    //Aluminum
    a = 26.98 * CLHEP::g / CLHEP::mole;
    G4Element *elAL = new G4Element(name = "Aluminium",
                                    symbol = "Al", z = 13., a);

    //Sodium
    a = 22.99 * CLHEP::g / CLHEP::mole;
    G4Element *elNa = new G4Element(name = "Sodium",
                                    symbol = "Na", z = 11., a);

    //Potassium
    a = 39.10 * CLHEP::g / CLHEP::mole;
    G4Element *elK = new G4Element(name = "Potassium",
                                   symbol = "K", z = 19., a);

    //Cesium

    a = 132.91 * CLHEP::g / CLHEP::mole;
    G4Element *elCs = new G4Element(name = "Cesium",
                                    symbol = "Cs", z = 55., a);

    //Antimony

    a = 121.76 * CLHEP::g / CLHEP::mole ;
    G4Element *elSb = new G4Element(name = "Antimony",
                                    symbol = "Sb", z = 51., a);


    // Tantalum
    a=180.94 *  CLHEP::g / CLHEP::mole ;
    G4Element *elTa  = new  G4Element(name = "TanTalum",
                                      symbol = "Ta", z= 73., a);
    


    //Define Materials
    G4cout << "\nNow Define Materials ..\n" << G4endl;
    //

    //Air at 20 degree C and 1 atm for the ambiet air.
    // Also Air as  a radiator material for inside the tubes.
    //--
    density = 1.205e-03 * CLHEP::g /CLHEP::cm3;
    pressure = 1. * CLHEP::atmosphere;
    temperature = 293. * CLHEP::kelvin;
    G4Material *Air = new G4Material(name = "Air", density, numel = 2,
                                     aStateGas, temperature, pressure);
    Air->AddElement(elN, fractionmass = 0.7);
    Air->AddElement(elO, fractionmass = 0.3);


    RichTbAmbientAir = Air;

    density = 1.205e-03 * CLHEP::g /CLHEP::cm3;
    pressure = 1. * CLHEP::atmosphere;
    temperature = 293. * CLHEP::kelvin;
    G4Material *TAir = new G4Material(name = "TAir", density, numel = 2,
                                      aStateGas, temperature, pressure);
    TAir->AddElement(elN, fractionmass = 0.7);
    TAir->AddElement(elO, fractionmass = 0.3);

    G4double *TAirAbsorpLength = new G4double[NumPhotWaveLengthBins];
    G4double *TAirRindex = new G4double[NumPhotWaveLengthBins];

    for (G4int ibin = 0; ibin < NumPhotWaveLengthBins; ibin++) {
      TAirAbsorpLength[ibin] = 1.E32 * CLHEP::mm;
        TAirRindex[ibin] = 1.000273;
    }
    G4MaterialPropertiesTable *TAirMPT = new G4MaterialPropertiesTable();

    TAirMPT->AddProperty("ABSLENGTH", PhotonMomentum, 
                  TAirAbsorpLength, NumPhotWaveLengthBins);

    TAirMPT->AddProperty("RINDEX", PhotonMomentum, TAirRindex, 
                        NumPhotWaveLengthBins);

    TAir->SetMaterialPropertiesTable(TAirMPT);
    RichTbTubeAir = TAir;

    //
    //

    density = 1.205e-03 * CLHEP::g /CLHEP::cm3;
    pressure = 1. * CLHEP::atmosphere;
    temperature = 293. * CLHEP::kelvin;
    G4Material *TAirA = new G4Material(name = "AAir", density, numel = 2,
                                       aStateGas, temperature, pressure);
    TAirA->AddElement(elN, fractionmass = 0.7);
    TAirA->AddElement(elO, fractionmass = 0.3);

    G4double *TAirAAbsorpLength = new G4double[NumPhotWaveLengthBins];
    // G4double *TAirARindex = new G4double[NumPhotWaveLengthBins];

    for (G4int ibin = 0; ibin < NumPhotWaveLengthBins; ibin++) {
      TAirAAbsorpLength[ibin] = 1.E32 * CLHEP::mm;
        //    TAirARindex[ibin]=1.0;
        //    TAirARindex[ibin]=1.000273;
    }
    G4MaterialPropertiesTable *TAirAMPT = new G4MaterialPropertiesTable();

    TAirAMPT->AddProperty("ABSLENGTH", PhotonMomentum, 
                              TAirAAbsorpLength, NumPhotWaveLengthBins);

    //    TAirAMPT->AddProperty("RINDEX", PhotonMomentum,
    //               TAirARindex,NumPhotWaveLengthBins);

    TAirA->SetMaterialPropertiesTable(TAirAMPT);
    RichTbAirA = TAirA;


    //Water
    
    density=1.000* CLHEP::g / CLHEP::cm3;
 G4Material* H2O = new G4Material(name="Water",density,numel=2);
 H2O->AddElement(elH,natoms=2);
 H2O->AddElement(elO,natoms=1);
    G4double *H20AbsorpLength = new G4double[NumPhotWaveLengthBins];
    G4double *H20Rindex = new G4double[NumPhotWaveLengthBins];

    G4MaterialPropertiesTable *H20AMPT = new G4MaterialPropertiesTable();
    for (G4int ibin = 0; ibin < NumPhotWaveLengthBins; ibin++) {
      H20AbsorpLength[ibin]=100000.0 * CLHEP::mm  ;      
         H20Rindex[ibin]=1.33;
       
    }
    H20AMPT->AddProperty("ABSLENGTH",PhotonMomentum,
                         H20AbsorpLength, NumPhotWaveLengthBins);

    H20AMPT->AddProperty("RINDEX", PhotonMomentum,
                         H20Rindex,NumPhotWaveLengthBins);

    H2O->SetMaterialPropertiesTable(H20AMPT);
    



  //Nitrogen gas.

  density = 0.8073e-03 * CLHEP::g / CLHEP::cm3;
  //  pressure=1.*CLHEP::atmosphere;
  // temperature=293.*CLHEP::kelvin;
  pressure = aRunConfig -> getNitrogenPressure();
  
  temperature = aRunConfig ->getNitrogenTemperature();
  

  G4Material* NitrogenGas = new G4Material(name=NitrogenGasMaterialName, 
                                 density, numel=1,
                                 kStateGas,temperature,pressure);
  NitrogenGas->AddElement(elN, natoms=2);

  G4double* NitrogenGasAbsorpLength=new G4double[NumPhotWaveLengthBins];
  G4double* NitrogenGasRindex=new G4double[NumPhotWaveLengthBins];
  G4double* NitrogenGasPhotMom=new G4double[NumPhotWaveLengthBins];

  G4double* NitrogenGasCkvProdRindex=
          new G4double[CkvProdNumPhotWaveLengthBins];
  G4double* NitrogenGasPhotMomCkvProd=
          new G4double[CkvProdNumPhotWaveLengthBins];
  

  std::vector<G4double>N2RefInd= InitN2RefIndex(pressure,temperature);
  std::vector<G4double>N2RefPhotMom=InitN2RefPhotMom();


  for (G4int ibin=0; ibin<NumPhotWaveLengthBins; ibin++){
    NitrogenGasAbsorpLength[ibin]=1.E32 * CLHEP::mm;

    NitrogenGasRindex[ibin]=N2RefInd[ibin];
    NitrogenGasPhotMom[ibin]=N2RefPhotMom[ibin];
    // G4cout<<" N2 ref index in RichMaterial "<<ibin<<"  "<< NitrogenGasPhotMom[ibin]	  <<"  "<<NitrogenGasRindex[ibin]<<G4endl;

  }
  
  for (G4int ibina=IbMinForCkv; ibina <IbMaxForCkv ; ibina++){
    G4int ibinp=  ibina-PhotEnerBinEdgeForSafety;
    
    NitrogenGasCkvProdRindex[ibinp]= NitrogenGasRindex[ibina];
    NitrogenGasPhotMomCkvProd[ibinp]=  NitrogenGasPhotMom[ibina];
    
  }

  
  G4MaterialPropertiesTable* NitrogenGasMPT = 
                            new G4MaterialPropertiesTable();

    NitrogenGasMPT->AddProperty("ABSLENGTH",NitrogenGasPhotMom,
                        NitrogenGasAbsorpLength,NumPhotWaveLengthBins);

    NitrogenGasMPT->AddProperty("RINDEX", NitrogenGasPhotMom, 
                      NitrogenGasRindex,NumPhotWaveLengthBins);


    G4cout <<" Now Nitrogen activate flags "<< aRadiatorActivateFlag << "   "<< aNitrogenRadiatorSwitchoffFlag <<G4endl;
    
    if( (aRadiatorActivateFlag !=2)  &&  ( aNitrogenRadiatorSwitchoffFlag != 1 )   ){
      G4cout <<" Now activate Ckv Prod in Nitrogen "<< G4endl;
      
        NitrogenGasMPT->AddProperty("CKVRNDX", NitrogenGasPhotMomCkvProd , 
                      NitrogenGasCkvProdRindex,CkvProdNumPhotWaveLengthBins);
    }
    
    NitrogenGas->SetMaterialPropertiesTable(NitrogenGasMPT);
    RichTbNitrogenGas = NitrogenGas;

    // test printout

    // G4MaterialPropertyVector* theRefractionIndexVector = 
    //		    	  NitrogenGasMPT ->GetProperty("CKVRNDX");

    //  G4int itb=0;
    //  theRefractionIndexVector->ResetIterator();
    //  while(++(*theRefractionIndexVector))

    //  {
    // itb++;
                               
    //  G4double currentPM = theRefractionIndexVector->GetPhotonMomentum();
    //  G4double currentRI=theRefractionIndexVector->GetProperty();


    // G4cout<<" Richtbmaterial N2refindVect  "<< itb<<"  "<< currentPM<<"  "<<currentRI
    //      <<G4endl;

    //  }  

  // end testprintout
  //c4f10 gas.

  density = 0.01195 * CLHEP::g / CLHEP::cm3;
  //  pressure=1.*CLHEP::atmosphere;
  // temperature=293.*CLHEP::kelvin;
  pressure = aRunConfig -> getc4f10Pressure();
  
  temperature = aRunConfig ->getc4f10Temperature();
  

  G4Material* c4f10Gas = new G4Material(name=c4f10GasMaterialName, 
                                 density, numel=2,
                                 kStateGas,temperature,pressure);
  c4f10Gas->AddElement(elC, natoms=4);
  c4f10Gas->AddElement(elF, natoms=10);

  G4double* c4f10GasAbsorpLength=new G4double[NumPhotWaveLengthBins];
  G4double* c4f10GasRindex=new G4double[NumPhotWaveLengthBins];
  G4double* c4f10GasPhotMom=new G4double[NumPhotWaveLengthBins];

  G4double* c4f10GasCkvProdRindex=
          new G4double[CkvProdNumPhotWaveLengthBins];
  G4double* c4f10GasPhotMomCkvProd=
          new G4double[CkvProdNumPhotWaveLengthBins];
  

  std::vector<G4double>c4f10RefInd= Initc4f10RefIndex(pressure,temperature);
  std::vector<G4double>c4f10RefPhotMom=Initc4f10RefPhotMom();


  for (G4int ibin=0; ibin<NumPhotWaveLengthBins; ibin++){
    c4f10GasAbsorpLength[ibin]=1.E32 * CLHEP::mm;

    c4f10GasRindex[ibin]=c4f10RefInd[ibin];
    c4f10GasPhotMom[ibin]=c4f10RefPhotMom[ibin];

  }
  
  for (G4int ibina=IbMinForCkv; ibina <IbMaxForCkv ; ibina++){
    G4int ibinp=  ibina-PhotEnerBinEdgeForSafety;
    
    c4f10GasCkvProdRindex[ibinp]= c4f10GasRindex[ibina];
    c4f10GasPhotMomCkvProd[ibinp]=  c4f10GasPhotMom[ibina];
    
  }
  
  G4MaterialPropertiesTable* c4f10GasMPT = 
                            new G4MaterialPropertiesTable();

     c4f10GasMPT->AddProperty("ABSLENGTH",c4f10GasPhotMom,
                        c4f10GasAbsorpLength,NumPhotWaveLengthBins);

     c4f10GasMPT->AddProperty("RINDEX", c4f10GasPhotMom, 
                      c4f10GasRindex,NumPhotWaveLengthBins);

     c4f10GasMPT->AddProperty("CKVRNDX", c4f10GasPhotMomCkvProd , 
                      c4f10GasCkvProdRindex,CkvProdNumPhotWaveLengthBins);

    c4f10Gas->SetMaterialPropertiesTable(c4f10GasMPT);
    RichTbc4f10Gas = c4f10Gas;


 // MirrorQuartz.
//Sio2 
//There is a quartz for the mirror and
 //another quartz which is used in aerogel and
 // yet another quartz used for the quartz window.
 //Mirrorquartz

 density=2.200 * CLHEP::g / CLHEP::cm3;
 G4Material* SiO2MirrorQuartz = new G4Material(name="MirrorQuartz",
                                              density,numel=2);
 SiO2MirrorQuartz->AddElement(elSi,natoms=1);
 SiO2MirrorQuartz->AddElement(elO,natoms=2);
 
 //  G4double* MirrorQuartzRindex=new G4double[NumPhotWaveLengthBins];
  G4double* MirrorQuartzAbsorpLength=new G4double[NumPhotWaveLengthBins];
 for (G4int ibin=0; ibin<NumPhotWaveLengthBins; ibin++){
    MirrorQuartzAbsorpLength[ibin]=0.01 * CLHEP::mm;
    //   MirrorQuartzRindex[ibin]=1.40;
  }
  G4MaterialPropertiesTable* MirrorQuartzMPT = 
                            new G4MaterialPropertiesTable();


  MirrorQuartzMPT->AddProperty("ABSLENGTH",PhotonMomentum,
                MirrorQuartzAbsorpLength,NumPhotWaveLengthBins);


  //  MirrorQuartzMPT->AddProperty("RINDEX", PhotonMomentum, 
  //                   MirrorQuartzRindex,NumPhotWaveLengthBins);

  SiO2MirrorQuartz->SetMaterialPropertiesTable(MirrorQuartzMPT);
  RichTbMirrorQuartz=SiO2MirrorQuartz;
 //
 // GasQuWindowQuartz.
//Sio2 

 density=2.200 * CLHEP::g / CLHEP::cm3;
 G4Material* SiO2GasWinQuartz = new G4Material(name="GasWinQuartz",
                                              density,numel=2);
 SiO2GasWinQuartz->AddElement(elSi,natoms=1);
 SiO2GasWinQuartz->AddElement(elO,natoms=2);
 
 // G4int CurGasQuWinAbsorpNumBins=aRichTbGasQuWinProperty->getGasQuWinAbsorpNumBins();
 //  G4double* GasWinQuartzAbsorpLength=new G4double[CurGasQuWinAbsorpNumBins];
 //  G4double* GasWinQuAbsorpPhotonMomentum= new G4double[ CurGasQuWinAbsorpNumBins];
 //  std::vector<G4double> GasQuWinAbsorpLengthVect= aRichTbGasQuWinProperty-> getGasQuWinAbsorpLength();
 //  std::vector<G4double> GasWinQuAbsorpPhotonMomentumVect=aRichTbGasQuWinProperty->  getGasQuWinAbsorpPhMom();  
 //  for(G4int ibina=0; ibina<CurGasQuWinAbsorpNumBins; ibina++) {
   
    //    GasWinQuartzAbsorpLength[ibina]=1.E32 * CLHEP::mm;
 //   GasWinQuartzAbsorpLength[ibina]=GasQuWinAbsorpLengthVect[ibina];
 //   GasWinQuAbsorpPhotonMomentum[ibina]= GasWinQuAbsorpPhotonMomentumVect[ibina];
 //  }

  // now for the refractive index of GasQuWindow.
 //  G4double* GasWinQuartzRindex=new G4double[NumPhotWaveLengthBins];
 // for (G4int ibin=0; ibin<NumPhotWaveLengthBins; ibin++){
    //    GasWinQuartzRindex[ibin]=1.40;
 //  GasWinQuartzRindex[ibin]=GasQuartzWindowNominalRefIndex;
 //  }


 //4MaterialPropertiesTable* GasWinQuartzMPT = 
 //                            new G4MaterialPropertiesTable();


 // GasWinQuartzMPT->AddProperty("ABSLENGTH",GasWinQuAbsorpPhotonMomentum,
 //               GasWinQuartzAbsorpLength,CurGasQuWinAbsorpNumBins);


 // GasWinQuartzMPT->AddProperty("RINDEX", PhotonMomentum, 
 //                    GasWinQuartzRindex,NumPhotWaveLengthBins);

 //  SiO2GasWinQuartz->SetMaterialPropertiesTable(GasWinQuartzMPT);
 // RichTbGasWinQuartz=SiO2GasWinQuartz;

//Vaccum
//
 density=CLHEP::universe_mean_density;    //from PhysicalConstants.h
 a=1.01* CLHEP::g/CLHEP::mole;
 pressure=1.e-19*CLHEP::pascal;
 temperature=0.1*CLHEP::kelvin;
// G4Material* vaccum = new G4Material(name="Galactic",z=1.,a,density,
 G4Material* vaccum = new G4Material(name="Galactic",density,numel=1,
                              kStateGas,temperature,pressure);
 vaccum->AddMaterial(Air, fractionmass=1.);
 G4double *vacAbsorpLength = new G4double[NumPhotWaveLengthBins];
 G4double *vacRindex = new G4double[NumPhotWaveLengthBins];
    for (G4int ibin = 0; ibin < NumPhotWaveLengthBins; ibin++) {
        vacAbsorpLength[ibin] = 1.E32 * CLHEP::mm;
        vacRindex[ibin] = 1.000273;
    }
    G4MaterialPropertiesTable *vacMPT = new G4MaterialPropertiesTable();

    vacMPT->AddProperty("ABSLENGTH", PhotonMomentum, 
                  vacAbsorpLength, NumPhotWaveLengthBins);

    vacMPT->AddProperty("RINDEX", PhotonMomentum, vacRindex, 
                        NumPhotWaveLengthBins);

     vaccum->SetMaterialPropertiesTable(vacMPT);
 
 RichTbVaccum=vaccum;

 // G4cout<<"Now define Aluminium "<<G4endl;
 
//Aluminium
  density=2.7 * CLHEP::g / CLHEP::cm3;
  G4Material* Aluminium =new G4Material(name="Aluminium",density,numel=1);
  Aluminium->AddElement(elAL,natoms=1);
 

  G4double* AluminiumAbsorpLength= new G4double[NumPhotWaveLengthBins];

  for (G4int ibin=0; ibin<NumPhotWaveLengthBins; ibin++){
    AluminiumAbsorpLength[ibin]=0.0 * CLHEP::mm;
  }


  G4MaterialPropertiesTable* AluminiumMPT = 
                            new G4MaterialPropertiesTable();


  AluminiumMPT->AddProperty("ABSLENGTH",PhotonMomentum,
                AluminiumAbsorpLength,NumPhotWaveLengthBins);



  Aluminium->SetMaterialPropertiesTable(AluminiumMPT);

  RichTbAluminium=Aluminium;

  // generic carbon
  density= 2.0 * CLHEP::g / CLHEP::cm3;
  G4Material* CarbonMaterial = 
    new G4Material (name="CarbonMaterial",
                    density,numel=1 );
   CarbonMaterial->AddElement(elC, natoms=1);  
   RichTbCarbon= CarbonMaterial;
   
 
  
// Kovar
  density=2.7 * CLHEP::g / CLHEP::cm3;
  G4Material* Kovar =new G4Material(PMTEnvelopeMaterialName,density,numel=1);
  Kovar->AddElement(elAL,natoms=1);
   
  PMTTubeEnvelopeMaterial=Kovar;
  HpdTubeEnvelopeMaterial=Kovar;
  
  // Silicon
  
   density=2.33 * CLHEP::g / CLHEP::cm3;
   //"PMTSilicon"
  G4Material* Silicon =new G4Material(name= PMTAnodeMaterialName,
             density,numel=1);
  Silicon->AddElement(elSi,natoms=1);

  PMTAnodeMaterial=Silicon;


  G4Material* HpdSilicon =new G4Material(name= HpdSiDetMaterialName,density,numel=1);
  HpdSilicon->AddElement(elSi,natoms=1);
  HpdSiDetMaterial = HpdSilicon;

 
  // hpd quartz window

 density=2.200 * CLHEP::g / CLHEP::cm3;
 //"PMTWindowQuartz"
 G4Material* PMTWindowQuartz = new G4Material(name=PmtQuartzWMaterialName,
                                              density,numel=2);
 PMTWindowQuartz->AddElement(elSi,natoms=1);
 PMTWindowQuartz->AddElement(elO,natoms=2);
 
 G4double* PMTWindowQuartzRindex=new G4double[PMTQuartzRefIndNumBins]; //31 bin
 G4double* PMTWindowQuartzPhMom = new G4double[PMTQuartzRefIndNumBins];
 G4double* PMTWindowQuartzAbsorpLength=new G4double[NumPhotWaveLengthBins];
  for (G4int ibin=0; ibin<NumPhotWaveLengthBins; ibin++){
   PMTWindowQuartzAbsorpLength[ibin]=1.E32 * CLHEP::mm;
   //    PMTWindowQuartzRindex[ibin]=1.40;
  }
  for(G4int ibina=0; ibina <PMTQuartzRefIndNumBins; ibina++ ) {
     PMTWindowQuartzPhMom[ibina]=
       PhotWaveLengthToMom/
       (PMTQuartzRefWaveLenValues[ibina]*PMTQuartzRefWaveLenUnits);     
      PMTWindowQuartzRindex[ibina] = PMTQuartzRefIndexValues[ibina];
    
  }
  
  G4MaterialPropertiesTable* PMTWindowQuartzMPT = 
                            new G4MaterialPropertiesTable();

  PMTWindowQuartzMPT->AddProperty("ABSLENGTH",PhotonMomentum,
                PMTWindowQuartzAbsorpLength,NumPhotWaveLengthBins);

  PMTWindowQuartzMPT->AddProperty("RINDEX",PMTWindowQuartzPhMom , 
                        PMTWindowQuartzRindex,PMTQuartzRefIndNumBins);

  PMTWindowQuartz->SetMaterialPropertiesTable(PMTWindowQuartzMPT);

  PMTQuartzWindowMaterial=PMTWindowQuartz;

  
 //"HPDWindowQuartz"

 G4Material* HPDWindowQuartz = new G4Material(name= HpdQuartzWMaterialName,density,numel=2);
 HPDWindowQuartz->AddElement(elSi,natoms=1);
 HPDWindowQuartz->AddElement(elO,natoms=2);
 
 G4double* HPDWindowQuartzRindex=new G4double[HPDQuartzRefIndNumBins]; //31 bin
 G4double* HPDWindowQuartzPhMom = new G4double[HPDQuartzRefIndNumBins];

 G4double* HPDWindowQuartzAbsorpLength=new G4double[NumPhotWaveLengthBins];

  for (G4int ibin=0; ibin<NumPhotWaveLengthBins; ibin++){
   HPDWindowQuartzAbsorpLength[ibin]=1.E32 * CLHEP::mm;
   //    PMTWindowQuartzRindex[ibin]=1.40;
  }
  for(G4int ibina=0; ibina <HPDQuartzRefIndNumBins; ibina++ ) {
     HPDWindowQuartzPhMom[ibina]=
       PhotWaveLengthToMom/
       (HPDQuartzRefWaveLenValues[ibina]*HPDQuartzRefWaveLenUnits);     
        HPDWindowQuartzRindex[ibina] = HPDQuartzRefIndexValues[ibina];
    
  }
  
  
  G4MaterialPropertiesTable* HPDWindowQuartzMPT = 
                            new G4MaterialPropertiesTable();

  HPDWindowQuartzMPT->AddProperty("ABSLENGTH",PhotonMomentum,
                HPDWindowQuartzAbsorpLength,NumPhotWaveLengthBins);

  HPDWindowQuartzMPT->AddProperty("RINDEX",HPDWindowQuartzPhMom , 
                        HPDWindowQuartzRindex,HPDQuartzRefIndNumBins);

  HPDWindowQuartz->SetMaterialPropertiesTable(HPDWindowQuartzMPT);

  HPDQuartzWindowMaterial=HPDWindowQuartz;



// crystal material

  density=2.200 * CLHEP::g / CLHEP::cm3; //non e' quella giusta
                       // please provide the correct density.  

 G4Material* CrystalMat = new G4Material(name=CrystalMaterialName,
                                              density,numel=2);
 CrystalMat->AddElement(elSi,natoms=1); // anche questi sono sbagliati
 CrystalMat->AddElement(elO,natoms=2);
 
  G4double* CrystalMatRindex=new G4double[CrystalMatRefIndNumBins]; //31 
  //std::vector<G4double> CrystalMatRefPhMom=Initc4f10RefPhotMom();
  G4double* CrystalMatPhMom = new G4double[CrystalMatRefIndNumBins];
  G4double* CrystalMatAbsorpLength= new G4double[CrystalMatRefIndNumBins];
  G4double* CrystalMatCkvProdRindex= new G4double[CrystalMatRefIndNumBins];
  //  G4cout << "n bin " << CkvProdNumPhotWaveLengthBins << G4endl;
  G4double* CrystalMatPhotMomCkvProd=
          new G4double[CrystalMatRefIndNumBins];
  //  test study for reconstruction
  //  G4bool m_activateRefIndexStudy = false;

   G4bool m_activateRefIndexStudy = true;
  
  //  G4double  CrysMatRefractiveIndexShift = m_activateRefIndexStudy ? 0.1 : 0.0 ;
  G4double  CrysMatRefractiveIndexShift = m_activateRefIndexStudy ? 0.03 : 0.0 ;
  
  // end test study for reconstruction
 
  
  for(G4int ibina=0; ibina <CrystalMatRefIndNumBins; ibina++ ) {
     CrystalMatPhMom[ibina]=
     PhotWaveLengthToMom/
    	(CrystalMatRefWaveLenValues[ibina]*CrystalMatRefWaveLenUnits);   
      CrystalMatRindex[ibina] = CrystalMatRefIndexValues[ibina] + CrysMatRefractiveIndexShift;
    //  G4cout<<"Crystal RI " << CrystalMatRindex[ibina] <<G4endl;
      //G4cout<<"momentum " << CrystalMatPhMom[ibina] <<G4endl;

      
      //  CrystalMatAbsorpLength[ibina]=1.E32 * CLHEP::mm;
       CrystalMatAbsorpLength[ibina] = CrystalMatAbsorptionValues[ibina] * CLHEP::mm;
       //  CrystalMatRindex[ibina]=1.5;
    // G4cout<<"Crystal RI " << CrystalMatRindex[ibin] <<G4endl;  
       //   G4cout<<"Crystal momentum and  Abs Length " <<CrystalMatPhMom[ibina]<< " "<<CrystalMatAbsorpLength[ibina] <<G4endl;
   
     G4int ibinp = ibina;
     CrystalMatCkvProdRindex[ibinp]= CrystalMatRindex[ibina];
    // G4cout << "Ckv crystal RI " << ibinp<< " " << CrystalMatCkvProdRindex[ibinp] << G4endl;
    CrystalMatPhotMomCkvProd[ibinp]=  CrystalMatPhMom[ibina];
    // G4cout << "Ckv momentum " << ibinp<< " " << CrystalMatPhotMomCkvProd[ibinp] << G4endl;
  }
  

  
  G4MaterialPropertiesTable* CrystalMPT = 
                            new G4MaterialPropertiesTable();

  CrystalMPT->AddProperty("ABSLENGTH",CrystalMatPhMom,
			  CrystalMatAbsorpLength,CrystalMatRefIndNumBins);

  CrystalMPT->AddProperty("RINDEX",CrystalMatPhMom , 
                        CrystalMatRindex,CrystalMatRefIndNumBins);

  CrystalMPT->AddProperty("CKVRNDX", CrystalMatPhotMomCkvProd , 
                      CrystalMatCkvProdRindex,CrystalMatRefIndNumBins);

  CrystalMat->SetMaterialPropertiesTable(CrystalMPT);

  CrystalMaterial=CrystalMat;


  // LayerTec radiator substrate material

  G4Material* LTSubstrateMat  = new G4Material(name=LTSubstrateMaterialName,
                                              density,numel=2);
  LTSubstrateMat->AddElement(elSi,natoms=1);
  LTSubstrateMat->AddElement(elO,natoms=2);

  G4double* LTSubstrateRindex=new G4double[LTSubstrateMatRefIndNumBins]; //30
  G4double* LTSubstratePhMom = new G4double[LTSubstrateMatRefIndNumBins];
  G4double* LTSubstrateAbsorpLength= new G4double[LTSubstrateMatRefIndNumBins];
  G4double* LTSubstrateCkvProdRindex= new G4double[LTSubstrateMatProdRefIndNumBins];
  G4double* LTSubstratePhMomCkvProd = new G4double[LTSubstrateMatProdRefIndNumBins];



  for (G4int ibint=0; ibint < LTSubstrateMatRefIndNumBins ; ibint++) {
    LTSubstratePhMom[ibint]=  PhotWaveLengthToMom/
      (LayerTecSubstrateWavelengthValues[ibint]*LTMatWaveLengthUnits);
    LTSubstrateRindex[ibint] = LayerTecSubstrateRefIndexValues[ibint];
    LTSubstrateAbsorpLength[ibint]= LayerTecSubstrateAbsorptionValues[ibint] * CLHEP::mm;
  }

  for (G4int ibins=0; ibins < LTSubstrateMatProdRefIndNumBins ; ibins++) {
     LTSubstratePhMomCkvProd[ibins]=PhotWaveLengthToMom/
       (LayerTecSubstrateProdRefIndexWavelengthValues[ibins]*LTMatWaveLengthUnits);
     LTSubstrateCkvProdRindex[ibins]= LayerTecSubstrateProdRefIndexValues[ibins];
  }
  


  G4MaterialPropertiesTable* LTSubstrateMPT = 
                            new G4MaterialPropertiesTable();

  LTSubstrateMPT ->AddProperty("ABSLENGTH", LTSubstratePhMom,
                               LTSubstrateAbsorpLength,LTSubstrateMatRefIndNumBins);
  
  LTSubstrateMPT ->AddProperty("RINDEX",LTSubstratePhMom,
                               LTSubstrateRindex,LTSubstrateMatRefIndNumBins);


  if( (aRadiatorActivateFlag !=2)  &&  (aRadiatorActivateFlag !=1) ){
 
    LTSubstrateMPT ->AddProperty("CKVRNDX", LTSubstratePhMomCkvProd,
                        LTSubstrateCkvProdRindex,LTSubstrateMatProdRefIndNumBins);
  
  }
  
  LTSubstrateMat ->SetMaterialPropertiesTable( LTSubstrateMPT);
  
  LTSubstrateMaterial= LTSubstrateMat;
  
  // LayerTec radiator equivalent material

  G4Material* LTPhCSampleAMat = new  G4Material(name=LTPhCSampleAMaterialName, 
                                              density,numel=3);
  LTPhCSampleAMat->AddElement(elSi,natoms=1);
  LTPhCSampleAMat->AddElement(elO,natoms=7);
  LTPhCSampleAMat->AddElement(elTa,natoms=2);

  G4double* LTPhCSampleARindex=new G4double[LTPhCMatRefIndNumBins]; //15
  G4double* LTPhCPhMom = new G4double[LTPhCMatRefIndNumBins];
  G4double* LTPhCAbsorpLength= new G4double[LTPhCMatRefIndNumBins];
  G4double* LTPhCSampleACkvProdRindex= new G4double[LTPhCMatProdRefIndNumBins]; //10
  G4double* LTPhCPhMomCkvProd = new G4double[LTPhCMatProdRefIndNumBins];


  // G4cout << "Layertec sampleA PhC refindex values "<<G4endl;
  
  for(G4int ibinzA=0; ibinzA<LTPhCMatRefIndNumBins; ibinzA++){
    LTPhCPhMom[ibinzA]= PhotWaveLengthToMom/
      (LayerTecPhCSampleWavelengthValues[ibinzA]*LTMatWaveLengthUnits); 
    LTPhCSampleARindex[ibinzA]= LayerTecPhCSampleARefIndexValues[ibinzA];
    LTPhCAbsorpLength[ibinzA]=  LayerTecSampleAbsorptionValues[ibinzA];
    //  G4cout <<"SampleA PhC bin wlen energy rindex abslength    "<< ibinzA <<"  "<<LayerTecPhCSampleWavelengthValues[ibinzA]
    //       <<"  "<< LTPhCPhMom[ibinzA] <<"  "<<LTPhCSampleARindex[ibinzA]<<"  "<<LTPhCAbsorpLength[ibinzA]<<G4endl;
    
  }
  for(G4int ibinaA=0; ibinaA< LTPhCMatProdRefIndNumBins; ibinaA++) {
    LTPhCPhMomCkvProd[ibinaA]=PhotWaveLengthToMom/
      (LayerTecPhCSampleProdWavelengthValues[ibinaA]*LTMatWaveLengthUnits); 
    LTPhCSampleACkvProdRindex[ibinaA]= LayerTecPhCSampleAProdRefIndexValues[ibinaA];
    
    //  G4cout <<"SampleA PhC CKVProd bin wlen energy rindex   "<<ibinaA<<"  "<<LayerTecPhCSampleProdWavelengthValues[ibinaA]
    //       <<"   "<<LTPhCPhMomCkvProd[ibinaA]<<"  "<<LTPhCSampleACkvProdRindex[ibinaA]<<G4endl;
    
  } 

  G4MaterialPropertiesTable* LTPhCSampleAMPT = 
                            new G4MaterialPropertiesTable();

  LTPhCSampleAMPT ->AddProperty("ABSLENGTH", LTPhCPhMom,
                               LTPhCAbsorpLength,LTPhCMatRefIndNumBins);
  
  LTPhCSampleAMPT ->AddProperty("RINDEX",LTPhCPhMom,
                               LTPhCSampleARindex,LTPhCMatRefIndNumBins);
  


  if( aRadiatorActivateFlag !=3 ){


    LTPhCSampleAMPT ->AddProperty("CKVRNDX", LTPhCPhMomCkvProd,
                        LTPhCSampleACkvProdRindex,LTPhCMatProdRefIndNumBins);
  
  }
  
  LTPhCSampleAMat ->SetMaterialPropertiesTable( LTPhCSampleAMPT);

  LTPhCSampleAMaterial= LTPhCSampleAMat;
  
  G4double* LTPhCSampleBRindex=new G4double[LTPhCMatRefIndNumBins]; //15
  G4double* LTPhCSampleBCkvProdRindex= new G4double[LTPhCMatRefIndNumBins];

  G4Material* LTPhCSampleBMat = new  G4Material(name=LTPhCSampleBMaterialName, 
                                              density,numel=3);
  LTPhCSampleBMat->AddElement(elSi,natoms=1);
  LTPhCSampleBMat->AddElement(elO,natoms=7);
  LTPhCSampleBMat->AddElement(elTa,natoms=2);

  
  for(G4int ibinzB=0; ibinzB<LTPhCMatRefIndNumBins; ibinzB++){
    LTPhCSampleBRindex[ibinzB]= LayerTecPhCSampleBRefIndexValues[ibinzB];
  }
  for(G4int ibinaB=0; ibinaB< LTPhCMatProdRefIndNumBins; ibinaB++) {
    LTPhCSampleBCkvProdRindex[ibinaB]= LayerTecPhCSampleBProdRefIndexValues[ibinaB];
    
  }

  G4MaterialPropertiesTable* LTPhCSampleBMPT = 
                            new G4MaterialPropertiesTable();

  LTPhCSampleBMPT ->AddProperty("ABSLENGTH", LTPhCPhMom,
                               LTPhCAbsorpLength,LTPhCMatRefIndNumBins);
  LTPhCSampleBMPT ->AddProperty("RINDEX",LTPhCPhMom,
                               LTPhCSampleBRindex,LTPhCMatRefIndNumBins);

  if( aRadiatorActivateFlag !=3 ){

     LTPhCSampleBMPT ->AddProperty("CKVRNDX", LTPhCPhMomCkvProd,
                        LTPhCSampleBCkvProdRindex,LTPhCMatProdRefIndNumBins);

  }
  
  LTPhCSampleBMat ->SetMaterialPropertiesTable( LTPhCSampleBMPT);
  LTPhCSampleBMaterial= LTPhCSampleBMat;


  // PHC filter material Sample A

  G4Material* LTFilterMatA  = new G4Material(name=LTFilterSampleAMaterialName,
                                              density,numel=2);
  LTFilterMatA->AddElement(elSi,natoms=1);
  LTFilterMatA->AddElement(elO,natoms=2);

  G4double* LTFilterARindex=new G4double[ LTFilterMatRefIndNumBins]; //30
  G4double* LTFilterAPhMom = new G4double[ LTFilterMatRefIndNumBins];
  G4double* LTFilterAAbsorpLength= new G4double[ LTFilterMatRefIndNumBins];
  G4double* LTFilterACkvProdRindex= new G4double[LTFilterMatProdRefIndNumBins];
  G4double* LTFilterAPhMomCkvProd = new G4double[LTFilterMatProdRefIndNumBins];



  for (G4int ibintfa=0; ibintfa < LTFilterMatRefIndNumBins ; ibintfa++) {
    LTFilterAPhMom[ibintfa]=  PhotWaveLengthToMom/
      (LayerTecFilterWavelengthValues[ibintfa]*LTMatWaveLengthUnits);
    LTFilterARindex[ibintfa] = LayerTecPhCFilterRefIndexValues[ibintfa];
    LTFilterAAbsorpLength[ibintfa]= LayerTecFilterSampleAAbsorptionValues[ibintfa] * CLHEP::mm;
  }

  for (G4int ibinsfa=0; ibinsfa < LTFilterMatProdRefIndNumBins ; ibinsfa++) {
     LTFilterAPhMomCkvProd[ibinsfa]=PhotWaveLengthToMom/
       (LayerTecFilterProdRefIndexWavelengthValues[ibinsfa]*LTMatWaveLengthUnits);
     LTFilterACkvProdRindex[ibinsfa]= LayerTecPhCFilterProdRefIndexValues[ibinsfa];
  }
  


  G4MaterialPropertiesTable* LTFilterAMPT = 
                            new G4MaterialPropertiesTable();

  LTFilterAMPT ->AddProperty("ABSLENGTH", LTFilterAPhMom,
                               LTFilterAAbsorpLength,LTFilterMatRefIndNumBins);
  
  LTFilterAMPT ->AddProperty("RINDEX",LTFilterAPhMom,
                               LTFilterARindex,LTFilterMatRefIndNumBins);


  if( (aRadiatorActivateFlag !=2)  &&  (aRadiatorActivateFlag !=1) ){
  
      LTFilterAMPT ->AddProperty("CKVRNDX", LTFilterAPhMomCkvProd,
                        LTFilterACkvProdRindex,LTFilterMatProdRefIndNumBins);

  }
  
  LTFilterMatA ->SetMaterialPropertiesTable( LTFilterAMPT);
  
  LTFilterSampleAMaterial= LTFilterMatA;


  
  G4Material* LTFilterMatB  = new G4Material(name=LTFilterSampleBMaterialName,
                                              density,numel=2);
  LTFilterMatB->AddElement(elSi,natoms=1);
  LTFilterMatB->AddElement(elO,natoms=2);

  G4double* LTFilterBRindex=new G4double[ LTFilterMatRefIndNumBins]; //30
  G4double* LTFilterBPhMom = new G4double[ LTFilterMatRefIndNumBins];
  G4double* LTFilterBAbsorpLength= new G4double[ LTFilterMatRefIndNumBins];
  G4double* LTFilterBCkvProdRindex= new G4double[LTFilterMatProdRefIndNumBins];
  G4double* LTFilterBPhMomCkvProd = new G4double[LTFilterMatProdRefIndNumBins];



  for (G4int ibintfb=0; ibintfb < LTFilterMatRefIndNumBins ; ibintfb++) {
    LTFilterBPhMom[ibintfb]=  PhotWaveLengthToMom/
      (LayerTecFilterWavelengthValues[ibintfb]*LTMatWaveLengthUnits);
    LTFilterBRindex[ibintfb] = LayerTecPhCFilterRefIndexValues[ibintfb];
    LTFilterBAbsorpLength[ibintfb]= LayerTecFilterSampleBAbsorptionValues[ibintfb] * CLHEP::mm;
  }

  for (G4int ibinsfb=0; ibinsfb < LTFilterMatProdRefIndNumBins ; ibinsfb++) {
     LTFilterBPhMomCkvProd[ibinsfb]=PhotWaveLengthToMom/
       (LayerTecFilterProdRefIndexWavelengthValues[ibinsfb]*LTMatWaveLengthUnits);
     LTFilterBCkvProdRindex[ibinsfb]= LayerTecPhCFilterProdRefIndexValues[ibinsfb];
  }
  


  G4MaterialPropertiesTable* LTFilterBMPT = 
                            new G4MaterialPropertiesTable();

  LTFilterBMPT ->AddProperty("ABSLENGTH", LTFilterBPhMom,
                               LTFilterBAbsorpLength,LTFilterMatRefIndNumBins);
  
  LTFilterBMPT ->AddProperty("RINDEX",LTFilterBPhMom,
                               LTFilterBRindex,LTFilterMatRefIndNumBins);
  
  LTFilterBMPT ->AddProperty("CKVRNDX", LTFilterBPhMomCkvProd,
                        LTFilterBCkvProdRindex,LTFilterMatProdRefIndNumBins);
  
  LTFilterMatB ->SetMaterialPropertiesTable( LTFilterBMPT);
  
  LTFilterSampleBMaterial= LTFilterMatB;



  // Now for the polymer plus radiator material

  //  G4cout <<" Now for polymer plus material "<<G4endl;
  

  density=1.2 * CLHEP::g / CLHEP::cm3;
  
  G4Material* PolymerPlusRad = new  G4Material(PolymerPlusMaterialName, 
                                               density, numel=2);
  
   PolymerPlusRad ->AddElement(elC, natoms=4);  
   PolymerPlusRad ->AddElement(elH, natoms=4);   

   G4MaterialPropertiesTable* PolymerPlusMPT = 
                            new G4MaterialPropertiesTable();
  
  G4double* PolymerPlusRindex=new G4double[PolymerPlusMatRefIndNumBins]; //30
  G4double* PolymerPlusPhMom = new G4double[PolymerPlusMatRefIndNumBins ];
  G4double* PolymerPlusAbsorpLength= new G4double[PolymerPlusMatRefIndNumBins];
  G4double* PolymerPlusCkvProdRindex= new G4double[PolymerPlusMatProdRefIndNumBins];
  G4double* PolymerPlusPhMomCkvProd = new G4double[PolymerPlusMatProdRefIndNumBins];


  for (G4int ibinp=0; ibinp < PolymerPlusMatRefIndNumBins ; ibinp++) {
     PolymerPlusPhMom  [ibinp] = PhotWaveLengthToMom/
       (PolymerPlusMatWavelengthValues[ibinp]* PolymerPlusWavelengthUnits);
    PolymerPlusRindex[ibinp] = PolymerPlusMatRefIndexValues[ibinp];


    
    PolymerPlusAbsorpLength [ibinp]= PolymerPlusMatAbsorptionValues[ibinp] * CLHEP::mm;

    //    G4cout << "Test abs length polymer bin val "<< ibinp <<"  "<<  PolymerPlusMatAbsorptionValues[ibinp] << 
    //  "  "<< PolymerPlusPhMom[ibinp] <<"  "<<PolymerPlusMatWavelengthValues[ibinp]<<"  "
    //  <<PolymerPlusAbsorpLength[ibinp]<<    G4endl;
  }

  for (G4int ibinq=0; ibinq <PolymerPlusMatProdRefIndNumBins  ; ibinq++) {
     PolymerPlusPhMomCkvProd [ibinq]=PhotWaveLengthToMom/
       (PolymerPlusMatProdRefIndWavelengthValues[ibinq]*PolymerPlusWavelengthUnits); 
     PolymerPlusCkvProdRindex [ibinq]= PolymerPlusMatProdRefIndexValues[ibinq];  
  }

   
     PolymerPlusMPT  -> AddProperty("ABSLENGTH", PolymerPlusPhMom,
                       PolymerPlusAbsorpLength,PolymerPlusMatRefIndNumBins);
  
  PolymerPlusMPT ->AddProperty("RINDEX",PolymerPlusPhMom,
                                 PolymerPlusRindex, PolymerPlusMatRefIndNumBins);
  
  PolymerPlusMPT ->AddProperty("CKVRNDX", PolymerPlusPhMomCkvProd,
                        PolymerPlusCkvProdRindex,PolymerPlusMatProdRefIndNumBins);
  

   
  PolymerPlusRad->SetMaterialPropertiesTable(PolymerPlusMPT);
  
 
   PolymerPlusMaterial =  PolymerPlusRad;


   // Now for quartz radiator material



  density=2.200 * CLHEP::g / CLHEP::cm3;

  G4Material* QuartzRadiatorMat = new G4Material(name=QuartzMaterialName,
                                              density,numel=2);
  QuartzRadiatorMat->AddElement(elSi,natoms=1);
  QuartzRadiatorMat->AddElement(elO,natoms=2);
 
  G4double* QuartzRadiatorMatRindex=new G4double[QuartzMatRefIndNumBins];
  G4double* QuartzRadiatorMatPhMom = new G4double[QuartzMatRefIndNumBins];
  G4double* QuartzRadiatorMatAbsorpLength= new G4double[QuartzMatRefIndNumBins];

  // G4double* QuartzRadiatorMatProdRindex= new G4double[QuartzMatProdRefIndNumBins];


  G4double* QuartzRadiatorMatCkvProdRindex =
          new G4double[QuartzMatProdRefIndNumBins];

  G4double* QuartzRadiatorMatCkvProdPhMom  =
          new G4double[QuartzMatProdRefIndNumBins];

   

  
 
  for(G4int ibinq=0; ibinq <QuartzMatRefIndNumBins; ibinq++ ) {
     QuartzRadiatorMatPhMom[ibinq]=
     PhotWaveLengthToMom/(QuartzMatRefWaveLenValues[ibinq]*QuartzMatRefWaveLenUnits);   

      QuartzRadiatorMatRindex[ibinq] = QuartzRadiatorMatRefIndexValues[ibinq];
      

       QuartzRadiatorMatAbsorpLength[ibinq] = QuartzRadiatorMatAbsorptionValues[ibinq] * CLHEP::mm;
  }
  
  for(G4int ibinqa=0; ibinqa <QuartzMatProdRefIndNumBins; ibinqa++ ) {

       QuartzRadiatorMatCkvProdRindex[ibinqa]=  QuartzRadiatorProdMatRefIndexValues[ibinqa];

       QuartzRadiatorMatCkvProdPhMom [ibinqa]= 
          PhotWaveLengthToMom/ (QuartzMatProdRefWaveLenValues [ibinqa]*QuartzMatRefWaveLenUnits) ;

  }
  

  
  G4MaterialPropertiesTable* QuartzRadiatorMPT = 
                            new G4MaterialPropertiesTable();

  QuartzRadiatorMPT->AddProperty("ABSLENGTH",   QuartzRadiatorMatPhMom,
			  QuartzRadiatorMatAbsorpLength , QuartzMatRefIndNumBins );

  QuartzRadiatorMPT->AddProperty("RINDEX", QuartzRadiatorMatPhMom, 
                        QuartzRadiatorMatRindex ,QuartzMatRefIndNumBins);

  QuartzRadiatorMPT->AddProperty("CKVRNDX", QuartzRadiatorMatCkvProdPhMom , 
                      QuartzRadiatorMatCkvProdRindex, QuartzMatProdRefIndNumBins);

  QuartzRadiatorMat ->  SetMaterialPropertiesTable(QuartzRadiatorMPT);

  QuartzRadiatorMaterial=QuartzRadiatorMat;








   

  // PMT Ph Cathode

 //the following numbers on the property of the S20 may not be accurate.
 //Some number is is jut put in for initial program test purposes.
 //The real composition is 60 nm of Na2KSb followed by 20 nm of Cs3Sb
 //from the outside to inside of the HPD. 
  density=0.100 * CLHEP::g / CLHEP::cm3;
  //"S20PhCathode"


 G4Material* S20PhCathode = new G4Material(name=PmtPhCathodeMaterialName, 
                                 density, numel=4);
 S20PhCathode->AddElement(elNa, fractionmass=37.5 * CLHEP::perCent);
 S20PhCathode->AddElement(elK, fractionmass=18.75 * CLHEP::perCent);
 S20PhCathode->AddElement(elCs, fractionmass=18.75 * CLHEP::perCent);
 S20PhCathode->AddElement(elSb, fractionmass=25.0 * CLHEP::perCent);

 // G4double* S20PhCathodeRindex=new G4double[NumPhotWaveLengthBins];
  G4int  S20PhCathodeRefIndNumBins=PMTQuartzRefIndNumBins;
  G4double* S20PhCathodeRindex=new G4double[S20PhCathodeRefIndNumBins];
  G4double* S20PhCathodeRefIndPhMom = new G4double[S20PhCathodeRefIndNumBins];
 // the ref index of phcathode is derived from that of the hpd quartz window.
 // using the formula (na*na-nb*nb)/(na*na+nb*nb) = fraction of refelcted photons. 
 G4double refindphFactor=1.04;
 if (PMTQwPhReflectionProb < 1.0)refindphFactor =  
       pow(((1+PMTQwPhReflectionProb)/(1-PMTQwPhReflectionProb)),0.5);
 for(G4int ibins=0; ibins <S20PhCathodeRefIndNumBins; ibins++ ) {
  //    S20PhCathodeRindex[ibin]=1.6;

    S20PhCathodeRefIndPhMom[ibins] =  PMTWindowQuartzPhMom[ibins];

    S20PhCathodeRindex[ibins] =   refindphFactor* PMTWindowQuartzRindex[ibins];
 }
  // now for the absorption length.
 G4double* S20PhCathodeAbsorpLength=new G4double[NumPhotWaveLengthBins];
 G4double MomBoundaryRedBlue=PhotWaveLengthToMom/PMTPhCathodeRedBlueBoundary;
 G4double ablengblue = -1.0*RichTbPMTPhCathodeThickness/log(PMTPhCathodeTransBlue);
 G4double ablengred=  -1.0*RichTbPMTPhCathodeThickness/log(PMTPhCathodeTransRed);

  for (G4int iabin=0; iabin < NumPhotWaveLengthBins; iabin++ ) {
   if(PhotonMomentum[iabin] < MomBoundaryRedBlue ) {
     S20PhCathodeAbsorpLength[iabin]=ablengred;     
   }else {
     S20PhCathodeAbsorpLength[iabin]= ablengblue;
   }
   

  }


 G4MaterialPropertiesTable* S20PhCathodeMPT = 
                            new G4MaterialPropertiesTable();
  S20PhCathodeMPT->AddProperty("ABSLENGTH",PhotonMomentum,
                S20PhCathodeAbsorpLength,NumPhotWaveLengthBins);

  //  S20PhCathodeMPT->AddProperty("RINDEX", PhotonMomentum, 
  //                      S20PhCathodeRindex,NumPhotWaveLengthBins);
  S20PhCathodeMPT->AddProperty("RINDEX",S20PhCathodeRefIndPhMom , 
                        S20PhCathodeRindex,S20PhCathodeRefIndNumBins);



  S20PhCathode->SetMaterialPropertiesTable(S20PhCathodeMPT);
  PMTPhCathodeMaterial=S20PhCathode;




  //"HPDS20PhCathode"

 G4Material* HPDS20PhCathode = new G4Material(name=HpdPhCathodeMaterialName, 
                                 density, numel=4);
 HPDS20PhCathode->AddElement(elNa, fractionmass=37.5 * CLHEP::perCent);
 HPDS20PhCathode->AddElement(elK, fractionmass=18.75 * CLHEP::perCent);
 HPDS20PhCathode->AddElement(elCs, fractionmass=18.75 * CLHEP::perCent);
 HPDS20PhCathode->AddElement(elSb, fractionmass=25.0 * CLHEP::perCent );

 // G4double* S20PhCathodeRindex=new G4double[NumPhotWaveLengthBins];

  G4int  HPDS20PhCathodeRefIndNumBins=HPDQuartzRefIndNumBins;

  G4double* HPDS20PhCathodeRindex=new G4double[HPDS20PhCathodeRefIndNumBins];
  G4double* HPDS20PhCathodeRefIndPhMom = new G4double[HPDS20PhCathodeRefIndNumBins];
 // the ref index of phcathode is derived from that of the hpd quartz window.
 // using the formula (na*na-nb*nb)/(na*na+nb*nb) = fraction of refelcted photons. 

 G4double hpdrefindphFactor=1.04;


 if (HPDQwPhReflectionProb < 1.0) 
   hpdrefindphFactor =  pow(((1+HPDQwPhReflectionProb)/(1-HPDQwPhReflectionProb)),0.5);

  for(G4int ibins=0; ibins <HPDS20PhCathodeRefIndNumBins; ibins++ ) {
  //    HPDS20PhCathodeRindex[ibin]=1.6;

    HPDS20PhCathodeRefIndPhMom[ibins] =  HPDWindowQuartzPhMom[ibins];

    HPDS20PhCathodeRindex[ibins] =   hpdrefindphFactor* HPDWindowQuartzRindex[ibins];
  }
  

  // now for the absorption length.
 G4double* HPDS20PhCathodeAbsorpLength=new G4double[NumPhotWaveLengthBins];

 // G4double HpdMomBoundaryRedBlue=PhotWaveLengthToMom/HPDPhCathodeRedBlueBoundary;
 G4double hablengblue = -1.0*RichTbHpdPhCathodeThickness/log(HPDPhCathodeTransBlue);
 G4double hablengred=  -1.0*RichTbHpdPhCathodeThickness/log(HPDPhCathodeTransRed);

 for (G4int ibin=0; ibin<NumPhotWaveLengthBins; ibin++){
   //   S20PhCathodeAbsorpLength[ibin]=1.E32 * CLHEP::mm;
   if(PhotonMomentum[ibin] < MomBoundaryRedBlue ) {
     // we are in the red region.
     HPDS20PhCathodeAbsorpLength[ibin]=hablengred;     
   }else {
     HPDS20PhCathodeAbsorpLength[ibin]= hablengblue;  
     
   } 

 }
 

 

  G4MaterialPropertiesTable* HPDS20PhCathodeMPT = 
                            new G4MaterialPropertiesTable();
  HPDS20PhCathodeMPT->AddProperty("ABSLENGTH",PhotonMomentum,
                                  HPDS20PhCathodeAbsorpLength,NumPhotWaveLengthBins);

  //  S20PhCathodeMPT->AddProperty("RINDEX", PhotonMomentum, 
  //                      S20PhCathodeRindex,NumPhotWaveLengthBins);

  HPDS20PhCathodeMPT->AddProperty("RINDEX",HPDS20PhCathodeRefIndPhMom , 
                                  HPDS20PhCathodeRindex,HPDS20PhCathodeRefIndNumBins);

  HPDS20PhCathode->SetMaterialPropertiesTable(HPDS20PhCathodeMPT);
  HPDPhCathodeMaterial=HPDS20PhCathode;



  




}





RichTbMaterial* RichTbMaterial::getRichTbMaterialInstance() 
{
  if( RichTbMaterialInstance== 0 ) {
    RichTbMaterialInstance= new RichTbMaterial();
    
  }

  return RichTbMaterialInstance;
  
}


RichTbMaterial::~RichTbMaterial()
{
    ;
}
