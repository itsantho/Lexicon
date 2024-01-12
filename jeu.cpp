#include "jeu.h"
#include "Joueurs.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// implémentation 

unsigned int demander_nb_joueurs(){
    unsigned int nb_joueurs = 0;
    while (nb_joueurs < JOUEUR_MIN || nb_joueurs > JOUEUR_MAX){
        cout << "SAISIR LE NOMBRE DE JOUEUR"<< endl;
        cin >> nb_joueurs;
    }
    return nb_joueurs;
}

void initialiser_paquet(ListeDeCartes& c){
    // i la position de carte dans le paquet de 51, index la lettre, j la quantité
    c = initialiser_liste_carte(NB_CARTES);
    // Assigne à chaque carte son nombre d'apparitions dans le paquet
    unsigned int qte[NB_CARTES_UNIQUE] = {2,2,2,2,5,1,2,2,4,1,1,2,1,3,2,1,1,3,3,3,3,1,1,1,1,1};
    for (unsigned int i = 0; i < NB_CARTES_UNIQUE; ++i) {
        for (unsigned int j = 0; j < qte[i]; ++j) {
            ajouter(c, 'A' + i);
        }
    }
}

void afficher_cartes(const ListeDeCartes& c){
    for(unsigned int i = 0 ; i < c.taille; ++i){
        cout << lire(c, i);
    }
    cout << endl;
}

void melanger_paquet(ListeDeCartes& c) {
    srand(time(nullptr));

    for (unsigned int i = 0; i < NB_CARTES; ++i)
    {
        const unsigned int j = rand() % NB_CARTES;
        Carte tmp = lire(c, i);

        modifier(c, i, lire(c, j));
        modifier(c, j, tmp);
    }
}

void donner_une_carte(Joueur& j, Carte c) {
    // Donne une carte que si le joueur est actif
    if(j.actif)
        ajouter(j.carte_possede, c);
}

void distribuer(ListeDeCartes& c, ListeDeJoueurs& liste, unsigned int nb_joueur) {
    for (unsigned int i = 0; i < nb_joueur; ++i) {
        for (unsigned int j = 0; j < NB_CARTES_JOUEUR; ++j) {
            donner_une_carte(liste.joueurs[i], lire(c,c.taille-1));
            --c.taille;
        }
    }
}

void affichage(ListeDeJoueurs& liste,Pile& p) {
    cout << "* JOUEUR" << ' ' << liste.indiceJoueurActuel+1 << " (" << sommet(p) << ") ";

    afficher_cartes(joueur_actuel(liste).carte_possede);

}

void afficher_commandes() {
    cout << "(Commandes valides : TEPRC)" << endl;
}

bool motdansdictionnaire(const ListeDeCartes& mot){
    // Ouverture du fichier

    ifstream fichier(DICTIONARY_PATH);

    // Vérification si le fichier est ouvert correctement
    if (!fichier.is_open()) {
        cerr << "Erreur lors de l'ouverture du fichier." << endl;
        return false;
    }

    // Recherche du mot dans le fichier
    char ligne[TAILLE_MAX_MOT+1];
    while (fichier.getline(ligne, TAILLE_MAX_MOT + 1)) {
        if (comparaison(mot,ligne)) {
            fichier.close();  // Fermeture du fichier
            return true;
        }
    }

    fichier.close();  // Fermeture du fichier
    return false;     // Le mot n'a pas été trouvé
}

bool comparaison(const ListeDeCartes& mot1, const char* mot2){
    for(unsigned int i = 0; i < mot1.taille; ++i){
        if (lire(mot1, i) != mot2[i])
            return false;
    }
    return true;
}

bool jeuEnCours(ListeDeJoueurs& liste){
    if(liste.nb_joueurs_actifs>1)
        return true;
    else
        return false;
}

void afficher_score(ListeDeJoueurs& listeDeJoueurs){
    cout << "Le tour est fini" << endl << "* Scores" << endl;

    for(unsigned int i = 0; i < listeDeJoueurs.nb_joueurs ; ++i)
        if(listeDeJoueurs.joueurs[i].actif)
            cout << "Joueur " << i+1 << " : " << listeDeJoueurs.joueurs[i].scores << endl;

    cout << endl;
}

bool liste_carte_diff(ListeDeCartes& a, ListeDeCartes& b){
    for (unsigned int i = 0; i < NB_CARTES; ++i){
        if(a.cartes != b.cartes)
            return true;
    }
    return false;
}



