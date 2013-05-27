/**
*\file [Mur.h]
*\brief Module des Murs du Jeu
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 13 mars 2013
*/
#ifndef MUR_H_INCLUDED
#define MUR_H_INCLUDED

#include<stdlib.h>
#include<stdio.h>
#include"Couleur.h"
/**
 * \struct Mur
 * \brief Structure d'un Mur
 */
typedef struct{
    float positionX;
    float positionY;
    unsigned int tailleX;
    unsigned int tailleY;
    Couleur couleur;
    float dureeVie;
}Mur;
/**
 * \fn MurGetPositionX
 * \brief assesseur de positionX
 * \param const Mur* mur
 * \return positionX
 */
float MurGetPositionX(const Mur* mur);
/**
 * \fn MurGetPositionY
 * \brief assesseur de positionY
 * \param const Mur* mur
 * \return positionY
 */
float MurGetPositionY(const Mur* mur);
/**
 * \fn MurGetTailleX
 * \brief assesseur de tailleX
 * \param const Mur* mur
 * \return tailleX
 */
unsigned int MurGetTailleX(const Mur* mur);
/**
 * \fn MurGetTailleY
 * \brief assesseur de tailleY
 * \param const Mur* mur
 * \return tailleY
 */
unsigned int MurGetTailleY(const Mur* mur);
/**
 * \fn MurGetCouleur
 * \brief assesseur de couleur
 * \param const Mur* mur
 * \return Couleur
 */
Couleur MurGetCouleur(const Mur* mur);
/**
 * \fn MurGetDureeVie
 * \brief assesseur de DureeVie
 * \param const Mur* mur
 * \return duree de Vie de Mur
 */
float MurGetDureeVie(const Mur* mur);

/**
 * \fn MurSetPositionX
 * \brief mutateur de positionX
 * \param Mur* mur,float posX
 */
void MurSetPositionX(Mur* mur,float posX);
/**
 * \fn MurSetPositionY
 * \brief mutateur de positionY
 * \param Mur* mur,float posY
 */
void MurSetPositionY(Mur* mur,float posY);
/**
 * \fn MurSetTailleX
 * \brief mutateur de tailleX
 * \param Mur* mur,float tailleX
 */
void MurSetTailleX(Mur* mur,unsigned int tailleX);
/**
 * \fn MurSetTailleY
 * \brief mutateur de tailleY
 * \param Mur* mur,float tailleY
 */
void MurSetTailleY(Mur* mur,unsigned int tailleY);
/**
 * \fn MurSetCouleur
 * \brief mutateur de couleur
 * \param Mur* mur,Couleur couleur
 */
void MurSetCouleur(Mur* mur,Couleur couleur);
/**
 * \fn MurSetDureeVie
 * \brief mutateur de Duree Vie
 * \param Mur* mur,float dureeVie
 */
void MurSetDureeVie(Mur* mur,float dureeVie);
/**
 * \fn AfficheStatsMur
 * \brief Affichage des Stats des Murs
 * \param Mur* mur
 */
void AfficheStatsMur(Mur* mur);

/**
 * \fn MurConstructeur
 * \brief Constructeur du Murs
 * \param Mur* mur,float posX, float posY, unsigned int tailleX, unsigned int tailleY,Couleur couleur, float dureeVie
 */
void MurConstructeur(Mur* mur,float posX, float posY, unsigned int tailleX, unsigned int tailleY,Couleur couleur, float dureeVie);
/**
 * \fn MurDestructeur
 * \brief Destructeur du Murs
 * \param Mur* mur
 */
void MurDestructeur(Mur* mur);

/**
 * \fn MurTestRegression
 * \brief Procédure qui teste le Module
 */
 void MurTestRegression();



#endif /* MUR_H_INCLUDED*/
