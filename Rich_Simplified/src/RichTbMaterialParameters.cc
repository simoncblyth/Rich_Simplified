// Geant 4
#include "globals.hh"

// STL etc
#include <iostream>
#include <vector>
#include <cmath>

// local
#include "RichTbMaterialParameters.hh"
#include "RichTbGeometryParameters.hh"


void InitializeRichTbMaterial()
{
	//Setup a switch between the various parametrizations of the
	// ref index.
}
void HistoRichMaterialProperty() {
	//histogram the material properties.

	//  G4cout<<" Now in histo material Property "<<G4endl;



}


std::vector<G4double> InitializePhotonMomentumVector() {

	G4double PhotonEnergyStep=(PhotonMaxEnergy-PhotonMinEnergy)/
			NumPhotWaveLengthBins;
	std::vector<G4double>PhotMomVect(NumPhotWaveLengthBins);
	for (G4int ibin=0; ibin<NumPhotWaveLengthBins; ibin++){
		PhotMomVect[ibin]=PhotonMinEnergy+PhotonEnergyStep*ibin;
	}
	return PhotMomVect;
}

G4double FresnelLossAtNormalIncidence(G4double RIndex1, G4double RIndex2 )
{
	G4double ALoss=0.0;

	if(RIndex1 >= 1.0 && RIndex2 >= 1.0) {

		ALoss= pow(((RIndex2- RIndex1)/( RIndex2+ RIndex1)),2.0);

	}
	return ALoss;

}

std::vector<G4double> InitN2RefIndex(G4double pressure, G4double temperature){

	G4int NumWLenBins=NumPhotWaveLengthBins;
	std::vector<G4double> PmV = InitN2RefPhotMom();
	std::vector<G4double> RefN2( NumPhotWaveLengthBins);

	// G4cout<<" RichTbmaterial Parameters Nitrogen GasPressure stppressure temp stptemp "
	//      << pressure <<"  "<<GasPressure_STP<<"   "
	//      << temperature<<"   "<<GasTemperature_STP<<G4endl;


	G4double GasRhoN2Cur=GasRhoN2atSTP*(GasTemperature_STP/temperature)*
			(pressure/ GasPressure_STP);

	//  G4cout<<" RichTbmaterial Parameters N2densitySTP N2Curdensity " <<GasRhoN2atSTP
	//	<<  "   "<<  GasRhoN2Cur<<G4endl;


	G4double epho,pfe,cpfe;
	for(G4int ibinwn =0; ibinwn<NumWLenBins ; ibinwn++ ){

		epho = PmV[ibinwn]/(CLHEP::eV);
		pfe  = SellN2F1/(SellN2E1*SellN2E1 - epho*epho )  +
				SellN2F2/(SellN2E2*SellN2E2 - epho*epho );
		cpfe=0.3738*(GasRhoN2Cur/GasMolWeightN2)*pfe;
		RefN2[ibinwn]=pow((1.0+2*cpfe)/(1.0-cpfe),0.5);
    //	   G4cout<<" N2 ref index "<< ibinwn<<"  "<<epho<<"   "<<PhotMomWaveConv/ epho
		//      <<"     "<<RefN2[ibinwn]<<G4endl;

	}

	return RefN2;
}

G4double N2RefIndexAtAnEnergy( G4double pressure, G4double temperature,
		G4double PhotonEnergy)
{
	G4double curRefIndex=1.0;

	G4double GasRhoN2Cur=GasRhoN2atSTP*(GasTemperature_STP/temperature)*
			(pressure/ GasPressure_STP);
	G4double epho=0.0;
	G4double pfe=0.0;
	G4double cpfe=0.0;


	epho = PhotonEnergy/(CLHEP::eV);
	pfe  = SellN2F1/(SellN2E1*SellN2E1 - epho*epho )  +
			SellN2F2/(SellN2E2*SellN2E2 - epho*epho );
	cpfe=0.3738*(GasRhoN2Cur/GasMolWeightN2)*pfe;

	curRefIndex=pow((1.0+2*cpfe)/(1.0-cpfe),0.5);

	return curRefIndex;

}


