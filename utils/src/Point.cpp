#include <iostream>
#include <cmath>
#include "Point.h"


using namespace std;

Point::Point(int x, int y)
{
    //ctor
    abs = x;
    ord = y;
}

Point::~Point()
{
    //dtor
}

void Point::deplacer(int dx, int dy){
    abs += dx;
    ord += dy;
}

void Point::afficher(){
    cout << "(" << abs << ", " << ord << ")" << endl;
}

double Point::dist_2(const Point &b){
    return sqrt(pow(b.Getabs() - abs, 2) + pow(b.Getord() - ord, 2));
}

double dist(const Point &a, const Point &b){
    return sqrt(pow(b.abs - a.abs, 2) + pow(b.ord - a.ord, 2));
}
