#!/bin/bash

# Vérifier si un argument est fourni
if [ $# -eq 0 ]; then
    echo "Veuillez fournir une chaîne d'opération en argument."
    exit 1
fi

# Récupérer la chaîne d'opération depuis le premier argument
operation=$1

# Utiliser l'évaluation arithmétique de Bash pour calculer le résultat
result=$((operation))

# Affichage du résultat

echo " $operation est : $result"
cowsay -e "$result" "$operation"

