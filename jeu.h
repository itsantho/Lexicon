#ifndef JEU_H
#define JEU_H
#include "Conteneur/piles.h"
#include "Joueurs.h"



/*
 * @brief Demande le nombre de joueurs*
 * @return le nombre de joueurs si valide
*/
unsigned int demander_nb_joueurs();

/*
 * @brief afficher_cartes un paquet de carte
 * @param[IN] tableau de type Carte
 * @param[IN] Nombre de cartes restantes dans le paquet
*/
void afficher_cartes(const ListeDeCartes& c);

/*
 *@ brief initialiser_paquet un paquet de carte
 *@ param[OUT] tableau de type Carte
*/
void initialiser_paquet(ListeDeCartes& c);

/*
 * @brief mélanger un paquet de carte
 * @param[OUT] tableau de type Carte
*/
void melanger_paquet(ListeDeCartes& c);

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
 * @return le nombre de cartes restante
*/
void distribuer(ListeDeCartes& c, ListeDeJoueurs& liste,unsigned int nb_joueur);


/*
 * @brief Affiche le joueur, la carte exposee et le deck du joueur
 * @param[in] Liste de joueur
 * param[in] Pile
*/
void affichage(ListeDeJoueurs& liste, Pile& p);

/*
 * @brief Affiche les commandes disponibles
 * @param[in] Commandes
 */
void afficher_commandes();

/*
 * @brief Vérifie qu'un mot est bien présent dans le dictionnaire
 * @param[IN] Le mot
 * @param[IN] Le dictionnaire
 * @return True ou False
 */

bool motdansdictionnaire(const ListeDeCartes& mot);

bool comparaison(const ListeDeCartes& mot1, const char* mot2);


/*
 * @brief affiche le score des joueurs
 * @param[in] La liste des joueurs
 * */
void afficher_score(ListeDeJoueurs& listeDeJoueurs);

bool liste_carte_diff(ListeDeCartes& a, ListeDeCartes& b);

#endif // JEU_H