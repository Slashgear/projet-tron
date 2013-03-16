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
        Vecteur2D vitesse;
} Moto;

/** assesseur position X moto*/
unsigned int motogetpositionX(Moto m);

/** assesseur position Y moto*/
unsigned int motogetpositionY(Moto m);

/** assesseur dimX moto*/
unsigned int motogetdimX(Moto m);

/** assesseur dimY moto*/
unsigned int motogetdimY(Moto m);

/** assesseur vitesse de moto*/
Vector2D motogetvitesse(Moto m);





/** mutateur de positionX de moto*/
void motosetpositionX(Moto m,unsigned int X);

/** mutateur de positionY de moto*/
void motosetpositionY(Moto m,unsigned int Y);

/**mutateur de dimX moto*/
void motosetdimX(Moto m,unsigned int X);

/**mutateur de dimY moto*/
void motosetdimY(Moto m,unsigned int Y);

/**mutateur de vitesse*/
void motosetvitesse(Moto m,Vector2D vecteur);




#endif // MOTOS_H_INCLUDED
