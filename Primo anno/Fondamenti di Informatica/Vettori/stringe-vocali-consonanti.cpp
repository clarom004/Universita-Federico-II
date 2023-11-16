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

//Record

//Prototipo della funzione
bool inserimento(char parola[DIM]);
void visualizzazione(char parola[DIM]);
void ricerca_vocali_consonanti(char parola[DIM], char vocali[DIM], char consonanti[DIM]);

//Inizio programma
int main () {
    /*
    Traccia:    
        Sviluppare un programma in C/C++ che:
        ○ chieda all’utente di inserire una parola tramite lo standard input;
        ○ ricerca le vocali e le consonanti all’interno della parola;
        ○ stampi a video quali sono le vocali e le consonanti trovate;
        ○ stampi a video il numero di vocali e consonanti trovate.
    */

    // Dichiarazione variabili
    int scelta;
    char word[DIM], vowels[DIM], consonants[DIM];
    bool vuoto=true;

    // Corpo Principale
    do {
        cout << "1. Inserimento\n";
        cout << "2. Visualizzazione\n";
        cout << "3. Visualizzazione delle vocali e delle consonanti\n";
        cout << "Altro: Esci\n";
        cout << "Inserisci il comando: ";
        cin >> scelta;

        system("cls");

        switch (scelta) {
            case 1:
                cout << "-------- INSERIMENTO --------\n\n";
                vuoto = inserimento(word);
            break;

            case 2:
                cout << "-------- VISUALIZZAZIONE --------\n\n";

                if (vuoto)
                    cout << "Inserire prima la parola.";

                else
                    cout << "La parola inserita \212: "; visualizzazione(word);
            break;

            case 3:
                cout << "-------- VISUALIZZAZIONE VOCALI E CONSONANTI --------\n\n";

                if (vuoto)
                    cout << "Inserire prima la parola.";

                else {
                    ricerca_vocali_consonanti(word, vowels, consonants);
                    cout << "Le vocali della parola '" << word << "' sono " << strlen(vowels) << " e sono: "; visualizzazione(vowels);
                    cout << "\nLe consonanti della parola '" << word << "' sono " << strlen(vowels) << " e sono: "; visualizzazione(consonants);
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
bool inserimento(char parola[DIM]) {
    cout << "Inserisci la parola: ";
    cin >> parola;

    return false;
}

void visualizzazione(char parola[DIM]) {
    cout << parola;

    return;
}

void ricerca_vocali_consonanti(char parola[DIM], char vocali[DIM], char consonanti[DIM]) {
    int dim_vocali=0, dim_consonanti=0;

    for (int i = 0; i < strlen(parola); i++) {
        if (strchr("aeiouAEIOU", parola[i]) != nullptr)
            vocali[dim_vocali++] = parola[i];

        else
            consonanti[dim_consonanti++] = parola[i];
    }

    vocali[dim_vocali] = 0;
    consonanti[dim_consonanti] = 0;

    return;
}
