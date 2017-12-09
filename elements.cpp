#include "elements.h"
#include "aleatoire.h" // nombreAleatoire

void Elements::positioner(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], const size_t nbElements) {
   for(size_t element = 0; element < nbElements; ++element) {
      int x;
      int y;

      do {
         x = nombreAleatoire(LARGEUR - 1, 0);
         y = nombreAleatoire(HAUTEUR - 1, 0);
      } while(not(carte[y][x] == Carte::TypeCase::VIDE));

      elements[element][Elements::Proprietes::x] = x;
      elements[element][Elements::Proprietes::y] = y;

      remplacerCase(carte, x, y, elements[element][Elements::Proprietes::type]);
   }
}

void Elements::definirType(int elements[][Elements::NB_PROPRIETES], const size_t nbElements, const int type) {
   for(size_t element = 0; element < nbElements; ++element) {
      elements[element][Elements::Proprietes::type] = type;
   }
}