#include<stdlib.h>
#include<stdio.h>
#include <assert.h>
#include "Grid.h"
#include "Mur.h"
#include "TableauDynamiqueMur.h"

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
TableauDynamiqueMur* GridGetMesMurs(Grid* grille){
    return &(grille->mesMurs);
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
void GridSetMesMurs(Grid* grille,TableauDynamiqueMur* mesMurs){
    grille->mesMurs = *mesMurs;
}
void GridConstructeur(Grid* grille, float posX, float posY, unsigned int TailleX, unsigned int TailleY,TableauDynamiqueMur* mesMurs){
    GridSetPositionX(grille,posX);
    GridSetPositionY(grille,posY);
    GridSetTailleX(grille,TailleX);
    GridSetTailleY(grille,TailleY);
    initialiserTabDynMur(mesMurs);
    GridSetMesMurs(grille,mesMurs);
}
void GridDestructeur(Grid* grille){
    GridSetPositionX(grille,0);
    GridSetPositionY(grille,0);
    GridSetTailleX(grille,0);
    GridSetTailleY(grille,0);
    testamentTabDynMur(GridGetMesMurs(grille));
}

 void ajouteMur(TableauDynamiqueMur* mesMurs, Mur mur){
    ajouterElementTabDynMur(mesMurs,mur);
 }

void effaceMur(TableauDynamiqueMur* mesMurs){
    int i;
    for(i=0;i<TabDynMurGetTaille_utilisee(mesMurs);i++){
        if(MurGetDureeVie(adresseIemeElementTabDynMur(mesMurs,i))<=0)
        {
            supprimerElementTabDynMur(mesMurs,i);
        }
    }
}
void nettoieGrid(TableauDynamiqueMur* mesMurs){
    int i;
    for(i=0;i<TabDynMurGetTaille_utilisee(mesMurs);i++){
    MurSetDureeVie(adresseIemeElementTabDynMur(mesMurs,i),0);
    }
}
void decrementeVieMur(Grid* grille){
    int i;
    for(i=0;i<TabDynMurGetTaille_utilisee(GridGetMesMurs(grille));i++){
        MurSetDureeVie(adresseIemeElementTabDynMur(GridGetMesMurs(grille),i),
                       MurGetDureeVie(adresseIemeElementTabDynMur(GridGetMesMurs(grille),i))-1);
    }
}






 void GridTestRegression(){
    Grid grille;
    float posX=10;
    float posY=5;
    unsigned int tailleX=3;
    unsigned int tailleY=4;
    Mur unMur;
    TableauDynamiqueMur mesMurs;
    MurConstructeur(&unMur,31,32,33,34,ORANGE,0);
    GridConstructeur(&grille,posX,posY,tailleX,tailleY,&mesMurs);
    printf("La valeur de PosX saisie est %f et dans Grid est %f\n",posX,GridGetPositionX(&grille));
    printf("La valeur de PosY saisie est %f et dans Grid est %f\n",posY,GridGetPositionY(&grille));
    printf("La valeur de tailleX saisie est %u et dans Grid est %u\n",tailleX,GridGetTailleX(&grille));
    printf("La valeur de tailleY saisie est %u et dans Grid est %u\n",tailleY,GridGetTailleY(&grille));
    ajouteMur(GridGetMesMurs(&grille),unMur);
    printf("La valeur de PosX du mur ajouté saisie est 31 et dans Grid est %f\n",MurGetPositionX(adresseIemeElementTabDynMur(GridGetMesMurs(&grille),0)));
    assert(TabDynMurGetTaille_utilisee(GridGetMesMurs(&grille))==1);
    effaceMur(GridGetMesMurs(&grille));
    assert(TabDynMurGetTaille_utilisee(GridGetMesMurs(&grille))==0);
    ajouteMur(GridGetMesMurs(&grille),unMur);
    nettoieGrid(GridGetMesMurs(&grille));
    assert(TabDynMurGetTaille_utilisee(GridGetMesMurs(&grille))==0);
    GridDestructeur(&grille);
    printf("Après destruction la valeur de PosX dans Grid est %f\n",GridGetPositionX(&grille));
    printf("Après destruction la valeur de PosY dans Grid est %f\n",GridGetPositionY(&grille));
    printf("Après destruction la valeur de tailleX dans Grid  est %u\n",GridGetTailleX(&grille));
    printf("Après destruction la valeur de tailleY dans Grid est %u\n",GridGetTailleY(&grille));
    printf("Après destruction la taille utilisée par mesMurs est %u \n \n",TabDynMurGetTaille_utilisee(GridGetMesMurs(&grille)));
 }

