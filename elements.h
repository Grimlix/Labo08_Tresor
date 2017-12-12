#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "carte.h" // LARGEUR, HAUTEUR
#include "terrains.h"

namespace Elements {
   enum Proprietes { type, x, y };
   
   const int NB_PROPRIETES = sizeof(Proprietes);
}

void positionerElements(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], const size_t nbElements);

int bougerElements(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], const int numElement, Carte::Direction direction);

int bougerAleatoirementElements(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], const int numElement);

void definirTypeElements(int elements[][Elements::NB_PROPRIETES], const size_t nbElements, const int type);


#endif /* ELEMENTS_H */
