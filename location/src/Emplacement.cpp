#include <iostream>
#include "Emplacement.h"

using namespace std;

Emplacement::Emplacement(const double &x, const double &y){
    abs = x;
    ord = y;
}
Emplacement::~Emplacement(){

}

void Emplacement::afficher(){
    cout << "(" << abs << ", " << ord << ")";
}

void Emplacement::echange(){
    double aux = abs;
    abs = ord;
    ord = aux;
}
