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
    int n;
    struct Nodo* next;
};

//Prototipo della funzione
void inserimentoTotale(struct Nodo** lista);
void inserimento(struct Nodo** lista);
void visualizzazione(struct Nodo* lista);
void massimo(struct Nodo* lista);
void deallocazione(struct Nodo* lista);

//Inizio programma
int main () {
    /*
    Traccia: 

    Creare un programma che riempia una lista collegata con valori interi
    forniti dall’utente tramite tastiera.

    Al termine dell'inserimento, il programma mette a disposizione un menù,
    tramite il quale l'utente può scegliere di inserire nuovi valori, individuare il
    massimo dei valori inseriti fino a quel momento, o visualizzare gli elementi
    della lista.
    */

    // Dichiarazione variabili
    int scelta;
    struct Nodo* pila = NULL;

    // Corpo Principale
    inserimentoTotale(&pila);

    printf("\n");
    system("pause");
    system("cls");

    do {
        printf("1. Inserimento\n");
        printf("2. Visualizzazione\n");
        printf("3. Calcola massimo\n");
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
                visualizzazione(pila);
            break;

            case 3:
                printf("-------- CALCOLO MASSIMO --------\n\n");
                massimo(pila);
            break;
        }

        if (scelta >= 1 && scelta <= 3) {
            printf("\n\n");
            system("pause");
            system("cls");
        }

    } while (scelta >= 1 && scelta <= 3);

    deallocazione(pila);

    return 0;
}

// Cosa fa ogni funzione
void inserimentoTotale(struct Nodo** lista) {
    int dim;

    printf("Quanti valori vuoi inserire? ");
    scanf("%d", &dim);

    printf("\n");

    for (int i = 0; i < dim; i++)
        inserimento(lista);
}

void inserimento(struct Nodo** lista) {
    struct Nodo* nuovoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));

    printf("Inserisci un valore intero: ");
    scanf("%d", &nuovoNodo->n);

    nuovoNodo->next = *lista;
    *lista = nuovoNodo;
}

void visualizzazione(struct Nodo* lista) {
    int i = 1;

    while (lista != NULL) {
        printf("NODO %d\n", i);
        printf("Numero: %d\n\n", lista->n);

        lista = lista->next;

        i++;
    }
}

void massimo(struct Nodo* lista) {
    int massimo = INT_MIN;
    while (lista != NULL) {
        massimo = max(massimo, lista->n);

        lista = lista->next;
    }

    printf("Il valore massimo tra tutti i nodi \212: %d", massimo);
}

void deallocazione(struct Nodo* lista) {
    while (lista != NULL) {
        struct Nodo* temp = lista;
        lista = lista->next;
        free(temp);
    }
}