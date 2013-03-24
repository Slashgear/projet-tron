#include "Joueur.h"
#include "Grid.h"
#include <stdio.h>
#include <stdlib.h>

Grid * JeuGetGrille(const Jeu * jeu){
    return jeu->grille;
}
Joueur * JeuGetMesJoueurs(const Jeu * jeu){
    return jeu->mesJoueurs[2];
}
void JeuSetGrille(Jeu * jeu,Grid grille){
    jeu->grille=grille
}


