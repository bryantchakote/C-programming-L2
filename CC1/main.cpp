#include <iostream>

using namespace std;

/* EXERCICE 5 */
int u(int N){
    if(N == 0) return 3;
    return 3 * u(N-1) + 4;
}

int main()
{
    /* EXERCICE 1
    double prix_HT, qte, TVA, prix_TTC;

    do{
        cout << "Prix HT : ";
        cin >> prix_HT;
        if(prix_HT <= 0) cout << "Valeur de prix invalide\n";
    }while(prix_HT <= 0);

    do{
        cout << "Quantite achetee : ";
        cin >> qte;
        if(qte <= 0) cout << "Valeur de quantite invalide\n";
    }while(qte <= 0);

    do{
        cout << "TVA (en pourcentage) : ";
        cin >> TVA;
        if(TVA < 0) cout << "Valeur de TVA invalide\n";
    }while(TVA <= 0);

    prix_TTC = qte * (1 + TVA / 100) * prix_HT;

    cout << "Net a payer : " << prix_TTC << endl;
    */


    /* EXERCICE 2
    int A, B, aux;

    cout << "Entrez les nombres\n";
    cout << "\tA = ";
    cin >> A;
    cout << "\tB = ";
    cin >> B;
    aux = A;
    A = B;
    B = aux;
    cout << "\nA = " << A << "\tB = " << B << endl;
    */


    /* EXERCICE 3
    int n;
    double m = 0;

    cout << "Entrez 5 entiers separes par un espace\n";
    cin >> n; m = m + n;
    cin >> n; m = m + n;
    cin >> n; m = m + n;
    cin >> n; m = m + n;
    cin >> n; m = m + n;
    m = m / 5;
    cout << "Moyenne : " << m << endl;
    */

    /* EXERCICE 4 (done) */

    /* EXERCICE 5 */
    int N;

    cout << "Entrez un entier positif : ";
    cin >> N;
    if (N >= 0)
        cout << u(N) << endl;
    else
        count << "Valeur invalide" << endl;

    return 0;
}
