#ifndef COMMANDES_H
#define COMMANDES_H

#include "jeu.h"
#include "Conteneur/ListMots.h"

#include <cstring>


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
void cmd_expose(Pile& expose, Joueur& j, ListeDeJoueurs& liste);

/*
 * @brief Poser un mot et retire les lettres de la main du joueur
 * @param[IN,OUT] j le joueur actuel
 * param[IN,OUT] motPose la liste des mots placés sur la table
 * param[IN] dictionnaire des mots valide
 * */
void cmd_poser(Joueur& j, ListeDeMots& motPose, ListeDeJoueurs& listeDeJoueurs);

/*
 * @brief Remplace un mot par un autre en utilisant les lettres du mot remplacé
 * @param[IN,OUT] j le Joueur actuel
 * param[IN,OUT] motPose la liste des mots placés sur la table
 * param[IN] dictionnaire des mots valide
 * */
void cmd_remplacer(Joueur& j, ListeDeMots& motsPose, ListeDeJoueurs& listeDeJoueurs);

/*
 * @brief Complete un mot en ajoutant les cartes du joueur
 * @param[IN,OUT] j le Joueur actuel
 * param[IN,OUT] motPose la liste des mots placés sur la table
 * param[IN] dictionnaire des mots valide
 */
void cmd_completer(Joueur& j, ListeDeMots& motsPose, ListeDeJoueurs& listeDeJoueurs);

#endif
