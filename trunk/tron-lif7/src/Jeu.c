#include "Jeu.h"
#include "Joueur.h"
#include "Grid.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Grid* JeuGetGrille(const Jeu* jeu){
    return jeu->grille;
}
Joueur* JeuGetMesJoueurs(const Jeu* jeu){
    return jeu->mesJoueurs;
}
void JeuSetGrille(Jeu* jeu,Grid* grille){
    jeu->grille=grille;
}
void JeuSetMesJoueurs(Jeu* jeu,Joueur* mesJoueurs){
    jeu->mesJoueurs=mesJoueurs;
}

void JeuConstructeur(Jeu* jeu, Grid* grille, Joueur* mesJoueurs){
    JeuSetGrille(jeu,grille);
    JeuSetMesJoueurs(jeu,mesJoueurs);
}
void JeuDestructeur(Jeu* jeu){
    int i;
    GridDestructeur(JeuGetGrille(jeu));
    for(i=0;i<2;i++){
    JoueurDestructeur(&(JeuGetMesJoueurs(jeu)[i]));
    }
    JeuSetGrille(jeu,NULL);
    JeuSetMesJoueurs(jeu,NULL);
}

char testCollisionMur(const Moto * moto,const Grid * grille){
    int i=0;
    char boolCollision = 1;
    float boundingBoxMur[4];
    float boundingBoxMoto[4]={MotoGetPositionX(moto),MotoGetPositionY(moto),(float)MotoGetTailleX(moto) + MotoGetPositionX(moto),
                                (float)MotoGetTailleY(moto) + MotoGetPositionY(moto)};
    float borduresGrid[4]={GridGetPositionX(grille),GridGetPositionY(grille),(float)GridGetTailleX(grille) + GridGetPositionX(grille),
                            (float)GridGetTailleY(grille) + GridGetPositionY(grille)};
    if((boundingBoxMoto[0]<=borduresGrid[0])||
       (boundingBoxMoto[2]>=borduresGrid[2])||
       (boundingBoxMoto[1]<=borduresGrid[1])||
       (boundingBoxMoto[3]>=borduresGrid[3]))
    {boolCollision = 0;}
    else while((i<TabDynGetTaille_utilisee(GridGetMesMurs(grille)))&&(boolCollision==1)){
                boundingBoxMur[0]=MurGetPositionX(adresseIemeElementTabDyn(GridGetMesMurs(grille),i));
                boundingBoxMur[1]=MurGetPositionY(adresseIemeElementTabDyn(GridGetMesMurs(grille),i));
                boundingBoxMur[2]=MurGetPositionX(adresseIemeElementTabDyn(GridGetMesMurs(grille),i))
                                +(float)MurGetTailleX(adresseIemeElementTabDyn(GridGetMesMurs(grille),i));
                boundingBoxMur[3]=MurGetPositionY(adresseIemeElementTabDyn(GridGetMesMurs(grille),i))
                                +(float)MurGetTailleY(adresseIemeElementTabDyn(GridGetMesMurs(grille),i));
                if((boundingBoxMoto[0]<=boundingBoxMur[2])&&
                    (boundingBoxMoto[2]>=boundingBoxMur[0])&&
                    (boundingBoxMoto[1]<=boundingBoxMur[3])&&
                    (boundingBoxMoto[3]>=boundingBoxMur[1]))
                {boolCollision = 0;}
                i++;
            }
    return boolCollision;
}

