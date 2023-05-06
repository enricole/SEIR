// funzione approsimazione fare come già fatto valutando la parte decimale con eventuale generazione random

// per fare data assimilation, valuto l'errore tra le previsione e il seir, dopodiché la esprimo in percentuale e la percentuale mi da quanto devo cambiare i vincoli con generazione random
// per il processo inverso semplicemente fit
#include "SEIR.hpp"

SEIR_model::SEIR_model(SEIR SEIR_ini, const float beta, const float gamma, const float mu, const float a, const unsigned int days) 
 : beta_(beta), gamma_(gamma), mu_(mu), a_(a), days_(days) {
    N_ = SEIR_ini.S + SEIR_ini.E + SEIR_ini.I + SEIR_ini.R;
    history_.push_back(SEIR_ini);
 }


void SEIR_model::approx(int T) {

    double residueS=history_[T].S-std::trunc(history_[T].S);
    double residueE=history_[T].E-std::trunc(history_[T].E);
    double residueI=history_[T].I-std::trunc(history_[T].I);
    double residueR=history_[T].R-std::trunc(history_[T].R);
    double r = residueS+residueE+residueI+residueR;
    int residuetot = static_cast<int>(r);

    int count=0;
    int rdm;

    count = (residueS>=residueR>=residueI>=residueE) ? 31 : count;
    count = (residueS>=residueI>=residueR>=residueE) ? 32 : count;
    count = (residueS>=residueE>=residueI>=residueR) ? 33 : count;
    count = (residueS>=residueE>=residueR>=residueI) ? 34 : count;
    count = (residueS>=residueR>=residueE>=residueI) ? 35 : count;
    count = (residueS>=residueR>=residueI>=residueE) ? 36 : count;

    count = (residueE>=residueI>=residueR>=residueS) ? 37 : count;
    count = (residueE>=residueI>=residueS>=residueR) ? 38 : count;
    count = (residueE>=residueR>=residueI>=residueS) ? 39 : count;
    count = (residueE>=residueR>=residueS>=residueI) ? 40 : count;
    count = (residueE>=residueS>=residueR>=residueI) ? 41 : count;
    count = (residueE>=residueS>=residueI>=residueR) ? 42 : count;

    count = (residueI>=residueR>=residueE>=residueS) ? 43 : count;
    count = (residueI>=residueE>=residueR>=residueS) ? 44 : count;
    count = (residueI>=residueS>=residueR>=residueE) ? 45 : count;
    count = (residueI>=residueS>=residueE>=residueR) ? 46 : count;
    count = (residueI>=residueE>=residueS>=residueR) ? 47 : count;
    count = (residueI>=residueR>=residueS>=residueE) ? 48 : count;

    count = (residueR>=residueI>=residueE>=residueS) ? 49 : count;
    count = (residueR>=residueE>=residueI>=residueS) ? 50 : count;
    count = (residueR>=residueS>=residueI>=residueE) ? 51 : count;
    count = (residueR>=residueS>=residueE>=residueI) ? 52 : count;
    count = (residueR>=residueE>=residueS>=residueI) ? 53 : count;
    count = (residueR>=residueI>=residueS>=residueE) ? 54 : count;

/*infine l'ultimo caso è residuetot=3 dove ho paura che bisognerà rifare tutto riversato, 
però necessariamente ho due >0.5, quindi basta metterli in ordine e l'ultimo per difetto*/

    if (residuetot==3) {
switch (count) {
    case 31:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].E = std::trunc(history_[T].E);
        break;
    case 32:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].E = std::trunc(history_[T].E);
        break;
    case 33:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].R = std::trunc(history_[T].R);
        break;
    case 34:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I);
        break;
    case 35:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].I = std::trunc(history_[T].I);
        break;
    case 36:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].E = std::trunc(history_[T].E);
        break;
    case 37:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].S = std::trunc(history_[T].S);
        break;
    case 38:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R);
        break;
    case 39:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].S = std::trunc(history_[T].S);
        break;
    case 40:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].I = std::trunc(history_[T].I);
        break;
    case 41:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I);
        break;

    case 42:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].R = std::trunc(history_[T].R);
        break;

    case 43:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].S = std::trunc(history_[T].S);
        break;

    case 44:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].S = std::trunc(history_[T].S);
        break;

    case 45:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].E = std::trunc(history_[T].E);
        break;

    case 46:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].R = std::trunc(history_[T].R);
        break;

    case 47:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R);
        break;

    case 48:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].E = std::trunc(history_[T].E);
        break;

    case 49:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].S = std::trunc(history_[T].S);
        break;

    case 50:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].S = std::trunc(history_[T].S);
        break;
    case 51:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].E = std::trunc(history_[T].E);
        break;

    case 52:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].I = std::trunc(history_[T].I);
        break;

    case 53:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].I = std::trunc(history_[T].I);
        break;

    case 54:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].E = std::trunc(history_[T].E);
        break;

