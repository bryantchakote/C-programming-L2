#include <iostream>

using namespace std;

void fibo(int n){
    if(n < 0){
        cout << "Negatif" << endl;
        return;
    }
    if(n > 100){
        cout << "> 100" << endl;
        return;
    }
    int u[100];
    u[0] = 0;
    u[1] = 1;

    if(n > 1)
        for(int i = 2; i <= n; i++)
            u[i] = u[i-1] + u[i-2];

    for(int i = 0; i <= n; i++)
        cout << i << " - " << u[i] << endl;

    return;
}

int main(){
    int n = 10;

    fibo(n);
}
