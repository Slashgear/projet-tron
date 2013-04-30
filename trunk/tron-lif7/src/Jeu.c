#include "Jeu.h"
#include "Joueur.h"
#include "Grid.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>



Grid* JeuGetGrille(Jeu* jeu){
    return &(jeu->grille);
}
Joueur* JeuGetIemeJoueurs(Jeu* jeu,int i){
    return (jeu->mesJoueurs)+i;
}
Bonus* JeuGetIemeBonus(Jeu* jeu,int i){
    return &((jeu->mesBonus)[i]);
}
int JeuGetTempsProchainBonus(Jeu* jeu){
    return jeu->tempsProchainBonus;
}
Musique* JeuGetMusique(Jeu* jeu){
    return &(jeu->musique);
}

void JeuSetGrille(Jeu* jeu,Grid* grille){
    jeu->grille= *grille;
}
void JeuSetIemeJoueurs(Jeu* jeu,Joueur* joueur,int i){
    (jeu->mesJoueurs)[i]= *joueur;
}
void JeuSetIemeBonus(Jeu* jeu,const Bonus* bonus,int i){
    (jeu->mesBonus)[i]=*bonus;
}
void JeuSetTempsProchainBonus(Jeu* jeu,int tempsProchainBonus){
    jeu->tempsProchainBonus=tempsProchainBonus;
}




void JeuConstructeur(Jeu* jeu, Grid* grille, Joueur *mesJoueurs){
    int i;
    Bonus bonus;
    Musique musique;

    srand(time(NULL));
    JeuSetTempsProchainBonus(jeu,rand()%350);
    BonusConstructeur(&bonus,0,0,10,10,AUCUN);
    JeuSetGrille(jeu,grille);
    jeu->mesJoueurs=mesJoueurs;
    for(i=0;i<_Nombre_de_Bonus;i++){
        JeuSetIemeBonus(jeu,&bonus,i);
    }
    MusiqueConstructeur(&musique);
    jeu->musique=musique;
    JouerIemeMusique(&musique,rand()%3,-1);
}

void JeuDestructeur(Jeu* jeu){
    int i;
    GridDestructeur(JeuGetGrille(jeu));
    free(jeu->mesJoueurs);
    jeu->mesJoueurs=NULL;
    for(i=0;i<_Nombre_de_Bonus;i++){
        BonusDestructeur(JeuGetIemeBonus(jeu,i));
    }
    MusiqueDestructeur(&(jeu->musique));
}


char testCollisionMur(Joueur * joueur, Grid * grille){
    int i=0;
    char boolCollision = 0;
    Mur* unMur;
    float boundingBoxMur[4];
    float boundingBoxMoto[4]={MotoGetPositionX(JoueurGetMoto(joueur)),MotoGetPositionY(JoueurGetMoto(joueur)),
                                (float)MotoGetTailleX(JoueurGetMoto(joueur)) + MotoGetPositionX(JoueurGetMoto(joueur)),
                                (float)MotoGetTailleY(JoueurGetMoto(joueur)) + MotoGetPositionY(JoueurGetMoto(joueur))};
    float borduresGrid[4]={GridGetPositionX(grille),GridGetPositionY(grille),(float)GridGetTailleX(grille) + GridGetPositionX(grille),
                            (float)GridGetTailleY(grille) + GridGetPositionY(grille)};
    Mur* dernierMur=JoueurGetDernierMur(joueur);
    float boundingboxDernierMur[4]={MurGetPositionX(dernierMur),MurGetPositionY(dernierMur),
                                    MurGetPositionX(dernierMur)+(float)MurGetTailleX(dernierMur),MurGetPositionY(dernierMur)+(float)MurGetTailleY(dernierMur)};
    if((boundingBoxMoto[0]<borduresGrid[0])||
       (boundingBoxMoto[2]>borduresGrid[2])||
       (boundingBoxMoto[1]<borduresGrid[1])||
       (boundingBoxMoto[3]>borduresGrid[3]))
    {boolCollision = 1;}
    else while((i<TabDynGetTaille_utilisee(GridGetMesMurs(grille)))&&(boolCollision==0)){
                unMur=adresseIemeElementTabDyn(GridGetMesMurs(grille),i);
                boundingBoxMur[0]=MurGetPositionX(unMur);
                boundingBoxMur[1]=MurGetPositionY(unMur);
                boundingBoxMur[2]=MurGetPositionX(unMur)
                                +(float)MurGetTailleX(unMur);
                boundingBoxMur[3]=MurGetPositionY(unMur)
                                +(float)MurGetTailleY(unMur);
                if((boundingBoxMoto[0]<boundingBoxMur[2])&&
                    (boundingBoxMoto[2]>boundingBoxMur[0])&&
                    (boundingBoxMoto[1]<boundingBoxMur[3])&&
                    (boundingBoxMoto[3]>boundingBoxMur[1])&&
                    (((MurGetDureeVie(unMur))<_Duree_Vie_Mur)||(JoueurGetCouleur(joueur)!=MurGetCouleur(unMur))))
                {boolCollision = 1;}
                if((MotoGetVitesse(JoueurGetMoto(joueur))>=10)&&
                    (boundingboxDernierMur[0]<boundingBoxMur[2])&&
                    (boundingboxDernierMur[2]>boundingBoxMur[0])&&
                    (boundingboxDernierMur[1]<boundingBoxMur[3])&&
                    (boundingboxDernierMur[3]>boundingBoxMur[1])&&
                    ((MurGetDureeVie(unMur)<(_Duree_Vie_Mur))||(MurGetCouleur(unMur)!=MurGetCouleur(dernierMur)))&&
                    ((((MotoGetDirection(JoueurGetMoto(joueur))==HAUT)||(MotoGetDirection(JoueurGetMoto(joueur))==BAS))&&(boundingboxDernierMur[0]!=boundingBoxMur[0]))||
                    (((MotoGetDirection(JoueurGetMoto(joueur))==GAUCHE)||(MotoGetDirection(JoueurGetMoto(joueur))==DROITE))&&(boundingboxDernierMur[1]!=boundingBoxMur[1]))) )
                {boolCollision=1;}
                i++;
            }
    return boolCollision;
}

