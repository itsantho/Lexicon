#include "jeu.h"
#include "Conteneur/ListCarte.h"
#include "Conteneur/piles.h"
#include "Joueurs.h"
#include <iostream>

using namespace std;

int main() {
    //
    // Lancement
    //

    // On demande le nombre de joueurs
    unsigned int nb_joueurs = 0;
    nb_joueurs = demander_nb_joueurs();

    //
    // Préparation de tous les conteneurs
    //
    ListeDeCartes cartes; // Paquet de carte
    Pile exposees; // l'exposée
    Pile talon; // Le talon
    ListeDeMots mots; // Liste des mots posés sur la table
    creer_liste_mots(mots,CAPACITE_LISTE_MOTS);

    // Création des joueurs
    ListeDeJoueurs listejoueurs = initialiserlistejoueur(nb_joueurs);

    //Creation du paquet de cartes
    initialiser_paquet(cartes);

    //Afficher les commandes disponibles
    afficher_commandes();


    while (jeuEnCours(listejoueurs)) {
        // DEBUT DU TOUR

        // Initialisation du tour

        //Melange du paquet de cartes
        melanger_paquet(cartes);

        //Distribution des cartes aux joueurs
        distribuer(cartes, listejoueurs, nb_joueurs);

        // Le reste des cartes deviennent la pile talon
        exposees = initialiser_pile();
        talon = initialiser_pile();

        //Assigne le paquet de cartes au talon
        pileDeCartes(talon,cartes);

        // La carte au sommet du reste des cartes (talon) devient la carte exposée
        empiler(exposees, depiler(talon));

        while(!agagneletour(joueur_actuel(listejoueurs))){

            // AFFICHAGE
            affichage(listejoueurs, exposees);
            afficher_liste_mots(mots);

            // SAISIE
            char cmd;
            cout << '>';
            cin >> cmd;

            switch (cmd) {
                case 'T': {
                    cmd_talon(talon, exposees, joueur_actuel(listejoueurs),listejoueurs);
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
                    cmd_completer(joueur_actuel(listejoueurs),mots,listejoueurs);
                    break;
                }
                default:
                    cout << "Coup invalide, recommencez" << endl;
                    break;
            }
        }
        // FIN DU TOUR
        // Actualiser le score
        maj_des_scores(listejoueurs);
        afficher_score(listejoueurs);

        // Réinitialiser toutes les données avant de commercer une nouvelle manche
        detruire_pile(exposees);
        detruire_pile(talon);
        detruire_liste_mots(mots);
        detruire_liste_carte(cartes);
    }
    cout << "La partie est finie";
}


