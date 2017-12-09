#ifndef TERRAINS_H
#define TERRAINS_H

#include "carte.h" // LARGEUR, HAUTEUR, aleatoire.h

namespace Terrains {
   enum Proprietes { type, x, y, rayon };
   
   const int NB_PROPRIETES = sizeof(Proprietes);
   
   void positioner(int carte[HAUTEUR][LARGEUR], int elements[][NB_PROPRIETES], const size_t nbElements);
   
   void definirType(int terrains[][NB_PROPRIETES], const size_t nbTerrains, const int type);
}

#endif /* TERRAINS_H */

