/**
*\file [Jeu.c]
*\brief Module centrale du Jeu
*\author {Antoine.C,Matthieu.B}
*\version 2.1
*\date 13 mars 2013
*/
#include "Jeu.h"
#include "Joueur.h"
#include "Grid.h"
#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TableauDynamiqueEntier.h"



Grid* JeuGetGrille(Jeu* jeu){
    return &(jeu->grille);
}
Joueur* JeuGetIemeJoueurs(Jeu* jeu,int i){
    return (jeu->mesJoueurs)+i;
}
int JeuGetIemeScore(Jeu* jeu,int i){
    return (jeu->scores)[i];
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
void JeuSetIemeScore(Jeu* jeu,int score,int i){
    (jeu->scores)[i]=score;
}
void JeuSetIemeBonus(Jeu* jeu,const Bonus* bonus,int i){
    (jeu->mesBonus)[i]=*bonus;
}
void JeuSetTempsProchainBonus(Jeu* jeu,int tempsProchainBonus){
    jeu->tempsProchainBonus=tempsProchainBonus;
}

void JeuConstructeur(Jeu* jeu, Grid* grille, Joueur *mesJoueurs, int* scores){
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
    jeu->scores=scores;
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
    jeu->scores=NULL;
}

char testCollisionGenerique(float objet1[4],float objet2[4]){
    char boolcollision=0;
    if((objet1[0]<objet2[2])&&
       (objet1[2]>objet2[0])&&
       (objet1[1]<objet2[3])&&
       (objet1[3]>objet2[1]))
    {boolcollision=1;}
    return boolcollision;
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
    float boundingboxDernierMur[4];
    if(dernierMur!=0){
        boundingboxDernierMur[0]=MurGetPositionX(dernierMur);
        boundingboxDernierMur[1]=MurGetPositionY(dernierMur);
        boundingboxDernierMur[2]=MurGetPositionX(dernierMur)+(float)MurGetTailleX(dernierMur);
        boundingboxDernierMur[3]=MurGetPositionY(dernierMur)+(float)MurGetTailleY(dernierMur);
    }
    if((boundingBoxMoto[0]<borduresGrid[0])||
       (boundingBoxMoto[2]>borduresGrid[2])||
       (boundingBoxMoto[1]<borduresGrid[1])||
       (boundingBoxMoto[3]>borduresGrid[3]))
    {boolCollision = 1;}
    else while((i<TabDynMurGetTaille_utilisee(GridGetMesMurs(grille)))&&(boolCollision==0)){
                unMur=adresseIemeElementTabDynMur(GridGetMesMurs(grille),i);
                boundingBoxMur[0]=MurGetPositionX(unMur);
                boundingBoxMur[1]=MurGetPositionY(unMur);
                boundingBoxMur[2]=MurGetPositionX(unMur)
                                +(float)MurGetTailleX(unMur);
                boundingBoxMur[3]=MurGetPositionY(unMur)
                                +(float)MurGetTailleY(unMur);
                if((testCollisionGenerique(boundingBoxMoto,boundingBoxMur))&&
                    (((MurGetDureeVie(unMur))<_Duree_Vie_Mur)||(JoueurGetCouleur(joueur)!=MurGetCouleur(unMur))))
                {boolCollision = 1;}
                if((MotoGetVitesse(JoueurGetMoto(joueur))>=10)&&
                    (dernierMur!=NULL)&&
                    (testCollisionGenerique(boundingboxDernierMur,boundingBoxMur))&&
                    ((MurGetDureeVie(unMur)<(_Duree_Vie_Mur))||(MurGetCouleur(unMur)!=MurGetCouleur(dernierMur)))&&
                    ((((MotoGetDirection(JoueurGetMoto(joueur))==HAUT)||(MotoGetDirection(JoueurGetMoto(joueur))==BAS))&&(boundingboxDernierMur[0]!=boundingBoxMur[0]))||
                    (((MotoGetDirection(JoueurGetMoto(joueur))==GAUCHE)||(MotoGetDirection(JoueurGetMoto(joueur))==DROITE))&&(boundingboxDernierMur[1]!=boundingBoxMur[1]))) )
                {boolCollision=2;}
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
    if(testCollisionGenerique(boundingBoxMoto1,boundingBoxMoto2)){
        boolCollision=1;
    }
    return boolCollision;
}

void JeuActionClavier(Joueur* joueur,Direction direction,Grid* grille){
    Moto* uneMoto=JoueurGetMoto(joueur);
    unsigned int tailleTemp=MotoGetTailleX(uneMoto);
    Mur unMur;
    float dureeVieMur=_Duree_Vie_Mur;
    char directionChange=0;
    if(MotoGetDirection(uneMoto)==HAUT){
        MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                            MotoGetTailleX(uneMoto),(float)MotoGetTailleY(uneMoto),
                            JoueurGetCouleur(joueur),dureeVieMur);
        if(direction==GAUCHE){
            MotoSetDirection(uneMoto,GAUCHE);
            MotoSetPositionX(uneMoto,(MotoGetPositionX(uneMoto)+(float)MotoGetTailleX(uneMoto)-(float)MotoGetTailleY(uneMoto)));
            directionChange=1;
            }
        else if(direction==DROITE){
            MotoSetDirection(uneMoto,DROITE);
            directionChange=1;
            }
        }
    else if(MotoGetDirection(uneMoto)==BAS){
            MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                            MotoGetTailleX(uneMoto),(float)MotoGetTailleY(uneMoto),
                            JoueurGetCouleur(joueur),dureeVieMur);
            if(direction==GAUCHE){
                MotoSetDirection(uneMoto,GAUCHE);
                MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+(float)MotoGetTailleX(uneMoto)-(float)MotoGetTailleY(uneMoto));
                MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)MotoGetTailleY(uneMoto)-(float)MotoGetTailleX(uneMoto));
                directionChange=1;
            }
            else if(direction==DROITE){
                MotoSetDirection(uneMoto,DROITE);
                MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)MotoGetTailleY(uneMoto)-(float)MotoGetTailleX(uneMoto));
                directionChange=1;
                }
        }
        else if(MotoGetDirection(uneMoto)==GAUCHE){
            MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                            MotoGetTailleX(uneMoto),MotoGetTailleY(uneMoto),
                            JoueurGetCouleur(joueur),dureeVieMur);
                if(direction==HAUT){
                    MotoSetDirection(uneMoto,HAUT);
                    MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)MotoGetTailleY(uneMoto)-(float)MotoGetTailleX(uneMoto));
                    directionChange=1;
                }
                else if(direction==BAS){
                        MotoSetDirection(uneMoto,BAS);
                        directionChange=1;
                    }
            }
            else if(MotoGetDirection(uneMoto)==DROITE){
                    MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                            MotoGetTailleX(uneMoto),MotoGetTailleY(uneMoto),
                            JoueurGetCouleur(joueur),dureeVieMur);
                    if(direction==HAUT){
                        MotoSetDirection(uneMoto,HAUT);
                        MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+(float)MotoGetTailleX(uneMoto)-(float)MotoGetTailleY(uneMoto));
                        MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)MotoGetTailleY(uneMoto)-(float)MotoGetTailleX(uneMoto));
                        directionChange=1;
                    }
                    else if(direction==BAS){
                            MotoSetDirection(uneMoto,BAS);
                            MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+(float)MotoGetTailleX(uneMoto)-(float)MotoGetTailleY(uneMoto));
                            directionChange=1;
                    }
                }
    if(directionChange==1){
        JoueurSetBooltourne(joueur,1);
        MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
        MotoSetTailleY(uneMoto,tailleTemp);
        ajouteMur(GridGetMesMurs(grille),unMur);
        JoueurSetDernierMur(joueur,adresseIemeElementTabDynMur(GridGetMesMurs(grille),TabDynMurGetTaille_utilisee(GridGetMesMurs(grille))-1));
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
            JoueurSetDernierMur(JeuGetIemeJoueurs(jeu,i),adresseIemeElementTabDynMur(GridGetMesMurs(JeuGetGrille(jeu)),TabDynMurGetTaille_utilisee(GridGetMesMurs(JeuGetGrille(jeu)))-1));
            MotoSetVitesse(uneMoto,MotoGetVitesse(uneMoto)+_Acceleration);
        }
    }
}

