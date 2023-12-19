#include "fonction.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

// implémentation 

void initialiser_paquet(ListCarte& c){
    // i la position de carte dans le paquet de 51, index la lettre, j la quantité
    initialiser(c, NbrCartes);
    unsigned int qte[NbrCartesUnique] = {2,2,2,2,5,1,2,2,4,1,1,2,1,3,2,1,1,3,3,3,3,1,1,1,1,1};
    for (unsigned int i = 0; i < NbrCartesUnique; ++i) {
        for (unsigned int j = 0; j < qte[i]; ++j) {
            ajouter(c, 'A' + i);
        }
    }
}

void afficher(const ListCarte& c){
    for(unsigned int i = 0 ; i < c.taille; ++i){
        cout << lire(c, i) << endl;
    }
}

void melanger_paquet(Carte* c) {
    srand(time(nullptr));

    for (size_t i = 0; i < NbrCartes; ++i)
    {
        const size_t j = rand() % NbrCartes;
        Carte tmp = c[i];
        c[i] = c[j];
        c[j] = tmp;
    }
}

void donner_une_carte(Joueur& j, Carte c) {
    assert(j.carte_restante < NbrCarteParJoueur);
    j.carte_possede[j.carte_restante] = c;
    ++j.carte_restante;
}

void distribuer(ListCarte& c, Joueur* joueurs, unsigned int nb_joueur) {
    for (unsigned int i = 0; i < nb_joueur; ++i) {
        for (unsigned int j = 0; j < NbrCarteParJoueur; ++j) {
            donner_une_carte(joueurs[i], lire(c,c.taille-1));
            --c.taille;
        }
    }
}

void afficher_deck(Joueur& joueur) {
    for (unsigned int i = 0; i < NbrCarteParJoueur; ++i) {
        cout << joueur.carte_possede[i];
    }
}

