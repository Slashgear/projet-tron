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
    unsigned float positionX;
    unsigned float positionY;
    unsigned int tailleX;
    unsigned int tailleY;
    Mur * mesMurs;
}Grid;

/**assesseur de positionX*/
unsigned float GridGetPositionX(Grid g);
/**assesseur de positionY*/
unsigned float GridGetPositionY(Grid g);
/**assesseur de tailleX*/
unsigned int GridGetTailleX(Grid g);
/**assesseur de tailleY*/
unsigned int GridGetTailleY(Grid g);
/**assesseur de mesMurs*/
Mur* GridGetMesMurs(Grid g);


/**mutateur de positionX*/
void GridSetPositionX(Grid g,unsigned float p);
/**mutateur de positionY*/
void GridSetPositionY(Grid g,unsigned float p);
/**mutateur de tailleX*/
void GridSetTailleX(Grid g,unsigned int t);
/**mutateur de tailleY*/
void GridSetTailleY(Grid g,unsigned int t);
/**mutateur de mesMurs*/
void GridSetMesMurs(Grid g,Mur* m);

/** Constructeur de grille*/


#endif /* GRID_H_INCLUDED */
