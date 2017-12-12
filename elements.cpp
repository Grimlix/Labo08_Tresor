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
   
   void bouger(int carte[HAUTEUR][LARGEUR], int positionChercheur[][NB_PROPRIETES]){

         int directionAleatoire = nombreAleatoire(3, 0);
         std::cout << directionAleatoire << std::endl;
         
         int anciennePositionX = positionChercheur[0][Proprietes::x];
         int anciennePositionY = positionChercheur[0][Proprietes::y];
         
         if(directionAleatoire == 0){
            positionChercheur[0][Proprietes::y] -= 1;
         }
         else if (directionAleatoire == 1){
            positionChercheur[0][Proprietes::y] += 1;
         }
         else if (directionAleatoire == 2){
            positionChercheur[0][Proprietes::x] -= 1;
         }
         else if (directionAleatoire == 3){
            positionChercheur[0][Proprietes::x] += 1;
         }
         
         remplacerCase(carte, positionChercheur[0][Proprietes::x] , positionChercheur[0][Proprietes::y],
                 positionChercheur[0][Proprietes::type]);
         
         remplacerCase(carte, anciennePositionX, anciennePositionY, Carte::TypeCase::VIDE);

   }
   
   void definirType(int elements[][NB_PROPRIETES], const size_t nbElements, const int type) {
      for(size_t element = 0; element < nbElements; ++element) {
         elements[element][Proprietes::type] = type;
      }
   }
}