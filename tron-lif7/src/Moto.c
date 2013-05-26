/**
\file [Moto.c]
\brief Module des Motos du jeu
\author {Antoine.C,Matthieu.B}
\version 0.1
\date 13 mars 2013
*/
#include<stdlib.h>
#include<stdio.h>
#include"Moto.h"


float MotoGetPositionX(const Moto* moto){
    return moto->positionX;
}
float MotoGetPositionY(const Moto* moto){
    return moto->positionY;
}
unsigned int MotoGetTailleX(const Moto* moto){
    return moto->tailleX;
}
unsigned int MotoGetTailleY(const Moto* moto){
    return moto->tailleY;
}
float MotoGetVitesse(const Moto* moto){
    return moto->vitesse;
}
Direction MotoGetDirection(const Moto* moto){
    return moto->direction;
}

void MotoSetPositionX(Moto* moto,float posX){
    moto->positionX=posX;
}
void MotoSetPositionY(Moto* moto,float posY){
    moto->positionY=posY;
}
void MotoSetTailleX(Moto* moto,unsigned int tailleX){
    moto->tailleX=tailleX;
}
void MotoSetTailleY(Moto* moto,unsigned int tailleY){
    moto->tailleY=tailleY;
}
void MotoSetVitesse(Moto* moto,float vitesse){
    moto->vitesse=vitesse;
}
void MotoSetDirection(Moto* moto, Direction direction){
    moto->direction=direction;
}

void MotoConstructeur(Moto* moto,float posX,float posY,unsigned int tailleX, unsigned int tailleY,float vitesse,Direction direction){
    MotoSetPositionX(moto,posX);
    MotoSetPositionY(moto,posY);
    MotoSetTailleX(moto,tailleX);
    MotoSetTailleY(moto,tailleY);
    MotoSetVitesse(moto,vitesse);
    MotoSetDirection(moto,direction);
}
void MotoDestructeur(Moto* moto){
    MotoSetPositionX(moto,0);
    MotoSetPositionY(moto,0);
    MotoSetTailleX(moto,0);
    MotoSetTailleY(moto,0);
    MotoSetVitesse(moto,0);
    MotoSetDirection(moto,NON_DIRIGE);
}

 void MotoTestRegression(){
    Moto moto;
    float posX=1;
    float posY=1;
    unsigned int tailleX=10;
    unsigned int tailleY=10;
    float vitesse=20;
    Direction direction=HAUT;
    MotoConstructeur(&moto,posX,posY,tailleX,tailleY,vitesse,direction);
    printf("La valeur posX est %f et dans Moto est de %f \n",posX,MotoGetPositionX(&moto));
    printf("La valeur posY est %f et dans Moto est de %f \n",posY,MotoGetPositionY(&moto));
    printf("La valeur tailleX est %u et dans Moto est de %u \n",tailleX,MotoGetTailleX(&moto));
    printf("La valeur tailleY est %u et dans Moto est de %u \n",tailleY,MotoGetTailleY(&moto));
    printf("La valeur vitesse est %f et dans Moto est de %f \n",vitesse,MotoGetVitesse(&moto));
    printf("La valeur de direction est de %d et dans Moto est de %d \n",direction,MotoGetDirection(&moto));
    MotoDestructeur(&moto);
    printf("Après destruction la posX Moto est de %f \n",MotoGetPositionX(&moto));
    printf("Après destruction la posY Moto est de %f \n",MotoGetPositionY(&moto));
    printf("Après destruction tailleX  Moto est de %u \n",MotoGetTailleX(&moto));
    printf("Après destruction tailleY  Moto est de %u \n",MotoGetTailleY(&moto));
    printf("Après destruction vitesse  Moto est de %f \n",MotoGetVitesse(&moto));
    printf("Après destruction de direction  Moto est de %d \n\n",MotoGetDirection(&moto));
}





