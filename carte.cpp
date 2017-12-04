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

   placerSurLaCarteAleatoirement(carte, symboles[(int)Elements::CHERCHEUR], symboles, largeur, hauteur);
   placerSurLaCarteAleatoirement(carte, symboles[(int)Elements::TRESOR], symboles, largeur, hauteur);
}

char placerSurLaCarte(char carte[], const char& symbole, int x, int y,
                      size_t largeur, size_t hauteur) {
   int pos = coordonneesAPlat(x, y, largeur, hauteur);
   char ancienContenu = carte[pos];
   carte[pos] = symbole;
   
   return ancienContenu;
}

void placerSurLaCarteAleatoirement(char carte[], const char& symbole, const char symboles[],
                                   size_t largeur, size_t hauteur) {
   int pos, x, y;

   do {
      x = nombreAleatoire(largeur, 0);
      y = nombreAleatoire(hauteur, 0);
      pos = coordonneesAPlat(x, y, largeur, hauteur);
   } while(carte[pos] != symboles[(int)Elements::VIDE]); // on s'assure que la case est vide

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