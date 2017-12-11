#ifndef ETATS_H
#define ETATS_H

#include "elements.h"



bool estMort (int nbrePas);

bool estDansLac(int positionChercheur[NB_CHERCHEURS][Elements::NB_PROPRIETES], int positionsLacs[NB_LACS][Terrains::NB_PROPRIETES]);  
   
bool estPerdu(int positionChercheur[NB_CHERCHEURS][Elements::NB_PROPRIETES], const int HAUTEUR, const int LARGEUR);

bool aGagne(int positionChercheur[NB_CHERCHEURS][Elements::NB_PROPRIETES], int positionTresor[NB_TRESORS][Elements::NB_PROPRIETES]);


#endif /* ETATS_H */

