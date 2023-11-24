#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<limits.h>
#include<windows.h>

// Record Prenotazione
struct Prenotazione {
    char nome[50];
    char destinazione[50];
    char data[10];
};

// Record Nodo
struct Nodo {
    struct Prenotazione prenotazione;
    struct Nodo* next;
};

//Prototipo della funzione
void inserimento(struct Nodo** coda);
void visualizzazione(struct Nodo* coda);
void eliminazione(struct Nodo** coda, char nome[50]);
void ricerca(struct Nodo* coda, char destinazione[50]);
int dimensione(struct Nodo* coda);
void deallocazione(struct Nodo** coda);

//Inizio programma
int main () {
    /*
    Traccia: Registro delle Prenotazioni di Viaggio

    Scrivi un programma in C per gestire un registro delle prenotazioni di viaggio. Ogni prenotazione dovrebbe essere rappresentata da un record contenente le seguenti informazioni: nome del passeggero, destinazione, data della prenotazione.

    Il programma dovrebbe consentire all'utente di:

    1. Inserire nuove prenotazioni nel sistema.
    2. Visualizzare l'elenco completo delle prenotazioni.
    3. Cancellare una prenotazione in base al nome del passeggero.
    4. Trovare e visualizzare tutte le prenotazioni per una destinazione specifica.
    
    Utilizza puntatori a record per gestire le informazioni sulle prenotazioni e assicurati di gestire dinamicamente la memoria.
    */

    // Dichiarazione variabili
    int scelta;
    struct Nodo* lista = NULL;
    char name[50];
    char destinazione[50];

    // Corpo Principale
    do {
        printf("1. Inserimento\n");
        printf("2. Visualizzazione\n");
        printf("3. Eliminazione per nome\n");
        printf("4. Ricerca per destinazione\n");
        printf("Altro: Esci\n");
        printf("Inserisci il comando: ");
        scanf("%d", &scelta);

        system("cls");

        switch (scelta) {
            case 1:
                printf("-------- INSERIMENTO --------\n\n");

                inserimento(&lista);
            break;

            case 2:
                printf("-------- VISUALIZZAZIONE --------\n\n");

                if (lista == NULL)
                    printf("Nessuna prenotazione registrata.");

                else
                    visualizzazione(lista);
            break;

            case 3:
                printf("-------- ELIMINAZIONE --------\n\n");

                if (lista == NULL)
                    printf("Nessuna prenotazione registrata.");

                else {
                    printf("Inserisci il nome del passeggero: ");
                    scanf(" %[^\n]", name);

                    eliminazione(&lista, name);
                }
            break;

            case 4:
                printf("-------- RICERCA --------\n\n");

                if (lista == NULL)
                    printf("Nessuna prenotazione registrata.");

                else {
                    printf("Inserisci la destinazione del viaggio: ");
                    scanf(" %[^\n]", destinazione);

                    ricerca(lista, destinazione);
                }
            break;
        }

        if (scelta >= 1 && scelta <= 4) {
            printf("\n\n");
            system("pause");
            system("cls");
        }

    } while (scelta >= 1 && scelta <= 4);

    deallocazione(&lista);

    return 0;
}

// Cosa fa ogni funzione
void inserimento(struct Nodo** coda) {
    int posizione;
    int dim = dimensione(*coda);

    struct Nodo* nuovoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));

    printf("Inserisci il nome del passeggero: ");
    scanf(" %[^\n]", nuovoNodo->prenotazione.nome);
    printf("Inserisci la destinazione del viaggio: ");
    scanf(" %[^\n]", nuovoNodo->prenotazione.destinazione);
    printf("Inserisci la data del viaggio (xx/yy/zzzz): ");
    scanf("%s", nuovoNodo->prenotazione.data);

    if (dim == 0)
        posizione = 1;

    if (dim > 0) {
        printf("\nInserisci la posizione in cui inserire la prenotazione (da 1=inizio a %d=fine): ", dim + 1);
        scanf("%d", &posizione);

        if(posizione <= 0 || posizione > dim + 1) {
            printf("\nPosizione non valida.");
            return;
        }
    }

    if (posizione == 1) {
        if (*coda == NULL)
            nuovoNodo->next = NULL;

        else
            nuovoNodo->next = *coda;

        *coda = nuovoNodo;

        return;
    }

    struct Nodo* temp = *coda;

    for (int i = 0; i < posizione - 2; i++)
        temp = temp->next;

    nuovoNodo->next = temp->next;
    temp->next = nuovoNodo;
}

void visualizzazione(struct Nodo* coda) {
    int i = 1;

    while (coda != NULL) {
        printf("PRENOTAZIONE %d\n", i);
        printf("\tNome passeggero: %s\n\tDestinazione viaggio: %s\n\tData viaggio: %s\n\n", coda->prenotazione.nome, coda->prenotazione.destinazione, coda->prenotazione.data);

        coda = coda->next;

        i++;
    }
}

void eliminazione(struct Nodo** coda, char nome[50]) {
    struct Nodo* temp = *coda;
    struct Nodo* precedente = NULL;

    while (temp != NULL && strcmp(nome, temp->prenotazione.nome) != 0) {
        precedente = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nNessuna prenotazione con nome passeggero '%s' trovata.", nome);
        return;
    }

    if (precedente == NULL)
        *coda = temp->next;

    else
        precedente->next = temp->next;

    free(temp);
    printf("\nPrenotazione eliminata con successo.");
}

void ricerca(struct Nodo* coda, char destinazione[50]) {
    int i = 1;

    while (coda != NULL) {
        if (strcmp(coda->prenotazione.destinazione, destinazione) == 0) {
            printf("\nPRENOTAZIONE %d\n", i);
            printf("\tNome passeggero: %s\n\tDestinazione viaggio: %s\n\tData viaggio: %s\n\n", coda->prenotazione.nome, coda->prenotazione.destinazione, coda->prenotazione.data);

            coda = coda->next;

            i++;
        }
    }
}

int dimensione(struct Nodo* coda) {
    int n = 0;

    while (coda != NULL) {
        coda = coda->next;
        n++;
    }

    return n;
}

void deallocazione(struct Nodo** coda) {
    while (*coda != NULL) {
        struct Nodo* temp = *coda;
        *coda = (*coda)->next;
        free(temp);
    }
}