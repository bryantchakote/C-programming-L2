#include <iostream>
#include <string>
#include "funct.h"
#include "Point.h"

using namespace std;
using std::string;

int main()
{
    /*
    double a, b;
    cout << "Entrez un nombre a : ";
    cin >> a;
    cout << "Entrez un nombre b : ";
    cin >> b;
    cout << "Valeur absolue de a : |" << a << "| = " << myAbs(a) << endl;
    cout << "Valeur absolue de b : |" << b << "| = " << myAbs(b) << endl;
    cout << "Max(" << a << ", " << b << ") = " << myMax(a, b) << endl;


    string str1, str2;
    cout << "Saisir un texte : ";
    getline(cin, str1);
    cout << "Saisir un texte : ";
    getline(cin, str2);
    cout << "Textes concatenes : " << str1 + str2 << endl;
    cout << "Longueur de '"<< str1 << "' : " << str1.size() << endl;

    */
    int a = 1, b = -3, c = -2, d = 1;
    double distance, distance_2;
    Point p(a, b), q(c, d);
    //cout << "Avant le deplacement : "; p.afficher();
    //p.deplacer(c, d);
    //cout << "Avant le deplacement : "; p.afficher();

    /*
    distance = dist(p, q);
    cout << "p = (" << p.Getabs() << ", " << p.Getord() << "), q = (" << q.Getabs() << ", " << q.Getord() << ")\n";
    cout << "d(p,q) = " << distance;
    */
    distance_2 = p.dist_2(q);
    cout << "p = (" << p.Getabs() << ", " << p.Getord() << "), q = (" << q.Getabs() << ", " << q.Getord() << ")\n";
    cout << "d_2(p,q) = " << distance_2;

    return 0;
}
