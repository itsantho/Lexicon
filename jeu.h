#ifndef FONCTION_H
#define FONCTION_H
#include "Conteneur/ListCarte.h"
#include "constante.h"
#include "Conteneur/piles.h"
#include "Conteneur/ListMots.h"


//Structure Joueur
struct Joueur {
    unsigned int score = 0;
    ListCarte carte_possede;
};

// Pointeurs pour les mots de la table
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
 * @param[IN,OUT] j le joueur actuelle
 * param[IN,OUT] motPose la liste des mots placés sur la table
 * param[IN] dictionnaire des mots valide
 * */
void poser(Joueur& j, ListMots& motPose, const ListMots& dictionnaire);

/*
 * @brief Remplace un mot par un autre en utilisant les lettres du mot remplacé
 * @param[IN,OUT] j le Joueur actuel
 * param[IN,OUT] motPose la liste des mots placés sur la table
 * param[IN] dictionnaire des mots valide
 * */
void remplacer(Joueur& j, ListMots& motsPose, const ListMots dictionnaire);

/*
 * @brief Complete un mot en ajoutant les cartes du joueurs
 * @param[IN,OUT] j le Joueur actuel
 * param[IN,OUT] motPose la liste des mots placés sur la table
 * param[IN] dictionnaire des mots valide
 */

void completer(Joueur& j, ListMots& motsPose, const ListMots dictionnaire);

#endif // FONCTION_H