#include <iostream>

using namespace std;

class One{
    public: One() { cout << "One's constructor" << endl; }
};
class Two{
    public: Two() { cout << "Two's constructor" << endl; }
    private: One o_;
    // On cree d'abord les elements de la classe avant d'appeler le constructeur. So, "One's constructor" s'affiche avant "Two's, constructor"0 
};

int main(){
    Two ob2;

    return 0;
}