#include "autres.h"
#include <iostream>
using namespace std;

Complexe lireComplexe(){
    double reel, imag;
    cout << "Partie réelle= ";
    cin >> reel;
    cout << "Partie imaginaire= ";
    cin >> imag;
    return Complexe(reel, imag);
}

double lireNombre(char texte[]){
    double nbr;
    cout << "Partie " << texte <<" = ";
    cin >> nbr;
    return nbr;
}
