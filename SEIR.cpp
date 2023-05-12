
#include "SEIR.hpp"


// NOT SEIR_MODEL FUNCTIONS


//This function is needed to convert numbers under 1e-10 in to 0.0
double approx_zero(double value, double tolerance = 1e-10) {
  if (std::abs(value) < tolerance) {
    return 0.0;
  } else {
    return value;
  }
}
//This function is needed to convert in int type the double values S,E,I,R preserving N=S+E+I+R
SEIR approx(SEIR non_approx) { 
// we first evaluate the decimal part of every SEIR parameter
    double residueS=non_approx.S-std::trunc(non_approx.S);
    double residueE=non_approx.E-std::trunc(non_approx.E);
    double residueI=non_approx.I-std::trunc(non_approx.I);
    double residueR=non_approx.R-std::trunc(non_approx.R);
    double r = residueS+residueE+residueI+residueR;
// the total residue tells us how many integers we have to add to the trunc versions of S,E,I,R
    int residuetot = round(r);
//we will use count as a flag
    int count=0;
// rdm will be usefull in the case of equal decimal parts
    int rdm;
// we list all the possible cases 4!=24
count = (residueS>=residueI && residueI>=residueE && residueE>=residueR) ? 31 : count;
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

// case residuetot==3
    if (residuetot==3) {
switch (count) {
// E const
    case 31:case 32:case 36:case 45:case 48:case 51:case 54:

        non_approx.R = std::trunc(non_approx.R) + 1;
        non_approx.I = std::trunc(non_approx.I) + 1;
        non_approx.S = std::trunc(non_approx.S) + 1;
        non_approx.E = std::trunc(non_approx.E);
        break;

// R const
    case 33:case 38:case 42:case 46:case 47:

        non_approx.I = std::trunc(non_approx.I) + 1;
        non_approx.E = std::trunc(non_approx.E) + 1;
        non_approx.S = std::trunc(non_approx.S) + 1;
        non_approx.R = std::trunc(non_approx.R);
        break;

// I const
    case 34:case 35:case 40:case 41:case 52:case 53:

        non_approx.R = std::trunc(non_approx.R) + 1;
        non_approx.E = std::trunc(non_approx.E) + 1;
        non_approx.S = std::trunc(non_approx.S) + 1;
        non_approx.I = std::trunc(non_approx.I);
        break;

// S const
    case 37:case 39:case 43:case 44:case 49:case 50:

        non_approx.R = std::trunc(non_approx.R) + 1;
        non_approx.E = std::trunc(non_approx.E) + 1;
        non_approx.I = std::trunc(non_approx.I) + 1;
        non_approx.S = std::trunc(non_approx.S);
        break;

}
    }
//end of residuetot==3
//case residuetot==2
else {
// case all 0.5
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
 // IE const
    case 31:case 35:case 36:case 51:case 52:

        non_approx.S = std::trunc(non_approx.S) + 1;
        non_approx.R = std::trunc(non_approx.R) + 1;
        non_approx.I = std::trunc(non_approx.I);
        non_approx.E = std::trunc(non_approx.E);
        break;
// RE const
    case 32:case 45:case 46:

        non_approx.S = std::trunc(non_approx.S) + 1;
        non_approx.I = std::trunc(non_approx.I) + 1;
        non_approx.R = std::trunc(non_approx.R);
        non_approx.E = std::trunc(non_approx.E);
        break;
// IR const
    case 33:case 34:case 41:case 42:

        non_approx.S = std::trunc(non_approx.S) + 1;
        non_approx.E = std::trunc(non_approx.E) + 1;
        non_approx.I = std::trunc(non_approx.I);
        non_approx.R = std::trunc(non_approx.R);
        break;
// RS const
    case 37:case 38:case 44:case 47:

        non_approx.E = std::trunc(non_approx.E) + 1;
        non_approx.I = std::trunc(non_approx.I) + 1;
        non_approx.R = std::trunc(non_approx.R);
        non_approx.S = std::trunc(non_approx.S);
        break;
// IS const
    case 39:case 40:case 50:case 53:

        non_approx.E = std::trunc(non_approx.E) + 1;
        non_approx.R = std::trunc(non_approx.R) + 1;
        non_approx.I = std::trunc(non_approx.I);
        non_approx.S = std::trunc(non_approx.S);
        break;
// ES const
    case 43:case 48:case 49:case 54:

        non_approx.I = std::trunc(non_approx.I) + 1;
        non_approx.R = std::trunc(non_approx.R) + 1;
        non_approx.E = std::trunc(non_approx.E);
        non_approx.S = std::trunc(non_approx.S);
        break;

}
    }
