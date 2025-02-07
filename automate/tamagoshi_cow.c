#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

/*
int fitness = 5;
int stock = 5;
Initialisation des variables globales dans la fonction main parce qu'en rajoutant ma fonction event_danger, le programme ne fonctionne pas.
*/

void affiche_vache(int etat_sante) {
    switch (etat_sante) {
        case 0: /* byebyelife */
            printf("^--^\n");
            printf("(XX)\\_______\n");
            printf("(__)\\       )\\/\\\n");
            printf(" U  ||----w |\n");
            printf("    ||     ||\n");
            break;
        case 1: /* lifesucks */
            printf("^--^\n");
            printf("(**)\\_______\n");
            printf("(__)\\       )\\/\\\n");
            printf("    ||----w |\n");
            printf("    ||     ||\n");
            break;
        case 2: /* liferocks */
            printf("^--^\n");
            printf("(00)\\_______\n");
            printf("(__)\\       )\\/\\\n");
            printf("    ||----w |\n");
            printf("    ||     ||\n");
            break;
        default:
            printf("Etat incorrect\n");
    }
}

int stock_update(int lunchfood, int crop, int stock){
    stock = stock - lunchfood + crop; /* Calcul du stock */
    if (stock > 10){ /* Ajustement de fitness pour que la variable soit comprise entre 0 et 10 */
        stock = 10;
    }
    if (stock < 0){
        stock = 0;
    }
    return stock;
}

int fitness_update(int lunchfood, int digestion, int fitness){
    fitness = fitness + lunchfood - digestion; /* Calcul de fitness après digestion */
    if (fitness > 10){ /* Ajustement de fitness pour que la variable soit comprise entre 0 et 10 */
        fitness = 10;
    }
    if (fitness < 0){
        fitness = 0;
    }
    return fitness;
}

int event_insecte(int danger, int fitness){
    if (danger > 9 && danger < 13){ /* Simulation du danger eventuel (probabilité de 7/16) */
        printf("Un moustique-tigre apparait et pique la vache!!! (-1 point de vie)\n");
        fitness = fitness - 1;
    } else if (danger > 12 && danger < 16){
        printf("Un bélier apparait et heurte la vache sur son chemin!!! (-2 point de vie)\n");
        fitness = fitness - 2;
    } else if (danger == 16) {
        printf("UN LOUP APPARAIT ET MORD LA VACHE!!! (-3 point de vie, spoil : c'est le dernier jour pour ta vache)\n");
        fitness = fitness - 3;
    }

    if (fitness > 10){ /* Ajustement de fitness pour que la variable soit comprise entre 0 et 10 */
        fitness = 10;
    }
    if (fitness < 0){
        fitness = 0;
    }
    return fitness;
}


int main(){
    srand(time(NULL));
    int etat_sante = 2;
    int duree_vie = 0;
    int fitness = 5;
    int stock = 5;
    while (etat_sante != 0) { /* Simulation des jours jusqu'à que la vache soit morte */
        affiche_vache(etat_sante);
        printf("Il vous reste %d sacs de nourritures dans votre stock\n", stock);
        int lunchfood;
        printf("Combien de sacs de nourritures voulez vous donner à la vache aujourd'hui ?\n");
        scanf("%d", &lunchfood);

        while (lunchfood > stock || lunchfood < 0) {
            printf("Vous n'avez pas choisi un nombre de sacs possible, recommencez\n");
            printf("Combien de sacs de nourritures voulez vous donner à la vache aujourd'hui ?\n");
            scanf("%d", &lunchfood);
        }

        int digestion = rand() % 4;
        int facteur = rand() % 2;
        int crop = rand() % 4;
        int danger = rand() % 17;
        if (facteur == 0){ /* Permet à la variable crop d'etre comprise entre -3 et 3 (proba de 1/2 pour que ça soit négatif ou positif) */
            crop = crop * (-1);
        }

        fitness = event_insecte(danger,fitness);
        fitness = fitness_update(lunchfood, digestion, fitness);
        stock = stock_update(lunchfood, crop, stock);
        duree_vie++;
        if ((fitness > 3) && (fitness < 7)) {
            etat_sante = 2;
        } else if (fitness == 0) {
            etat_sante = 0;
        } else {
            etat_sante = 1;
        }
        sleep(2);
    }
    affiche_vache(etat_sante);
    printf("Votre vache est décédée, vous avez réussi à élever votre vache pendant %d jours!!!\n", duree_vie);

    return 0;
}