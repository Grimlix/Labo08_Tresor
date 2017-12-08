#include "aleatoire.h"
#include <time.h>
#include <stdlib.h>

int nombreAleatoire(const int& maxValue, const int& minValue) {
   static bool estInitialise = false;
   
   if(not(estInitialise)) {
      initialiserAleatoire();
      
      estInitialise = true;
   }

   return rand() % (maxValue-minValue) + minValue;
}

void initialiserAleatoire() {
   srand((unsigned)time(NULL));
}