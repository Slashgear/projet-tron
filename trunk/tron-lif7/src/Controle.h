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
    char droite;
    char haut;
    char bas;
    char gauche;
}Controle;

/** assesseur de touche_droite*/
char ControlGetDroite(Controle C);
/** assesseur de touche_haut*/
char ControlGetHaut(Controle C);
/** assesseur de touche_bas*/
char ControlGetBas(Controle C);
/** assesseur de touche_gauche*/
char ControlGetGauche(Controle C);

/** mutateur de touche_droite*/
void ControlSetDroite(Controle C,char x);
/** mutateur de touche_haut*/
void ControlSetHaut(Controle C,char x);
/** mutateur de touche_bas*/
void ControlSetBas(Controle C,char x);
/**mutateur de touche_gauche*/
void ControlSetGauche(Controle C,char x);

#endif // CONTROLE_H_INCLUDED
