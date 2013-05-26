/**
*\file [Controle.c]
*\brief Module qui défini les Controles
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 13 mars 2013
*/
#include"Controle.h"
#include<stdlib.h>
#include<stdio.h>
#include <assert.h>
#include<SDL/SDL.h>


SDLKey ControleGetDroite(const Controle* controle){
    return controle->droite;
}
SDLKey ControleGetHaut(const Controle* controle){
    return controle->haut;
}
SDLKey ControleGetGauche(const Controle* controle){
    return controle->gauche;
}
SDLKey ControleGetBas(const Controle* controle){
    return controle->bas;
}

SDLKey ControleGetBonus(const Controle* controle){
    return controle->bonus;
}

void ControleSetDroite(Controle* controle,SDLKey x){
    controle->droite=x;
}
void ControleSetHaut(Controle* controle,SDLKey x){
    controle->haut=x;
}

void ControleSetGauche(Controle* controle,SDLKey x){
    controle->gauche=x;
}
void ControleSetBas(Controle* controle,SDLKey x){
    controle->bas=x;
}
void ControleSetBonus(Controle* controle,SDLKey x){
    controle->bonus=x;
}

void ControleConstructeur(Controle* controle, SDLKey haut,SDLKey bas,SDLKey gauche,SDLKey droite,SDLKey bonus){
    ControleSetDroite(controle, droite);
    ControleSetGauche(controle, gauche);
    ControleSetHaut(controle, haut);
    ControleSetBas(controle, bas);
    ControleSetBonus(controle, bonus);
}

void ControleDestructeur(Controle* controle){
    ControleSetDroite(controle, SDLK_F7);
    ControleSetGauche(controle, SDLK_F7);
    ControleSetHaut(controle, SDLK_F7);
    ControleSetBas(controle, SDLK_F7);
    ControleSetBonus(controle, SDLK_F7);
}


 void ControleTestRegression(){
    Controle unControle;
    SDLKey touchehaut=SDLK_z;
    SDLKey touchebas=SDLK_s;
    SDLKey touchegauche=SDLK_q;
    SDLKey touchedroite=SDLK_d;
    SDLKey touchebonus=SDLK_a;
    ControleConstructeur(&unControle,touchehaut,touchebas,touchegauche,touchedroite,touchebonus);
assert(ControleGetDroite(&unControle)==SDLK_d);
    ControleDestructeur(&unControle);
assert(ControleGetDroite(&unControle)==SDLK_F7);
 }

