#ifndef FONCTION_H
#define FONCTION_H
#include "ListCarte.h"
#include "constante.h"
#include "piles.h"


//Structure Joueur
struct Joueur {
    unsigned int score = 0;
    ListCarte carte_possede;
};

ListCarte* mots;

/*
 * @brief afficher_cartes un paquet de carte
 * @param[IN] tableau de type Carte
 * @param[IN] Nombre de carte restante dans le paquet
*/
void afficher_cartes(const ListCarte& c);

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

/*
 * @brief Affiche les commandes disponibles
 * @param[in] Commandes
 */
void afficher_commandes();

/*
 * @brief Commande Talon
 * @param[out] pile
 * param[IN] lettre
 * */
void talon(Pile &talon, Pile& expose, Joueur& j);

/*
 * @brief Remplace la carte au sommet par la carte du joueur
 * @param[OUT] expose
 * param[OUT] la carte*/
void expose(Pile& expose, Joueur&j);

/*
 * @brief Poser un mot et retire les lettres de la main du joueur
 * @param[OUT] les cartes joueurs
 * */
void poser(Joueur& j, ListCarte m[10]);

#endif // FONCTION_H