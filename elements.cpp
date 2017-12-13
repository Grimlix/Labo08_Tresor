#include "aleatoire.h" // nombreAleatoire
#include "elements.h"

void positionerElements(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], const size_t nbElements) {
   for(size_t element = 0; element < nbElements; ++element) {
      positionerElement(carte, elements, element);
   }
}

void positionerElement(int carte[HAUTEUR][LARGEUR], int elements[][Elements::NB_PROPRIETES], const size_t numElement) {
   int x;
   int y;

   do {
      // on définit des coordonées aléatoirement
      x = nombreAleatoire(LARGEUR - 1, 0);
      y = nombreAleatoire(HAUTEUR - 1, 0);
   } while(carte[y][x] != Carte::TypeCase::VIDE); // on s'assure que la case est vide

   elements[numElement][Elements::Proprietes::x] = x;
   elements[numElement][Elements::Proprietes::y] = y;

   // on place l'élément sur la carte
   remplacerCase(carte, x, y, elements[numElement][Elements::Proprietes::type]);
}

void bougerElement(int elements[][Elements::NB_PROPRIETES], const size_t numElement, Carte::Direction direction) {
   switch(direction) {
      case Carte::Direction::NORD :
         elements[numElement][Elements::Proprietes::y] -= 1;
         break;
      case Carte::Direction::SUD :
         elements[numElement][Elements::Proprietes::y] += 1;
         break;
      case Carte::Direction::OUEST :
         elements[numElement][Elements::Proprietes::x] -= 1;
         break;
      case Carte::Direction::EST :
         elements[numElement][Elements::Proprietes::x] += 1;
         break;
      default :
         std::cout << "Erreur : la direction " << direction << " n'existe pas !\n";
         break;
   }
}

void bougerAleatoirementElement(int elements[][Elements::NB_PROPRIETES], const size_t numElement) {
   // on choisit une direction aléatoirement, -1 car 
   int directionAleatoire = nombreAleatoire(sizeof(Carte::Direction)-1);

   bougerElement(elements, numElement, Carte::Direction(directionAleatoire));
}

void definirTypeElements(int elements[][Elements::NB_PROPRIETES], const size_t nbElements, const int type) {
   for(size_t element = 0; element < nbElements; ++element) {
      elements[element][Elements::Proprietes::type] = type;
   }
}