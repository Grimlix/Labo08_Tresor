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
#include "elements.h"

using namespace std;

int main() {
   
   // INITIALISATION
   int carte[HAUTEUR][LARGEUR] = {};

   int lacs[NB_LACS][Terrains::NB_PROPRIETES];
   int chercheurs[NB_CHERCHEURS][Elements::NB_PROPRIETES];
   int tresors[NB_TRESORS][Elements::NB_PROPRIETES];
           
   creerCarte(carte);

   return EXIT_SUCCESS;
}

