#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void affiche_vache(char* yeux, char* text,char langue) {
    if (strlen(yeux) != 2) {
        printf("Les yeux doivent être représentés par une chaîne de deux caractères.\n");
        return;
    }
    if (strlen(text) > 0) {
    int i;
    printf(" ");
    for (i = 0; i < strlen(text); i++) {
        printf("_");
    }
    printf(" \n");
    printf("< %s >\n", text); // Afficher le texte
    printf(" ");
    for (i = 0; i < strlen(text); i++) {
        printf("-");
    }
    printf(" \n");
}

    printf("  \\  ^__^\n");
    printf("   \\ (%s)\\_______\n", yeux);
    printf("     (__)\\       )\\/\\\n");
    printf("      %c  ||----w |\n",langue);
    printf("         ||     ||\n");
}

// Fonction pour lire le fichier caractere par caractere
void lireFichier(FILE* fichier) {
    char caractere;
    char* contenu = (char*)malloc(1); // Allouer de l'espace pour un caractère initial
    *contenu = '\0'; // Initialiser la chaîne vide
    while ((caractere = getc(fichier)) != EOF) {
        affiche_vache("oo", contenu, caractere);

        // Allouer de la mémoire pour un nouveau caractère dans la chaîne contenu
        contenu = (char*)realloc(contenu, strlen(contenu) + 2);
        if (contenu == NULL) {
            perror("Erreur lors de la réallocation de mémoire");
            exit(EXIT_FAILURE);
        }

        //Concaténer le caractere lu a la fin de la chaine
        contenu[strlen(contenu)] = caractere;
        contenu[strlen(contenu) + 1] = '\0'; //teminer la chaine avec un caractère nul

        usleep(1000000); // attendre 1 seconde
        system("clear"); // effacer l'ecran pour afficher le prochain caractère

    }
    affiche_vache("oo",contenu,' ');
    printf("Fin du fichier.\n");
    free(contenu); // liberer la mémoire allouee
}

int main(int argc, char* argv[]) {
    FILE* fichier;
    if (argc == 2) {
        fichier = fopen(argv[1], "r");
        if (fichier == NULL) {
            perror("Erreur lors de l'ouverture du fichier");
            return 1;
        }
    } else if (argc == 1) {
        fichier = stdin; // utiliser l'entree standard
    } else {
        printf("Usage: %s [nom_du_fichier]\n", argv[0]);
        return 1;
    }

    lireFichier(fichier);

    if (argc == 2) {
        fclose(fichier);
    }

    return 0;
}
