#include <TGraph2D.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void plotHits() {
    TCanvas *c = new TCanvas("c","Hits collected by Opticks and Geant4",0, 0, 1000, 1000);
    
    TGraph2D *ophits = new TGraph2D();
    ifstream fophits("build/Opticks_hits.txt", ios::in);
    char line[128];
    int N = 0;
    double x, y, z;
    while(fophits.getline(line,sizeof(line))) {
        stringstream word(line);
	word >> x; word >> y; word >> z;
	cout << N << " " << x << " " << y << " " << z << endl;
	ophits->SetPoint(N,x,y,z);
	N+=1;
    }
    
    TGraph2D *g4hits = new TGraph2D();
    ifstream fg4hits("build/Geant4_hits.txt", ios::in);
    N = 0;
    while(fg4hits.getline(line,sizeof(line))) {
        stringstream word(line);
	word >> x; word >> y; word >> z;
	g4hits->SetPoint(N,x,y,z);
    	N+=1;
    }

    ophits->Draw("P");
    ophits->SetMarkerStyle(20);
    ophits->SetMarkerColor(5);

    g4hits->Draw("same P");
    g4hits->SetMarkerStyle(10);
    g4hits->SetMarkerColor(4);

    c->SaveAs("plotHits.pdf");
}
