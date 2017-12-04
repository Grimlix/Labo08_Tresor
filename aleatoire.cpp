#include "aleatoire.h"
#include <time.h>
#include <stdlib.h>

int nombreAleatoire(const int& maxValue, const int& minValue) {     
   return rand() % (maxValue-minValue) + minValue;
}

void initialiserAleatoire() {
   srand((unsigned)time(NULL));
}