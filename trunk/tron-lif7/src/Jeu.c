#include "Jeu.h"
#include "Joueur.h"
#include "Grid.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

Grid* JeuGetGrille(Jeu* jeu){
    return &(jeu->grille);
}
Joueur* JeuGetIemeJoueurs(Jeu* jeu,int i){
    return &(jeu->mesJoueurs[i]);
}

void JeuSetGrille(Jeu* jeu,Grid* grille){
    jeu->grille= *grille;
}
void JeuSetIemeJoueurs(Jeu* jeu,Joueur* joueur,int i){
    jeu->mesJoueurs[i]= *joueur;
}

void JeuConstructeur(Jeu* jeu, Grid* grille, Joueur* mesJoueurs[_Nombre_de_Joueur]){
    int i;
    JeuSetGrille(jeu,grille);
    for(i=0;i<_Nombre_de_Joueur;i++){
         JeuSetIemeJoueurs(jeu,mesJoueurs[i],i);
    }
}
void JeuDestructeur(Jeu* jeu){
    int i;
    GridDestructeur(JeuGetGrille(jeu));
    for(i=0;i<_Nombre_de_Joueur;i++){
    JoueurDestructeur(JeuGetIemeJoueurs(jeu,i));
    }
}




char testCollisionMur(const Moto * moto, Grid * grille){
    int i=0;
    char boolCollision = 0;
    float boundingBoxMur[4];
    float boundingBoxMoto[4]={MotoGetPositionX(moto),MotoGetPositionY(moto),(float)MotoGetTailleX(moto) + MotoGetPositionX(moto),
                                (float)MotoGetTailleY(moto) + MotoGetPositionY(moto)};
    float borduresGrid[4]={GridGetPositionX(grille),GridGetPositionY(grille),(float)GridGetTailleX(grille) + GridGetPositionX(grille),
                            (float)GridGetTailleY(grille) + GridGetPositionY(grille)};
    if((boundingBoxMoto[0]<borduresGrid[0])||
       (boundingBoxMoto[2]>borduresGrid[2])||
       (boundingBoxMoto[1]<borduresGrid[1])||
       (boundingBoxMoto[3]>borduresGrid[3]))
    {boolCollision = 1;}
    else while((i<TabDynGetTaille_utilisee(GridGetMesMurs(grille)))&&(boolCollision==0)){
                boundingBoxMur[0]=MurGetPositionX(adresseIemeElementTabDyn(GridGetMesMurs(grille),i));
                boundingBoxMur[1]=MurGetPositionY(adresseIemeElementTabDyn(GridGetMesMurs(grille),i));
                boundingBoxMur[2]=MurGetPositionX(adresseIemeElementTabDyn(GridGetMesMurs(grille),i))
                                +(float)MurGetTailleX(adresseIemeElementTabDyn(GridGetMesMurs(grille),i));
                boundingBoxMur[3]=MurGetPositionY(adresseIemeElementTabDyn(GridGetMesMurs(grille),i))
                                +(float)MurGetTailleY(adresseIemeElementTabDyn(GridGetMesMurs(grille),i));
                if((boundingBoxMoto[0]<boundingBoxMur[2])&&
                    (boundingBoxMoto[2]>boundingBoxMur[0])&&
                    (boundingBoxMoto[1]<boundingBoxMur[3])&&
                    (boundingBoxMoto[3]>boundingBoxMur[1]))
                {boolCollision = 1;}
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
            MotoSetPositionX(uneMoto,(MotoGetPositionX(uneMoto)+(float)(MotoGetTailleX(uneMoto)-MotoGetTailleY(uneMoto))));
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
                MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+(float)(MotoGetTailleX(uneMoto)-MotoGetTailleY(uneMoto)));
                MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)(MotoGetTailleY(uneMoto)-MotoGetTailleX(uneMoto)));
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
                        MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)(MotoGetTailleX(uneMoto)-MotoGetTailleY(uneMoto)));
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
                    if(touche==ControleGetGauche(unControle)){
                        MotoSetDirection(uneMoto,HAUT);
                        MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+(float)(MotoGetTailleY(uneMoto)-MotoGetTailleX(uneMoto)));
                        MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)(MotoGetTailleX(uneMoto)-MotoGetTailleY(uneMoto)));
                        tailleTemp=MotoGetTailleX(uneMoto);
                        MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
                        MotoSetTailleY(uneMoto,tailleTemp);
                    }
                    else if(touche==ControleGetDroite(unControle)){
                            MotoSetDirection(uneMoto,DROITE);
                            MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+(float)(MotoGetTailleY(uneMoto)-MotoGetTailleX(uneMoto)));
                            tailleTemp=MotoGetTailleX(uneMoto);
                            MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
                            MotoSetTailleY(uneMoto,tailleTemp);
                    }
                }
}

