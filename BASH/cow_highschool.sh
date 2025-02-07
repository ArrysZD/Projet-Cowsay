#!/bin/bash

# Vérifie s'il y a des arguments en entrée
if [ $# -eq 0 ]; then
    echo "attendu : $0 <arg : nombre>"  # Affiche un message d'utilisation si aucun argument n'est fourni
    exit 1  # Quitte le script avec un code d'erreur
fi

n=$1  # Stocke le premier argument dans la variable n

# Boucle de 1 à n
for ((i=1; i<=$n; i++))
do
    clear  # Efface l'écran
    x=$((i*i))  # Calcule le carré de i et le stocke dans x
    cowsay "le carré de $i est $x"  # Affiche le carré de i avec cowsay
    sleep 1  # Pause d'une seconde
done

clear  # Efface l'écran
cowsay -d " "  # Affiche une vache ASCII avec un texte vide
