/*


#include "etats.h"
#include "terrains.h"
#include "carte.h"

#include <cmath>


bool estMort (int nbrePas){ 
   const int pasMaximum = HAUTEUR * LARGEUR;
   if (nbrePas > pasMaximum){
      std::cout << "Le chercheur est mort de faim" << std::endl;
      return true;
   }
   else{
      return false;
   } 
}

bool estDansLac(int positionChercheur[NB_CHERCHEURS][Elements::NB_PROPRIETES], int positionLacs[NB_LACS][Terrains::NB_PROPRIETES]){
   
   int x = positionChercheur[NB_CHERCHEURS][Elements::Proprietes::x];
   int y = positionChercheur[NB_CHERCHEURS][Elements::Proprietes::y];
   int centreX = positionLacs[NB_LACS][Terrains::Proprietes::x];
   int centreY = positionLacs[NB_LACS][Terrains::Proprietes::y];
   int rayon = positionLacs[NB_LACS][Terrains::Proprietes::rayon];
   
   if(pow((x-centreX),2)+pow((y-centreY),2) <= rayon*rayon){
      return true;
   }
   else {
      return false;
   }
}   
   
bool estPerdu(int positionChercheur[NB_CHERCHEURS][Elements::NB_PROPRIETES], const int HAUTEUR, const int LARGEUR){
   const int largeurMin = 0;
   const int longueurMin = 0;
   int longueurMax = HAUTEUR;
   int largeurMax = LARGEUR;
   
   int x = positionChercheur[NB_CHERCHEURS][Elements::Proprietes::x];
   int y = positionChercheur[NB_CHERCHEURS][Elements::Proprietes::y];
   
   if(x < largeurMin || x > largeurMax || y < longueurMin || y > longueurMax){
      return true;
   }
   else {
      return false;
   }
}

bool aGagne(int positionChercheur[NB_CHERCHEURS][Elements::NB_PROPRIETES],
            int positionTresor[NB_TRESORS][Elements::NB_PROPRIETES]){
   
   int xC = positionChercheur[NB_CHERCHEURS][Elements::Proprietes::x];
   int yC = positionChercheur[NB_CHERCHEURS][Elements::Proprietes::y];
   
   int xT = positionTresor[NB_TRESORS][Elements::Proprietes::x];
   int yT = positionTresor[NB_TRESORS][Elements::Proprietes::y];
   
   
   if(xC == xT && yC == yT){
      return true;
   }
   else {
      return false;
   }
}

*/






