#include "terrains.h"
#include "aleatoire.h" // nombreAleatoire

namespace Terrains {
   void positioner(int carte[HAUTEUR][LARGEUR], int terrains[][NB_PROPRIETES], const size_t nbTerrains) {
      for(size_t terrain = 0; terrain < nbTerrains; ++terrain) {
         int x;
         int y;
         int rayon;
         bool chevauche;

         do {
            x = nombreAleatoire(LARGEUR - 1, 0);
            y = nombreAleatoire(HAUTEUR - 1, 0);

            rayon = nombreAleatoire(((LARGEUR - 1) + (HAUTEUR - 1)) / (2 * nbTerrains), 1);

            // vérifier que les lacs ne se chevauchent pas
            for(int terrainPrecedent = terrain; terrainPrecedent-1 > 0; --terrainPrecedent) {
               int xPrecedent     = terrains[terrainPrecedent][Proprietes::x];
               int yPrecedent     = terrains[terrainPrecedent][Proprietes::y];
               int rayonPrecedent = terrains[terrainPrecedent][Proprietes::rayon];
               chevauche = (distancePoint(x, y, xPrecedent, yPrecedent) <= rayon + rayonPrecedent);
            }
         } while(not(carte[y][x] == Carte::TypeCase::VIDE) && chevauche);



         terrains[terrain][Proprietes::x] = x;
         terrains[terrain][Proprietes::y] = y;
         terrains[terrain][Proprietes::rayon] = rayon;

         creerDisque(carte, x, y, terrains[terrain][Proprietes::type], rayon);
      }
   }

   void definirType(int terrains[][NB_PROPRIETES], const size_t nbTerrains, const int type) {
      for(size_t terrain = 0; terrain < nbTerrains; ++terrain) {
         terrains[terrain][Proprietes::type] = type;
      }
   }
}