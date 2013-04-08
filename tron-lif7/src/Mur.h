#ifndef MUR_H_INCLUDED
#define MUR_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include"Couleur.h"

/**
*\file [Grid.h]
*\brief Module des vecteurs
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 13 mars 2013
*/


typedef struct{
    float positionX;
    float positionY;
    unsigned int tailleX;
    unsigned int tailleY;
    Couleur couleur;
    float dureeVie;
}Mur;

/** assesseur de positionX*/
float MurGetPositionX(const Mur* mur);
/** assesseur de positionY*/
float MurGetPositionY(const Mur* mur);
/** assesseur de tailleX*/
unsigned int MurGetTailleX(const Mur* mur);
/** assesseur de tailleY*/
unsigned int MurGetTailleY(const Mur* mur);
/** assesseur de couleur*/
Couleur MurGetCouleur(const Mur* mur);
/** assesseur de dureeVie*/
float MurGetDureeVie(const Mur* mur);


/** mutateur de positionX*/
void MurSetPositionX(Mur* mur,float posX);
/** mutateur de positionY*/
void MurSetPositionY(Mur* mur,float posY);
/** mutateur de tailleX*/
void MurSetTailleX(Mur* mur,unsigned int tailleX);
/** mutateur de tailleY*/
void MurSetTailleY(Mur* mur,unsigned int tailleY);
/** mutateur de couleur*/
void MurSetCouleur(Mur* mur,Couleur couleur);
/** mutateur de dureeVie*/
void MurSetDureeVie(Mur* mur,float dureeVie);
/** affiche les stats des murs crée*/
void AfficheStatsMur(Mur* mur);


/** Constructeur de Mur*/
void MurConstructeur(Mur* mur,float posX, float posY, unsigned int tailleX, unsigned int tailleY,Couleur couleur, float dureeVie);
/** Destructeur de Mur*/
void MurDestructeur(Mur* mur);


/** Procedure qui teste le module Mur*/
 void MurTestRegression();



#endif /* MUR_H_INCLUDED*/
