#include"Controle.h"
#include<stdlib.h>
#include<stdio.h>
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
    ControleSetDroite(controle, 'n');
    ControleSetGauche(controle, 'n');
    ControleSetHaut(controle, 'n');
    ControleSetBas(controle, 'n');
}


 void ControleTestRegression(){
     Controle unControle;
     SDLKey touchedroite=SDLK_d;
     SDLKey touchegauche=SDLK_q;
     SDLKey touchehaut=SDLK_z;
     SDLKey touchebas=SDLK_s;
     SDLKey touchebonus=SDLK_a;
     ControleConstructeur(&unControle,touchehaut,touchebas,touchegauche,touchedroite,touchebonus);
     printf("Le caractere de la touche droite est %c ,et dans le Controle est %c\n",touchedroite,ControleGetDroite(&unControle));
     printf("Le caractere de la touche gauche est %c ,et dans le Controle est %c\n",touchegauche,ControleGetGauche(&unControle));
     printf("Le caractere de la touche haut est %c ,et dans le Controle est %c\n",touchehaut,ControleGetHaut(&unControle));
     printf("Le caractere de la touche bas est %c ,et dans le Controle est %c\n",touchebas,ControleGetBas(&unControle));
     ControleDestructeur(&unControle);
     printf("Le caractere de la touche droite est %c ,et après destruction est %c\n",touchedroite,ControleGetDroite(&unControle));
     printf("Le caractere de la touche gauche est %c ,et après destruction est %c\n",touchegauche,ControleGetGauche(&unControle));
     printf("Le caractere de la touche haut est %c ,et après destruction est %c\n",touchehaut,ControleGetHaut(&unControle));
     printf("Le caractere de la touche bas est %c ,et après destruction est %c\n\n",touchebas,ControleGetBas(&unControle));
 }

