#include "aleatoire.h"
#include "terrains.h" // nombreAleatoire
#include "elements.h"

#include <cmath>

void positionerElements(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], const size_t nbElements) {
   for(size_t element = 0; element < nbElements; ++element) {
      positionerElement(carte, elements, element);
   }
}

void positionerElement(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], int numElement) {
   int x;
   int y;

   do {
      x = nombreAleatoire(LARGEUR - 1, 0);
      y = nombreAleatoire(HAUTEUR - 1, 0);
   } while(not(carte[y][x] == Carte::TypeCase::VIDE));

   elements[numElement][Elements::Proprietes::x] = x;
   elements[numElement][Elements::Proprietes::y] = y;

   remplacerCase(carte, x, y, elements[numElement][Elements::Proprietes::type]);
}

int bougerElements(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], int numElement, Carte::Direction direction) {
   // remplacer la case où l'élément était par du vide
   remplacerCase(carte, elements[numElement][Elements::Proprietes::x] , elements[0][Elements::Proprietes::y], Carte::TypeCase::VIDE);

   switch(direction) {
      case Carte::Direction::NORD :
         elements[numElement][Elements::Proprietes::y] -= 1;
         break;
      case Carte::Direction::SUD :
         elements[numElement][Elements::Proprietes::y] += 1;
         break;
      case Carte::Direction::OUEST :
         elements[numElement][Elements::Proprietes::x] -= 1;
         break;
      case Carte::Direction::EST :
         elements[numElement][Elements::Proprietes::x] += 1;
         break;
   }

   // remplacer la case où est maintenant l'élément et si ce n'est pas possible ne rien changeer à la carte
   remplacerCase(carte, elements[numElement][Elements::Proprietes::x] , elements[0][Elements::Proprietes::y], elements[numElement][Elements::Proprietes::type]);

   return carte[elements[numElement][Elements::Proprietes::y]][elements[numElement][Elements::Proprietes::x]];
}

int bougerAleatoirementElements(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], const int numElement) {
   int directionAleatoire = nombreAleatoire(sizeof(Carte::Direction));

   return bougerElements(carte, elements, numElement, Carte::Direction(directionAleatoire));
}

void definirTypeElements(int elements[][Elements::NB_PROPRIETES], const size_t nbElements, const int type) {
   for(size_t element = 0; element < nbElements; ++element) {
      elements[element][Elements::Proprietes::type] = type;
   }
}