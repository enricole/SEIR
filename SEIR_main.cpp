 #include "SEIR.hpp"
 #include "SEIR_graph.hpp"
using std::cout;
using std::cin;
using std::endl;

 int main() {
    double s,e,i,r;
    double a,b,c,d;
    int f;


    cout<<"dimmi beta"<<endl;
    cin>>a;
    cout<<"dimmi gamma"<<endl;
    cin>>b;
    cout<<"dimmi mu"<<endl;
    cin>>c;
    cout<<"dimmi a"<<endl;
    cin>>d;
    cout<<"dimmi i giorni"<<endl;
    cin>>f;
    cout<<"dimmi i suscettibili"<<endl;
    cin>>s;
    cout<<"dimmi gli infetti"<<endl;
    cin>>i;
    cout<<"dimmi gli esposti"<<endl;
    cin>>e;
    cout<<"dimmi i curati"<<endl;
    cin>>r;
    SEIR seirprova{s, e, i, r};
    SEIR_graph modello1(seirprova, a, b, c, d, f);
    SEIR_graph modello2(seirprova, a, b, c, d, f);
    modello1.verify();
    modello1.evolve_runge_kutta();
    modello1.print();
    modello1.print_out("evolve_runge_kutta.txt");
    modello2.evolve();
    modello2.print_out("evolve_std.txt");
    modello1.graph("SEIR_RK.png","SEIR_RK_O.png");
    modello2.graph("SEIR.png", "SEIR_O.png");

    return 0;
 }
