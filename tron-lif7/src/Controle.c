#include"Controle.h"
#include<stdlib.h>
#include<stdio.h>

char gettouche_droite(Controle C){
    return C.touche_droite;
}
char gettouche_haut(Controle C){
    return C.touche_haut;
}
char gettouche_gauche(Controle C){
    return C.touche_gauche;
}
char gettouche_bas(Controle C){
    return C.touche_bas;
}
void settouche_droite(Controle C,char x){
    C.touche_droite=x;
}
void settouche_haut(Controle C,char x){
    C.touche_haut=x;
}
void settouche_bas(Controle C,char x){
    C.touche_bas=x;
}
void settouche_gauche(Controle C,char x){
    C.touche_gauche=x;
}
