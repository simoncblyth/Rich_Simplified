// $Id: $
// Include files

#include "G4Material.hh"
#include "G4MaterialTable.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"
#include "G4OpticalSurface.hh"
#include "RichTbRunConfig.hh"
#include "RichTbMaterialParameters.hh"
#include "RichTbSurfaceParameters.hh"
#include <fstream>
#include <vector>
#include <cstdlib>


// local
#include "RichTbSurfaceDefinition.hh"

//-----------------------------------------------------------------------------
// Implementation file for class : RichTbSurfaceDefinition
//
// 2003-11-24 : Sajan EASO
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables
//=============================================================================
RichTbSurfaceDefinition* RichTbSurfaceDefinition::RichTbSurfaceDefinitionInstance=0;

RichTbSurfaceDefinition::RichTbSurfaceDefinition(  )
:  MirrorSurfWlen(std::vector<G4double>(10)),
   MirrorSurfReflect(std::vector<G4double>(10)) {

  // in the above 10 is a dummy value.


  createMirrorOpticalSurface();
  createVesselSurface();
  createPMTQuartzWSurface();
  createPMTQuartzWPhCathodeSurface();
  createRichTbKovarSurface();
  createtRichTbSiDetSurface();


}

RichTbSurfaceDefinition::~RichTbSurfaceDefinition(  ) {

}

RichTbSurfaceDefinition* RichTbSurfaceDefinition::getRichTbSurfaceDefinitionInstance()
{
  if(RichTbSurfaceDefinitionInstance == 0) {
    RichTbSurfaceDefinitionInstance= new RichTbSurfaceDefinition(  );
  }
  return RichTbSurfaceDefinitionInstance;

}


void RichTbSurfaceDefinition::createMirrorOpticalSurface()
{

  ReadMirrorReflectivity();

  // Now for the Spherical mirror surface
 G4double* MirrReflPhotonMomentum
    =new G4double[NumPhotMirrorReflectBins];
 G4double* MirrReflect
    = new G4double[NumPhotMirrorReflectBins];
 G4double* MirrEff
   = new G4double[NumPhotMirrorReflectBins];
 G4double* MirrReflRefIndex
   = new G4double[NumPhotMirrorReflectBins];

 for(G4int ibin=0; ibin<NumPhotMirrorReflectBins;ibin++) {
  MirrReflPhotonMomentum[ibin]=
    PhotWaveLengthToMom/
    ( MirrorSurfWlen[ibin]*PhotonMirrReflWavelengthUnits);
  // in the following the 100 is to convert from percent
  // to absolute fraction.
   MirrReflect[ibin]=  MirrorSurfReflect[ibin]/100.0;
   MirrEff[ibin]=0.0;
   MirrReflRefIndex[ibin]=1.40;

   //  G4cout<<" Mirror reflectivity bin Wlen refl  "<<
   //  ibin<<"   "<< MirrorSurfWlen[ibin] <<" " << MirrReflPhotonMomentum[ibin]
   //    <<"   "<< MirrReflect[ibin]<<G4endl;

 }

 G4OpticalSurface* OpRichTbMirrorSurface =
     new G4OpticalSurface("RichTbMirrorSurface");

   OpRichTbMirrorSurface->SetType(dielectric_metal);
   OpRichTbMirrorSurface->SetFinish(polished);
   OpRichTbMirrorSurface->SetModel(glisur);
   G4MaterialPropertiesTable* OpRichTbMirrorSurfaceMPT =
                            new G4MaterialPropertiesTable();

   OpRichTbMirrorSurfaceMPT->AddProperty("REFLECTIVITY",
                                         MirrReflPhotonMomentum,
                                         MirrReflect,
                                         NumPhotMirrorReflectBins);

   OpRichTbMirrorSurfaceMPT->AddProperty("EFFICIENCY",
                                            MirrReflPhotonMomentum,
                                            MirrEff,
                                            NumPhotMirrorReflectBins);
   OpRichTbMirrorSurfaceMPT->AddProperty("RINDEX",
                                             MirrReflPhotonMomentum,
                                             MirrReflRefIndex,
                                             NumPhotMirrorReflectBins);
   OpRichTbMirrorSurface->SetMaterialPropertiesTable(OpRichTbMirrorSurfaceMPT);

   RichTbSphMirrorSurface=  OpRichTbMirrorSurface;

}




