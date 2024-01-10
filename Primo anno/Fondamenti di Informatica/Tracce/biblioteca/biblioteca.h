#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<limits.h>
#include<windows.h>

// Variabili globali
#define MAX 50

// Struttura Libro
struct Libro {
    char titolo[51];
    char nomeAutore[41];
    char cognomeAutore[41];
    int annoPubblicazione;
    int nCopie;
};

// Funzioni
void inserisciLibro(struct Libro libri[MAX], int* n, char title[51], char name[41], char surname[41], int year, int copies) {
    strcpy(libri[*n].titolo, title);
    strcpy(libri[*n].nomeAutore, name);
    strcpy(libri[*n].cognomeAutore, surname);
    libri[*n].annoPubblicazione = year;
    libri[*n].nCopie = copies;

    (*n)++;
}

void visualizzaLibri(struct Libro libri[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("LIBRO %d:\n", i+1);
        printf("\tTitolo: %s\n\tNome autore: %s\n\tCognome autore: %s\n\tAnno pubblicazione: %d\n\tNumero copie: %d\n\n", libri[i].titolo, libri[i].nomeAutore, libri[i].cognomeAutore, libri[i].annoPubblicazione, libri[i].nCopie);
    }
}