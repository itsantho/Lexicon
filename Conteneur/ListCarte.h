//
// Created by Anthony on 19/12/2023.
//

#ifndef LEXICON_LISTCARTE_H
#define LEXICON_LISTCARTE_H


#include "../constante.h"


//
//
enum
{
    CARD_LIST_CAPACITY_EXTEND = 2  // Facteur d'extension par défaut d'une liste de carte
};
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
ListCarte initialiser_liste_carte(unsigned int capa);

/*
 * @brief ajouter une carte à une la liste
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
void modifier(ListCarte& liste, unsigned int index, Carte carte);

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

/*
 * @brief Vérifie que la carte se trouve dans la main du joueurs
 * param[in] La liste de carte du joueur
 * param[in] La carte à poser*/
bool contient(const ListCarte& cartes, Carte carte);

/*
 * @brief affiche le mot que forme les cartes
 * param[in] Liste de carte*/
void afficher_liste_carte(const ListCarte& cartes);

#endif //LEXICON_LISTCARTE_H
