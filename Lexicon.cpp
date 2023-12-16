#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include "fonction.h"

using namespace std;






int main(int argc, char* argv[]) {

    Carte carte[NbrCartes];
    Joueur joueur[4];
    initialiser(carte);
    afficher(carte);
    cout << endl;
    melanger_tableau(carte);
    afficher(carte);
    return 0;
}


