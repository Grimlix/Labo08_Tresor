#include "elements.h"
#include "etats.h"
#include "terrains.h"
#include "carte.h"
#include "aleatoire.h"
#include <cstdlib>
#include <iostream>
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
      int rayon = positionLacs[0][Elements::Proprietes::rayon];

      if(pow((x-centreX),2)+pow((y-centreY),2) <= rayon*rayon){
         return true;
      }
      else {
         return false;
      }
   }   

   bool estPerdu(int positionChercheur[][NB_PROPRIETES]){
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

   bool aGagne(int positionChercheur[][Elements::NB_PROPRIETES],
               int positionTresor[][Elements::NB_PROPRIETES]){

      int xC = positionChercheur[0][Elements::Proprietes::x];
      int yC = positionChercheur[0][Elements::Proprietes::y];

      int xT = positionTresor[0][Elements::Proprietes::x];
      int yT = positionTresor[0][Elements::Proprietes::y];


      if(xC == xT && yC == yT){
         return true;
      }
      else {
         return false;
      }
   }