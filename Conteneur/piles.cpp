#include "piles.h"



void pileDeCartes(Pile& p, const ListeDeCartes& listeDeCarte) {
    p.cartes = listeDeCarte;
}

Pile initialiser_pile(unsigned int capa_initiale){
    Pile p;
    
    p.cartes = initialiser_liste_carte(capa_initiale);
    
    return p;
}
bool estVide(const Pile& p)
{
    return p.cartes.taille == 0;
}

void detruire_pile(Pile& p)
{
    detruire_liste_carte(p.cartes);
}

Carte sommet(Pile& p)
{
    return lire(p.cartes, p.cartes.taille - 1);
}

void empiler(Pile& p, Carte it)
{
    ajouter(p.cartes, it);
}

Carte depiler(Pile& p)
{
    return retirer_derniere_cartes(p.cartes);
}