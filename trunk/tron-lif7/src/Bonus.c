#include "Jeu.h"
#include "EffetBonus.h"
#include "stdio.h"
#include "Bonus.h"
#include "time.h"

float BonusGetPositionX(const Bonus* bonus){
    return bonus->positionX;
}
float BonusGetPositionY(const Bonus* bonus){
    return bonus->positionY;
}
unsigned int BonusGetTailleX(const Bonus* bonus){
    return bonus->tailleX;
}
unsigned int BonusGetTailleY(const Bonus* bonus){
    return bonus->tailleY;
}
EffetBonus BonusGetEffetBonus(const Bonus* bonus){
    return bonus->effet;
}


void BonusSetPositionX(Bonus* bonus,float positionX){
     bonus->positionX=positionX;
}
void BonusSetPositionY(Bonus* bonus,float positionY){
     bonus->positionY=positionY;
}
void BonusSetTailleX(Bonus* bonus,unsigned int tailleX){
     bonus->tailleX=tailleX;
}
void BonusSetTailleY(Bonus* bonus,unsigned int tailleY){
     bonus->tailleY=tailleY;
}
void BonusSetEffetBonus(Bonus* bonus,EffetBonus effet){
     bonus->effet=effet;
}

void BonusConstructeur(Bonus *bonus, float positionX,float positionY,unsigned int tailleX,unsigned int tailleY,EffetBonus effet){
    BonusSetPositionX(bonus,positionX);
    BonusSetPositionY(bonus,positionY);
    BonusSetTailleX(bonus,tailleX);
    BonusSetTailleY(bonus,tailleY);
    BonusSetEffetBonus(bonus,effet);
}

void BonusDestructeur(Bonus* bonus){
    BonusSetPositionX(bonus,0);
    BonusSetPositionY(bonus,0);
    BonusSetTailleX(bonus,0);
    BonusSetTailleY(bonus,0);
    BonusSetEffetBonus(bonus,AUCUN);
}

char BonusTestCollisionMoto(Moto *moto,Bonus* bonus){
    float BoiteMoto[4]={MotoGetPositionX(moto),MotoGetPositionY(moto),MotoGetPositionX(moto)+(float)MotoGetTailleX(moto),
    MotoGetPositionY(moto)+(float)MotoGetTailleY(moto)};
    float Boitebonus[4]={BonusGetPositionX(bonus),BonusGetPositionY(bonus),BonusGetPositionX(bonus)+(float)BonusGetTailleX(bonus),
    BonusGetPositionY(bonus)+(float)BonusGetTailleY(bonus)};
    char boolCollision = 0;
    if((BoiteMoto[0]<Boitebonus[2])&&
       (BoiteMoto[2]>Boitebonus[2])&&
       (BoiteMoto[1]<Boitebonus[3])&&
       (BoiteMoto[3]>Boitebonus[1]))
    {boolCollision=1;}
    return boolCollision;
}

char BonusTestCollisionMurs(Grid *grille,Bonus* bonus){
    int i;
    char boolCollision=0;
    float boundingBoxMur[4];
    float Boitebonus[4]={BonusGetPositionX(bonus),BonusGetPositionY(bonus),BonusGetPositionX(bonus)+(float)BonusGetTailleX(bonus),
    BonusGetPositionY(bonus)+(float)BonusGetTailleY(bonus)};
    float borduresGrid[4]={GridGetPositionX(grille),GridGetPositionY(grille),(float)GridGetTailleX(grille) + GridGetPositionX(grille),
                            (float)GridGetTailleY(grille) + GridGetPositionY(grille)};
    while((i<TabDynGetTaille_utilisee(GridGetMesMurs(grille)))&&(boolCollision==0)){
                boundingBoxMur[0]=MurGetPositionX(adresseIemeElementTabDyn(GridGetMesMurs(grille),i));
                boundingBoxMur[1]=MurGetPositionY(adresseIemeElementTabDyn(GridGetMesMurs(grille),i));
                boundingBoxMur[2]=MurGetPositionX(adresseIemeElementTabDyn(GridGetMesMurs(grille),i))
                                +(float)MurGetTailleX(adresseIemeElementTabDyn(GridGetMesMurs(grille),i));
                boundingBoxMur[3]=MurGetPositionY(adresseIemeElementTabDyn(GridGetMesMurs(grille),i))
                                +(float)MurGetTailleY(adresseIemeElementTabDyn(GridGetMesMurs(grille),i));
                if( ((Boitebonus[0]<boundingBoxMur[2])||(Boitebonus[0]<borduresGrid[0]))&&
                    ((Boitebonus[2]>boundingBoxMur[0])||(Boitebonus[2]>borduresGrid[2]))&&
                    ((Boitebonus[1]<boundingBoxMur[3])||(Boitebonus[1]<borduresGrid[1]))&&
                    ((Boitebonus[3]>boundingBoxMur[1])||(Boitebonus[3]>borduresGrid[3])))
                {boolCollision = 1;}
                i++;
            }
    return boolCollision;
}

void PlaceBonus(Grid* grid,Bonus* bonus){
    float positionX;
    float positionY;
    unsigned int numeroBonus;
    srand(time(NULL));
    do{
        positionX=rand()%(GridGetTailleX(grid)-BonusGetTailleX(bonus))+GridGetPositionX(grid);
        positionY=rand()%(GridGetTailleY(grid)-BonusGetTailleY(bonus))+GridGetPositionY(grid);
        BonusSetPositionX(bonus,positionX);
        BonusSetPositionY(bonus,positionY);
        numeroBonus=rand()%_Nombre_Type_Bonus +0;
        BonusSetEffetBonus(bonus,numeroBonus);
    }while(BonusTestCollisionMurs(grid,bonus)==1);
}


void BonusTestRegression(){
    Grid grille;
    TableauDynamique t;
    Bonus bonus;
    GridConstructeur(&grille,5,5,1000,700,&t);
    BonusConstructeur(&bonus,0,0,5,5,AUCUN);
    PlaceBonus(&grille,&bonus);
    printf("La position X du bonus %f\n",BonusGetPositionX(&bonus));
    printf("La position Y du bonus %f\n",BonusGetPositionY(&bonus));
    printf("Le numéro du bonus %u \n\n",BonusGetEffetBonus(&bonus));
}




