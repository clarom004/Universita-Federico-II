#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<limits.h>
#include<stdbool.h>
#include<windows.h>

// Definizione della struttura (record) alunno
struct Studente {
    char nome[50];
    char cognome[50];
    char matricola[10];
    float voto;
};

// Definizione di una lista di studenti utilizzando una lista collegata
struct Nodo {
    struct Studente studente;
    struct Nodo* next;
};

//Prototipo della funzione
void inserimento(struct Nodo** lista);
void visualizzazione(struct Nodo* lista);
void media(struct Nodo* lista);
void ricerca(struct Nodo* lista, char matricola[10]);
void eliminazione(struct Nodo** lista, char matricola[10]);

//Inizio programma
int main () {
    /*
    Traccia: Gestione di Studenti

    Si vuole creare un programma in C per gestire una lista di studenti. Ogni studente ha le seguenti informazioni:

    - Nome
    - Cognome
    - Matricola
    - Voto di esame

    Dichiarare una struttura "Studente" che contenga questi campi.

    1. Creare una funzione per l'inserimento di nuovi studenti. La funzione dovrebbe richiedere all'utente di inserire nome, cognome, matricola e voto di esame per uno studente e aggiungerlo alla lista.

    2. Creare una funzione per la stampa di tutti gli studenti presenti nella lista. Assicurarsi che vengano visualizzati tutti i dettagli di ciascuno studente.

    3. Creare una funzione per calcolare la media dei voti di tutti gli studenti presenti nella lista e stamparla.

    4. Creare una funzione per cercare uno studente per matricola. L'utente dovrebbe inserire una matricola, e il programma dovrebbe restituire tutti i dettagli dello studente con quella matricola.

    5. Implementare una funzione per la cancellazione di uno studente dalla lista. L'utente dovrebbe inserire la matricola dello studente da eliminare.
    */

    // Dichiarazione variabili
    int scelta;
    char mat[10];
    struct Nodo* lista = NULL; // Inizializza la lista degli studenti come vuota

    // Corpo Principale
    do {
        printf("1. Inserimento\n");
        printf("2. Visualizzazione\n");
        printf("3. Calcolo media\n");
        printf("4. Ricerca\n");
        printf("5. Eliminazione\n");
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
                    printf("Non ci sono studenti.");
                
                else
                    visualizzazione(lista);
            break;

            case 3:
                printf("-------- CALCOLO MEDIA --------\n\n");

                if (lista == NULL) 
                    printf("Non ci sono studenti.");
                
                else
                    media(lista);
            break;

            case 4:
                printf("-------- RICERCA --------\n\n");

                if (lista == NULL) 
                    printf("Non ci sono studenti.");
                
                else {
                    printf("Inserisci la matricola da ricercare: ");
                    scanf("%s", mat);

                    ricerca(lista, mat);
                }
            break;

            case 5:
                printf("-------- ELIMINAZIONE --------\n\n");

                if (lista == NULL) 
                    printf("Non ci sono studenti.");
                
                else {
                    printf("Inserisci la matricola da eliminare: ");
                    scanf("%s", mat);

                    eliminazione(&lista, mat);
                }
            break;
        }

        if (scelta >= 1 && scelta <= 5) {
            printf("\n\n");
            system("pause");
            system("cls");
        }

    } while (scelta >= 1 && scelta <= 5);

    // Deallocazione della memoria alla fine del programma
    while (lista != NULL) {
        struct Nodo* temp = lista;
        lista = lista->next;
        free(temp);
    }

    return 0;
}

// Cosa fa ogni funzione
void inserimento(struct Nodo** lista) {
    struct Studente nuovoStudente;

    printf("Inserisci il nome dello studente: ");
    scanf("%s", nuovoStudente.nome);
    printf("Inserisci il cognome dello studente: ");
    scanf("%s", nuovoStudente.cognome);
    printf("Inserisci la matricola dello studente: ");
    scanf("%s", nuovoStudente.matricola);
    printf("Inserisci il voto dello studente: ");
    scanf("%f", &nuovoStudente.voto);

    struct Nodo* nuovoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuovoNodo->studente = nuovoStudente;
    nuovoNodo->next = *lista;
    *lista = nuovoNodo;

    return;
}

void visualizzazione(struct Nodo* lista) {
    int i = 1;

    while (lista != NULL) {
        printf("STUDENTE %d\n", i);
        printf("\tNome: %s\n\tCognome: %s\n\tMatricola: %s\n\tVoto: %.2f\n\n", lista->studente.nome, lista->studente.cognome, lista->studente.matricola, lista->studente.voto);

        lista = lista->next;

        i++;
    }

    return;
}

void media(struct Nodo* lista) {
    float media = 0;
    int cont = 0;

    while (lista != NULL) {
        media += lista->studente.voto;
        cont++;

        lista = lista->next;
    }

    media /= cont;

    printf("La media dei voti \212: %.2f", media);

    return;
}

void ricerca(struct Nodo* lista, char matricola[10]) {
    while (lista != NULL) {
        if (strcmp(lista->studente.matricola, matricola) == 0) {
            printf("\nStudente trovato:\n");
            printf("\tNome: %s\n\tCognome: %s\n\tMatricola: %s\n\tVoto: %.2f", lista->studente.nome, lista->studente.cognome, lista->studente.matricola, lista->studente.voto);

            return;
        }

        lista = lista->next;
    }

    printf("Studente non trovato.");

    return;
}

void eliminazione(struct Nodo** lista, char matricola[10]) {
    struct Nodo* temp = *lista;
    struct Nodo* precedente = NULL;

    while (temp != NULL && strcmp(temp->studente.matricola, matricola) != 0) {
        precedente = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Studente non trovato.");
        return;
    }

    if(precedente == NULL)
        *lista = temp->next;

    else
        precedente->next = temp->next;

    free(temp);
    printf("Studente eliminato con successo.");

    return;
}