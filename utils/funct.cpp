#include "funct.h"

double myAbs(double x){
    return (x > 0) ? x : -x;
}

void mySwap(double &x, double &y){
    double tmp = x;
    x = y;
    y = tmp;

    return;
}

double myMax(double x, double y){
    return (x > y) ? x : y;
}
