#include <iostream>
#include <cstdlib>

using namespace std;

// EXERCICE 2
bool f(int t[], int size){
    int i = 0;
    bool b = 0;

    for(i = 0; i < size; i++)
        if(t[i] >= 0 && t[i] <= 10){
            b = 1;
            return b;
        }

    return b;
}

// EXERCICE 5
int u(int n){
    if(n < 0) {
        cout << "Valeur invalide\n";
        exit(EXIT_FAILURE);
    }
    if(n == 0 || n == 1) return 1;
    return (u(n-1) + u(n-2));
}

int main(){
    /* EXERCICE 1
    int n, i, j, S, N[100];

    n = i = j = S = 0;

    while(true){
        do{
            cout << "\nENTREZ UN ENTIER > 0 : ";
            cin >> n;
            if(n < 0)
                cout << "ERRREUR\n";
        }while(n < 0);
        if(n > 0){
            N[i] = n;
            i++;
        }
        else{
            if(i == 0){
                cout << "\nPAS DE MOYENNE\n";
                break;
            }
            for(j = 0; j < i; j++)
                S = S + N[j];
            cout << "\nMOYENNE : " << S / i << endl;
            break;
        }
    }
    */

    /* EXERCICE 2
    int t[] = {12, 5, 11};
    cout << f(t, 3);
    //*/

    /* EXERCICE 3
    int i, j, V, N[10];

    cout << "ENTREZ LES NOMBRES\n";
    for(j = 0; j < 10; j++){
        cout << "\t" << j << ". ";
        cin >> N[j];
    }

    cout << "\nINDICE DE REMPLACEMENT (0 a 9) : ";
    cin >> i;
    cout << "\nVALEUR DE REMPLACEMENT : ";
    cin >> V;

    for(j = 8; j >= i; j--){
        N[j+1] = N[j];
    }
    N[i] = V;
    cout << "\nNOUVEAU TABLEAU\n";
    for(j = 0; j < 10; j++){
        cout << "\t" << j << ". " << N[j] << "\n";
    }
     */

    /* EXERCICE 4
    double L, l, P, S;

    do{
        cout << "\nLONGUEUR : ";
        cin >> L;
        if(L <= 0) cout << "VALEUR INVALIDE\n";
    }while(L <= 0);

    do{
        cout << "\nLARGEUR : ";
        cin >> l;
        if(l <= 0) cout << "VALEUR INVALIDE\n";
        if(l > L) cout << "LA LARGEUR DOIT ETRE INFERIEURE A LA LONGUEUR\n";
    }while(l <= 0 || l > L);

    P = 2 * (L + l);
    S = L * l;

    cout << "\nPERIMETRE : " << P << " ~ SURFACE : " << S << endl;
    */

    /* EXERCICE 5 (FIBONNACI) */
    int i = 0;
    for(i = 0; i < 10; i++){
        cout << "u(" << i << ") = " << u(i) << "\n";
    }
    
    return 0;
}
