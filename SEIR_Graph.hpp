#ifndef SEIRGRAPH_HPP
#define SEIRGRAPH_HPP

#include "TCanvas.h"
#include "TGraph.h"
#include "TPad.h"
#include "TAxis.h"
#include "TMultiGraph.h"
#include "TLegend.h"

#include "SEIR.hpp"

class SEIR_graph : public SEIR_model {
    public:
        //derived constructor  
        SEIR_graph(SEIR SEIR_ini, const float beta, const float gamma, const float mu, const float a, const unsigned int days);
        //method to generate two graphic representations of the simulation
        void graph(const char* name1, const char* name2);
};
#endif