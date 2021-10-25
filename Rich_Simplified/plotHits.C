#include <TGraph2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void plotHits() {
    TCanvas *c = new TCanvas("c","Hits collected by Opticks and Geant4",0, 0, 1000, 600);
    c->Divide(2,1);

    TGraph2D *ophits = new TGraph2D();
    TGraph *ophits_yz = new TGraph();
    ifstream fophits("build/Opticks_hits.txt", ios::in);
    char line[128];
    int N = 0;
    double x, y, z;
    while(fophits.getline(line,sizeof(line))) {
        stringstream word(line);
	word >> x; word >> y; word >> z;
	cout << N << " " << x << " " << y << " " << z << endl;
	ophits->SetPoint(N,x,y,z);
	ophits_yz->SetPoint(N,y,z);
	N+=1;
    }
    
    TGraph2D *g4hits = new TGraph2D();
    TGraph *g4hits_yz = new TGraph();
    ifstream fg4hits("build/Geant4_hits.txt", ios::in);
    N = 0;
    while(fg4hits.getline(line,sizeof(line))) {
        stringstream word(line);
	word >> x; word >> y; word >> z;
	g4hits->SetPoint(N,x,y,z);
	g4hits_yz->SetPoint(N,y,z);
    	N+=1;
    }
    
    c->cd(1);
    ophits->Draw("P");
    ophits->SetMarkerStyle(20);
    ophits->SetMarkerColor(kRed);
    ophits->SetTitle("Opticks");
    ophits->GetXaxis()->SetTitle("x");
    ophits->GetYaxis()->SetTitle("y");
    ophits->GetZaxis()->SetTitle("z");
    g4hits->Draw("same P");
    g4hits->SetMarkerStyle(20);
    g4hits->SetMarkerColor(kBlue);
    g4hits->SetTitle("Geant4");
    //c->BuildLegend();
    //c->SetTitle("Hits collected by Opticks and Geant4");
    ophits->SetTitle("Hits collected by Opticks and Geant4");
    
    c->cd(2);
    cout << ophits_yz->GetN() << endl;
    ophits_yz->Draw("AP");
    ophits_yz->SetMarkerStyle(20);
    ophits_yz->SetMarkerColor(kRed);
    ophits_yz->SetTitle("Opticks");
    ophits_yz->GetXaxis()->SetTitle("y");
    ophits_yz->GetYaxis()->SetTitle("z");
    g4hits_yz->Draw("same P");
    g4hits_yz->SetMarkerStyle(20);
    g4hits_yz->SetMarkerColor(kBlue);
    g4hits_yz->SetTitle("Geant4");
    ophits_yz->SetTitle("Hits collected by Opticks and Geant4 in y-z projection");
   
    auto leg = new TLegend(0.1,0.1,0.35,0.35);
    leg->AddEntry(ophits_yz,"Opticks","p");
    leg->AddEntry(g4hits_yz,"Geant4","p");
    leg->Draw();

    c->SaveAs("plotHits.pdf");
}
