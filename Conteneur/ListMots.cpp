//
// Created by ieman on 04/01/2024.
//

#include <cassert>

#include "ListMots.h"
#include <iostream>

void CreerListMots(ListMots& liste, unsigned int capa) {
    liste.capacite = capa;
    liste.mots = new ListCarte[capa];
    liste.taille = 0;
}

void afficher_liste_mots(const ListMots& liste){
    for(unsigned int i = 0 ; i < liste.taille; ++i){
        afficher_liste_carte(liste.mots[i]);
    }
}


void DetruireListMots(ListMots& listMots) {
    for(unsigned int i = 0; i < listMots.taille; ++i){
        ListCarte mot = MotRef(listMots, i);
        detruire(mot);
    }
    delete[] listMots.mots;
}
unsigned int TailleList(const ListMots &listMots) {
    return listMots.taille;
}
ListCarte& MotRef(const ListMots& listMots, unsigned int index){
    assert(index < TailleList(listMots));
    return listMots.mots[index];
}

void ModifierMot(ListMots &listMots, unsigned int index, const ListCarte &mot) {
    assert(index < TailleList(listMots));

    detruire(listMots.mots[index]);

    listMots.mots[index] = mot;
}

void AjouterListMots(ListMots &listMots, const ListCarte& mot) {
    // Vérifier s'il est nécessaire de réallouer
    if (listMots.taille >= listMots.capacite)
    {
        const ListCarte* old = listMots.mots;

        listMots.capacite = (listMots.capacite + 1) * WORD_LIST_CAPACITY_EXTEND;
        listMots.mots = new ListCarte[listMots.capacite];

        if (old)
        {
            for (size_t i = 0; i < TailleList(listMots); ++i)
                listMots.mots[i] = old[i];

            // Libérer la mémoire qui contenait l'ancien tableau (pas celle qui contient les éléments des listes)
            delete[] old;
        }
    }

    // Ajouter le mot à la fin du tableau
    listMots.mots[listMots.taille] = mot;
    ++listMots.taille;
}


