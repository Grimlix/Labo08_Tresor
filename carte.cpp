#include "carte.h"
#include "aleatoire.h"

void creerCarte(char carte[], const char symboles[],
                size_t largeur, size_t hauteur) {
   initialiserAleatoire();
   
   int posX;
   int posY;

   for(int cellule = 0; cellule < largeur * hauteur; ++cellule) {
      carte[cellule] = symboles[(int)Elements::VIDE];
   }

   
   // placer le trésor aléatoirement
   posX = nombreAleatoire(largeur, 0);
   posY = nombreAleatoire(hauteur, 0);
   placerSurLaCarte(carte, symboles[(int)Elements::TRESOR], posX, posY, largeur, hauteur);
   
   // placer le chercheur aléatoirement | /!\ pourrait être placé sur un trésor
   posX = nombreAleatoire(largeur, 0);
   posY = nombreAleatoire(hauteur, 0);
   placerSurLaCarte(carte, symboles[(int)Elements::CHERCHEUR], posX, posY, largeur, hauteur);
}

void placerSurLaCarte(char carte[], const char symbole, int x, int y,
                      size_t largeur, size_t hauteur) {
   int pos = coordonneesAPlat(x, y, largeur, hauteur);

   carte[pos] = symbole;
}

void afficherCarte(const char carte[], size_t largeur, size_t hauteur) {
   int pos;

   for(size_t y = 0; y < hauteur; ++y) {
      for(size_t x = 0; x < largeur; ++x) {
         pos = coordonneesAPlat(x, y, largeur, hauteur);
         std::cout << carte[pos] << ' ';
      }
      
      std::cout << std::endl;
   }   
}

int coordonneesAPlat(int x, int y, size_t largeur, size_t hauteur) {
   return y * largeur + x;
}