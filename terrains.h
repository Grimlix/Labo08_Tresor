#ifndef TERRAINS_H
#define TERRAINS_H

#include "carte.h"

namespace Terrains {
   enum Proprietes { type, x, y, rayon };
   
   const int NB_PROPRIETES = sizeof(Proprietes);
}

void positionerTerrains(int carte[HAUTEUR][LARGEUR], int elements[][Terrains::NB_PROPRIETES], const size_t nbElements);
   
void definirTypeTerrains(int terrains[][Terrains::NB_PROPRIETES], const size_t nbTerrains, const int type);


#endif /* TERRAINS_H */
