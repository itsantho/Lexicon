//
// Created by Anthony on 19/12/2023.
//
#include "ListCarte.h"
#include <cassert>

void initialiser(ListCarte& liste, unsigned int capa){
    liste.capacite = capa;
    liste.cartes = new Carte[capa];
    liste.taille = 0;
}

void ajouter(ListCarte &liste, Carte carte) {

    if(liste.taille >= liste.capacite) {
        Carte* nouveau = new Carte[liste.capacite*2];
        for(unsigned int i = 0; i < liste.taille; ++i){
            nouveau[i]= liste.cartes[i];

        }
        delete[] liste.cartes;
        liste.cartes = nouveau;
        liste.capacite *=2;
    }
    liste.cartes[liste.taille] = carte;
    ++liste.taille;
}

void modifier(ListCarte &liste, unsigned int index, Carte carte) {
    assert(index < liste.taille);
    liste.cartes[index] = carte;
}

Carte lire(const ListCarte &liste, unsigned int index) {
    assert(index < liste.taille);
    return liste.cartes[index];
}

void retirer(ListCarte &liste, Carte carte) {
// (A, B, C, D, E, F)
// (A, B, D, E, F)

    for (unsigned int i = 0;  i < liste.taille  ; ++i) {
        if (liste.cartes[i] == carte){
            for(; i < liste.taille-1 ; ++i)
                liste.cartes[i] = liste.cartes[i+1];
        }
    }
    --liste.taille;
}

void detruire(ListCarte &liste) {
    delete[] liste.cartes;
}


bool contient(ListCarte &cartes, Carte carte) {

    for (unsigned int i = 0; i < cartes.taille; ++i)
    {
        if (cartes.cartes[i] == carte)
            return true;
    }

    return false;
}
