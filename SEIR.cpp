
#include "SEIR.hpp"


double approx_zero(double value, double tolerance = 1e-10) {
  if (std::abs(value) < tolerance) {
    return 0.0;
  } else {
    return value;
  }
}
//ci sono cout da eliminnare sia subito che subito prima del primo if
SEIR approx(SEIR non_approx) {

    double residueS=non_approx.S-std::trunc(non_approx.S);
    double residueE=non_approx.E-std::trunc(non_approx.E);
    double residueI=non_approx.I-std::trunc(non_approx.I);
    double residueR=non_approx.R-std::trunc(non_approx.R);
    double r = residueS+residueE+residueI+residueR;
    int residuetot = round(r);
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
//infine l'ultimo caso è residuetot=3 dove ho paura che bisognerà rifare tutto riversato, però necessariamente ho tre >0.5, quindi basta metterli in ordine e l'ultimo per difetto

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
        non_approx.R = std::trunc(non_approx.R) + 1;
        non_approx.I = std::trunc(non_approx.I) + 1;
        non_approx.S = std::trunc(non_approx.S) + 1;
        non_approx.E = std::trunc(non_approx.E);
        break;

// R invariata
    case 33:
    case 38:
    case 42:
    case 46:
    case 47:
        non_approx.I = std::trunc(non_approx.I) + 1;
        non_approx.E = std::trunc(non_approx.E) + 1;
        non_approx.S = std::trunc(non_approx.S) + 1;
        non_approx.R = std::trunc(non_approx.R);
        break;

// I invariata
    case 34:
    case 35:
    case 40:
    case 41:
    case 52:
    case 53:
        non_approx.R = std::trunc(non_approx.R) + 1;
        non_approx.E = std::trunc(non_approx.E) + 1;
        non_approx.S = std::trunc(non_approx.S) + 1;
        non_approx.I = std::trunc(non_approx.I);
        break;

// S invariata
    case 37:
    case 39:
    case 43:
    case 44:
    case 49:
    case 50:
        non_approx.R = std::trunc(non_approx.R) + 1;
        non_approx.E = std::trunc(non_approx.E) + 1;
        non_approx.I = std::trunc(non_approx.I) + 1;
        non_approx.S = std::trunc(non_approx.S);
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
        non_approx.S=std::trunc(non_approx.S)+1;
        non_approx.I=std::trunc(non_approx.I)+1;
        count=55;
        break;
    case 2:
        non_approx.E=std::trunc(non_approx.E)+1;
        non_approx.S=std::trunc(non_approx.S)+1;
        count=56;
        break;
    case 3:
        non_approx.R=std::trunc(non_approx.R)+1;
        non_approx.S=std::trunc(non_approx.S)+1;
        count=57;
        break;
    case 4:
        non_approx.R=std::trunc(non_approx.R)+1;
        non_approx.E=std::trunc(non_approx.E)+1;
        count=58;
    case 5:
        non_approx.R=std::trunc(non_approx.R)+1;
        non_approx.I=std::trunc(non_approx.I)+1;
        count=59;
        break;
    case 6:
        non_approx.I=std::trunc(non_approx.I)+1;
        non_approx.E=std::trunc(non_approx.E)+1;
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
        non_approx.S = std::trunc(non_approx.S) + 1;
        non_approx.R = std::trunc(non_approx.R) + 1;
        non_approx.I = std::trunc(non_approx.I);
        non_approx.E = std::trunc(non_approx.E);
        break;
// RE invariati case 45,46,
    case 32:
    case 45:
    case 46:
        non_approx.S = std::trunc(non_approx.S) + 1;
        non_approx.I = std::trunc(non_approx.I) + 1;
        non_approx.R = std::trunc(non_approx.R);
        non_approx.E = std::trunc(non_approx.E);
        break;
// IR invariati 34, 41,42,
    case 33:
    case 34:
    case 41:
    case 42:
        non_approx.S = std::trunc(non_approx.S) + 1;
        non_approx.E = std::trunc(non_approx.E) + 1;
        non_approx.I = std::trunc(non_approx.I);
        non_approx.R = std::trunc(non_approx.R);
        break;
// RS invariati case 38,44,47,
    case 37:
    case 38:
    case 44:
    case 47:
        non_approx.E = std::trunc(non_approx.E) + 1;
        non_approx.I = std::trunc(non_approx.I) + 1;
        non_approx.R = std::trunc(non_approx.R);
        non_approx.S = std::trunc(non_approx.S);
        break;
// IS invariati case 40,50,53,
    case 39:
    case 40:
    case 50:
    case 53:
        non_approx.E = std::trunc(non_approx.E) + 1;
        non_approx.R = std::trunc(non_approx.R) + 1;
        non_approx.I = std::trunc(non_approx.I);
        non_approx.S = std::trunc(non_approx.S);
        break;
// ES invariati 48,49,54
    case 43:
    case 48:
    case 49:
    case 54:
        non_approx.I = std::trunc(non_approx.I) + 1;
        non_approx.R = std::trunc(non_approx.R) + 1;
        non_approx.E = std::trunc(non_approx.E);
        non_approx.S = std::trunc(non_approx.S);
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
            non_approx.S=std::trunc(non_approx.S)+1;
            non_approx.E=std::trunc(non_approx.E);
            non_approx.I=std::trunc(non_approx.I);
            non_approx.R=std::trunc(non_approx.R);
            break;
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
            non_approx.E=std::trunc(non_approx.E)+1;
            non_approx.S=std::trunc(non_approx.S);
            non_approx.I=std::trunc(non_approx.I);
            non_approx.R=std::trunc(non_approx.R);
            break;
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 48:           
            non_approx.I=std::trunc(non_approx.I)+1;
            non_approx.E=std::trunc(non_approx.E);
            non_approx.S=std::trunc(non_approx.S);
            non_approx.R=std::trunc(non_approx.R);
            break;
        case 49:
        case 50:
        case 51:
        case 52:
        case 53:
        case 54:
            non_approx.R=std::trunc(non_approx.R)+1;
            non_approx.E=std::trunc(non_approx.E);
            non_approx.I=std::trunc(non_approx.I);
            non_approx.S=std::trunc(non_approx.S);
            break; 
        }
    }
}
 }
}
    non_approx.R=approx_zero(non_approx.R);
    non_approx.E=approx_zero(non_approx.E);
    non_approx.I=approx_zero(non_approx.I);
    non_approx.S=approx_zero(non_approx.S);
 return non_approx;
 }


