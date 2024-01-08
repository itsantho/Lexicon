//
// Created by ieman on 26/12/2023.
//

#ifndef LEXICON_CONSTANTE_H
#define LEXICON_CONSTANTE_H

//
// chemin relatif du fichier dictionnaire à utiliser
//

#define DICTIONARY_PATH "ods4.txt"



// Constantes
enum {
    JOUEUR_MIN = 2,
    JOUEUR_MAX = 4,
    NB_CARTES = 51,
    NB_CARTES_UNIQUE = 26,
    NB_CARTES_JOUEUR = 10,
    CAPACITE_LISTE_MOTS = 10,
    TAILLE_MAX_MOT = 15,
    PENALITE = 3,
    SCORE_DEFAITE = 100
};

// Un type carte qui représente un char
typedef char Carte;

#endif //LEXICON_CONSTANTE_H
