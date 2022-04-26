#include <iostream>
#include "complexe.h"
#include "autres.h"

using namespace std;

int main(){
    double reel, imag;
    cout << "Nous allons travailler avec des nombres complexes" << endl;
    cout << "Lisons un complexe" << endl;
    reel = lireNombre("réelle");
    imag = lireNombre("imaginaire");
    Complexe c(reel, imag);
    cout << "Le complexe lu est ";
    c.displayStyle1();
    cout << "\nSon conjugué est ";
    c.conjugue().displayStyle1();
    cout << "\nSon module est " << c.module();
    cout << "\nSon argument est " << c.arg();
    return 0;
}