char testCollisionMoto(Moto* moto1, Moto* moto2){
    char boolCollision=0;
    float boundingBoxMoto1[4]={MotoGetPositionX(moto1),MotoGetPositionY(moto1),(float)MotoGetTailleX(moto1) + MotoGetPositionX(moto1),
                                (float)MotoGetTailleY(moto1) + MotoGetPositionY(moto1)};
    float boundingBoxMoto2[4]={MotoGetPositionX(moto2),MotoGetPositionY(moto2),(float)MotoGetTailleX(moto2) + MotoGetPositionX(moto2),
                                (float)MotoGetTailleY(moto2) + MotoGetPositionY(moto2)};
    if((boundingBoxMoto1[0]<boundingBoxMoto2[2])&&
        (boundingBoxMoto1[2]>boundingBoxMoto2[0])&&
        (boundingBoxMoto1[1]<boundingBoxMoto2[3])&&
        (boundingBoxMoto1[3]>boundingBoxMoto2[1])){
        boolCollision=1;
    }
    return boolCollision;
}

void JeuActionClavier(Joueur* joueur,const SDLKey touche,Grid* grille){
    Controle* unControle=JoueurGetControle(joueur);
    Moto* uneMoto=JoueurGetMoto(joueur);
    unsigned int tailleTemp=MotoGetTailleX(uneMoto);
    Mur unMur;
    float dureeVieMur=_Duree_Vie_Mur;
    char directionChange=0;
    if(MotoGetDirection(uneMoto)==HAUT){
        MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                            MotoGetTailleX(uneMoto),(float)MotoGetTailleY(uneMoto),
                            JoueurGetCouleur(joueur),dureeVieMur);
        if(touche==ControleGetGauche(unControle)){
            MotoSetDirection(uneMoto,GAUCHE);
            MotoSetPositionX(uneMoto,(MotoGetPositionX(uneMoto)+(float)MotoGetTailleX(uneMoto)-(float)MotoGetTailleY(uneMoto)));
            directionChange=1;
            }
        else if(touche==ControleGetDroite(unControle)){
            MotoSetDirection(uneMoto,DROITE);
            directionChange=1;
            }
        }
    else if(MotoGetDirection(uneMoto)==BAS){
            MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                            MotoGetTailleX(uneMoto),(float)MotoGetTailleY(uneMoto),
                            JoueurGetCouleur(joueur),dureeVieMur);
            if(touche==ControleGetGauche(unControle)){
                MotoSetDirection(uneMoto,GAUCHE);
                MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+(float)MotoGetTailleX(uneMoto)-(float)MotoGetTailleY(uneMoto));
                MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)MotoGetTailleY(uneMoto)-(float)MotoGetTailleX(uneMoto));
                directionChange=1;
            }
            else if(touche==ControleGetDroite(unControle)){
                MotoSetDirection(uneMoto,DROITE);
                MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)MotoGetTailleY(uneMoto)-(float)MotoGetTailleX(uneMoto));
                directionChange=1;
                }
        }
        else if(MotoGetDirection(uneMoto)==GAUCHE){
            MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                            MotoGetTailleX(uneMoto),MotoGetTailleY(uneMoto),
                            JoueurGetCouleur(joueur),dureeVieMur);
                if(touche==ControleGetHaut(unControle)){
                    MotoSetDirection(uneMoto,HAUT);
                    MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)MotoGetTailleY(uneMoto)-(float)MotoGetTailleX(uneMoto));
                    directionChange=1;
                }
                else if(touche==ControleGetBas(unControle)){
                        MotoSetDirection(uneMoto,BAS);
                        directionChange=1;
                    }
            }
            else if(MotoGetDirection(uneMoto)==DROITE){
                    MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                            MotoGetTailleX(uneMoto),MotoGetTailleY(uneMoto),
                            JoueurGetCouleur(joueur),dureeVieMur);
                    if(touche==ControleGetHaut(unControle)){
                        MotoSetDirection(uneMoto,HAUT);
                        MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+(float)MotoGetTailleX(uneMoto)-(float)MotoGetTailleY(uneMoto));
                        MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)MotoGetTailleY(uneMoto)-(float)MotoGetTailleX(uneMoto));
                        directionChange=1;
                    }
                    else if(touche==ControleGetBas(unControle)){
                            MotoSetDirection(uneMoto,BAS);
                            MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+(float)MotoGetTailleX(uneMoto)-(float)MotoGetTailleY(uneMoto));
                            directionChange=1;
                    }
                }
    if(directionChange){
        MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
        MotoSetTailleY(uneMoto,tailleTemp);
        ajouteMur(GridGetMesMurs(grille),unMur);
        JoueurSetDernierMur(joueur,adresseIemeElementTabDyn(GridGetMesMurs(grille),TabDynGetTaille_utilisee(GridGetMesMurs(grille))-1));
    }
}

