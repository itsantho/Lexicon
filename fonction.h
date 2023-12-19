#ifndef FONCTION_H
#define FONCTION_H
#include "ListCarte.h"

// Constantes
enum {
    NbrCartes = 51,
    NbrCartesUnique = 26,
    NbrCarteParJoueur = 10
};

// Un type carte qui représente un char
typedef char Carte;

//Structure Joueur
struct Joueur {
    unsigned int carte_restante = 0;
    unsigned int score = 0;
    char carte_possede[NbrCarteParJoueur];
};

/*
 * @brief afficher un paquet de carte
 * @param[IN] tableau de type Carte
 * @param[IN] Nombre de carte restante dans le paquet
*/
void afficher(const ListCarte& c);

/*
 *@ brief initialiser_paquet un paquet de carte
 *@ param[OUT] tableau de type Carte
*/
void initialiser_paquet(ListCarte& c);

/*
 * @brief mélanger un paquet de carte
 * @param[OUT] tableau de type Carte
*/
void melanger_paquet(ListCarte& c);

/*
 * @brief Donne une carte à un joueur
 * @param[OUT] Un joueur
 * @param[OUT] une carte
*/
void donner_une_carte(Joueur& j, Carte c);

/*
 * @brief Distribuer des cartes aux joeurs
 * @param[IN]
 * @param[OUT]
 * @param[OUT]
 * @return le nombre de carte restante
*/
void distribuer(ListCarte& c, Joueur* j,unsigned int nb_joueur);

/*
 * @brief Affiche le deck du joueur
 * @param[in] Joueur
*/
void afficher_deck(Joueur& joueur);

#endif // FONCTION_H