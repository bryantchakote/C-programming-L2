#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[]){
    int a, b, res;
    char op;

    if(argc > 3){
        a = atoi(argv[1]);
        b = atoi(argv[3]);
        op = argv[2][0];
    }

    switch(op){
        case '+': res = a + b; cout << a << " + " << b << " = " << res; break;
        case '-': res = a - b; cout << a << " - " << b << " = " << res; break;
        case '*': res = a * b; cout << a << " x " << b << " = " << res; break;
        case '/': res = a / b; cout << a << " / " << b << " = " << res; break;
        case '%': res = a % b; cout << a << " % " << b << " = " << res; break;
        default : cout << "Operateur invalide !\n"; break;
    }

    return 0;
}
