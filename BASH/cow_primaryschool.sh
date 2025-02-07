#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Usage: $0 <nombre>"
    exit 1
fi

n=$1

for ((i=1; i<=$n; i++))
do
    clear
    cowsay " $i"
    sleep 1
done

clear
cowsay -d " "

