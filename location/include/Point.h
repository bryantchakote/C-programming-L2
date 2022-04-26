#ifndef POINT_H
#define POINT_H
#include "Emplacement.h"
#include <string>

using namespace std;

class Point : public Emplacement
{
    public:
        Point(const double & = 0.0, const double & = 0.0, const string & = "noir");
        virtual ~Point();

        string getCouleur(){return couleur;}

        void setCouleur(string val){couleur = val;}

        void afficher();

    protected:

    private:
        string couleur;
};

#endif // POINT_H
