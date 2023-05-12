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

// see file .cpp
SEIR approx(SEIR non_approx);

class SEIR_model {
 protected:
    float beta_; //transmission rate
    float gamma_; // healing and mortality rate caused by the illness
    float mu_; // natural mortality rate NOT caused by the illness
    float a_; // inverse of the incubation time of the illness
    int days_;
    int N_; //the sum of SEIR parameters, that MUST stay constant
    std::vector<SEIR> history_; // a vector that recall the SEIR parameters for every day
 public:
 // function use is suggested by the name, can be deepened in the SEIR.cpp file
    SEIR_model(SEIR SEIR_ini, float beta, float gamma, float mu, float a, int days);
    bool verify();
    void evolve();
    void evolve_runge_kutta();
    void print(int D);
    void print_out(std::string name);
    SEIR daily_seir(int T); //used in the test file
    SEIR_model& operator=(const SEIR_model& other); //ridefinition of = operator
};


#endif