default:
    break;
}
    }
//fine caso residue tot=3
//inizio caso residuetot=2
else {

// caso tutti 0.5
    if (residuetot==2 && residueE==residueI==residueR==residueS) {
        rdm=std::rand() % 6 +1;
switch (rdm)
    {
    case 1:
        history_[T].S=std::trunc(history_[T].S)+1;
        history_[T].I=std::trunc(history_[T].I)+1;
        count=55;
        break;
    case 2:
        history_[T].E=std::trunc(history_[T].E)+1;
        history_[T].S=std::trunc(history_[T].S)+1;
        count=56;
        break;
    case 3:
        history_[T].R=std::trunc(history_[T].R)+1;
        history_[T].S=std::trunc(history_[T].S)+1;
        count=57;
        break;
    case 4:
        history_[T].R=std::trunc(history_[T].R)+1;
        history_[T].E=std::trunc(history_[T].E)+1;
        count=58;
    case 5:
        history_[T].R=std::trunc(history_[T].R)+1;
        history_[T].I=std::trunc(history_[T].I)+1;
        count=59;
        break;
    case 6:
        history_[T].I=std::trunc(history_[T].I)+1;
        history_[T].E=std::trunc(history_[T].E)+1;
        count=60;
        break;
    }
    }
else {
        if (residuetot==2) {
switch (count) {
    case 31:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I);
        history_[T].E = std::trunc(history_[T].E);
        break;
    case 32:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].R = std::trunc(history_[T].R);
        history_[T].E = std::trunc(history_[T].E);
        break;
    case 33:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].I = std::trunc(history_[T].I);
        history_[T].R = std::trunc(history_[T].R);
        break;
    case 34:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].R = std::trunc(history_[T].R);
        history_[T].I = std::trunc(history_[T].I);
        break;
    case 35:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].E = std::trunc(history_[T].E);
        history_[T].I = std::trunc(history_[T].I);
        break;
    case 36:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I);
        history_[T].E = std::trunc(history_[T].E);
        break;
    case 37:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].R = std::trunc(history_[T].R);
        history_[T].S = std::trunc(history_[T].S);
        break;
    case 38:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].S = std::trunc(history_[T].S);
        history_[T].R = std::trunc(history_[T].R);
        break;
    case 39:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I);
        history_[T].S = std::trunc(history_[T].S);
        break;
    case 40:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].S = std::trunc(history_[T].S);
        history_[T].I = std::trunc(history_[T].I);
        break;
    case 41:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R);
        history_[T].I = std::trunc(history_[T].I);
        break;

    case 42:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].I = std::trunc(history_[T].I);
        history_[T].R = std::trunc(history_[T].R);
        break;

    case 43:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].E = std::trunc(history_[T].E);
        history_[T].S = std::trunc(history_[T].S);
        break;

    case 44:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].R = std::trunc(history_[T].R);
        history_[T].S = std::trunc(history_[T].S);
        break;

    case 45:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R);
        history_[T].E = std::trunc(history_[T].E);
        break;

    case 46:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].E = std::trunc(history_[T].E);
        history_[T].R = std::trunc(history_[T].R);
        break;

    case 47:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].S = std::trunc(history_[T].S);
        history_[T].R = std::trunc(history_[T].R);
        break;

    case 48:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].S = std::trunc(history_[T].S);
        history_[T].E = std::trunc(history_[T].E);
        break;

    case 49:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].E = std::trunc(history_[T].E);
        history_[T].S = std::trunc(history_[T].S);
        break;

    case 50:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].I = std::trunc(history_[T].I);
        history_[T].S = std::trunc(history_[T].S);
        break;
    case 51:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].I = std::trunc(history_[T].I);
        history_[T].E = std::trunc(history_[T].E);
        break;

    case 52:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].E = std::trunc(history_[T].E);
        history_[T].I = std::trunc(history_[T].I);
        break;

    case 53:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].S = std::trunc(history_[T].S);
        history_[T].I = std::trunc(history_[T].I);
        break;

    case 54:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].S = std::trunc(history_[T].S);
        history_[T].E = std::trunc(history_[T].E);
        break;

