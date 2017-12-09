#include "terrains.h"
#include "aleatoire.h" // nombreAleatoire

void Terrains::positioner(int carte[HAUTEUR][LARGEUR], int terrains[][Terrains::NB_PROPRIETES], const size_t nbTerrains) {
   for(size_t terrain = 0; terrain < nbTerrains; ++terrain) {
      int x;
      int y;

      do {
         x = nombreAleatoire(LARGEUR - 1, 0);
         y = nombreAleatoire(HAUTEUR - 1, 0);
      } while(not(carte[y][x] == Carte::TypeCase::VIDE));

      terrains[terrain][Terrains::Proprietes::x] = x;
      terrains[terrain][Terrains::Proprietes::y] = y;

      double rayon = nombreAleatoire(((LARGEUR - 1) + (HAUTEUR-1)) / 2 * nbTerrains);

      creerDisque(carte, x, y, Proprietes::type, rayon);
   }
}

void Terrains::definirType(int terrains[][Terrains::NB_PROPRIETES], const size_t nbTerrains, const int type) {
   for(size_t terrain = 0; terrain < nbTerrains; ++terrain) {
      terrains[terrain][Terrains::Proprietes::type] = type;
   }
}
