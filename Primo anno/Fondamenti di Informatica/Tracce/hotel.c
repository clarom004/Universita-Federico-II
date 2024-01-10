#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<limits.h>
#include<windows.h>

// Variabili globali
#define MAX 120

// Struttura Ospite
struct Ospite {
    char nome[51];
    char cognome[51];
    char email[31];
    int prenotazione;
};

// Prototipo della funzione
void inserisciUtente(struct Ospite ospiti[MAX], int* n, char name[51], char surname[51], char eMail[31], int booking);
void mostraOspiti(struct Ospite ospiti[MAX], int n);
void mostraOspite(struct Ospite ospiti[MAX], int n, char name[51], char surname[51]);
int eliminaOspite(struct Ospite ospiti[MAX], int *n, char name[51], char surname[51]);

int validaEmail(char email[31]);

// Inizio programma
int main () {
    /*
    Traccia: Ospiti Hotel
    */

    // Dichiarazione variabili
    int scelta, dim=0, booking, check;
    char name[51], surname[51], eMail[31];
    struct Ospite v[MAX];

    // Corpo Principale
    do {
        printf("1. Inserisci ospite\n");
        printf("2. Mostra ospiti\n");
        printf("3. Stampa ospite\n");
        printf("4. Elimina ospite\n");
        printf("Altro: Esci\n");
        printf("Inserisci il comando: ");
        scanf("%d", &scelta);

        while (getchar() != '\n');

        system("cls");

        switch (scelta) {
            case 1:
                printf("-------- INSERIMENTO --------\n\n");

                if (dim == MAX)
                    printf("Dimensione massima raggiunta.");

                else {
                    printf("Inserisci il nome: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = 0;
                    printf("Inserisci il cognome: ");
                    fgets(surname, sizeof(surname), stdin);
                    surname[strcspn(surname, "\n")] = 0;

                    do {
                        printf("Inserisci l'email: ");
                        fgets(eMail, sizeof(eMail), stdin);
                        eMail[strcspn(eMail, "\n")] = 0;

                        check = validaEmail(eMail);

                        if (!check)
                            printf("Indirizzo email non valido. Riprova.\n");

                    }while (!check);

                    printf("Inserisci il tipo di prenotazione (1 = bed and breakfast, 2 = mezza pensione, 3 = pensione completa): ");
                    scanf("%d", &booking);

                    inserisciUtente(v, &dim, name, surname, eMail, booking);
                }
            break;

            case 2:
                printf("-------- MOSTRA OSPITI --------\n\n");

                if (dim == 0)
                    printf("Non ci sono ospiti registrati.");

                else
                    mostraOspiti(v, dim);
            break;

            case 3:
                printf("-------- MOSTRA OSPITE --------\n\n");

                if (dim == 0)
                    printf("Non ci sono ospiti registrati.");

                else {
                    printf("Inserisci il nome: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = 0;
                    printf("Inserisci il cognome: ");
                    fgets(surname, sizeof(surname), stdin);
                    surname[strcspn(surname, "\n")] = 0;

                    printf("\n");

                    mostraOspite(v, dim, name, surname);
                }
            break;

            case 4:
                printf("-------- ELIMINA OSPITE --------\n\n");

                if (dim == 0)
                    printf("Non ci sono ospiti registrati.");

                else {
                    printf("Inserisci il nome: ");
                    fgets(name, sizeof(name), stdin);
                    name[strcspn(name, "\n")] = 0;
                    printf("Inserisci il cognome: ");
                    fgets(surname, sizeof(surname), stdin);
                    surname[strcspn(surname, "\n")] = 0;

                    printf("\n");

                    if (eliminaOspite(v, &dim, name, surname))
                        printf("Eliminazione eseguita con successo.");

                    else
                        printf("Non esiste nessun ospite che si chiama %s %s", name, surname);
                }
            break;
        }

        if (scelta >= 1 && scelta <= 4) {
            printf("\n\n");
            system("pause");
            system("cls");
        }

    } while (scelta >= 1 && scelta <= 4);

    return 0;
}

// Cosa fa ogni funzione
void inserisciUtente(struct Ospite ospiti[MAX], int* n, char name[51], char surname[51], char eMail[31], int booking) {
    strcpy(ospiti[*n].nome, name);
    strcpy(ospiti[*n].cognome, surname);
    strcpy(ospiti[*n].email, eMail);
    ospiti[*n].prenotazione = booking;

    (*n)++;
}

void mostraOspiti(struct Ospite ospiti[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("OSPITE %d\n", i+1);
        printf("\tNome: %s\n\tCognome: %s\n\tEmail: %s\n\tPrenotazione (1 = bed and breakfast, 2 = mezza pensione, 3 = pensione completa): %d\n\n", ospiti[i].nome, ospiti[i].cognome, ospiti[i].email, ospiti[i].prenotazione);
    }
}

void mostraOspite(struct Ospite ospiti[MAX], int n, char name[51], char surname[51]) {
    int trovato = 0;

    for (int i = 0; i < n; i++) {
        if (strcmp(ospiti[i].nome, name) == 0 && strcmp(ospiti[i].cognome, surname) == 0) {
            printf("Nome: %s\nCognome: %s\nEmail: %s\nPrenotazione (1 = bed and breakfast, 2 = mezza pensione, 3 = pensione completa): %d\n\n", ospiti[i].nome, ospiti[i].cognome, ospiti[i].email, ospiti[i].prenotazione);

            trovato = 1;
        }
    }

    if (!trovato)
        printf("Nessun ospite che si chiama %s %s", name, surname);
}

int eliminaOspite(struct Ospite ospiti[MAX], int *n, char name[51], char surname[51]) {
    for (int i = 0; i < *n; i++) {
        if (strcmp(ospiti[i].nome, name) == 0 && strcmp(ospiti[i].cognome, surname) == 0) {
            for (int j = i; j < *n - 1; j++)
                ospiti[j] = ospiti[j+1];

            (*n)--;
            return 1;
        }
    }

    return 0;
}

int validaEmail(char email[31]) {
    int len = strlen(email);

    for (int i = 0; i < len; i++) {
        if (email[i] == '@')
            return 1;
    }

    return 0;
}