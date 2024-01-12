//
// Created by ieman on 04/01/2024.
//

#include "Joueurs.h"

void assert(bool b);

void penaliser(Joueur& joueur){
    joueur.scores += PENALITE;
}

void scorejoueur(Joueur& joueur) {
    //On assigne le score correspondant à chaque carte
    unsigned int scores[NB_CARTES_UNIQUE] = {
            10, 2, 8, 6, 10, 2, 4, 8, 10,
            6, 8, 8, 8, 8, 8, 8, 4, 8,
            8, 8, 8, 8, 8, 2, 4, 2
    };

    char lettres[NB_CARTES_UNIQUE] = {
            'A','B','C','D','E','F' ,'G' ,'H' ,
            'I' ,'J','K','L','M','N','O','P',
            'Q','R','S','T','U','V','W','X',
            'Y','Z'
    };


    for (unsigned int i = 0; i < joueur.carte_possede.taille; ++i){
        for (unsigned int Cartepos = 0, ScoreAjouter = 0; Cartepos < NB_CARTES_UNIQUE; ++Cartepos)
            if (joueur.carte_possede.cartes[i] == lettres[Cartepos] and ScoreAjouter == 0){
                joueur.scores += scores[Cartepos];
                ++ScoreAjouter;
            }
    }
    if(joueur.scores >=SCORE_DEFAITE)
        joueur.actif = false;
}

ListeDeJoueurs initialiserlistejoueur(unsigned int nb_joueurs){
    ListeDeJoueurs joueurs {
        joueurs.joueurs = new Joueur[nb_joueurs],
        joueurs.nb_joueurs = nb_joueurs,
        joueurs.indiceJoueurActuel = 0
};
    // Créer une liste de carte vide pour chaque joueur
    for (unsigned int i = 0; i < nb_joueurs; ++i)
    {
        joueurs.joueurs[i].carte_possede = initialiser_liste_carte(NB_CARTES_JOUEUR);
        joueurs.joueurs[i].scores = 0;
        joueurs.joueurs[i].actif = true;
        joueurs.nb_joueurs_actifs = nb_joueurs;
    }


    return joueurs;
}

Joueur& joueur_actuel(const ListeDeJoueurs& joueurs)
{
    return joueurs.joueurs[joueurs.indiceJoueurActuel];
}

void joueur_suivant(ListeDeJoueurs &liste) {
    do {
        // Passe au joueur suivant qui est actif
        ++liste.indiceJoueurActuel;

        if(liste.indiceJoueurActuel >= liste.nb_joueurs)
            liste.indiceJoueurActuel = 0;
    } while (!liste.joueurs[liste.indiceJoueurActuel].actif);
}

bool fin_tour(const ListeDeJoueurs& joueurs){
    for(unsigned int i = 0; i < joueurs.nb_joueurs; ++i)
        if(joueurs.joueurs[i].actif)
            if (joueurs.joueurs[i].carte_possede.taille == 0)
                return true;

    return false;
}

void detruireListeJoueur(ListeDeJoueurs& joueurs){
    delete[] joueurs.joueurs;
}
