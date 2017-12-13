/*
 -----------------------------------------------------------------------------------
 Laboratoire : Labo_08
 Fichier     : <nom du fichier>.cpp
 Auteur(s)   : Simon Walther et Nicolas Hungerbühler 
 Date        : 13.12.2017

 But         : Faire une chasse aux trésors avec un nombre n de chercheurs. Les
               chercheurs se déplacent aléatoirement sur l'une des cases adjacentes
               à leur position. Les chercheurs se perdent s'ils sortent des limites,
               se noyent s'ils tombent dans un lac, meurent de faim s'ils dépassent
               le nombre de déplacements maximum et deviennent riche s'ils trouvent
               le trésor.

 Remarque(s) : La carte est générée aléatoirement. 

 Compilateur : MinGW-g++ 
 -----------------------------------------------------------------------------------
 */

#include <cstdlib> // pour EXIT_SUCCESS

#include "carte.h"
#include "elements.h"
#include "saisie.h"
#include "stats.h"

using namespace std;

int main() {
   
   // Message d'initialisation
   cout << "Bonjour, ce programme genere une carte au tresor. Le but est de créer une simulation,"
           "vous allez choisir le nombre de chercheurs et ce programme va creer des statistiques "
           "de ses résultats." << endl;
   
   do {
      // initialisation des variables pour les statistiques
      int nbEssai;
      int pasTotaux = 0;
      int nombreDeVictoires = 0;

      // initialisation des elements de la carte
      int carte[HAUTEUR][LARGEUR] = {};

      // saisie du nombre de simulations que l'on veut tester
      nbEssai = saisieUtilisateur();
  
      // boucle des simulations
      simulation(carte, pasTotaux, nombreDeVictoires, nbEssai);

      // Calcule et affichage des statistiques
      int moyennePas = calculeMoyenne(pasTotaux, nbEssai);
      cout << "La moyenne de pas par simulation est de environs : " << moyennePas << " pas" << endl;
      float pourcentageVictoire = calculePourcentage(nombreDeVictoires, nbEssai);
      cout << "Le pourcentage de victoire par simulation est de environs : " << pourcentageVictoire << "%" << endl;

   } while(recommencerProgramme());
 
   return EXIT_SUCCESS;
}

