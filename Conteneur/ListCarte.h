#ifndef LEXICON_LISTCARTE_H
#define LEXICON_LISTCARTE_H


#include "../constante.h"

enum
{
    CARD_LIST_CAPACITY_EXTEND = 2  // Facteur d'extension par défaut d'une liste de carte
};
struct ListeDeCartes {
    Carte* cartes; // correspond à une liste de carte
    unsigned int taille; // taille de la liste
    unsigned int capacite;
};

/*
 * @brief initialise une liste de carte
 * @param[IN] liste
 *
*/
ListeDeCartes initialiser_liste_carte(unsigned int capa);

/*
 * @brief ajouter une carte à une liste
 * @param[OUT] liste
 * @param[IN] Carte
*/
void ajouter(ListeDeCartes& liste, Carte carte);

/*
 * @brief modifier une carte de la liste à une position précise
 * @param[OUT] liste
 * @param[IN] l'indice de la carte
 * @param[OUT] Carte
*/
void modifier(ListeDeCartes& liste, unsigned int index, Carte carte);

/*
 * @brief retire une carte de la liste
 * @param[OUT] liste de carte
 * @param[IN] Carte à retirer
*/
void retirer(ListeDeCartes& liste, Carte carte);

/*
 * @brief Lire une carte dans la liste
 * @param[IN] liste de carte
 * @param[IN] l'indice de la carte
*/
Carte lire(const ListeDeCartes& liste, unsigned int index);

/*
 * @brief détruit une liste
 * param[IN] liste
*/
void detruire_liste_carte(ListeDeCartes& liste);

/*
 * @brief Vérifie que la carte se trouve dans la main du joueur
 * param[in] La liste de carte du joueur
 * param[in] La carte à cmd_poser*/
bool contient(const ListeDeCartes& cartes, Carte carte);

/*
 * @brief affiche le mot que forme les cartes
 * param[in] Liste de carte*/
void afficher_liste_carte(const ListeDeCartes& cartes);
/*
 * @brief Retire la dernière carte (sommet)
 * param[out] La carte*/
Carte retirer_derniere_cartes(ListeDeCartes& cardList);

#endif //LEXICON_LISTCARTE_H