void JeuActionClavier(Joueur* joueur,const char touche){
    unsigned int tailleTemp;
    Controle* unControle=JoueurGetControle(joueur);
    Moto* uneMoto=JoueurGetMoto(joueur);
    if(MotoGetDirection(uneMoto)==HAUT){
        if(touche==ControleGetGauche(unControle)){
            MotoSetDirection(uneMoto,GAUCHE);
            MotoSetPositionX(uneMoto,(float)(MotoGetTailleX(uneMoto)-MotoGetTailleY(uneMoto)));
            tailleTemp=MotoGetTailleX(uneMoto);
            MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
            MotoSetTailleY(uneMoto,tailleTemp);
            }
        else if(touche==ControleGetDroite(unControle)){
            MotoSetDirection(uneMoto,DROITE);
            tailleTemp=MotoGetTailleX(uneMoto);
            MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
            MotoSetTailleY(uneMoto,tailleTemp);
            }
        }
    else if(MotoGetDirection(uneMoto)==BAS){
            if(touche==ControleGetGauche(unControle)){
                MotoSetDirection(uneMoto,GAUCHE);
                MotoSetPositionX(uneMoto,(float)(MotoGetTailleX(uneMoto)-MotoGetTailleY(uneMoto)));
                MotoSetPositionY(uneMoto,(float)(MotoGetTailleY(uneMoto)-MotoGetTailleX(uneMoto)));
                tailleTemp=MotoGetTailleX(uneMoto);
                MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
                MotoSetTailleY(uneMoto,tailleTemp);
            }
            else if(touche==ControleGetDroite(unControle)){
                MotoSetDirection(uneMoto,DROITE);
                tailleTemp=MotoGetTailleX(uneMoto);
                MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
                MotoSetTailleY(uneMoto,tailleTemp);
                }
        }
        else if(MotoGetDirection(uneMoto)==GAUCHE){
                    if(touche==ControleGetHaut(unControle)){
                        MotoSetDirection(uneMoto,HAUT);
                        MotoSetPositionY(uneMoto,(float)(MotoGetTailleX(uneMoto)-MotoGetTailleY(uneMoto)));
                        tailleTemp=MotoGetTailleX(uneMoto);
                        MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
                        MotoSetTailleY(uneMoto,tailleTemp);
                    }
                    else if(touche==ControleGetBas(unControle)){
                            MotoSetDirection(uneMoto,BAS);
                            tailleTemp=MotoGetTailleX(uneMoto);
                            MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
                            MotoSetTailleY(uneMoto,tailleTemp);
                        }
            }
            else if(MotoGetDirection(uneMoto)==DROITE){
                    if(touche==ControleGetHaut(unControle)){
                        MotoSetDirection(uneMoto,HAUT);
                        MotoSetPositionX(uneMoto,(float)(MotoGetTailleY(uneMoto)-MotoGetTailleX(uneMoto)));
                        MotoSetPositionY(uneMoto,(float)(MotoGetTailleX(uneMoto)-MotoGetTailleY(uneMoto)));
                        tailleTemp=MotoGetTailleX(uneMoto);
                        MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
                        MotoSetTailleY(uneMoto,tailleTemp);
                    }
                    else if(touche==ControleGetBas(unControle)){
                            MotoSetDirection(uneMoto,BAS);
                            MotoSetPositionX(uneMoto,(float)(MotoGetTailleY(uneMoto)-MotoGetTailleX(uneMoto)));
                            tailleTemp=MotoGetTailleX(uneMoto);
                            MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
                            MotoSetTailleY(uneMoto,tailleTemp);
                    }
                }
}

void BougeMoto(Jeu* jeu){
    int i;
    float dureeVieMur = 1000;
    Moto* uneMoto;
    Mur unMur;
    for(i=0;i<2;i++){
        uneMoto = JoueurGetMoto(&JeuGetMesJoueurs(jeu)[i]);
        if(MotoGetDirection(uneMoto)==HAUT){
            MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto)+MotoGetTailleY(uneMoto)-MotoGetVitesse(uneMoto)+1,
                            MotoGetTailleX(uneMoto),MotoGetVitesse(uneMoto),JoueurGetCouleur(&JeuGetMesJoueurs(jeu)[i]),dureeVieMur);
            MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)-MotoGetVitesse(uneMoto));
        }
        else if(MotoGetDirection(uneMoto)==BAS){
                MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto)-1,
                                MotoGetTailleX(uneMoto),MotoGetVitesse(uneMoto),JoueurGetCouleur(&JeuGetMesJoueurs(jeu)[i]),dureeVieMur);
                MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+MotoGetVitesse(uneMoto));
                }
            else if(MotoGetDirection(uneMoto)==GAUCHE){
                    MurConstructeur(&unMur,MotoGetPositionX(uneMoto)+MotoGetTailleX(uneMoto)-MotoGetVitesse(uneMoto)+1,MotoGetPositionY(uneMoto),
                                    MotoGetVitesse(uneMoto),MotoGetTailleY(uneMoto),JoueurGetCouleur(&JeuGetMesJoueurs(jeu)[i]),dureeVieMur);
                    MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)-MotoGetVitesse(uneMoto));
                    }
                else if(MotoGetDirection(uneMoto)==DROITE){
                        MurConstructeur(&unMur,MotoGetPositionX(uneMoto)-1,MotoGetPositionY(uneMoto),
                                        MotoGetVitesse(uneMoto),MotoGetTailleY(uneMoto),JoueurGetCouleur(&JeuGetMesJoueurs(jeu)[i]),dureeVieMur);
                        MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)-MotoGetVitesse(uneMoto));
                        }
        ajouteMur(GridGetMesMurs(JeuGetGrille(jeu)),unMur);
        MotoSetVitesse(uneMoto,MotoGetVitesse(uneMoto)+0.1f);
        }
}

