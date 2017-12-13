#ifndef STATS_H
#define STATS_H

/**
 * Permet de calculer le pourcentage
 * @param valeur , valeur initiale
 * @param total , nombre total de simulations
 * @return Pourcentage , en type float. On veut que les résultat soient plus préscis,
 * surtout que le chercheur arrivera souvent à 0% de réussite si on arrondis toujours.
 */
float calculePourcentage( int valeur , int total );

/**
 * Permet de calculer la moyenne
 * @param valeur , valeur initiale
 * @param total , nombre total de simulation
 * @return resultat. Le réusltat de la division pour avoir la moyenne
 */
int calculeMoyenne(int valeur, int total);

#endif /* STATS_H */

