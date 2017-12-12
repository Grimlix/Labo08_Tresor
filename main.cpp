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
      int moyennePas = calculeTotal(pasTotaux, nbEssai);
      cout << "La moyenne de pas par simulation est de environs : " << moyennePas << " pas" << endl;
      float pourcentageVictoire = calculePourcentage(nombreDeVictoires, nbEssai);
      cout << "Le pourcentage de victoire par simulation est de environs : " << pourcentageVictoire << "%" << endl;

   } while(recommencerProgramme());
 
   return EXIT_SUCCESS;
}

