//
// Created by ieman on 04/01/2024.
//

#ifndef LEXICON_LISTMOTS_H
#define LEXICON_LISTMOTS_H

#include "ListCarte.h"

struct ListMots{
    unsigned int taille;
    unsigned int capacite;
    ListCarte *mots;
};
enum
{
    WORD_LIST_CAPACITY_EXTEND = 2  // facteur d'extension par défaut d'une liste de mot
};
/*
 * @brief Initialise une liste de mots
 * @param[IN] la capacité de la liste
*/

void CreerListMots(ListMots& liste, unsigned int capa);

/*
 * @brief Affiche tout les mots posé
 * @param[IN] Liste de mot*/
void afficher_liste_mots(const ListMots& liste);

/*
 * @brief Desalloue les mots de la liste
 * @param[IN, OUT] la liste a désallouer
*/

void DetruireListMots(ListMots& listMots);
/*
 * @brief Retourne le nombre de mot dans la liste
 * @param[in] listMots La liste
 * @return Le nombre de mot dans la liste
 */
unsigned int TailleList(const ListMots& listMots);

/*
 * @brief Retourne une référence vers un mot de la liste
 * @param[in] listMots La liste de mot
 * @param[in] index Indice du mot que l'on veut récupérer
 * @return Référence vers le mot à l'indice index
 * @pre index < ListSize(listMots)
 */
ListCarte& MotRef(const ListMots& listMots, unsigned int index);

/*
 * @brief Modifie la valeur le mot à l'indice donné
 * @param[in, out] listMots La liste de mot
 * @param[in] index L'indice du mot à modifié
 * @param[in] mot La nouvelle valeur du mot
 * @pre index < ListTaille(wordList)
 */
void ModifierMot(ListMots& listMots, unsigned int index, const ListCarte& moy);

/*
 * @brief Ajoute un mot dans la liste
 * @param[in, out] listMots liste dans laquelle ajouter
 * @param[in] mot Le mot à ajouter
 */
void AjouterListMots(ListMots& listMots, const ListCarte& mot);

#endif //LEXICON_LISTMOTS_
