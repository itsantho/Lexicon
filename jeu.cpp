#include "jeu.h"
#include "Joueurs.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <cassert>
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
    if(liste.nb_joueurs_actifs<=1)
        return false;
    return true;
}

void afficher_score(ListeDeJoueurs& listeDeJoueurs){
    cout << "Le tour est fini" << endl << "* Scores" << endl;

    for(unsigned int i = 0; i < listeDeJoueurs.nb_joueurs ; ++i)
        if(listeDeJoueurs.joueurs[i].actif)
            cout << "Joueur " << i+1 << " : " << listeDeJoueurs.joueurs[i].scores;

    cout << endl;
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

void cmd_poser(Joueur& j, ListeDeMots& motPose, ListeDeJoueurs& listeDeJoueurs){
    char input[TAILLE_MAX_MOT+1];
    // Allouer de la place pour le mot
    ListeDeCartes mot = initialiser_liste_carte(TAILLE_MAX_MOT);

    cin >> setw(TAILLE_MAX_MOT) >> input;

    for (unsigned int i = 0; i < strlen(input); ++i) {
        ajouter(mot, input[i]);
    };

    // Vérifie si le joueur possède ces cartes
    for(unsigned int i = 0; i < mot.taille; ++i){
        if (!contient(j.carte_possede,mot.cartes[i])){
            detruire_liste_carte(mot);
            return;
        }

    }
    // Valide par rapport au dictionnaire
    if(!motdansdictionnaire(mot)){
        cout << "Le mot ne fait pas partie du dictionnaire, passe ton tour" << endl;
        penaliser(joueur_actuel(listeDeJoueurs));
        joueur_suivant(listeDeJoueurs);
        detruire_liste_carte(mot);
        return;
    }

    // Supprimer les cartes du joueur
    for (unsigned int i = 0; i < mot.taille; ++i){
        retirer(j.carte_possede,mot.cartes[i]);
    }

    // Ajouter le mot à la liste de mot sur la table
    ajouter_mot(motPose,mot);

    //Désallouer le mot créé au début de la fonction
    detruire_liste_carte(mot);

    // Passe au joueur suivant
    joueur_suivant(listeDeJoueurs);
}

void cmd_remplacer(Joueur& j, ListeDeMots& motsPose){
    // 1. Vérifier que l'indice du mot est valide
    unsigned int numero;
    cin >> numero;
     if (numero > motsPose.taille) {
         return;
     }

    // 2. Le nouveau mot doit avoir la même taille que celui remplacé
    // Récupérer toutes les cartes remplaçantes et toutes les cartes remplacées dans deux listes
    // Vérifier que le joueur possède les cartes remplaçantes
    // Vérifier que le mot est valide
    // Remplacer le mot
    // Supprimer les cartes utilisées pour remplacer et récupérer les cartes remplacées
}

void cmd_completer(Joueur& j, ListeDeMots& motsPose, ListeDeJoueurs& listeDeJoueurs) {
    unsigned int numero;
    char input[TAILLE_MAX_MOT + 1];
    // Allouer de la place pour le mot
    ListeDeCartes mot = initialiser_liste_carte(TAILLE_MAX_MOT);
    cin >> numero >> setw(TAILLE_MAX_MOT) >> input;

    // Vérifier si le numéro est valide
    if (numero > motsPose.taille) {
        detruire_liste_carte(mot);
        return;
    }
    // Vérifie si le joueur possède ces cartes
    for (unsigned int i = 0; i < mot.taille; ++i) {
        if (!contient(j.carte_possede, mot.cartes[i])) {
            detruire_liste_carte(mot);
            return;
        }
    }
    // Valide par rapport au dictionnaire
    if (!motdansdictionnaire(mot)) {
        cout << "Le mot ne fait pas partie du dictionnaire, passe ton tour" << endl;
        penaliser(joueur_actuel(listeDeJoueurs));
        joueur_suivant(listeDeJoueurs);
        detruire_liste_carte(mot);
        return;
    }
    // Modifie le mot à l'indice souhaité
    modifier_mot(motsPose,numero,mot);

    // Supprimer les cartes du joueur
    for (unsigned int i = 0; i < mot.taille; ++i){
        retirer(j.carte_possede,mot.cartes[i]);
    }

    detruire_liste_carte(mot);
    joueur_suivant(listeDeJoueurs);
}

