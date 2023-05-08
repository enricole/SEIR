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
    std::cout<<"residuetot è "<<residuetot<<std::endl;
    std::cout<<"residueS è "<<residueS<<std::endl;
    std::cout<<"residueE è "<<residueE<<std::endl;
    std::cout<<"residueI è "<<residueI<<std::endl;
    std::cout<<"residueR è "<<residueR<<std::endl;
    int count=0;
    int rdm;

count = (residueS>=residueR && residueR>=residueI && residueI>=residueE) ? 31 : count;
count = (residueS>=residueI && residueI>=residueR && residueR>=residueE) ? 32 : count;
count = (residueS>=residueE && residueE>=residueI && residueI>=residueR) ? 33 : count;
count = (residueS>=residueE && residueE>=residueR && residueR>=residueI) ? 34 : count;
count = (residueS>=residueR && residueR>=residueE && residueE>=residueI) ? 35 : count;
count = (residueS>=residueR && residueR>=residueI && residueI>=residueE) ? 36 : count;

count = (residueE>=residueI && residueI>=residueR && residueR>=residueS) ? 37 : count;
count = (residueE>=residueI && residueI>=residueS && residueS>=residueR) ? 38 : count;
count = (residueE>=residueR && residueR>=residueI && residueI>=residueS) ? 39 : count;
count = (residueE>=residueR && residueR>=residueS && residueS>=residueI) ? 40 : count;
count = (residueE>=residueS && residueS>=residueR && residueR>=residueI) ? 41 : count;
count = (residueE>=residueS && residueS>=residueI && residueI>=residueR) ? 42 : count;

count = (residueI>=residueR && residueR>=residueE && residueE>=residueS) ? 43 : count;
count = (residueI>=residueE && residueE>=residueR && residueR>=residueS) ? 44 : count;
count = (residueI>=residueS && residueS>=residueR && residueR>=residueE) ? 45 : count;
count = (residueI>=residueS && residueS>=residueE && residueE>=residueR) ? 46 : count;
count = (residueI>=residueE && residueE>=residueS && residueS>=residueR) ? 47 : count;
count = (residueI>=residueR && residueR>=residueS && residueS>=residueE) ? 48 : count;

count = (residueR>=residueI && residueI>=residueE && residueE>=residueS) ? 49 : count;
count = (residueR>=residueE && residueE>=residueI && residueI>=residueS) ? 50 : count;
count = (residueR>=residueS && residueS>=residueI && residueI>=residueE) ? 51 : count;
count = (residueR>=residueS && residueS>=residueE && residueE>=residueI) ? 52 : count;
count = (residueR>=residueE && residueE>=residueS && residueS>=residueI) ? 53 : count;
count = (residueR>=residueI && residueI>=residueS && residueS>=residueE) ? 54 : count;
std::cout<<"count è "<<count<<std::endl;
/*infine l'ultimo caso è residuetot=3 dove ho paura che bisognerà rifare tutto riversato, 
però necessariamente ho tre >0.5, quindi basta metterli in ordine e l'ultimo per difetto*/

    if (residuetot==3) {
switch (count) {
// E invariata
    case 31:
    case 32:
    case 36:
    case 45:
    case 48:
    case 51:
    case 54:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].E = std::trunc(history_[T].E);
        break;

// R invariata
    case 33:
    case 38:
    case 42:
    case 46:
    case 47:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R);
        break;

// I invariata
    case 34:
    case 35:
    case 40:
    case 41:
    case 52:
    case 53:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].I = std::trunc(history_[T].I);
        break;

// S invariata
    case 37:
    case 39:
    case 43:
    case 44:
    case 49:
    case 50:
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].S = std::trunc(history_[T].S);
        break;

}
    }
//fine caso residue tot=3
//inizio caso residuetot=2
else {
// caso tutti 0.5
    if (residuetot==2 && residueE==residueI && residueR==residueS && residueI==residueR) {
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
 // IE invariati case 35,36,51,52  
    case 31:
    case 35:
    case 36:
    case 51:
    case 52:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I);
        history_[T].E = std::trunc(history_[T].E);
        break;
// RE invariati case 45,46,
    case 32:
    case 45:
    case 46:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].R = std::trunc(history_[T].R);
        history_[T].E = std::trunc(history_[T].E);
        break;
// IR invariati 34, 41,42,
    case 33:
    case 34:
    case 41:
    case 42:
        history_[T].S = std::trunc(history_[T].S) + 1;
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].I = std::trunc(history_[T].I);
        history_[T].R = std::trunc(history_[T].R);
        break;
// RS invariati case 38,44,47,
    case 37:
    case 38:
    case 44:
    case 47:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].R = std::trunc(history_[T].R);
        history_[T].S = std::trunc(history_[T].S);
        break;
// IS invariati case 40,50,53,
    case 39:
    case 40:
    case 50:
    case 53:
        history_[T].E = std::trunc(history_[T].E) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].I = std::trunc(history_[T].I);
        history_[T].S = std::trunc(history_[T].S);
        break;
// ES invariati 48,49,54
    case 43:
    case 48:
    case 49:
    case 54:
        history_[T].I = std::trunc(history_[T].I) + 1;
        history_[T].R = std::trunc(history_[T].R) + 1;
        history_[T].E = std::trunc(history_[T].E);
        history_[T].S = std::trunc(history_[T].S);
        break;

}
    }
//fine caso residuetot=2
//inizio caso residuetot=1
else {
    if (residuetot==1) {
        switch (count)
        {
        case 31:
        case 32:
        case 33:
        case 34:
        case 35:
        case 36:
            history_[T].S=std::trunc(history_[T].S)+1;
            history_[T].E=std::trunc(history_[T].E);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            break;
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
            history_[T].E=std::trunc(history_[T].E)+1;
            history_[T].S=std::trunc(history_[T].S);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].R=std::trunc(history_[T].R);
            break;
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:           
            history_[T].I=std::trunc(history_[T].I)+1;
            history_[T].E=std::trunc(history_[T].E);
            history_[T].S=std::trunc(history_[T].S);
            history_[T].R=std::trunc(history_[T].R);
            break;
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
            history_[T].R=std::trunc(history_[T].R)+1;
            history_[T].E=std::trunc(history_[T].E);
            history_[T].I=std::trunc(history_[T].I);
            history_[T].S=std::trunc(history_[T].S);
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

SEIR SEIR_model::publish(int T) {
     SEIR r {history_[T].S,history_[T].E,history_[T].I,history_[T].R};
    return r;
}
