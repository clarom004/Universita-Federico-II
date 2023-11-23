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
void inserimento(struct Nodo** lista);
void visualizzazione(struct Nodo* lista);
void eliminazione(struct Nodo** lista, char nome[50]);
void ricerca(struct Nodo* lista, char destinazione[50]);
void deallocazione(struct Nodo* lista);

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
    struct Nodo* pila = NULL;
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

                inserimento(&pila);
            break;

            case 2:
                printf("-------- VISUALIZZAZIONE --------\n\n");

                if (pila == NULL)
                    printf("Nessuna prenotazione registrata.");

                else
                    visualizzazione(pila);
            break;

            case 3:
                printf("-------- ELIMINAZIONE --------\n\n");

                if (pila == NULL)
                    printf("Nessuna prenotazione registrata.");

                else {
                    printf("Inserisci il nome del passeggero: ");
                    scanf(" %[^\n]", name);

                    eliminazione(&pila, name);
                }
            break;

            case 4:
                printf("-------- RICERCA --------\n\n");

                if (pila == NULL)
                    printf("Nessuna prenotazione registrata.");

                else {
                    printf("Inserisci la destinazione del viaggio: ");
                    scanf(" %[^\n]", destinazione);

                    ricerca(pila, destinazione);
                }
            break;
        }

        if (scelta >= 1 && scelta <= 4) {
            printf("\n\n");
            system("pause");
            system("cls");
        }

    } while (scelta >= 1 && scelta <= 4);

    deallocazione(pila);

    return 0;
}

// Cosa fa ogni funzione
void inserimento(struct Nodo** lista) {
    struct Nodo* nuovoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));

    printf("Inserisci il nome del passeggero: ");
    scanf(" %[^\n]", nuovoNodo->prenotazione.nome);
    printf("Inserisci la destinazione del viaggio: ");
    scanf(" %[^\n]", nuovoNodo->prenotazione.destinazione);
    printf("Inserisci la data del viaggio (xx/yy/zzzz): ");
    scanf("%s", nuovoNodo->prenotazione.data);

    nuovoNodo->next = *lista;
    *lista = nuovoNodo;

    return;
}

void visualizzazione(struct Nodo* lista) {
    int i = 1;

    while (lista != NULL) {
        printf("PRENOTAZIONE %d\n", i);
        printf("\tNome passeggero: %s\n\tDestinazione viaggio: %s\n\tData viaggio: %s\n\n", lista->prenotazione.nome, lista->prenotazione.destinazione, lista->prenotazione.data);

        lista = lista->next;

        i++;
    }

    return;
}

void eliminazione(struct Nodo** lista, char nome[50]) {
    struct Nodo* temp = *lista;
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
        *lista = temp->next;

    else
        precedente->next = temp->next;

    free(temp);
    printf("\nPrenotazione eliminata con successo.");

    return;
}

void ricerca(struct Nodo* lista, char destinazione[50]) {
    int i = 1;

    while (lista != NULL) {
        if (strcmp(lista->prenotazione.destinazione, destinazione) == 0) {
            printf("\nPRENOTAZIONE %d\n", i);
            printf("\tNome passeggero: %s\n\tDestinazione viaggio: %s\n\tData viaggio: %s\n\n", lista->prenotazione.nome, lista->prenotazione.destinazione, lista->prenotazione.data);

            lista = lista->next;

            i++;
        }
    }

    return;
}

void deallocazione(struct Nodo* lista) {
    while (lista != NULL) {
        struct Nodo* temp = lista;
        lista = lista->next;
        free(temp);
    }

    return;
}