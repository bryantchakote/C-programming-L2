#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <climits>
#include "../include/polynome.h"

using namespace std;

// Initialiser un polynome
Polynome *initialiserPolynome(){
    return NULL;
}

// Definir un polynome
Polynome *definirPolynome(){
    Polynome *P = initialiserPolynome();
    double c;
    int d;

    do{
        cout << "coef : ";
        cin >> c;
        if(c == 0)
            break;

        cout << "deg : ";
        cin >> d;
        if(d < -1)
            break;

        P = ajouterMonome(P, c, d);
        afficherPolynome(P);
        cout << "\n\n";
    }while(c != 0 && d != -1);

    return P;
}

// Copier un polynome
Polynome *copie(Polynome *P){
    Polynome *Q, *tmp = P;

    Q = initialiserPolynome();

    if(P == NULL)
        return P;

    while(P != NULL){
        Q = ajouterMonome(Q, P->coef, P->deg);
        P = P->next;
    }

    return Q;
}

// Oppose d'un polynome
Polynome *moins(Polynome *P){
    Polynome *Q = copie(P), *tmp = Q;

    if(P == NULL || degre(P) == -1)
        return P;

    while(tmp->next != NULL){
        tmp->coef *= -1;
        tmp = tmp->next;
    }

    tmp->coef *= -1;
    tmp = Q;

    return tmp;
}

// Degre d'un polynome
double degre(Polynome *P){
    if(P == NULL)
        return -2;

    return P->deg;
}

// Afficher un polynome
void afficherPolynome(Polynome *P){
    Polynome *tmp = P;

    if(P == NULL){
        cout << "Polynome vide!";
        return;
    }

    if(degre(P) == -1){
        cout << "0";
        return;
    }

    while(tmp != NULL){
        if(tmp->deg > 1){
            if(tmp->coef == 1)
                cout << "+X";
            else if(tmp->coef == -1)
                cout << "-X";
            else{
                if(tmp->coef > 0)
                    cout << "+";
                cout << tmp->coef << "X";
            }

            cout << tmp->deg << " ";
        }

        if(tmp->deg == 1){
            if(tmp->coef == 1)
                cout << "+X";
            else if(tmp->coef == -1)
                cout << "-X";
            else{
                if(tmp->coef > 0)
                    cout << "+";
                cout << tmp->coef << "X";
            }
        }
        cout << " ";

        if(tmp->deg == 0){
            if(tmp->coef > 0)
                cout << "+";
            cout << tmp->coef;
        }

        tmp = tmp->next;
    }
}

// Ajouter un monome
Polynome *ajouterMonome(Polynome *P, double c, int d){
    // Initialisation du monome a inserer
    Polynome *tmp = new Polynome;
    tmp->coef = c;
    tmp->deg = d;
    tmp->next = NULL;

    // Polynome null (P = 0)
    if(d == -1){
        tmp->coef = 0;
        tmp->deg = -1;
        tmp->next = NULL;
        return tmp;
    }

    // Cas limite 1
    if(P == NULL)
        return tmp;

    // Cas limite 2
    if(P->next == NULL){
        if(P->deg == d){
            if(P->coef + c == 0.0)
                tmp = produitMonomes(0, 0, 0, 0);
            else
                tmp->coef += P->coef;
        }

        else if(P->deg > d){
            P->next = tmp;
            tmp = P;
        }
        else
            tmp->next = P;

        return tmp;
    }

    // Autres cas possibles
    Polynome *f, *b;

    f = b = P;
    while(f->next != NULL){
        if((f->deg) > d){
            b = f;
            f = f->next;
        }
        else if((f->deg) < d){
            if(f == P){
                tmp->next = P;
            }
            else{
                tmp->next = f;
                b->next = tmp;
                tmp = P;
            }
            return tmp;
        }
        else{
            if(f->coef + c == 0.0){
                if(f == P)
                    P = P->next;

                else
                    b->next = f->next;
            }
            else
                f->coef += c;

            tmp = P;
            return tmp;
        }

    }

    // Si le suivant de f est null
    if((f->deg) > d){
        f->next = tmp;
    }
    else if((f->deg) < d){
        b->next = tmp;
        tmp->next = f;
    }
    else{
        if(f->coef + c == 0.0)
            b->next = NULL;

        else
            f->coef += c;
    }
    tmp = P;
    return tmp;
}

