// Include files


#include <iostream>
#include "globals.hh"
#include "Randomize.hh"
#include <cstdlib>
#include <fstream>
#include <sstream>

// local
#include "RichTbPmtPixelEfficiency.hh"
#include "RichTbGeometryParameters.hh"
#include "RichTbRunConfig.hh"


//-----------------------------------------------------------------------------
// Implementation file for class : RichTbPmtPixelEfficiency
//
// 2015-03-11 : Sajan Easo
// 2015-06-27 : Michele Blago modified for 2015 testbeam
//-----------------------------------------------------------------------------

//=============================================================================
// Standard constructor, initializes variables

RichTbPmtPixelEfficiency* RichTbPmtPixelEfficiency::RichTbPmtPixelEfficiencyInstance=0;


//=============================================================================
RichTbPmtPixelEfficiency::RichTbPmtPixelEfficiency(  ):
				  mPmtPixelEff (8,std::vector<G4double> (64)),
				  mPmtPixelLabel(8,std::vector<G4String> (64)) {

	PmtPixelEffInitialize();


}

void RichTbPmtPixelEfficiency::PmtPixelEffInitialize() {

	// The following line does not work.
	// mPmtPixelEff.resize(RichTbTotNumPmt, std::vector<G4double> (NumPixelTotInPmt, 1.0)  );
	RichTbRunConfig* aConfig = RichTbRunConfig::  getRunConfigInstance();
	G4int aRadiatorConfiguration = aConfig ->getRadiatorConfiguration();

	if ( (aRadiatorConfiguration == 3) || ( aRadiatorConfiguration == 6) || (aRadiatorConfiguration == 7) ) {
    RichTbTotNumPmtFinal = RichTbTotNumPmt15;
	}else { 
    RichTbTotNumPmtFinal = RichTbTotNumPmt; 
  }
  

	mPmtPixelEff.resize(RichTbTotNumPmtFinal);
	mPmtPixelLabel.resize(RichTbTotNumPmtFinal);

	std::vector<G4double> aEffInit (NumPixelTotInPmt, 1.0);
	std::vector<G4String> aLabelnit (NumPixelTotInPmt, "JU00");

	for (G4int ipmt =0; ipmt <RichTbTotNumPmtFinal ; ++ipmt){
		mPmtPixelEff [ipmt]= aEffInit;
		mPmtPixelLabel[ipmt]= aLabelnit;
	}

	std::vector <G4String> aPL(RichTbTotNumPmtFinal,"JA");
	aPL[1]="JA";
	aPL[1]="JA";
	aPL[2]="JB";
	aPL[3]="JB";
	aPL[4]="SA";
	aPL[5]="SA";
	aPL[6]="SB";
	aPL[7]="SB";
	if(RichTbTotNumPmtFinal==RichTbTotNumPmt15) {
		aPL[8]="JAB";
		aPL[9]="JAB";
		aPL[10]="JBB";
		aPL[11]="JBB";
		aPL[12]="SAB";
		aPL[13]="SAB";
		aPL[14]="SBB";
		aPL[15]="SBB";
	}

	for (G4int ipm =0; ipm <RichTbTotNumPmtFinal ; ++ipm) {
		for ( G4int ipx =0 ; ipx <NumPixelTotInPmt; ++ipx ) {
			mPmtPixelLabel[ipm] [ipx] = aPL[ipm] + std::to_string(ipx+1);
		}
	}

	ReadPixelEfficiency();
	FillPixelEfficiency();

}

G4bool RichTbPmtPixelEfficiency::PmtPixelEffOK (G4int aPmtNum, G4int aPixelNum) {
	RichTbRunConfig* aRunConfig =  RichTbRunConfig::getRunConfigInstance();
	G4bool aEffFlag = true;
	if(aRunConfig ->ApplyPixelEff() ) {
		G4double curEff = getPixelEff (aPmtNum,aPixelNum);
		G4double RandPx =  G4UniformRand();
		if ( RandPx >  curEff )aEffFlag = false;
		// G4cout<<" PmtPixelEfficiency CurEff randpx flag "<<  curEff <<"  "<< RandPx <<"  "<<aEffFlag<<G4endl;


	}
	return  aEffFlag;

}


void RichTbPmtPixelEfficiency::FillPixelEfficiency() {
	RichTbRunConfig* aRunConfig =  RichTbRunConfig::getRunConfigInstance();
	G4int aEffFlag = aRunConfig-> MapmtPixelEfficiencyFlag ();
	if(aEffFlag  != 0 ){
		for (G4int ipm =0; ipm <RichTbTotNumPmtFinal ; ++ipm) {
			for ( G4int ipx =0 ; ipx <NumPixelTotInPmt; ++ipx ) {
				G4double aEff = mPmtAnodeEffMap.find( mPmtPixelLabel[ipm][ipx] )->second ;
				mPmtPixelEff [ipm] [ipx]= aEff;
				//     G4cout<<" Pmt Pixel Label eff  "<< ipm <<"  "<<ipx <<"   "
				//      << mPmtPixelLabel[ipm][ipx] <<"   "<<aEff<<G4endl;


			}

		}

	}

}





