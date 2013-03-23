#ifndef MOTOS_H_INCLUDED
#define MOTOS_H_INCLUDED
#include<stdlib.h>



/**
\file [Moto.h]
\brief Module des Motos du jeu
\author {Antoine.C,Matthieu.B}
\version 0.1
\date 13 mars 2013
*/

typedef enum{NON_DIRIGE=0,HAUT=1,BAS=2,GAUCHE=3,DROITE=4} Direction;

typedef struct{
        float positionX;
        float positionY;
        unsigned int tailleX;
        unsigned int tailleY;
        float vitesse;
        Direction direction;
} Moto;
/** assesseur position X moto*/
float MotoGetPositionX(const Moto* moto);
/** assesseur position Y moto*/
float MotoGetPositionY(const Moto* moto);
/** assesseur tailleX moto*/
unsigned int MotoGetTailleX(const Moto* moto);
/** assesseur tailleY moto*/
unsigned int MotoGetTailleY(const Moto* moto);
/** assesseur vitesse de moto*/
float MotoGetVitesse(const Moto* moto);
/** assesseur de direction*/
Direction MotoGetDirection(const Moto* moto);

/** mutateur de positionX de moto*/
void MotoSetPositionX(Moto* m,float posX);
/** mutateur de positionY de moto*/
void MotoSetPositionY(Moto* m,float posY);
/**mutateur de dimX moto*/
void MotoSetTailleX(Moto* m,unsigned int tailleX);
/**mutateur de dimY moto*/
void MotoSetTailleY(Moto* m,unsigned int tailleY);
/**mutateur de vitesse*/
void MotoSetVitesse(Moto* m,float vitesse);
/**mutateur de direction*/
void MotoSetDirection(Moto* m, Direction direction);

/** Constructeur de Moto*/
void MotoConstructeur(Moto* moto,float posX,float posY,unsigned int tailleX, unsigned int tailleY,float vitesse,Direction direction);
/** Destructeur de Moto*/
void MotoDestructeur(Moto* moto);

/** Procedure qui teste le module Moto*/
 void MotoTestRegression();


#endif /* MOTOS_H_INCLUDED */
