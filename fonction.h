#ifndef FONCTION_H
#define FONCTION_H


// Constantes
enum {
    NbrCartes = 51,
    NbrCartesUnique = 26,
    NbrCarteParJoueur = 10
};

// Structure pour représenter une carte
struct Carte {
    char lettre;
    unsigned int quantite;
    unsigned int points;
};
struct Joueur {
    unsigned int carte_restante;
    unsigned int score;
    char carte_possede[NbrCarteParJoueur];
};


/*
 *@brief affichee un paquet de carte
 *@param[IN] tableau de type Carte
*/
void afficher(Carte *c);

/*
 *@brief initialisee un paquet de carte
 *@param[OUT] tableau de type Carte
*/
void initialiser(Carte* c);

/*
 *@brief mélanger un paquet de carte
 *@param[OUT] tableau de type Carte
*/
void melanger_paquet(Carte* c);



#endif // FONCTION_H