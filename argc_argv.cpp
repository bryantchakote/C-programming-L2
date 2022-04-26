#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[])
{
    int add, sub, mul, div, mod;
    char opp;

    cout << "Choix de l'operateur : " ;
    cin >> opp;

    switch(opp){
        case '+':
            add = atoi(argv[1]) + atoi(argv[2]);
            cout << "Somme\n" << argv[1] << " + " << argv[2] << " = " << add;
            break;
        case '-':
            sub = atoi(argv[1]) - atoi(argv[2]);
            cout << "Soustraction\n" << argv[1] << " - " << argv[2] << " = " << sub;
            break;
        case '*':
            mul = atoi(argv[1]) * atoi(argv[2]);
            cout << "Multiplication\n" << argv[1] << " * " << argv[2] << " = " << mul;
            break;
        case '/':
            div = atoi(argv[1]) / atoi(argv[2]);
            cout << "Division\n" << argv[1] << " / " << argv[2] << " = " << div;
            break;
        case '%':
            mod = atoi(argv[1]) % atoi(argv[2]);
            cout << "Modulo\n" << argv[1] << " % " << argv[2] << " = " << mod;
            break;
        default:
            cout << "Operateur invalide !\n";
    }
    
    return 0;
}