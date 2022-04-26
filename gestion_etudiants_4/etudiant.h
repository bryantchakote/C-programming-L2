#ifndef ETUDIANT_H_INCLUDED
#define ETUDIANT_H_INCLUDED
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

class Etudiant{
    public:
        // constructors
        Etudiant():
            matricule_("00000000000"), nom_("vide"), prenom_("vide"), sexe_(' '), age_(0), moyenne_(0) {}
        Etudiant(string matricule, string nom, string prenom, char sexe, int age, double moyenne):
            matricule_(matricule), nom_(nom), prenom_(prenom), sexe_(sexe), age_(age), moyenne_(moyenne) {}

        // setters
        void set_matricule(string matricule) {matricule_ = matricule;}
        void set_nom(string nom) {nom_ = nom;}
        void set_prenom(string prenom) {prenom_ = prenom;}
        void set_sexe(char sexe) {sexe_ = sexe;}
        void set_age(int age) {age_ = age;}
        void set_moyenne(double moyenne) {moyenne_ = moyenne;}

        // getters
        string get_matricule() const {return matricule_;}
        string get_nom() const {return nom_;}
        string get_prenom() const {return prenom_;}
        char get_sexe() const {return sexe_;}
        int get_age() const {return age_;}
        double get_moyenne() const {return moyenne_;}

    private:
        string matricule_;
        string nom_;
        string prenom_;
        char sexe_;
        int age_;
        double moyenne_;
};

#endif // ETUDIANT_H_INCLUDED
