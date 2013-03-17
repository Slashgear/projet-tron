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
        unsigned float positionX;
        unsigned float positionY;
        unsigned float dimX;
        unsigned float dimY;
        float vitesse;
        enum {HAUT,BAS,GAUCHE,DROITE}direction;
} Moto;
/** assesseur position X moto*/
unsigned float MotoGetPositionX(Moto m);
/** assesseur position Y moto*/
unsigned float MotoGetPositionY(Moto m);
/** assesseur dimX moto*/
unsigned float MotoGetDimX(Moto m);
/** assesseur dimY moto*/
unsigned float MotoGetDimY(Moto m);
/** assesseur vitesse de moto*/
float MotoGetVitesse(Moto m);
/** assesseur de direction*/
enum{HAUT,BAS,GAUCHE,DROITE} MotoGetDirection(Moto m);

/** mutateur de positionX de moto*/
void MotoSetPositionX(Moto m,unsigned float X);
/** mutateur de positionY de moto*/
void MotoSetPositionY(Moto m,unsigned float Y);
/**mutateur de dimX moto*/
void MotoSetDimX(Moto m,unsigned float X);
/**mutateur de dimY moto*/
void MotoSetDimY(Moto m,unsigned float Y);
/**mutateur de vitesse*/
void MotoSetVitesse(Moto m,float vecteur);
/**mutateur de direction*/
void MotoSetDirection(Moto m, enum{HAUT,BAS,GAUCHE,BAS} direction);




#endif // MOTOS_H_INCLUDED
