#include<stdlib.h>
#include<stdio.h>
#include "src/Grid.h"
#include "src/Mur.h"


unsigned int GridgetpositionX(Grid g){
    return g.positionX;
}

unsigned int GridgetpositionY(Grid g){
    return g.positionY;
}

unsigned int GridgettailleX(Grid g){
    return g.tailleX;
}

unsigned int GridgettailleY(Grid g){
    return g.tailleY;
}

void GridsetpositionX(Grid g,unsigned int p){
    //assert(p>=0);
    g.positionX=p;
}
void GridsetpositionY(Grid g,unsigned int p){
    //assert(p>=0);
    g.positionX=p;
}
void GridsettailleX(Grid g,unsigned int t){
   // assert(t>=0);
    g.tailleX=t;
}
void GridsettailleY(Grid g,unsigned int t){
   // assert(t>=0);
    g.tailleY=t;
}
void GridsetmesMurs(Grid g,Mur* mur){
   //assert(mur!=NULL);
    g.mesMurs=mur;
}

void constructeurGrid(unsigned int positionX,unsigned int positionY,unsigned int tailleX,unsigned int tailleY,Mur * mesMurs){
    Grid g;
    GridsetpositionX(&g,0);
    GridgetpositionY(&g,0);
    mesmurs=(Mur *)malloc(tailleY*tailleX*sizeof(Mur)))
}


