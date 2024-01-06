
#include "jeu.h"
#include "Conteneur/ListCarte.h"
#include "Conteneur/piles.h"
#include "Joueurs.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    // on demande le nombre de joueurs
    // Verifie si le le nombre de joueur dépasse le min ou max
    unsigned int nb_joueurs = 0;
    nb_joueurs = demander_nb_joueurs();
    // Initialisation

    // Paquet de carte
    ListCarte cartes;
    Pile exposees;
    Pile tal;
    initialiser(tal, TAILLE_MAX_MOT);
    initialiser(exposees, TAILLE_MAX_MOT);
    const char *dictionnaire = "ods4.txt";
    ListMots mots;
    CreerListMots(mots,10);
    ListeDeJoueurs listejoueurs = InitialiserListeJoueur(nb_joueurs);


    //Creation du paquet de cartes
    initialiser_paquet(cartes);


    //Melange du paquet de cartes
    melanger_paquet(cartes);

    //Distribuation des cartes aux joueurs

    distribuer(cartes, listejoueurs, nb_joueurs);

    //Fonction qui permet d'afficher les commandes disponibles
    afficher_commandes();


    //Indicateur du bon déroulement de la partie
    bool jeu_en_cours = true;

    while (jeu_en_cours) {
        // Debut du tour
        while(!aGagneLeTour(listejoueurs.joueurs[listejoueurs.indiceJoueurActuel])){
            afficher_deck(listejoueurs);
            afficher_liste_mots(mots);
                cout << '>';
                char cmd;
                cin >> cmd;
                switch (cmd) {
                    case 'T': {
                        // La lettre doit correspondre à une de celles détenues par le joueur. La carte correspondante est placée au dessus
                        //des cartes exposées et la première carte du talon est ramassée par le joueur

                        cmd_talon(tal, exposees, listejoueurs.joueurs[listejoueurs.indiceJoueurActuel],listejoueurs);
                        break;
                    }
                    case 'E': {
                        cmd_expose(exposees,listejoueurs.joueurs[listejoueurs.indiceJoueurActuel],listejoueurs);

                        break;
                    }
                    case 'P': {
                        cmd_poser(listejoueurs.joueurs[listejoueurs.indiceJoueurActuel], mots, listejoueurs);
                        break;
                    }
                    case 'R':
                    case 'C': {
                        jeu_en_cours = false;
                        break;
                    }
                    default:
                        std::cout << "Coup invalide, recommencez" << std::endl;
                        break;
                }
        }

    }
}


