#ifndef ALEATOIRE_H
#define ALEATOIRE_H

/**
 * génére un nombre entier aléatoire dans un intervalle donné
 * @param maxValue  la valeur maximum voulue
 * @param minValue  la valeur minimum voulue
 * @return la valeur générée
 */
int nombreAleatoire(const int& maxValue, const int& minValue = 0);

/**
 * initialiser le "seed" de rand par rapport à l'horloge du système
 * @warning à utiliser au moins une fois pour pouvoir utiliser nombreAleatoire correctement
 */
void initialiserAleatoire();

#endif /* ALEATOIRE_H */