default:
    break;
}
    }
//fine caso residuetot=2
//inizio caso residuetot=1
 else {

        if (residuetot==1) {
            
    count = (residueS>residueE && residueS>residueR && residueS>residueI) ? 1 : count;
    count = (residueE>residueS && residueE>residueR && residueE>residueI) ? 2 : count;
    count = (residueI>residueE && residueI>residueR && residueI>residueS) ? 3 : count;
    count = (residueR>residueE && residueR>residueI && residueR>residueS) ? 4 : count;

    switch (count) {
        case 1:
            history_[T].S=std::trunc(history_[T].S)+1;
            history_[T].E=std::trunc(history_[T].E);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            break;
        case 2:
            history_[T].E=std::trunc(history_[T].E)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            break;
        case 3:
            history_[T].I=std::trunc(history_[T].I)+1;
            history_[T].E=std::trunc(history_[T].E);
            history_[T].S=std::trunc(history_[T].S);
            history_[T].R=std::trunc(history_[T].R);
            break;
        case 4:
            history_[T].R=std::trunc(history_[T].R)+1;
            history_[T].E=std::trunc(history_[T].E);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].S=std::trunc(history_[T].S);
            break;
        default:
            count=0;
            break;
    }

rdm=std::rand() % 2 +1;
    count = (residueS==residueE && residueS>residueR && residueS>residueI) ? 5 : count;
    count = (residueE==residueI && residueE>residueR && residueE>residueS) ? 7 : count;
    count = (residueI==residueS && residueI>residueR && residueI>residueE) ? 9 : count;
    count = (residueR==residueS && residueR>residueI && residueR>residueE) ? 11 : count;
    count = (residueR==residueE && residueR>residueI && residueR>residueS) ? 13 : count;
    count = (residueR==residueI && residueR>residueS && residueR>residueE) ? 15 : count;


    switch(count) {
        case 5:
            if (rdm==1) {
            history_[T].S=std::trunc(history_[T].S)+1;
            history_[T].E=std::trunc(history_[T].E);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            }
            else {
            history_[T].E=std::trunc(history_[T].E)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            }
            break;
        case 7:
            if (rdm==1) {
             history_[T].E=std::trunc(history_[T].E)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            }
            else {
            history_[T].I=std::trunc(history_[T].I)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].E=std::trunc(history_[T].E);
            history_[T].R=std::trunc(history_[T].R);
            }
            break;
        case 9:
            if (rdm==1) {
            history_[T].I=std::trunc(history_[T].I)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].E=std::trunc(history_[T].E);
            history_[T].R=std::trunc(history_[T].R);
            }
            else {
            history_[T].S=std::trunc(history_[T].S)+1;
            history_[T].E=std::trunc(history_[T].E);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            }
            break;
        case 11:
            if (rdm==1) {
            history_[T].R=std::trunc(history_[T].R)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].E=std::trunc(history_[T].E);
            }
            else {
            history_[T].S=std::trunc(history_[T].S)+1;
            history_[T].E=std::trunc(history_[T].E);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            }
            break;
        case 13:
            if (rdm==1) {
            history_[T].R=std::trunc(history_[T].R)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].E=std::trunc(history_[T].E);
            }
            else {
            history_[T].E=std::trunc(history_[T].E)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            }
            break;
        case 15:
            if (rdm==1) {
            history_[T].R=std::trunc(history_[T].R)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].E=std::trunc(history_[T].E);
            }
            else {
            history_[T].I=std::trunc(history_[T].I)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].E=std::trunc(history_[T].E);
            history_[T].R=std::trunc(history_[T].R);
            }
            break;
        default:
            count=0;
            break;
    }