void bougeMoto(Jeu* jeu){
    int i;
    float dureeVieMur = 50;
    Moto* uneMoto;
    Mur unMur;
    for(i=0;i<_Nombre_de_Joueur;i++){
        uneMoto = JoueurGetMoto(JeuGetIemeJoueurs(jeu,i));
        if(MotoGetDirection(uneMoto)==HAUT){
            MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto)+MotoGetTailleY(uneMoto)-MotoGetVitesse(uneMoto)+1,
                            MotoGetTailleX(uneMoto),MotoGetVitesse(uneMoto)+1,JoueurGetCouleur(JeuGetIemeJoueurs(jeu,i)),dureeVieMur);
            MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)-MotoGetVitesse(uneMoto));
        }
        else if(MotoGetDirection(uneMoto)==BAS){
                MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto)-1,
                                MotoGetTailleX(uneMoto),MotoGetVitesse(uneMoto)+1,JoueurGetCouleur(JeuGetIemeJoueurs(jeu,i)),dureeVieMur);
                MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+MotoGetVitesse(uneMoto));
                }
            else if(MotoGetDirection(uneMoto)==GAUCHE){
                    MurConstructeur(&unMur,MotoGetPositionX(uneMoto)+MotoGetTailleY(uneMoto)-MotoGetVitesse(uneMoto)+1,MotoGetPositionY(uneMoto),
                                    MotoGetVitesse(uneMoto)+1,MotoGetTailleY(uneMoto),JoueurGetCouleur(JeuGetIemeJoueurs(jeu,i)),dureeVieMur);
                    MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)-MotoGetVitesse(uneMoto));
                    }
                else if(MotoGetDirection(uneMoto)==DROITE){
                        MurConstructeur(&unMur,MotoGetPositionX(uneMoto)-1,MotoGetPositionY(uneMoto),
                                        MotoGetVitesse(uneMoto)+1,MotoGetTailleY(uneMoto),JoueurGetCouleur(JeuGetIemeJoueurs(jeu,i)),dureeVieMur);
                        MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+MotoGetVitesse(uneMoto));
                        }
        ajouteMur(GridGetMesMurs(JeuGetGrille(jeu)),unMur);
        MotoSetVitesse(uneMoto,MotoGetVitesse(uneMoto)+0.1);
        }
}

void JeuEvolue(Jeu* jeu,short int* jeuFini){
    int i;
    Grid* grille=JeuGetGrille(jeu);
    bougeMoto(jeu);
    for(i=0;i<2;i++){
        if(testCollisionMur(JoueurGetMoto(JeuGetIemeJoueurs(jeu,i)),grille)){
            printf("Le joueur %d a perdu ! \n",i+1);
            *jeuFini=i+1;
        }
    }
    decrementeVieMur(grille);
    effaceMur(GridGetMesMurs(grille));
}

void JeuTestRegression(){
    Grid grille;
    float posXg=1.;
    float posYg=1.;
    unsigned int tailleXg=300;
    unsigned int tailleYg=400;
    TableauDynamique mesMurs;

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

    short int jeuContinue=0;
    Jeu jeu;
    Joueur * mesJoueurs[_Nombre_de_Joueur];

    MurConstructeur(&unMur,posXm,posYm,tailleXm,tailleYm,couleur2,dureeVie);

    GridConstructeur(&grille,posXg,posYg,tailleXg,tailleYg,&mesMurs);

    MotoConstructeur(&moto1,posX1,posY1,tailleX1,tailleY1,vitesse1,direction1);
    ControleConstructeur(&controle1,touchedroite1,touchegauche1,touchehaut1,touchebas1);
    JoueurConstructeur(&joueur1,&moto1,&controle1,couleur1);
    mesJoueurs[0] = &joueur1;
    printf("La valeur posX1 est %f et dans la Moto1 du joueur1 est de %f \n",posX1,
           MotoGetPositionX(JoueurGetMoto(&joueur1)));

    MotoConstructeur(&moto2,posX2,posY2,tailleX2,tailleY2,vitesse2,direction2);
    ControleConstructeur(&controle2,touchedroite2,touchegauche2,touchehaut2,touchebas2);
    JoueurConstructeur(&joueur2,&moto2,&controle2,couleur2);
    mesJoueurs[1] = &joueur2;
    printf("La valeur posX2 est %f et dans la Moto2 du joueur2 est de %f \n",
           posX2,MotoGetPositionX(JoueurGetMoto(&joueur2)));

    JeuConstructeur(&jeu,&grille,(Joueur **)&mesJoueurs);


    printf("La valeur vitesse2 est %f et dans la vitesse de la moto2 du joueur2 du jeu est de %f \n",
           vitesse2,MotoGetVitesse(JoueurGetMoto(JeuGetIemeJoueurs(&jeu,1))));

    assert(1== testCollisionMur(JoueurGetMoto(JeuGetIemeJoueurs(&jeu,0)),JeuGetGrille(&jeu)));
    assert(1== testCollisionMur(JoueurGetMoto(JeuGetIemeJoueurs(&jeu,1)),JeuGetGrille(&jeu)));

    ajouteMur(GridGetMesMurs(JeuGetGrille(&jeu)),unMur);
    assert(0== testCollisionMur(JoueurGetMoto(JeuGetIemeJoueurs(&jeu,0)),JeuGetGrille(&jeu)));
    assert(1== testCollisionMur(JoueurGetMoto(JeuGetIemeJoueurs(&jeu,1)),JeuGetGrille(&jeu)));

    bougeMoto(&jeu);
    printf("La vitesse de la moto1 (1 avant) après bougeMoto est %f \n",
           MotoGetVitesse(JoueurGetMoto(JeuGetIemeJoueurs(&jeu,0))));
    printf("La positionY de la moto2 (30avant + 2vitesse) après bougeMoto est %f \n",
           MotoGetPositionY(JoueurGetMoto(JeuGetIemeJoueurs(&jeu,1))));

    nettoieGrid(GridGetMesMurs(JeuGetGrille(&jeu)));

    JeuEvolue(&jeu,&jeuContinue);

    JeuDestructeur(&jeu);
    printf("Après destruction, le pointeur de grille du jeu est %p \n",JeuGetGrille(&jeu));
    printf("Après destruction, le pointeur du joueur 2 de mesJoueurs du jeu est %p \n \n",JeuGetIemeJoueurs(&jeu,1));


}


