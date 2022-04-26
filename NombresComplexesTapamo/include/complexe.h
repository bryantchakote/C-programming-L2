#ifndef COMPLEXE_H
#define COMPLEXE_H


class Complexe
{
    public:
        /** Default constructor */
        Complexe(const double& =0.0, const double& =0.0);
        /** Default destructor */
        virtual ~Complexe();
        /** Copy constructor
         *  \param other Object to copy from
         */
        Complexe(const Complexe& other);
        /** Assignment operator
         *  \param other Object to assign from
         *  \return A reference to this
         */
        Complexe& operator=(const Complexe& other);

        /** Access re
         * \return The current value of re
         */
        double getRe() { return re; }
        /** Set re
         * \param val New value to set
         */
        void setRe(double val) { re = val; }
        /** Access im
         * \return The current value of im
         */
        double getIm() { return im; }
        /** Set im
         * \param val New value to set
         */
        void setIm(double val) { im = val; }
        void displayStyle1(); //Display in the form re +im i
        void displayStyle2(); //Display in the form (re, im)

        double module();
        double arg();
        Complexe conjugue();

    protected:

    private:
        double re; //!< Real part of the complex number "re"
        double im; //!< Imaginary part of the complex number "im"
};

#endif // COMPLEXE_H
