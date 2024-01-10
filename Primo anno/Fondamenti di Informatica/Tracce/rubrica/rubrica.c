#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<time.h>
#include<limits.h>
#include<windows.h>

// Variabili globali
#define MAX 100

// Enum Categoria
enum Categoria {
    AMICI, 
    LAVORO, 
    FAMIGLIA, 
    ALTRO
};

// Struttura Contatto
struct Contatto {
    char nome[51];
    char cognome[51];
    char telefono[16];
    char sesso;
    unsigned int eta;
    enum Categoria categoria;
};

// Struttura Pila Statica
struct Rubrica {
    struct Contatto contatti[MAX];
    int n;
};

// Prototipo della funzione
struct Rubrica nuovaRubrica();
struct Contatto nuovoContatto(char nome[51], char cognome[51], char telefono[16], char sesso, unsigned int eta, enum Categoria categoria);
void aggiungiContatto(struct Rubrica* rubrica, struct Contatto newContatto);
void mostraRubrica(struct Rubrica rubrica);
void stampaContatto(struct Contatto contatto);
void ordinaPerNomeCognome(struct Rubrica* rubrica);
bool contattoDaNumero(struct Rubrica rubrica, char telefono[16]);
bool eliminaContatto(struct Rubrica* rubrica, char nome[51], char cognome[51]);

void salvaSuFile(struct Rubrica rubrica);
void caricaDaFile(struct Rubrica* rubrica);

