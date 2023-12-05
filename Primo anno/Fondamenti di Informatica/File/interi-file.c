#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
#include<limits.h>
#include<windows.h>
#include<stdbool.h>

// Variabili globali
int const MAX = 100;

// Prototipo della funzione
void caricamentoVettore(int v[MAX], int n);
void caricamentoFile(int v[MAX], int n);
void letturaFile(int n);

// Inizio programma
int main () {
    /*
    Traccia: 
    - Progettare e scrivere un programma che legga una sequenza di interi da un file di testo e li inserisca in un vettore.
    - Il programma scrive gli interi letti in un altro file, riportando gli interi in sequenza inversa e sommando 1 a ciascun valore.
    */

    // Dichiarazione variabili
    int scelta, vett[MAX], dim;

    // Corpo Principale
    do {
        printf("1. Caricamento vettore\n");
        printf("2. Lettura file\n");
        printf("Altro: Esci\n");
        printf("Inserisci il comando: ");
        scanf("%d", &scelta);

        system("cls");

        switch (scelta) {
            case 1:
                printf("-------- CARICAMENTO VETTORE E FILE --------\n\n");

                do {
                    printf("Inserisci la dimensione: ");
                    scanf("%d", &dim);

                    if (dim <= 0 || dim > MAX)
                        printf("Dimensione non valida.\n\n");

                }while (dim <= 0 || dim > MAX);

                printf("\n");

                caricamentoVettore(vett, dim);
                caricamentoFile(vett, dim);
            break;

            case 2:
                printf("-------- LETTURA FILE --------\n\n");

                if (dim == 0)
                    printf("File vuoto.");

                else
                    letturaFile(dim);
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
void caricamentoVettore(int v[MAX], int n) {
    for (int i = 0; i < n; i++) {
        printf("Inserisci il %d\247 numero: ", i+1);
        scanf("%d", &v[i]);
    }
}

void caricamentoFile(int v[MAX], int n) {
    FILE* output;

    output = fopen("file_interi.txt", "a");

    for (int i = 0; i < n; i++) {
        fprintf(output, "%d\n", v[i]);
    }

    fclose(output);
}

void letturaFile(int n) {
    FILE* input;

    input = fopen("file_interi.txt", "r");

    int minimo = INT_MAX, massimo = INT_MIN, dim = 0, numeri[MAX], i = 0;

    while (fscanf(input, "%d", &numeri[i]) == 1) {
        printf("%d\247 numero: %d\n", i + 1, numeri[i]);
        minimo = min(minimo, numeri[i]);
        massimo = max(massimo, numeri[i]);
        i++;
        dim++;
    }

    printf("\nIl minimo numero \212: %d", minimo);
    printf("\nIl massimo numero \212: %d", massimo);


    printf("\n\n-------- VETTORE AL CONTRARIO --------\n\n");
    for (int i = 0, j = dim-1; j >= 0; i++, j--) {
        numeri[j]++;
        printf("%d\247 numero: %d\n", i + 1, numeri[j]);
    }

    fclose(input);
}
