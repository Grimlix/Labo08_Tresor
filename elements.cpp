#include "aleatoire.h"
#include "terrains.h" // nombreAleatoire
#include "elements.h"

#include <cmath>

namespace Elements {
   void positioner(int carte[HAUTEUR][LARGEUR], int elements[][NB_PROPRIETES], const size_t nbElements) {
      for(size_t element = 0; element < nbElements; ++element) {
         int x;
         int y;

         do {
            x = nombreAleatoire(LARGEUR - 1, 0);
            y = nombreAleatoire(HAUTEUR - 1, 0);
         } while(not(carte[y][x] == Carte::TypeCase::VIDE));

         elements[element][Proprietes::x] = x;
         elements[element][Proprietes::y] = y;

         remplacerCase(carte, x, y, elements[element][Proprietes::type]);
      }
   }

   int bouger(int carte[HAUTEUR][LARGEUR], int elements[][NB_PROPRIETES], int numElement, Carte::Direction direction) {
      // remplacer la case où l'élément était par du vide
      remplacerCase(carte, elements[numElement][Proprietes::x] , elements[0][Proprietes::y], Carte::TypeCase::VIDE);
      
      switch(direction) {
         case Carte::Direction::NORD :
            elements[numElement][Proprietes::y] -= 1;
            break;
         case Carte::Direction::SUD :
            elements[numElement][Proprietes::y] += 1;
            break;
         case Carte::Direction::OUEST :
            elements[numElement][Proprietes::x] -= 1;
            break;
         case Carte::Direction::EST :
            elements[numElement][Proprietes::x] += 1;
            break;
      }

      // remplacer la case où est maintenant l'élément et si ce n'est pas possible ne rien changeer à la carte
      remplacerCase(carte, elements[numElement][Proprietes::x] , elements[0][Proprietes::y], elements[numElement][Proprietes::type]);
      
      return carte[elements[numElement][Proprietes::y]][elements[numElement][Proprietes::x]];
   }

   int bougerAleatoirement(int carte[HAUTEUR][LARGEUR], int elements[][NB_PROPRIETES], const int numElement) {
      int directionAleatoire = nombreAleatoire(sizeof(Carte::Direction));
      
      return bouger(carte, elements, numElement, Carte::Direction(directionAleatoire));
   }
   
   void definirType(int elements[][NB_PROPRIETES], const size_t nbElements, const int type) {
      for(size_t element = 0; element < nbElements; ++element) {
         elements[element][Proprietes::type] = type;
      }
   }
}
