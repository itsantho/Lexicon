#ifndef LEXICON_PILES_H
#define LEXICON_PILES_H

#include "ListCarte.h"


struct Pile {
    ListeDeCartes cartes;
};
/*
 * @brief Créer une Pile de carte avec une liste de cartes
 * @param[OUT] la pile
 * @param[in] Liste de carte*/
void pileDeCartes(Pile& p, const ListeDeCartes& listeDeCarte);
/*
 * @brief initialise une pile de carte
 * @param[in] capacité initial à 0
 * */
Pile initialiser_pile(unsigned int capa_initiale = 0);

bool estVide(const Pile& p);
void detruire_pile(Pile& p);

Carte sommet(Pile& p);

void empiler(Pile& p, Carte it);
Carte depiler(Pile& p);


#endif //LEXICON_PILES_H
