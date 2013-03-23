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

void ControleConstructeur(Controle* controle, char droite, char gauche, char haut, char bas){
    ControleSetDroite(controle, droite);
    ControleSetGauche(controle, gauche);
    ControleSetHaut(controle, haut);
    ControleSetBas(controle, bas);

}

void ControleDestructeur(Controle* controle){
    ControleSetDroite(controle, 'n');
    ControleSetGauche(controle, 'n');
    ControleSetHaut(controle, 'n');
    ControleSetBas(controle, 'n');
}


 void ControleTestRegression(){
     Controle unControle;
     char touchedroite='d';
     char touchegauche='g';
     char touchehaut='h';
     char touchebas='b';
     ControleConstructeur(&unControle,touchedroite,touchegauche,touchehaut,touchebas);
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

