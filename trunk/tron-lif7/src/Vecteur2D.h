#ifndef VECTEUR2D_H_INCLUDED
#define VECTEUR2D_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>

/**
*\file [Vecteur2D.h]
*\brief Module des vecteurs
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 13 mars 2013
*/

typedef struct{
    float X;
    float Y;
}Vecteur2D;

/** fonction qui à partir d'un vecteur retourne sa norme euclidenne*/
float norme(Vecteur2D vecteur);
/** assesseur de X*/
float getX(Vecteur2D vecteur);
/** assesseur de Y*/
float getY(Vecteur2D vecteur);
/** mutateur de X*/
void setX(Vecteur2D vecteur,float x);
/** mutateur de Y*/
void setY(Vecteur2D vecteur,float y);


#endif // VECTEUR2D_H_INCLUDED