void bougeMoto(Jeu* jeu){
    int i;
    float dureeVieMur = _Duree_Vie_Mur;
    Moto* uneMoto;
    Mur unMur;
    for(i=0;(i<_Nombre_de_Joueur);i++){
        if(JoueurGetEnJeu(JeuGetIemeJoueurs(jeu,i))==1){
            uneMoto = JoueurGetMoto(JeuGetIemeJoueurs(jeu,i));
            if(MotoGetDirection(uneMoto)==HAUT){
                MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto)+(float)MotoGetTailleY(uneMoto)-MotoGetVitesse(uneMoto)-1.0f,
                                MotoGetTailleX(uneMoto),(int)(MotoGetVitesse(uneMoto)/1)+1,JoueurGetCouleur(JeuGetIemeJoueurs(jeu,i)),dureeVieMur);
                MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)-MotoGetVitesse(uneMoto));
            }
            else if(MotoGetDirection(uneMoto)==BAS){
                    MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                                    MotoGetTailleX(uneMoto),MotoGetVitesse(uneMoto)+1,JoueurGetCouleur(JeuGetIemeJoueurs(jeu,i)),dureeVieMur);
                    MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+MotoGetVitesse(uneMoto));
                    }
                else if(MotoGetDirection(uneMoto)==GAUCHE){
                        MurConstructeur(&unMur,MotoGetPositionX(uneMoto)+(float)MotoGetTailleX(uneMoto)-MotoGetVitesse(uneMoto)-1.0f,MotoGetPositionY(uneMoto),
                                        MotoGetVitesse(uneMoto)+1,MotoGetTailleY(uneMoto),JoueurGetCouleur(JeuGetIemeJoueurs(jeu,i)),dureeVieMur);
                        MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)-MotoGetVitesse(uneMoto));
                        }
                    else if(MotoGetDirection(uneMoto)==DROITE){
                            MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                                            MotoGetVitesse(uneMoto)+1,MotoGetTailleY(uneMoto),JoueurGetCouleur(JeuGetIemeJoueurs(jeu,i)),dureeVieMur);
                            MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+MotoGetVitesse(uneMoto));
                            }
            ajouteMur(GridGetMesMurs(JeuGetGrille(jeu)),unMur);
            JoueurSetDernierMur(JeuGetIemeJoueurs(jeu,i),adresseIemeElementTabDyn(GridGetMesMurs(JeuGetGrille(jeu)),TabDynGetTaille_utilisee(GridGetMesMurs(JeuGetGrille(jeu)))-1));
            MotoSetVitesse(uneMoto,MotoGetVitesse(uneMoto)+_Acceleration);
        }
    }
}

