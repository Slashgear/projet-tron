/**
	\file [Jeu.h]
	 Module centrale du Jeu
	\author {Antoine.C,Matthieu.B}
	\version 2.1
	\date 13 mars 2013
*/
#ifndef _JEU_H
#define _JEU_H

#include "Joueur.h"
#include "Grid.h"
#include "Constantes.h"
#include "Bonus.h"
#include "Musique.h"

/**
 	\struct Jeu
 Structure du Jeu
 */
typedef struct
{
	Grid grille;
	Joueur *mesJoueurs;
	int *scores;
	Bonus mesBonus[_Nombre_de_Bonus];
	int tempsProchainBonus;
	Musique *musique;
} Jeu;
/**
 	\fn JeuGetGrille
 assesseur de grille
 	\param Jeu* jeu
 	\return Grid*
 */
Grid* JeuGetGrille(Jeu* jeu);
/**
 	\fn JeuGetGrille
 assesseur du Ieme Joueur
 	\param Jeu* jeu,int i
 	\return Joueur*
 */
Joueur* JeuGetIemeJoueurs(Jeu* jeu,int i);
/**
 	\fn JeuGetIemeScore
 assesseur de scores
 	\param Jeu* jeu,int i
 	\return un score
 */
int JeuGetIemeScore(Jeu* jeu,int i);
/**
 	\fn JeuGetIemeBonus
 assesseur du ieme  Bonus
 	\param Jeu* jeu,int i
 	\return Bonus*
 */
Bonus* JeuGetIemeBonus(Jeu* jeu,int i);
/**
 	\fn JeuGetTempsProchainBonus
 assesseur de tempsProchainBonus
 	\param Jeu* jeu
 	\return temps avant prochain Bonus
 */
int* JeuGetScores(Jeu* jeu);
/**
 	\fn JeuGetScores
 assesseur des Scores
 	\param Jeu* jeu
 	\return tableau des scores
 */
int JeuGetTempsProchainBonus(Jeu* jeu);
/**
 	\fn JeuGetMusique
 assesseur de tempsProchainBonus
 	\param Jeu* jeu
 	\return Musique*
 */
Musique* JeuGetMusique(Jeu* jeu);

/**
 	\fn JeuSetGrille
 mutateur de grille
 	\param Jeu* jeu,Grid* grille
 */
void JeuSetGrille(Jeu* jeu,Grid* grille);
/**
 	\fn JeuSetIemeJoueurs
 mutateur de mesjoueurs
 	\param Jeu* jeu,Joueur* Joueur,int i
 */
void JeuSetIemeJoueurs(Jeu* jeu,Joueur* Joueur,int i);
/**
 	\fn JeuSetIemeScore
 mutateur de scores
 	\param Jeu* jeu,int score,int i
 */
void JeuSetIemeScore(Jeu* jeu,int score,int i);
/**
 	\fn JeuSetIemeBonus
 mutateur du ieme bonus
 	\param Jeu* jeu,const Bonus* bonus,int i
 */
void JeuSetIemeBonus(Jeu* jeu,const Bonus* bonus,int i);
/**
 	\fn  JeuSetTempsProchainBonus
 mutateur de tempsProchainBonus
 	\param Jeu* jeu,int tempsProchainBonus
 */
void JeuSetTempsProchainBonus(Jeu* jeu,int tempsProchainBonus);
/**
 	\fn  JeuSetMusique
 mutateur de musique
 	\param Jeu* jeu,Musique* musique
 */
void JeuSetMusique(Jeu* jeu,Musique* musique);

/**
 	\fn  JeuConstructeur
 Constructeur de Jeu
 	\param Jeu* jeu, Grid* grille, Joueur * mesJoueurs, int* scores, Musique *musique
 */
void JeuConstructeur(Jeu* jeu, Grid* grille, Joueur * mesJoueurs, int* scores,Musique *musique);
/**
 	\fn  JeuDestructeur
 Destructeur de Jeu
 	\param Jeu* jeu
 */
void JeuDestructeur(Jeu* jeu);
/**
 	\fn  JeuEvolue
 Centre de l'action du jeu
 	\param Jeu* jeu,short int* jeuFini,char *nouveauMessage,Couleur *couleurMessage
 * Procédure qui gère tous les tours l'avancement et l'état de chaque moto, ainsi que les conditions de victoire
 * Elle lance également les affichages des informations principales du jeu et modifie les scores
 */
void JeuEvolue(Jeu* jeu,short int* jeuFini,char *nouveauMessage,Couleur *couleurMessage);
/**
 	\fn  bougeMoto
 procédure qui gère le mouvement de toutes les motos
 	\param Jeu* jeu
 */
void bougeMoto(Jeu* jeu);
/**
 	\fn  testCollisionMur
 fonction qui teste les collisions entre les motos et les Murs
 	\param Joueur * joueur, Grid * grille,char boolSaut
 	\return Retourne 0 si pas de collisions, 1 si collision simple, 2 si collision à grande vitesse
 */
char testCollisionMur(Joueur * joueur, Grid * grille,char boolSaut);
/**
 	\fn  testCollisionMoto
 fonction qui teste les collisions entre les motos
 	\param Moto* moto, Moto* moto2
 	\return Retourne 0 si pas de collisions, 1 si collision
 */
