#include "stats.h"

int calculePourcentage( int valeur , int total ){
   
   int pourcentage ;
   //C++ a besoin de type float pour avoir une division précise
   //Nous retournons quand même un résultat en int , selon le cahier des charges
   pourcentage = ( (float)valeur/ (float)total )  * 100 ; 
   return pourcentage ;
}

int calculeTotal(int valeur, int total){
   
   int reponse;
   reponse = (valeur / total);
   return reponse;
   
}

