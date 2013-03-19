#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED
#include"Mur.h"
#include<stdlib.h>
#include<stdio.h>
#include"TableauDynamique.h"

/**
*\file [Grid.h]
*\brief Module des vecteurs
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 13 mars 2013
*/

typedef struct {
    float positionX;
    float positionY;
    unsigned int tailleX;
    unsigned int tailleY;
    TableauDynamique* mesMurs;
} Grid;

/**assesseur de positionX*/
float GridGetPositionX(const Grid* grille);
/**assesseur de positionY*/
float GridGetPositionY(const Grid* grille);
/**assesseur de tailleX*/
unsigned int GridGetTailleX(const Grid* grille);
/**assesseur de tailleY*/
unsigned int GridGetTailleY(const Grid* grille);
/**assesseur de mesMurs*/
TableauDynamique* GridGetMesMurs(const Grid* grille);


/**mutateur de positionX*/
void GridSetPositionX(Grid* grille,float posX);
/**mutateur de positionY*/
void GridSetPositionY(Grid* grille,float posY);
/**mutateur de tailleX*/
void GridSetTailleX(Grid* grille,unsigned int tailleX);
/**mutateur de tailleY*/
void GridSetTailleY(Grid* grille,unsigned int tailleY);
/**mutateur de mesMurs*/
void GridSetMesMurs(Grid* grille,const TableauDynamique* mesMurs);

 /** Constructeur de Grid*/
 void GridConstructeur(Grid* grille, float posX, float posY, unsigned int TailleX, unsigned int TailleY, TableauDynamique* mesMurs);
 /** Destructeur de Grid*/
 void GridDestructeur(Grid* grille);
 /** Ajoute un mur*/
 void ajouteMur(TableauDynamique* mesMurs, Mur mur);
 /** Efface un mur*/
 void ajouteMur(TableauDynamique* mesMurs, Mur mur);
 /** Nettoie tous les murs de la Grid*/
 void nettoieGrid(TableauDynamique* mesMurs);

 /** Procedure qui teste le module Grid*/
 void GridTestRegression();


#endif /* GRID_H_INCLUDED */
