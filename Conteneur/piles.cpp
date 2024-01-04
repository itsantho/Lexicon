//
// Created by ieman on 26/12/2023.
#include "piles.h"
#include "ListCarte.h"

void initialiser(Pile &p, unsigned int capa) {
    initialiser(p.cartes, capa);
}

bool estVide(const Pile& p)
{
    return p.cartes.taille == 0;
}

void detruire(Pile& p)
{
    detruire(p.cartes);
}

Carte sommet(Pile& p)
{
    return lire(p.cartes, p.cartes.taille - 1);
}

void empiler(Pile& p, Carte it)
{
    ajouter(p.cartes, it);
}

void depiler(Pile& p)
{
    --p.cartes.taille;
}