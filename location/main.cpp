#include <iostream>
#include "Emplacement.h"
#include "Point.h"

using namespace std;

int main()
{
    Emplacement x, y(1, 5);
    Point z(-1, 0, "rouge");

    cout << "x = ";
    x.afficher();

    cout << "\ny = ";
    y.afficher();

    cout << "\n\nAvant z = ";
    z.afficher();
    z.echange();
    cout << "\nApres z = ";
    z.afficher();
    cout << "\n(Emplacement) z = ";
    z.Emplacement::afficher();
    cout << endl;

    return 0;
}
