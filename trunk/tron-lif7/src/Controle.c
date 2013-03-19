#include"Controle.h"
#include<stdlib.h>
#include<stdio.h>

char ControleGetDroite(const Controle* controle){
    return controle->droite;
}
char ControleGetHaut(const Controle* controle){
    return controle->haut;
}
char ControleGetGauche(const Controle* controle){
    return controle->gauche;
}
char ControleGetBas(const Controle* controle){
    return controle->bas;
}

void ControleSetDroite(Controle* controle,char x){
    controle->droite=x;
}
void ControleSetHaut(Controle* controle,char x){
    controle->haut=x;
}

void ControleSetGauche(Controle* controle,char x){
    controle->gauche=x;
}
void ControleSetBas(Controle* controle,char x){
    controle->bas=x;
}

/** Constructeur de Controle*/
void ControleConstructeur(Controle* controle, char droite, char gauche, char haut, char bas){
    controle = (Controle*) malloc(sizeof(Controle));
    ControleSetDroite(controle, droite);
    ControleSetGauche(controle, gauche);
    ControleSetHaut(controle, haut);
    ControleSetBas(controle, bas);

}
/** Destructeur de Controle*/
void ControleDestructeur(Controle* controle){}

/** Procedure qui teste le module Controle*/
 void ControleTestRegression(){
 }

