#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<limits.h>
#include<windows.h>

// Variabile globale
#define MAX 100

// Struct Data
struct Data {
    int giorno;
    int mese;
    int anno;
};

// Struct Transazione
struct Transazione {
    char nome[30];
    char cognome[30];
    float importo;
    struct Data data;
};

// Prototipo della funzione
void inserimento(struct Transazione acquisti[MAX], int punti[MAX], int* n);
int calcolaPunti(struct Transazione acquisti[MAX], int i);
int stampaPuntiUtente(struct Transazione acquisti[MAX], int punti[MAX], char name[30], char surname[30], int n);

// Inizio programma
int main () {
    /*
    Traccia: 
    */

    // Dichiarazione variabili
    int scelta, dim=7, punti;
    struct Transazione vAcquisti[MAX] = {{"Mario", "Rossi", 43.12, {12, 11, 2023}}, {"Mario", "Rossi", 7.4, {12, 5, 2023}}, {"Mario", "Rossi", 13.35, {2, 1, 2023}}, {"Feliciano", "Murru", 3.0, {7, 11, 2023}}, {"Feliciano", "Murru", 36.4, {17, 6, 2023}}, {"Feliciano", "Murru", 4, {7, 11, 2023}}, {"Grazia", "De Biase", 14, {7, 11, 2023}}};
    int vPunti[MAX] = {8, 1, 2, 0, 7, 0, 2};
    char name[30], surname[30];

    // Corpo Principale
    do {
        printf("1. Inserisci transazione\n");
        printf("2. Stampa punti di un utente\n");
        printf("Altro: Esci\n");
        printf("Inserisci il comando: ");
        scanf("%d", &scelta);

        while (getchar() != '\n');

        system("cls");

        switch (scelta) {
            case 1:
                printf("-------- INSERIMENTO TRANSAZIONE --------\n\n");
                inserimento(vAcquisti, vPunti, &dim);
            break;

            case 2:
                printf("-------- VISUALIZZAZIONE --------\n\n");

                if (dim == 0)
                    printf("Non ci sono acquisti registrati.");

                else {
                    printf("Inserisci il nome: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = 0;

                    printf("Inserisci il cognome: ");
                    fgets(surname, sizeof(surname), stdin);
                    surname[strcspn(surname, "\n")] = 0;
                    
                    punti = stampaPuntiUtente(vAcquisti, vPunti, name, surname, dim);

                    printf("L'utente %s %s ha: %d punti.", name, surname, punti);
                }

                
            break;
        }

        if (scelta >= 1 && scelta <= 2) {
            printf("\n\n");
            system("pause");
            system("cls");
        }

    } while (scelta >= 1 && scelta <= 2);

    return 0;
}

// Cosa fa ogni funzione
void inserimento(struct Transazione acquisti[MAX], int punti[MAX], int* n) {
    printf("Inserisci il nome: ");
    fgets(acquisti[*n].nome, sizeof(acquisti[*n].nome), stdin);
    acquisti[*n].nome[strcspn(acquisti[*n].nome, "\n")] = 0;

    printf("Inserisci il cognome: ");
    fgets(acquisti[*n].cognome, sizeof(acquisti[*n].cognome), stdin);
    acquisti[*n].cognome[strcspn(acquisti[*n].cognome, "\n")] = 0;

    printf("Inserisci l'importo: ");
    scanf("%f", &acquisti[*n].importo);

    printf("Inserisci il giorno: ");
    scanf("%d", &acquisti[*n].data.giorno);
    printf("Inserisci il mese: ");
    scanf("%d", &acquisti[*n].data.mese);
    printf("Inserisci l'anno: ");
    scanf("%d", &acquisti[*n].data.anno);

    while (getchar() != '\n');

    punti[*n] = calcolaPunti(acquisti, *n);

    (*n)++;
}

int calcolaPunti(struct Transazione acquisti[MAX], int i) {
    int punti = (int)acquisti[i].importo / 5;

    if (acquisti[i].data.mese == 12 || acquisti[i].data.mese == 1)
        punti *= 2;

    return punti;
}

int stampaPuntiUtente(struct Transazione acquisti[MAX], int punti[MAX], char name[30], char surname[30], int n) {
    int points = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(acquisti[i].nome, name) == 0 && strcmp(acquisti[i].cognome, surname) == 0)
            points += punti[i];
    }

    return points;
}
