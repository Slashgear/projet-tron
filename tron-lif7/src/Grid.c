#include<stdlib.h>
#include<stdio.h>
#include "Grid.h"
#include "Mur.h"
#include "TableauDynamique.h"
#include "assert.h"

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

void effaceMur(TableauDynamique* mesMurs){
    int i;
    for(i=0;i<=TabDynGetTaille_utilisee(&mesMurs);i++){
        if(MurGetDureeVie(&valeurIemeElementTabDyn(mesMurs,i))==0)
        {
            supprimerElementTabDyn(mesMurs,i);
        }
    }
}
void nettoieGrid(TableauDynamique* mesMurs){
    int i;
    for(i=0;i<=TabDynGetTaille_utilisee(&mesMurs);i++){
    supprimerElementTabDyn(mesMurs,i);
    }
}

 void GridTestRegression(){
    Grid grille;
    float posX=10
    float posY=5
    unsigned int tailleX=3
    unsigned int tailleY=4
    TableauDynamique mesMurs;
    Mur unMur;
    GridConstructeur(&grille,posX,posY,tailleX,tailleY,mesMurs);
    printf("La valeur de PosX saisie est %f et dans Grid est %f\n",posX,GridGetPositionX(&grille));
    printf("La valeur de PosY saisie est %f et dans Grid est %f\n",posY,GridGetPositionY(&grille));
    printf("La valeur de tailleX saisie est %u et dans Grid est %u\n",tailleX,GridGetTailleX(&grille));
    printf("La valeur de tailleY saisie est %u et dans Grid est %u\n",tailleY,GridGetTailleY(&grille));
    ajouteMur(mesMur,Mur);
    assert(TabDynGetTaille_utilisee(mesMurs)!=1);
    MurSetDureeVie(&unMur,0);
    effaceMur(&mesMurs);
    assert(TabDynGetTaille_utilisee(mesMurs)!=0);
    ajouteMur(mesMur,Mur);
    nettoieGrid(mesMurs);
    assert(TabDynGetTaille_utilisee(mesMurs)!=0);
    GridDestructeur(&grille);
    printf("Après destruction la valeur de PosX est %f\n",GridGetPositionX(&grille));
    printf("Après destruction la valeur de PosY est %f\n",GridGetPositionY(&grille));
    printf("Après destruction la valeur de tailleX  est %u\n",GridGetTailleX(&grille));
    printf("Après destruction la valeur de tailleY est %u\n",GridGetTailleY(&grille));
    printf("Après destruction la valeur du pointeur de TabDyn est %u\n",GridGetMesMurs(&grille));
 }

