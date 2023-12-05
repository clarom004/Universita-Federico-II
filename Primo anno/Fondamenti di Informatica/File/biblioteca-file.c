#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struttura Libro
struct Libro {
    char ISBN[13];
    char titolo[100];
    char autore[50];
    int nCopie;
};

// Struttura Nodo per una Coda FIFO
struct Nodo {
    struct Libro libro;
    struct Nodo* next;
};

// Prototipo della funzione
void aggiungiLibro(struct Nodo** coda, char isbn[13], char title[100], char author[50], int copies);
void visualizzaCatalogo(struct Nodo* coda);

void deallocazione(struct Nodo** coda);

void salvaSuFile(struct Nodo* coda);
void caricaDaFile(struct Nodo** coda);

void clearScreen();
void pauseExecution();

// Inizio programma
int main() {
    /*
    Traccia del Programma: Gestione Biblioteca con Coda FIFO

    Obiettivo:
    Implementare un sistema di gestione di una biblioteca in C utilizzando la struttura di coda FIFO con record, puntatori e operazioni su file.
    
    Specifiche:
    
    Definire una struttura, ad esempio Libro, per rappresentare un libro in biblioteca. La struttura dovrebbe contenere campi come titolo, autore, numero di copie disponibili.
    
    Implementare una struttura per la coda.
    
    Scrivere funzioni per eseguire le seguenti operazioni:
    
    1. aggiungiLibro: Aggiunge un nuovo libro alla fine della coda.
    2. prestaLibro: Decrementa il numero di copie del libro (lo elimina se era l'ultima copia rimasta).
    3. verificaDisponibilita: Controlla se il libro è presente nella coda.
    4. visualizzaCatalogo: Visualizza l'elenco dei libri nella coda.
    
    Creare un programma con un menu che consenta all'utente di interagire con la biblioteca. Il menu dovrebbe includere opzioni per:
    
    1. Aggiungere un nuovo libro al catalogo.
    2. Prestare un libro.
    3. Verificare la disponibilità di libri.
    4. Visualizzare il catalogo dei libri.
    5. Uscire dal programma.
    
    Utilizzare operazioni su file per salvare lo stato corrente della coda dei libri su un file e caricarlo all'avvio del programma.
    */
    
    // Dichiarazione variabili
    int scelta, copies;
    struct Nodo* lista = NULL;
    char isbn[13], title[100], author[50];
    
    // Corpo principale
    caricaDaFile(&lista);

    do {
        printf("1. Aggiungi libro\n");
        printf("2. Visualizza catalogo\n");
        printf("Altro: Esci\n");
        printf("Inserisci il comando: ");
        scanf("%d", &scelta);
        
        clearScreen();
        
        switch (scelta) {
            case 1:
                printf("-------- AGGIUNGI LIBRO --------\n\n");
                
                printf("Inserisci l'ISBN: ");
                scanf("%s", isbn);
                while (getchar() != '\n');
                
                printf("Inserisci il titolo: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;
                
                printf("Inserisci l'autore: ");
                fgets(author, sizeof(author), stdin);
                author[strcspn(author, "\n")] = 0;
                
                printf("Inserisci il numero di copie: ");
                scanf("%d", &copies);
                
                aggiungiLibro(&lista, isbn, title, author, copies);
                salvaSuFile(lista);
            break;
            
            case 2:
                printf("-------- VISUALIZZA CATALOGO --------\n\n");
                
                if (lista == NULL)
                    printf("Nessun libro presente.");
                    
                else
                    visualizzaCatalogo(lista);
            break;
        }
        
        if (scelta >= 1 && scelta <= 3) {
            printf("\n\n");
            pauseExecution();
            clearScreen();
        }
        
    } while (scelta >= 1 && scelta <= 2);
    
    deallocazione(&lista);
    
    return 0;
}

// Definizione funzioni
void aggiungiLibro(struct Nodo** coda, char isbn[13], char title[100], char author[50], int copies) {
    struct Nodo* nuovoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    
    strcpy(nuovoNodo->libro.ISBN, isbn);
    strcpy(nuovoNodo->libro.titolo, title);
    strcpy(nuovoNodo->libro.autore, author);
    nuovoNodo->libro.nCopie = copies;
    
    nuovoNodo->next = NULL;
    
    if (*coda == NULL)
        *coda = nuovoNodo;
        
    else {
        struct Nodo* temp = *coda;
        
        while (temp->next != NULL)
            temp = temp->next;
            
        temp->next = nuovoNodo;
    }
}

void visualizzaCatalogo(struct Nodo* coda) {
    while (coda != NULL) {
        printf("------------------------------------------------\n");
        printf("ISBN: %s\nTitolo: %s\nAutore: %s\nNumero copie: %d\n", coda->libro.ISBN, coda->libro.titolo, coda->libro.autore, coda->libro.nCopie);
        printf("------------------------------------------------\n\n");
        coda = coda->next;
    }
}

void salvaSuFile(struct Nodo* coda) {
    FILE* output = fopen("catalogo.txt", "w");
    
    while (coda != NULL) {
        fprintf(output, "------------------------------------------------\n");
        fprintf(output, "ISBN: %s\nTitolo: %s\nAutore: %s\nNumero copie: %d\n", coda->libro.ISBN, coda->libro.titolo, coda->libro.autore, coda->libro.nCopie);
        fprintf(output, "------------------------------------------------\n\n");
        coda = coda->next;
    }
    
    fclose(output);
}

void caricaDaFile(struct Nodo** coda) {
    FILE* input = fopen("catalogo.txt", "r");
    
    if (input == NULL)
        return;

    char isbn[13], title[100], author[50];
    int copies;

    while (fscanf(input, "------------------------------------------------\nISBN: %s\nTitolo: %[^\n]\nAutore: %[^\n]\nNumero copie: %d\n------------------------------------------------\n\n", isbn, title, author, &copies) == 4)
        aggiungiLibro(coda, isbn, title, author, copies);

    fclose(input);
}

void deallocazione(struct Nodo** coda) {
    while (*coda != NULL) {
        struct Nodo* temp = *coda;
        *coda = (*coda)->next;
        free(temp);
    }
}

void clearScreen() {
    printf("\033[2J\033[H");
}

void pauseExecution() {
    printf("Premi Invio per continuare...");
    getchar();
    while (getchar() != '\n');
}