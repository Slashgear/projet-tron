#ifndef MOTOS_H_INCLUDED
#define MOTOS_H_INCLUDED
#include<stdlib.h>
#include"Vecteur2D"


/**
\file [Moto.h]
\brief Module des Motos du jeu
\author {Antoine.C,Matthieu.B}
\version 0.1
\date 13 mars 2013
*/

typedef struct{
        float positionX;
        float positionY;
        unsigned int tailleX;
        unsigned int tailleY;
        float vitesse;
        enum {HAUT,BAS,GAUCHE,DROITE} direction;
} Moto;
/** assesseur position X moto*/
float MotoGetPositionX(Moto moto);
/** assesseur position Y moto*/
float MotoGetPositionY(Moto moto);
/** assesseur tailleX moto*/
unsigned int MotoGetTailleX(Moto moto);
/** assesseur tailleY moto*/
unsigned int MotoGetTailleY(Moto moto);
/** assesseur vitesse de moto*/
float MotoGetVitesse(Moto moto);
/** assesseur de direction*/
enum{HAUT,BAS,GAUCHE,DROITE} MotoGetDirection(Moto moto);

/** mutateur de positionX de moto*/
void MotoSetPositionX(Moto m,float posX);
/** mutateur de positionY de moto*/
void MotoSetPositionY(Moto m,float posY);
/**mutateur de dimX moto*/
void MotoSetTailleX(Moto m,unsigned int tailleX);
/**mutateur de dimY moto*/
void MotoSetTailleY(Moto m,unsigned int tailleY);
/**mutateur de vitesse*/
void MotoSetVitesse(Moto m,float vitesse);
/**mutateur de direction*/
void MotoSetDirection(Moto m, enum{HAUT,BAS,GAUCHE,DROITE} direction);

/** Constructeur de Moto*/
void MotoConstructeur(Moto* moto);
/** Destructeur de Moto*/
void MotoDestructeur(Moto* moto);

/** Procedure qui teste le module Moto*/
 void MotoTestRegression();


#endif /* MOTOS_H_INCLUDED */
