#include<stdlib.h>
#include<stdio.h>
#include"Moto.h"

float MotoGetPositionX(const Moto* moto){
    return moto->positionX;
}
float MotoGetPositionY(const Moto* moto){
    return moto->positionY;
}
unsigned int MotoGetTailleX(const Moto* moto){
    return moto->tailleX;
}
unsigned int MotoGetTailleY(const Moto* moto){
    return moto->tailleY;
}
float MotoGetVitesse(const Moto* moto){
    return moto->vitesse;
}
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





