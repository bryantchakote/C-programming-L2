#ifndef EMPLACEMENT_H
#define EMPLACEMENT_H


class Emplacement
{
    public:
        Emplacement(const double & = 0.0, const double & = 0.0);
        virtual ~Emplacement();

        double getAbs(){return abs;}
        double getOrd(){return ord;}

        void setAbs(double val){abs = val;}
        void setOrd(double val){ord = val;}

        void afficher();
        void echange();

    protected:
        double abs;
        double ord;

    private:
};

#endif // EMPLACEMENT_H
