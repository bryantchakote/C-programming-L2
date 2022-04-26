#ifndef COMPLEXE_H
#define COMPLEXE_H
#include <cmath>
#include <cstdlib>

using namespace std;

class Complexe
{
    public:
        // Constructors
        Complexe();
        Complexe(double, double);

        // Setters
        void set_Re(double a){Re = a;}
        void set_Im(double b){Im = b;}
        void set_mod(){mod = sqrt(Re*Re + Im*Im);}
        void set_arg(){arg = atan(Im / Re);}

        // Getters
        double get_Re(){return Re;}
        double get_Im(){return Im;}
        double get_mod(){return mod;}
        double get_arg(){return arg;}

        // Utils
        void disp(); // // Affichage
        Complexe conj(){return Complexe(Re, -Im);} // // Conjugue
        friend Complexe operator - (Complexe z){return Complexe(-z.Re, -z.Im);} // // Oppose

        // // Somme
        Complexe sum(Complexe z){return Complexe(Re + z.Re,  Im + z.Im);}
        friend Complexe sum(Complexe z1, Complexe z2){return z1.sum(z2);}
        friend Complexe operator + (Complexe z1, Complexe z2){return z1.sum(z2);}

        // // Produit de deux complexes
        Complexe mul(Complexe z){return Complexe(Re*z.Re - Im*z.Im, Re*z.Im + Im*z.Re);}
        friend Complexe mul(Complexe z1, Complexe z2){return z1.mul(z2);}
        friend Complexe operator * (Complexe z1, Complexe z2){return z1.mul(z2);}

        // // Produit d'un complexe et d'un scalaire
        friend Complexe operator * (double a, Complexe z){return Complexe(a*z.Re, a*z.Im);}
        friend Complexe operator * (Complexe z, double a){return (a * z);}

        // // Rapport de deux complexes
        Complexe div(Complexe z){
            if(z.mod == 0){
                cout << "MATH ERROR !\n";
                exit(EXIT_FAILURE);
            }
            return ((1 / z.mod) * (Complexe(Re, Im) * z.conj()));
        }
        friend Complexe div(Complexe z1, Complexe z2){return z1.div(z2);}
        friend Complexe operator / (Complexe z1, Complexe z2){return z1.div(z2);}

        // // Division d'un complexe par un scalaire
        friend Complexe operator / (Complexe z, double a){
            if(a == 0){
                cout << "MATH ERROR !\n";
                exit(EXIT_FAILURE);
            }
            return ((1 / a) * z);
        }

        // // Division d'un scalaire par un complexe
        friend Complexe operator / (double a, Complexe z){
            if(z.Re == 0 && z.Im == 0){
                cout << "MATH ERROR !\n";
                exit(EXIT_FAILURE);
            }
            return (Complexe(a, 0) / z);
        }

        // Destructor
        virtual ~Complexe();

    protected:

    private:
        double Re, Im, mod, arg;
};

#endif // COMPLEXE_H
