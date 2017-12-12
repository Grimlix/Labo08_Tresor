#include "etats.h"
#include "aleatoire.h"
#include "carte.h"

#include <cstdlib>
#include <cmath>

using namespace std;


// Le chercheur meurt lorsqu'il fait plus de pas que
// toutes les cases réunies de la carte. C'est pourquoi
// on va vérifier que ses pas soient plus petit que la 
// hauteur et la largeur de la carte
bool estMort(int nbrePas) { 
   const int pasMaximum = HAUTEUR * LARGEUR;
   
   return (nbrePas > pasMaximum);
}

// Le chercheur decède lorsqu'il touche de l'eau, c'est pourquoi
// on va vérifier que c'est coordonnées n'approche pas le rayon
// d'un des lacs posés aléatoirement
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
      if(distancePoint(x, y, centreLacX, centreLacY) <= rayonLac)
         return true;
   }
   
   return false;
} 

// Le chercheur est perdu quand il sort de la carte,
// on va alors vérifier que ses coordonnées x et y ne depasse pas
// les limites de la carte
bool estPerdu(int positionChercheur[][Elements::NB_PROPRIETES], size_t numChercheur) {
   const int largeurMin = 0;
   const int longueurMin = 0;
   int longueurMax = LARGEUR;
   int largeurMax = HAUTEUR;

   int x = positionChercheur[numChercheur][Elements::Proprietes::x];
   int y = positionChercheur[numChercheur][Elements::Proprietes::y];

   return (x < largeurMin || x > largeurMax || y < longueurMin || y > longueurMax);
}

// Le chercheur est riche lorsqu'il trouve le tresor,
// on a vérifier que la valeur x ET la valeur y du chercheur
// soient égales à celles du tresor posées aléatoirement
bool estRiche(int chercheurs[][Elements::NB_PROPRIETES],
            int tresors[][Elements::NB_PROPRIETES],
            size_t numChercheur) {

   int xC = chercheurs[numChercheur][Elements::Proprietes::x];
   int yC = chercheurs[numChercheur][Elements::Proprietes::y];
 
   for(int tresor = 0; tresor < NB_TRESORS; ++tresor) {
      int xT = tresors[tresor][Elements::Proprietes::x];
      int yT = tresors[tresor][Elements::Proprietes::y];
      
      if(xC == xT && yC == yT)
         return true;
   }

   return false;
}