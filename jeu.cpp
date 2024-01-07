#include "jeu.h"
#include "Joueurs.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iomanip>
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
    // Assigne à chaque carte son nombre d'apparition dans le paquet
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

void affichage(ListeDeJoueurs& liste,Pile& p) {
    cout << "* JOUEUR" << ' ' << liste.indiceJoueurActuel+1 << " (" << sommet(p) << ") ";

    afficher_cartes(joueur_actuel(liste).carte_possede);

}



void afficher_commandes() {
    cout << "(Commandes valides : TEPRC)" << endl;
}

void cmd_talon(Pile& tal, Pile& expose, Joueur& j, ListeDeJoueurs& liste)  {
    char lettre;
    cin >> lettre;

    // Vérifie si le joueur possède la carte
    if (!contient(j.carte_possede, lettre))
        return;
    // Empile la carte au-dessus des cartes exposées
    empiler(expose,lettre);
    // Supprime la carte de la main du joueur
    retirer(j.carte_possede, lettre);

    Carte c = sommet(tal);
    depiler(tal);
    // La première carte de talon est ajouté à la main du joueur
    ajouter(j.carte_possede, c);
    joueur_suivant(liste);
}

void cmd_expose(Pile& exposee, Joueur &j, ListeDeJoueurs& liste) {
    char lettre;
    cin >> lettre;

    if (!contient(j.carte_possede, lettre))
        return;
    // La carte exposée est remplacée par la carte du joueur
    Carte tmp = sommet(exposee);
    depiler(exposee);
    empiler(exposee, lettre);
    // Le joueur remplace sa carte par l'ancienne carte exposée
    retirer(j.carte_possede,lettre);
    ajouter(j.carte_possede, tmp);
    // Fin de la commande et passe au joueur suivant
    joueur_suivant(liste);
}

void cmd_poser(Joueur& j, ListMots& motPose, ListeDeJoueurs& liste){
    char input[TAILLE_MAX_MOT+1];
    ListCarte word = initialiser_liste_carte(TAILLE_MAX_MOT);

    cin >> std::setw(TAILLE_MAX_MOT) >> input;

    for (unsigned int i = 0; i < strlen(input); ++i) {
        ajouter(word, input[i]);
    };


    // Valide par rapport au dictionnaire
    if(!motdansdictionnaire(word)){
        cout << "Le mot ne fait pas partie du dictionnaire, passe ton tour" << endl;
        penaliser(joueur_actuel(liste));
        joueur_suivant(liste);
        return;
    }

    // On vérifie si le joueur possède ces cartes
    for(unsigned int i = 0; i < word.taille; ++i){
        if (!contient(j.carte_possede,word.cartes[i]))
            return;
    }
    // Supprimer les cartes du joueur
    for (unsigned int i = 0; i < word.taille; ++i){
        retirer(j.carte_possede,word.cartes[i]);
    }

    // Ajouter le mot à la liste de mot sur la table
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


bool motdansdictionnaire(const ListCarte& mot) {
    // Ouverture du fichier

    std::ifstream fichier(DICTIONARY_PATH);

    // Vérification si le fichier est ouvert correctement
    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
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

bool comparaison(const ListCarte& mot1, const char* mot2)
{
    for(unsigned int i = 0; i < mot1.taille; ++i){
        if (lire(mot1, i) != mot2[i])
            return false;
    }
    return true;
}

bool jeuEnCours(ListeDeJoueurs& liste){
    if(liste.nb_joueurs_actifs<=1)
        return false;
    return true;
}



