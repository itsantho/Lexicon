//
// Created by ieman on 04/01/2024.
//

#include "Joueurs.h"
void penaliser(Joueur& joueur){
    joueur.scores += PENALITE;
}

unsigned int scorejoueur(const Joueur& joueur) {
    //On assigne le score correspondant à chaque carte
    unsigned int scores[NbrCartesUnique] = {
            10, 2, 8, 6, 10, 2, 4, 8, 10,
            6, 8, 8, 8, 8, 8, 8, 4, 8,
            8, 8, 8, 8, 8, 2, 4, 2
    };

    //Initialisation du score a 0
    unsigned int score = 0;

    //On rajoute le score en fonction des cartes du joueur à la fin du tour
    for (unsigned int i = 0; i < joueur.carte_possede.taille ;++i)
    {
        const Carte card = joueur.carte_possede.cartes[i];
        score += scores[card];
    }

    return score;
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
        joueurs.joueurs[i].carte_possede = initialiser_liste_carte(NbrCarteParJoueur);
        joueurs.joueurs[i].scores = 0;
        joueurs.joueurs[i].actif = true;
        joueurs.nb_joueurs_actifs = nb_joueurs;
    }


    return joueurs;
}



void maj_des_scores(ListeDeJoueurs& joueurs){
    for (unsigned int i = 0; i < joueurs.nb_joueurs_actifs; ++i)
    {
        Joueur& joueur = joueur_actuel(joueurs);

        joueur.scores += scorejoueur(joueur);

        //
        // Vérifier si le joueur dépasse le score maximal, et le rendre inactif si c'est le cas
        //
        if (joueur.scores >= SCORE_DEFAITE){
            // Le joueur actuel est éliminé et le nombre de joueurs actifs diminue
            joueur.actif = false;
            --joueurs.nb_joueurs_actifs;
        }

        joueur_suivant(joueurs);
    }
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

bool agagneletour(const Joueur& joueurActuel){
    if (joueurActuel.carte_possede.taille == 0)
        return true;
    else
        return false;
}

void detruireListeJoueur(ListeDeJoueurs& joueurs){
    delete[] joueurs.joueurs;
}
