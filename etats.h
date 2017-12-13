#ifndef ETATS_H
#define ETATS_H

#include "elements.h"
#include "terrains.h"

namespace Etats {
   // EXPLORE signifie qu'il est encore en train de se déplacer
   enum EtatsChercheur { EXPLORE, MORT, NOYE, PERDU, RICHE };
}

/**
* Le chercheur meurt lorsqu'il fait plus de pas que toutes les cases réunies de la carte.
* @param nbrePas : on a besoin de savoir combien de pas il a fait pour comparer avec
 * le nombre de pas maximum qu'il peut faire.
* @return true si ses pas sont supérieurs aux pas maximum, autrement false.
*/
bool estMort(int nbrePas);


/**
* Le chercheur décède lorsqu'il touche de l'eau d'un des trois lacs.
* @param chercheur : on a besoin de la position x et y du chercheur.
* @param lacs : on a besoin de la position x et y des lacs.
* @param numChercheur : on a besoin de savoir de quel chercheur on parle
* @return si la distance entre le chercheur et le centre du lac est plus petite que le rayon du lac,
 *  ça veut dire qu'il est a l'intérieur du lac et va return la valeur true
*/
bool estDansLac(int chercheurs[][Elements::NB_PROPRIETES],
        int lacs[][Terrains::NB_PROPRIETES], size_t numChercheur);  
   
/**
* Le chercheur est perdu quand il sort de la carte
* @param chercheur : on a besoin de la position x et y du chercheur.
* @param numChercheur : on a besoin de savoir de quel chercheur on parle
* @return il va return true si l'élement x ou y du chercheur n'est plus dans la carte.
*/
bool estPerdu(int chercheurs[][Elements::NB_PROPRIETES], size_t numChercheur);

/**
* Le chercheur est riche lorsqu'il trouve le tresor
* @param chercheur : on a besoin de la position x et y du chercheur.
* @param tresor : on a besoin de la position x et y du tresor.
* @param numChercheur : on a besoin de savoir de quel chercheur on parle
* @return on va vérifier si les valeurs x et y sont égale a celles du tresor, si oui il va
 * returner true.
*/
bool estRiche(int chercheurs[][Elements::NB_PROPRIETES],
            int tresors[][Elements::NB_PROPRIETES],
            size_t numChercheur);


#endif /* ETATS_H */

