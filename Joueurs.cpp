//
// Created by ieman on 04/01/2024.
//

#include "Joueurs.h"
void Penaliser(Joueur& joueur){
    joueur.scores += PENALITE;
}

unsigned int ScoreJoueur(const Joueur& joueur) {
    unsigned int scores[NbrCartesUnique] = {
            10, 2, 8, 6, 10, 2, 4, 8, 10,
            6, 8, 8, 8, 8, 8, 8, 4, 8,
            8, 8, 8, 8, 8, 2, 4, 2
    };

    unsigned int score = 0;

    for (unsigned int i = 0; i < joueur.carte_possede.taille ;++i)
    {
        const Carte card = joueur.carte_possede.cartes[i];
        score += scores[CARD_NO(card)];
    }

    return score;
}

ListeDeJoueurs InitialiserListeJoueur(unsigned int nb_joueurs){
    ListeDeJoueurs players {
        .joueurs = new Joueur[nb_joueurs],
        .nb_joueurs = nb_joueurs,
        .indiceJoueurActuel = 0
};
    // Créer une liste de carte vide pour chaque joueur
    for (unsigned int i = 0; i < nb_joueurs; ++i)
    {
        players.joueurs[i].carte_possede = initialiser_liste_carte(NbrCarteParJoueur);
        players.joueurs[i].scores = 0;
        players.joueurs[i].actif = true;
    }


    return players;
}



void Maj_des_Scores(ListeDeJoueurs& joueurs){
    for (unsigned int i = 0; i < joueurs.nb_joueurs; ++i)
    {
        Joueur& joueur = joueurs.joueurs[i]; //jsp ça fait reference a quelle fonction

        joueur.scores += ScoreJoueur(joueur);

        //
        // Vérifier si le joueur dépasse le score maximal, et le rendre inactif si c'est le cas
        //
        if (joueur.scores >= SCORE_DEFAITE)
            joueur.actif = false;
    }
}

void joueur_suivant(ListeDeJoueurs &liste) {
    // Passe au joueur suivant qui est actif
    while(!liste.joueurs[liste.indiceJoueurActuel].actif){
        ++liste.indiceJoueurActuel;
        if(liste.indiceJoueurActuel > liste.nb_joueurs)
            liste.indiceJoueurActuel = 0;

    }
}
