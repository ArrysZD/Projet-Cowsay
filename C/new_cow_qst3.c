#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void affiche_vache(char* yeux, char* text, bool Tongue, char* langue) { //focntion de base pour afficher la vache avec les option -e et -T
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
        printf("      %c  ||----w |\n",langue[0]);
    }else{
        printf("         ||----w |\n");
    }

    printf("         ||     ||\n");
}

void affiche_taureau(){
printf("                           \n");
printf("               ^__^        (__)\n");
printf("      _______//(♥♥)        (♥♥)\\_______\n");
printf("/\\//(        //(__)        (__)\\       )\\/\\\n");
printf("       | w----||              ||------ |\n");
printf("       ||     ||              ||     ||\n");
printf("         vache        ♥♥        taureau\n");
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
    char* blagues[10] = {
        "Pourquoi les plongeurs plongent-ils toujours en arrière et jamais en avant ? ",
        "Parce que sinon ils tombent dans le bateau.",
        "Quel est le comble pour un électricien ? ",
        "De prendre une châtaigne en travaillant.",
        "Pourquoi les poissons détestent-ils les ordinateurs ? ",
        "Parce qu'ils ont peur du net.",
        "Qu'est-ce qui est jaune et qui attend ? ",
        "Jonathan.",
        "Pourquoi les plongeurs plongent-ils toujours en arrière et jamais en avant ? ",
        "Parce que sinon ils tombent dans le bateau."
    };

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
        } else if (strcmp(argv[i], "-j") == 0 || strcmp(argv[i], "--joke") == 0) {
            char reponse[100];
            affiche_vache(yeux, "veux-tu une blague ? : ", Tongue, langue);
            fflush(stdout);
            scanf("%s", reponse);
            affiche_vache("O-", "j'ai pas compris ?, repete ", Tongue, langue);
            fflush(stdout);
            scanf("%s", reponse);


            if (strcasecmp(reponse, "oui") == 0) {
                random :
                system("clear");
                srand(time(NULL));
                int nombreAleatoire = rand() % 10;
                if (nombreAleatoire % 2 == 0) {

                    affiche_vache(yeux, blagues[nombreAleatoire], Tongue, langue);
                    #ifdef _WIN32
                    Sleep(3000);
                    #else
                    sleep(3);
                    #endif
                    affiche_vache("~~", blagues[nombreAleatoire + 1], true, "U");
                } else {
                    goto random;
                }
            }else if(strcasecmp(reponse, "non") == 0){
                affiche_vache(yeux, "je vous la raconte quand meme \n", Tongue, langue);
                sleep(2);
                goto random;
            }
                goto fin;
        } else if(strcmp(argv[i], "-l") == 0 || strcmp(argv[i], "--love") == 0){

                affiche_taureau();
                goto fin;

        }else {
            text = argv[i];
        }
    }

    if (strcmp(creature, "dragon") == 0) {
        affiche_dragon(text);
    } else if (strcmp(creature, "pony") == 0) {
        affiche_pony(text);
    } else {
        affiche_vache(yeux, text, Tongue, langue);
    }
    fin :
    return 0;
}
