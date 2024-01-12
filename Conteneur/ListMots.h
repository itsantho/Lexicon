#ifndef LEXICON_LISTMOTS_H
#define LEXICON_LISTMOTS_H

#include "ListCarte.h"

struct ListeDeMots{
    unsigned int taille;
    unsigned int capacite;
    ListeDeCartes *mots;
};
enum
{
    COEF = 2  // facteur d'extension par défaut d'une liste de mot
};
/*
 * @brief Initialise une liste de mots
 * @param[IN] la capacité de la liste
*/

void creer_liste_mots(ListeDeMots& liste, unsigned int capa);

/*
 * @brief Affiche tous les mots posés
 * @param[IN] Liste de mot*/
void afficher_liste_mots(const ListeDeMots& liste);

/*
 * @brief Desalloue les mots de la liste
 * @param[IN, OUT] la liste à désallouer
*/

void detruire_liste_mots(ListeDeMots& listeMots);
/*
 * @brief Retourne le nombre de mots dans la liste
 * @param[in] listeMots La liste
 * @return Le nombre de mots dans la liste
 */
unsigned int TailleListeDeMots(const ListeDeMots& listeMots);

/*
 * @brief Retourne une référence vers un mot de la liste
 * @param[in] listeMots La liste de mot
 * @param[in] index Indice du mot que l'on veut récupérer
 * @return Référence vers le mot à l'indice index
 * @pre index < TailleList(listeMots)
 */
ListeDeCartes& MotRef(const ListeDeMots& listeMots, unsigned int index);

/*
 * @brief Modifie le mot à l'indice donné
 * @param[in, out] listeMots La liste de mot
 * @param[in] index L'indice du mot à modifier
 * @param[in] mot La nouvelle valeur du mot
 * @pre index < TailleListe(wordList)
 */
void modifier_mot(ListeDeMots& listeMots, unsigned int index, const ListeDeCartes& mot);

/*
 * @brief Ajoute un mot dans la liste
 * @param[in, out] listeMots liste dans laquelle ajouter
 * @param[in] mot Le mot à ajouter
 */
void ajouter_mot(ListeDeMots& listeMots, const ListeDeCartes& mot);

#endif //LEXICON_LISTMOTS_
