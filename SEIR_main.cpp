 #include "SEIR.hpp"
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
    SEIR_model modello1(seirprova, a, b, c, d, f);
    modello1.approx(0);
    modello1.print();
    return 0;
 }
