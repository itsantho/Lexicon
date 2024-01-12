#include "Commandes.h"
#include <iostream>
#include <istream>
#include <iomanip>



using namespace std;

void cmd_talon(Pile& tal, Pile& expose, Joueur& j, ListeDeJoueurs& liste) {
    char lettre;
    cin >> lettre;

        // Vérifie si le joueur possède la carte
    if (!contient(j.carte_possede, lettre)) {

    }

    // Empile la carte au-dessus des cartes exposées
    empiler(expose, lettre);
    // Supprime la carte de la main du joueur
    retirer(j.carte_possede, lettre);

    Carte c = sommet(tal);
    depiler(tal);
    // La première carte de talon est ajouté à la main du joueur
    ajouter(j.carte_possede, c);
    joueur_suivant(liste);
}

void cmd_expose(Pile& exposee, Joueur& j, ListeDeJoueurs& liste) {
    char lettre;
    cin >> lettre;

    if (!contient(j.carte_possede, lettre)) {
        cout << "Coup invalide, recommencez" << endl;
        return;
    }
    // La carte exposée est remplacée par la carte du joueur
    Carte tmp = sommet(exposee);
    depiler(exposee);
    empiler(exposee, lettre);
    // Le joueur remplace sa carte par l'ancienne carte exposée
    retirer(j.carte_possede, lettre);
    ajouter(j.carte_possede, tmp);
    // Fin de la commande et passe au joueur suivant
    joueur_suivant(liste);
}

