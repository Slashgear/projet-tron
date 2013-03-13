#include "Vecteur2D.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float norme(Vector2D vecteur){
    return sqrt((vecteur.X)*(vecteur.X)+(vecteur.Y)*(vecteur.Y));
}

float getX(Vector2D vecteur){
    return vecteur.X;
}

float getY(Vector2D vecteur){
    return vecteur.Y;
}

void setX(Vector2D vecteur,float x){
    vecteur.X=x;
}

void setY(Vector2D vecteur,float y){
    vecteur.Y=y;
}
