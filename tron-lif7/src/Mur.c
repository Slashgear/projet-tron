#include<stdlib.h>
#include<stdio.h>
#include"Couleur.h"
#include"Mur.h"

float MurGetPositionX(const Mur* mur){
    return mur->positionX;
}
float MurGetPositionY(const Mur* mur){
    return mur->positionY;
}
unsigned int MurGetTailleX(const Mur* mur){
    return mur->tailleX;
}
unsigned int MurGetTailleY(const Mur* mur){
    return mur->tailleY;
}
Couleur MurGetCouleur(const Mur* mur){
    return mur->couleur;
}
float MurGetDureeVie(const Mur* mur){
    return mur->dureeVie;
}

void MurSetPositionX(Mur* mur,float posX){
    mur->positionX=posX;
}
void MurSetPositionY(Mur* mur,float posY){
    mur->positionY=posY;
}
void MurSetTailleX(Mur* mur,unsigned int tailleX){
    mur->tailleX=tailleX;
}
void MurSetTailleY(Mur* mur,unsigned int tailleY){
    mur->tailleY=tailleY;
}
void MurSetCouleur(Mur* mur,Couleur couleur){
    mur->couleur=couleur;
}
void MurSetDureeVie(Mur* mur,float duree){
    mur->dureeVie=duree;
}


void MurConstructeur(Mur* mur,float posX, float posY, unsigned int TailleX, unsigned int TailleY,Couleur couleur, float dureeVie){
    mur=(Mur*)malloc(sizeof(Mur));
    MurSetpositionX(mur,posX);
    MurSetpositionY(mur,posY);
    MurSetTailleX(mur,TailleX);
    MurSetTailleY(mur,TailleY);
    MurSetCouleur(mur,couleur);
    MurSetDureeVie(mur,dureeVie);
}
void MurDestructeur(Mur* mur){
    free(mur);
    mur=0;
}



void MurTestRegression(){
    /*mur est utilisé sans être initialisé*/
    Mur mur;
    float posX=0;
    float posY=0;
    unsigned int tailleX=10;
    unsigned int tailleY=10;
    Couleur couleur=1;
    float dureeVie=10;
    MurConstructeur(&mur,posX,posY,tailleX,tailleY,couleur,dureeVie);
    printf("La valeur posX est %f et dans Mur est de %f \n",posX,MurGetPositionX(&mur));
    printf("La valeur posY est %f et dans Mur est de %f \n",posY,MurGetPositionY(&mur));
    printf("La valeur tailleX est %u et dans Mur est de %u \n",tailleX,MurGetTailleX(&mur));
    printf("La valeur tailleY est %u et dans Mur est de %u \n",tailleY,MurGetTailleY(&mur));
    printf("La durée de vie est de %f et dasn Mur est de %f\n",dureeVie,MurGetDureeVie(&mur));
    MurDestructeur(&mur);
}