void JeuEvolue(Jeu* jeu,short int* jeuFini){
    int i,j;
    Grid* grille=JeuGetGrille(jeu);
    Bonus* unBonus=NULL;
    short int NbJoueurEnJeu=0;
    char collisionBonus=0;

    bougeMoto(jeu);
    for(i=0;i<_Nombre_de_Joueur;i++){
        if(JoueurGetEnJeu(JeuGetIemeJoueurs(jeu,i))==VIVANT){
            if(testCollisionMur(JeuGetIemeJoueurs(jeu,i),grille)){
                JouerIemeSonCourt(&(jeu->musique),0);
                printf("Le joueur %d a perdu ! \n",i+1);
                JoueurSetEnJeu(JeuGetIemeJoueurs(jeu,i),MOURANT);
            }
            else {
                for(j=i+1;(j<_Nombre_de_Joueur);j++){
                    if((JoueurGetEnJeu(JeuGetIemeJoueurs(jeu,j))==VIVANT)
                       &&(testCollisionMoto(JoueurGetMoto(JeuGetIemeJoueurs(jeu,i)),JoueurGetMoto(JeuGetIemeJoueurs(jeu,j))))){
                        JouerIemeSonCourt(&(jeu->musique),0);
                        JoueurSetEnJeu(JeuGetIemeJoueurs(jeu,j),MOURANT);
                        printf("Le joueur %d a perdu ! \n",j+1);
                        JoueurSetEnJeu(JeuGetIemeJoueurs(jeu,i),MOURANT);
                        printf("Le joueur %d a perdu ! \n",i+1);


                    }
                }
            }
        }
    }
    for(i=0;i<_Nombre_de_Joueur;i++){
        if(JoueurGetEnJeu(JeuGetIemeJoueurs(jeu,i))==VIVANT){
            NbJoueurEnJeu++;
        }
    }
    if(NbJoueurEnJeu==1){
        *jeuFini=1;
        i=0;
        while(i<_Nombre_de_Joueur){
            if(JoueurGetEnJeu(JeuGetIemeJoueurs(jeu,i))==1){
                printf("Le joueur %d a gagné ! \n",i+1);
                i++;
            }
            else {i++;}
        }
    }
    if(NbJoueurEnJeu==0){
        *jeuFini=1;
        printf("Les joueurs : ");
        for(i=0;i<_Nombre_de_Joueur;i++){
            if(JoueurGetEnJeu(JeuGetIemeJoueurs(jeu,i))==MOURANT){
                printf("%d, ",i+1);
                JoueurSetEnJeu(JeuGetIemeJoueurs(jeu,i),MORT);
            }
        }
        printf("sont à égalité ! \n");
    }
    for(i=0;i<_Nombre_de_Joueur;i++){
        if(JoueurGetEnJeu(JeuGetIemeJoueurs(jeu,i))==MOURANT){
            JoueurSetEnJeu(JeuGetIemeJoueurs(jeu,i),MORT);
        }
    }
    if(JeuGetTempsProchainBonus(jeu)==0){
        i=0;
        do{
            unBonus=JeuGetIemeBonus(jeu,i);
            i++;
        }
        while((BonusGetEffetBonus(unBonus)!=AUCUN)&&(i<_Nombre_de_Bonus));
        if(BonusGetEffetBonus(unBonus)==AUCUN){
            PlaceBonus(jeu,unBonus);
        }
        JeuSetTempsProchainBonus(jeu,(rand()%330)+20);
    }
    else {(jeu->tempsProchainBonus)-- ;}
    for(i=0;i<_Nombre_de_Bonus;i++){
        unBonus=JeuGetIemeBonus(jeu,i);
        collisionBonus=testCollisionMotoBonus(jeu->mesJoueurs,unBonus);
        if(BonusGetEffetBonus(unBonus)==NETTOYAGE){
            if(collisionBonus!=0){
                JouerIemeSonCourt(JeuGetMusique(jeu),1);
                nettoieGrid(GridGetMesMurs(JeuGetGrille(jeu)));
                BonusSetPositionX(unBonus,0);
                BonusSetPositionY(unBonus,0);
                BonusSetEffetBonus(unBonus,AUCUN);
            }
        }
        else if(BonusGetEffetBonus(unBonus)==BOOST){
                if(collisionBonus!=0){
                    JouerIemeSonCourt(JeuGetMusique(jeu),1);
                    JoueurSetEffetBonus(JeuGetIemeJoueurs(jeu,collisionBonus-1),BOOST);
                    JoueurSetTempsBonus(JeuGetIemeJoueurs(jeu,collisionBonus-1),_Temps_Bonus_Boost);
                    BonusSetPositionX(unBonus,0);
                    BonusSetPositionY(unBonus,0);
                    BonusSetEffetBonus(unBonus,AUCUN);
                }
        }
    }
    decrementeTempsBonus(jeu);
    decrementeVieMur(grille);
    effaceMur(GridGetMesMurs(grille));
}

