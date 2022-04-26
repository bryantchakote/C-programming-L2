#include "complexe.h"
#include <iostream>
#include <cmath>


using namespace std;

Complexe::Complexe(const double& x, const double& y){
    //ctor
    re = x;
    im = y;
}

Complexe::~Complexe(){
    //dtor
}

Complexe::Complexe(const Complexe& other){
    //copy ctor
    re = other.re;
    im = other.im;
}

Complexe& Complexe::operator=(const Complexe& rhs){
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

void Complexe::displayStyle1(){
    if(re==0.0)
        if (im == 0.0)
            cout << 0.0;
        else
            cout << im << "i";
    else
        if(im == 0)
            cout << re ;
        else if (im < 0)
            cout << re << im << "i";
        else
            cout << re << "+" << im << "i";
}
void Complexe::displayStyle2(){
    cout << "(" << re <<", " << im <<")";
}

double Complexe::module(){
    return sqrt(re*re+im*im);
}

double Complexe::arg(){
    return atan(im/re);
}
Complexe Complexe::conjugue(){
    return Complexe(re, -im);
}