std::vector<G4double> InitN2RefPhotMom() {
	return InitializePhotonMomentumVector() ;
}
std::vector<G4double> Initc4f10RefPhotMom() {
	return InitializePhotonMomentumVector() ;
}

std::vector<G4double> CrystalRefPhotMom() {
	return InitializePhotonMomentumVector() ;
}

std::vector<G4double> Initc4f10RefIndex(G4double pressure, G4double temperature){

	G4int NumWLenBins=NumPhotWaveLengthBins;
	std::vector<G4double> PmV = Initc4f10RefPhotMom();
	std::vector<G4double> RefC4F10( NumPhotWaveLengthBins);

	//  G4cout<<" RichTbmaterial Parameters c4f10GasPressure stppressure temp stptemp "
	//      << pressure <<"  "<<GasPressure_STP<<"   "
	//      << temperature<<"   "<<GasTemperature_STP<<G4endl;


	G4double GasRhoC4F10Cur=GasRhoC4F10atSTP*(GasTemperature_STP/temperature)*
			(pressure/ GasPressure_STP);

	G4double epho=0.0;
	G4double pfe=0.0;
	G4double cpfe=0.0;

	for(G4int ibinwn =0; ibinwn<NumWLenBins ; ibinwn++ ){

		epho = PmV[ibinwn]/(CLHEP::eV);
		pfe  = SellC4F10F1/(SellC4F10E1*SellC4F10E1 - epho*epho )  +
				SellC4F10F2/(SellC4F10E2*SellC4F10E2 - epho*epho );
		cpfe=0.3738*(GasRhoC4F10Cur/GasMolWeightC4F10)*pfe;
		RefC4F10[ibinwn]  = pow((1.0+2*cpfe)/(1.0-cpfe),0.5);
	}
	return RefC4F10;
}

G4double c4f10RefIndexAtAnEnergy(G4double pressure, G4double temperature ,
		G4double PhotonEnergy){

	G4double curRefIndex=1.0;

	G4cout<<" RichTbmaterial Parameters c4f10GasPressure stppressure temp stptemp "
			<< pressure <<"  "<<GasPressure_STP<<"   "
			<< temperature<<"   "<<GasTemperature_STP<<G4endl;


	G4double GasRhoC4F10Cur=GasRhoC4F10atSTP*(GasTemperature_STP/temperature)*
			(pressure/ GasPressure_STP);

	G4double epho=0.0;
	G4double pfe=0.0;
	G4double cpfe=0.0;

	epho = PhotonEnergy/(CLHEP::eV);

	pfe  = SellC4F10F1/(SellC4F10E1*SellC4F10E1 - epho*epho )  +
			SellC4F10F2/(SellC4F10E2*SellC4F10E2 - epho*epho );
	cpfe=0.3738*(GasRhoC4F10Cur/GasMolWeightC4F10)*pfe;
	curRefIndex = pow((1.0+2*cpfe)/(1.0-cpfe),0.5);

	return curRefIndex ;
}
std::vector<G4double>  InitializePMTWaveL(G4int /* ipmtnum */)
						{
	// for now it is the same wavlength bins for all pmts.

	std::vector<G4double>PmtQEW(PmtQENumBins);
	for (G4int iqb=0; iqb<PmtQENumBins; iqb++){
		PmtQEW[iqb]= PmtQEWaveLen [iqb]*PmtQEWaveLenUnits;
	}
	return PmtQEW;

						}
