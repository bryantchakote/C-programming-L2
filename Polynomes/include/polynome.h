#ifndef POLYNOME_H
#define POLYNOME_H
#include <vector>

using namespace std;

struct polynome{
    int deg;                // Degre du polynome
    double coef;            // Coefficient du polynome
    struct polynome * next; // Pointeur sur un element de type polynome
};

typedef struct polynome Polynome;   // Creation du type Polynome

// Initialiser un polynome
Polynome *initialiserPolynome();

// Definir un polynome
Polynome *definirPolynome();

// Copier un polynome
Polynome *copie(Polynome *);

// Oppose d'un polynome
Polynome *moins(Polynome *);

// Degre d'un polynome
double degre(Polynome *);

// Afficher un polynome
void afficherPolynome(Polynome *);

// Ajouter un monome
Polynome *ajouterMonome(Polynome *, double, int);

// Supprimer un monome
Polynome *supprimerMonome(Polynome *, int);

// Evaluer un polynome
double evaluerPolynome(Polynome *, double);

// Somme de deux polynomes
Polynome *add(Polynome *, Polynome *);

// Difference de deux polynomes
Polynome *sub(Polynome *, Polynome *);

// Produit de deux monomes
Polynome *produitMonomes(double, int, double, int);

// Produit de deux polynomes
Polynome *prod(Polynome *, Polynome *);

//Rapport de deux polynomes
Polynome *div(Polynome *, Polynome *, char);

// Derivee d'un polynome
Polynome *derivee(Polynome *);

#endif // POLYNOME_H
