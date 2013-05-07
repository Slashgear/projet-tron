#include "EffetBonus.h"
#include "stdio.h"
#include "Bonus.h"
#include "time.h"
#include "Jeu.h"

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




void BonusTestRegression(){
/*

    Grid grille;
    float posXg=1.;
    float posYg=1.;
    unsigned int tailleXg=300;
    unsigned int tailleYg=400;
    TableauDynamiqueMur mesMurs;

    Mur unMur;
    float posXm=50.;
    float posYm=70.;
    unsigned int tailleXm=3;
    unsigned int tailleYm=3;
    float dureeVie=5.;

    Joueur joueur1;
    Moto moto1;
    Controle controle1;
    Couleur couleur1=ORANGE;
    float posX1=52.;
    float posY1=72.;
    unsigned int tailleX1=2;
    unsigned int tailleY1=5;
    float vitesse1=1.;
    Direction direction1=HAUT;
    char touchedroite1='d';
    char touchegauche1='q';
    char touchehaut1='z';
    char touchebas1='s';

    Joueur joueur2;
    Moto moto2;
    Controle controle2;
    Couleur couleur2=BLEU;
    float posX2=100.;
    float posY2=5.;
    unsigned int tailleX2=2;
    unsigned int tailleY2=5;
    float vitesse2=2.;
    Direction direction2=HAUT;
    char touchedroite2='m';
    char touchegauche2='k';
    char touchehaut2='o';
    char touchebas2='l';
    char touchebonus1='a';
    char touchebonus2='i';
    Bonus bonus;

    Jeu jeu;
    Joueur *mesJoueurs=(Joueur*)malloc(_Nombre_de_Joueur*sizeof(Joueur));

    MurConstructeur(&unMur,posXm,posYm,tailleXm,tailleYm,couleur2,dureeVie);

    GridConstructeur(&grille,posXg,posYg,tailleXg,tailleYg,&mesMurs);

    MotoConstructeur(&moto1,posX1,posY1,tailleX1,tailleY1,vitesse1,direction1);
    ControleConstructeur(&controle1,touchedroite1,touchegauche1,touchehaut1,touchebas1,touchebonus1);
    JoueurConstructeur(&joueur1,&moto1,&controle1,couleur1,1,AUCUN,-1);
    mesJoueurs[0]=joueur1;

    MotoConstructeur(&moto2,posX2,posY2,tailleX2,tailleY2,vitesse2,direction2);
    ControleConstructeur(&controle2,touchedroite2,touchegauche2,touchehaut2,touchebas2,touchebonus2);
    JoueurConstructeur(&joueur2,&moto2,&controle2,couleur2,1,AUCUN,-1);
    mesJoueurs[1]=joueur2;

    JeuConstructeur(&jeu,&grille,mesJoueurs);

    BonusConstructeur(&bonus,0,0,5,5,AUCUN);
    PlaceBonus(&jeu,&bonus);
    printf("La position X du bonus %f\n",BonusGetPositionX(&bonus));
    printf("La position Y du bonus %f\n",BonusGetPositionY(&bonus));
    printf("Le numéro du bonus %u \n\n",BonusGetEffetBonus(&bonus));
*/
}




