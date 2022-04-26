#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point(int abs, int ord);
        virtual ~Point();

        int Getabs() { return abs; }
        void Setabs(int val) { abs = val; }
        int Getord() { return ord; }
        void Setord(int val) { ord = val; }
        void deplacer(int dx, int dy);
        double dist_2(const Point);
        void afficher();

        friend double dist(const Point&, const Point&);

    protected:

    private:
        int abs;
        int ord;
};

#endif // POINT_H
