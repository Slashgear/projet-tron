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
void GridSetMesMurs(Grid* grille,TableauDynamique* mesMurs){
    grille->mesMurs=mesMurs;
}
void GridConstructeur(Grid* grille, float posX, float posY, unsigned int TailleX, unsigned int TailleY,TableauDynamique* mesMurs){
    GridSetPositionX(grille,posX);
    GridSetPositionY(grille,posY);
    GridSetTailleX(grille,TailleX);
    GridSetTailleY(grille,TailleY);
    GridSetMesMurs(grille,mesMurs);
    initialiserTabDyn(GridGetMesMurs(grille));
}
void GridDestructeur(Grid* grille){
    GridSetPositionX(grille,0);
    GridSetPositionY(grille,0);
    GridSetTailleX(grille,0);
    GridSetTailleY(grille,0);
    testamentTabDyn(GridGetMesMurs(grille));
    GridSetMesMurs(grille,NULL);
}

 void ajouteMur(TableauDynamique* mesMurs, Mur* mur){
    ajouterElementTabDyn(mesMurs,mur);
 }




