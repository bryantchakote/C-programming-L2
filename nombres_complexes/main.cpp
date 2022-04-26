#include <iostream>
#include "Complexe.h"

using namespace std;

void second_degre(double a, double b, double c)
{
    Complexe z1, z2;
    double D, d;

    if(a == 0)
    {
        cout << "L'equation n'est pas du second degre!" << endl;
        return;
    }

    D = b*b - 4*a*c;

    if(D == 0)
    {
        Complexe z1(-b/(2*a), 0);
        cout << "L'unique solution de l'equation est : ";
        z1.disp();
        cout << endl;
        return;
    }
    if(D < 0)
    {
        d = sqrt(-D);
        Complexe z1(-b/(2*a), d/(2*a));
        Complexe z2(-b/(2*a), -d/(2*a));
        cout << "Les solutions de l'equation sont les complexes : ";
        z1.disp();
        cout << " et ";
        z2.disp();
        cout << endl;
        return;
    }
    if(D > 0)
    {
        d = sqrt(D);
        Complexe z1((-b-d)/(2*a), 0);
        Complexe z2((-b+d)/(2*a), 0);
        cout << "Les solutions de l'equation sont les reels : ";
        z1.disp();
        cout << " et ";
        z2.disp();
        cout << endl;
        return;
    }
}

int main()
{
    Complexe z, z1(1, 1), z2(0, -1), z3(-1, 2);

    // 0
    cout << "Nombre complexe nul : ";
    z.disp();

    // Re, Im, Conj, Arg, Opp
    cout << "\n\nz1 = ";
    z1.disp();
    cout << "\nPartie reelle = " << z1.get_Re() << " ~ Partie imaginaire = " << z1.get_Im();
    cout << "\nModule = " << z1.get_mod() << " ~ Argument = " << z1.get_arg();
    cout << "\nConjugue = ";
    z1.conj().disp();
    cout << "\t-z1 = ";
    (-z1).disp();

    // Somme de deux complexes
    cout << "\n\nz2 = ";
    z2.disp();
    cout << " et z3 = ";
    z3.disp();
    cout << "\nz2 + z3 = ";
    z2.sum(z3).disp();
    cout << " = ";
    sum(z2, z3).disp();
    cout << " = ";
    (z2 + z3).disp();

    // Produit de deux complexes
    cout << "\n\n(";
    z1.disp();
    cout << ") * (";
    z3.disp();
    cout << ") = ";
    z1.mul(z3).disp();
    cout << " = ";
    mul(z1, z3).disp();
    cout << " = ";
    (z1 * z3).disp();

    // Produit par un scalaire
    cout << "\n\n2 * (";
    z3.disp();
    cout << ") = (";
    z3.disp();
    cout << ") * 2 = ";
    (2 * z3).disp();
    cout << " = ";
    (z3 * 2.0).disp();

    // Division de deux complexes
    cout << "\n\n(";
    z3.disp();
    cout << ") / (";
    z2.disp();
    cout << ") = ";
    z3.div(z2).disp();
    cout << " = ";
    div(z3, z2).disp();
    cout << " = ";
    (z3 / z2).disp();


    // Division d'un scalaire par un complexe
    cout << "\n\n2 / (";
    z2.disp();
    cout << ") = ";
    (2 / z2).disp();

    // Division d'un complexe par un scalaire
    cout << "\n\n(";
    z2.disp();
    cout << ") / 3 = ";
    (z2 / 3).disp();

    cout << endl;

    return 0;
}
