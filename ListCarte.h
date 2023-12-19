//
// Created by Anthony on 19/12/2023.
//

#ifndef LEXICON_LISTCARTE_H
#define LEXICON_LISTCARTE_H


#include "fonction.h"



//
//

struct ListCarte {
    Carte* cartes; // correspond à une liste de carte
    unsigned int taille; // taille de la liste
    unsigned int capacite;
};

/*
 * @brief initialise une liste de carte
 * @param[IN] liste
 *
*/
void initialiser(ListCarte& liste, unsigned int capa);

/*
 * @brief ajouter une carte de la liste
 * @param[OUT] liste
 * @param[IN] Carte
*/
void ajouter(ListCarte& liste, Carte carte);

/*
 * @brief ajouter une carte de la liste
 * @param[OUT] liste
 * @param[IN] indice
 * @param[OUT] Carte
*/
void modifier(ListCarte& liste, unsigned int index,Carte carte);

/*
 * @brief retire une carte de la liste
 * @param[OUT] liste
 * @param[IN] Carte
*/
void retirer(ListCarte& liste, Carte carte);

/*
 * @brief Lire un carte dans la liste
 * @param[IN] liste
 * @param[IN] indice
*/
Carte lire(const ListCarte& liste, unsigned int index);

/*
 * @brief détruit une liste
 * param[IN] liste
*/
void detruire(ListCarte& liste);

#endif //LEXICON_LISTCARTE_H
