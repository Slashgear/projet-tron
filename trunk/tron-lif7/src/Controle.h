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
}Controle;

/** assesseur de touche_droite*/
char gettouche_droite(Controle C);
/** assesseur de touche_haut*/
char gettouche_haut(Controle C);
/** assesseur de touche_bas*/
char gettouche_bas(Controle C);
/** assesseur de touche_gauche*/
char gettouche_gauche(Controle C);

/** mutateur de touche_droite*/
void settouche_droite(Controle C,char x);
/** mutateur de touche_haut*/
void settouche_haut(Controle C,char x);
/** mutateur de touche_bas*/
void settouche_bas(Controle C,char x);
/**mutateur de touche_gauche*/
void settouche_gauche(Controle C,char x);

#endif // CONTROLE_H_INCLUDED
