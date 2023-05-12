 #include "SEIR.hpp"
 #include "SEIR_graph.hpp"
using std::cout;
using std::cin;
using std::endl;

 int main() {
    double s,e,i,r;
    double Beta,Gamma,Mu,a;
    int Days;
    int Day;
    cout<<"Set the number of susceptible"<<endl; cin>>s;
    cout<<"Set the number of exposed"<<endl; cin>>e;
    cout<<"Set the number of infected"<<endl; cin>>i;
    cout<<"Set the number of recovered"<<endl; cin>>r;
    cout<<"Set beta value"<<endl; cin>>Beta;
    cout<<"Set gamma value"<<endl; cin>>Gamma;
    cout<<"Set mu value"<<endl; cin>>Mu;
    cout<<"Set a value"<<endl; cin>>a;
    cout<<"Set number of days of the simulation"<<endl; cin>>Days;
   SEIR SEIR_setted{s, e, i, r};
   SEIR_graph model1 (SEIR_setted, Beta, Gamma, Mu, a, Days);
   while (model1.verify()==false) {
    cout<<"Set the number of susceptible"<<endl; cin>>s;
    cout<<"Set the number of exposed"<<endl; cin>>e;
    cout<<"Set the number of infected"<<endl; cin>>i;
    cout<<"Set the number of recovered"<<endl; cin>>r;
    cout<<"Set beta value"<<endl; cin>>Beta;
    cout<<"Set gamma value"<<endl; cin>>Gamma;
    cout<<"Set mu value"<<endl; cin>>Mu;
    cout<<"Set a value"<<endl; cin>>a;
    cout<<"Set number of days of the simulation"<<endl; cin>>Days;
    SEIR SEIR_verify{s, e, i, r};
    SEIR_graph model0 (SEIR_verify, Beta, Gamma, Mu, a, Days);
    model1 = model0;
   }
   SEIR_graph model2 (SEIR_setted, Beta, Gamma, Mu, a, Days);
    model1.evolve_runge_kutta();
    model2.evolve();
    cout<<"Set the day you want to print"<<endl;
    cin>>Day;
    model1.print(Day);
    model1.print_out("evolve_runge_kutta.txt");
    model2.print_out("evolve_euler.txt");
    model1.graph("SEIR_RK.png","SEIR_RK_O.png");
    model2.graph("SEIR.png", "SEIR_O.png");

    return 0;
 }
