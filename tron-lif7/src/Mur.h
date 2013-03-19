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
float MurGetPositionX(const Mur*);
/** assesseur de positionY*/
float MurGetPositionY(const Mur*);
/** assesseur de tailleX*/
unsigned int MurGetTailleX(const Mur* );
/** assesseur de tailleY*/
unsigned int GetTailleY(const Mur* );
/** assesseur de couleur*/
Couleur MurGetCouleur(const Mur* );
/** assesseur de dureeVie*/
float MurGetDureeVie(const Mur* );


/** mutateur de positionX*/
void MurSetpositionX(Mur* ,float );
/** mutateur de positionY*/
void MurSetpositionY(Mur* ,float );
/** mutateur de tailleX*/
void MurSetTailleX(Mur* ,unsigned int );
/** mutateur de tailleY*/
void MurSetTailleY(Mur* ,unsigned int );
/** mutateur de couleur*/
void MurSetCouleur(Mur* ,Couleur );
/** mutateur de dureeVie*/
void MurSetDureeVie(Mur* ,float );

/** Constructeur de Mur*/
void MurConstructeur(Mur* mur,float posX, float posY, unsigned int TailleX, unsigned int TailleY,Couleur couleur, float dureeVie);
/** Destructeur de Mur*/
void MurDestructeur(Mur* mur);

/** Procedure qui teste le module Mur*/
 void MurTestRegression();



#endif /* MUR_H_INCLUDED*/
