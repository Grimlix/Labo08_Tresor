#include "etats.h"
#include "aleatoire.h"
#include "carte.h"


#include <cstdlib>
#include <cmath>

using namespace std;


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

   bool estDansLac(int positionChercheur[][Elements::NB_PROPRIETES],
           int positionLacs[][Terrains::NB_PROPRIETES]){

      int x = positionChercheur[0][Elements::Proprietes::x];
      int y = positionChercheur[0][Elements::Proprietes::y];
      int centreX = positionLacs[0][Elements::Proprietes::x];
      int centreY = positionLacs[0][Elements::Proprietes::y];
      int rayon = positionLacs[0][Terrains::Proprietes::rayon];
      
//      char chercheur = Carte::TypeCase::CHERCHEUR;
//      char lac = Carte::TypeCase::LAC;
//      
//      if(bool estDansEau = creerDisque(carte, )){
//         std::cout << "Le chercheur s'est noye" << std::endl;
//         return true;  
//     }

      if(pow((x-centreX),2)+pow((y-centreY),2) <= rayon*rayon){
         std::cout << "Le chercheur s'est noye" << std::endl;
         return true; 
      }
      else {
         return false;
      }
   }   

   bool estPerdu(int positionChercheur[][Elements::NB_PROPRIETES]){
      const int largeurMin = 0;
      const int longueurMin = 0;
      int longueurMax = LARGEUR;
      int largeurMax = HAUTEUR;

      int x = positionChercheur[0][Elements::Proprietes::x];
      int y = positionChercheur[0][Elements::Proprietes::y];

      if(x < largeurMin || x > largeurMax || y < longueurMin || y > longueurMax){
         std::cout << "Le chercheur s'est perdu" << std::endl;
         return true;
      }
      else {
         return false;
      }
   }

   bool aGagne(int positionChercheur[][Elements::NB_PROPRIETES],
               int positionTresor[][Elements::NB_PROPRIETES]){

      int xC = positionChercheur[0][Elements::Proprietes::x];
      int yC = positionChercheur[0][Elements::Proprietes::y];

      int xT = positionTresor[0][Elements::Proprietes::x];
      int yT = positionTresor[0][Elements::Proprietes::y];


      if(xC == xT && yC == yT){
         std::cout << "Le chercheur a trouve le tresor" << std::endl;
         return true;
      }
      else {
         return false;
      }
   }