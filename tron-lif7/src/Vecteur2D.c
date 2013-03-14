#include "Vecteur2D.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float norme(Vecteur2D vecteur){
    return sqrt((vecteur.X)*(vecteur.X)+(vecteur.Y)*(vecteur.Y));
}

float getX(Vecteur2D vecteur){
    return vecteur.X;
}

float getY(Vecteur2D vecteur){
    return vecteur.Y;
}

void setX(Vecteur2D vecteur,float x){
    vecteur.X=x;
}

void setY(Vecteur2D vecteur,float y){
    vecteur.Y=y;
}
