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
    Mur * mesMurs;
}Grid;

/**assesseur de positionX*/
unsigned int GridgetpositionX(Grid g);
/**assesseur de positionY*/
unsigned int GridgetpositionY(Grid g);
/**assesseur de tailleX*/
unsigned int GridgettailleX(Grid g);
/**assesseur de tailleY*/
unsigned int GridgettailleY(Grid g);
/**assesseur de mesMurs*/
Mur* GridgetmesMurs(Grid g);


/**mutateur de positionX*/
void GridsetpositionX(Grid g,unsigned int p);
/**mutateur de positionY*/
void GridsetpositionY(Grid g,unsigned int p);
/**mutateur de tailleX*/
void GridsettailleX(Grid g,unsigned int t);
/**mutateur de tailleY*/
void GridsettailleY(Grid g,unsigned int t);
/**mutateur de mesMurs*/
void GridsetmesMurs(Grid g,Mur* m);

/** Constructeur de grille*/
void constructeurGrid(unsigned int positionX,unsigned int positionY,unsigned int tailleX,unsigned int tailleY,Mur * mesMurs)


#endif /* GRID_H_INCLUDED */
