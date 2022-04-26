#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include "utils.h"
#include "etudiant.h"

using namespace std;

int main(){
    int choix, repeter;
    vector<Etudiant> etudiants;

    do{
        etudiants = importer();
        
        cout << "\n\n\n\n\n~ ~ ~ ~ ~ ~ ~ ~ ~ ~ CLASSE DE LICENCE 2 - ESSFAR - 2020/2021 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
        cout << "\t1. AJOUTER UN ETUDIANT\n";
        cout << "\t2. AFFICHER LA LISTE DES ETUDIANTS\n";
        cout << "\t3. MODIFIER LES INFORMATIONS D'UN ETUDIANT\n";
        cout << "\t4. SUPPRIMER UN ETUDIANT\n";
        cout << "VEUILLEZ CHOISIR UNE ACTION A EXECUTER : ";
        cin >> choix;
        cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";

        switch(choix){
            case 1: ajouter(etudiants); break;
            case 2: lister(etudiants); break;
            case 3: modifier(etudiants); break;
            case 4: supprimer(); break;
            default:
                cout << "\tCHOIX INDISPONIBLE\n";
                cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";
                break;
        }

        cout << "SOUHAITEZ-VOUS EFFECTUER UN AUTRE TRAITEMENT ?\n\t\t    1. Oui\n\tAutre chiffre. Non\n";
        cout << "VEUILLEZ CHOISIR UNE ACTION A EXECUTER : ";
        cin >> repeter;
    }while(repeter == 1);

    return 0;
}
