#ifndef CARTE_H
#define CARTE_H

#include <iostream> // size_t

// 20 * 20 pour tester mais normalement 100, 200
const size_t LARGEUR   = 20;
const size_t HAUTEUR   = 20;
const size_t NB_ESSAIS = 100000;

const size_t NB_TRESORS = 1;
const size_t NB_LACS = 3;

namespace Carte {
   enum TypeCase { CHERCHEUR, TRESOR, LAC, VIDE };

   enum Direction { NORD, SUD, OUEST, EST };
}

/**
 * effectue la simulation
 * @param carte              la carte
 * @param pasTotaux          le nombre de pas totaux effectué dans la simulation
 * @param nombreDeVictoires  le nombre de trésors trouvés par les chercheurs
 * @param nbEssai            le nombre d'essai à effectuer
 */
void simulation(int carte[HAUTEUR][LARGEUR], int& pasTotaux, int& nombreDeVictoires, int nbEssai);

/**
 * définit tout les cases de la carte à vide
 * @param carte
 */
void viderCarte(int carte[HAUTEUR][LARGEUR]);

/**
 * remplace une case de la case en s'assurant que la case existe
 * @param carte  la carte
 * @param x      la coordonnée x de la case
 * @param y      la coordonnée y de la case
 * @param type   le type à placer
 * @return si l'opération a réussi
 */
bool remplacerCase(int carte[HAUTEUR][LARGEUR], const int x, const int y, const int type);

/**
 * affiche une représentation ASCII de la carte
 * @param carte  la carte
 */
void afficherCarte(const int carte[HAUTEUR][LARGEUR]);

/**
 * calcule la distance entre 2 points
 * @param lx  le premier x
 * @param ly  le premier y
 * @param rx  le deuxième x
 * @param ry  le deuxième y
 * @return    la distance
 */
int distancePoint(const int& lx, const int& ly, const int& rx, const int& ry);

/**
 * créer un disque de terrain et place ce terrain sur la carte
 * @param carte    la carte
 * @param centreX  la coordonnée x du centre du terrain
 * @param centreY  la coordonnée y du centre du terrain
 * @param type     le type du terrain
 * @param rayon    le rayon du disque de terrain
 */
void creerDisque(int carte[HAUTEUR][LARGEUR], const size_t centreX, const size_t centreY, const int type, const int rayon);

#endif /* CARTE_H */
