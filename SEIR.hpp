#ifndef SEIR_HPP
#define SEIR_HPP

#include <vector>
#include <iostream>
#include <cmath>
#include <stdexcept>


struct SEIR {
double S;
double E;
double I;
double R;
};


class SEIR_model {
 protected:
    const float beta_;
    const float gamma_;
    const float mu_;
    const float a_;
    const unsigned int days_;
    int N_;
    std::vector<SEIR> history_;
 public:
    SEIR_model(SEIR SEIR_ini, const float beta, const float gamma, const float mu, const float a, const unsigned int days);
    void verify();
    void approx(int T);
    void evolve();
    void print();
};


#endif