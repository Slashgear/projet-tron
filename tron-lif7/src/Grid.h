/**
*\file [Grid.h]
*@brief Module des vecteurs
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
 * @brief Structure de la grille
 */
typedef struct {
    float positionX; /*!< Position X de la grille */
    float positionY; /*!< Position Y de la grille */
    unsigned int tailleX; /*!< Taille X de la grille */
    unsigned int tailleY; /*!< Taille Y de la grille*/
    TableauDynamiqueMur mesMurs; /*!< Tableau des Murs */
} Grid;
/**
 * \fn GridGetPositionX
 * @brief assesseur de positionX
 * @param const Grid*
 * \return positionX
 */
float GridGetPositionX(const Grid* );
/**
 * \fn GridGetPositionY
 * @brief assesseur de positionY
 * @param const Grid*
 * \return positionY
 */
float GridGetPositionY(const Grid* );
/**
 * \fn GridGetTailleX
 * @brief assesseur de tailleX
 * @param const Grid*
 * \return tailleX
 */
unsigned int GridGetTailleX(const Grid* );
/**
 * \fn GridGetTailleY
 * @brief assesseur de tailleY
 * @param const Grid*
 * \return tailleY
 */
unsigned int GridGetTailleY(const Grid*);
/**
 * \fn GridGetTailleY
 * @brief assesseur de mesMurs
 * @param const Grid*
 * \return pointeur de tableau Dynamique
 */
TableauDynamiqueMur* GridGetMesMurs(Grid*);

/**
 * \fn GridSetPositionX
 * @brief mutateur de positionX
 * @param Grid* grille,float posX
 */
void GridSetPositionX(Grid* grille,float posX);
/**
 * \fn GridSetPositionY
 * @brief mutateur de positionY
 * @param Grid* grille,float posY
 */
void GridSetPositionY(Grid* grille,float posY);
/**
 * \fn GridSetTailleX
 * @brief mutateur de tailleX
 * @param Grid* ,unsigned int tailleX
 */
void GridSetTailleX(Grid* ,unsigned int );
/**
 * \fn GridSetTailleY
 * @brief mutateur de tailleY
 * @param Grid* ,unsigned int tailleY
 */
void GridSetTailleY(Grid* ,unsigned int );
/**
 * \fn GridSetMesMurs
 * @brief mutateur de mesMurs
 * @param Grid* ,TableauDynamiqueMur*
 */
void GridSetMesMurs(Grid* ,TableauDynamiqueMur* );
/**
 * \fn GridConstructeur
 * @brief Constructeur de Grid
 * @param Grid* , float , float , unsigned int , unsigned int ,TableauDynamiqueMur*
 */
 void GridConstructeur(Grid* , float , float , unsigned int , unsigned int ,TableauDynamiqueMur* );
 /**
 * \fn GridDestructeur
 * @brief Destructeur de Grid
 * @param Grid*
 */
 void GridDestructeur(Grid* grille);
  /**
 * \fn ajouteMur
 * @brief ajoute un Mur au tableau Dynamique de Murs
 * @param TableauDynamiqueMur* mesMurs, Mur mur
 */
 void ajouteMur(TableauDynamiqueMur* mesMurs, Mur mur);
   /**
 * \fn effaceMur
 * @brief Efface les Murs qui ont une durée de Vie <1
 * @param ableauDynamiqueMur* mesMurs
 */
 void effaceMur(TableauDynamiqueMur* mesMurs);
  /**
 * \fn nettoieGrid
 * @brief Nettoie tous les murs de la Grid en setant leur durée Vie à 0.
 * @param Grid*
 */
 void nettoieGrid(TableauDynamiqueMur* mesMurs);
  /**
 * \fn decrementeVieMur
 * @brief décrementation de la durée de vie des murs
 * @param Grid*
 */
 void decrementeVieMur(Grid* grille);
 /**
 * \fn GridTestRegression
 * @brief procédure de Test du module
 */
 void GridTestRegression();


#endif /* GRID_H_INCLUDED */
