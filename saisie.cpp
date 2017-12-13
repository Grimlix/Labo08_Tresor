#include "saisie.h"

int saisieUtilisateur()
{
   int nbDeSimulations;

   bool saisieCorrect = false;
   
   //Variables entrées par l'utilisateur
   int nbreChercheur;
   
   //On recommence tant que la saisie n'est pas correcte
   do{  
      cout << "Entrez le nombre de simulations [" 
      << MIN_SIMULATION << " - " << MAX_SIMULATION << "]" << endl ;
      
      cin >> nbDeSimulations ; 

      //Si l'utilisateur remplit correctement les champs 
      if(!cin.fail()){
         if(controleSaisie( nbDeSimulations , MIN_SIMULATION , MAX_SIMULATION, "Nombre de simulations incorrect !")){
            saisieCorrect = true ;
         }
         VIDER_BUFFER;
      }
   } while(!saisieCorrect); // On recommence tant que la saisie n'est pas correcte
   
   return nbDeSimulations;
}

bool controleSaisie( int valeur , unsigned int limiteInf , unsigned limiteSup , string message){
   
   //Controle d'une valeur entre deux bornes
   if( valeur < limiteInf or valeur > limiteSup ){
      cout << message << endl ;
      return false ;
   }
   return true ;
}

bool recommencerProgramme()
{
   char reponseUtilisateur ; 
   bool saisieOK;
   bool recommencerProgramme = false ; 
   
   // Demande de recommencer le programme
   do 
   {
      cout << "Voulez-vous recommencer le programme ? " << endl
           << "(si non, le programme se terminera) [O/N] : ";

      cin >> reponseUtilisateur;
      
      saisieOK = ( (reponseUtilisateur == 'O') || (reponseUtilisateur == 'N') || (reponseUtilisateur == 'o') || (reponseUtilisateur == 'n') );

      if (!saisieOK){
         cin.clear();
         cout << "Votre saisie n'est pas valide." << endl << endl;
      }
      // Si la saisie est valide, on va initialiser le flag qui détermine si le
      // programme doit recommencer.
      else{
         recommencerProgramme = (reponseUtilisateur == 'O') || (reponseUtilisateur == 'o');
      }
      VIDER_BUFFER;
      
   }while (!saisieOK); // On recommence tant que la saisie n'est pas correcte
   
   return recommencerProgramme ;
}

