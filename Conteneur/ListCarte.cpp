#include "ListCarte.h"
#include <iostream>
#include <cassert>

ListeDeCartes initialiser_liste_carte(unsigned int capa){
    const ListeDeCartes cartes = {
            .cartes = capa ? new Carte[capa]: nullptr,
            .taille = 0,
            .capacite = capa
    };
    return cartes;
}

void ajouter(ListeDeCartes &liste, Carte carte) {
    // Vérifier si on a besoin de réallouer
    if(liste.taille >= liste.capacite) {
        Carte* nouveau = new Carte[liste.capacite*2];
        for(unsigned int i = 0; i < liste.taille; ++i){
            nouveau[i]= liste.cartes[i];

        }
        // Supprime l'ancienne liste de carte
        delete[] liste.cartes;
        liste.cartes = nouveau;
        liste.capacite *=2;
    }
    // Ajoute le mot à la fin du tableau
    liste.cartes[liste.taille] = carte;
    ++liste.taille;
}

void modifier(ListeDeCartes &liste, unsigned int index, Carte carte) {
    assert(index < liste.taille);
    liste.cartes[index] = carte;
}

Carte lire(const ListeDeCartes &liste, unsigned int index) {
    assert(index < liste.taille);
    return liste.cartes[index];
}

void retirer(ListeDeCartes &liste, Carte carte) {
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

void detruire_liste_carte(ListeDeCartes &liste) {
    delete[] liste.cartes;
}


bool contient(const ListeDeCartes &cartes, Carte carte) {

    for (unsigned int i = 0; i < cartes.taille; ++i)
    {
        if (cartes.cartes[i] == carte)
            return true;
    }

    return false;
}

void afficher_liste_carte(const ListeDeCartes& cartes){
    for(unsigned int i = 0; i < cartes.taille; ++i){
        std::cout << lire(cartes,i);
    }

    std::cout << std::endl;
}

Carte retirer_derniere_cartes(ListeDeCartes& listeDecarte)
{
    const Carte sommet = listeDecarte.cartes[listeDecarte.taille - 1];

    --listeDecarte.taille;

    return sommet;
}