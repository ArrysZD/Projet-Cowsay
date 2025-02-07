#!/bin/bash

# boucle de 1 à 10
for i in {1..10}
do
    clear  # efface l'ecran
    cowsay "$i"  # Affiche le nombre actuel dans une bulle de texte avec cowsay
    sleep 1  # Pause d'une seconde
done

clear  # Efface l'écran
cowsay -T "U" " "  # Affiche une vache ASCII avec le texte "U"
