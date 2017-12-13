#include <iostream>
#include <cmath> // floor

#include "carte.h"
#include "aleatoire.h"
#include "elements.h"
#include "etats.h"

void simulation(int carte[HAUTEUR][LARGEUR], int& pasTotaux, int& nombreDeVictoires, int nbEssai) {
   initialiserAleatoire();

   viderCarte(carte);
   
   ////////////
   //ELEMENTS//
   ////////////
   int lacs[NB_LACS][Terrains::NB_PROPRIETES];
   int chercheurs[nbEssai][Elements::NB_PROPRIETES];
   int tresors[NB_TRESORS][Elements::NB_PROPRIETES];
   
   // définir les types des tableaux d'éléments / de terrain
   definirTypeTerrains(lacs, NB_LACS, Carte::TypeCase::LAC);
   definirTypeElements(chercheurs, nbEssai, Carte::TypeCase::CHERCHEUR);
   definirTypeElements(tresors, NB_TRESORS, Carte::TypeCase::TRESOR);
 
   // positionnner tous les éléments
   positionerTerrains(carte, lacs, NB_LACS);
   positionerElements(carte, tresors, NB_TRESORS);
   
   // positionner le premier chercheur /!\ la fonction doit placer qu'un élément
   // car autrement elle placerai, en même temps, le nb de chercheur total
   // (pour tout les essais) sur la carte
   positionerElement(carte, chercheurs, 0);
   
   // les positions du premie chercheur sont conservées afin de pouvoir réinitialiser
   // la position à chaque nouvel essai à la position initial
   int xInitial = chercheurs[0][Elements::Proprietes::x];
   int yInitial = chercheurs[0][Elements::Proprietes::y];

   // à chaque essai on fait utilise un nouveau chercheur
   // pour pouvoir éventuellement conserver les états de chaque chercheur
   for(size_t essai = 0; essai < nbEssai; ++essai) {
      int pas = 0;
      // réinitialiser chercheur
      chercheurs[essai][Elements::Proprietes::x] = xInitial;
      chercheurs[essai][Elements::Proprietes::y] = yInitial;
      chercheurs[essai][Elements::Proprietes::etat] = Etats::EXPLORE;
      
      do {
         bougerAleatoirementElement(chercheurs, essai);
         pas++;

         if(estMort(pas)) {
            chercheurs[essai][Elements::Proprietes::etat] = Etats::MORT;
            std::cout << "Le chercheur " << essai << " est mort de faim" << std::endl;
         } else if(estDansLac(chercheurs, lacs, essai)) {
            chercheurs[essai][Elements::Proprietes::etat] = Etats::NOYE;
            std::cout << "Le chercheur " << essai << " s'est noye" << std::endl;
         } else if(estRiche(chercheurs, tresors, essai)) {
            chercheurs[essai][Elements::Proprietes::etat] = Etats::RICHE;
            nombreDeVictoires += 1;
            std::cout << "Le chercheur " << essai <<  "a trouve le tresor" << std::endl;
         } else if(estPerdu(chercheurs, essai)) {
            chercheurs[essai][Elements::Proprietes::etat] = Etats::PERDU;
            std::cout << "Le chercheur " << essai << " s'est perdu" << std::endl;
         }
      } while(chercheurs[essai][Elements::Proprietes::etat] == Etats::EXPLORE);
      
      std::cout << "Il a fait : " << pas << " pas" << std::endl;
      
      
      // on ajoute le nombre de pas du chercheur au nombre de pas total
      pasTotaux += pas;
   }
   
   // affiche la carte utilisée par la simulation
   afficherCarte(carte);
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
