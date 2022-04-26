#include <iostream>
#include "include/polynome.h"

using namespace std;

int main()
{
    Polynome *A, *B, *C, *D, *E, *F, *G, *H, *I, *J;
    A = B = C = D = E = F = G = H = I = J = initialiserPolynome();

    cout << "A\n";
    A = definirPolynome();
    cout << "\nB\n";
    B = definirPolynome();

    cout << "\nA(x) = ";
    afficherPolynome(A);
    cout << "\nB(x) = ";
    afficherPolynome(B);

    cout << "\n\nAjout de monomes a A\n";
    A = ajouterMonome(A, -1, 1);
    A = ajouterMonome(A, 3, 6);
    cout << "A(x) = ";
    afficherPolynome(A);

    cout << "\n\nSuppression de monomes de B\n";
    B = supprimerMonome(B, 2);
    B = supprimerMonome(B, 8);
    cout << "B(x) = ";
    afficherPolynome(B);

    C = moins(A);
    cout << "\n\nOppose de A\nC(x) = -A(x) = ";
    afficherPolynome(C);

    D = copie(C);
    cout << "\n\nCopie de C\nD(x) = C(x) = ";
    afficherPolynome(D);

    cout << "\ndeg(D) = " << degre(D) << endl;

    cout << "D(0) = " << evaluerPolynome(D, 0);
    cout << "\nD(-1) = " << evaluerPolynome(D, -1);

    cout << "\n\nA(x) = ";
    afficherPolynome(A);
    cout << "\nB(x) = ";
    afficherPolynome(B);

    E = add(A, B);
    F = sub(A, B);
    G = prod(A, B);
    H = div(A, B, 'Q');
    I = div(A, B, 'R');
    J = derivee(A);

    cout << "\n\nSomme\nE(x) = A(x) + B(x) = ";
    afficherPolynome(E);
    cout << "\n\nDifference\nF(x) = A(x) - B(x) = ";
    afficherPolynome(F);
    cout << "\n\nProduit\nG(x) = A(x) * B(x) = ";
    afficherPolynome(G);

    cout << "\n\nDivision euclidienne (A = B * Q + R)\n";
    afficherPolynome(A);
    cout << " = (";
    afficherPolynome(B);
    cout << ") * (";
    afficherPolynome(H);
    cout << ") + (";
    afficherPolynome(I);
    cout << ")";

    cout << "\n\nDerivee de A\nA'(x) = ";
    afficherPolynome(J);

    return 0;
}
