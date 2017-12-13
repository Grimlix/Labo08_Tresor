#ifndef ELEMENTS_H
#define ELEMENTS_H

#include "carte.h" // LARGEUR, HAUTEUR

namespace Elements {
   enum Proprietes { type, x, y, etat };
   
   const int NB_PROPRIETES = sizeof(Proprietes);
}

/**
 * place aléatoirement les éléments d'un tableau élément sur la carte
 * @param carte      la carte
 * @param elements   le tableau d'élément
 * @param nbElements le nombre d'élément
 */
void positionerElements(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], const size_t nbElements);

/**
 * place aléatoirement un élément d'un tableau sur la carte
 * @param carte      la carte
 * @param elements   le tableau d'élément contenant l'élément
 * @param numElement la position de l'élément dans le tableau d'élément
 */
void positionerElement(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], const size_t numElement);

/**
 * modifie les coordonées d'un élément par rapport à une direction donnée
 * @param carte       la carte
 * @param elements    le tableau d'élément contenant l'élément
 * @param numElement  la position de l'élément dans le tableau d'élément
 * @param direction   la direction donnée
 */
void bougerElement(int elements[][Elements::NB_PROPRIETES], const size_t numElement, Carte::Direction direction);

/**
 * modifie les coordonées d'un élément
 * par rapport à une direction determinée aléatoirement
 * @param elements    le tableau d'élément contenant l'élément
 * @param numElement  la position de l'élément dans le tableau d'élément
 */
void bougerAleatoirementElement(int elements[][Elements::NB_PROPRIETES], const size_t numElement = 0);

/**
 * prend un tableau d'élément et change le type
 * pour le type voulu pour tout ce tableau
 * @param elements    le tableau d'élément
 * @param nbElements  le nombre d'élément
 * @param type        le type désiré
 */
void definirTypeElements(int elements[][Elements::NB_PROPRIETES], const size_t nbElements, const int type);


#endif /* ELEMENTS_H */
