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

/** assesseur de touche droite*/
char ControleGetDroite(const Controle* controle);
/** assesseur de touche haut*/
char ControlGetHaut(const Controle* controle);
/** assesseur de touche bas*/
char ControlGetBas(const Controle* controle);
/** assesseur de touche gauche*/
char ControlGetGauche(const Controle* controle);

/** mutateur de touche droite*/
void ControleSetDroite(Controle* controle,char x);
/** mutateur de touche haut*/
void ControleSetHaut(Controle* controle,char x);
/** mutateur de touche bas*/
void ControleSetBas(Controle* controle,char x);
/**mutateur de touche gauche*/
void ControleSetGauche(Controle* controle,char x);

/** Constructeur de Controle*/
void ControleConstructeur(Controle* controle);
/** Destructeur de Controle*/
void ControleDestructeur(Controle* controle);

/** Procedure qui teste le module Controle*/
 void ControleTestRegression();

#endif /* CONTROLE_H_INCLUDED */
