
#ifndef _JEU_H
#define _JEU_H

#include "Joueur.h"
#include "Grid.h"
#include "Constantes.h"
#include "Bonus.h"
#include "Musique.h"




typedef struct
{
	Grid grille;
	Joueur *mesJoueurs;
	Bonus mesBonus[_Nombre_de_Bonus];
	int tempsProchainBonus;
	Musique musique;/*assesseur non fait*/
} Jeu;

/**assesseur de grille*/
Grid* JeuGetGrille(Jeu* jeu);
/**assesseur de mesjoueurs*/
Joueur* JeuGetIemeJoueurs(Jeu* jeu,int i);
/**assesseur du ieme  Bonus*/
Bonus* JeuGetIemeBonus(Jeu* jeu,int i);
/**assesseur de tempsProchainBonus*/
int JeuGetTempsProchainBonus(Jeu* jeu);
/**assesseur de musique*/
Musique* JeuGetMusique(Jeu* jeu);




/**mutateur de grille*/
void JeuSetGrille(Jeu* jeu,Grid* grille);
/**mutateur de mesjoueurs*/
void JeuSetIemeJoueurs(Jeu* jeu,Joueur* Joueur,int i);
/**mutateur du ieme bonus*/
void JeuSetIemeBonus(Jeu* jeu,const Bonus* bonus,int i);
/**mutateur de tempsProchainBonus*/
void JeuSetTempsProchainBonus(Jeu* jeu,int tempsProchainBonus);
/**mutateur de Musique*/
void JeuSetMusique(Jeu* jeu,Musique* musique);


/**constructeur du jeu*/
void JeuConstructeur(Jeu* jeu, Grid* grille, Joueur * mesJoueurs);
/**destructeur du jeu*/
void JeuDestructeur(Jeu* jeu);
/**Boucle d'évolutions du jeu*/
void JeuEvolue(Jeu* jeu,short int* jeuFini,char *nouveauMessage,Couleur *couleurMessage);
/**procédure qui gère le mouvement de toutes les motos*/
void bougeMoto(Jeu* jeu);
/**fonction qui teste les collisions avec le murs*/
char testCollisionMur(Joueur * joueur, Grid * grille);
/**fonction qui teste les collisions entre 2 moto*/
char testCollisionMoto(Moto* moto, Moto* moto2);
/**procédure qui gère les actions des motos en fonction des touches saisies*/
void JeuActionClavier(Joueur* joueur, Direction direction,Grid* grille);
/**procédure qui actionne le bonus*/
void JeuActionneBonus(Joueur*Joueur);
/**procedure qui gère les mouvements d'une IA*/
void JeuGereIA(Joueur* joueur,Jeu* jeu);
/**procédure qui affiche le tableau d'analyse de la grille*/
void afficheGrilleAnalyse(short int (*grilleAnalyse)[_Taille_Y_Grille/_Precision_Analyse_IA][_Taille_X_Grille/_Precision_Analyse_IA]);
/**procédure qui affiche le tableau d'analyse des distances de la grille*/
void afficheGrilleDistances(short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA][_Taille_X_Grille/_Precision_Analyse_IA]);
/**procédure qui crée le tableau d'analyse de la grille*/
void creerGrilleAnalyse(short int (*grilleAnalyse)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                  [_Taille_X_Grille/_Precision_Analyse_IA],
                        Jeu* jeu,Joueur* joueurIA);
/**Procédure qui renvoie la distance entre une case et toute la grille (grilleDistance doit être initialisé à -1 partout)*/
 void creerGrilleDistances(short int ligne1,short int colonne1,
                                short int (*grilleAnalyse)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                          [_Taille_X_Grille/_Precision_Analyse_IA],
                                short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                          [_Taille_X_Grille/_Precision_Analyse_IA]);
/**Procédure qui choisie la cible d'un joueurIA et retourne la distance à ce joueur*/
short int choisieCibleIA(Joueur* joueurIA,Jeu* jeu,short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                                              [_Taille_X_Grille/_Precision_Analyse_IA]);

/**Procédure qui décide de la direction choisie à chaque tour pour l'IA à partir de la grille des distances
de la cible ou si l'IA n'a pas de cible, la grille des distance de l'IA*/
void choisieDirection(Joueur* joueurIA,Jeu *jeu,short int distanceJoueurCible,
                      short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                 [_Taille_X_Grille/_Precision_Analyse_IA]);
/**Procédure qui donne les indices ligne et colonne d'un joueur dans la grille*/
void indicesGrilleJoueur(short int *ligne,short int *colonne,Joueur* joueur);
/**Fonction qui teste la collision entre deux objets carrés (autrement appelé bounding box)*/
char testCollisionGenerique(float objet1[4],float objet2[4]);
/**Fonction qui teste si une moto rentre en collision avec une Moto, renvoie 0 si pas de collision, le numéro du joueur si il y a collision*/
char testCollisionMotoBonus(Joueur *mesJoueurs,Bonus* bonus);
/**Fonction qui teste si un bonus est en Collision avec un Mur*/
char testCollisionMursBonus(Grid *grille,Bonus* bonus);
/**Fonction qui place des bonus sur la grille*/
void PlaceBonus(Jeu *jeu,Bonus *bonus);
/**Procedure qui décrémente le tempsBonus des bonus actifs des joueurs*/
void decrementeTempsBonus(Jeu *jeu);

/**procédure de test*/
void JeuTestRegression();

#endif
