#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cctype>
#include<ctime>
#include<climits>
#include<stdio.h>
#include<windows.h>
#include<fstream>

int const N=4;
int const M=3;

using namespace std;

//Record

//Prototipo della funzione
bool inserimento(int m[N][M]);
void visualizzazione(int m[N][M]);
void calcolo(int m[N][M], int somme[N], int massimi[N]);

//Inizio programma
int main () {
    /*
    Traccia: Data una matrice con 4 righe e 3 colonne, calcolare la somma ed il massimo dei valori per ogni riga
    */

    // Dichiarazione variabili
    int scelta, mat[N][M], sum[N], max[N];
    bool vuota = true;

    // Corpo Principale
    do {
        cout << "1. Inserimento\n";
        cout << "2. Visualizzazione\n";
        cout << "3. Calcolo della somma e del valore massimo per ogni riga\n";
        cout << "Altro: Esci\n";
        cout << "Inserisci il comando: ";
        cin >> scelta;

        system("cls");

        switch (scelta) {
            case 1:
                cout << "-------- INSERIMENTO --------\n\n";
                vuota = inserimento(mat);
            break;

            case 2:
                cout << "-------- VISUALIZZAZIONE --------\n\n";

                if (vuota)
                    cout << "La matrice \212 vuota.";

                else
                    visualizzazione(mat);
            break;

            case 3:
                cout << "-------- CALCOLO SOMME E MASSIMI --------\n\n";

                if (vuota)
                    cout << "La matrice \212 vuota.";

                else {
                    calcolo(mat, sum, max);

                    for (int i = 0; i < N; i++)
                        cout << "La somma della riga " << i << " \212: " << sum[i] << endl;

                    cout << endl << endl;

                    for (int i = 0; i < N; i++)
                        cout << "Il valore massimo della riga " << i << " \212: " << max[i] << endl;
                }
            break;
        }

        if (scelta >= 1 && scelta <= 3) {
            cout << endl << endl;
            system("pause");
            system("cls");
        }

    } while (scelta >= 1 && scelta <= 3);

    return 0;
}

// Cosa fa ogni funzione
bool inserimento(int m[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "Inserisci un valore nel posto [" << i << "][" << j << "] della matrice: ";
            cin >> m[i][j];
        }
    }

    return false;
}

void visualizzazione(int m[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << m[i][j] << "\t";

        cout << endl;
    }

    return;
}

void calcolo(int m[N][M], int somme[N], int massimi[N]) {
    int somma, massimo;

    for (int i = 0; i < N; i++) {
        somma = 0;
        massimo = INT_MIN;

        for (int j = 0; j < M; j++) {
            somma += m[i][j];
            massimo = max(massimo, m[i][j]);
        }

        somme[i] = somma;
        massimi[i] = massimo;
    }

    return;
}