rdm=std::rand() % 3 +1;
    count = (residueS==residueE==residueR && residueS>residueI) ? 17 : count;
    count = (residueE==residueI==residueR && residueE>residueS) ? 20 : count;
    count = (residueI==residueS==residueR && residueI>residueE) ? 23 : count;
    count = (residueS==residueE==residueI && residueR>residueS) ? 26 : count;
     
     
     switch(count) {
        case 17:
            if (rdm==1) {
            history_[T].S=std::trunc(history_[T].S)+1;
            history_[T].E=std::trunc(history_[T].E);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            }
            else {
                if (rdm==2) {
            history_[T].E=std::trunc(history_[T].E)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            }
             else {
            history_[T].R=std::trunc(history_[T].R)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].E=std::trunc(history_[T].E);
             }}
            break;
        case 20:
            if (rdm==1) {
            history_[T].E=std::trunc(history_[T].E)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            }
            else {
                if (rdm==2) {
            history_[T].I=std::trunc(history_[T].I)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].E=std::trunc(history_[T].E);
            history_[T].R=std::trunc(history_[T].R);
            }
             else {
            history_[T].R=std::trunc(history_[T].R)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].E=std::trunc(history_[T].E);
             }}
            break;
        case 23:
            if (rdm==1) {
            history_[T].I=std::trunc(history_[T].I)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].E=std::trunc(history_[T].E);
            history_[T].R=std::trunc(history_[T].R);
            }
            else {
                if (rdm==2) {
            history_[T].S=std::trunc(history_[T].S)+1;
            history_[T].E=std::trunc(history_[T].E);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            }
             else {
            history_[T].R=std::trunc(history_[T].R)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].E=std::trunc(history_[T].E);
             }}
            break;
        case 26:
            if (rdm==1) {
            history_[T].S=std::trunc(history_[T].S)+1;
            history_[T].E=std::trunc(history_[T].E);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            }
            else {
                if (rdm==2) {
            history_[T].E=std::trunc(history_[T].E)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            }
             else {
            history_[T].I=std::trunc(history_[T].I)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].E=std::trunc(history_[T].E);
            history_[T].R=std::trunc(history_[T].R);
             }}
            break;
        default:
            count=0;
            break;
    }
rdm=std::rand() % 4 +1;
    switch (rdm)
    {
    case 1:
        history_[T].S=std::trunc(history_[T].S)+1;
        history_[T].E=std::trunc(history_[T].E);
        history_[T].I=std::trunc(history_[T].I);
        history_[T].R=std::trunc(history_[T].R);
        break;
    case 2:
        history_[T].E=std::trunc(history_[T].E)+1;
        history_[T].S=std::trunc(history_[T].S);
        history_[T].I=std::trunc(history_[T].I);
        history_[T].R=std::trunc(history_[T].R);
        break;
    case 3:
        history_[T].I=std::trunc(history_[T].I)+1;
        history_[T].S=std::trunc(history_[T].S);
        history_[T].E=std::trunc(history_[T].E);
        history_[T].R=std::trunc(history_[T].R);
        break;
    case 4:
        history_[T].R=std::trunc(history_[T].R)+1;
        history_[T].S=std::trunc(history_[T].S);
        history_[T].I=std::trunc(history_[T].I);
        history_[T].E=std::trunc(history_[T].E);
        count=30;
        break;
    }
        }
 }
 }
}
 
 }

void SEIR_model::print() {
    int N = days_;
    for (int i=0; i<N; i++) {
        std::cout<<"il numero di suscettibili è, nel giorno "<<i<<", :"<<history_[i].S<<std::endl;
        std::cout<<"il numero di infetti è, nel giorno "<<i<<", :"<<history_[i].I<<std::endl;
        std::cout<<"il numero di esposti è, nel giorno "<<i<<" :"<<history_[i].E<<std::endl;
        std::cout<<"il numero di recovered è, nel giorno "<<i<<" :"<<history_[i].R<<std::endl;

    }
    

}

