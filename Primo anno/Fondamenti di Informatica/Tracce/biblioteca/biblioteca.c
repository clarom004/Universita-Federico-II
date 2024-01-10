#include "biblioteca.h"

// Inizio programma
int main () {
    /*
    Traccia: Biblioteca
    */

    // Dichiarazione variabili
    int scelta, dim=5, year, copies;
    char title[51], name[41], surname[41];
    struct Libro v[MAX] = {{"Poe", "Edgar_Allan", "La_sfinge", 1846, 3}, {"Pirandello", "Luigi", "Il_fu_Mattia_Pascal", 1904, 0}, {"Svevo", "Italo", "La_coscienza_di_Zeno", 1923, 0}, {"Calvino", "Italo", "Il_barone_rampante", 1957, 1}, {"Tolkien", "John Ronald Reuel", "Il_signore_degli_anelli", 1968, 5}};

    // Corpo Principale
    do {
        printf("1. Inserisci libro\n");
        printf("2. Visualizza libri\n");
        printf("Altro: Esci\n");
        printf("Inserisci il comando: ");
        scanf("%d", &scelta);

        while (getchar() != '\n');

        system("cls");

        switch (scelta) {
            case 1:
                printf("-------- INSERIMENTO --------\n\n");

                printf("Inserisci il titolo: ");
                fgets(title, sizeof(title), stdin);
                title[strcspn(title, "\n")] = 0;

                printf("Inserisci il nome: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                printf("Inserisci il cognome: ");
                fgets(surname, sizeof(surname), stdin);
                surname[strcspn(surname, "\n")] = 0;

                printf("Inserisci l'anno di pubblicazione: ");
                scanf("%d", &year);

                printf("Inserisci il numero di copie: ");
                scanf("%d", &copies);

                inserisciLibro(v, &dim, title, name, surname, year, copies);
            break;

            case 2:
                printf("-------- VISUALIZZAZIONE --------\n\n");

                if (dim == 0)
                    printf("Non ci sono libri registrati.");

                else
                    visualizzaLibri(v, dim);
            break;
        }

        if (scelta >= 1 && scelta <= 2) {
            printf("\n\n");
            system("pause");
            system("cls");
        }

    } while (scelta >= 1 && scelta <= 2);

    return 0;
}