//end of residuetot==2
//case residuetot==1
else {
    if (residuetot==1) {
        switch (count)
        {
// EIR const
        case 31:case 32:case 33:case 34:case 35:case 36:

            non_approx.S=std::trunc(non_approx.S)+1;
            non_approx.E=std::trunc(non_approx.E);
            non_approx.I=std::trunc(non_approx.I);
            non_approx.R=std::trunc(non_approx.R);
            break;
// SIR const
        case 37:case 38:case 39:case 40:case 41:case 42:

            non_approx.E=std::trunc(non_approx.E)+1;
            non_approx.S=std::trunc(non_approx.S);
            non_approx.I=std::trunc(non_approx.I);
            non_approx.R=std::trunc(non_approx.R);
            break;
// ESR const
        case 43:case 44:case 45:case 46:case 47:case 48:        

            non_approx.I=std::trunc(non_approx.I)+1;
            non_approx.E=std::trunc(non_approx.E);
            non_approx.S=std::trunc(non_approx.S);
            non_approx.R=std::trunc(non_approx.R);
            break;
// EIS const
        case 49:case 50:case 51:case 52:case 53:case 54:
        
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
// we use the already defined approx_zero to prevent the smallest possible double to "escape" trunc
    non_approx.R=approx_zero(non_approx.R);
    non_approx.E=approx_zero(non_approx.E);
    non_approx.I=approx_zero(non_approx.I);
    non_approx.S=approx_zero(non_approx.S);
 return non_approx;
}


// SEIR_MODEL FUNCTIONS 


// A simple contructor that initialize the parameters
SEIR_model::SEIR_model(SEIR SEIR_ini, float beta, float gamma, float mu, float a,int days) 
 : beta_(beta), gamma_(gamma), mu_(mu), a_(a), days_(days) {
    SEIR_ini = approx(SEIR_ini);
    N_ = SEIR_ini.S + SEIR_ini.E + SEIR_ini.I + SEIR_ini.R;
    history_.push_back(SEIR_ini);
 }

/*we opted for a boolean control so to make a switch control in the main for a correct object
initialization*/
bool SEIR_model::verify() {
        if (typeid(beta_) != typeid(float) || typeid(gamma_) != typeid(float) || typeid(mu_) != typeid(float) || typeid(a_) != typeid(float) ||
        beta_ < 0 || beta_ > 1 || gamma_ < 0 || gamma_ > 1 || mu_ < 0 || mu_ > 1|| a_ < 0 || a_ >1){
        std::cout<<"beta, gamma, mu and a must be between zero and one and positive"<<std::endl;
        return false;
    }

        if (round(history_[0].S) != history_[0].S || round(history_[0].I) != history_[0].I || round(history_[0].E) != history_[0].E || round(history_[0].R) != history_[0].R || 
        history_[0].S < 0 || history_[0].I < 0 || history_[0].E < 0 || history_[0].R < 0) {
        std::cout<<"S, I, E e R must be non-negative integer"<<std::endl;
        return false;
    }

    if (days_<0) {
        
        std::cout<<"number of days must be non-negative integer"<<std::endl;
        return false;
    }
    else {return true;}
    
}
// a trivial Euler discretization of the SEIR differential equations
void SEIR_model::evolve() {
    for (int i=0; i<days_; i++) {
        SEIR last = history_.back();
        SEIR next;
        next.S = mu_*N_+(last.S * (1-mu_))-(beta_*last.I*last.S/N_);
        next.E = last.E*(1-mu_-a_)+(beta_*last.I*last.S/N_);
        next.I = last.I*(1-gamma_-mu_)+(a_*last.E);
        next.R = last.R*(1-mu_)+(last.I*gamma_);
        history_.push_back(next);
    }
// we here approximate to integers (after the total evolution) in order not to have decimals of people
    for (int j=0; j<1+static_cast<int>(days_); j++) {
        history_[j] = approx(history_[j]);
    }
}
// a less trivial discretization through Runge-Kutta discretization of the SEIR differential equations
void SEIR_model::evolve_runge_kutta() {
    std::vector<double> K_S(4,0);
    std::vector<double> K_E(4,0);
    std::vector<double> K_I(4,0);
    std::vector<double> K_R(4,0);
    for (int i=0; i<days_; i++) {
        SEIR last = history_.back();
        SEIR next;

        K_S[0]= mu_*N_-(mu_*last.S)-(beta_*last.I*last.S/N_);
        K_E[0] = -last.E*(mu_+a_)+(beta_*last.I*last.S/N_);
        K_I[0] = -last.I*(gamma_+mu_)+(a_*last.E);
        K_R[0] = -(last.R*mu_)+(last.I*gamma_);

        K_S[1]= mu_*N_-(mu_*(last.S+K_S[0]/2))-(beta_*(last.I+K_I[0]/2)*(last.S+K_S[0]/2)/N_);
        K_E[1] = -(last.E+K_E[0]/2)*(mu_+a_)+(beta_*(last.I+K_I[0]/2)*(last.S+K_S[0]/2)/N_);
        K_I[1] = -(last.I+K_I[0]/2)*(gamma_+mu_)+(a_*(last.E+K_E[0]/2));
        K_R[1] = -((last.R+K_R[0]/2)*mu_)+((last.I+K_I[0]/2)*gamma_);


        K_S[2]= mu_*N_-(mu_*(last.S+K_S[1]/2))-(beta_*(last.I+K_I[1]/2)*(last.S+K_S[1]/2)/N_);
        K_E[2] = -(last.E+K_E[1]/2)*(mu_+a_)+(beta_*(last.I+K_I[1]/2)*(last.S+K_S[1]/2)/N_);
        K_I[2] = -(last.I+K_I[1]/2)*(gamma_+mu_)+(a_*(last.E+K_E[1]/2));
        K_R[2] = -((last.R+K_R[1]/2)*mu_)+((last.I+K_I[1]/2)*gamma_);

        K_S[3]= mu_*N_-(mu_*(last.S+K_S[2]))-(beta_*(last.I+K_I[2])*(last.S+K_S[2])/N_);
        K_E[3] = -(last.E+K_E[2])*(mu_+a_)+(beta_*(last.I+K_I[2])*(last.S+K_S[2])/N_);
        K_I[3] = -(last.I+K_I[2])*(gamma_+mu_)+(a_*(last.E+K_E[2]));
        K_R[3] = -((last.R+K_R[2])*mu_)+((last.I+K_I[2])*gamma_);

        next.S = (last.S+(K_S[0]+2*K_S[1]+2*K_S[2]+K_S[3])/6);
        next.E = (last.E+(K_E[0]+2*K_E[1]+2*K_E[2]+K_E[3])/6);
        next.I = (last.I+(K_I[0]+2*K_I[1]+2*K_I[2]+K_I[3])/6);
        next.R = (last.R+(K_R[0]+2*K_R[1]+2*K_R[2]+K_R[3])/6);
        history_.push_back(next);
    }
    for (int j=0; j<1+static_cast<int>(days_); j++) {
        history_[j] = approx(history_[j]);
    }
}

// a simple print function that prints in te terminal the D day or in the case of -1 the all days
void SEIR_model::print(int D) {
    if (D>=0) {
        std::cout<<"il numero di suscettibili è, nel giorno "<<D<<" : "<<history_[D].S<<std::endl;
        std::cout<<"il numero di infetti è, nel giorno "<<D<<" : "<<history_[D].I<<std::endl;
        std::cout<<"il numero di esposti è, nel giorno "<<D<<" : "<<history_[D].E<<std::endl;
        std::cout<<"il numero di recovered è, nel giorno "<<D<<" : "<<history_[D].R<<std::endl;
    }
    else {
    if (D==-1) {
        std::cout<<"GIORNO - Susceptible - Exposed - Infected - Recovered"<<std::endl;
    int N = days_;
    for (int i=0; i<N+1 ; i++) {
        std::cout<<"   "<<i<<"         "<<history_[i].S<<"          "<<history_[i].E<<"         "<<history_[i].I<<"          "<<history_[i].R<<"     "<<std::endl;
    }}
    }

}
// a simple function to save datas in the repository
void SEIR_model::print_out(std::string name) {
    std::ofstream output_file(name);
    if (output_file.is_open()) {
        output_file <<"GIORNO - Susceptible - Exposed - Infected - Recovered"<<std::endl;
        for (int i=0; i<days_; i++) {
            output_file <<"   "<<i<<"         "<<history_[i].S<<"          "<<history_[i].E<<"         "<<history_[i].I<<"          "<<history_[i].R<<"     "<<std::endl;

        }

    }
}
/*a function that return the SEIR struct of the T day in order to make comparison using the redefinition of the == operator for SEIR*/
SEIR SEIR_model::daily_seir(int T) {
     SEIR r {history_[T].S,history_[T].E,history_[T].I,history_[T].R};
    return r;
}

// redefinition of = for SEIR_model objects
SEIR_model& SEIR_model::operator=(const SEIR_model& other) {
    if (this != &other) {
        beta_ = other.beta_;
        gamma_ = other.gamma_;
        mu_ = other.mu_;
        a_ = other.a_;
        days_ = other.days_;
        N_ = other.N_;
        history_ = other.history_;
    }

 return *this;
}
