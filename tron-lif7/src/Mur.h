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
    bool obstacle;
    unsigned int duree;
}Mur;




#endif // MUR_H_INCLUDED
