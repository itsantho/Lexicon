#ifndef FONCTION_H
#define FONCTION_H


// Constantes
enum {
    NbrCartes = 51,
    NbrCartesUnique = 26,
    NbrCarteParJoueur = 10
};

// Un type carte qui représente un char
typedef char Carte;

//Structure Joueur
struct Joueur {
    unsigned int carte_restante = 0;
    unsigned int score = 0;
    char carte_possede[NbrCarteParJoueur];
};
// Structure sur toutes les cartes
struct ListCarte {
    Carte* cartes;
    unsigned int taille;
};

/*
 * @brief afficher un paquet de carte
 * @param[IN] tableau de type Carte
 * @param[IN] Nombre de carte restante dans le paquet
*/
void afficher(Carte* c, unsigned int nb_carte);

/*
 *@ brief initialiser un paquet de carte
 *@ param[OUT] tableau de type Carte
*/
void initialiser(Carte* c);

/*
 * @brief mélanger un paquet de carte
 * @param[OUT] tableau de type Carte
*/
void melanger_paquet(Carte* c);

/*
 * @brief Donne une carte à un joueur
 * @param[OUT] Un joueur
 * @param[OUT] une carte
*/
void donner_une_carte(Joueur* j, Carte c);

/*
 * @brief Distribuer des cartes aux joeurs
 * @param[IN]
 * @param[OUT]
 * @param[OUT]
 * @return le nombre de carte restante
*/
unsigned int distribuer(Carte* c, Joueur* j,unsigned int nb_joueur);

/*
 * @brief Affiche le deck du joueur
 * @param[in] Joueur
*/
void afficher_deck(Joueur& joueur);

#endif // FONCTION_H