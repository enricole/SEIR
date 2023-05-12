#ifndef SEIR_HPP
#define SEIR_HPP

#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>   

// a struct definition in order to use more nimbly the parameters and confront them
struct SEIR {
double S; //Susceptible
double E; //Exposed
double I; //Infected
double R; //Recovered
bool operator==(SEIR const& other) const noexcept {  
  return S == other.S && E == other.E && I == other.I && R == other.R;
 }

};

SEIR approx(SEIR non_approx);

class SEIR_model {
 protected:
    const float beta_; //transmission rate
    const float gamma_; // healing and mortality rate FOR the ilness
    const float mu_; // natural mortality rate NOT FOR the ilness
    const float a_; // inverse of the incubation time of the ilness
    const int days_;
    int N_; //the sum of SEIR parameters, that MUST stay constant
    std::vector<SEIR> history_; // a vector that recall the SEIR parameters for every day
 public:
 // function use is suggested by the name, can be deepened in the SEIR.cpp file
    SEIR_model(SEIR SEIR_ini, const float beta, const float gamma, const float mu, const float a, const int days);
    bool verify();
    void evolve();
    void evolve_runge_kutta();
    void print(int D);
    void print_out(std::string name);
    SEIR daily_seir(int T);
};


#endif

