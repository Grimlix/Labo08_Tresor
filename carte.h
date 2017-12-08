#ifndef CARTE_H
#define CARTE_H

#include <iostream>
#include "elements.h" // NB_PROPRIETES

// 20 * 20 pour tester mais normalement 100, 200
const size_t LARGEUR = 20;
const size_t HAUTEUR = 20;

const size_t NB_CHERCHEURS = 1;
const size_t NB_TRESORS = 1;
const size_t NB_LACS = 3;

namespace Carte {
   enum Elements { CHERCHEUR, TRESOR, LAC, VIDE };
}

void creerCarte(int carte[HAUTEUR][LARGEUR]);

void viderCarte(int carte[HAUTEUR][LARGEUR]);

void definirTypeElements(int elements[][NB_PROPRIETES], size_t nbElements, const int type);

void remplacerCase(int carte[HAUTEUR][LARGEUR], const int x, const int y, const int type);

void afficherCarte(const int carte[HAUTEUR][LARGEUR]);

int distancePoint(const int& lx, const int& ly, const int& rx, const int& ry);

//void creerDisqueElement(double rayon);

#endif /* CARTE_H */
