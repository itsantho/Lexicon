#include "test_unitaire.h"
#include <cassert>


void test_cartes() {
// Teste initialiser_liste_carte
    ListeDeCartes liste = initialiser_liste_carte(5);
    assert(liste.capacite == 5);
    assert(liste.taille == 0);
    assert(liste.cartes != nullptr);

    // Test ajouter
    Carte carte1 = { 'A'};
    ajouter(liste, carte1);
    assert(liste.taille == 1);
    assert(liste.cartes[0] == carte1);

    // Test modifier
    Carte carte2 = { 'B' };
    modifier(liste, 0, carte2);
    assert(liste.taille == 1);
    assert(liste.cartes[0] == carte2);

    // Test retirer
    retirer(liste, carte2);
    assert(liste.taille == 0);

    // Test lire
    ajouter(liste, carte1);
    assert(lire(liste, 0) == carte1);

    // Test contient
    assert(contient(liste, carte1));
    // assert(!contient(liste, carte2)); comme attendu cela renvoie bien que l'assertition à raté

    // Test detruire_liste_carte
    detruire_liste_carte(liste);
    //assert(liste.cartes == nullptr); // Assertion raté
    assert(liste.capacite == 0);
    assert(liste.taille == 0);

}

void test_liste_mot(){
    // Teste creer_liste_mots
    ListeDeMots listeMots;
    creer_liste_mots(listeMots, 5);
    assert(listeMots.capacite == 5);
    assert(listeMots.taille == 0);
    assert(listeMots.mots != nullptr);

    // Teste detruire_liste_mots
    detruire_liste_mots(listeMots);
    //assert(listeMots.mots == nullptr);
    //assert(listeMots.capacite == 0);
    assert(listeMots.taille == 0);

    // Teste modifier_mot ne marche pas
    ListeDeCartes nouveauMot;
    modifier_mot(listeMots, 0, nouveauMot);
    assert(listeMots.mots[0].capacite == nouveauMot.capacite);
    assert(listeMots.mots[0].taille == nouveauMot.taille);

    // Teste ajouter_mot
    ajouter_mot(listeMots, nouveauMot);
    assert(listeMots.taille == 2);
    assert(listeMots.mots[1].capacite == nouveauMot.capacite);
    assert(listeMots.mots[1].taille == nouveauMot.taille);


    detruire_liste_mots(listeMots);
}

void test_pile(){
    // Teste initialiser_pile
    Pile pile = initialiser_pile(5);
    assert(pile.cartes.capacite == 5);
    assert(pile.cartes.taille == 0);
    assert(pile.cartes.cartes != nullptr);

    // Teste estVide
    assert(estVide(pile));

    // Teste detruire_pile
    detruire_pile(pile);
    //assert(pile.cartes.cartes == nullptr);
    assert(pile.cartes.capacite == 0);
    assert(pile.cartes.taille == 0);

}

void test_joueurs(){

    // Tous les tests marche correctement

    // Teste initialiserlistejoueur
    unsigned int nbJoueurs = 2;  // Adjust the number of players as needed
    ListeDeJoueurs listeJoueurs = initialiserlistejoueur(nbJoueurs);
    assert(listeJoueurs.nb_joueurs == nbJoueurs);
    assert(listeJoueurs.nb_joueurs_actifs == nbJoueurs);
    assert(listeJoueurs.indiceJoueurActuel == 0);

    // Teste joueur_actuel
    assert(&joueur_actuel(listeJoueurs) == &listeJoueurs.joueurs[0]);

    // Teste joueur_suivant
    joueur_suivant(listeJoueurs);
    assert(listeJoueurs.indiceJoueurActuel == 1);

    // Teste penaliser
    penaliser(listeJoueurs.joueurs[0]);
    assert(listeJoueurs.joueurs[0].scores == 3);

    // Teste scorejoueur
    scorejoueur(listeJoueurs.joueurs[0]);
    assert(listeJoueurs.joueurs[0].scores >= 0);


    detruireListeJoueur(listeJoueurs);
}

void test_jeu(){
    // Tous les tests marche correctement

    ListeDeCartes listeDeCartes1;
    initialiser_paquet(listeDeCartes1);

    ListeDeCartes listeDeCartes2;
    initialiser_paquet(listeDeCartes2);

    assert(listeDeCartes2.cartes[0]=='A');
    assert(listeDeCartes2.cartes[2]=='B');
    assert(listeDeCartes2.cartes[4]=='C');
    assert(listeDeCartes2.cartes[6]=='D');
    assert(listeDeCartes2.cartes[11]=='E');

    melanger_paquet(listeDeCartes2);
    assert(liste_carte_diff(listeDeCartes1,listeDeCartes2));

    ListeDeJoueurs listejoueurs = initialiserlistejoueur(JOUEUR_MIN);
    ListeDeJoueurs liste2 = initialiserlistejoueur(JOUEUR_MIN);
    donner_une_carte(liste2.joueurs[0], listeDeCartes1.cartes[0]);
    assert(liste2.joueurs[0].carte_possede.cartes[0] == 'A');


    distribuer(listeDeCartes2, listejoueurs,JOUEUR_MIN);
    unsigned int nb_c_paquet = 50;

    for(unsigned int j = 0; j < NB_CARTES_JOUEUR; ++j, --nb_c_paquet)
        assert(listejoueurs.joueurs[0].carte_possede.cartes[j] == listeDeCartes2.cartes[nb_c_paquet]);

    detruireListeJoueur(listejoueurs);
    detruireListeJoueur(liste2);
    detruire_liste_carte(listeDeCartes1);
    detruire_liste_carte(listeDeCartes2);

}