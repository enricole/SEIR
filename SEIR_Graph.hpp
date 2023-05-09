#ifndef SIRGRAPH_HPP
#define SIRGRAPH_HPP

#include "TCanvas.h"
#include "TGraph.h"
#include "TPad.h"
#include "TAxis.h"

#include "sir_model.hpp"

class SEIR_graph : public SEIR_model {
    public:
        SEIR_graph(SEIR SEIR_ini, const float beta, const float gamma, const float mu, const float a, const unsigned int days);
        void graph();
}
#endif