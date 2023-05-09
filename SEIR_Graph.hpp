#include "TCanvas.h"
#include "TGraph.h"
#include "TPad.h"
#include "TAxis.h"

#include "sir_model.hpp"

class SEIRgraph : public SEIR_model {
    public:
        SEIRgraph(SEIR SEIR_ini, const float beta, const float gamma, const float mu, const float a, const unsigned int days);
        void graph();
}