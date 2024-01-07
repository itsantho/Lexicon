
#include "jeu.h"
#include "Conteneur/ListCarte.h"
#include "Conteneur/piles.h"
#include "Joueurs.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    // On demande le nombre de joueurs
    unsigned int nb_joueurs = 0;
    nb_joueurs = demander_nb_joueurs(); // Vérifie si le nombre de joueurs dépasse le minimum ou maximum
    // Initialisation

    // Paquet de carte
    ListCarte cartes;
    Pile exposees;
    Pile tal;


    ListMots mots;
    CreerListMots(mots,10);
    ListeDeJoueurs listejoueurs = initialiserlistejoueur(nb_joueurs);


    //Creation du paquet de cartes
    initialiser_paquet(cartes);


    //Melange du paquet de cartes
    melanger_paquet(cartes);

    //Distribution des cartes aux joueurs
    distribuer(cartes, listejoueurs, nb_joueurs);



    // Le reste des cartes deviennent la pile talon
    exposees = initialiser_pile();
    tal = initialiser_pile();
    //Assigne le paquet de cartes au talon
    pileDeCartes(tal,cartes);
    // La carte au sommet du reste des cartes devient la carte exposé
    empiler(exposees, depiler(tal));
    //Fonction qui permet d'afficher les commandes disponibles
    afficher_commandes();


    while (jeuEnCours(listejoueurs)) {
        // Debut du tour
        while(!agagneletour(joueur_actuel(listejoueurs))){
            affichage(listejoueurs, exposees);
            afficher_liste_mots(mots);
                cout << '>';
                char cmd;
                cin >> cmd;
                switch (cmd) {
                    case 'T': {
                        // La lettre doit correspondre à une de celles détenues par le joueur. La carte correspondante est placée au dessus
                        //des cartes exposées et la première carte du talon est ramassée par le joueur

                        cmd_talon(tal, exposees, joueur_actuel(listejoueurs),listejoueurs);
                        break;
                    }
                    case 'E': {
                        cmd_expose(exposees,joueur_actuel(listejoueurs),listejoueurs);

                        break;
                    }
                    case 'P': {
                        cmd_poser(joueur_actuel(listejoueurs), mots, listejoueurs);
                        break;
                    }
                    case 'R':
                    case 'C': {

                        break;
                    }
                    default:
                        cout << "Coup invalide, recommencez" << endl;
                        break;
                }
        }
        // Actualiser le score
        maj_des_scores(listejoueurs);

    }
}


