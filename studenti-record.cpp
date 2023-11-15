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

int const DIM = 2;
int const N = 3;

using namespace std;

//Record
struct alunno {
    string nome;
    string cognome;
    int eta;
    float voti[N];
};

//Prototipo della funzione
bool inserimento(alunno studente[DIM]);
void visualizzazione(alunno studente[DIM]);
bool omonimia(alunno studente[DIM]);
int risultati(alunno studente[DIM], float &media1, float &media2);

//Inizio programma
int main () {
    /*
    Traccia:
        Progettare e scrivere un programma che:

        ○ permetta di inserire le informazioni relative a due studenti
            Le informazioni di ciascuno studente sono memorizzate in un record con i
            seguenti campi: nome , cognome, età, lista voti ultimi 3 esami

        ○ (calcoli e) stampi a video le seguenti informazioni:

            i. riepilogo informazioni inserite per ciascuno studente

            ii. se i due studenti sono omonimi
                ● input: due record studente
                ● output: bool (true se omonimi)
                
            iii. quale studente ha conseguito una media più alta negli ultimi 3 esami
                ● input: due record studente
                ● output: -1 se studente 1 ha la media più alta, +1 se lo studente 2 ha la media più alta, 0 se hanno la stessa media
    */

    // Dichiarazione variabili
    int scelta, risultato;
    float avg1=0, avg2=0;
    bool vuoto = true;
    alunno vett[DIM];

    // Corpo Principale
    do {
        cout << "1. Inserimento\n";
        cout << "2. Visualizzazione\n";
        cout << "3. Risultati\n";
        cout << "Altro: Esci\n";
        cout << "Inserisci il comando: ";
        cin >> scelta;

        system("cls");

        switch (scelta) {
            case 1:
                cout << "-------- INSERIMENTO --------\n\n";
                vuoto = inserimento(vett);
            break;

            case 2:
                cout << "-------- VISUALIZZAZIONE --------\n\n";

                if (vuoto)
                    cout << "Il record \212 vuoto.";

                else
                    visualizzazione(vett);
            break;

            case 3:
                cout << "-------- RISULTATI --------\n\n";

                if (vuoto)
                    cout << "Il record \212 vuoto.";

                else {
                    risultato = risultati(vett, avg1, avg2);

                    if (risultato == -1)
                        cout << "Lo studente '" << vett[0].nome << " " << vett[0].cognome << "' ha la media pi\227 alta dello studente '" << vett[1].nome << " " << vett[1].cognome << "' ed \212 " << avg1 << ".";

                    else if (risultato == 1)
                        cout << "Lo studente '" << vett[1].nome << " " << vett[1].cognome << "' ha la media pi\227 alta dello studente '" << vett[0].nome << " " << vett[0].cognome << "' ed \212 " << avg2 << ".";

                    if (risultato == 0)
                        cout << "Gli studenti '" << vett[0].nome << " " << vett[0].cognome << "' e '" << vett[1].nome << " " << vett[1].cognome << "' hanno la stessa media ed \212 " << avg1 << ".";
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
bool inserimento(alunno studente[DIM]) {
    for (int i = 0; i < DIM; i++) {
        cout << i+1 << "\247 STUDENTE\n";
        cout << "\tInserisci il nome: ";
        cin >> studente[i].nome;
        cout << "\tInserisci il cognome: ";
        cin >> studente[i].cognome;
        cout << "\tInserisci il eta: ";
        cin >> studente[i].eta;
        
        for (int j = 0; j < N; j++) {
            cout << "\tInserisci il " << j+1 << "\247 voto: ";
            cin >> studente[i].voti[j];
        }

        cout << endl;
    }

    return false;
}

void visualizzazione(alunno studente[DIM]) {
    for (int i = 0; i < DIM; i++) {
        cout << i+1 << "\247 STUDENTE\n";
        cout << "\tNome: " << studente[i].nome << endl;
        cout << "\tCognome: " << studente[i].cognome << endl;
        cout << "\tEta: " << studente[i].eta << endl;
        
        for (int j = 0; j < N; j++) {
            cout << "\t" << j+1 << "\247 voto: " << studente[i].voti[j] << endl;
        }

        cout << endl;
    }

    if(omonimia(studente))
        cout << "\nN.B. Gli studenti sono omonimi.";

    return;
}

bool omonimia(alunno studente[DIM]) {
    if (studente[0].nome == studente[1].nome && studente[0].cognome == studente[1].cognome)
        return true;

    else
        return false;
}

int risultati(alunno studente[DIM], float &media1, float &media2) {
    for (int i = 0; i < N; i++) {
        media1 += studente[0].voti[i];
        media2 += studente[1].voti[i];
    }
    
    media1 /= N;
    media2 /= N;

    media1 = round(media1 * 100) / 100;
    media2 = round(media2 * 100) / 100;

    if (media1 > media2)
        return -1;

    else if (media1 == media2)
        return 0;

    else
        return 1;
}