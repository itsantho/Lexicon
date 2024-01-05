//
// Created by ieman on 26/12/2023.
//

#ifndef LEXICON_PILES_H
#define LEXICON_PILES_H

#include "ListCarte.h"


struct Pile {
    ListCarte cartes;
};
/*
 * @brief initialise une pile
 * @param[OUT] la pile
 * @param[OUT] capa sa capacité*/
void initialiser(Pile& p, unsigned int capa);
bool estVide(const Pile& p);
void detruire(Pile& p);

Carte sommet(Pile& p);

void empiler(Pile& p, Carte it);
void depiler(Pile& p);


#endif //LEXICON_PILES_H
