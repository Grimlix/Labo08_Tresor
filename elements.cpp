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
   
   void Elements::bouger(int carte[HAUTEUR][LARGEUR], int positionChercheur[][Elements::NB_PROPRIETES], int positionLacs[][Terrains::NB_PROPRIETES],
                         int positionTresor[][Elements::NB_PROPRIETES]){
      bool etat = true; //false;
      int pas = 0;
      do{
         int directionAleatoire = nombreAleatoire(3, 0);
         std::cout << directionAleatoire << std::endl;
         if(directionAleatoire == 0){
            positionChercheur[0][Elements::Proprietes::y] -= 1;
         }
         else if (directionAleatoire == 1){
            positionChercheur[0][Elements::Proprietes::y] += 1;
         }
         else if (directionAleatoire == 2){
            positionChercheur[0][Elements::Proprietes::x] -= 1;
         }
         else if (directionAleatoire == 3){
            positionChercheur[0][Elements::Proprietes::x] += 1;
         }
         std::cout << positionChercheur[0][Elements::Proprietes::x] << std::endl;
         pas++;
         remplacerCase(carte, positionChercheur[0][Elements::Proprietes::x] , positionChercheur[0][Elements::Proprietes::y], positionChercheur[0][Elements::Proprietes::type]);
         /*
         etat = estMort(pas);
         etat = estDansLac(positionChercheur[NB_CHERCHEURS][Elements::NB_PROPRIETES], positionLacs[NB_LACS][Terrains::NB_PROPRIETES]);
         etat = aGagne(positionChercheur[NB_CHERCHEURS][Elements::NB_PROPRIETES], positionTresor[NB_TRESORS][Elements::NB_PROPRIETES]);
         etat = estPerdu(positionChercheur[NB_CHERCHEURS][Elements::NB_PROPRIETES], HAUTEUR, LARGEUR);
          */ 
      }while (etat == false);
   }
   
   void definirType(int elements[][NB_PROPRIETES], const size_t nbElements, const int type) {
      for(size_t element = 0; element < nbElements; ++element) {
         elements[element][Proprietes::type] = type;
      }
   }
}

   /*bool estMort (int nbrePas){ 
      const int pasMaximum = HAUTEUR * LARGEUR;
      if (nbrePas > pasMaximum){
         std::cout << "Le chercheur est mort de faim" << std::endl;
         return true;
      }
      else{
         return false;
      } 
   }

   bool estDansLac(int positionChercheur[NB_CHERCHEURS][NB_PROPRIETES], int positionLacs[NB_LACS][Terrains::NB_PROPRIETES]){

      int x = positionChercheur[NB_CHERCHEURS][Proprietes::x];
      int y = positionChercheur[NB_CHERCHEURS][Proprietes::y];
      int centreX = positionLacs[NB_LACS][Proprietes::x];
      int centreY = positionLacs[NB_LACS][Proprietes::y];
      int rayon = positionLacs[NB_LACS][Proprietes::rayon];

      if(pow((x-centreX),2)+pow((y-centreY),2) <= rayon*rayon){
         return true;
      }
      else {
         return false;
      }
   }   

   bool estPerdu(int positionChercheur[NB_CHERCHEURS][NB_PROPRIETES], const int HAUTEUR, const int LARGEUR){
      const int largeurMin = 0;
      const int longueurMin = 0;
      int longueurMax = HAUTEUR;
      int largeurMax = LARGEUR;

      int x = positionChercheur[NB_CHERCHEURS][Proprietes::x];
      int y = positionChercheur[NB_CHERCHEURS][Proprietes::y];

      if(x < largeurMin || x > largeurMax || y < longueurMin || y > longueurMax){
         return true;
      }
      else {
         return false;
      }
   }

   bool aGagne(int positionChercheur[NB_CHERCHEURS][NB_PROPRIETES],
               int positionTresor[NB_TRESORS][NB_PROPRIETES]){

      int xC = positionChercheur[NB_CHERCHEURS][Proprietes::x];
      int yC = positionChercheur[NB_CHERCHEURS][Proprietes::y];

      int xT = positionTresor[NB_TRESORS][Proprietes::x];
      int yT = positionTresor[NB_TRESORS][Proprietes::y];


      if(xC == xT && yC == yT){
         return true;
      }
      else {
         return false;
      }
   }*/