SEIR_model::SEIR_model(SEIR SEIR_ini, const float beta, const float gamma, const float mu, const float a, const unsigned int days) 
 : beta_(beta), gamma_(gamma), mu_(mu), a_(a), days_(days) {
    SEIR_ini = approx(SEIR_ini);
    N_ = SEIR_ini.S + SEIR_ini.E + SEIR_ini.I + SEIR_ini.R;
    history_.push_back(SEIR_ini);
 }
 
bool SEIR_model::verify() {
        if (typeid(beta_) != typeid(const float) || typeid(gamma_) != typeid(const float) || typeid(mu_) != typeid(const float) || typeid(a_) != typeid(const float) ||
        beta_ < 0 || beta_ > 1 || gamma_ < 0 || gamma_ > 1 || mu_ < 0 || mu_ > 1|| a_ < 0 || a_ >1){
        std::cout<<"beta, gamma, mu and a must be between zero and one and positive"<<std::endl;
        return false;
    }

        if (round(history_[0].S) != history_[0].S || round(history_[0].I) != history_[0].I || round(history_[0].E) != history_[0].E || round(history_[0].R) != history_[0].R || 
        history_[0].S < 0 || history_[0].I < 0 || history_[0].E < 0 || history_[0].R < 0) {
        std::cout<<"S, I, E e R must be non-negative integer"<<std::endl;
        return false;
    }

    if (typeid(days_) != typeid(unsigned int)) {
        std::cout<<"number of days must be non-negative integer"<<std::endl;
        return false;
    }
    else {return true;}
    
}

void SEIR_model::evolve() {
    for (int i=0; i<static_cast<int>(days_); i++) {
        SEIR last = history_.back();
        SEIR next;
        next.S = mu_*N_+(last.S * (1-mu_))-(beta_*last.I*last.S/N_);
        next.E = last.E*(1-mu_-a_)+(beta_*last.I*last.S/N_);
        next.I = last.I*(1-gamma_-mu_)+(a_*last.E);
        next.R = last.R*(1-mu_)+(last.I*gamma_);
        std::cout<<"i suscettibili al giorno "<<i+1<<"sono"<<next.S<<std::endl;
        std::cout<<"gli esposti al giorno "<<i+1<<"sono"<<next.E<<std::endl;
        std::cout<<"gli infetti al giorno "<<i+1<<"sono"<<next.I<<std::endl;
        std::cout<<"i curati al giorno "<<i+1<<"sono"<<next.R<<std::endl;
        std::cout<<"i suscettibili al giorno approssimati"<<i+1<<"sono"<<next.S<<std::endl;
        std::cout<<"gli esposti al giorno approssimati"<<i+1<<"sono"<<next.E<<std::endl;
        std::cout<<"gli infetti al giorno approssimati"<<i+1<<"sono"<<next.I<<std::endl;
        std::cout<<"i curati al giorno approssimati"<<i+1<<"sono"<<next.R<<std::endl;
        history_.push_back(next);
    }
    for (int j=0; j<1+static_cast<int>(days_); j++) {
        history_[j] = approx(history_[j]);
    }
}
void SEIR_model::print() {
    int N = days_;
    for (int i=0; i<N+1 ; i++) {
        std::cout<<"il numero di suscettibili è, nel giorno "<<i<<", :"<<history_[i].S<<std::endl;
        std::cout<<"il numero di infetti è, nel giorno "<<i<<", :"<<history_[i].I<<std::endl;
        std::cout<<"il numero di esposti è, nel giorno "<<i<<" :"<<history_[i].E<<std::endl;
        std::cout<<"il numero di recovered è, nel giorno "<<i<<" :"<<history_[i].R<<std::endl;

    }
    

}

SEIR SEIR_model::daily_seir(int T) {
     SEIR r {history_[T].S,history_[T].E,history_[T].I,history_[T].R};
    return r;
}