char testCollisionMoto(Moto* moto, Moto* moto2);
/**
 	\fn  JeuActionClavier
 procédure qui gère les actions des motos en fonction des touches saisies
 	\param Joueur* joueur, Direction direction,Grid* grille
 */
void JeuActionClavier(Joueur* joueur, Direction direction,Grid* grille);
/**
 	\fn  JeuActionneBonus
 procédure qui actionne le Bonus
 	\param Joueur* joueur
 */
void JeuActionneBonus(Joueur*Joueur);
/**
 	\fn JeuGereIA
 procédure qui gère les mouvements d'une IA
 	\param Joueur* joueur,Jeu* jeu
 */
void JeuGereIA(Joueur* joueur,Jeu* jeu);
/**
 	\fn afficheGrilleAnalyse
 procédure qui affiche le tableau d'analyse de la grille
 	\param short int (*grilleAnalyse)[_Taille_Y_Grille/_Precision_Analyse_IA][_Taille_X_Grille/_Precision_Analyse_IA]
 */
void afficheGrilleAnalyse(short int (*grilleAnalyse)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                    [_Taille_X_Grille/_Precision_Analyse_IA]);
/**
 	\fn afficheGrilleDistances
 procédure qui affiche le tableau d'analyse des distances de la grille
 	\param short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA][_Taille_X_Grille/_Precision_Analyse_IA]
 */
void afficheGrilleDistances(short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                       [_Taille_X_Grille/_Precision_Analyse_IA]);
 /**
 	\fn afficheGrilleDistances
 procédure qui crée le tableau d'analyse de la grille
 	\param short int (*grilleAnalyse)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                    [_Taille_X_Grille/_Precision_Analyse_IA],
                    Jeu* jeu,Joueur* joueurIA
 */
void creerGrilleAnalyse(short int (*grilleAnalyse)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                  [_Taille_X_Grille/_Precision_Analyse_IA],
                        Jeu* jeu,Joueur* joueurIA);
 /**
 	\fn creerGrilleDistances
 procédure qui crée la grille distance
 	\param short int (*grilleAnalyse)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                    [_Taille_X_Grille/_Precision_Analyse_IA],
                    Jeu* jeu,Joueur* joueurIA
    Procédure qui renvoie la distance entre une case et toute la grille (grilleDistance doit être initialisé à -1 partout)
 */
 void creerGrilleDistances(short int ligne1,short int colonne1,
                                short int (*grilleAnalyse)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                          [_Taille_X_Grille/_Precision_Analyse_IA],
                                short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                          [_Taille_X_Grille/_Precision_Analyse_IA]);
/**
 	\fn choisieCibleIA
 Procédure qui choisie la cible d'un joueurIA et retourne la distance à ce joueur
 	\param Joueur* joueurIA,Jeu* jeu,short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                               [_Taille_X_Grille/_Precision_Analyse_IA]
 */
short int choisieCibleIA(Joueur* joueurIA,Jeu* jeu,short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                                            [_Taille_X_Grille/_Precision_Analyse_IA]);
/**
	\fn choisieDirection
 Procédure qui choisie de la Direction de l'IA
 	\param Joueur* joueurIA,Jeu* jeu,short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                               [_Taille_X_Grille/_Precision_Analyse_IA]
*Procédure qui décide de la direction choisie à chaque tour pour l'IA à partir de la grille des distances
de la cible ou si l'IA n'a pas de cible, la grille des distance de l'IA
 */
void choisieDirection(Joueur* joueurIA,Jeu *jeu,short int distanceJoueurCible,
                      short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                 [_Taille_X_Grille/_Precision_Analyse_IA]);
/**
	\fn indicesGrilleJoueur
 Procédure qui donne les indices ligne et colonne d'un joueur dans la grille
 	\param short int *ligne,short int *colonne,Joueur* joueur
 */
void indicesGrilleJoueur(short int *ligne,short int *colonne,Joueur* joueur);
/**
	\fn testCollisionGenerique
 Fonction qui teste la collision entre deux objets carrés (autrement appelé bounding box)
 	\param float objet1[4],float objet2[4]
 */
char testCollisionGenerique(float objet1[4],float objet2[4]);
/**
    \fn testCollisionMotoBonus
 Fonction qui teste la collision entre la Moto et un Bonus
 	\param Joueur *mesJoueurs,Bonus* bonus
 *Fonction qui teste si une moto rentre en collision avec une Moto,
 renvoie 0 si pas de collision, le numéro du joueur si il y a collision
 */
char testCollisionMotoBonus(Joueur *mesJoueurs,Bonus* bonus);
/**
 \fn PlaceBonus
 Fonction qui place des bonus sur la grille
 	\param Jeu *jeu,Bonus *bonus
 */
void PlaceBonus(Jeu *jeu,Bonus *bonus);
/**
\fn decrementeTempsBonus
 Procedure qui décrémente le tempsBonus des bonus actifs des joueurs
 	\param Jeu *jeu
 */
void decrementeTempsBonus(Jeu *jeu);
/**
    \fn JeuTestRegression
 procédure de test
 */
void JeuTestRegression();

#endif
