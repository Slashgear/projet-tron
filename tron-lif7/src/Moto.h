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
        unsigned int positionX;
        unsigned int positionY;
        unsigned int dimX;
        unsigned int dimY;
        Vector2D vitesse;
} Moto;

/** assesseur position X moto*/
unsigned int motopositionX(Moto m);

/** assesseur position Y moto*/
unsigned int motopositionX(Moto m);

/** assesseur dimX moto*/
unsigned int motodimX(Moto m);

/** assesseur dimX moto*/
unsigned int motodimX(Moto m);

/** assesseur vitesse de moto*/
Vector2D getvitesse(Moto m);





#endif // MOTOS_H_INCLUDED
