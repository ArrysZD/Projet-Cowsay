#include <stdio.h>
#include <string.h>

// procedure pour afficher une vache avec des yeux personnalises
void affiche_vache(char* yeux) {
    // Vérification de la longueur des yeux fournis
    if (strlen(yeux) != 2) {
        printf("Les yeux doivent être représentés par une chaîne de deux caractères.\n");
        return;
    }


    printf("  \\  ^__^\n");
    printf("   \\ (%s)\\_______\n",  yeux);
    printf("     (__)\\       )\\/\\\n");
    printf("         ||----w |\n");
    printf("         ||     ||\n");
}

// Fonction principale
int main(int argc, char* argv[]) {
    // Vérification des arguments
    if (argc != 3 || (strcmp(argv[1], "-e") != 0 && strcmp(argv[1], "--eyes") != 0)) {
        printf("Utilisation : %s -e <yeux>\n", argv[0]);
        return 1;
    }
    // Récupération des yeux depuis les arguments
    char* yeux = argv[2];

    // Appel de la fonction affiche_vache avec les yeux personnalisés
    affiche_vache(yeux);

    return 0;
}