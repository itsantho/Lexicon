#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include "fonction.h"
#include "ListCarte.h"

using namespace std;

int main(int argc, char* argv[]) {
    ListCarte cartes;


    Joueur joueurs[4];
    initialiser_paquet(cartes);
    afficher(cartes);
    cout << endl;
    melanger_paquet(cartes);
    afficher(cartes);
    distribuer(cartes, joueurs, 4);
    cout << endl;
    afficher(cartes);
    afficher_deck(joueurs[0]);
    return 0;
}


