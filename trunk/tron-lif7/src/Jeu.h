
#ifndef _JEU_H
#define _JEU_H

#include "Joueur.h"
#include "Grid.h"



typedef struct
{
	Grid* grille;
	Joueur* mesJoueurs;
} Jeu;

/**assesseur de grille*/
Grid* JeuGetGrille(const Jeu* jeu);
/**assesseur de mesjoueurs*/
Joueur* JeuGetMesJoueurs(const Jeu* jeu);

/**mutateur de grille*/
void JeuSetGrille(Jeu* jeu,Grid* grille);
/**mutateur de mesjoueurs*/
void JeuSetMesJoueurs(Jeu* jeu,Joueur* mesJoueurs);

/**constructeur du jeu*/
void JeuConstructeur(Jeu* jeu, Grid* grille, Joueur* mesJoueurs);
/**destructeur du jeu*/
void JeuDestructeur(Jeu* jeu);
/**Boucle d'évolutions du jeu*/
void JeuEvolue(Jeu* jeu,char jeuFini);
/**procédure qui gère le mouvement de toutes les motos*/
void bougeMoto(Jeu* jeu);
/**fonction qui teste les collisions avec le murs*/
char testCollisionMur(const Moto * moto,const Grid * grille);
/**procédure qui gère les actions des motos en fonction des touches saisies*/
void JeuActionClavier(Joueur* joueur, const char touche);

/**procédure de test*/
void JeuTestRegression();

#endif
