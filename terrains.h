#ifndef TERRAINS_H
#define TERRAINS_H

#include "carte.h"

namespace Terrains {
   enum Proprietes { type, x, y, rayon };
   
   const int NB_PROPRIETES = sizeof(Proprietes);
}

/**
 * place aléatoirement les terrains d'un tableau de terrain sur la carte
 * @param carte       la carte
 * @param terrains    le tableau de terrain
 * @param nbTerrains  le nombre de terrain
 */
void positionerTerrains(int carte[HAUTEUR][LARGEUR], int terrains[][Terrains::NB_PROPRIETES], const size_t nbTerrains);
   
/**
 * prend un tableau de terrain et change le type
 * pour le type voulu pour tout ce tableau
 * @param terrains    le tableau de terrain
 * @param nbTerrains  le nombre de terrain
 * @param type        le type désiré
 */
void definirTypeTerrains(int terrains[][Terrains::NB_PROPRIETES], const size_t nbTerrains, const int type);


#endif /* TERRAINS_H */
