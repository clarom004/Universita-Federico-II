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

int const DIM = 100;

using namespace std;

//Prototipo della funzione
void inserimento(int v[DIM], int &n, int voto);
void visualizzazione(int v[DIM], int n);
float calcoloMedia(int v[DIM], int n);
int votoMassimo(int v[DIM], int n);
int votoMinimo(int v[DIM], int n);

//Inizio programma
int main () {
    /*
    Traccia: Progettare e scrivere un programma che permetta di gestire i voti della carriera
    universitaria di uno studente (array di interi).
    Prevedere le seguenti funzioni:
    - 1. Inserimento nuovo voto (18 <= voto <= 30)
    - 2. Calcola media
    - 3. Individuazione voto max
    - 4. Individuazione voto min
    Prevedere un vettore aggiuntivo di valori booleani (che indichi se all’esame è stata
    conseguita la lode)
    - La funzione di inserimento valida il voto da aggiungere.
    - Realizzare un menu interattivo che permetta all’utente di eseguire la funzione
    desiderata.
    */

    // Dichiarazione variabili
    int scelta, vett[DIM], dim = 0, valore;
    float avg = 0;

    // Corpo Principale
    do {
        cout << "1. Inserimento\n";
        cout << "2. visualizzazione\n";
        cout << "3. Calcolo media\n";
        cout << "4. Individuazione voto massimo\n";
        cout << "5. Individuazione voto minimo\n";
        cout << "6. Esci\n";
        cout << "Inserisci il comando: ";
        cin >> scelta;

        system("cls");

        switch (scelta) {
            case 1:
                cout << "INSERIMENTO\n\n";

                do {
                    cout << "Inserisci il voto: ";
                    cin >> valore;

                    if (!(valore >= 18 && valore <= 30))
                        cout << "\nIl voto non \212 valido. Deve essere compreso tra 18 e 30 (estremi compresi). Riprova.\n\n";

                }while (!(valore >= 18 && valore <= 30));

                inserimento(vett, dim, valore);
            break;

            case 2:
                cout << "VISUALIZZAZIONE\n\n";

                if (dim == 0)
                    cout << "Non ci sono voti presenti.";

                else
                    visualizzazione(vett, dim);
            break;

            case 3:
                cout << "CALCOLO MEDIA\n\n";

                if (dim == 0)
                    cout << "Non ci sono voti presenti.";

                else {
                    avg = calcoloMedia(vett, dim);

                    cout << "La tua media dei voti \212: " << avg << endl;

                    if (avg >= 24)
                        cout << "Hai degli ottimi voti!";

                    else
                        cout << "Cerca di migliorare!";
                }
            break;

            case 4:
                cout << "CALCOLO VOTO MASSIMO\n\n";

                if (dim == 0)
                    cout << "Non ci sono voti presenti.";

                else
                    cout << "Il voto massimo \212: " << votoMassimo(vett, dim);
            break;

            case 5:
                cout << "CALCOLO VOTO MINIMO\n\n";

                if (dim == 0)
                    cout << "Non ci sono voti presenti.";

                else
                    cout << "Il voto minimo \212: " << votoMinimo(vett, dim);
        }

        if (scelta >= 1 && scelta <= 5) {
            cout << endl << endl;
            system("pause");
            system("cls");
        }

    } while (scelta >= 1 && scelta <= 5);

    return 0;
}

// Corpo delle funzioni
void inserimento(int v[DIM], int &n, int voto) {
    v[n] = voto;
    n++;

    return;
}

void visualizzazione(int v[DIM], int n) {
    cout << "{";
    for (int i = 0; i < n; i++) {
        if (i == n-1)
            cout << v[i];

        else
            cout << v[i] << ",\t";
    }
    cout << "}";

    return;
}

float calcoloMedia(int v[DIM], int n) {
    float media = 0;

    for (int i = 0; i < n; i++) {
        media += v[i];
    }

    media /= n;

    return media;
}

int votoMassimo(int v[DIM], int n) {
    int massimo = INT_MIN;

    for (int i = 0; i < n; i++) {
        massimo = max(massimo, v[i]);
    }

    return massimo;
}

int votoMinimo(int v[DIM], int n) {
    int minimo = INT_MAX;

    for (int i = 0; i < n; i++) {
        minimo = min(minimo, v[i]);
    }

    return minimo;
}