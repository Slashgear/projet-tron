
#ifndef _JEU_H
#define _JEU_H

#include "Joueur.h"
#include "Grid.h"
#include "Constantes.h"
#include "Bonus.h"



typedef struct
{
	Grid grille;
	Joueur mesJoueurs[_Nombre_de_Joueur];
	/*Bonus tableauDeBonus[_Nombre_de_Bonus];*/
} Jeu;

/**assesseur de grille*/
Grid* JeuGetGrille(Jeu* jeu);
/**assesseur de mesjoueurs*/
Joueur* JeuGetIemeJoueurs(Jeu* jeu,int i);
/**assesseur du ieme  Bonus*/
Bonus* JeuGetIemeBonus(Jeu* jeu,int i);

/**mutateur de grille*/
void JeuSetGrille(Jeu* jeu,Grid* grille);
/**mutateur de mesjoueurs*/
void JeuSetIemeJoueurs(Jeu* jeu,Joueur* mesJoueurs,int i);
/**mutateur du ieme bonus*/
void JeuSetIemeBonus(Jeu* jeu,Bonus* bonus,int i);

/**constructeur du jeu*/
void JeuConstructeur(Jeu* jeu, Grid* grille, Joueur* mesJoueurs[_Nombre_de_Joueur]/*,Bonus* tableauDeBonus[_Nombre_de_Bonus]*/);
/**destructeur du jeu*/
void JeuDestructeur(Jeu* jeu);
/**Boucle d'évolutions du jeu*/
void JeuEvolue(Jeu* jeu,short int* jeuFini);
/**procédure qui gère le mouvement de toutes les motos*/
void bougeMoto(Jeu* jeu);
/**fonction qui teste les collisions avec le murs*/
char testCollisionMur(const Moto * moto, Grid * grille);
/**fonction qui teste les collisions entre 2 moto*/
char testCollisionMoto(Moto* moto, Moto* moto2);
/**procédure qui gère les actions des motos en fonction des touches saisies*/
void JeuActionClavier(Joueur* joueur, const SDLKey touche,Grid* grille);

/**procédure de test*/
void JeuTestRegression();

#endif
