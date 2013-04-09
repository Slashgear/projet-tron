#ifndef CONTROLE_H_INCLUDED
#define CONTROLE_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>
#include <SDL/SDL.h>

/**
*\file [Controle.h]
*\brief Module des vecteurs
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 13 mars 2013
*/

typedef struct{
    SDLKey droite;
    SDLKey haut;
    SDLKey bas;
    SDLKey gauche;
    SDLKey bonus;
}Controle;

/** assesseur de touche droite*/
SDLKey ControleGetDroite(const Controle* controle);
/** assesseur de touche haut*/
SDLKey ControleGetHaut(const Controle* controle);
/** assesseur de touche bas*/
SDLKey ControleGetBas(const Controle* controle);
/** assesseur de touche gauche*/
SDLKey ControleGetGauche(const Controle* controle);
/** assesseur de touche bonus*/
SDLKey ControleGetBonus(const Controle* controle);

/** mutateur de touche droite*/
void ControleSetDroite(Controle* controle,SDLKey x);
/** mutateur de touche haut*/
void ControleSetHaut(Controle* controle,SDLKey x);
/** mutateur de touche bas*/
void ControleSetBas(Controle* controle,SDLKey x);
/** mutateur de touche gauche*/
void ControleSetGauche(Controle* controle,SDLKey x);
/** mutateur de touche bonus*/
void ControleSetBonus(Controle* controle,SDLKey x);

/** Constructeur de Controle*/
void ControleConstructeur(Controle* controle, SDLKey haut,SDLKey bas,SDLKey gauche,SDLKey droite,SDLKey bonus);
/** Destructeur de Controle*/
void ControleDestructeur(Controle* controle);

/** Procedure qui teste le module Controle*/
 void ControleTestRegression();

#endif /* CONTROLE_H_INCLUDED */
