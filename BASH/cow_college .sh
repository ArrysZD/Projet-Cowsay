#!/bin/bash
#La suite de Fibonacci est une suite d'entiers dans laquelle chaque terme est la somme des deux termes précédents.
if [ $# -eq 0 ]; then
    echo "Usage: $0 <nombre>"
    exit 1
fi

if [ $1 -eq 0 ] || [ $1 -eq 1 ]; then
cowsay  $1
sleep 1
clear
else
U1=0
Usuiv=1
while [ $usuiv -le $1 ]; do
	uf=$((usuiv + u1))  # calcule le prochain terme de la suite
	cowsay $usuiv  # affiche le terme actuel avec cowsay
	u1=$usuiv  # met à jour le premier terme pour le prochain calcul
	usuiv=$uf  # met à jour le deuxième terme pour le prochain calcul
	sleep 1
	clear
done
fi
