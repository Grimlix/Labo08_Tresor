#ifndef CARTE_H
#define CARTE_H

#include <iostream>

enum class Elements { CHERCHEUR, TRESOR, LAC, VIDE };

/**
 * permet de placer les différents éléments sur une carte
 * @param carte             la carte
 * @param symboles          les symboles représentant les éléments de la carte
 * @param largeur           la largeur de la carte
 * @param hauteur           la hauteur de la carte
 */
void creerCarte(char carte[], const char symboles[],
                size_t largeur = 100, size_t hauteur = 200);

/**
 * place un élément à une coordonée de la carte
 * @param carte     la carte
 * @param symbole   le symbole à ajouter
 * @param x      la coordonnée x
 * @param y      la coordonnée y
 * @param largeur   la largeur de la carte
 * @param hauteur   la hauteur de la carte
 */
void placerSurLaCarte(char carte[], const char symbole, int x, int y,
                      size_t largeur, size_t hauteur);

/**
 * afficher la carte et ses éléments
 * @warning cette fonction n'est utile que pour visualiser de petites cartes
 * @param carte    la carte à afficher
 * @param largeur  la largeur de la carte
 * @param hauteur  la hauteur de la carte
 */
void afficherCarte(const char carte[], size_t largeur, size_t hauteur);

/**
 * convertit une coordonnée x, y en une position en entier
 * @param x        la coordonnée x
 * @param y        la coordonnée y
 * @param largeur  la largeur de la carte
 * @param hauteur  la heuteur de la cartes
 * @return la position en entier
 */
int coordonneesAPlat(int x, int y, size_t largeur, size_t hauteur);

#endif /* CARTE_H */

