#include<stdlib.h>
#include<stdio.h>
#include"Moto.h"

unsigned float MotoGetPositionX(Moto m){
    return m.positionX;
}
unsigned float MotoGetPositionY(Moto m){
    return m.positionY;
}
unsigned float MotoGetDimX(Moto m){
    return m.dimX;
}
unsigned float MotoGetDimY(Moto m){
    return m.dimY;
}
float MotoGetVitesse(Moto m){
    return m.vitesse;
}
enum{HAUT,BAS,GAUCHE,DROITE} MotoGetDirection(Moto m){
    return m.direction;
}

void MotoSetPositionX(Moto m,unsigned float X){
    m.positionX=X;
}
void MotoSetPositionY(Moto m,unsigned float Y){
    m.positionY=Y;
}
void MotoSetDimX(Moto m,unsigned float X){
    m.dimX=X
}
void MotoSetDimY(Moto m,unsigned float Y){
    m.dimY=Y;
}
void MotoSetVitesse(Moto m,float v){
    m.vitesse=v;
}
void MotoSetDirection(Moto m, enum{HAUT,BAS,GAUCHE,BAS} direction){
    m.direction=direction;
}







