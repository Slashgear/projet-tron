#ifndef CONTROLE_H_INCLUDED
#define CONTROLE_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>

/**
*\file [Controle.h]
*\brief Module des vecteurs
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 13 mars 2013
*/

typedef struct{
    char touche_droite;
    char touche_haut;
    char touche_bas;
    char touche_gauche;
}Controls;

/** assesseur de touche_droite*/
char gettouche_droite(touche_droite d);
/** assesseur de touche_haut*/
char gettouche_haut(touche_haut h);
/** assesseur de touche_bas*/
char gettouche_bas(touche_bas b);
/** assesseur de touche_gauche*/
char gettouche_gauche(touche_gauche g);

/** mutateur de touche_droite*/
void setX(touche_droite d,char x);
/** mutateur de touche_haut*/
void setY(touche_haut h,char x);
/** mutateur de touche_bas*/
void setY(touche_bas b,char x);
/**mutateur de touche_gauche*/
void setY(touche_gauche g,char x);

#endif // CONTROLE_H_INCLUDED