// Supprimer un monome
Polynome *supprimerMonome(Polynome *P, int d){
    Polynome *tmp = copie(P);

    if(tmp == NULL)
        return tmp;

    if(tmp->next == NULL){
        if(tmp->deg != d)
            return tmp;
        return NULL;
    }

    Polynome *f, *b;
    f = b = tmp;
    while(f->next != NULL){
        if(f->deg < d)
            return tmp;

        if(f->deg > d){
            b = f;
            f = f->next;
        }

        if(f->deg == d){
            if(f == tmp)
                tmp = tmp->next;
            else
                b->next = f->next;

            return tmp;
        }
    }
}

// Evaluer un polynome
double evaluerPolynome(Polynome *P, double x){
    double P_x = 0;

    if(P == NULL){
        cout << "Polynome vide" << endl;
        return NAN;
    }

    if(degre(P) == -1)
        return 0;

    while(P != NULL){
        P_x += P->coef * pow(x, P->deg);
        P = P->next;
    }
    return P_x;
}

// Somme de deux polynomes
Polynome *add(Polynome *P, Polynome *Q){
    if(P == NULL || degre(P) == -1)
        return Q;
    if(Q == NULL || degre(Q) == -1)
        return P;

    Polynome *S, *U, *R;
    S = U = initialiserPolynome();

    R = P;
    do{
        S = ajouterMonome(S, R->coef, R->deg);
        U = R;
        R = R->next;
    }
    while(U->next != NULL);

    R = Q;
    do{
        S = ajouterMonome(S, R->coef, R->deg);
        U = R;
        R = R->next;
    }
    while(U->next != NULL);

    return S;
}

// Difference de deux polynomes
Polynome *sub(Polynome *P, Polynome *Q){
    return add(P, moins(Q));
}

// Produit de deux monomes
Polynome *produitMonomes(double c1, int d1, double c2, int d2){
    Polynome *P = new Polynome;

    P->coef = c1 * c2;
    P->deg = d1 + d2;
    P->next = NULL;

    if(P->coef == 0)
        P->deg = -1;

    return P;
}

// Produit de deux polynomes
Polynome *prod(Polynome *P, Polynome *Q){
    if(P == NULL || Q == NULL)
        return NULL;

    if(degre(P) == -1 || degre(Q) == -1)
        return produitMonomes(0, 0, 0, 0);

    Polynome *R, *S, *T, *U, *V, *W = initialiserPolynome();

    R = P;
    do{
        S = Q;
        do{
            T = produitMonomes(R->coef, R->deg, S->coef, S->deg);
            W = ajouterMonome(W, T->coef, T->deg);
            U = S;
            S = S->next;
        }while(U->next != NULL);
        V = R;
        R = R->next;
    }while(V->next != NULL);

    return W;
}

//Rapport de deux polynomes
Polynome *div(Polynome *A, Polynome *B, char Q_R = 'Q'){
    if(A == NULL || B == NULL || degre(B) == -1)
        return NULL;

    Polynome *Q, *R, *S, *T;
    double c, d;

    Q = produitMonomes(0, 0, 0, 0);
    R = copie(A);

    if(degre(R) >= degre(B)){
        Q = NULL;
        do{
            T = S = NULL;
            c = R->coef / B->coef;
            d = R->deg - B->deg;
            Q = ajouterMonome(Q, c, d);
            T = ajouterMonome(T, c, d);
            S = prod(T, B);
            R = sub(R, S);
        }while(degre(R) >= degre(B));
    }

    if(Q_R == 'Q')
        return Q;

    if(Q_R == 'R')
        return R;

    return NULL;
}

// Derivee d'un polynome
Polynome *derivee(Polynome *P){
    double c;
    int d;
    Polynome *dP, *M = copie(P);
    dP = initialiserPolynome();

    if(P == NULL)
        return NULL;

    if(degre(P) == -1)
        return produitMonomes(0, 0, 0, 0);

    while(M->next != NULL){
        c = M->coef * M->deg;
        d = M->deg - 1;

        if(d >= 0)
            dP = ajouterMonome(dP, c, d);

        M = M->next;
    }

    c = M->coef * M->deg;
    d = M->deg - 1;

    if(d >= 0)
        dP = ajouterMonome(dP, c, d);

    return dP;
}
