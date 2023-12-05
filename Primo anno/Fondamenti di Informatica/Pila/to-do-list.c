#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<limits.h>
#include<windows.h>

// Struttura Pila
struct Nodo {
    char attivita[255];
    struct Nodo* next;
};

// Prototipo della funzione
void inserimento(struct Nodo** pila);
void visualizzazione(struct Nodo* pila);
void eliminazione(struct Nodo** pila, int n);
void deallocazione(struct Nodo** pila);

// Inizio programma
int main () {
    /*
    Traccia:
    Scrivi un programma in linguaggio C che simuli un gestore di attività (to-do list) utilizzando una struttura di pila (stack) LIFO.

    Le funzionalità del programma possono includere:

    1. Aggiunta di attività: consenti all'utente di aggiungere nuove attività alla to-do list.

    2. Visualizzazione delle attività: stampa a schermo l'elenco delle attività presenti nella to-do list.

    3. Rimozione dell'ultima attività: implementa la possibilità di rimuovere l'ultima attività inserita.

    4. Undo delle operazioni: permetti all'utente di annullare l'ultima operazione effettuata, ripristinando lo stato precedente della to-do list.
    */

    // Dichiarazione variabili
    int scelta, numero;
    struct Nodo* lista = NULL;

    // Corpo Principale
    do {
        printf("1. Inserimento\n");
        printf("2. Visualizzazione\n");
        printf("3. Eliminazione\n");
        printf("Altro: Esci\n");
        printf("Inserisci il comando: ");
        scanf("%d", &scelta);

        while (getchar() != '\n');

        system("cls");

        switch (scelta) {
            case 1:
                printf("-------- INSERIMENTO --------\n\n");

                inserimento(&lista);
            break;

            case 2:
                printf("-------- VISUALIZZAZIONE --------\n\n");

                if (lista == NULL)
                    printf("Non ci sono attivita nella to-do list.");

                else
                    visualizzazione(lista);
            break;

            case 3:
                printf("-------- ELIMINAZIONE --------\n\n");

                if (lista == NULL)
                    printf("Non ci sono attivita nella to-do list.");

                else {
                    printf("Inserisci il numero dell'attivita da eliminare: ");
                    scanf("%d", &numero);

                    eliminazione(&lista, numero);
                }
            break;
        }

        if (scelta >= 1 && scelta <= 3) {
            printf("\n\n");
            system("pause");
            system("cls");
        }

    } while (scelta >= 1 && scelta <= 3);

    return 0;
}

// Cosa fa ogni funzione
void inserimento(struct Nodo** pila) {
    struct Nodo* nuovoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));

    printf("Inserisci l'attivita: ");
    fgets(nuovoNodo->attivita, sizeof(nuovoNodo->attivita), stdin);
    nuovoNodo->attivita[strcspn(nuovoNodo->attivita, "\n")] = 0;

    nuovoNodo->next = *pila;
    *pila = nuovoNodo;
}

void visualizzazione(struct Nodo* pila) {
    int i = 1;

    while (pila != NULL) {
        printf("%d. %s\n", i, pila->attivita);

        pila = pila->next;
        i++;
    }
}

void eliminazione(struct Nodo** pila, int n) {
    struct Nodo* temp = *pila;
    struct Nodo* precedente = NULL;

    int i = 1;

    while (temp != NULL && i != n) {
        precedente = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Non esiste un attivita con questo numero.");
        return;
    }

    if (precedente == NULL)
        *pila = (*pila)->next;

    else
        precedente->next = temp->next;

    free(temp);
    printf("Attivita eliminata con successo.");
}

void deallocazione(struct Nodo** pila) {
    while (*pila != NULL) {
        struct Nodo* temp = *pila;
        *pila = (*pila)->next;
        free(temp);
    }
}