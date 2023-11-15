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
void inserimentoMezzo(int v[DIM], int &n, int voto, int posizione);
bool ricerca(int v[DIM], int n, int voto, int &posizione);
void modifica(int v[DIM], int n, int voto, int posizione);
void eliminazioneFine(int v[DIM], int &n);
void eliminazioneInizio(int v[DIM], int &n);
void eliminazioneMezzo(int v[DIM], int &n, int posizione);

//Inizio programma
int main () {
    /*
    Traccia: leggi nome file
    */

    // Dichiarazione variabili
    int scelta, vett[DIM], dim = 0, valore, posto;

    // Corpo Principale
    do {
        cout << "1. Inserimento\n";
        cout << "2. visualizzazione\n";
        cout << "3. Inserimento nel mezzo\n";
        cout << "4. Ricerca\n";
        cout << "5. Modifica\n";
        cout << "6. Eliminazione alla fine\n";
        cout << "7. Eliminazione all'inizio\n";
        cout << "8. Eliminazione nel mezzo\n";
        cout << "Altro: Esci\n";
        cout << "Inserisci il comando: ";
        cin >> scelta;

        system("cls");

        switch (scelta) {
            case 1:
                cout << "INSERIMENTO\n\n";

                if (dim == 100)
                    cout << "Hai raggiunto la dimensione massima.";

                else {
                    do {
                        cout << "Inserisci il voto: ";
                        cin >> valore;

                        if (!(valore >= 18 && valore <= 30))
                            cout << "\nIl voto non \212 valido. Deve essere compreso tra 18 e 30 (estremi compresi). Riprova.\n\n";

                    }while (!(valore >= 18 && valore <= 30));

                    inserimento(vett, dim, valore);
                }
            break;

            case 2:
                cout << "VISUALIZZAZIONE\n\n";

                if (dim == 0)
                    cout << "Non ci sono voti presenti.";

                else
                    visualizzazione(vett, dim);
            break;

            case 3:
                cout << "INSERIMENTO NEL MEZZO\n\n";

                if (dim == 100)
                    cout << "Hai raggiunto la dimensione massima.";

                else {
                    if (dim == 0)
                        cout << "Non ci sono voti presenti.";

                    else {
                        do {
                            cout << "Inserisci il posto in cui vuoi inserire il voto: ";
                            cin >> posto;

                            if (!(posto >= 0 && posto <= dim))
                                cout << "Posto non disponibile. Riprova.\n\n";

                        }while (!(posto >= 0 && posto <= dim));

                        cout << "Inserisci il voto: ";
                        cin >> valore;

                        inserimentoMezzo(vett, dim, valore, posto);

                        cout << "\nIl voto è stato aggiunto.";
                    }
                }
            break;

            case 4:
                cout << "RICERCA\n\n";

                if (dim == 0)
                    cout << "Non ci sono voti presenti.";

                else {
                    cout << "Inserisci il voto che vuoi ricercare: ";
                    cin >> valore;

                    if (ricerca(vett, dim, valore, posto))
                        cout << "\nIl voto '" << valore << "' \212 presente e si trova nella posizione '" << posto << "'.";

                    else
                        cout << "\nIl voto '" << valore << "' non \212 presente.";
                }
            break;

            case 5:
                cout << "MODIFICA\n\n";

                if (dim == 0)
                    cout << "Non ci sono voti presenti.";

                else {
                    cout << "Inserisci il voto che vuoi modificare: ";
                    cin >> valore;

                    if (ricerca(vett, dim, valore, posto)) {
                        cout << "Inserisci il nuovo voto: ";
                        cin >> valore;

                        modifica(vett, dim, valore, posto);

                        cout << "\nIl voto \212 stato modificato.";
                    }

                    else
                        cout << "Il voto '" << valore << "' non \212 presente.";
                }
            break;

            case 6:
                cout << "ELIMINAZIONE ALLA FINE\n\n";

                if (dim == 0)
                    cout << "Non ci sono voti presenti.";

                else {
                    
                    eliminazioneFine(vett, dim);
                    
                    cout << "L'ultimo voto \212 stato cancellato.";
                }
            break;

            case 7:
                cout << "ELIMINAZIONE ALL'INIZIO\n\n";

                if (dim == 0)
                    cout << "Non ci sono voti presenti.";

                else {
                    
                    eliminazioneInizio(vett, dim);
                    
                    cout << "Il primo voto \212 stato cancellato.";
                }
            break;

            case 8:
                cout << "ELIMINAZIONE NEL MEZZO\n\n";

                if (dim == 0)
                    cout << "Non ci sono voti presenti.";

                else {
                    cout << "Inserisci il voto da eliminare: ";
                    cin >> valore;

                    if (ricerca(vett, dim, valore, posto)) {
                        eliminazioneMezzo(vett, dim, posto);
                    
                        cout << "Il voto '" << valore << "' \212 stato cancellato.";
                    }

                    else
                        cout << "Il voto '" << valore << "' non \212 presente.";
                }
        }

        if (scelta >= 1 && scelta <= 8) {
            cout << endl << endl;
            system("pause");
            system("cls");
        }

    } while (scelta >= 1 && scelta <= 8);

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

void inserimentoMezzo(int v[DIM], int &n, int voto, int posizione) {
    int i;

    for (i = n-1; i >= posizione; i--) {
        v[i+1] = v[i];
    }

    v[i+1] = voto;
    n++;

    return;
}

bool ricerca(int v[DIM], int n, int voto, int &posizione) {
    bool trovato = false;

    for (int i = 0; i < n; i++) {
        if (voto == v[i]) {
            trovato = true;
            posizione = i;
        }
    }

    return trovato;
}

void modifica(int v[DIM], int n, int voto, int posizione) {
    v[posizione] = voto;

    return;
}

void eliminazioneFine(int v[DIM], int &n) {
    n--;

    return;
}

void eliminazioneInizio(int v[DIM], int &n) {
    for (int i = 0; i < n; i++) {
        v[i] = v[i+1];
    }

    n--;

    return;
}

void eliminazioneMezzo(int v[DIM], int &n, int posizione) {
    for (int i = posizione; i < n; i++) {
        v[i] = v[i+1];
    }

    n--;

    return;
}