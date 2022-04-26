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

vector<string> split(const string &src, char delim)
{
   vector<string> v;
   auto p = begin(src);
   for(auto q = find(p, end(src), delim); q != end(src); q = find(++p, end(src), delim))
   {
      v.emplace_back(p, q);
      p = q;
   }
   if(p != end(src))
      v.emplace_back(p, end(src));
   return v;
}

vector<Etudiant> importer(){
    ifstream in_liste;
    string ligne;
    vector<string> infos_et;
    vector<Etudiant> etudiants;
    
    in_liste.open("liste_classe.txt");
    
    if(in_liste.fail()){
        cerr << "Impossible d'ouvrir le fichier\n";
        exit(1);
    }

    while(getline(in_liste, ligne)){
        infos_et = split(ligne, ',');
        Etudiant et(infos_et[0], infos_et[1], infos_et[2], infos_et[3][0], stoi(infos_et[4]), stof(infos_et[5]));
        etudiants.push_back(et);
    }

    in_liste.close();

    return etudiants;
}

void exporter(vector<Etudiant> ets){
    Etudiant et;
    int i, j;
    ofstream out_liste;

    out_liste.open("liste_classe.txt");

    if(out_liste.fail()){
        cerr << "Impossible d'ouvrir le fichier\n";
        exit(1);
    }

    for(i = 0; i < ets.size(); i++){
        et = ets[i];
        out_liste << et.get_matricule() << "," << et.get_nom() << "," << et.get_prenom() << "," << et.get_sexe() << "," << et.get_age() << "," << et.get_moyenne() << "\n"; 
    }

    out_liste.close();

    return;
}

Etudiant rechercher(vector<Etudiant> ets, string mat){
    Etudiant et;
    int i, found = -1;

    for(i = 0; i < ets.size(); i++){
        if(mat == ets[i].get_matricule()){
            found = i;
            break;
        }
    }

    if(found == -1){
        return et;
    }

    else return ets[found];
}


string entrer_matricule(vector<Etudiant> ets){
    string matricule;
    Etudiant et_existant;
    bool confirm_mat = 0;
    int i;
    do{
        cout << "Matricule     : ";
        getline(cin, matricule);
        et_existant = rechercher(ets, matricule);
        
        if(et_existant.get_matricule() != "00000000000")
            cout << "MATRICULE EXISTANT!\n";
        else{
            for(i = 0; i < matricule.size(); i++){
                if(matricule[i] < '0' || matricule[i] > '9' || matricule.size() != 11){
                    cout << "MATRICULE INVALIDE!\n";
                    i = matricule.size() + 1;
                }
            }
            if(i == matricule.size())
                confirm_mat = 1;
        }
    }while(!confirm_mat);

    return matricule;
}
string entrer_nom(){
    string nom;
    do{
        cout << "Nom           : ";
        getline(cin, nom);
        if(nom.size() > 50) cout << "NOM INVALIDE!\n";
    }while(nom.size() > 50);

    return nom;
}
string entrer_prenom(){
    string prenom;
    do{
        cout << "Prenom        : ";
        getline(cin, prenom);
        if(prenom.size() > 50) cout << "PRENOM INVALIDE!\n";
    }while(prenom.size() > 50);

    return prenom;
}
char entrer_sexe(){
    char sexe;
    do{
        cout << "Sexe (M ou F) : ";
        cin >> sexe;
        if(sexe != 'M' && sexe != 'm' && sexe != 'F' && sexe != 'f') cout << "SEXE INVALIDE!\n";
    }while(sexe != 'M' && sexe != 'm' && sexe != 'F' && sexe != 'f');

    return sexe;
}
int entrer_age(){
    int age;
    do{
        cout << "Age           : ";
        cin >> age;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(age < 14 || age > 36) cout << "AGE INVALUDE!\n";
    }while(age < 14 || age > 36);

    return age;
}
double entrer_moyenne(){
    double moyenne;
    do{
        cout << "Moyenne       : ";
        cin >> moyenne;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if(moyenne < 0 || moyenne > 20) cout << "MOYENNE INVALIDE\n";
    }while(moyenne < 0 || moyenne > 20);

    return moyenne;
}


void ajouter(vector<Etudiant> ets){
    string et_infos;
    Etudiant et;
    
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\tNOUVEL ETUDIANT\n";

    et.set_matricule(entrer_matricule(ets));
    et.set_nom(entrer_nom());
    et.set_prenom(entrer_prenom());
    et.set_sexe(entrer_sexe());
    et.set_age(entrer_age());
    et.set_moyenne(entrer_moyenne());    

    ets.push_back(et);

    exporter(ets);

    cout << "\tETUDIANT ENREGISTRE AVEC SUCCES!\n";
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";

    return;
}

void lister(vector<Etudiant> ets){
    int i, j;
    Etudiant et;

    cout << "\tLISTE DES ETUDIANTS\n";

    for(i = 0; i < ets.size(); i++){
        et = ets[i];
        cout << et.get_matricule() << "," << et.get_nom() << "," << et.get_prenom() << "," << et.get_sexe() << "," << et.get_age() << "," << et.get_moyenne() << "\n";
    }

    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";

    return;
}

void modifier(vector<Etudiant> ets){
    Etudiant et_existant;
    string mat;
    int i, found = -1, choix = 0;

    cout << "\tMODIFICATION D'UN ETUDIANT\n";

    cout << "MATRICULE DE L'ETUDIANT A MODIFIER : ";
    cin >> mat;

    et_existant = rechercher(ets, mat);

    if(et_existant.get_matricule() == "00000000000"){
        cout << "MATRICULE  INEXISTANT!\n";
        return;
    }

    cout << "QUELLE INFORMATION SOUHAITEZ-VOUS MODIFIER ?\n";
    cout << "\t1. MATRICULE\n";
    cout << "\t2. NOM\n";
    cout << "\t3. PRNEOM\n";
    cout << "\t4. SEXE\n";
    cout << "\t5. AGE\n";
    cout << "\t6. MOYENNE\n";
    cout << "VEUILLEZ CHOISIR UNE ACTION A EXECUTER : ";
    cin >> choix;

    switch(choix){
        case 1:

            break;

        case 2:
        
            break;
        case 3:
        
            break;
        case 4:
        
            break;
        
        case 5:
        
            break;

        case 6:
        
            break;
    }

    cout << "\tETUDIANT MODIFIE AVEC SUCCES!\n";
    cout << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n";

    return;
}

void supprimer(){


    return;
}