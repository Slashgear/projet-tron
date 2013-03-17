#include"Controle.h"
#include<stdlib.h>
#include<stdio.h>

char ControlGetDroite(Controle C){
    return C.touche_droite;
}
char ControlGetHaut(Controle C){
    return C.touche_haut;
}
char ControlGetGauche(Controle C){
    return C.touche_gauche;
}
char ControlGetBas(Controle C){
    return C.touche_bas;
}
void ControlSetDroite(Controle C,char x){
    C.touche_droite=x;
}
void ControlSethaut(Controle C,char x){
    C.touche_haut=x;
}
void ControlSetBas(Controle C,char x){
    C.touche_bas=x;
}
void ControlSetGauche(Controle C,char x){
    C.touche_gauche=x;
}
