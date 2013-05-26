/**
*\file [Grid.h]
*\brief Module des vecteurs
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 13 mars 2013
*/
#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED
#include"Mur.h"
#include<stdlib.h>
#include<stdio.h>
#include"TableauDynamiqueMur.h"

/**
 * \struct Grid
 * \brief Structure de la grille
 */
typedef struct {
    float positionX; /*!< Position X de la grille */
    float positionY; /*!< Position Y de la grille */
    unsigned int tailleX; /*!< Taille X de la grille */
    unsigned int tailleY; /*!< Taille Y de la grille*/
    TableauDynamiqueMur mesMurs; /*!< Tableau des Murs */
} Grid;

/**assesseur de positionX*/
float GridGetPositionX(const Grid* );
/**assesseur de positionY*/
float GridGetPositionY(const Grid* );
/**assesseur de tailleX*/
unsigned int GridGetTailleX(const Grid* );
/**assesseur de tailleY*/
unsigned int GridGetTailleY(const Grid*);
/**assesseur de mesMurs*/
TableauDynamiqueMur* GridGetMesMurs(Grid*);


/**mutateur de positionX*/
void GridSetPositionX(Grid* grille,float posX);
/**mutateur de positionY*/
void GridSetPositionY(Grid* grille,float posY);
/**mutateur de tailleX*/
void GridSetTailleX(Grid* ,unsigned int );
/**mutateur de tailleY*/
void GridSetTailleY(Grid* ,unsigned int );
/**mutateur de mesMurs*/
void GridSetMesMurs(Grid* ,TableauDynamiqueMur* );

 /** Constructeur de Grid*/
 void GridConstructeur(Grid* , float , float , unsigned int , unsigned int ,TableauDynamiqueMur* );
 /** Destructeur de Grid*/
 void GridDestructeur(Grid* grille);
 /** Ajoute un mur*/
 void ajouteMur(TableauDynamiqueMur* mesMurs, Mur mur);
 /** Efface un mur*/
 void effaceMur(TableauDynamiqueMur* mesMurs);
 /** Nettoie tous les murs de la Grid*/
 void nettoieGrid(TableauDynamiqueMur* mesMurs);
 /** décrementation de la durée de vie des murs*/
 void decrementeVieMur(Grid* grille);

 /** Procedure qui teste le module Grid*/
 void GridTestRegression();


#endif /* GRID_H_INCLUDED */
