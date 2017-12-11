#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "carte.h" // LARGEUR, HAUTEUR
#include "terrains.h"

namespace Elements {
   enum Proprietes { type, x, y };
   
   const int NB_PROPRIETES = sizeof(Proprietes);
   
   void positioner(int carte[HAUTEUR][LARGEUR], int elements[][NB_PROPRIETES], const size_t nbElements);
   
   int bouger(int carte[HAUTEUR][LARGEUR], int elements[][NB_PROPRIETES], const int numElement, Carte::Direction direction);
   
   int bougerAleatoirement(int carte[HAUTEUR][LARGEUR], int elements[][NB_PROPRIETES], const int numElement);
   
   void definirType(int elements[][NB_PROPRIETES], const size_t nbElements, const int type);

}

#endif /* ELEMENTS_H */
