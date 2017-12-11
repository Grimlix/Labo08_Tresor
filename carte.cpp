#include <iostream>
#include <cmath> // floor

//#include "elements.h"
//#include "terrains.h"
#include "carte.h"
#include "aleatoire.h"


void creerCarte(int carte[HAUTEUR][LARGEUR],
        int& lacs[][Terrains::NB_PROPRIETES],
        int& chercheurs[][Elements::NB_PROPRIETES],
        int& tresors[][Elements::NB_PROPRIETES]) {
   initialiserAleatoire();

   viderCarte(carte);

   // définir les types des tableaux d'éléments / de terrain
   Terrains::definirType(lacs, NB_LACS, Carte::TypeCase::LAC);
   Elements::definirType(chercheurs, NB_CHERCHEURS, Carte::TypeCase::CHERCHEUR);
   Elements::definirType(tresors, NB_TRESORS, Carte::TypeCase::TRESOR);
   
   // placer les éléments
   Terrains::positioner(carte, lacs, NB_LACS);
   Elements::positioner(carte, chercheurs, NB_CHERCHEURS);
   Elements::positioner(carte, tresors, NB_CHERCHEURS);
}

bool remplacerCase(int carte[HAUTEUR][LARGEUR], const int x, const int y, const int type) {
   if((y >= 0 && y <= HAUTEUR - 1) && (x >= 0 && x <= LARGEUR - 1)) {
      carte[y][x] = type;

      return true;
   } else {
      return false; // la case n'existe pas sur la carte
   }
}

void viderCarte(int carte[HAUTEUR][LARGEUR]) {
   for(size_t y = 0; y < HAUTEUR; ++y) {
      for(size_t x = 0; x < LARGEUR; ++x) {
         carte[y][x] = Carte::TypeCase::VIDE;  
      }
   }   
}

void afficherCarte(const int carte[HAUTEUR][LARGEUR]) {
   for(size_t y = 0; y < HAUTEUR; ++y) {
      for(size_t x = 0; x < LARGEUR; ++x) {     
         // afficher le symbole du type de la position de la carte
         switch(carte[y][x]) {
            case Carte::TypeCase::CHERCHEUR : std::cout << 'C'; break;
            case Carte::TypeCase::LAC :       std::cout << '~'; break;
            case Carte::TypeCase::TRESOR :    std::cout << 'X'; break;
            case Carte::TypeCase::VIDE :      std::cout << '.'; break;
            default :                         std::cout << carte[y][x]; break;
         }
         
         std::cout << ' ';
      }
      
      std::cout << std::endl;
   }   
}

int distancePoint(const int& lx, const int& ly, const int& rx, const int& ry) {
   return abs(lx - rx) + abs(ly - ry);
}

void creerDisque(int carte[HAUTEUR][LARGEUR], const size_t centreX, const size_t centreY, const int type, const int rayon) {
   if(rayon > 0) {
      size_t diametre = (size_t)(2 * (rayon + 0.5)); // le rayon doit avoir une "moitié de case" pour que le diamètre soit correct
      
      int premierX = (int)(centreX - rayon);
      int premierY = (int)(centreY - rayon);
      int dernierX = premierX + diametre;
      int dernierY = premierY + diametre;

      double distanceCentre;
 
      for(int y = premierY; y < dernierY; ++y) {
         for(int x = premierX; x < dernierX; ++x) {
            distanceCentre = distancePoint(x, y, centreX, centreY);

            if(distanceCentre <= rayon + 0.5) {
               remplacerCase(carte, x, y, type);
            }
         }
      }
   }
}