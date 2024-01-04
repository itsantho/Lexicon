#include <iostream>
#include "jeu.h"
#include "Conteneur/ListCarte.h"
#include "Conteneur/piles.h"

using namespace std;

int main(int argc, char* argv[]) {


    ListCarte cartes;

    Joueur joueurs[4];

    initialiser_paquet(cartes);
    melanger_paquet(cartes);

    distribuer(cartes, joueurs, 4);

    afficher_commandes();

    Pile talon;
    Pile exposees;
    initialiser(talon, 20);
    initialiser(exposees, 20);

    bool jeu_en_cours = true;

    while (jeu_en_cours){
        cout << '>';

        char c;
        cin >> c;

        if (c == 'T')

    }

    return 0;
}


