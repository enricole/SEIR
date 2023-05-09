#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"    
#include "SEIR.hpp"



TEST_CASE("Testing SEIR_model::approx") {
    double S, E, I, R;
    
    SUBCASE("Test approx caso residuetot==3 ") {
        S=13.8; E=18.7; I=7.9; R=3.6;
        SEIR SEIR_test{S,E,I,R};
        SEIR_model SEIR_model_test(SEIR_test,1,1,1,1,1);
        SEIR SEIR_approx_test {14,19,8,3};
        SEIR_model_test.evolve();
        CHECK(SEIR_model_test.daily_seir(0)==SEIR_approx_test);
    }
    SUBCASE("Test approx caso resideutot==2") {
        S=12.9; E=0; I=4.6; R=14.5;
        SEIR SEIR_test{S,E,I,R};
        SEIR_model SEIR_model_test(SEIR_test,1,1,1,1,1);
        SEIR SEIR_approx_test {13,0,5,14};
        SEIR_model_test.evolve();
        CHECK(SEIR_model_test.daily_seir(0)==SEIR_approx_test);
    }
    SUBCASE("Test approx caso residuetot==1"){
        S=13.4; E=18.3; I=7.2; R=3.1;
        SEIR SEIR_test{S,E,I,R};
        SEIR_model SEIR_model_test(SEIR_test,1,1,1,1,1);
        SEIR SEIR_approx_test {14,18,7,3};
        SEIR_model_test.evolve();
        SEIR_model_test.print();
        CHECK(SEIR_model_test.daily_seir(0)==SEIR_approx_test);
    }
}