void cmd_poser(Joueur& j, ListeDeMots& motPose, ListeDeJoueurs& listeDeJoueurs) {
    char input[TAILLE_MAX_MOT + 1];
    // initialiser
    ListeDeCartes mot = initialiser_liste_carte(TAILLE_MAX_MOT);

    cin >> setw(TAILLE_MAX_MOT) >> input;

    for (unsigned int i = 0; i < strlen(input); ++i) {
        ajouter(mot, input[i]);
    };

    // Vérifie si le joueur possède ces cartes
    for (unsigned int i = 0; i < mot.taille; ++i) {
        if (!contient(j.carte_possede, mot.cartes[i])) {
            detruire_liste_carte(mot);
            cout << "Coup invalide, recommencez" << endl;
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

    // Supprimer les cartes du joueur
    for (unsigned int i = 0; i < mot.taille; ++i) {
        retirer(j.carte_possede, mot.cartes[i]);
    }

    // Ajouter le mot à la liste de mot sur la table
    ajouter_mot(motPose, mot);

    // Passe au joueur suivant
    joueur_suivant(listeDeJoueurs);


}

void cmd_remplacer(Joueur& j, ListeDeMots& motsPose, ListeDeJoueurs& listeDeJoueurs) {

    unsigned int numero;
    char input[TAILLE_MAX_MOT + 1];
    ListeDeCartes carte_remplace = initialiser_liste_carte(TAILLE_MAX_MOT);
    // Allouer de la place pour le nouveau mot
    ListeDeCartes nouveau_mot = initialiser_liste_carte(TAILLE_MAX_MOT);
    cin >> numero >> input;
    --numero;


    // Donner les caractères saisie au mot
    for (unsigned int i = 0; i < strlen(input); ++i) {
        ajouter(nouveau_mot, input[i]);
    };


    // Vérifier si le numéro est valide
    if (numero > motsPose.taille) {
        detruire_liste_carte(nouveau_mot);
        detruire_liste_carte(carte_remplace);
        cout << "Coup invalide, recommencez" << endl;
        return;
    }
    // Le nouveau mot doit avoir la même taille que celui remplacé
    if (nouveau_mot.taille != motsPose.mots[numero].taille) {
        detruire_liste_carte(nouveau_mot);
        detruire_liste_carte(carte_remplace);
        cout << "Coup invalide, recommencez" << endl;
        return;
    }

    // Récupérer toutes les cartes remplaçantes et toutes les cartes remplacées dans deux listes
    for (unsigned int i = 0; i < nouveau_mot.taille; ++i) {
        if (lire(nouveau_mot, i) != lire(motsPose.mots[numero], i))
            ajouter(carte_remplace, lire(nouveau_mot, i));
    }
    // Vérifier que le joueur possède les cartes remplaçantes
    for (unsigned int i = 0; i < carte_remplace.taille; ++i) {
        if (!contient(j.carte_possede, carte_remplace.cartes[i])) {
            detruire_liste_carte(nouveau_mot);
            detruire_liste_carte(carte_remplace);
            cout << "Coup invalide, recommencez" << endl;
            return;
        }

    }

    // Valide par rapport au dictionnaire
    if (!motdansdictionnaire(nouveau_mot)) {
        cout << "Le mot ne fait pas partie du dictionnaire, passe ton tour" << endl;
        penaliser(joueur_actuel(listeDeJoueurs));
        joueur_suivant(listeDeJoueurs);
        detruire_liste_carte(nouveau_mot);
        return;
    }
    // Remplacer les lettres
    for (unsigned int i = 0; i < nouveau_mot.taille; ++i) {
        if (lire(nouveau_mot, i) != lire(motsPose.mots[numero], i))
            modifier(motsPose.mots[numero], i, nouveau_mot.cartes[i]);
    }
    // Supprimer les cartes utilisées pour remplacer et récupérer les cartes remplacées
    for (unsigned int i = 0; i < carte_remplace.taille; ++i) {
        retirer(j.carte_possede, nouveau_mot.cartes[i]);
        ajouter(j.carte_possede, carte_remplace.cartes[i]);

    }

    // Desallouer les listes de cartes
    detruire_liste_carte(carte_remplace);
    detruire_liste_carte(nouveau_mot);

    joueur_suivant(listeDeJoueurs);
}

void cmd_completer(Joueur& j, ListeDeMots& motsPose, ListeDeJoueurs& listeDeJoueurs) {

    unsigned int numero;
    char input[TAILLE_MAX_MOT + 1];
    // Allouer de la place pour le nouveau mot
    ListeDeCartes nouveau_mot = initialiser_liste_carte(TAILLE_MAX_MOT);
    ListeDeCartes nouveau_mot_valide = initialiser_liste_carte(TAILLE_MAX_MOT);
    cin >> numero >> input;
    --numero;

    // Donner les caractères saisie au mot
    for (unsigned int i = 0; i < strlen(input); ++i) {
        ajouter(nouveau_mot, input[i]);
    };


    // Vérifier si le numéro est valide
    if (numero > motsPose.taille) {
        detruire_liste_carte(nouveau_mot);
        cout << "Coup invalide, recommencez" << endl;
        return;
    }


    // Vérifie si le joueur possède ces cartes ou que ces cartes sont présentes dans le mot
    for (unsigned int i = 0; i < nouveau_mot.taille; ++i) {
        if (!contient(j.carte_possede, nouveau_mot.cartes[i]) && !contient(motsPose.mots[numero], nouveau_mot.cartes[i])) {
            detruire_liste_carte(nouveau_mot);
            cout << "Coup invalide, recommencez" << endl;
            return;
        }
    }


    // Valide par rapport au dictionnaire
    if (!motdansdictionnaire(nouveau_mot)) {
        cout << "Le mot ne fait pas partie du dictionnaire, passe ton tour" << endl;
        penaliser(joueur_actuel(listeDeJoueurs));
        joueur_suivant(listeDeJoueurs);
        detruire_liste_carte(nouveau_mot);
        return;
    }


    // Parcourir la liste de mot pour savoir quelle lettre faut-il supprimer chez la main du joueur
    // Supprimer les cartes se trouvant déjà dans l'ancien mot
    for (unsigned int i = 0; i < motsPose.mots[numero].taille; ++i) {
        retirer(nouveau_mot, motsPose.mots[numero].cartes[i]);
    }

    // Supprimer les cartes du deck
    for (unsigned int i = 0; i < nouveau_mot.taille; ++i)
        retirer(j.carte_possede, nouveau_mot.cartes[i]);


    detruire_liste_carte(nouveau_mot);

    // Redonner les caractères saisies au mot



    // Donner les caractères saisie au mot
    for (unsigned int i = 0; i < strlen(input); ++i) {
        ajouter(nouveau_mot_valide, input[i]);
    };


    // Modifie le mot
    modifier_mot(motsPose, numero, nouveau_mot_valide);


    joueur_suivant(listeDeJoueurs);
}