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
