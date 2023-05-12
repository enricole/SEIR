#include "SEIR_graph.hpp"

SEIR_graph :: SEIR_graph(SEIR SEIR_ini, const float beta, const float gamma, const float mu, const float a, const unsigned int days) : SEIR_model(SEIR_ini, beta, gamma, mu, a, days){}

void SEIR_graph::graph(const char* name1, const char* name2){
    //In this section the graph are declared and defined, the titles and the colors are set
    TGraph * graphS = new TGraph();
    graphS->SetTitle("Susceptible");
    graphS->GetXaxis()->SetTitle("Days");
    graphS->GetYaxis()->SetTitle("Number");
    graphS->SetLineColor(kGreen);

    TGraph * graphE = new TGraph();
    graphE->SetTitle("Exposed");
    graphE->GetXaxis()->SetTitle("Days");
    graphE->GetYaxis()->SetTitle("Number");
    graphE->SetLineColor(kOrange);

    TGraph * graphI = new TGraph();
    graphI->SetTitle("Infected");
    graphI->GetXaxis()->SetTitle("Days");
    graphI->GetYaxis()->SetTitle("Number");
    graphI->SetLineColor(kRed);

    TGraph * graphR = new TGraph();
    graphR->SetTitle("Recovered");
    graphR->GetXaxis()->SetTitle("Days");
    graphR->GetYaxis()->SetTitle("Number");
    graphR->SetLineColor(kBlue);

    //this for cycle plots the values of the history_ vector to the corresponding graph
    for (int i = 0; i < history_.size(); i++){
    graphS-> SetPoint(i, static_cast<double> (i) , history_[i].S);
    graphE-> SetPoint(i, static_cast<double> (i) , history_[i].E);    
    graphI-> SetPoint(i, static_cast<double> (i) , history_[i].I);
    graphR-> SetPoint(i, static_cast<double> (i) , history_[i].R);
    }
    //here the canvas and pads are created, so that the graphs can be displayed in 
    TCanvas* canvas = new TCanvas ("SEIR", "SEIR_separated", 1200, 1200);
    TCanvas* canvas2 = new TCanvas ("SEIR_O", "SEIR_overlapped", 1200, 1200);

    TPad* padS = new TPad("padS", "Susceptible", 0.05, 0.5, 0.5, 1.0);
    TPad* padE = new TPad("padE", "Exposed", 0.55, 0.5, 1.0, 1.0);    
    TPad* padI = new TPad("padI", "Infected", 0.05, 0.0, 0.5, 0.5);
    TPad* padR = new TPad("padR", "Recovered", 0.55, 0.0, 1.0, 0.5);
    TPad* pad = new TPad("pad", "Overlapped", 0.0, 0.0, 1.0, 1.0);
    padS -> SetLeftMargin(0.15);
    padE -> SetLeftMargin(0.15);
    padI -> SetLeftMargin(0.15);
    padR -> SetLeftMargin(0.15);
    pad -> SetLeftMargin(0.15);
    //here the graphs are effectively drawn
    canvas -> cd();
    padS -> Draw();
    padE -> Draw();
    padI -> Draw();
    padR -> Draw();

    padS -> cd();
    graphS -> Draw("AL");
    padE -> cd();
    graphE -> Draw("AL");
    padI -> cd();
    graphI -> Draw("AL");
    padR -> cd();
    graphR -> Draw("AL");
    
    canvas->SaveAs(name1);
    //multigraph is implemented to generate the overlapped graphs
    TMultiGraph* multi = new TMultiGraph();
    multi -> Add(graphS);
    multi -> Add(graphE);
    multi -> Add(graphI);
    multi -> Add(graphR);
    multi -> GetXaxis() -> SetTitle("Days");
    multi -> GetYaxis() -> SetTitle("Number");

    canvas2 -> cd();
    pad -> Draw();
    pad -> cd();

    multi -> Draw("AL");
    TLegend* legend = new TLegend(0.8,0.7,0.9,0.9);
    legend->AddEntry(graphS,"  S","l");
    legend->AddEntry(graphE,"  E","l");
    legend->AddEntry(graphI,"  I","l");
    legend->AddEntry(graphR,"  R","l");
    legend->Draw();

    canvas2 -> SaveAs(name2);
    delete graphS;
    delete graphE;
    delete graphI;
    delete graphR;
    delete canvas;
    delete canvas2;
}