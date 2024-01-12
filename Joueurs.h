#ifndef LEXICON_JOUEURS_H
#define LEXICON_JOUEURS_H
#include "Conteneur/ListCarte.h"

//Structure Joueur
struct Joueur {
    // Score qui change chaque tour et points de pénalité
    unsigned int scores;
    // Deck du joueur
    ListeDeCartes carte_possede;

    // Etat du joueur true = actif et false = éliminer
    bool actif;

};
/*
 * Structure représentant la liste des joueurs du jeu, actifs ou éliminés
 */
struct ListeDeJoueurs
{
    // Pointeurs vers les joueurs du jeu
    Joueur* joueurs;

    // Le nombre de joueurs dans la liste, JOUEUR_MIN <= nb_joueur <= JOUEUR_MAX
    unsigned int nb_joueurs;

    // Le nombre de joueurs actif
    unsigned int nb_joueurs_actifs;
    // L'indice dans la liste du joueur actuel, 0 <= indiceJoueurActuel < nb_joueur
    unsigned int indiceJoueurActuel;
};


/*
 * @brief Créer la liste des joueurs de Lexicon
 * @param[in] playerCount Le nombre de joueur
 * @return La liste des joueurs, aucun n'a de carte ou de points de pénalité
 * @pre JOUEUR_MIN <= nb_joueurs <= JOUEUR_MAX
 */
ListeDeJoueurs initialiserlistejoueur(unsigned int nb_joueurs);

/*
 * @brief Désalloue la liste de joueurs alloués par ListeDeJoueurs
 * @param[in, out] joueurs La liste des joueurs à désallouer
 * @note La fonction désalloue aussi les listes de carte des joueurs
 */
void detruireListeJoueur(ListeDeJoueurs& joueurs);

Joueur& joueur_actuel(const ListeDeJoueurs& joueurs);

/*
 * @brief Passe au joueur suivant
 * @param[OUT] liste de joueurs*/
void joueur_suivant(ListeDeJoueurs& liste);

/*
 * @brief Ajoute 3 points de pénalité à un joueur (lorsqu'il forme un mot invalide)
 * @param[in, out] Le joueur qui reçoit des points de pénalité
 */
void penaliser(Joueur& joueur);

/*
 * @brief Calcul le score d'un joueur à la fin d'un tour, c'est-à-dire la somme des points de ses cartes restantes
 * @param[in]
 * Le joueur dont le score est calculé
 * @return Le score du joueur
 * @note La fonction doit être appelée à la fin d'un tour
 */
void scorejoueur(Joueur& joueur);

/*
 * @brief Détermine un joueur a gagné
 * @param[in] La liste des joueurs
 * @return true si le joueur a gagné le tour, false sinon
 * 
 */
bool fin_tour(const ListeDeJoueurs& joueurs);

#endif //LEXICON_JOUEURS_H
