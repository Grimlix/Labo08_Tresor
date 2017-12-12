#ifndef CARTE_H
#define CARTE_H

#include <iostream> // size_t

// 20 * 20 pour tester mais normalement 100, 200
const size_t LARGEUR   = 20;
const size_t HAUTEUR   = 20;
const size_t NB_ESSAIS = 10000;

const size_t NB_CHERCHEURS = NB_ESSAIS;
const size_t NB_TRESORS = 1;
const size_t NB_LACS = 3;

namespace Carte {
   enum TypeCase { CHERCHEUR, TRESOR, LAC, VIDE };
   enum Direction { NORD, SUD, OUEST, EST };
}

void creerCarte(int carte[HAUTEUR][LARGEUR]);

void viderCarte(int carte[HAUTEUR][LARGEUR]);

bool remplacerCase(int carte[HAUTEUR][LARGEUR], const int x, const int y, const int type);

void afficherCarte(const int carte[HAUTEUR][LARGEUR]);

int distancePoint(const int& lx, const int& ly, const int& rx, const int& ry);

void creerDisque(int carte[HAUTEUR][LARGEUR], const size_t centreX, const size_t centreY, const int type, const int rayon);

#endif /* CARTE_H */
