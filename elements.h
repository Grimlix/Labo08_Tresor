#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "carte.h" // LARGEUR, HAUTEUR
#include "terrains.h"

namespace Elements {
   enum Proprietes { type, x, y };
   
   const int NB_PROPRIETES = sizeof(Proprietes);
   
   void positioner(int carte[HAUTEUR][LARGEUR], int elements[][NB_PROPRIETES], const size_t nbElements);
   
   void bouger(int carte[HAUTEUR][LARGEUR], int positionChercheur[][Elements::NB_PROPRIETES], int positionLacs[NB_LACS][Terrains::NB_PROPRIETES],
                      int positionTresor[][Elements::NB_PROPRIETES]);
   
   void definirType(int elements[][NB_PROPRIETES], const size_t nbElements, const int type);
   
   bool estMort (int nbrePas);

   bool estDansLac(int positionChercheur[NB_CHERCHEURS][Elements::NB_PROPRIETES], int positionsLacs[NB_LACS][Terrains::NB_PROPRIETES]);  
   
   bool estPerdu(int positionChercheur[NB_CHERCHEURS][Elements::NB_PROPRIETES], const int HAUTEUR, const int LARGEUR);

   bool aGagne(int positionChercheur[NB_CHERCHEURS][Elements::NB_PROPRIETES], int positionTresor[NB_TRESORS][Elements::NB_PROPRIETES]);
}

#endif /* ELEMENTS_H */

