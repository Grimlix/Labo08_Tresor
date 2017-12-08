#include "carte.h"
#include "aleatoire.h"
#include "cmath" // floor

/*
 * enum class Elements { CHERCHEUR, LAC }
 * int carte[y][x]
 * int positionsChercheur[2] (0 : x, 1: y)
 * int positionsLacs[nbLacs][] ??? (0 : x du milieu, 1 : y du milieu)
 */

void creerCarte(int carte[HAUTEUR][LARGEUR]) {
   initialiserAleatoire();

   viderCarte(carte);

   ////////////
   // ELEMENTS
   ////////////
   int chercheurs[NB_CHERCHEURS][NB_PROPRIETES];
   int lacs[NB_LACS][NB_PROPRIETES];
   int tresors[NB_TRESORS][NB_PROPRIETES];
   
   // définir les types des tableaux d'éléments
   definirTypeElements(chercheurs, NB_CHERCHEURS, Carte::Elements::CHERCHEUR);
   definirTypeElements(lacs, NB_LACS, Carte::Elements::LAC);
   definirTypeElements(tresors, NB_TRESORS, Carte::Elements::TRESOR);
   
   // placer les éléments
   
   int x;
   int y;
   
   do {
      x = nombreAleatoire(LARGEUR - 1, 0);
      y = nombreAleatoire(HAUTEUR - 1, 0);
   } while(not(carte[y][x] == Carte::Elements::VIDE));
   
   chercheurs[0][Elements::Proprietes::x] = x;
   chercheurs[0][Elements::Proprietes::y] = y;

   remplacerCase(carte, x, y, chercheurs[0][Elements::Proprietes::type]);
}

void remplacerCase(int carte[HAUTEUR][LARGEUR], const int x, const int y, const int type) {
   carte[y][x] = type;
}

void viderCarte(int carte[HAUTEUR][LARGEUR]) {
   for(size_t y = 0; y < HAUTEUR; ++y) {
      for(size_t x = 0; x < LARGEUR; ++x) {
         carte[y][x] = Carte::Elements::VIDE;  
      }
   }   
}

void definirTypeElements(int elements[][NB_PROPRIETES], const size_t nbElements, const int type) {
   for(size_t element = 0; element < nbElements; ++element) {
      elements[element][Elements::Proprietes::type] = type;
   }
}

void afficherCarte(const int carte[HAUTEUR][LARGEUR]) {
   for(size_t y = 0; y < HAUTEUR; ++y) {
      for(size_t x = 0; x < LARGEUR; ++x) {     
         // afficher le symbole du type de la position de la carte
         switch(carte[y][x]) {
            case Carte::Elements::CHERCHEUR : std::cout << 'C'; break;
            case Carte::Elements::LAC :       std::cout << '~'; break;
            case Carte::Elements::TRESOR :    std::cout << 'X'; break;
            case Carte::Elements::VIDE :      std::cout << '.'; break;
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

/* void creerDisqueElement(double rayon) {
   if(rayon > 0) {
      size_t diametre = (size_t)(2 * rayon);
      size_t milieu   = (size_t)floor(rayon);

      int disque[diametre][diametre];
      double distanceCentre;

      for(size_t y = 0; y < diametre; ++y) {
         for(size_t x = 0; x < diametre; ++x) {
            distanceCentre = distancePoint(x, y, milieu, milieu);

            if(distanceCentre <= rayon) {
               disque[y][x] = Carte::Elements::LAC; // TASK: A DEPLACER EN PARAMETRE
            }
         }
         
         std::cout << std::endl;
      }      
   }
}*/