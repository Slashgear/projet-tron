#include<stdlib.h>
#include<stdio.h>
#include "Grid.h"
#include "Mur.h"
#include "TableauDynamique.h"

float GridGetPositionX(const Grid* grille){
    return grille->positionX;
}
float GridGetPositionY(const Grid* grille){
    return grille->positionY;
}
unsigned int GridGetTailleX(const Grid* grille){
    return grille->tailleX;
}
unsigned int GridGetTailleY(const Grid* grille){
    return grille->tailleY;
}
TableauDynamique* GridGetMesMurs(const Grid* grille){
    return grille->mesMurs;
}
void GridSetPositionX(Grid* grille,float posX){
    grille->positionX=posX;
}
void GridSetPositionY(Grid* grille,float posY){
    grille->positionY=posY;
}
void GridSetTailleX(Grid* grille,unsigned int tailleX){
    grille->tailleX=tailleX;
}
void GridSetTailleY(Grid* grille,unsigned int tailleY){
    grille->tailleY=tailleY;
}
void GridSetMesMurs(Grid* grille,const TableauDynamique* mesMurs){
    grille->mesMurs=mesMurs;
}




