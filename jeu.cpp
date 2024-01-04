#include "jeu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <cstring>

using namespace std;

// implémentation 

void initialiser_paquet(ListCarte& c){
    // i la position de carte dans le paquet de 51, index la lettre, j la quantité
    initialiser(c, NbrCartes);
    unsigned int qte[NbrCartesUnique] = {2,2,2,2,5,1,2,2,4,1,1,2,1,3,2,1,1,3,3,3,3,1,1,1,1,1};
    for (unsigned int i = 0; i < NbrCartesUnique; ++i) {
        for (unsigned int j = 0; j < qte[i]; ++j) {
            ajouter(c, 'A' + i);
        }
    }
}

void afficher_cartes(const ListCarte& c){
    for(unsigned int i = 0 ; i < c.taille; ++i){
        cout << lire(c, i) << endl;
    }

    std::cout << std::endl;
}

void melanger_paquet(ListCarte& c) {
    srand(time(nullptr));

    for (size_t i = 0; i < NbrCartes; ++i)
    {
        const size_t j = rand() % NbrCartes;
        Carte tmp = lire(c, i);

        modifier(c, i, lire(c, j));
        modifier(c, j, tmp);
    }
}

void donner_une_carte(Joueur& j, Carte c) {
    ajouter(j.carte_possede, c);
}

void distribuer(ListCarte& c, Joueur* joueurs, unsigned int nb_joueur) {
    for (unsigned int i = 0; i < nb_joueur; ++i) {
        for (unsigned int j = 0; j < NbrCarteParJoueur; ++j) {
            donner_une_carte(joueurs[i], lire(c,c.taille-1));
            --c.taille;
        }
    }
}

void afficher_deck(Joueur& joueur) {
    afficher_cartes(joueur.carte_possede);
}

void afficher_commandes() {
    cout << "(Commandes valides : TEPRC)" << endl;
}

void talon(Pile &talon, Pile& expose, Joueur& j) {

    char lettre;
    std::cin >> lettre;

    if (!contient(j.carte_possede, lettre))
        return;

    empiler(expose,lettre);
    retirer(j.carte_possede, lettre);

    Carte c = sommet(talon);
    depiler(talon);
    ajouter(j.carte_possede, c);
}

void expose(Pile &expose, Joueur &j) {
    char lettre;
    cin >> lettre;

    if (!contient(j.carte_possede, lettre))
        return;

    Carte tmp = sommet(expose);
    depiler(expose);
    empiler(expose, lettre);
    retirer(j.carte_possede,lettre);
    ajouter(j.carte_possede, tmp);
}

void poser(Joueur& j, ListMots& motPose, const ListMots& dictionnaire){
    ListCarte mot;
    initialiser(mot, 20);

    char input[16];
    cin >> input;
    //On ajoute à mot les caractères saisies
    for (unsigned int i = 0; i < strlen(input); ++i)
        ajouter(mot, input[i]);

    // On vérifie si le joueur possèdes ces cartes
    for(unsigned int i = 0; i < mot.taille; ++i){
        if (!contient(j.carte_possede,mot.cartes[i]))
            return;
    }
    // Valide par rapport au dictionnaire

    //Supprimer les carte du joueurs
    for (unsigned int i = 0; i < mot.taille; ++i){
        retirer(j.carte_possede,mot.cartes[i]);
    }
    //ajouter le mot à la liste de mot sur la table
    AjouterListMots(motPose,mot);
}

void remplacer(Joueur &j, ListMots &motsPose, const ListMots dictionnaire) {

}
