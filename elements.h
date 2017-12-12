#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "carte.h" // LARGEUR, HAUTEUR
#include "terrains.h"

namespace Elements {
   enum Proprietes { type, x, y };
   
   const int NB_PROPRIETES = sizeof(Proprietes);
   
   void positioner(int carte[HAUTEUR][LARGEUR], int elements[][NB_PROPRIETES], const size_t nbElements);
   
   void bouger(int carte[HAUTEUR][LARGEUR], int positionChercheur[][NB_PROPRIETES]);
   
   void definirType(int elements[][NB_PROPRIETES], const size_t nbElements, const int type);

}

#endif /* ELEMENTS_H */
