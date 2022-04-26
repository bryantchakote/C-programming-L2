#include <iostream>
#include "Complexe.h"

using namespace std;

// Constructors
Complexe::Complexe(){
    set_Re(0);
    set_Im(0);
    set_mod();
    set_arg();
}
Complexe::Complexe(double a, double b){
    set_Re(a);
    set_Im(b);
    set_mod();
    set_arg();
}

// Utils
void Complexe::disp(){
    if(Re == 0)
        if(Im == 0) cout << "0";
        else if(Im == 1) cout << "i";
        else if(Im == -1) cout << "-i";
        else cout << Im << "i";
    else{
        cout << Re;
        if(Im == 1) cout << "+i";
        else if(Im == -1) cout << "-i";
        else if(Im < 0) cout << Im << "i";
        else if(Im > 0) cout << "+" << Im << "i";
    }
    return;
}

Complexe::~Complexe(){

}
