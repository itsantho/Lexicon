#include "jeu.h"
#include "Joueurs.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <fstream>

class NbJoueurMax;

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



void initialiser_paquet(ListCarte& c){
    // i la position de carte dans le paquet de 51, index la lettre, j la quantité
    c = initialiser_liste_carte(NbrCartes);
    unsigned int qte[NbrCartesUnique] = {2,2,2,2,5,1,2,2,4,1,1,2,1,3,2,1,1,3,3,3,3,1,1,1,1,1};
    for (unsigned int i = 0; i < NbrCartesUnique; ++i) {
        for (unsigned int j = 0; j < qte[i]; ++j) {
            ajouter(c, 'A' + i);
        }
    }
}

void afficher_cartes(const ListCarte& c){
    for(unsigned int i = 0 ; i < c.taille; ++i){
        cout << lire(c, i);
    }
    cout << endl;
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
    // Donne une carte que si le joueur est actif
    if(j.actif)
        ajouter(j.carte_possede, c);
}



void distribuer(ListCarte& c, ListeDeJoueurs& liste, unsigned int nb_joueur) {
    for (unsigned int i = 0; i < nb_joueur; ++i) {
        for (unsigned int j = 0; j < NbrCarteParJoueur; ++j) {
            donner_une_carte(liste.joueurs[i], lire(c,c.taille-1));
            --c.taille;
        }
    }
}

void afficher_deck(ListeDeJoueurs& liste) {
    cout << "* JOUEUR" << ' ' << liste.indiceJoueurActuel+1 << ' ';
    afficher_cartes(liste.joueurs[liste.indiceJoueurActuel].carte_possede);
    cout << endl;
}

void afficher_commandes() {
    cout << "(Commandes valides : TEPRC)" << endl;
}

bool TourGagne(ListeDeJoueurs& liste){
    for(unsigned int i = 0; i < liste.nb_joueurs; ++i){
        if(liste.joueurs[i].carte_possede.taille == 0)
            return true;
    }
    return false;
}



void cmd_talon(Pile& tal, Pile& expose, Joueur& j, ListeDeJoueurs& liste)  {
    char lettre;
    cin >> lettre;

    // Vérifie si le joueur possède la carte
    if (!contient(j.carte_possede, lettre))
        return;
    // empile la carte au dessus des cartes exposés
    empiler(expose,lettre);
    // Supprime la carte de la main du joueur
    retirer(j.carte_possede, lettre);

    Carte c = sommet(tal);
    depiler(tal);
    //La première carte de talon est ajouté à la main du joueur
    ajouter(j.carte_possede, c);
    joueur_suivant(liste);
}

void cmd_expose(Pile& exposee, Joueur &j, ListeDeJoueurs& liste) {
    char lettre;
    cin >> lettre;

    if (!contient(j.carte_possede, lettre))
        return;

    Carte tmp = sommet(exposee);
    depiler(exposee);
    empiler(exposee, lettre);
    retirer(j.carte_possede,lettre);
    ajouter(j.carte_possede, tmp);
    joueur_suivant(liste);
}

void cmd_poser(Joueur& j, ListMots& motPose, ListeDeJoueurs& liste){
    string m;
    string input;
    ListCarte word = initialiser_liste_carte(TAILLE_MAX_MOT);
    cin >> input;
    for (char caractere : input) {
        ajouter(word, caractere);
    };


    // Valide par rapport au dictionnaire
    if(!motDansDictionnaire(input, DICTIONARY_PATH)){
        cout << "Le mot ne fait pas partie du dictionnaire, passe ton tour" << endl;
        joueur_suivant(liste);
        return;
    }


    // On vérifie si le joueur possèdes ces cartes
    for(unsigned int i = 0; i < word.taille; ++i){
        if (!contient(j.carte_possede,word.cartes[i]))
            return;
    }
    //Supprimer les carte du joueurs
    for (unsigned int i = 0; i < word.taille; ++i){
        retirer(j.carte_possede,word.cartes[i]);
    }

    //ajouter le mot à la liste de mot sur la table
    AjouterListMots(motPose,word);

    // Passe au joueur suivant
    joueur_suivant(liste);
}

void remplacer(Joueur& j, ListMots& motsPose, const ListMots dictionnaire){
    // 1. Vérifier que l'indice du mot est valide
    unsigned int numero;
    cin >> numero;
     if (numero > motsPose.capacite) {
            cout << "erreur" << endl;
     }

    // 2. Le nouveau mot doit avoir la même taille que celui remplacé
    // Récupérer toutes les cartes remplaçantes et toutes les cartes remplacées dans deux listes
    // Vérifier que le joueur possède les cartes remplaçantes
    // Vérifier que le mot est valide
    // Remplacer le mot
    // Supprimer les cartes utilisées pour remplacer et récupérer les cartes remplacées
}


bool motDansDictionnaire(const std::string& mot, const std::string& fichierDictionnaire) {
    // Ouverture du fichier

    std::ifstream fichier(fichierDictionnaire);

    // Vérification si le fichier est ouvert correctement
    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return false;
    }

    // Recherche du mot dans le fichier
    std::string ligne;
    while (std::getline(fichier, ligne)) {
        // Comparaison sans tenir compte de la casse (minuscules/majuscules)
        if (mot == ligne) {
            fichier.close();  // Fermeture du fichier
            return true;
        }
    }

    fichier.close();  // Fermeture du fichier
    return false;     // Le mot n'a pas été trouvé
}


