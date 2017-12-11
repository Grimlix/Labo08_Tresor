#ifndef ETATS_H
#define ETATS_H

#include "elements.h"

bool estMort (int nbrePas);

bool estDansLac(int positionChercheur[][Elements::NB_PROPRIETES], int positionLacs[][Terrains::NB_PROPRIETES]);  
   
bool estPerdu(int positionChercheur[][Elements::NB_PROPRIETES]);

bool aGagne(int positionChercheur[][Elements::NB_PROPRIETES], int positionTresor[][Elements::NB_PROPRIETES]);


#endif /* ETATS_H */

