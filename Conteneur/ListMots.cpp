#include "ListMots.h"
#include <cassert>
#include <iostream>

using namespace std;

void creer_liste_mots(ListeDeMots& liste, unsigned int capa) {
    liste.capacite = capa;
    liste.mots = new ListeDeCartes[capa];
    liste.taille = 0;
}

void afficher_liste_mots(const ListeDeMots& liste){
    for(unsigned int i = 0 ; i < liste.taille; ++i){
        cout << i+1 << " - ";
        afficher_liste_carte(liste.mots[i]);
    }
}


void detruire_liste_mots(ListeDeMots& listeMots) {
    for(unsigned int i = 0; i < listeMots.taille; ++i){
        ListeDeCartes mot = MotRef(listeMots, i);
        detruire_liste_carte(mot);
    }
    delete[] listeMots.mots;
}

unsigned int TailleListeDeMots(const ListeDeMots &listeMots) {
    return listeMots.taille;
}
ListeDeCartes& MotRef(const ListeDeMots& listeMots, unsigned int index){
    assert(index < TailleListeDeMots(listeMots));
    return listeMots.mots[index];
}

void modifier_mot(ListeDeMots &listeMots, unsigned int index, const ListeDeCartes &mot) {
    assert(index < TailleListeDeMots(listeMots));

    detruire_liste_carte(listeMots.mots[index]);

    listeMots.mots[index] = mot;
}

void ajouter_mot(ListeDeMots &listeMots, const ListeDeCartes& mot) {
    // Vérifier s'il est nécessaire de réallouer
    if (listeMots.taille >= listeMots.capacite)
    {
        const ListeDeCartes* old = listeMots.mots;

        listeMots.capacite = (listeMots.capacite + 1) * WORD_LIST_CAPACITY_EXTEND;
        listeMots.mots = new ListeDeCartes[listeMots.capacite];

        if (old)
        {
            for (size_t i = 0; i < TailleListeDeMots(listeMots); ++i)
                listeMots.mots[i] = old[i];

            // Libérer la mémoire qui contenait l'ancien tableau (pas celle qui contient les éléments des listes)
            delete[] old;
        }
    }

    // Ajouter le mot à la fin du tableau
    listeMots.mots[listeMots.taille] = mot;
    ++listeMots.taille;
}


