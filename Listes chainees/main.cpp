#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct etu{
    string nom;
    int age;
    int niveau;
} Etudiant;

typedef struct maliste{
    Etudiant e;
    maliste *suiv;
} liste;

// Inserer en tete de liste
liste *insererTete(liste *l, Etudiant et){
    liste *r;
    r = (maliste *)malloc(sizeof(maliste)); // OU r = new maliste;
    r -> e = et;
    r -> suiv = l;
    l = r;

    return l;
}

// Inserer en queue de liste
liste *insererQueue(liste *l, Etudiant et){
    liste *r, *t;

    r = new maliste;
    r -> e = et;

    if(l == NULL){
        l = r;
        l -> suiv = NULL;
        return l;
    }

    t = l;
    while(t -> suiv != NULL){
        t = t -> suiv;
    }
    t -> suiv = r;
    r -> suiv = NULL;
    return l;
}

// Supprimer la tete
liste *supprimerTete(liste *l){
    if(l != NULL){
        liste *r;
        r = l;
        l = l -> suiv;
        free(r);
    }
    return l;
}

// Supprimer la queue
liste *supprimerQueue(liste *l){
    liste *t, *pp;
    t = l;

    if(t == NULL)
        return t;

    if(t -> suiv == NULL){
        free(t);
        t = NULL;
        return t;
    }

    while(t -> suiv != NULL){
        pp = t;
        t = t -> suiv;
    }
    free(t);
    pp = NULL;
    return l;
}

int main()
{
    liste *l;
    l = (maliste *)malloc(sizeof(maliste));
    (*l).suiv = NULL; // OU l -> suiv = NULL

    l -> e.nom = "Baba";
    l -> e.age = 10;
    l -> e.niveau = 2;

    return 0;
}