void RichTbPmtPixelEfficiency::ReadPixelEfficiency() {
	RichTbRunConfig* aRunConfig =  RichTbRunConfig::getRunConfigInstance();
	G4int aEffFlag = aRunConfig-> MapmtPixelEfficiencyFlag ();
	G4int aRadiatorConfiguration = aRunConfig->getRadiatorConfiguration();
	G4String aJuraFileName;
	G4String aSaleveFileName;
	G4String aJuraFileNameUpgr;
	G4String aSaleveFileNameUpgr;
	G4String aJuraTop100;
	G4String aJuraBottom100;
	G4String aSaleveTop100;
	G4String aSaleveBottom100;


	if(aEffFlag  != 0 ){

		if( aEffFlag   == 1 ) { // read the optimized effiency

			aJuraFileName = aRunConfig->MapmtPixelOptEffFileNameJura();
			aSaleveFileName = aRunConfig->MapmtPixelOptEffFileNameSaleve() ;


		}else if ( aEffFlag   == 2 ) { // read the thrshold7 efficiency

			aJuraFileName = aRunConfig->MapmtPixelThr7EffFileNameJura() ;
			aSaleveFileName = aRunConfig->MapmtPixelThr7EffFileNameSaleve() ;

		}

		aJuraFileNameUpgr = aRunConfig->MapmtPixelOptEffFileNameJuraUpgr();
		aSaleveFileNameUpgr = aRunConfig->MapmtPixelOptEffFileNameSaleveUpgr();

		aJuraTop100 = aRunConfig->MapmtPixelEffFileNameJuraTop100();
		aJuraBottom100 = aRunConfig->MapmtPixelEffFileNameJuraBottom100();
		aSaleveTop100 = aRunConfig->MapmtPixelEffFileNameSaleveTop100();
		aSaleveBottom100 = aRunConfig->MapmtPixelEffFileNameSaleveBottom100();

		G4cout<<" Now reading Pmt pixel efficiency files "
				<< aJuraFileName <<"\n"
				<< aSaleveFileName<<"\n"
				<< aJuraFileNameUpgr<<"\n"
				<< aSaleveFileNameUpgr<<"\n"
				<< aJuraTop100<<"\n"
				<< aJuraBottom100<<"\n"
				<< aSaleveTop100<<"\n"
				<< aSaleveBottom100<<G4endl;

		mPmtAnodeEffMap.clear();


//		ReadAndCopyPixelEffFromFile(aJuraFileName);
//		ReadAndCopyPixelEffFromFile(aSaleveFileName);
		ReadAndCopyPixelEffFromFile(aJuraTop100);
		ReadAndCopyPixelEffFromFile(aSaleveTop100);
		if( (aRadiatorConfiguration==3)|| (aRadiatorConfiguration==6) || (aRadiatorConfiguration==7) ) {//testbeam 2015 upgrade dummy refls
			//			ReadAndCopyPixelEffFromFile(aJuraFileNameUpgr);
			//			ReadAndCopyPixelEffFromFile(aSaleveFileNameUpgr);
			ReadAndCopyPixelEffFromFile(aJuraBottom100);
			ReadAndCopyPixelEffFromFile(aSaleveBottom100);
		}
	}

}


void  RichTbPmtPixelEfficiency::ReadAndCopyPixelEffFromFile(G4String aInpFileName  ) {

	const char* aFileName_char = aInpFileName.c_str();
	std::ifstream aInpFileStr (aFileName_char);
	if( !aInpFileStr ) {
		G4cout<<" Unable to read from "<<aInpFileName  <<G4endl;

	}else {



		G4String aAnodeName="AnodeName";
		G4String ClaroNumberS = "0";
		G4String ClaroChanNumS = "0";
		G4String aPmtEffS = "1.0";
		G4double aPmtEff =1.0;
		G4int NumItemsPerLine=4;
		G4String HeaderName_PixelName,HeaderName_ClaroNum,HeaderName_ClaroChanNum, HeaderName_Eff;

		G4int curLineNum=-1;
		std::vector<G4String>line_record;

		while  (aInpFileStr ) {
			std::string aLine;
			if(!std::getline (aInpFileStr , aLine) ) break;
			curLineNum++;
			std::istringstream ss(aLine);
			line_record.clear();
			line_record.reserve(NumItemsPerLine);

			while (ss) {
				std::string aWord;
				if(!std::getline(ss,aWord,','))break;
				line_record.push_back(aWord);
			}

			if(curLineNum == 0 ) {
				HeaderName_PixelName=line_record[0];
				HeaderName_ClaroNum=line_record[1];
				HeaderName_ClaroChanNum=  line_record[2];
				HeaderName_Eff =line_record[3];

				// G4cout<<"FileHeader "<<HeaderName_PixelName  <<"  "<<HeaderName_ClaroNum<<"  "
				//             << HeaderName_ClaroChanNum<<"  "<<HeaderName_Eff<<G4endl;


			}else {
				aAnodeName = line_record[0];
				ClaroNumberS = line_record[1];
				ClaroChanNumS  = line_record[2];
				aPmtEffS = line_record[3];
				aPmtEff = atof( aPmtEffS.c_str());

				//  G4cout<<" Reading Anode name claronum clarochan eff "<< aAnodeName<<"  "
				//      <<ClaroNumberS<<"  "<<ClaroChanNumS<<"  "<<aPmtEff<<G4endl;

				mPmtAnodeEffMap.insert(std::make_pair(aAnodeName,aPmtEff));

			}
		}
	}
}




//=============================================================================
// Destructor
//=============================================================================
RichTbPmtPixelEfficiency::~RichTbPmtPixelEfficiency() { ;}

//=============================================================================

RichTbPmtPixelEfficiency*  RichTbPmtPixelEfficiency::getRichTbPmtPixelEfficiencyInstance() {
	if(RichTbPmtPixelEfficiencyInstance == 0 ) {
		RichTbPmtPixelEfficiencyInstance = new RichTbPmtPixelEfficiency();
	}

	return RichTbPmtPixelEfficiencyInstance;

}
