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
   int carte[HAUTEUR][LARGEUR] = {};
   
   creerCarte(carte);

   afficherCarte(carte);
   
   //creerDisqueElement(3.5);
   
   return EXIT_SUCCESS;
}