void JeuEvolue(Jeu* jeu,short int* jeuFini,char *nouveauMessage,Couleur *couleurMessage){
    int i,j;
    Grid* grille=JeuGetGrille(jeu);
    Bonus* unBonus=NULL;
    short int NbJoueurEnJeu=0;
    short int NbJoueurEnDoute=0;
    char collisionBonus=0;
    char collisionMur=0;
    Joueur *joueur;
    char chaine[10];


    bougeMoto(jeu);
    for(i=0;i<_Nombre_de_Joueur;i++){
        joueur=JeuGetIemeJoueurs(jeu,i);
        if(JoueurGetEnJeu(joueur)==VIVANT){
            collisionMur=testCollisionMur(joueur,grille);
            if(collisionMur==1){
                JouerIemeSonCourt(&(jeu->musique),0);
                sprintf(nouveauMessage,"Le joueur %d a perdu ! ",i+1);
                JoueurSetEnJeu(joueur,MOURANT);
                *couleurMessage=JoueurGetCouleur(joueur);
            }
            else {
                if(collisionMur==2){
                    JoueurSetEnJeu(joueur,DOUTE);
                }
                for(j=i+1;(j<_Nombre_de_Joueur);j++){
                    if((JoueurGetEnJeu(JeuGetIemeJoueurs(jeu,j))==VIVANT)
                       &&(testCollisionMoto(JoueurGetMoto(JeuGetIemeJoueurs(jeu,i)),
                                            JoueurGetMoto(JeuGetIemeJoueurs(jeu,j))))){
                        JouerIemeSonCourt(&(jeu->musique),0);
                        JoueurSetEnJeu(JeuGetIemeJoueurs(jeu,j),MOURANT);
                        JoueurSetEnJeu(JeuGetIemeJoueurs(jeu,i),MOURANT);
                        sprintf(nouveauMessage,"Mort des joueurs %d et %d !",i+1,j+1);
                        *couleurMessage=NOIR;
                    }
                }
            }
        }
    }
    for(i=0;i<_Nombre_de_Joueur;i++){
        joueur=JeuGetIemeJoueurs(jeu,i);
        if(JoueurGetEnJeu(joueur)==VIVANT){
            NbJoueurEnJeu++;
        }
        if(JoueurGetEnJeu(joueur)==DOUTE){
            NbJoueurEnDoute++;
            NbJoueurEnJeu++;
        }
    }
    if(NbJoueurEnDoute==1){
        for(i=0;i<_Nombre_de_Joueur;i++){
            joueur=JeuGetIemeJoueurs(jeu,i);
            if(JoueurGetEnJeu(joueur)==DOUTE){
                JouerIemeSonCourt(&(jeu->musique),0);
                sprintf(nouveauMessage,"Le joueur %d a perdu !",i+1);
                JoueurSetEnJeu(joueur,MOURANT);
                *couleurMessage=JoueurGetCouleur(joueur);
                NbJoueurEnJeu--;
            }
        }
    }
    if(NbJoueurEnDoute>1){
        for(i=0;i<_Nombre_de_Joueur;i++){
            joueur=JeuGetIemeJoueurs(jeu,i);
            if(JoueurGetEnJeu(joueur)==DOUTE){
                if(JoueurGetBooltourne(joueur)==1){
                    JouerIemeSonCourt(&(jeu->musique),0);
                    sprintf(nouveauMessage,"Le joueur %d a perdu !",i+1);
                    *couleurMessage=JoueurGetCouleur(joueur);
                    JoueurSetEnJeu(joueur,MOURANT);
                    NbJoueurEnJeu--;
                }
                else {
                    JoueurSetEnJeu(joueur,VIVANT);
                }
            }
        }
    }
    if(NbJoueurEnJeu==1){
        *jeuFini=1;
        i=0;
        while(i<_Nombre_de_Joueur){
            joueur=JeuGetIemeJoueurs(jeu,i);
            if(JoueurGetEnJeu(joueur)==1){
                JeuSetIemeScore(jeu,JeuGetIemeScore(jeu,i)+2,i);
                sprintf(nouveauMessage,"Le joueur %d a gagne ! ",i+1);
                *couleurMessage=JoueurGetCouleur(joueur);
                i++;
            }
            else {i++;}
        }
    }
    if(NbJoueurEnJeu==0){
        *jeuFini=1;
        strcpy(nouveauMessage,"Joueurs ");
        for(i=0;i<_Nombre_de_Joueur;i++){
            if(JoueurGetEnJeu(JeuGetIemeJoueurs(jeu,i))==MOURANT){
                JeuSetIemeScore(jeu,JeuGetIemeScore(jeu,i)+1,i);
                sprintf(chaine,"%d, ",i+1);
                strcat(nouveauMessage,chaine);
            }
        }
        strcat(nouveauMessage,"font egalite !");
        *couleurMessage=NOIR;
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

    for(i=_Nombre_de_Joueur-_Nombre_IA;i<_Nombre_de_Joueur;i++){
        joueur=JeuGetIemeJoueurs(jeu,i);
        if((JoueurGetBoolIA(joueur)==1)&&(JoueurGetEnJeu(joueur)==VIVANT))
            JeuGereIA(joueur,jeu);
    }
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
        if(testCollisionGenerique(Boitebonus,BoiteMoto))
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
    while((i<TabDynMurGetTaille_utilisee(GridGetMesMurs(grille)))&&(boolCollision==0)){
                boundingBoxMur[0]=MurGetPositionX(adresseIemeElementTabDynMur(GridGetMesMurs(grille),i));
                boundingBoxMur[1]=MurGetPositionY(adresseIemeElementTabDynMur(GridGetMesMurs(grille),i));
                boundingBoxMur[2]=MurGetPositionX(adresseIemeElementTabDynMur(GridGetMesMurs(grille),i))
                                +(float)MurGetTailleX(adresseIemeElementTabDynMur(GridGetMesMurs(grille),i));
                boundingBoxMur[3]=MurGetPositionY(adresseIemeElementTabDynMur(GridGetMesMurs(grille),i))
                                +(float)MurGetTailleY(adresseIemeElementTabDynMur(GridGetMesMurs(grille),i));
                if((testCollisionGenerique(Boitebonus,boundingBoxMur))
                    ||((Boitebonus[0]<borduresGrid[0])||(Boitebonus[2]>borduresGrid[2])
                    ||(Boitebonus[1]<borduresGrid[1])||(Boitebonus[3]>borduresGrid[3])))
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

void afficheGrilleAnalyse(short int (*grilleAnalyse)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                    [_Taille_X_Grille/_Precision_Analyse_IA]){
    int i,j;
    FILE* fichier=NULL;
    fichier=fopen("Module_image/grilleAnalyse.txt","w+");
    for(i=0;i<_Taille_Y_Grille/_Precision_Analyse_IA;i++){
        for(j=0;j<_Taille_X_Grille/_Precision_Analyse_IA;j++){
            fprintf(fichier,"%d ",(*grilleAnalyse)[i][j]);
        }
    }
    fclose(fichier);
}

void afficheGrilleDistances(short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA][_Taille_X_Grille/_Precision_Analyse_IA]){
    int i,j;
    FILE* fichier=NULL;
    fichier=fopen("Module_image/grilleDistances.txt","w+");
    for(i=0;i<_Taille_Y_Grille/_Precision_Analyse_IA;i++){
        for(j=0;j<_Taille_X_Grille/_Precision_Analyse_IA;j++){
            fprintf(fichier,"%d ",(*grilleDistance)[i][j]);
        }
    }
    fclose(fichier);
}

void JeuGereIA(Joueur* joueurIA,Jeu* jeu){
    int i,j;
    short int ligneJoueurIA,colonneJoueurIA,ligneJoueurCible,colonneJoueurCible;
    short int distanceCible=0;
    short int grilleAnalyse[_Taille_Y_Grille/_Precision_Analyse_IA ][_Taille_X_Grille/_Precision_Analyse_IA];
    short int grilleDistances[_Taille_Y_Grille/_Precision_Analyse_IA ][_Taille_X_Grille/_Precision_Analyse_IA];
    short int grilleDistancesCible[_Taille_Y_Grille/_Precision_Analyse_IA ][_Taille_X_Grille/_Precision_Analyse_IA];
    for(i=0;i<_Taille_Y_Grille/_Precision_Analyse_IA;i++){
        for(j=0;j<_Taille_X_Grille/_Precision_Analyse_IA;j++){
            grilleAnalyse[i][j]=0;
            grilleDistances[i][j]=-1;
            grilleDistancesCible[i][j]=-1;
        }
    } /** On initialise la grilleAnalyse et la grilleDistance à 0*/
    indicesGrilleJoueur(&ligneJoueurIA,&colonneJoueurIA,joueurIA);
    /** On initialise la position du joueurIA au devant de sa moto*/
    creerGrilleAnalyse(&grilleAnalyse,jeu,joueurIA);
  /*  afficheGrilleAnalyse(&grilleAnalyse);*/
    creerGrilleDistances(ligneJoueurIA,colonneJoueurIA,&grilleAnalyse,&grilleDistances);
  /*  afficheGrilleDistances(&grilleDistances);*/
    distanceCible=choisieCibleIA(joueurIA,jeu,&grilleDistances);
    if(JoueurGetJoueurCible(joueurIA)!=0){
        indicesGrilleJoueur(&ligneJoueurCible,&colonneJoueurCible,JeuGetIemeJoueurs(jeu,JoueurGetJoueurCible(joueurIA)-1));
        creerGrilleDistances(ligneJoueurCible,colonneJoueurCible,&grilleAnalyse,&grilleDistancesCible);
        /*afficheGrilleDistances(&grilleDistancesCible);*/
        choisieDirection(joueurIA,jeu,distanceCible,&grilleDistancesCible);
    }
    else choisieDirection(joueurIA,jeu,distanceCible,&grilleDistances);
}

void indicesGrilleJoueur(short int *ligne,short int *colonne,Joueur* joueur){
    Direction directionJoueur=MotoGetDirection(JoueurGetMoto(joueur));
    if(directionJoueur==HAUT){
        *ligne=floor(((MotoGetPositionY(JoueurGetMoto(joueur))+2.5))/_Precision_Analyse_IA);
        *colonne=floor(((MotoGetPositionX(JoueurGetMoto(joueur))+2.5))/_Precision_Analyse_IA);
    }
    else {if(directionJoueur==BAS){
            *ligne=floor(((MotoGetPositionY(JoueurGetMoto(joueur))+7.5))/_Precision_Analyse_IA);
            *colonne=floor(((MotoGetPositionX(JoueurGetMoto(joueur))+2.5))/_Precision_Analyse_IA);
        }
        else {if(directionJoueur==GAUCHE){
                *ligne=floor(((MotoGetPositionY(JoueurGetMoto(joueur))+2.5))/_Precision_Analyse_IA);
                *colonne=floor(((MotoGetPositionX(JoueurGetMoto(joueur))+2.5))/_Precision_Analyse_IA);
            }
            else {if(directionJoueur==DROITE){
                    *ligne=floor(((MotoGetPositionY(JoueurGetMoto(joueur))+2.5))/_Precision_Analyse_IA);
                    *colonne=floor(((MotoGetPositionX(JoueurGetMoto(joueur))+7.5))/_Precision_Analyse_IA);
                }
            }
        }
    }
}

void creerGrilleDistances(short int ligne1,short int colonne1,
                                short int (*grilleAnalyse)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                          [_Taille_X_Grille/_Precision_Analyse_IA],
                                short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                          [_Taille_X_Grille/_Precision_Analyse_IA]){
    int i;
    short int distance=0;
    TableauDynamiqueEntier tabCase;
    int ligneCase,colonneCase;
    initialiserTabDynEntier(&tabCase);
    (*grilleDistance)[ligne1][colonne1]=distance;
    distance++;
    ajouterElementTabDynEntier(&tabCase,ligne1);
    ajouterElementTabDynEntier(&tabCase,colonne1);
    while(TabDynEntierGetTaille_utilisee(&tabCase)!=0){
        for(i=TabDynEntierGetTaille_utilisee(&tabCase)-1;i>=0;i-=2){
            ligneCase=valeurIemeElementTabDynEntier(&tabCase,i-1);
            colonneCase=valeurIemeElementTabDynEntier(&tabCase,i);
            if((ligneCase!=_Taille_Y_Grille/_Precision_Analyse_IA-1)&&((*grilleAnalyse)[ligneCase+1][colonneCase]==0)&&
                    ((*grilleDistance)[ligneCase+1][colonneCase]==-1)){
                (*grilleDistance)[ligneCase+1][colonneCase]=distance;
                ajouterElementTabDynEntier(&tabCase,ligneCase+1);
                ajouterElementTabDynEntier(&tabCase,colonneCase);
            }
            if((colonneCase!=_Taille_X_Grille/_Precision_Analyse_IA-1)&&((*grilleAnalyse)[ligneCase][colonneCase+1]==0)&&
                    ((*grilleDistance)[ligneCase][colonneCase+1]==-1)){
                (*grilleDistance)[ligneCase][colonneCase+1]=distance;
                ajouterElementTabDynEntier(&tabCase,ligneCase);
                ajouterElementTabDynEntier(&tabCase,colonneCase+1);
            }
            if((ligneCase!=0)&&((*grilleAnalyse)[ligneCase-1][colonneCase]==0)&&
                    ((*grilleDistance)[ligneCase-1][colonneCase]==-1)){
                (*grilleDistance)[ligneCase-1][colonneCase]=distance;
                ajouterElementTabDynEntier(&tabCase,ligneCase-1);
                ajouterElementTabDynEntier(&tabCase,colonneCase);
            }
            if((colonneCase!=0)&&((*grilleAnalyse)[ligneCase][colonneCase-1]==0)&&
                    ((*grilleDistance)[ligneCase][colonneCase-1]==-1)){
                (*grilleDistance)[ligneCase][colonneCase-1]=distance;
                ajouterElementTabDynEntier(&tabCase,ligneCase);
                ajouterElementTabDynEntier(&tabCase,colonneCase-1);
            }
            supprimerElementTabDynEntier(&tabCase,i);
            supprimerElementTabDynEntier(&tabCase,i-1);
        }
        distance++;
    }
    testamentTabDynEntier(&tabCase);
}

void creerGrilleAnalyse(short int (*grilleAnalyse)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                  [_Taille_X_Grille/_Precision_Analyse_IA],
                        Jeu* jeu,Joueur* joueurIA){
    int i;
    float decalageXMur=0;
    float decalageYMur=0;
    int indiceLigne=0;
    int indiceColonne=0;
    Mur* unMur;
    short int* pValeurCase;
    for(i=TabDynMurGetTaille_utilisee(GridGetMesMurs(JeuGetGrille(jeu)))-1;i>=0;i--){ /** On parcours les murs et on  */
        unMur=adresseIemeElementTabDynMur(GridGetMesMurs(JeuGetGrille(jeu)),i);       /** Crée une zone de danger autour d'eux*/
        if((MurGetDureeVie(unMur)<_Duree_Vie_Mur-2)||(MurGetCouleur(unMur)!=JoueurGetCouleur(joueurIA))){
            if(MurGetTailleX(unMur)==5){/**Si la largeur est selon x on se place au bord gauche du mur*/
                decalageXMur=0;
                decalageYMur=MurGetTailleY(unMur);
                while(decalageYMur>0){
                                    /** On crée la zone de danger au bout du mur, on décrémente le décalage */
                                    /** puis on crée la zone de danger au milieu du mur etc ...*/
                    indiceLigne=floor((MurGetPositionY(unMur)+decalageYMur)/_Precision_Analyse_IA);
                    indiceColonne=floor((MurGetPositionX(unMur)+decalageXMur)/_Precision_Analyse_IA);
                    pValeurCase=&((*grilleAnalyse)[indiceLigne][indiceColonne]);
                    if(*pValeurCase<ceil(MurGetDureeVie(unMur)))
                        *pValeurCase=ceil(MurGetDureeVie(unMur));
                    decalageYMur-=_Precision_Analyse_IA;
                    if((decalageYMur<=0)&&(decalageXMur==0)){/**A la fin du parcours on se replace au */
                        decalageXMur=5;                      /**bord droit du mur et on recommence*/
                        decalageYMur=MurGetTailleY(unMur);
                    }
                }
                    /**Enfin on crée la zone de danger au début du mur au bord gauche puis au bord droit*/
                indiceLigne=floor((MurGetPositionY(unMur)+0)/_Precision_Analyse_IA);
                indiceColonne=floor((MurGetPositionX(unMur)+0)/_Precision_Analyse_IA);
                pValeurCase=&((*grilleAnalyse)[indiceLigne][indiceColonne]);
                if(*pValeurCase<ceil(MurGetDureeVie(unMur)))
                    *pValeurCase =ceil(MurGetDureeVie(unMur));
                indiceLigne=floor((MurGetPositionY(unMur)+0)/_Precision_Analyse_IA);
                indiceColonne=floor((MurGetPositionX(unMur)+5)/_Precision_Analyse_IA);
                pValeurCase=&((*grilleAnalyse)[indiceLigne][indiceColonne]);
                if(*pValeurCase<ceil(MurGetDureeVie(unMur)))
                    *pValeurCase =ceil(MurGetDureeVie(unMur));
            }
            else{ /**Si la largeur est selon y on se place au bord haut du mur*/
                decalageYMur=0;
                decalageXMur=MurGetTailleX(unMur);
                while(decalageXMur>0){
                                    /** On crée la zone de danger au bout du mur, on décrémente le décalage */
                                    /** puis on crée la zone de danger au milieu du mur etc ...*/
                    indiceLigne=floor((MurGetPositionY(unMur)+decalageYMur)/_Precision_Analyse_IA);
                    indiceColonne=floor((MurGetPositionX(unMur)+decalageXMur)/_Precision_Analyse_IA);
                    pValeurCase=&((*grilleAnalyse)[indiceLigne][indiceColonne]);
                    if(*pValeurCase<ceil(MurGetDureeVie(unMur)))
                        *pValeurCase =ceil(MurGetDureeVie(unMur));
                    decalageXMur-=_Precision_Analyse_IA;
                    if((decalageXMur<=0)&&(decalageYMur==0)){/**A la fin du parcours on se replace au */
                        decalageYMur=5;                      /**bord bas du mur et on recommence*/
                        decalageXMur=MurGetTailleX(unMur);
                    }
                }
                    /**Enfin on crée la zone de danger au début du mur au bord haut puis au bord bas*/
                indiceLigne=floor((MurGetPositionY(unMur)+0)/_Precision_Analyse_IA);
                indiceColonne=floor((MurGetPositionX(unMur)+0)/_Precision_Analyse_IA);
                pValeurCase=&((*grilleAnalyse)[indiceLigne][indiceColonne]);
                if(*pValeurCase<ceil(MurGetDureeVie(unMur)))
                    *pValeurCase =ceil(MurGetDureeVie(unMur));
                indiceLigne=floor((MurGetPositionY(unMur)+5)/_Precision_Analyse_IA);
                indiceColonne=floor((MurGetPositionX(unMur)+0)/_Precision_Analyse_IA);
                pValeurCase=&((*grilleAnalyse)[indiceLigne][indiceColonne]);
                if(*pValeurCase<ceil(MurGetDureeVie(unMur)))
                    *pValeurCase =ceil(MurGetDureeVie(unMur));
            }
        }
    }
}

short int choisieCibleIA(Joueur* joueurIA,Jeu* jeu,short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                          [_Taille_X_Grille/_Precision_Analyse_IA]){
    int i,numeroJoueurCible=0;
    short int distanceJoueurCible=-1,distanceJoueurCibleTemp;
    Joueur* unJoueur;
    Direction directionJoueur;
    int ligne,colonne;
    for(i=0;i<_Nombre_de_Joueur;i++){
        unJoueur=JeuGetIemeJoueurs(jeu,i);
        if(JoueurGetNumeroJoueur(joueurIA)!=JoueurGetNumeroJoueur(unJoueur)){
            directionJoueur=MotoGetDirection(JoueurGetMoto(unJoueur));
            if(directionJoueur==HAUT){/**On prend pour position du joueur le devant de sa moto
                                        Si cette case est inaccessible on prend une case plus loin*/
                ligne=floor((MotoGetPositionY(JoueurGetMoto(unJoueur)))/_Precision_Analyse_IA);
                colonne=floor((MotoGetPositionX(JoueurGetMoto(unJoueur))+2.5)/_Precision_Analyse_IA);
                if(((*grilleDistance)[ligne][colonne]==-1)&&(ligne!=0)){
                    ligne--;
                }
            }
            else {if(directionJoueur==BAS){
                    ligne=floor((MotoGetPositionY(JoueurGetMoto(unJoueur))+10)/_Precision_Analyse_IA);
                    colonne=floor((MotoGetPositionX(JoueurGetMoto(unJoueur))+2.5)/_Precision_Analyse_IA);
                    if(((*grilleDistance)[ligne][colonne]==-1)&&(ligne!=(_Taille_Y_Grille/_Precision_Analyse_IA)-1)){
                        ligne++;
                    }
                }
                else {if(directionJoueur==GAUCHE){
                        ligne=floor((MotoGetPositionY(JoueurGetMoto(unJoueur))+2.5)/_Precision_Analyse_IA);
                        colonne=floor((MotoGetPositionX(JoueurGetMoto(unJoueur)))/_Precision_Analyse_IA);
                        if(((*grilleDistance)[ligne][colonne]==-1)&&(colonne!=0)){
                            colonne--;
                        }
                    }
                    else {if(directionJoueur==DROITE){
                            ligne=floor((MotoGetPositionY(JoueurGetMoto(unJoueur))+2.5)/_Precision_Analyse_IA);
                            colonne=floor((MotoGetPositionX(JoueurGetMoto(unJoueur))+10)/_Precision_Analyse_IA);
                            if(((*grilleDistance)[ligne][colonne]==-1)&&(colonne!=(_Taille_X_Grille/_Precision_Analyse_IA)-1)){
                                colonne++;
                            }
                        }
                    }
                }
            }
            if(JoueurGetEnJeu(unJoueur)==VIVANT){
                distanceJoueurCibleTemp=(*grilleDistance)[ligne][colonne];
                if((distanceJoueurCibleTemp!=-1)&&
                   ((distanceJoueurCibleTemp<distanceJoueurCible)||(distanceJoueurCible==-1))){
                    distanceJoueurCible=distanceJoueurCibleTemp;
                    numeroJoueurCible=i+1;
                }
            }
        }
    }
    JoueurSetJoueurCible(joueurIA,numeroJoueurCible);
    return distanceJoueurCible;
}

void choisieDirection(Joueur* joueurIA,Jeu *jeu,short int distanceJoueurCible,
                      short int (*grilleDistance)[_Taille_Y_Grille/_Precision_Analyse_IA]
                                                 [_Taille_X_Grille/_Precision_Analyse_IA]){
    int i;
    int ligne1;
    int ligne2;
    int colonne1;
    int colonne2;
    Direction nouvelleDirection=NON_DIRIGE;
    Direction directionCourante=MotoGetDirection(JoueurGetMoto(joueurIA));
    short int distanceTemp,distanceMin=32000,
            distanceSecurite=ceil((MotoGetVitesse(JoueurGetMoto(joueurIA))+1)/_Precision_Analyse_IA);
    char boolDistanceValide=1;
    if((directionCourante==HAUT)||(directionCourante==GAUCHE)){/**on crée 2 points pour définir la hitBox de la moto*/
        ligne1=floor(((MotoGetPositionY(JoueurGetMoto(joueurIA))+0))/_Precision_Analyse_IA);
        colonne1=floor(((MotoGetPositionX(JoueurGetMoto(joueurIA))+0))/_Precision_Analyse_IA);
        ligne2=floor(((MotoGetPositionY(JoueurGetMoto(joueurIA))+5))/_Precision_Analyse_IA);
        colonne2=floor(((MotoGetPositionX(JoueurGetMoto(joueurIA))+5))/_Precision_Analyse_IA);
    }
    else{
        if(directionCourante==BAS){
            ligne1=floor(((MotoGetPositionY(JoueurGetMoto(joueurIA))+5))/_Precision_Analyse_IA);
            colonne1=floor(((MotoGetPositionX(JoueurGetMoto(joueurIA))+0))/_Precision_Analyse_IA);
            ligne2=floor(((MotoGetPositionY(JoueurGetMoto(joueurIA))+10))/_Precision_Analyse_IA);
            colonne2=floor(((MotoGetPositionX(JoueurGetMoto(joueurIA))+5))/_Precision_Analyse_IA);
        }
        else{
            if(directionCourante==DROITE){
                ligne1=floor(((MotoGetPositionY(JoueurGetMoto(joueurIA))+0))/_Precision_Analyse_IA);
                colonne1=floor(((MotoGetPositionX(JoueurGetMoto(joueurIA))+5))/_Precision_Analyse_IA);
                ligne2=floor(((MotoGetPositionY(JoueurGetMoto(joueurIA))+5))/_Precision_Analyse_IA);
                colonne2=floor(((MotoGetPositionX(JoueurGetMoto(joueurIA))+10))/_Precision_Analyse_IA);
            }
        }
    }

    if((JoueurGetJoueurCible(joueurIA)==0)){/**Si on a pas de cible, l'IA essaie de survivre sans se bloquer*/
        if(directionCourante==HAUT){
            /**Amélioration possible : fonction aireGrilleDistance qui détermine le choix de direction
            selon la place disponible ou même selon le mur qui va disparaitre le plus tôt */
            if(colonne1>=distanceSecurite){
                for(i=1;i<=distanceSecurite;i++){
                    if((*grilleDistance)[ligne1][colonne1-i]==-1){
                        boolDistanceValide=0;
                    }
                }
                if(boolDistanceValide==1){/**Si la position a gauche de la moto est libre, */
                    JeuActionClavier(joueurIA,GAUCHE,JeuGetGrille(jeu));        /**On tourne à gauche*/
                }
                else{
                    if(ligne1<distanceSecurite){/**Si la position devant la moto est bloquée,*/
                        JeuActionClavier(joueurIA,DROITE,JeuGetGrille(jeu));/**alors on tourne à droite*/
                    }
                    else{
                        boolDistanceValide=1;
                        for(i=1;i<=distanceSecurite;i++){
                            if((*grilleDistance)[ligne1-i][colonne1]==-1){
                                boolDistanceValide=0;
                            }
                        }
                        if(boolDistanceValide==0){/**Si la position devant la moto est bloquée,*/
                            JeuActionClavier(joueurIA,DROITE,JeuGetGrille(jeu));/**alors on tourne à droite*/
                        }
                    }
                }
            }
            else{
                if(ligne1<distanceSecurite){/**Si la position devant la moto est bloquée,*/
                    JeuActionClavier(joueurIA,DROITE,JeuGetGrille(jeu));/**alors on tourne à droite*/
                }
                else{
                    boolDistanceValide=1;
                    for(i=1;i<=distanceSecurite;i++){
                        if((*grilleDistance)[ligne1-i][colonne1]==-1){
                            boolDistanceValide=0;
                        }
                    }
                    if(boolDistanceValide==0){/**Si la position devant la moto est bloquée,*/
                        JeuActionClavier(joueurIA,DROITE,JeuGetGrille(jeu));/**alors on tourne à droite*/
                    }
                }
            }
        }
        else{
            if(directionCourante==BAS){ /**Si la moto va vers le bas, elle essaie de continuer à descendre,*/
                if(ligne2>(_Taille_Y_Grille/_Precision_Analyse_IA)-1-distanceSecurite){ /**jusqu'à ce que le bas soit bloqué*/
                   if(colonne1>=distanceSecurite){
                       boolDistanceValide=1;
                       for(i=1;i<=distanceSecurite;i++){
                            if((*grilleDistance)[ligne2][colonne1-i]==-1){
                                boolDistanceValide=0;
                            }
                        }
                        if(boolDistanceValide==1){
                            JeuActionClavier(joueurIA,GAUCHE,JeuGetGrille(jeu));
                        }
                        else{
                            JeuActionClavier(joueurIA,DROITE,JeuGetGrille(jeu));
                        }
                   }
                   else{
                        JeuActionClavier(joueurIA,DROITE,JeuGetGrille(jeu));
                    }
                }
                else{
                    boolDistanceValide=1;
                    for(i=1;i<=distanceSecurite;i++){
                        if((*grilleDistance)[ligne2+i][colonne1]==-1){
                            boolDistanceValide=0;
                        }
                    }
                    if(boolDistanceValide==0){ /**jusqu'à ce que le bas soit bloqué*/
                        if(colonne1>=distanceSecurite){
                           boolDistanceValide=1;
                           for(i=1;i<=distanceSecurite;i++){
                                if((*grilleDistance)[ligne2][colonne1-i]==-1){
                                    boolDistanceValide=0;
                                }
                            }
                            if(boolDistanceValide==1){
                                JeuActionClavier(joueurIA,GAUCHE,JeuGetGrille(jeu));
                            }
                            else{
                                JeuActionClavier(joueurIA,DROITE,JeuGetGrille(jeu));
                            }
                       }
                       else{
                            JeuActionClavier(joueurIA,DROITE,JeuGetGrille(jeu));
                        }
                    }
                }
            }
            else{
                if(directionCourante==GAUCHE){
                    if(ligne2<=(_Taille_Y_Grille/_Precision_Analyse_IA)-1-distanceSecurite){
                        boolDistanceValide=1;
                        for(i=1;i<=distanceSecurite;i++){
                            if((*grilleDistance)[ligne2+i][colonne1]==-1){
                                boolDistanceValide=0;
                            }
                        }
                        if(boolDistanceValide==1){
                            JeuActionClavier(joueurIA,BAS,JeuGetGrille(jeu));
                        }
                        else{
                            if(colonne1<distanceSecurite){
                                JeuActionClavier(joueurIA,HAUT,JeuGetGrille(jeu));
                            }
                            else{
                                boolDistanceValide=1;
                                for(i=1;i<=distanceSecurite;i++){
                                    if((*grilleDistance)[ligne1][colonne1-i]==-1){
                                        boolDistanceValide=0;
                                    }
                                }
                                if(boolDistanceValide==0){
                                    JeuActionClavier(joueurIA,HAUT,JeuGetGrille(jeu));
                                }
                            }
                        }
                    }
                    else{
                        if(colonne1<distanceSecurite){
                            JeuActionClavier(joueurIA,HAUT,JeuGetGrille(jeu));
                        }
                        else{
                            boolDistanceValide=1;
                            for(i=1;i<=distanceSecurite;i++){
                                if((*grilleDistance)[ligne1][colonne1-i]==-1){
                                    boolDistanceValide=0;
                                }
                            }
                            if(boolDistanceValide==0){
                                JeuActionClavier(joueurIA,HAUT,JeuGetGrille(jeu));
                            }
                        }
                    }
                }
                else{
                    if(directionCourante==DROITE){
                        if((ligne2<=(_Taille_Y_Grille/_Precision_Analyse_IA)-1-distanceSecurite)){
                           boolDistanceValide=1;
                            for(i=1;i<=distanceSecurite;i++){
                                if((*grilleDistance)[ligne2+i][colonne2]==-1){
                                    boolDistanceValide=0;
                                }
                            }
                            if(boolDistanceValide==1){
                                JeuActionClavier(joueurIA,BAS,JeuGetGrille(jeu));
                            }
                            else{
                                if(colonne2>(_Taille_X_Grille/_Precision_Analyse_IA)-1-distanceSecurite){
                                    JeuActionClavier(joueurIA,HAUT,JeuGetGrille(jeu));
                                }
                                else{
                                    boolDistanceValide=1;
                                    for(i=1;i<=distanceSecurite;i++){
                                        if((*grilleDistance)[ligne2][colonne2+i]==-1){
                                            boolDistanceValide=0;
                                        }
                                    }
                                    if(boolDistanceValide==0){
                                        JeuActionClavier(joueurIA,HAUT,JeuGetGrille(jeu));
                                    }
                                }
                            }
                        }
                        else{
                            if(colonne2>(_Taille_X_Grille/_Precision_Analyse_IA)-1-distanceSecurite){
                                    JeuActionClavier(joueurIA,HAUT,JeuGetGrille(jeu));
                            }
                            else{
                                boolDistanceValide=1;
                                for(i=1;i<=distanceSecurite;i++){
                                    if((*grilleDistance)[ligne2][colonne2+i]==-1){
                                        boolDistanceValide=0;
                                    }
                                }
                                if(boolDistanceValide==0){
                                    JeuActionClavier(joueurIA,HAUT,JeuGetGrille(jeu));
                                }
                            }
                        }
                    }
                }
            }
        }
    }/**Fin de l'algo de survie, ci-dessous l'IA essaie de suivre l'adversaire pour le bloquer*/
    else{
        if(JoueurGetNumeroJoueur(joueurIA)==JoueurGetJoueurCible(joueurIA)){
        }
        if(distanceJoueurCible>=distanceSecurite*2){
            boolDistanceValide=1;
            if(ligne1>=distanceSecurite){
                for(i=1;i<=distanceSecurite;i++){
                    if((*grilleDistance)[ligne1-i][colonne1]==-1){
                        boolDistanceValide=0;
                    }
                }
                distanceTemp=(*grilleDistance)[ligne1-distanceSecurite][colonne1];
                if((distanceTemp<=distanceMin)&&(boolDistanceValide==1)){
                    nouvelleDirection=HAUT;
                    distanceMin=distanceTemp;
                }
            }
            boolDistanceValide=1;
            if(ligne1<=(_Taille_Y_Grille/_Precision_Analyse_IA)-1-distanceSecurite){
                for(i=1;i<=distanceSecurite;i++){
                    if((*grilleDistance)[ligne1+i][colonne1]==-1){
                        boolDistanceValide=0;
                    }
                }
                distanceTemp=(*grilleDistance)[ligne1+distanceSecurite][colonne1];
                if((distanceTemp<distanceMin)&&(boolDistanceValide==1)){
                    nouvelleDirection=BAS;
                    distanceMin=distanceTemp;
                }
            }
            boolDistanceValide=1;
            if(colonne1>=distanceSecurite){
                for(i=1;i<=distanceSecurite;i++){
                    if((*grilleDistance)[ligne1][colonne1-i]==-1){
                        boolDistanceValide=0;
                    }
                }
                distanceTemp=(*grilleDistance)[ligne1][colonne1-distanceSecurite];
                if((distanceTemp<distanceMin)&&(boolDistanceValide==1)){
                    nouvelleDirection=GAUCHE;
                    distanceMin=distanceTemp;
                }
            }
            boolDistanceValide=1;
            if(colonne1<=(_Taille_X_Grille/_Precision_Analyse_IA)-1-distanceSecurite){
                for(i=1;i<=distanceSecurite;i++){
                    if((*grilleDistance)[ligne1][colonne1+i]==-1){
                        boolDistanceValide=0;
                    }
                }
                distanceTemp=(*grilleDistance)[ligne1][colonne1+distanceSecurite];
                if((distanceTemp<distanceMin)&&(boolDistanceValide==1)){
                    nouvelleDirection=DROITE;
                    distanceMin=distanceTemp;
                }
            }

            if (((directionCourante==HAUT)||(directionCourante==BAS))&&
                ((nouvelleDirection==GAUCHE)||(nouvelleDirection==DROITE))){
                JeuActionClavier(joueurIA,nouvelleDirection,JeuGetGrille(jeu));
            }
            else if (((directionCourante==GAUCHE)||(directionCourante==DROITE))&&
                ((nouvelleDirection==HAUT)||(nouvelleDirection==BAS))){
                JeuActionClavier(joueurIA,nouvelleDirection,JeuGetGrille(jeu));
            }

        }
        else{
            nouvelleDirection=MotoGetDirection(JoueurGetMoto(JeuGetIemeJoueurs(jeu,JoueurGetJoueurCible(joueurIA)-1)));
            if (((directionCourante==HAUT)||(directionCourante==BAS))&&
                ((nouvelleDirection==GAUCHE)||(nouvelleDirection==DROITE))){
                JeuActionClavier(joueurIA,nouvelleDirection,JeuGetGrille(jeu));
            }
            else if (((directionCourante==GAUCHE)||(directionCourante==DROITE))&&
                ((nouvelleDirection==HAUT)||(nouvelleDirection==BAS))){
                JeuActionClavier(joueurIA,nouvelleDirection,JeuGetGrille(jeu));
            }
        }
    }
}


void JeuTestRegression(){
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

    short int jeuContinue=0;
    int scores[2]={0};
    Jeu jeu;
    Joueur *mesJoueurs=(Joueur*)malloc(_Nombre_de_Joueur*sizeof(Joueur));

    MurConstructeur(&unMur,posXm,posYm,tailleXm,tailleYm,couleur2,dureeVie);

    GridConstructeur(&grille,posXg,posYg,tailleXg,tailleYg,&mesMurs);

    MotoConstructeur(&moto1,posX1,posY1,tailleX1,tailleY1,vitesse1,direction1);
    ControleConstructeur(&controle1,touchedroite1,touchegauche1,touchehaut1,touchebas1,touchebonus1);
    JoueurConstructeur(&joueur1,&moto1,&controle1,couleur1,1,AUCUN,-1,1,0);
    mesJoueurs[0]=joueur1;

    printf("La valeur posX1 est %f et dans la Moto1 du joueur1 est de %f \n",posX1,
           MotoGetPositionX(JoueurGetMoto(&joueur1)));

    MotoConstructeur(&moto2,posX2,posY2,tailleX2,tailleY2,vitesse2,direction2);
    ControleConstructeur(&controle2,touchedroite2,touchegauche2,touchehaut2,touchebas2,touchebonus2);
    JoueurConstructeur(&joueur2,&moto2,&controle2,couleur2,1,AUCUN,-1,1,0);
    mesJoueurs[1]=joueur2;

    printf("La valeur posX2 est %f et dans la Moto2 du joueur2 est de %f \n",
           posX2,MotoGetPositionX(JoueurGetMoto(&joueur2)));

    JeuConstructeur(&jeu,&grille,mesJoueurs,scores);


    printf("La valeur vitesse2 est %f et dans la vitesse de la moto2 du joueur2 du jeu est de %f \n",
           vitesse2,MotoGetVitesse(JoueurGetMoto(JeuGetIemeJoueurs(&jeu,1))));

    assert(0== testCollisionMur(JeuGetIemeJoueurs(&jeu,0),JeuGetGrille(&jeu)));
    assert(0== testCollisionMur(JeuGetIemeJoueurs(&jeu,1),JeuGetGrille(&jeu)));

  /*  ajouteMur(GridGetMesMurs(JeuGetGrille(&jeu)),unMur);
    assert(1== testCollisionMur(JeuGetIemeJoueurs(&jeu,0),JeuGetGrille(&jeu)));
    assert(0== testCollisionMur(JeuGetIemeJoueurs(&jeu,1),JeuGetGrille(&jeu)));*/

    bougeMoto(&jeu);
    printf("La vitesse de la moto1 (1 avant) après bougeMoto est %f \n",
           MotoGetVitesse(JoueurGetMoto(JeuGetIemeJoueurs(&jeu,0))));
    printf("La positionY de la moto2 (2avant + vitesse) après bougeMoto est %f \n",
           MotoGetPositionY(JoueurGetMoto(JeuGetIemeJoueurs(&jeu,1))));

    printf("\n printf \n");
    JeuGereIA(JeuGetIemeJoueurs(&jeu,0),&jeu);
    printf("\n printf \n");

    nettoieGrid(GridGetMesMurs(JeuGetGrille(&jeu)));

    JeuEvolue(&jeu,&jeuContinue,NULL,NOIR);

    JeuDestructeur(&jeu);
    printf("Après destruction, la position de la grille du jeu est %f \n",GridGetPositionX(JeuGetGrille(&jeu)));
    printf("Après destruction, le pointeur de mesJoueurs est %p \n \n",jeu.mesJoueurs);


}


