#include<stdlib.h>
#include<stdio.h>
#include "Grid.h"
#include "Mur.h"


unsigned float GridGetPositionX(Grid g){
    return g.positionX;
}

unsigned float GridGetPositionY(Grid g){
    return g.positionY;
}

unsigned int GridGetTailleX(Grid g){
    return g.tailleX;
}

unsigned int GridGetTailleY(Grid g){
    return g.tailleY;
}

void GridSetPositionX(Grid g,unsigned float p){
    //assert(p>=0);
    g.positionX=p;
}
void GridSetPositionY(Grid g,unsigned float p){
    //assert(p>=0);
    g.positionX=p;
}
void GridSetTailleX(Grid g,unsigned int t){
   // assert(t>=0);
    g.tailleX=t;
}
void GridSetTailleY(Grid g,unsigned int t){
   // assert(t>=0);
    g.tailleY=t;
}
void GridSetMesMurs(Grid g,Mur* mur){
   //assert(mur!=NULL);
    g.mesMurs=mur;
}

