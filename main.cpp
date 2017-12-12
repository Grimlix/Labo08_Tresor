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
#include "stats.h"

using namespace std;

int main() {
   
   
   do{
   // initialisation des variables pour les statistiques
   int nbreDeSimulations = 0;
   int pasTotaux = 0;
   int nombreDeVictoires = 0;
 
   // initialisation des elements de la carte
   int carte[HAUTEUR][LARGEUR] = {};
//   int lacs[NB_LACS][Terrains::NB_PROPRIETES];
//   int chercheurs[NB_CHERCHEURS][Elements::NB_PROPRIETES];
//   int tresors[NB_TRESORS][Elements::NB_PROPRIETES];  
   
   // saisie du nombre de simulations que l'on veut tester
   saisieUtilisateur(nbreDeSimulations);
   
   // boucle des simulations
   for(int sim = 0; sim <= nbreDeSimulations; sim++){  
      simulation(carte, pasTotaux, nombreDeVictoires);
   }
   
   // Calcule et affichage des statistiques
   int moyennePas = calculeTotal(pasTotaux, nbreDeSimulations);
   cout << "La moyenne de pas par simulation est de environs : " << moyennePas << " pas" << endl;
   int pourcentageVictoire = calculePourcentage(nombreDeVictoires, nbreDeSimulations);
   cout << "Le pourcentage de victoire par simulation est de environs : " << pourcentageVictoire << "%" << endl;
   
   }while(recommencerProgramme());


   return EXIT_SUCCESS;
}

