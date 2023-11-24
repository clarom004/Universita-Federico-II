#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<time.h>
#include<limits.h>
#include<windows.h>

//Variabili globali
int const MAX = 100;

//Record
struct Studente {
    char nome[50];
    char cognome[50];
    int eta;
    float voto;
    int lavoratore;
};

//Prototipo della funzione
void inserimento(struct Studente vett[MAX], int* n);
void visualizzazione(struct Studente vett[MAX], int n);
void ricerca(struct Studente vett[MAX], int n, char nome[50], char cognome[50]);
void media(struct Studente vett[MAX], int n);
void meno25(struct Studente vett[MAX], int n);

//Inizio programma
int main () {
    /*
    Traccia: 
    */

    // Dichiarazione variabili
    int scelta, dim=0;
    struct Studente v[MAX];
    char name[50], surname[50];

    // Corpo Principale
    do {
        printf("1. Inserimento\n");
        printf("2. Visualizzazione\n");
        printf("3. Ricerca per nome e cognome\n");
        printf("4. Media dei non lavoratori\n");
        printf("5. Studenti con meno di 25 anni\n");
        printf("Altro: Esci\n");
        printf("Inserisci il comando: ");
        scanf("%d", &scelta);

        system("cls");

        switch (scelta) {
            case 1:
                printf("-------- INSERIMENTO --------\n\n");
                inserimento(v, &dim);
            break;

            case 2:
                printf("-------- VISUALIZZAZIONE --------\n\n");
                if (dim<=0)
                    printf("Non ci sono studenti registrati.");

                else
                    visualizzazione(v, dim);
            break;

            case 3:
                printf("-------- RICERCA --------\n\n");
                if (dim<=0)
                    printf("Non ci sono studenti registrati.");

                else {
                    printf("Inserisci il nome: ");
                    scanf("%s", name);
                    printf("Inserisci il cognome: ");
                    scanf("%s", surname);

                    ricerca(v, dim, name, surname);
                }
            break;

            case 4:
                printf("-------- CALCOLO MEDIA VOTI NON LAVORATORI --------\n\n");
                if (dim<=0)
                    printf("Non ci sono studenti registrati.");

                else
                    media(v, dim);
            break;

            case 5:
                printf("-------- STUDENTI DI MENO DI 25 ANNI --------\n\n");
                if (dim<=0)
                    printf("Non ci sono studenti registrati.");

                else
                    meno25(v, dim);
            break;
        }

        if (scelta >= 1 && scelta <= 5) {
            printf("\n\n");
            system("pause");
            system("cls");
        }

    } while (scelta >= 1 && scelta <= 5);

    return 0;
}

// Cosa fa ogni funzione
void inserimento(struct Studente vett[MAX], int* n) {
    printf("Inserisci il nome: ");
    scanf("%s", vett[*n].nome);
    printf("Inserisci il cognome: ");
    scanf("%s", vett[*n].cognome);
    printf("Inserisci l'eta: ");
    scanf("%d", &vett[*n].eta);
    printf("Inserisci il voto: ");
    scanf("%f", &vett[*n].voto);
    printf("Lavoratore (si=1, no=0): ");
    scanf("%d", &vett[*n].lavoratore);

    (*n)++;

    return;
}

void visualizzazione(struct Studente vett[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("STUDENTE %d\n", i+1);
        printf("\tNome: %s\n\tCognome: %s\n\tEta: %d\n\tVoto: %.2f\n\tLavoratore (si=1, no=0): %d\n\n", vett[i].nome, vett[i].cognome, vett[i].eta, vett[i].voto, vett[i].lavoratore);
    }

    return;
}

void ricerca(struct Studente vett[MAX], int n, char nome[50], char cognome[50]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nome, vett[i].nome) == 0 && strcmp(cognome, vett[i].cognome) == 0) {
            printf("\nSTUDENTE %d\n", i+1);
            printf("\tNome: %s\n\tCognome: %s\n\tEta: %d\n\tVoto: %.2f\n\tLavoratore (si=1, no=0): %d\n\n", vett[i].nome, vett[i].cognome, vett[i].eta, vett[i].voto, vett[i].lavoratore);
        }
    }

    return;
}

void media(struct Studente vett[MAX], int n) {
    float media = 0;

    for (int i = 0; i < n; i++) {
        if (vett[i].lavoratore == 0)
            media += vett[i].voto;
    }

    media /= n;

    printf("La media dei voti degli studenti non lavoratori \212: %.2f", media);

    return;
}

void meno25(struct Studente vett[MAX], int n) {
    for (int i = 0; i < n; i++) {
        if (vett[i].eta < 25) {
            printf("STUDENTE %d\n", i+1);
            printf("\tNome: %s\n\tCognome: %s\n\tEta: %d\n\tVoto: %.2f\n\tLavoratore (si=1, no=0): %d\n\n", vett[i].nome, vett[i].cognome, vett[i].eta, vett[i].voto, vett[i].lavoratore);
        }
    }

    return;
}