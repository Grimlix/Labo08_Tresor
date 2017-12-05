/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>


using namespace std;

const unsigned int pasMaximum = 20000;

bool estMort (int nbrePas){ 
   if (nbrePas > pasMaximum){
      cout << "Le chercheur est mort de faim" << endl;
      return true;
   }
   else{
      return false;
   } 
}

bool estNoye (char nouvellePositionChercheur[]){
   if (nouvellePositionChercheur == "~"){
      cout << "Le chercheur s'est noye" << endl;
      return true;
   }
   else{
      return false;
   }
}   
   
bool estPerdu (char nouvellePositionChercheur[]){
   if (nouvellePositionChercheur == " "){
       cout << "Le chercheur s'est perdu" << endl;
       return true;
   }
   else{
       return false;
   }
}








