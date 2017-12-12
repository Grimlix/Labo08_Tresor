#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "carte.h" // LARGEUR, HAUTEUR
#include "terrains.h"

namespace Elements {
   enum Proprietes { type, x, y, etat };
   
   const int NB_PROPRIETES = sizeof(Proprietes);
}

void positionerElements(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], const size_t nbElements);

void positionerElement(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], int numElement);

int bougerElements(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], const int numElement, Carte::Direction direction);

int bougerAleatoirementElements(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], const int numElement = 0);

void definirTypeElements(int elements[][Elements::NB_PROPRIETES], const size_t nbElements, const int type);


#endif /* ELEMENTS_H */
