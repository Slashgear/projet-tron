
#ifndef _JEU_H
#define _JEU_H

#include "Joueur.h"
#include "Grid.h"
#include "Constantes.h"
#include "Bonus.h"




typedef struct
{
	Grid grille;
	Joueur *mesJoueurs;
	Bonus mesBonus[_Nombre_de_Bonus];
	int tempsProchainBonus;
} Jeu;

/**assesseur de grille*/
Grid* JeuGetGrille(Jeu* jeu);
/**assesseur de mesjoueurs*/
Joueur* JeuGetIemeJoueurs(Jeu* jeu,int i);
/**assesseur du ieme  Bonus*/
Bonus* JeuGetIemeBonus(Jeu* jeu,int i);
/**assesseur de tempsProchainBonus*/
int JeuGetTempsProchainBonus(Jeu* jeu);

/**mutateur de grille*/
void JeuSetGrille(Jeu* jeu,Grid* grille);
/**mutateur de mesjoueurs*/
void JeuSetIemeJoueurs(Jeu* jeu,Joueur* Joueur,int i);
/**mutateur du ieme bonus*/
void JeuSetIemeBonus(Jeu* jeu,const Bonus* bonus,int i);
/**mutateur de tempsProchainBonus*/
void JeuSetTempsProchainBonus(Jeu* jeu,int tempsProchainBonus);

/**constructeur du jeu*/
void JeuConstructeur(Jeu* jeu, Grid* grille, Joueur * mesJoueurs);
/**destructeur du jeu*/
void JeuDestructeur(Jeu* jeu);
/**Boucle d'évolutions du jeu*/
void JeuEvolue(Jeu* jeu,short int* jeuFini);
/**procédure qui gère le mouvement de toutes les motos*/
void bougeMoto(Jeu* jeu);
/**fonction qui teste les collisions avec le murs*/
char testCollisionMur(Joueur * joueur, Grid * grille);
/**fonction qui teste les collisions entre 2 moto*/
char testCollisionMoto(Moto* moto, Moto* moto2);
/**procédure qui gère les actions des motos en fonction des touches saisies*/
void JeuActionClavier(Joueur* joueur, const SDLKey touche,Grid* grille);

/**Fonction qui teste si une moto rentre en collision avec une Moto, renvoie 0 si pas de collision, le numéro du joueur si il y a collision*/
char testCollisionMotoBonus(Joueur *mesJoueurs,Bonus* bonus);
/**Fonction qui teste si un bonus est en Collision avec un Mur*/
char testCollisionMursBonus(Grid *grille,Bonus* bonus);
/**fonction qui place des bonus sur la grille*/
void PlaceBonus(Jeu *jeu,Bonus *bonus);

/**procédure de test*/
void JeuTestRegression();

#endif
