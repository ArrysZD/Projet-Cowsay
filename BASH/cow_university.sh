#!/bin/bash

# Validation des arguments
if [ $# -eq 0 ]; then
    echo "manque arguement: $0 <arg : nombre>"  # Affiche un message d'erreur si aucun argument n'est fourni
    exit 1  # Quitte le script avec un code d'erreur
fi

n=$1  # Stocke le premier argument dans la variable n
i=2  # Initialise le compteur à 2

while [ $i -le $n ]; do
    if [ $((n % 2)) -ne 0 ] || [ $((n % 3)) -ne 0 ]; then  # Vérifie si n n'est pas divisible par 2 ou 3
        cowsay $i  # Affiche le nombre actuel avec cowsay
        sleep 1  # Pause d'une seconde
        clear  # Efface l'écran
    else
        if [ $((n % i)) -ne 0 ]; then  # Vérifie si n n'est pas divisible par i
            cowsay $i  # Affiche le nombre actuel avec cowsay
            sleep 1  # Pause d'une seconde
            clear  # Efface l'écran
        fi
    fi
    i=$((i + 1))  # Incrémente le compteur
done
