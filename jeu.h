#ifndef FONCTION_H
#define FONCTION_H
#include "Conteneur/ListCarte.h"
#include "constante.h"
#include "Conteneur/piles.h"
#include "Conteneur/ListMots.h"
#include "Joueurs.h"
#include <cstring>
#include <string>


/*
 * @brief Demande le nombre de joueurs*
 * @return le nombre de joueurs si valide
*/
unsigned int demander_nb_joueurs();

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
 * @brief Distribuer des cartes aux joueurs
 * @param[IN]
 * @param[OUT]
 * @param[OUT]
 * @return le nombre de carte restante
*/
void distribuer(ListCarte& c, ListeDeJoueurs& liste,unsigned int nb_joueur);

/*
 * @brief Affiche le deck du joueur
 * @param[in] Liste de joueur
*/
void afficher_deck(ListeDeJoueurs& liste);

/*
 * @brief Affiche les commandes disponibles
 * @param[in] Commandes
 */
void afficher_commandes();

/*
 * @brief Vérifie si le tour est fini
 * param[IN] Liste dee joueurs
 * @return True ou False
 * */
bool TourGagne(ListeDeJoueurs& liste);


/*
 * @brief Commande Talon
 * @param[out] pile de talon
 * @param[out] pile de talon
 * @param[out] les cartes du joueurs
 * @param[out] la liste des joueurs
 * @param[IN] lettre
 * */
void cmd_talon(Pile& tal, Pile& expose, Joueur& j, ListeDeJoueurs& liste);

/*
 * @brief Remplace la carte au sommet par la carte du joueur
 * @param[OUT] expose
 * param[OUT] la carte*/
void cmd_expose(Pile& expose, Joueur&j,ListeDeJoueurs& liste);

/*
 * @brief Poser un mot et retire les lettres de la main du joueur
 * @param[IN,OUT] j le joueur actuelle
 * param[IN,OUT] motPose la liste des mots placés sur la table
 * param[IN] dictionnaire des mots valide
 * */
void cmd_poser(Joueur& j, ListMots& motPose, ListeDeJoueurs& liste);

/*
 * @brief Remplace un mot par un autre en utilisant les lettres du mot remplacé
 * @param[IN,OUT] j le Joueur actuel
 * param[IN,OUT] motPose la liste des mots placés sur la table
 * param[IN] dictionnaire des mots valide
 * */
void remplacer(Joueur& j, ListMots& motsPose, const ListMots& dictionnaire);

/*
 * @brief Complete un mot en ajoutant les cartes du joueurs
 * @param[IN,OUT] j le Joueur actuel
 * param[IN,OUT] motPose la liste des mots placés sur la table
 * param[IN] dictionnaire des mots valide
 */

void completer(Joueur& j, ListMots& motsPose, const ListMots& dictionnaire);

/*
 * @brief Verifie qu'un mot est bien présent dans le dictionnaire
 * @param[IN] Le mot
 * @param[IN] Le dictionnaire
 * @return True ou False
 *
 */
/*
 * @brief Vérifie si un mot se trouve dans le dictionnaire
 * param[in] Le mot à comparer
 * param[in] Le dictionnaire*/
bool motDansDictionnaire(const std::string& mot, const std::string& fichierDictionnaire);



#endif // FONCTION_H