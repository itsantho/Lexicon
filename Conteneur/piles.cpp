//
// Created by ieman on 26/12/2023.
#include "piles.h"
#include "ListCarte.h"
#include <cassert>

void pileDeCartes(Pile& p, const ListCarte& listeDeCarte) {
    p.cartes = listeDeCarte;
}

Pile initialiser_pile(unsigned int capa_initiale){
    Pile p {
        .cartes = initialiser_liste_carte(capa_initiale)
    };
    return p;
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

Carte depiler(Pile& p)
{
    assert(!estVide(p));
    return retirer_derniere_cartes(p.cartes);
}