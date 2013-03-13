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
    unsigned int positionX; //positionX de la première case
    unsigned int positionY; //positionY de la première case
    unsigned int tailleX;
    unsigned int tailleY;
    Mur * tab_terrain;
}Mur;




#endif // MUR_H_INCLUDED
