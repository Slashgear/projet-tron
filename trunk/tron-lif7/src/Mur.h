#ifndef MUR_H_INCLUDED
#define MUR_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>


/**
*\file [Grid.h]
*\brief Module des vecteurs
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 13 mars 2013
*/

typedef struct{
    unsigned int positionX;
    unsigned int positionY;
    unsigned int tailleX;
    unsigned int tailleY;
    char obstacle;
    unsigned int duree;
}Mur;

/** assesseur de positionX*/
unsigned int getpositionX(Mur m);
/** assesseur de positionY*/
unsigned int getpositionY(Mur m);
/** assesseur de tailleX*/
unsigned int gettailleX(Mur m);
/** assesseur de tailleY*/
unsigned int gettailleY(Mur m);
/** assesseur de obstacle*/
char getobstacle(Mur m);
/** assesseur de duree*/
unsigned int getduree(Mur m);


/** mutateur de positionX*/
void setpositionX(Mur m,unsigned int X);
/** mutateur de positionY*/
void setpositionY(Mur m,unsigned int X);
/** mutateur de tailleX*/
void settailleX(Mur m,unsigned int X);
/** mutateur de tailleY*/
void settailleY(Mur m,unsigned int X);
/** mutateur de obstacle*/
void setobstacle(Mur m,char X);
/** mutateur de duree*/
void setduree(Mur m,unsigned int X);



#endif // MUR_H_INCLUDED