// Inizio programma
int main () {
    /*
    Traccia: Rubrica
    */

    // Dichiarazione variabili
    int scelta;
    bool trovato;
    char nome[51], cognome[51], telefono[16], sesso;
    unsigned int eta; 
    enum Categoria categoria;
    struct Rubrica rubrica = nuovaRubrica();

    // Corpo Principale
    caricaDaFile(&rubrica);

    do {
        printf("1. Aggiungi nuovo contatto\n");
        printf("2. Mostra rubrica ordinata per eta\n");
        printf("3. Ricerca contatto da numero di telefono\n");
        printf("4. Elimina contatto\n");
        printf("Altro: Esci\n");
        printf("Inserisci il comando: ");
        scanf("%d", &scelta);

        while (getchar() != '\n');

        system("cls");

        switch (scelta) {
            case 1:
                printf("-------- INSERIMENTO --------\n\n");

                if (rubrica.n >= MAX)
                    printf("Rubrica piena.");

                else {
                    printf("Inserisci il nome: ");
                    fgets(nome, sizeof(nome), stdin);
                    nome[strcspn(nome, "\n")] = 0;

                    printf("Inserisci il cognome: ");
                    fgets(cognome, sizeof(cognome), stdin);
                    cognome[strcspn(cognome, "\n")] = 0;

                    printf("Inserisci il numero di telefono: ");
                    scanf("%s", telefono);

                    while (getchar() != '\n');

                    printf("Inserisci il sesso (m = maschio, f = femmina): ");
                    scanf("%c", &sesso);

                    printf("Inserisci l'eta: ");
                    scanf("%d", &eta);

                    printf("Inserisci la categoria (AMICI = 0, LAVORO = 1, FAMIGLIA = 2, ALTRO = 3): ");
                    scanf("%d", &categoria);

                    struct Contatto newContatto = nuovoContatto(nome, cognome, telefono, sesso, eta, categoria);
                    aggiungiContatto(&rubrica, newContatto);
                    salvaSuFile(rubrica);
                }
            break;

            case 2:
                printf("-------- VISUALIZZAZIONE --------\n\n");

                if (rubrica.n == 0)
                    printf("Rubrica vuota.");

                else {
                    ordinaPerNomeCognome(&rubrica);
                    mostraRubrica(rubrica);
                }
            break;

            case 3:
                printf("-------- RICERCA CONTATTO DA NUMERO DI TELEFONO --------\n\n");

                if (rubrica.n == 0)
                    printf("Rubrica vuota.");

                else {
                    printf("Inserisci il numero di telefono: ");
                    scanf("%s", telefono);

                    printf("\n");

                    if (!contattoDaNumero(rubrica, telefono))
                        printf("Non ci sono contatti con numero di telefono '%s'.", telefono);

                }
            break;

            case 4:
                printf("-------- ELIMINA CONTATTO --------\n\n");

                if (rubrica.n == 0)
                    printf("Rubrica vuota.");

                else {
                    printf("Inserisci il nome: ");
                    fgets(nome, sizeof(nome), stdin);
                    nome[strcspn(nome, "\n")] = 0;

                    printf("Inserisci il cognome: ");
                    fgets(cognome, sizeof(cognome), stdin);
                    cognome[strcspn(cognome, "\n")] = 0;

                    trovato = eliminaContatto(&rubrica, nome, cognome);

                    if (trovato)
                        printf("\nEliminazione effettuata con successo.");

                    else if (!trovato)
                        printf("\nNon ci sono contatti che si chiamano '%s %s'.", nome, cognome);

                    salvaSuFile(rubrica);
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
struct Rubrica nuovaRubrica() {
    struct Rubrica nuovaRubrica;
    nuovaRubrica.n = 0;
    return nuovaRubrica;
}

struct Contatto nuovoContatto(char nome[51], char cognome[51], char telefono[16], char sesso, unsigned int eta, enum Categoria categoria) {
    struct Contatto newContatto;

    strcpy(newContatto.nome, nome);
    strcpy(newContatto.cognome, cognome);
    strcpy(newContatto.telefono, telefono);
    newContatto.sesso = sesso;
    newContatto.eta = eta;
    newContatto.categoria = categoria;

    return newContatto;
}

void aggiungiContatto(struct Rubrica* rubrica, struct Contatto newContatto) {
    rubrica->contatti[rubrica->n] = newContatto;
    (rubrica->n)++;
}

void mostraRubrica(struct Rubrica rubrica) {
    printf("La rubrica contiene %d contatti.\n\n", rubrica.n);

    for (int i = 0; i < rubrica.n; i++)
        stampaContatto(rubrica.contatti[i]);
}

void stampaContatto(struct Contatto contatto) {
    printf("------------------------------------------------\n");
    printf("Nome: %s\nCognome: %s\nNumero di telefono: %s\nSesso: %c\nEta: %d\n", contatto.nome, contatto.cognome, contatto.telefono, contatto.sesso, contatto.eta);
    switch (contatto.categoria) {
        case AMICI:
            printf("Categoria: Amici\n");
        break; 
        case LAVORO:
            printf("Categoria: Lavoro\n");
        break; 
        case FAMIGLIA:
            printf("Categoria: Famiglia\n");
        break; 
        case ALTRO:
            printf("Categoria: Altro\n");
        break;
    }
    printf("------------------------------------------------\n\n");
}

void ordinaPerNomeCognome(struct Rubrica* rubrica) {
    for (int i = 0; i < rubrica->n - 1; i++) {
        for (int j = i + 1; j < rubrica->n; j++) {
            if (strcmp(rubrica->contatti[i].nome, rubrica->contatti[j].nome) > 0 && strcmp(rubrica->contatti[i].cognome, rubrica->contatti[j].cognome) > 0) {
                struct Contatto temp = rubrica->contatti[i];
                rubrica->contatti[i] = rubrica->contatti[j];
                rubrica->contatti[j] = temp;
            }
        }
    }
}

bool contattoDaNumero(struct Rubrica rubrica, char telefono[16]) {
    for (int i = 0; i < rubrica.n; i++) {
        if (strcmp(rubrica.contatti[i].telefono, telefono) == 0) {
            stampaContatto(rubrica.contatti[i]);
            return true;
        }
    }

    return false;
}

bool eliminaContatto(struct Rubrica* rubrica, char nome[51], char cognome[51]) {
    for (int i = 0; i < rubrica->n; i++) {
        if (strcmp(rubrica->contatti[i].nome, nome) == 0 && strcmp(rubrica->contatti[i].cognome, cognome) == 0) {
            for (int j = i + 1; j < rubrica->n - 1; j++)
                rubrica->contatti[j] = rubrica->contatti[j+1];

            (rubrica->n)--;
            return true;
        }
    }

    return false;
}

void salvaSuFile(struct Rubrica rubrica) {
    FILE* output = fopen("rubrica.txt", "w");

    for (int i = 0; i < rubrica.n; i++) {
        fprintf(output, "------------------------------------------------\n");
        fprintf(output, "Nome: %s\nCognome: %s\nNumero di telefono: %s\nSesso: %c\nEta: %d\nCategoria: %d\n", rubrica.contatti[i].nome, rubrica.contatti[i].cognome, rubrica.contatti[i].telefono, rubrica.contatti[i].sesso, rubrica.contatti[i].eta, rubrica.contatti[i].categoria);
        fprintf(output, "------------------------------------------------\n\n");
    }

    fclose(output);
}

void caricaDaFile(struct Rubrica* rubrica) {
    struct Contatto newContatto;

    FILE* input = fopen("rubrica.txt", "r");

    if (input == NULL)
        return;

    while (fscanf(input, "------------------------------------------------\nNome: %[^\n]\nCognome: %[^\n]\nNumero di telefono: %s\nSesso: %c\nEta: %d\nCategoria: %d\n------------------------------------------------\n\n", newContatto.nome, newContatto.cognome, newContatto.telefono, &newContatto.sesso, &newContatto.eta, &newContatto.categoria) != EOF) {
        aggiungiContatto(rubrica, newContatto);
    }

    fclose(input);
}