void decrementeTempsBonus(Jeu *jeu){
    int i;
    Joueur* unJoueur;
    for(i=0;i<_Nombre_de_Joueur;i++){
        unJoueur=JeuGetIemeJoueurs(jeu,i);
        if((JoueurGetEffetBonus(unJoueur)==BOOST)&&(JoueurGetTempsBonus(unJoueur)!=_Temps_Bonus_Boost)){
            JoueurSetTempsBonus(unJoueur,JoueurGetTempsBonus(unJoueur)-1);
            if(JoueurGetTempsBonus(unJoueur)==0){
                JoueurSetEffetBonus(unJoueur,AUCUN);
                MotoSetVitesse(JoueurGetMoto(unJoueur),MotoGetVitesse(JoueurGetMoto(unJoueur))-_Vitesse_Boost);
            }
        }
    }
}

void JeuActionneBonus(Joueur *joueur){
    if(JoueurGetEffetBonus(joueur)==BOOST){
        JoueurSetTempsBonus(joueur,JoueurGetTempsBonus(joueur)-1);
        MotoSetVitesse(JoueurGetMoto(joueur),MotoGetVitesse(JoueurGetMoto(joueur))+_Vitesse_Boost);
    }
}

char testCollisionMotoBonus(Joueur *mesJoueurs,Bonus* bonus){
    Moto* moto;
    int i;
    float BoiteMoto[4];
    float Boitebonus[4];
    char boolCollision = 0;
    for(i=0;i<_Nombre_de_Joueur;i++){
        moto=JoueurGetMoto(mesJoueurs+i);
        BoiteMoto[0]=MotoGetPositionX(moto);
        BoiteMoto[1]=MotoGetPositionY(moto);
        BoiteMoto[2]=MotoGetPositionX(moto)+(float)MotoGetTailleX(moto);
        BoiteMoto[3]=MotoGetPositionY(moto)+(float)MotoGetTailleY(moto);
        Boitebonus[0]=BonusGetPositionX(bonus);
        Boitebonus[1]=BonusGetPositionY(bonus);
        Boitebonus[2]=BonusGetPositionX(bonus)+(float)BonusGetTailleX(bonus);
        Boitebonus[3]=BonusGetPositionY(bonus)+(float)BonusGetTailleY(bonus);
        if((BoiteMoto[0]<Boitebonus[2])&&
           (BoiteMoto[2]>Boitebonus[0])&&
           (BoiteMoto[1]<Boitebonus[3])&&
           (BoiteMoto[3]>Boitebonus[1]))
        {boolCollision=i+1;}
    }
    return boolCollision;
}

char testCollisionMursBonus(Grid *grille,Bonus* bonus){
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
                if(((Boitebonus[0]<boundingBoxMur[2])&&(Boitebonus[2]>boundingBoxMur[0])
                    &&(Boitebonus[1]<boundingBoxMur[3])&&(Boitebonus[3]>boundingBoxMur[1]))
                    ||((Boitebonus[0]<borduresGrid[0])&&(Boitebonus[2]>borduresGrid[2])
                    &&(Boitebonus[1]<borduresGrid[1])&&(Boitebonus[3]>borduresGrid[3])))
                {boolCollision = 1;}
                i++;
            }
    return boolCollision;
}