std::vector<G4double>  InitializePMTQE(G4int ipmtqe) {

        RichTbRunConfig* rConfig = RichTbRunConfig::getRunConfigInstance();
        G4int aRadiatorConfiguration = rConfig ->getRadiatorConfiguration();

	G4double PmtQEReductionFactor =1.;
	//  if(ihpdqe >= 2 ) {
	//   G4cout<<"Wrong HPD Number for QE " <<ihpdqe<<"  vs "
	//      <<NumPMTs <<G4endl;
	// }

	std::vector<G4double>qeCurPerCent( PmtQENumBins);

  if(aRadiatorConfiguration==7){
        PmtQEReductionFactor = 100.0; // to convert QEs to percentages

	if(ipmtqe == 0 ){
		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  EC3PMT1QE_2017[iqb]* PmtQEReductionFactor;
	    //   G4cout<<"Now fill the QE for PMT0"<<G4endl;
		}

	}else if( ipmtqe == 1 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC3PMT2QE_2017[iqb]* PmtQEReductionFactor;
	    //  G4cout<<"Now fill the QE for PMT1"<<G4endl;
		}
	}else if( ipmtqe == 2 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC3PMT0QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 3){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC3PMT3QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 4 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC2PMT1QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 5 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC2PMT2QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 6 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC2PMT1QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 7 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC2PMT3QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 8 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC1PMT1QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe ==9 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC1PMT2QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 10 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC1PMT0QE_2017[iqb]* PmtQEReductionFactor;
	    // G4cout<<"Now fill the QE for PMT10, pixel number :"<<iqb<< "  eff :"<<EC2PMT3QE_2017[iqb] <<G4endl;
		}
	}else if( ipmtqe == 11 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
		  qeCurPerCent[iqb] = EC1PMT3QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 12 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC0PMT1QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 13 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC0PMT2QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 14){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC0PMT0QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 15 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC0PMT3QE_2017[iqb]* PmtQEReductionFactor;
		}
	}

	/*
	if(ipmtqe == 0 ){
		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  EC3PMT1QE_2017[iqb]* PmtQEReductionFactor;
	    //   G4cout<<"Now fill the QE for PMT0"<<G4endl;
		}

	}else if( ipmtqe == 1 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC3PMT2QE_2017[iqb]* PmtQEReductionFactor;
	    //  G4cout<<"Now fill the QE for PMT1"<<G4endl;
		}
	}else if( ipmtqe == 2 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC3PMT0QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 3 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC3PMT3QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 4 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC2PMT1QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 5 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC2PMT2QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 6 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC2PMT1QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 7 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC2PMT3QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 8 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC1PMT1QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 9 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC1PMT2QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 10 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC1PMT0QE_2017[iqb]* PmtQEReductionFactor;
	    // G4cout<<"Now fill the QE for PMT10, pixel number :"<<iqb<< "  eff :"<<EC2PMT3QE_2017[iqb] <<G4endl;
		}
	}else if( ipmtqe == 11 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC1PMT3QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 12 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC0PMT1QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 13 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC0PMT2QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 14 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC0PMT0QE_2017[iqb]* PmtQEReductionFactor;
		}
	}else if( ipmtqe == 15 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] = EC0PMT3QE_2017[iqb]* PmtQEReductionFactor;
		}
	}
	*/
 }else{


	if(ipmtqe == 0 ){
		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt0QEPerCent[iqb]* PmtQEReductionFactor;
		}


	}else if( ipmtqe == 1 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt1QEPerCent[iqb]* PmtQEReductionFactor;
		}

	}else if( ipmtqe == 2 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt2QEPerCent[iqb]* PmtQEReductionFactor;
		}

	} else if ( ipmtqe == 3 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt3QEPerCent[iqb]* PmtQEReductionFactor;
		}


	} else if ( ipmtqe == 4 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt4QEPerCent[iqb]* PmtQEReductionFactor;
		}

	}else if ( ipmtqe == 5 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt5QEPerCent[iqb]* PmtQEReductionFactor;
		}


	}else if ( ipmtqe == 6 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt6QEPerCent[iqb]* PmtQEReductionFactor;
		}


	}else if ( ipmtqe == 7 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt7QEPerCent[iqb]* PmtQEReductionFactor;
		}

	}else if( ipmtqe == 8 ){
		for(G4int  iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt8QEPerCent[iqb]* PmtQEReductionFactor;
		}

	}else if( ipmtqe == 9 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt9QEPerCent[iqb]* PmtQEReductionFactor;
		}

	} else if ( ipmtqe == 10 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt1QEPerCent[iqb]* PmtQEReductionFactor;
		}


	} else if ( ipmtqe == 11 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt11QEPerCent[iqb]* PmtQEReductionFactor;
		}

	}else if ( ipmtqe == 12 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt12QEPerCent[iqb]* PmtQEReductionFactor;
		}


	}else if ( ipmtqe == 13 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt13QEPerCent[iqb]* PmtQEReductionFactor;
		}


	}else if ( ipmtqe == 14 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt14QEPerCent[iqb]* PmtQEReductionFactor;
		}

	}else if ( ipmtqe == 15 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt15QEPerCent[iqb]* PmtQEReductionFactor;
		}


	}else if (ipmtqe == 16 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt16QEPerCent[iqb]* PmtQEReductionFactor;
		}

	}else if ( ipmtqe == 17 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt17QEPerCent[iqb]* PmtQEReductionFactor;
		}
	
	}else if (ipmtqe == 18 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt18QEPerCent[iqb]* PmtQEReductionFactor;
		}
	}else if (ipmtqe == 19 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt19QEPerCent[iqb]* PmtQEReductionFactor;
		}

	}else if (ipmtqe == 20 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt20QEPerCent[iqb]* PmtQEReductionFactor;
		}

	}else if (ipmtqe == 21 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt21QEPerCent[iqb]* PmtQEReductionFactor;
		}

	}else if (ipmtqe == 22 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt22QEPerCent[iqb]* PmtQEReductionFactor;
		}
	
	}else if (ipmtqe == 23 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt23QEPerCent[iqb]* PmtQEReductionFactor;
		}

	}else if (ipmtqe == 24 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt24QEPerCent[iqb]* PmtQEReductionFactor;
		}

	}else if (ipmtqe == 25 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt25QEPerCent[iqb]* PmtQEReductionFactor;
		}
	}else if (ipmtqe == 26 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt26QEPerCent[iqb]* PmtQEReductionFactor;
		}
	}else if (ipmtqe == 27 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt27QEPerCent[iqb]* PmtQEReductionFactor;
		}
	}else if (ipmtqe == 28 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt28QEPerCent[iqb]* PmtQEReductionFactor;
		}
	}else if (ipmtqe == 29 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt29QEPerCent[iqb]* PmtQEReductionFactor;
		}
	}else if (ipmtqe == 30 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt30QEPerCent[iqb]* PmtQEReductionFactor;
		}
	}else if (ipmtqe == 31 ){

		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
            qeCurPerCent[iqb] =  Pmt31QEPerCent[iqb]* PmtQEReductionFactor;
		}
	
	}
  }







//	else if ( ipmtqe == 16 ){
//
//		for(G4int iqb=0; iqb< PmtQENumBins ; iqb++){
//			qeCurPerCent[iqb] =  Pmt16QEPerCent[iqb]* PmtQEReductionFactor;
//		}
//
//	}



	return  qeCurPerCent;

}

std::vector<G4double>  InitializeHpdQE(G4int ihpdqe) {

	G4double HpdQEReductionFactor =1.;
	std::vector<G4double>qeCurPerCent( HpdQENumBins);
	if(ihpdqe == 0 ){
		for(G4int iqa=0; iqa< HpdQENumBins ; iqa++){
			qeCurPerCent[iqa] =  Hpd0QEPerCent[iqa]* HpdQEReductionFactor;
		}

	}


	return  qeCurPerCent;


}

std::vector<G4double>  InitializeHpdWaveL(G4int /* ipmtnum */)
						{
	// for now it is the same wavlength bins for all pmts.

	std::vector<G4double>HpdQEW(HpdQENumBins);
	for (G4int iqb=0; iqb<HpdQENumBins; iqb++){
		HpdQEW[iqb]= HpdQEWaveLen [iqb]*HpdQEWaveLenUnits;
	}
	return HpdQEW;

						}


