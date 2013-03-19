
#ifndef _JEU_H
#define _JEU_H

#include "Joueur.h"
#include "Grid.h"



typedef struct
{
	Grid* grille;
	Joueur* mesJoueurs[2];
} Jeu;

/**assesseur de grille*/
Grid * JeuGetGrille(const Jeu * jeu);
/**assesseur de mesjoueurs*/
Joueur * JeuGetMesJoueurs(const Jeu * jeu);

/**mutateur de grille*/
void JeuSetGrille(Jeu * jeu,Grid grille);
/**mutateur de mesjoueurs*/
void JeuSetMesJoueurs(Jeu * jeu,Joueur joueur)

/**constructeur du jeu*/
void JeuConstructeur(Jeu *jeu, const Grid* grille, const Joueur* mesJoueurs);
/**destructeur du jeu*/
void JeuDestructeur(Jeu *jeu);
/**Boucle d'évolutions du jeu*/
void JeuEvolue(Jeu *jeu);
/**procédure qui gère le mouvement de toutes les motos*/
void BougeMoto(Jeu *jeu);
/**fonction qui teste les collisions avec le murs*/
char testCollisionMur(const Moto * moto,const Grid * grille);
/**procédure qui gère les actions des motos en fonction des touches saisies*/
void JeuActionClavier(Joueur * mesJoueurs);

/**procédure de test*/
void JeuTestRegression();

#endif