void PlaceBonus(Jeu *jeu,Bonus* bonus){
    float positionX;
    float positionY;
    unsigned int effetBonus;
    Grid *grille=JeuGetGrille(jeu);
    srand(time(NULL));
    do{
        positionX=rand()%(GridGetTailleX(grille)-BonusGetTailleX(bonus))+GridGetPositionX(grille);
        positionY=rand()%(GridGetTailleY(grille)-BonusGetTailleY(bonus))+GridGetPositionY(grille);
        BonusSetPositionX(bonus,positionX);
        BonusSetPositionY(bonus,positionY);
        effetBonus=rand()%_Nombre_Type_Bonus +1;
        BonusSetEffetBonus(bonus,effetBonus);
    }while((testCollisionMursBonus(grille,bonus)==1)||(testCollisionMotoBonus(jeu->mesJoueurs,bonus)!=0));
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
    char touchebonus1='a';
    char touchebonus2='i';

    short int jeuContinue=0;
    Jeu jeu;
    Joueur *mesJoueurs=(Joueur*)malloc(_Nombre_de_Joueur*sizeof(Joueur));

    MurConstructeur(&unMur,posXm,posYm,tailleXm,tailleYm,couleur2,dureeVie);

    GridConstructeur(&grille,posXg,posYg,tailleXg,tailleYg,&mesMurs);

    MotoConstructeur(&moto1,posX1,posY1,tailleX1,tailleY1,vitesse1,direction1);
    ControleConstructeur(&controle1,touchedroite1,touchegauche1,touchehaut1,touchebas1,touchebonus1);
    JoueurConstructeur(&joueur1,&moto1,&controle1,couleur1,1,AUCUN,-1);
    mesJoueurs[0]=joueur1;

    printf("La valeur posX1 est %f et dans la Moto1 du joueur1 est de %f \n",posX1,
           MotoGetPositionX(JoueurGetMoto(&joueur1)));

    MotoConstructeur(&moto2,posX2,posY2,tailleX2,tailleY2,vitesse2,direction2);
    ControleConstructeur(&controle2,touchedroite2,touchegauche2,touchehaut2,touchebas2,touchebonus2);
    JoueurConstructeur(&joueur2,&moto2,&controle2,couleur2,1,AUCUN,-1);
    mesJoueurs[1]=joueur2;

    printf("La valeur posX2 est %f et dans la Moto2 du joueur2 est de %f \n",
           posX2,MotoGetPositionX(JoueurGetMoto(&joueur2)));

    JeuConstructeur(&jeu,&grille,mesJoueurs);


    printf("La valeur vitesse2 est %f et dans la vitesse de la moto2 du joueur2 du jeu est de %f \n",
           vitesse2,MotoGetVitesse(JoueurGetMoto(JeuGetIemeJoueurs(&jeu,1))));

    assert(0== testCollisionMur(JeuGetIemeJoueurs(&jeu,0),JeuGetGrille(&jeu)));
    assert(0== testCollisionMur(JeuGetIemeJoueurs(&jeu,1),JeuGetGrille(&jeu)));

    ajouteMur(GridGetMesMurs(JeuGetGrille(&jeu)),unMur);
    assert(1== testCollisionMur(JeuGetIemeJoueurs(&jeu,0),JeuGetGrille(&jeu)));
    assert(0== testCollisionMur(JeuGetIemeJoueurs(&jeu,1),JeuGetGrille(&jeu)));

    bougeMoto(&jeu);
    printf("La vitesse de la moto1 (1 avant) après bougeMoto est %f \n",
           MotoGetVitesse(JoueurGetMoto(JeuGetIemeJoueurs(&jeu,0))));
    printf("La positionY de la moto2 (2avant + vitesse) après bougeMoto est %f \n",
           MotoGetPositionY(JoueurGetMoto(JeuGetIemeJoueurs(&jeu,1))));

    nettoieGrid(GridGetMesMurs(JeuGetGrille(&jeu)));

    JeuEvolue(&jeu,&jeuContinue);

    JeuDestructeur(&jeu);
    printf("Après destruction, la position de la grille du jeu est %f \n",GridGetPositionX(JeuGetGrille(&jeu)));
    printf("Après destruction, le pointeur de mesJoueurs est %p \n \n",jeu.mesJoueurs);


}


