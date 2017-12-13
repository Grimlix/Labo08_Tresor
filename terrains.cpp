#include "terrains.h"
#include "aleatoire.h" // nombreAleatoire

void positionerTerrains(int carte[HAUTEUR][LARGEUR], int terrains[][Terrains::NB_PROPRIETES], const size_t nbTerrains) {
   for(size_t terrain = 0; terrain < nbTerrains; ++terrain) {
      int x;
      int y;
      int rayon;
      bool chevauche;

      do {
         x = nombreAleatoire(LARGEUR - 1, 0);
         y = nombreAleatoire(HAUTEUR - 1, 0);

         // le rayon maximum est définit comme étant
         // la moyenne de la largeur et de la hauteur de la carte
         // divisé par 2 * le nombre de terrains à placer
         rayon = nombreAleatoire(((LARGEUR - 1) + (HAUTEUR - 1)) / (2 * nbTerrains), 1);

         // vérifier que les lacs ne se chevauchent pas
         for(int terrainPrecedent = terrain; terrainPrecedent-1 > 0; --terrainPrecedent) {
            int xPrecedent     = terrains[terrainPrecedent][Terrains::Proprietes::x];
            int yPrecedent     = terrains[terrainPrecedent][Terrains::Proprietes::y];
            int rayonPrecedent = terrains[terrainPrecedent][Terrains::Proprietes::rayon];
            chevauche = (distancePoint(x, y, xPrecedent, yPrecedent) <= rayon + rayonPrecedent + 2);
         }
      } while(not(carte[y][x] == Carte::TypeCase::VIDE) && chevauche);

      terrains[terrain][Terrains::Proprietes::x] = x;
      terrains[terrain][Terrains::Proprietes::y] = y;
      terrains[terrain][Terrains::Proprietes::rayon] = rayon;

      creerDisque(carte, x, y, terrains[terrain][Terrains::Proprietes::type], rayon);
   }
}

void definirTypeTerrains(int terrains[][Terrains::NB_PROPRIETES], const size_t nbTerrains, const int type) {
   for(size_t terrain = 0; terrain < nbTerrains; ++terrain) {
      terrains[terrain][Terrains::Proprietes::type] = type;
   }
}
