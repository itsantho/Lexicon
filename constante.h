//
// Created by ieman on 26/12/2023.
//

#ifndef LEXICON_CONSTANTE_H
#define LEXICON_CONSTANTE_H

//
// chemin relatif du fichier dictionnaire à utiliser
//
#define DICTIONARY_PATH "ods4.txt"

//
// Récupère la position (à partir de 0) d'une lettre dans l'alphabet
// 'A' -> 0
// 'B' -> 1
// ...
// 'Y' -> 24
// 'Z' -> 25
//
#define CARD_NO(c) ((c) - 'A')

//
// Récupère la valeur correspondant à une position (à partir de 0) dans l'alphabet
// 0 -> 'A'
// 1 -> 'B'
// ...
// 24 -> 'Y'
// 25 -> 'Z'
//
#define CARD_VALUE(cardNo) ((cardNo) + 'A')

// Constantes
enum {

    JOUEUR_MIN = 2,
    JOUEUR_MAX = 4,

    NbrCartes = 51,
    NbrCartesUnique = 26,
    NbrCarteParJoueur = 10,

    MaxLettreMot = 60,
    NbJoueurMax = 4,

    NB_MOTS_DICTIONNAIRE= 369085,
    TAILLE_MAX_MOT = 15,

    PENALITE = 3,

    SCORE_DEFAITE = 101
};

// Un type carte qui représente un char
typedef char Carte;



#endif //LEXICON_CONSTANTE_H
