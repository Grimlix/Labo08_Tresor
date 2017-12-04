/*
 -----------------------------------------------------------------------------------
 Laboratoire : <nn>
 Fichier     : <nom du fichier>.cpp
 Auteur(s)   : <prénom> <nom>
 Date        : <jj.mm.aaaa>

 But         : <à compléter>

 Remarque(s) : <à compléter>

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
 */

#include <cstdlib>

#include "carte.h"

using namespace std;

int main() {
   char symboles[sizeof(Elements)];
   symboles[(int)Elements::CHERCHEUR] = 'C';
   symboles[(int)Elements::TRESOR] = 'X';
   symboles[(int)Elements::LAC] = '~';
   symboles[(int)Elements::VIDE] = '-';
  
   // note : 20 * 20 pour tester mais normalement 100*200
   size_t largeur = 20;
   size_t hauteur = 20;
   char carte[largeur * hauteur];
   
   creerCarte(carte, symboles, largeur, hauteur);

   afficherCarte(carte, largeur, hauteur);
   
   return EXIT_SUCCESS;
}

