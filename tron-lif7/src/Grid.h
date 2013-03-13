#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED
#include"Mur.h"
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
    Mur * tab_cases;
}Grid;

/**assesseur de positionX*/
unsigned int GridgetpositionX(Grid g);
/**assesseur de positionY*/
unsigned int GridgetpositionY(Grid g);
/**assesseur de tailleX*/
unsigned int GridgettailleX(Grid g);
/**assesseur de tailleY*/
unsigned int GridgettailleY(Grid g);


#endif // GRID_H_INCLUDED