/**Boucle d'évolutions du jeu*/
void JeuEvolue(Jeu* jeu){
    int i;
    TableauDynamique* tabDyn=GridGetMesMurs(JeuGetGrille(jeu));
    BougeMoto(jeu);
    for(i=0;i<2;i++){
        if(testCollisionMur(JoueurGetMoto(&JeuGetMesJoueurs(jeu)[j]),)){

        }
    }
}

void JeuTestRegression(){
    Grid grille;
    float posXg=10;
    float posYg=5;
    unsigned int tailleXg=300;
    unsigned int tailleYg=400;
    TableauDynamique mesMurs;

    Mur unMur;
    float posXm=10;
    float posYm=20;
    unsigned int tailleXm=3;
    unsigned int tailleYm=3;
    float dureeVie=5;

    Joueur joueur1;
    Moto moto1;
    Controle controle1;
    Couleur couleur1=ORANGE;
    float posX1=12;
    float posY1=22;
    unsigned int tailleX1=2;
    unsigned int tailleY1=5;
    float vitesse1=20;
    Direction direction1=HAUT;
    char touchedroite1='d';
    char touchegauche1='q';
    char touchehaut1='z';
    char touchebas1='s';

    Joueur joueur2;
    Moto moto2;
    Controle controle2;
    Couleur couleur2=BLEU;
    float posX2=20;
    float posY2=30;
    unsigned int tailleX2=2;
    unsigned int tailleY2=5;
    float vitesse2=30;
    Direction direction2=BAS;
    char touchedroite2='m';
    char touchegauche2='k';
    char touchehaut2='o';
    char touchebas2='l';

    Jeu jeu;
    Joueur mesJoueurs[2];

    MurConstructeur(&unMur,posXm,posYm,tailleXm,tailleYm,couleur2,dureeVie);

    GridConstructeur(&grille,posXg,posYg,tailleXg,tailleYg,&mesMurs);

    MotoConstructeur(&moto1,posX1,posY1,tailleX1,tailleY1,vitesse1,direction1);
    ControleConstructeur(&controle1,touchedroite1,touchegauche1,touchehaut1,touchebas1);
    JoueurConstructeur(&joueur1,&moto1,&controle1,couleur1);
    mesJoueurs[0] = joueur1;
    printf("La valeur posX1 est %f et dans la Moto1 du joueur1 est de %f \n",posX1,MotoGetPositionX(JoueurGetMoto(&mesJoueurs[0])));

    MotoConstructeur(&moto2,posX2,posY2,tailleX2,tailleY2,vitesse2,direction2);
    ControleConstructeur(&controle2,touchedroite2,touchegauche2,touchehaut2,touchebas2);
    JoueurConstructeur(&joueur2,&moto2,&controle2,couleur2);
    mesJoueurs[1] = joueur2;
    printf("La valeur posX2 est %f et dans la Moto2 du joueur2 est de %f \n",posX2,MotoGetPositionX(JoueurGetMoto(&mesJoueurs[1])));

    JeuConstructeur(&jeu,&grille,(Joueur*)&mesJoueurs);
    printf("La valeur vitesse2 est %f et dans la vitesse de la moto2 du joueur2 du jeu est de %f \n",vitesse2,MotoGetVitesse(JoueurGetMoto(&JeuGetMesJoueurs(&jeu)[1])));

    ajouteMur(GridGetMesMurs(JeuGetGrille(&jeu)),unMur);
    assert(0== testCollisionMur(JoueurGetMoto(&mesJoueurs[0]),JeuGetGrille(&jeu)));
    assert(1== testCollisionMur(JoueurGetMoto(&mesJoueurs[1]),JeuGetGrille(&jeu)));

    BougeMoto(&jeu);
    printf("La vitesse de la moto1 (30 avant) après bougeMoto est %f \n",MotoGetVitesse(JoueurGetMoto(&JeuGetMesJoueurs(&jeu)[1])));
    printf("La positionY de la moto2 (30avant + 30vitesse) après bougeMoto est %f \n",MotoGetPositionY(JoueurGetMoto(&JeuGetMesJoueurs(&jeu)[1])));

    JeuDestructeur(&jeu);
    printf("Après destruction, le pointeur de grille du jeu est %p \n",JeuGetGrille(&jeu));
    printf("Après destruction, le pointeur de mesJoueurs du jeu est %p \n \n",JeuGetMesJoueurs(&jeu));


}


