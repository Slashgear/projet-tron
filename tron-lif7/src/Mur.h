/**
	\file [Mur.h]
	 Module des Murs du Jeu
	\author {Antoine.C,Matthieu.B}
	\version 0.1
	\date 13 mars 2013
*/
#ifndef MUR_H_INCLUDED
#define MUR_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include"Couleur.h"
/**
 	\struct Mur
 Structure d'un Mur
 */
typedef struct{
    float positionX;
    float positionY;
    unsigned int tailleX;
    unsigned int tailleY;
    Couleur couleur;
    float dureeVie;
}Mur;
/**
 	\fn MurGetPositionX
 assesseur de positionX
 	\param const Mur* mur
 	\return positionX
 */
float MurGetPositionX(const Mur* mur);
/**
 	\fn MurGetPositionY
 assesseur de positionY
 	\param const Mur* mur
 	\return positionY
 */
float MurGetPositionY(const Mur* mur);
/**
 	\fn MurGetTailleX
 assesseur de tailleX
 	\param const Mur* mur
 	\return tailleX
 */
unsigned int MurGetTailleX(const Mur* mur);
/**
 	\fn MurGetTailleY
 assesseur de tailleY
 	\param const Mur* mur
 	\return tailleY
 */
unsigned int MurGetTailleY(const Mur* mur);
/**
 	\fn MurGetCouleur
 assesseur de couleur
 	\param const Mur* mur
 	\return Couleur
 */
Couleur MurGetCouleur(const Mur* mur);
/**
 	\fn MurGetDureeVie
 assesseur de DureeVie
 	\param const Mur* mur
 	\return duree de Vie de Mur
 */
float MurGetDureeVie(const Mur* mur);

/**
 	\fn MurSetPositionX
 mutateur de positionX
 	\param Mur* mur,float posX
 */
void MurSetPositionX(Mur* mur,float posX);
/**
 	\fn MurSetPositionY
 mutateur de positionY
 	\param Mur* mur,float posY
 */
void MurSetPositionY(Mur* mur,float posY);
/**
 	\fn MurSetTailleX
 mutateur de tailleX
 	\param Mur* mur,float tailleX
 */
void MurSetTailleX(Mur* mur,unsigned int tailleX);
/**
 	\fn MurSetTailleY
 mutateur de tailleY
 	\param Mur* mur,float tailleY
 */
void MurSetTailleY(Mur* mur,unsigned int tailleY);
/**
 	\fn MurSetCouleur
 mutateur de couleur
 	\param Mur* mur,Couleur couleur
 */
void MurSetCouleur(Mur* mur,Couleur couleur);
/**
 	\fn MurSetDureeVie
 mutateur de Duree Vie
 	\param Mur* mur,float dureeVie
 */
void MurSetDureeVie(Mur* mur,float dureeVie);
/**
 	\fn AfficheStatsMur
 Affichage des Stats des Murs
 	\param Mur* mur
 */
void AfficheStatsMur(Mur* mur);

/**
 	\fn MurConstructeur
 Constructeur du Murs
 	\param Mur* mur,float posX, float posY, unsigned int tailleX, unsigned int tailleY,Couleur couleur, float dureeVie
 */
void MurConstructeur(Mur* mur,float posX, float posY, unsigned int tailleX, unsigned int tailleY,Couleur couleur, float dureeVie);
/**
 	\fn MurDestructeur
 Destructeur du Murs
 	\param Mur* mur
 */
void MurDestructeur(Mur* mur);

/**
 	\fn MurTestRegression
 Procédure qui teste le Module
 */
 void MurTestRegression();



#endif /* MUR_H_INCLUDED*/