void RichTbSurfaceDefinition::createVesselSurface()
{
  G4int NumPhotVesselSurfaceBins=10;

  G4double VesselSurfacePhotMom[]=
   {1.0 * CLHEP::eV,2.0 * CLHEP::eV, 3.0 * CLHEP::eV,4.0 * CLHEP::eV,5.0 * CLHEP::eV,6.0 * CLHEP::eV,7.0 * CLHEP::eV,8.0 * CLHEP::eV,
    9.0 * CLHEP::eV,10.0 * CLHEP::eV};

   G4double VesselSurfaceReflectivity[]=
   {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
   G4double VesselSurfaceEfficiency[]=
   {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

 G4OpticalSurface* OpVesselSurface=
   new G4OpticalSurface("VesselOpticalSurface");
 OpVesselSurface->SetType(dielectric_metal);
 OpVesselSurface->SetFinish(polished);
 OpVesselSurface->SetModel(glisur);

 G4MaterialPropertiesTable* OpVesselSurfaceMPT =
          new G4MaterialPropertiesTable();

 OpVesselSurfaceMPT->AddProperty("REFLECTIVITY",
                                 VesselSurfacePhotMom,
                                 VesselSurfaceReflectivity,
                                 NumPhotVesselSurfaceBins);


 OpVesselSurfaceMPT->AddProperty("EFFICIENCY",
                                 VesselSurfacePhotMom,
                                 VesselSurfaceEfficiency,
                                 NumPhotVesselSurfaceBins);
 OpVesselSurface->SetMaterialPropertiesTable( OpVesselSurfaceMPT);

 RichTbVesselSurface=  OpVesselSurface;

}

void RichTbSurfaceDefinition::createPMTQuartzWSurface()
{
  G4int NumPhotPMTQuartzWMasterSurfaceWavelengthBins=10;
  G4double PMTQuartzWMasterSurfacePhotMom []=
   {1.0 * CLHEP::eV,2.0 * CLHEP::eV, 3.0 * CLHEP::eV,4.0 * CLHEP::eV,5.0 * CLHEP::eV,6.0 * CLHEP::eV,7.0 * CLHEP::eV,8.0 * CLHEP::eV,
    9.0 * CLHEP::eV,10.0 * CLHEP::eV};
  G4double PMTQuartzWMasterSurfaceReflectivity[]=
    {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

  G4double PMTQuartzWMasterSurfaceEff[]=
    {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
   G4OpticalSurface* OpPMTQuartzWMasterSurface=
     new  G4OpticalSurface("PMTQuartzWMasterSurface");

   OpPMTQuartzWMasterSurface->SetType(dielectric_dielectric);
   OpPMTQuartzWMasterSurface->SetFinish(polished);
   OpPMTQuartzWMasterSurface->SetModel(glisur);
   //   OpPMTQuartzWMasterSurface->SetModel(unified);

   G4MaterialPropertiesTable*  OpPMTQuartzWMasterSurfaceMPT =
           new G4MaterialPropertiesTable();

   OpPMTQuartzWMasterSurfaceMPT ->AddProperty("REFLECTIVITY",
                  PMTQuartzWMasterSurfacePhotMom,
                  PMTQuartzWMasterSurfaceReflectivity,
                  NumPhotPMTQuartzWMasterSurfaceWavelengthBins);

   OpPMTQuartzWMasterSurfaceMPT ->AddProperty( "EFFICIENCY",
                  PMTQuartzWMasterSurfacePhotMom,
                  PMTQuartzWMasterSurfaceEff,
                  NumPhotPMTQuartzWMasterSurfaceWavelengthBins);

    OpPMTQuartzWMasterSurface->
      SetMaterialPropertiesTable(OpPMTQuartzWMasterSurfaceMPT);

    RichTbPMTMasterQuartzWSurface=OpPMTQuartzWMasterSurface;

}

void RichTbSurfaceDefinition::createPMTQuartzWPhCathodeSurface()
{

  G4int  NumPhotQuartzWPhCathodeSurfaceWavelengthBins=10;
  G4double PMTQuartzWPhCathodeSurfaceReflectivity[]=
    {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
  G4double PMTQuartzWPhCathodeSurfaceEff[]=
    {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};
  G4double PMTQuartzWPhCathodeSurfacePhotMom[]=
  {1.0 * CLHEP::eV,2.0 * CLHEP::eV, 3.0 * CLHEP::eV,4.0 * CLHEP::eV,5.0 * CLHEP::eV,6.0 * CLHEP::eV,7.0 * CLHEP::eV,8.0 * CLHEP::eV,
    9.0 * CLHEP::eV,10.0 * CLHEP::eV};

  G4OpticalSurface * OpPMTQuartzWPhCathodeSurface=
            new  G4OpticalSurface("PMTQuartzWPhCathodeSurface");
  OpPMTQuartzWPhCathodeSurface->SetType(dielectric_dielectric);
  OpPMTQuartzWPhCathodeSurface->SetFinish(polished);
  OpPMTQuartzWPhCathodeSurface->SetModel(glisur);

  G4MaterialPropertiesTable* OpPMTQuartzWPhCathodeSurfaceMPT=
           new G4MaterialPropertiesTable();

  OpPMTQuartzWPhCathodeSurfaceMPT->AddProperty("REFLECTIVITY",
            PMTQuartzWPhCathodeSurfacePhotMom,
            PMTQuartzWPhCathodeSurfaceReflectivity,
            NumPhotQuartzWPhCathodeSurfaceWavelengthBins);

  OpPMTQuartzWPhCathodeSurfaceMPT->AddProperty("EFFICIENCY",
            PMTQuartzWPhCathodeSurfacePhotMom,
            PMTQuartzWPhCathodeSurfaceEff,
            NumPhotQuartzWPhCathodeSurfaceWavelengthBins);

  OpPMTQuartzWPhCathodeSurface->
   SetMaterialPropertiesTable(OpPMTQuartzWPhCathodeSurfaceMPT);

  RichTbPMTQuartzWPhCathodeSurface= OpPMTQuartzWPhCathodeSurface;

}

void RichTbSurfaceDefinition::ReadMirrorReflectivity() {


  RichTbRunConfig* aRunConfig= RichTbRunConfig::getRunConfigInstance();
  G4String MirrorFname= aRunConfig->getMirrorReflFileName();
  G4cout<<" MirrorReflectivity being read from   "<<MirrorFname<<G4endl;
  MirrorSurfWlen.clear();
  MirrorSurfReflect.clear();
  G4int numbinrefl=0;
  // the -1 above is to take care of the addtional 1 which
  // happens when closing the while loop.
  const char* MirrorDataFileNameChar= MirrorFname.c_str();
  std::ifstream finpfa(MirrorDataFileNameChar );
  if(!finpfa) {
    G4cout<<"Mirror Reflectivity data file  cannot be opened " <<
           "  Please check the file names and paths "<<G4endl;
  } else {
      G4double wa=0.0;
      G4double rf=0.0;
      while(!finpfa.eof()) {
       finpfa>>wa;
       finpfa>>rf;
       numbinrefl++;

       MirrorSurfWlen.push_back(wa);
       MirrorSurfReflect.push_back(rf);

      }

      // remove the last bin since it is a repeat of the previous bin.

      G4int aSize= G4int (MirrorSurfWlen.size());
      if(MirrorSurfWlen[aSize-1] ==MirrorSurfWlen[aSize-2] ) {
        MirrorSurfWlen.pop_back();
	MirrorSurfReflect.pop_back();
        numbinrefl--;

      }

      //      G4cout<<"Numbins in Mirr file "<<numbinrefl
      //	    <<"  "<<G4int( MirrorSurfWlen.size()) <<G4endl;

      //  G4cout<<"Now adding the bins in Mirror Refl "<<G4endl;
      // it assumes that in the data file,  the order
      // is set with highest wavelength to lower wavelengths.

      if(MirrorSurfWlen.front() >  0.0 ) {
        G4double MirrFirstMom=PhotWaveLengthToMom/
            ((MirrorSurfWlen.front())* PhotonMirrReflWavelengthUnits) ;
	  if(MirrFirstMom >   PhotonMinEnergy ){
            numbinrefl++;
	    G4double PhotonMaxWlen=
        PhotMomToWaveLength/(PhotonMinEnergy* CLHEP::nanometer);

	    MirrorSurfWlen.insert( MirrorSurfWlen.begin(), PhotonMaxWlen);
	MirrorSurfReflect.insert(MirrorSurfReflect.begin(),
				 MirrorSurfReflect.front());

	  }


      }

      if( MirrorSurfWlen.back()  > 0.0 ) {
        G4double MirrLastMom=PhotWaveLengthToMom/
	  ((MirrorSurfWlen.back())* PhotonMirrReflWavelengthUnits);
        if(MirrLastMom <  PhotonMaxEnergy ) {
            numbinrefl++;
            G4double PhotonMinWlen=
	      PhotMomToWaveLength/( PhotonMaxEnergy* CLHEP::nanometer);
	    MirrorSurfWlen.push_back(PhotonMinWlen);
            MirrorSurfReflect.push_back( MirrorSurfReflect.back());
	      }

      }

      NumPhotMirrorReflectBins= numbinrefl;
      reverse(MirrorSurfWlen.begin(),MirrorSurfWlen.end());
      reverse(MirrorSurfReflect.begin(),MirrorSurfReflect.end());


      // test print
      /*
      G4cout<<"Numbins for Mirror refl "<<NumPhotMirrorReflectBins<<G4endl;

        for(G4int ii=0; ii<NumPhotMirrorReflectBins; ii++ ) {
        G4cout<<"Mirr "<<MirrorSurfWlen[ii]<<"   "
          <<MirrorSurfReflect[ii]
              <<G4endl;
        }

      */

      //end of test print.


    G4cout<<"End of reading Mirror reflectivity"<<G4endl;
  }

}

void RichTbSurfaceDefinition::createRichTbKovarSurface() {

   G4int NumPhotKovarSurfaceBins=12;

  G4double KovarSurfacePhotMom[]=
   {0.01 * CLHEP::eV, 1.0 * CLHEP::eV,2.0 * CLHEP::eV, 3.0 * CLHEP::eV,4.0 * CLHEP::eV,5.0 * CLHEP::eV,6.0 * CLHEP::eV,7.0 * CLHEP::eV,8.0 * CLHEP::eV,
    9.0 * CLHEP::eV,10.0 * CLHEP::eV,11 * CLHEP::eV};

   G4double KovarSurfaceReflectivity[]=
   {0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05};
   G4double KovarSurfaceEfficiency[]=
   {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

 G4OpticalSurface* OpKovarSurface=
   new G4OpticalSurface("KovarOpticalSurface");
 OpKovarSurface->SetType(dielectric_dielectric);
 OpKovarSurface->SetFinish(groundfrontpainted);
 OpKovarSurface->SetModel(glisur);

 G4MaterialPropertiesTable* OpKovarSurfaceMPT =
          new G4MaterialPropertiesTable();

 OpKovarSurfaceMPT->AddProperty("REFLECTIVITY",
                                 KovarSurfacePhotMom,
                                 KovarSurfaceReflectivity,
                                 NumPhotKovarSurfaceBins);


 OpKovarSurfaceMPT->AddProperty("EFFICIENCY",
                                 KovarSurfacePhotMom,
                                 KovarSurfaceEfficiency,
                                 NumPhotKovarSurfaceBins);
 OpKovarSurface->SetMaterialPropertiesTable(OpKovarSurfaceMPT);

 RichTbKovarSurface =  OpKovarSurface;

}

void   RichTbSurfaceDefinition::createtRichTbSiDetSurface(){

  RichTbRunConfig* aRunConfig= RichTbRunConfig::getRunConfigInstance();
  G4int aSiReflFlag= aRunConfig-> getPMTSiReflFlag();

   G4int NumPhotSiDetSurfaceBins=13;


  G4double SiDetSurfacePhotMom[]=
   {0.01 * CLHEP::eV, 1.0 * CLHEP::eV,2.0 * CLHEP::eV, 2.5 * CLHEP::eV, 3.0 * CLHEP::eV,4.0 * CLHEP::eV,5.0 * CLHEP::eV,6.0 * CLHEP::eV,7.0 * CLHEP::eV,8.0 * CLHEP::eV,9.0 * CLHEP::eV,10.0 * CLHEP::eV,11 * CLHEP::eV};
  G4double SiDetSurfaceReflectivity[]=
   {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};



  // For now using 30% reflectivity. The use of this may be refined in the
  // future using more bins of the QE and disentagling the transmission
  // in photocathode vs reflection in Si etc.
  if(aSiReflFlag >0 ) {
    for(G4int ib=0; ib< NumPhotSiDetSurfaceBins;ib++) {
      SiDetSurfaceReflectivity[ib]=PMTSiDetSurfaceReflectivity;

    }

  }


   G4double SiDetSurfaceEfficiency[]=
   {0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0};

   G4double* SiDetReflRefIndex
   = new G4double[NumPhotSiDetSurfaceBins];

 for(G4int ibind=0; ibind<NumPhotSiDetSurfaceBins;ibind++) {
   SiDetReflRefIndex[ibind]=1.40;
 }
 G4OpticalSurface* OpSiDetSurface=
   new G4OpticalSurface("SiDetOpticalSurface");
 OpSiDetSurface->SetType(dielectric_metal);
 OpSiDetSurface->SetFinish(polished);
 OpSiDetSurface->SetModel(glisur);

 G4MaterialPropertiesTable* OpSiDetSurfaceMPT =
          new G4MaterialPropertiesTable();

 OpSiDetSurfaceMPT->AddProperty("REFLECTIVITY",
                                 SiDetSurfacePhotMom,
                                 SiDetSurfaceReflectivity,
                                 NumPhotSiDetSurfaceBins);


 OpSiDetSurfaceMPT->AddProperty("EFFICIENCY",
                                 SiDetSurfacePhotMom,
                                 SiDetSurfaceEfficiency,
                                 NumPhotSiDetSurfaceBins);

 OpSiDetSurfaceMPT->AddProperty("RINDEX",
                                 SiDetSurfacePhotMom,
				 SiDetReflRefIndex,
                                 NumPhotSiDetSurfaceBins );


 OpSiDetSurface->SetMaterialPropertiesTable(OpSiDetSurfaceMPT);

 RichTbSiDetSurface =  OpSiDetSurface;

}
//=============================================================================
