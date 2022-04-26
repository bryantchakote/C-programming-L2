#include <iostream>
#include "Point.h"

Point::Point(const double & x, const double & y, const string & c)
{
    //ctor
    abs = x;
    ord = y;
    couleur = c;
}

Point::~Point()
{
    //dtor
}

void Point::afficher(){
    cout << "(" << abs << ", " << ord << ", " << couleur << ")";
}
