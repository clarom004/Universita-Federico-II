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

using namespace std;

//Record

//Prototipo della funzione
int computer();
int gioco(int opzione, int &vittoria, int &sconfitta, int &pareggio);

//Inizio programma
int main () {
    /*
    Traccia: Morra cinese
    */

    // Dichiarazione variabili
    int scelta1, scelta2, figura, vittoria, vincite=0, sconfitte=0, pareggi=0;

    // Corpo Principale
    cout << "-------- MORRA CINESE --------\n\n";
    cout << "Benvenuto nel gioco della morra cinese, anche chiamato 'sasso, carta, forbici'.\n\n"
             "Scopo:\n"
             "Lo scopo \212 sconfiggere l'avversario scegliendo un segno in grado di battere quello dell'altro.\n\n"
             "Regole:\n"
             "- Il sasso spezza le forbici (vince il sasso)\n"
             "- La carta avvolge il sasso (vince la carta)\n"
             "- Le forbici tagliano la carta (vincono le forbici)\n\n\n"
             
             "Sei pronto per giocare?\n";

    system("pause");
    system("cls");

    do {
        cout << "-------- MORRA CINESE --------\n\n";

        cout << "1. Gioca\n";
        cout << "2. Visualizza punteggio\n";
        cout << "Altro: Esci\n";
        cout << "Inserisci il comando: ";
        cin >> scelta1;

        system("cls");

        switch (scelta1) {
            case 1:
                do {
                    cout << "1. Sasso\n";
                    cout << "2. Carta\n";
                    cout << "3. Forbici\n";
                    cout << "Inserisci il comando: ";
                    cin >> scelta2;

                    if (scelta2 < 1 || scelta2 > 3)
                        cout << "Comando errato. Riprova.\n\n";

                }while (scelta2 < 1 || scelta2 > 3);

                system("cls");

                cout << "Sasso, carta, for-bi-ci...";
                Sleep(1500);
                system("cls");

                if (scelta2 == 1)
                    cout << "Tu hai scelto SASSO.\n";

                else if (scelta2 == 2)
                    cout << "Tu hai scelto CARTA.\n";

                else if (scelta2 == 3)
                    cout << "Tu hai scelto FORBICI.\n";

                figura = computer();

                if (figura == 1)
                    cout << "Il computer ha scelto SASSO.\n\n";

                else if (figura == 2)
                    cout << "Il computer ha scelto CARTA.\n\n";

                else if (figura == 3)
                    cout << "Il computer ha scelto FORBICI.\n\n";

                vittoria = gioco(scelta2, vincite, sconfitte, pareggi);

                if (vittoria == 1)
                    cout << "Hai vinto!";

                else if (vittoria == 0)
                    cout << "C'\212 stato un pareggio!";

                else
                    cout << "Hai perso, ma puoi riprovare!";
            break;

            case 2:
                cout << "Vittorie: " << vincite << endl;
                cout << "Sconfitte: " << sconfitte << endl;
                cout << "Pareggi: " << pareggi;
            break;
        }

        if (scelta1 >= 1 && scelta1 <= 2) {
            cout << endl << endl;
            system("pause");
            system("cls");
        }

    } while (scelta1 >= 1 && scelta1 <= 2);

    return 0;
}

// Cosa fa ogni funzione
int gioco(int opzione, int &vittoria, int &sconfitta, int &pareggio) {
    int oggetto = computer();

    if ((opzione == 1 && oggetto == 3) || (opzione == 2 && oggetto == 1) || (opzione == 3 && oggetto == 2)) {
        vittoria++;
        return 1; //Vittoria
    }

    else if ((opzione == 1 && oggetto == 1) || (opzione == 2 && oggetto == 2) || (opzione == 3 && oggetto == 3)) {
        pareggio++;
        return 0; //Pareggio
    }
    
    else {
        sconfitta++;
        return -1; //Sconfitta
    }
}

int computer() {
    srand(time(NULL));

    int simbolo = rand() % 3 + 1;

    return simbolo;
}