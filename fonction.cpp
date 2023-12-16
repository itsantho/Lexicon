#include "fonction.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// implémentation 

void initialiser(Carte* c){
    // i la position de carte dans le paquet de 51, index la lettre, j la quantité
    char lettres[NbrCartesUnique] = { 'A','B','C','D','E','F' ,'G' ,'H' ,'I' ,'J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    unsigned int points[NbrCartesUnique]={10,2,8,6,10,2,4,8,10,6,8,8,8,8,8,8,4,8,8,8,8,8,8,2,4,2};
    unsigned int qte[NbrCartesUnique] = {2,2,2,2,5,1,2,2,4,1,1,2,1,3,2,1,1,3,3,3,3,1,1,1,1,1};
    
    for (unsigned int i = 0, index = 0; i < NbrCartes; ++index) {
        for (unsigned int j = 0; j < qte[index]; ++j, ++i) {
            c[i].lettre = lettres[index];
            c[i].points = points[index];

        }
    }
}

void afficher(Carte *c){
    for(unsigned int i = 0 ; i < NbrCartes; ++i){
        cout << c[i].lettre  << ' ' << c[i].points << endl;
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