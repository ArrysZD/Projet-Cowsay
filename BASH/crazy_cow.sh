#!/bin/bash

echo "Bienvenue dans la Vache Polynomiale!"
echo "Donnez-moi un polynôme pour que je calcule sa dérivée."
echo "Format du polynôme : ax^n + bx^(n-1) + ... + cx^1 + dx^0"

# Demander à l'utilisateur de saisir un polynôme
read -p "Polynôme (ex. 3x^2 + 2x + 1): " polynomial

# Fonction pour calculer la dérivée d'un terme du polynôme
derive_terme() {
    local terme="$1"
    local coefficient=$(echo "$terme" | grep -oE "^-?[0-9]+")
    local exposant=$(echo "$terme" | grep -oE "[0-9]+$")
    local derive=""

    if [[ $exposant -eq 0 ]]; then
        derive=""
    else
        local nouveau_coefficient=$((coefficient * exposant))
        local nouveau_exposant=$((exposant - 1))
        if [[ $nouveau_exposant -eq 0 ]]; then
            derive="$nouveau_coefficient"
        else
            derive="$nouveau_coefficient*x^$nouveau_exposant"
        fi
    fi

    echo "$derive"
}


# Fonction pour calculer la dérivée du polynôme
derive_polynome() {
    local polynomial="$1"
    local derive=""
    local termes=($(echo "$polynomial" | tr '+' ' '))

    for terme in "${termes[@]}"; do
        local derive_terme=$(derive_terme "$terme")
        if [[ -n "$derive_terme" ]]; then
            if [[ -n "$derive" ]]; then
                derive="$derive + $derive_terme"
            else
                derive="$derive_terme"
            fi
        fi
    done

    echo "$derive"
}

# Calculer la dérivée du polynôme fourni par l'utilisateur
derivative=$(derive_polynome "$polynomial")

# Afficher la dérivée
cowsay "La derivee du polynome $polynomial est : $derivative"
