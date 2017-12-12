#include "etats.h"
#include "aleatoire.h"
#include "carte.h"

#include <cstdlib>
#include <cmath>

using namespace std;

bool estMort(int nbrePas) { 
   const int pasMaximum = HAUTEUR * LARGEUR;
   
   return(nbrePas > pasMaximum);
}

bool estDansLac(int chercheurs[][Elements::NB_PROPRIETES],
        int lacs[][Terrains::NB_PROPRIETES], size_t numChercheur) {

   int x = chercheurs[numChercheur][Elements::Proprietes::x];
   int y = chercheurs[numChercheur][Elements::Proprietes::y];
   int centreLacX;
   int centreLacY;
   int rayonLac;

   for(int lac = 0; lac < NB_LACS; ++lac) {
      centreLacX = lacs[lac][Elements::Proprietes::x];
      centreLacY = lacs[lac][Elements::Proprietes::y];
      rayonLac = lacs[lac][Terrains::Proprietes::rayon];
      
      // si le chercheur est dans le rayon d'un lac il s'est noyé
      if(distancePoint(x, y, centreLacX, centreLacY) <= rayonLac);
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
   
   return false;
}   

bool estRiche(int chercheurs[][Elements::NB_PROPRIETES],
            int tresors[][Elements::NB_PROPRIETES],
            size_t numChercheur) {

   int xC = chercheurs[numChercheur][Elements::Proprietes::x];
   int yC = chercheurs[numChercheur][Elements::Proprietes::y];

   int xT = tresors[numChercheur][Elements::Proprietes::x];
   int yT = tresors[numChercheur][Elements::Proprietes::y];
   
   return(xC == xT && yC == yT);
}