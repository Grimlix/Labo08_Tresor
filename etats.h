#ifndef ETATS_H
#define ETATS_H

#include "elements.h"
#include "terrains.h"

namespace Etats {
   enum EtatsChercheur { EXPLORE, MORT, NOYE, PERDU, RICHE };
}

bool estMort(int nbrePas);

bool estDansLac(int chercheurs[][Elements::NB_PROPRIETES],
        int lacs[][Terrains::NB_PROPRIETES], size_t numChercheur = 0);  
   
bool estPerdu(int chercheurs[][Elements::NB_PROPRIETES], size_t numChercheur = 0);

bool estRiche(int chercheurs[][Elements::NB_PROPRIETES],
            int tresors[][Elements::NB_PROPRIETES],
            size_t numChercheur = 0);


#endif /* ETATS_H */

