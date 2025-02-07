#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h> // Pour utiliser la fonction strcmp

void affiche_vache(char* yeux, char* text, bool Tongue, char* langue) {
    if (strlen(yeux) != 2) {
        printf("Les yeux doivent être représentés par une chaîne de deux caractères.\n");
        return;
    }
    if (strlen(text) > 0) {
        printf("%s\n", text);
    }
    printf("  \\  ^__^\n");
    printf("   \\ (%s)\\_______\n", yeux);
    printf("     (__)\\       )\\/\\\n");
    if (Tongue == true) {
        printf("      %s", langue);
    }
    printf("         ||----w |\n");
    printf("         ||     ||\n");
}

void affiche_dragon(char *text) {
    if (strlen(text) > 0) {
        printf("%s\n", text);
    }
    printf("   \\                    / \\  //\\\n");
    printf("    \\    |\\___/|      /   \\//  \\\\\n");
    printf("         /0  0  \\__  /    //  | \\ \\           *\n");
    printf("        /     /  \\/_/    //   |  \\  \\         ***\n");
    printf("        @_^_@'/   \\/_   //    |   \\   \\       *****\n");
    printf("        //_^_/     \\/_ //     |    \\    \\     |   |\n");
    printf("     ( //) |        \\///      |     \\     \\   | | | |\n");
    printf("   ( / /) _|_ /   )  //       |      \\     \\_/ | | |_\n");
    printf(" ( // /) '/,_ _ _/  ( ; -.    |    _ _\\.-~       .-~~~^-.\n");
    printf("(( / / )) ,-{        _      `-.|.-~-.           .~         `.\n");
    printf("(( // / ))  '/\\      /                 ~-. _ .-~      .-~^-.  \\ \\\n");
    printf("(( /// ))      `.   {            }                   /      \\  \\ \\\n");
    printf("(( / ))     .----~-\\        \\-'                 .~         \\  `. \\^-.\n");
    printf("           ///.----..>        \\             _ -~             `.  ^-`  ^-_ \\\n");
    printf("             ///-._ _ _ _ _ _ _}^ - - - - ~                   `-,   ^- _ _ _ _ _>\n");
}

void affiche_pony(char *text) {
    if (strlen(text) > 0) {
        printf("%s\n", text);
    }
    printf("       \\          /\\/\\\n");
    printf("        \\         \\/\\/\n");
    printf("         \\        /   -\\\n");
    printf("          \\     /  oo   -\\\n");
    printf("           \\  /           \\\n");
    printf("             |    ---\\    -\\\n");
    printf("             \\--/     \\     \\\n");
    printf("                       |      -\\\n");
    printf("                        \\       -\\\n");
    printf("                         \\        \\-------\n");
    printf("                          -              /--------\\    /-\\\n");
    printf("                           \\+   +---------          \\   |\n");
    printf("                            |   |                   |   \\\n");
    printf("                            |   |                    \\   |\n");
    printf("                            |   |                    |   \\\n");
    printf("                             \\  |                    |   |\n");
    printf("                             |  |                     \\  \\\n");
    printf("                             |  |                      |   |\n");
    printf("                             +--+                      ---+\n");
}

int main(int argc, char* argv[]) {
    char* yeux = "oo";
    char* text = "";
    char* creature = "";
    char* langue = "";
    bool Tongue = false;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--eyes") == 0) {
            if (i + 1 < argc) {
                yeux = argv[i + 1];
                if (i + 2 < argc) {
                    text = argv[i + 2];
                }
            } else {
                printf("Erreur : l'option -e ou --eyes nécessite une chaîne de deux caractères.\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-f") == 0) {
            if (i + 1 < argc) {
                creature = argv[i + 1];

                if (strcmp(creature, "dragon") == 0 || strcmp(creature, "pony") == 0) {
                    if (i + 2 < argc) {
                        text = argv[i + 2];
                    }
                } else {
                    printf("Erreur : L'argument de l'option -f doit être 'dragon' ou 'pony'.\n");
                    return 1;
                }
            } else {
                printf("Erreur : l'option -f nécessite un argument.\n");
                return 1;
            }
        } else if (strcmp(argv[i], "-T") == 0) {
            Tongue = true;
            if (i + 1 < argc) {
                langue = argv[i + 1];
                if (i + 2 < argc) {
                    text = argv[i + 2];
                }
            } else {
                printf("Erreur : l'option -T nécessite une chaîne de caractères pour la langue.\n");
                return 1;
            }
        } else{
            text=argv[i];
        }
    }


    if (strcmp(creature, "dragon") == 0) {
        affiche_dragon(text);
    } else if (strcmp(creature, "pony") == 0) {
        affiche_pony(text);
    } else {
        affiche_vache(yeux, text,Tongue,langue);
    }

    return 0;
}
