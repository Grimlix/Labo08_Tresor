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
#include <limits>

#include "carte.h"
#include "elements.h"
#include "saisie.h"

//#define VIDER_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')

using namespace std;

int main() {
   
   
   do{
   
   int nbreDeSimulations = 0;
   saisieUtilisateur(nbreDeSimulations);
      
      
   
   // INITIALISATION
   int carte[HAUTEUR][LARGEUR] = {};

   int lacs[NB_LACS][Terrains::NB_PROPRIETES];
   int chercheurs[NB_CHERCHEURS][Elements::NB_PROPRIETES];
   int tresors[NB_TRESORS][Elements::NB_PROPRIETES];

   simulation(carte);

   }while(recommencerProgramme());


   return EXIT_SUCCESS;
}

