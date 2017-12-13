#include "etats.h"
#include "aleatoire.h"
#include "carte.h"

#include <cstdlib>

bool estMort(int nbrePas) { 
   const int pasMaximum = HAUTEUR * LARGEUR;
   
   return (nbrePas > pasMaximum);
}

bool estDansLac(int chercheurs[][Elements::NB_PROPRIETES],
        int lacs[][Terrains::NB_PROPRIETES], size_t numChercheur) {

   // on configure les variables x et y actuelles du chercheur
   int x = chercheurs[numChercheur][Elements::Proprietes::x];
   int y = chercheurs[numChercheur][Elements::Proprietes::y];
   int centreLacX;
   int centreLacY;
   int rayonLac;

   // vu qu'il y a plusieurs lacs, il faut vérifier avec les 3 lacs.
   // on configure comme pour le chercheur, les variables x et y au centre du lac
   for(int lac = 0; lac < NB_LACS; ++lac) {
      centreLacX = lacs[lac][Elements::Proprietes::x];
      centreLacY = lacs[lac][Elements::Proprietes::y];
      rayonLac = lacs[lac][Terrains::Proprietes::rayon];
      
      // si le chercheur est dans le rayon d'un lac il s'est noyé
      if(distancePoint(x, y, centreLacX, centreLacY) <= rayonLac)
         return true;
   }
   return false;
} 

bool estPerdu(int positionChercheur[][Elements::NB_PROPRIETES], size_t numChercheur) {
   const int largeurMin = 0;
   const int longueurMin = 0;
   int longueurMax = LARGEUR;
   int largeurMax = HAUTEUR;

   int x = positionChercheur[numChercheur][Elements::Proprietes::x];
   int y = positionChercheur[numChercheur][Elements::Proprietes::y];

   return (x < largeurMin || x > largeurMax || y < longueurMin || y > longueurMax);
}

bool estRiche(int chercheurs[][Elements::NB_PROPRIETES],
            int tresors[][Elements::NB_PROPRIETES],
            size_t numChercheur) {

   int xC = chercheurs[numChercheur][Elements::Proprietes::x];
   int yC = chercheurs[numChercheur][Elements::Proprietes::y];

   // on utilise que un tresor, mais si on voulait en rajouter il faudrait juste changer $
   // la variable NB_TRESORS
   for(int tresor = 0; tresor < NB_TRESORS; ++tresor) {
      int xT = tresors[tresor][Elements::Proprietes::x];
      int yT = tresors[tresor][Elements::Proprietes::y];
      
      if(xC == xT && yC == yT)
         return true;
   }

   return false;
}