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
        CHECK(SEIR_model_test.daily_seir(0)==SEIR_approx_test);
    }
}


TEST_CASE("Testing SEIR_model::verify") {
        double S, E, I, R;
        S=1;E=1;I=1;R=1;
        SEIR SEIR_test{S,E,I,R};
// SUBCASES beta
    SUBCASE("Case beta>1") {
        SEIR_model SEIR_model_test(SEIR_test,1.2,0.2,0.2,0.2,1);
        CHECK(SEIR_model_test.verify()==false);
    }
    SUBCASE("Case beta<0") {
        SEIR_model SEIR_model_test(SEIR_test,-1,0.2,0.2,0.2,1);
        CHECK(SEIR_model_test.verify()==false);
    }
    SUBCASE("Case 0<=beta<1") {
        SEIR_model SEIR_model_test(SEIR_test,0.2,0.2,0.2,0.2,1);
        CHECK(SEIR_model_test.verify()==true);
    }
// SUBCASES gamma
    SUBCASE("Case gamma>1") {
        SEIR_model SEIR_model_test(SEIR_test,0.2,1.2,0.2,0.2,1);
        CHECK(SEIR_model_test.verify()==false);
    }
    SUBCASE("Case gamma<0") {
        SEIR_model SEIR_model_test(SEIR_test,0.2,-1,0.2,0.2,1);
        CHECK(SEIR_model_test.verify()==false);
    }
    SUBCASE("Case 0<=gamma<1") {
        SEIR_model SEIR_model_test(SEIR_test,0.2,0.2,0.2,0.2,1);
        CHECK(SEIR_model_test.verify()==true);
    }
// SUBCASES mu
    SUBCASE("Case mu>1") {
        SEIR_model SEIR_model_test(SEIR_test,0.2,0.2,2,0.2,1);
        CHECK(SEIR_model_test.verify()==false);
    }
    SUBCASE("Case mu<0") {
        SEIR_model SEIR_model_test(SEIR_test,0.2,0.2,-0.2,0.2,1);
        CHECK(SEIR_model_test.verify()==false);
    }
    SUBCASE("Case 0<=mu<1") {
        SEIR_model SEIR_model_test(SEIR_test,0.2,0.2,0.2,0.2,1);
        CHECK(SEIR_model_test.verify()==true);
    }
// SUBCASES a
    SUBCASE("Case a>1") {
        SEIR_model SEIR_model_test(SEIR_test,0.2,0.2,0.2,2,1);
        CHECK(SEIR_model_test.verify()==false);
    }
    SUBCASE("Case a<0") {
        SEIR_model SEIR_model_test(SEIR_test,0.2,0.2,0.2,-0.2,1);
        CHECK(SEIR_model_test.verify()==false);
    }
    SUBCASE("Case 0<=a<1") {
        SEIR_model SEIR_model_test(SEIR_test,0.2,0.2,0.2,0.2,1);
        CHECK(SEIR_model_test.verify()==true);
    }
// SUBCASES days
    SUBCASE("Case days>=1") {
        SEIR_model SEIR_model_test(SEIR_test,0.2,0.2,0.2,0.2,2);
        CHECK(SEIR_model_test.verify()==true);
    }
    SUBCASE("Case days<0") {
        SEIR_model SEIR_model_test(SEIR_test,0.2,0.2,0.2,0.2,-3);
        CHECK(SEIR_model_test.verify()==false);
    }
}


TEST_CASE("Testing SEIR_model::evolve") {
    double S, E, I, R;
    
    SUBCASE ("Trivial case no infected no exposed no mortality") {
        S=50;E=0;I=0;R=1;
        SEIR SEIR_test{S,E,I,R};
        SEIR_model SEIR_model_test (SEIR_test,0.2,0.2,0.00001,0.2,10);
        SEIR_model_test.evolve();
        SEIR_test = SEIR_model_test.daily_seir(10);
        CHECK(SEIR_test.S==50);
    }
        SUBCASE ("Trivial case no transmission") {
        S=50;E=1;I=30;R=1;
        SEIR SEIR_test{S,E,I,R};
        SEIR_model SEIR_model_test (SEIR_test,0.000000000001,0.2,0.2,0.2,10);
        SEIR_model_test.evolve();
        SEIR_test = SEIR_model_test.daily_seir(10);
        CHECK(SEIR_test.I<30);
    }
        SUBCASE ("Trivial case low mortality and great transmission") {
        S=50;E=1;I=30;R=1;
        SEIR SEIR_test{S,E,I,R};
        SEIR_model SEIR_model_test (SEIR_test,0.6,0.01,0.01,0.3,10);
        SEIR_model_test.evolve();
        SEIR_test = SEIR_model_test.daily_seir(10);
        CHECK(SEIR_test.S<25);
    }
}
TEST_CASE("Testing compatibility") {
    double S, E, I, R;
    SUBCASE ("Case 1") {
        S=50;E=0;I=2;R=1;
        SEIR SEIR_test{S,E,I,R};
        SEIR SEIR_test_2{S,E,I,R}; 
        SEIR_model SEIR_model_test1 (SEIR_test,0.8,0.2,0.00001,0.2,1000);
        SEIR_model SEIR_model_test2 (SEIR_test,0.8,0.2,0.00001,0.2,1000);
        SEIR_model_test1.evolve();
        SEIR_model_test2.evolve_runge_kutta();
        SEIR_test= SEIR_model_test1.daily_seir(1000);
        SEIR_test_2 = SEIR_model_test2.daily_seir(1000);
        CHECK(std::abs(SEIR_test.S-SEIR_test_2.S)<=1);
        CHECK(std::abs(SEIR_test.E-SEIR_test_2.E)<=1);
        CHECK(std::abs(SEIR_test.I-SEIR_test_2.I)<=1);
        CHECK(std::abs(SEIR_test.R-SEIR_test_2.R)<=1);
    }
}
