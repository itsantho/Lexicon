#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include "fonction.h"

using namespace std;

int main(int argc, char* argv[]) {
    unsigned int nb_carte_paquet = NbrCartes;
    Carte cartes[NbrCartes];

    Joueur joueurs[4];
    initialiser(cartes);
    afficher(cartes, nb_carte_paquet);
    cout << endl;
    melanger_paquet(cartes);
    afficher(cartes, nb_carte_paquet);
    nb_carte_paquet = distribuer(cartes, joueurs, 4);
    cout << endl;
    afficher(cartes, nb_carte_paquet);
    afficher_deck(joueurs[0]);
    return 0;
}


