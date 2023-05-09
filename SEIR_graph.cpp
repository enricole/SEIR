#include "SEIR_Graph.hpp"

SEIR_graph :: SEIR_graph(SEIR SEIR_ini, const float beta, const float gamma, const float mu, const float a, const unsigned int days) : SEIR_model(SEIR_ini, beta, gamma, mu, a, days){}

void SEIR_graph::graph(){

    TGraph * graphS = new TGraph();
    graphS->SetTitle("Susceptible");
    graphS->GetXaxis()->SetTitle("Days");
    graphS->GetYaxis()->SetTitle("Number");
    graphS->SetLineColor(kGreen);

    TGraph * graphE = new TGraph();
    graphE->SetTitle("Exposed");
    graphE->GetXaxis()->SetTitle("Days");
    graphE->GetYaxis()->SetTitle("Number");
    graphE->SetLineColor(kYellow);

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

    for (int i = 0; i < record_.size(); i++){
    graphS-> AddPoint (static_cast<double> (i) , record_[i].S);
    graphE-> AddPoint (static_cast<double> (i) , record_[i].E);    
    graphI-> AddPoint (static_cast<double> (i) , record_[i].I);
    graphR-> AddPoint (static_cast<double> (i) , record_[i].R);
    }

    TCanvas* canvas = new TCanvas ("SEIR", "SEIR_model", 1200, 1200);

    TPad* padS = new TPad("padS", "Susceptible", 0.0, 0.0, 0.33, 1.0);
    TPad* padE = new TPad("padE", "Exposed", 0.0, 0.0, 0.33, 1.0);    
    TPad* padI = new TPad("padI", "Infected", 0.33, 0.0, 0.66, 1.0);
    TPad* padR = new TPad("padR", "Recovered", 0.66, 0.0, 1.0, 1.0);
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
    
    canvas->SaveAs("graficoSEIR.png");    

    delete graphS;
    delete graphE;
    delete graphI;
    delete graphR;
    delete canvas;
}