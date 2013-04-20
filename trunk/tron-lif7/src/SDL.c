#include "Jeu.h"
#include "SDL.h"
#include <assert.h>
#include <SDL/SDL.h>
#include <time.h>
#include "Joystick.h"


Jeu* SDLGetJeu(SDL* sdl){
    return &(sdl->jeu);
}
SDL_Surface * SDLGetIemeTexture(const SDL* sdl,unsigned int i){
    return sdl->textures[i];
}
Manette* SDLGetIemeManette(const SDL* sdl,unsigned int i){
    return (sdl->mesManettes)+i;
}
SDL_Surface * SDLGetTextures(const SDL* sdl){
    return sdl->textures[0];
}

void SDLSetJeu(SDL * sdl,Jeu* jeu){
    sdl->jeu= *jeu;
}
void SDLSetIemeTexture(SDL *sdl,unsigned int i,SDL_Surface * texture){
    sdl->textures[i]=texture;
}




SDL_Surface* SDLChargeImage(const char* nomfichier){
	/* Temporary storage for the image that's loaded */
	SDL_Surface* loadedImage = NULL;

	/* Load the image */
	loadedImage = SDL_LoadBMP( nomfichier );

	/* If nothing went wrong in loading the image */
	if ( loadedImage == NULL ) printf("image non chargée ! %s \n",nomfichier);


	/* Return the optimized image */
	return loadedImage;
}

void SDLAppliqueSurface(SDL_Surface * surfaceA, SDL_Surface * surfaceB,const int positionX,const int positionY){
	/* Make a temporary rectangle to hold the offsets */
	SDL_Rect offset;

	/* Give the offsets to the rectangle */
	offset.x = positionX;
	offset.y = positionY;

	/* Blit the surface */
	SDL_BlitSurface( surfaceA, NULL, surfaceB, &offset );
}



void SDLConstructeur(SDL *sdl,Jeu* jeu,Manette *manettes){
    SDLSetJeu(sdl,jeu);
    SDLSetIemeTexture(sdl,0,SDL_SetVideoMode(1010,710,32,SDL_HWSURFACE));
    SDLSetIemeTexture(sdl,1,SDLChargeImage("data/grid.bmp"));
    SDLSetIemeTexture(sdl,2,SDLChargeImage("data/moto1H.bmp"));
    SDLSetIemeTexture(sdl,3,SDLChargeImage("data/moto1B.bmp"));
    SDLSetIemeTexture(sdl,4,SDLChargeImage("data/moto1G.bmp"));
    SDLSetIemeTexture(sdl,5,SDLChargeImage("data/moto1D.bmp"));
    SDLSetIemeTexture(sdl,6,SDLChargeImage("data/moto2H.bmp"));
    SDLSetIemeTexture(sdl,7,SDLChargeImage("data/moto2B.bmp"));
    SDLSetIemeTexture(sdl,8,SDLChargeImage("data/moto2G.bmp"));
    SDLSetIemeTexture(sdl,9,SDLChargeImage("data/moto2D.bmp"));
    if(_Nombre_de_Joueur>=3){
        SDLSetIemeTexture(sdl,10,SDLChargeImage("data/moto3H.bmp"));
        SDLSetIemeTexture(sdl,11,SDLChargeImage("data/moto3B.bmp"));
        SDLSetIemeTexture(sdl,12,SDLChargeImage("data/moto3G.bmp"));
        SDLSetIemeTexture(sdl,13,SDLChargeImage("data/moto3D.bmp"));
    }
    if(_Nombre_de_Joueur>=4){
        SDLSetIemeTexture(sdl,14,SDLChargeImage("data/moto4H.bmp"));
        SDLSetIemeTexture(sdl,15,SDLChargeImage("data/moto4B.bmp"));
        SDLSetIemeTexture(sdl,16,SDLChargeImage("data/moto4G.bmp"));
        SDLSetIemeTexture(sdl,17,SDLChargeImage("data/moto4D.bmp"));
    }
    if(_Nombre_de_Joueur>=5){
        SDLSetIemeTexture(sdl,18,SDLChargeImage("data/moto5H.bmp"));
        SDLSetIemeTexture(sdl,19,SDLChargeImage("data/moto5B.bmp"));
        SDLSetIemeTexture(sdl,20,SDLChargeImage("data/moto5G.bmp"));
        SDLSetIemeTexture(sdl,21,SDLChargeImage("data/moto5D.bmp"));
    }
    if(_Nombre_de_Joueur>=6){
        SDLSetIemeTexture(sdl,22,SDLChargeImage("data/moto6H.bmp"));
        SDLSetIemeTexture(sdl,23,SDLChargeImage("data/moto6B.bmp"));
        SDLSetIemeTexture(sdl,24,SDLChargeImage("data/moto6G.bmp"));
        SDLSetIemeTexture(sdl,25,SDLChargeImage("data/moto6D.bmp"));
    }
    if(_Nombre_de_Joueur>=7){
        SDLSetIemeTexture(sdl,26,SDLChargeImage("data/moto7H.bmp"));
        SDLSetIemeTexture(sdl,27,SDLChargeImage("data/moto7B.bmp"));
        SDLSetIemeTexture(sdl,28,SDLChargeImage("data/moto7G.bmp"));
        SDLSetIemeTexture(sdl,29,SDLChargeImage("data/moto7D.bmp"));
    }
    if(_Nombre_de_Joueur>=8){
        SDLSetIemeTexture(sdl,30,SDLChargeImage("data/moto8H.bmp"));
        SDLSetIemeTexture(sdl,31,SDLChargeImage("data/moto8B.bmp"));
        SDLSetIemeTexture(sdl,32,SDLChargeImage("data/moto8G.bmp"));
        SDLSetIemeTexture(sdl,33,SDLChargeImage("data/moto8D.bmp"));
    }
    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4,SDLChargeImage("data/BonusNettoyage.bmp"));
    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+1,SDLChargeImage("data/BonusBoost.bmp"));
    sdl->mesManettes=manettes;

}

void SDLDestructeur(SDL *sdl){
    int i;
    for(i=0;i<(2+4*_Nombre_de_Joueur+_Nombre_Type_Bonus);i++){
        SDL_FreeSurface(SDLGetIemeTexture(sdl,i));
        SDLSetIemeTexture(sdl,i,NULL);
    }
    JeuDestructeur(SDLGetJeu(sdl));
    for(i=0;i<_Nombre_de_Manette;i++){
        detruireManette(SDLGetIemeManette(sdl,i));
    }
    free(sdl->mesManettes);
    sdl->mesManettes=NULL;
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}



void SDLJeuInitN(SDL *sdl){
    int i;
    short int nbJoueurClavier=_Nombre_de_Joueur-_Nombre_de_Manette;
    Jeu jeu;
    Grid grille;
    TableauDynamique tabDynMurs;
    Controle unControle;
    Moto uneMoto;
    SDL_Surface *ecran;
    Joueur unJoueur;
    Manette uneManette;
    Joueur *mesJoueurs=(Joueur*)malloc(_Nombre_de_Joueur*sizeof(Joueur));
    Manette *mesManettes=(Manette*)malloc(_Nombre_de_Manette*sizeof(Manette));

    SDL_JoystickEventState(SDL_ENABLE);
    assert((_Nombre_de_Joueur<=8)&&(_Nombre_de_Joueur>0)&&(_Nombre_de_Manette<=4)&&(_Nombre_de_Manette>=0)&&
           (nbJoueurClavier<=4)&&(nbJoueurClavier>=0)&&(SDL_NumJoysticks()>=_Nombre_de_Manette)&&
           (_Duree_Vie_Mur>=0)&&(_Acceleration>=0)&&(_Vitesse_Initiale>=0)&&(_Nombre_de_Bonus>=0));

    for(i=0;i<nbJoueurClavier;i++){
        if(_Nombre_de_Joueur<=4){
            if(i==0){
                ControleConstructeur(&unControle,'z','s','q','d','a');
                MotoConstructeur(&uneMoto,498,50,5,10,_Vitesse_Initiale,BAS);
                JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ORANGE,VIVANT,AUCUN,-1);
            }
            else if(i==1){
                    ControleConstructeur(&unControle,'o','l','k','m','i');
                    MotoConstructeur(&uneMoto,503,650,5,10,_Vitesse_Initiale,HAUT);
                    JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLEU,VIVANT,AUCUN,-1);
                }
                else if(i==2){
                        ControleConstructeur(&unControle,SDLK_t,SDLK_g,SDLK_f,SDLK_h,SDLK_r);
                        MotoConstructeur(&uneMoto,200,355,10,5,_Vitesse_Initiale,DROITE);
                        JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ROUGE,VIVANT,AUCUN,-1);
                    }
                    else if(i==3){
                            ControleConstructeur(&unControle,SDLK_UP,SDLK_DOWN,SDLK_LEFT,SDLK_RIGHT,SDLK_END);
                            MotoConstructeur(&uneMoto,800,350,10,5,_Vitesse_Initiale,GAUCHE);
                            JoueurConstructeur(&unJoueur,&uneMoto,&unControle,VERT,VIVANT,AUCUN,-1);
                        }
        }
        else{
            if(i==0){
                ControleConstructeur(&unControle,'z','s','q','d','a');
                MotoConstructeur(&uneMoto,403,50,5,10,_Vitesse_Initiale,BAS);
                JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ORANGE,VIVANT,AUCUN,-1);
            }
            else if(i==1){
                    ControleConstructeur(&unControle,'o','l','k','m','i');
                    MotoConstructeur(&uneMoto,809,253,10,5,_Vitesse_Initiale,GAUCHE);
                    JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLEU,VIVANT,AUCUN,-1);
                }
                else if(i==2){
                        ControleConstructeur(&unControle,SDLK_t,SDLK_g,SDLK_f,SDLK_h,SDLK_r);
                        MotoConstructeur(&uneMoto,603,660,5,10,_Vitesse_Initiale,HAUT);
                        JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ROUGE,VIVANT,AUCUN,-1);
                    }
                    else if(i==3){
                            ControleConstructeur(&unControle,SDLK_UP,SDLK_DOWN,SDLK_LEFT,SDLK_RIGHT,SDLK_END);
                            MotoConstructeur(&uneMoto,200,456,10,5,_Vitesse_Initiale,DROITE);
                            JoueurConstructeur(&unJoueur,&uneMoto,&unControle,VERT,VIVANT,AUCUN,-1);
                        }
        }
        mesJoueurs[i]=unJoueur;
    }
    for(i=nbJoueurClavier;i<_Nombre_de_Joueur;i++){
        if(_Nombre_de_Joueur<=4){
            if(i==0){
                ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                MotoConstructeur(&uneMoto,498,50,5,10,_Vitesse_Initiale,BAS);
                initialiserManette(&uneManette,i-nbJoueurClavier);
                JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ORANGE,VIVANT,AUCUN,i-nbJoueurClavier);
            }
            else if(i==1){
                    ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                    MotoConstructeur(&uneMoto,503,650,5,10,_Vitesse_Initiale,HAUT);
                    initialiserManette(&uneManette,i-nbJoueurClavier);
                    JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLEU,VIVANT,AUCUN,i-nbJoueurClavier);
                }
                else if(i==2){
                        ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                        MotoConstructeur(&uneMoto,200,355,10,5,_Vitesse_Initiale,DROITE);
                        initialiserManette(&uneManette,i-nbJoueurClavier);
                        JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ROUGE,VIVANT,AUCUN,i-nbJoueurClavier);
                    }
                    else if(i==3){
                            ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                            MotoConstructeur(&uneMoto,800,350,10,5,_Vitesse_Initiale,GAUCHE);
                            initialiserManette(&uneManette,i-nbJoueurClavier);
                            JoueurConstructeur(&unJoueur,&uneMoto,&unControle,VERT,VIVANT,AUCUN,i-nbJoueurClavier);
                        }
        }
        else {
            if(i==1){
                ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                MotoConstructeur(&uneMoto,809,253,10,5,_Vitesse_Initiale,GAUCHE);
                initialiserManette(&uneManette,i-nbJoueurClavier);
                JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLEU,VIVANT,AUCUN,i-nbJoueurClavier);
            }
            else if(i==2){
                    ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                    MotoConstructeur(&uneMoto,603,660,5,10,_Vitesse_Initiale,HAUT);
                    initialiserManette(&uneManette,i-nbJoueurClavier);
                    JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ROUGE,VIVANT,AUCUN,i-nbJoueurClavier);
                }
                else if(i==3){
                        ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                        MotoConstructeur(&uneMoto,200,456,10,5,_Vitesse_Initiale,DROITE);
                        initialiserManette(&uneManette,i-nbJoueurClavier);
                        JoueurConstructeur(&unJoueur,&uneMoto,&unControle,VERT,VIVANT,AUCUN,i-nbJoueurClavier);
                    }
                    else if(i==4){
                            ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                            MotoConstructeur(&uneMoto,606,50,5,10,_Vitesse_Initiale,BAS);
                            initialiserManette(&uneManette,i-nbJoueurClavier);
                            JoueurConstructeur(&unJoueur,&uneMoto,&unControle,VIOLET,VIVANT,AUCUN,i-nbJoueurClavier);
                        }
                        else if(i==5){
                                ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                                MotoConstructeur(&uneMoto,403,660,5,10,_Vitesse_Initiale,HAUT);
                                initialiserManette(&uneManette,i-nbJoueurClavier);
                                JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLEUF,VIVANT,AUCUN,i-nbJoueurClavier);
                            }
                            else if(i==6){
                                    ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                                    MotoConstructeur(&uneMoto,200,253,10,5,_Vitesse_Initiale,DROITE);
                                    initialiserManette(&uneManette,i-nbJoueurClavier);
                                    JoueurConstructeur(&unJoueur,&uneMoto,&unControle,JAUNE,VIVANT,AUCUN,i-nbJoueurClavier);
                                }
                                else if(i==7){
                                        ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                                        MotoConstructeur(&uneMoto,809,456,10,5,_Vitesse_Initiale,GAUCHE);
                                        initialiserManette(&uneManette,i-nbJoueurClavier);
                                        JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLANC,VIVANT,AUCUN,i-nbJoueurClavier);
                                    }
        }
        mesManettes[i-nbJoueurClavier]=uneManette;
        mesJoueurs[i]=unJoueur;
    }

    GridConstructeur(&grille,5,5,1000,700,&tabDynMurs);
    JeuConstructeur(&jeu,&grille,mesJoueurs);

    SDL_WM_SetCaption( "TRON-The Grid v0.1", NULL );
    SDLConstructeur(sdl,&jeu,mesManettes);
    ecran=SDLGetIemeTexture(sdl,0);
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDLSetIemeTexture(sdl,0,ecran);
}



/** Boucle principale du Jeu */
void SDLBoucleJeu(SDL* sdl, short int *jeuReInit){
    short int jeuFini = 0;
    int i;
    SDL_Event evenement;
    float horloge_courante, horloge_precedente;
    float intervalle_horloge=0.05f;
    int affAJour;
    Controle* unControle;
    Manette* uneManette;
    int nbJoueurClavier=_Nombre_de_Joueur-_Nombre_de_Manette;


    SDLAfficheJeu(sdl);
    assert(SDL_Flip(SDLGetIemeTexture(sdl,0)) != -1);
    horloge_precedente = (float)clock()/(float) CLOCKS_PER_SEC;

    while(!jeuFini){
        affAJour = 1;
        horloge_courante = (float)clock()/(float) CLOCKS_PER_SEC;
        if(horloge_courante-horloge_precedente >= intervalle_horloge){
            JeuEvolue(SDLGetJeu(sdl),&jeuFini);
            affAJour = 0;
            horloge_precedente = horloge_courante;
        }
        while ( SDL_PollEvent( &evenement ) ){
            if ( evenement.type == SDL_QUIT ){
				affAJour = 0;
            }
            if (evenement.type == SDL_KEYDOWN){
                for(i=0;(i<nbJoueurClavier);i++){
                    if(JoueurGetEnJeu(JeuGetIemeJoueurs(SDLGetJeu(sdl),i))==1){
                        unControle=JoueurGetControle(JeuGetIemeJoueurs(SDLGetJeu(sdl),i));
                        if(evenement.key.keysym.sym==ControleGetHaut(unControle)){
                            JeuActionClavier(JeuGetIemeJoueurs(SDLGetJeu(sdl),i),
                                                ControleGetHaut(unControle),JeuGetGrille(SDLGetJeu(sdl)));
                            affAJour = 0;
                        }
                        else  if(evenement.key.keysym.sym==ControleGetBas(unControle)){
                                JeuActionClavier( JeuGetIemeJoueurs(SDLGetJeu(sdl),i),
                                                ControleGetBas(unControle),JeuGetGrille(SDLGetJeu(sdl)));
                                affAJour = 0;
                            }
                            else if(evenement.key.keysym.sym==ControleGetGauche(unControle)){
                                    JeuActionClavier( JeuGetIemeJoueurs(SDLGetJeu(sdl),i),
                                                        ControleGetGauche(unControle),JeuGetGrille(SDLGetJeu(sdl)));
                                    affAJour = 0;
                                    }
                                    else if(evenement.key.keysym.sym==ControleGetDroite(unControle)){
                                            JeuActionClavier( JeuGetIemeJoueurs(SDLGetJeu(sdl),i),
                                                             ControleGetDroite(unControle),JeuGetGrille(SDLGetJeu(sdl)));
                                            affAJour = 0;
                                        }
                                        else if(evenement.key.keysym.sym==ControleGetBonus(unControle)){
                                                JeuActionneBonus(JeuGetIemeJoueurs(SDLGetJeu(sdl),i));
                                                affAJour=0;
                                        }
                    }
                }

            }

            for(i=0;i<_Nombre_de_Manette;i++){
                uneManette=SDLGetIemeManette(sdl,i);
                updateEvent(uneManette,evenement);
                if(uneManette->boutons[3]){
                    SDLActionManette(JeuGetIemeJoueurs(SDLGetJeu(sdl),nbJoueurClavier+i),HAUT,JeuGetGrille(SDLGetJeu(sdl)));
                    uneManette->boutons[3]=0;
                    affAJour = 0;
                }
                if(uneManette->boutons[0]){
                    SDLActionManette(JeuGetIemeJoueurs(SDLGetJeu(sdl),nbJoueurClavier+i),BAS,JeuGetGrille(SDLGetJeu(sdl)));
                    uneManette->boutons[0]=0;
                    affAJour = 0;
                }
                if((uneManette->boutons[2])){
                    SDLActionManette(JeuGetIemeJoueurs(SDLGetJeu(sdl),nbJoueurClavier+i),GAUCHE,JeuGetGrille(SDLGetJeu(sdl)));
                    uneManette->boutons[2]=0;
                    affAJour = 0;
                }
                if(uneManette->boutons[1]){
                    SDLActionManette(JeuGetIemeJoueurs(SDLGetJeu(sdl),nbJoueurClavier+i),DROITE,JeuGetGrille(SDLGetJeu(sdl)));
                    uneManette->boutons[1]=0;
                    affAJour = 0;
                }
                if(uneManette->boutons[6]){
                    JeuActionneBonus(JeuGetIemeJoueurs(SDLGetJeu(sdl),nbJoueurClavier+i));
                    uneManette->boutons[6]=0;
                    affAJour = 0;
                }
            }
        }
        if(!affAJour){
            SDLAfficheJeu(sdl);
        }
    }
    printf("Partie terminée ! \n Appuyez sur échap pour quitter ou sur F1 pour rejouer. \n");
    while((evenement.key.keysym.sym!=SDLK_ESCAPE)&&(evenement.key.keysym.sym!=SDLK_F1)){
        SDL_WaitEvent(&evenement);
    }
    if(evenement.key.keysym.sym==SDLK_ESCAPE){
        *jeuReInit=0;
    }
    if(evenement.key.keysym.sym==SDLK_F1){
        *jeuReInit=1;
    }
}

void SDLActionManette(Joueur* joueur, Direction direction,Grid* grille){
    Moto* uneMoto=JoueurGetMoto(joueur);
    unsigned int tailleTemp=MotoGetTailleX(uneMoto);
    Mur unMur;
    float dureeVieMur=_Duree_Vie_Mur;
    char directionChange=0;
    if(JoueurGetEnJeu(joueur)!=VIVANT){
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
        if(directionChange){
            MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
            MotoSetTailleY(uneMoto,tailleTemp);
            ajouteMur(GridGetMesMurs(grille),unMur);
        }
    }
}

void SDLAfficheMotos(SDL* sdl){
    Moto *moto;
    SDL_Surface * surfaceMoto;
    int i;
    for(i=0;(i<_Nombre_de_Joueur);i++){
            if(JoueurGetEnJeu(JeuGetIemeJoueurs(SDLGetJeu(sdl),i))==VIVANT){
                moto=JoueurGetMoto(JeuGetIemeJoueurs(SDLGetJeu(sdl),i));
                if(MotoGetDirection(moto)==HAUT){
                    surfaceMoto=SDLGetIemeTexture(sdl,2+(i*4));
                }
                else if(MotoGetDirection(moto)==BAS){
                        surfaceMoto=SDLGetIemeTexture(sdl,2+(i*4)+1);
                    }
                    else if(MotoGetDirection(moto)==GAUCHE){
                            surfaceMoto=SDLGetIemeTexture(sdl,2+(i*4)+2);
                        }
                        else if(MotoGetDirection(moto)==DROITE){
                                surfaceMoto=SDLGetIemeTexture(sdl,2+(i*4)+3);
                            }

                SDLAppliqueSurface(surfaceMoto,SDLGetIemeTexture(sdl,0),MotoGetPositionX(moto),MotoGetPositionY(moto));
            }
        }

}
void SDLAfficheMurs(SDL *sdl){
    SDL_Surface * surfaceMur;
    Mur* mur;
    int i;
    SDLAppliqueSurface(SDLGetIemeTexture(sdl,1),SDLGetIemeTexture(sdl,0),GridGetPositionX(JeuGetGrille(SDLGetJeu(sdl))),GridGetPositionY(JeuGetGrille(SDLGetJeu(sdl))));
    for(i=0;i<TabDynGetTaille_utilisee(GridGetMesMurs(JeuGetGrille(SDLGetJeu(sdl))));i++){
        mur= adresseIemeElementTabDyn(GridGetMesMurs(JeuGetGrille(SDLGetJeu(sdl))),i);
        surfaceMur=SDL_CreateRGBSurface(SDL_HWSURFACE,MurGetTailleX(mur),MurGetTailleY(mur),32,0,0,0,0);
        if(MurGetCouleur(mur)==ORANGE){
            SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,255,204,51));
        }
        else if(MurGetCouleur(mur)==BLEU){
            SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,51,204,255));
            }
            else if(MurGetCouleur(mur)==ROUGE){
            SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,232,33,5));
            }
                else if(MurGetCouleur(mur)==VERT){
                SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,33,198,33));
                }
                    else if(MurGetCouleur(mur)==VIOLET){
                    SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,204,51,255));
                    }
                        else if(MurGetCouleur(mur)==BLEUF){
                        SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,13,24,179));
                        }
                            else if(MurGetCouleur(mur)==JAUNE){
                            SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,231,239,11));
                            }
                                else if(MurGetCouleur(mur)==BLANC){
                                SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,255,255,255));
                                }
        SDLAppliqueSurface(surfaceMur,SDLGetIemeTexture(sdl,0),(int)(MurGetPositionX(mur)/1),(int)(MurGetPositionY(mur)/1));
        SDL_FreeSurface(surfaceMur);
    }
}
void SDLAfficheBonus(SDL*sdl){
    int i;
    Bonus *unBonus;
    for(i=0;i<_Nombre_de_Bonus;i++){
        unBonus=JeuGetIemeBonus(SDLGetJeu(sdl),i);
        if(BonusGetEffetBonus(unBonus)==NETTOYAGE){
             SDLAppliqueSurface(SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4),SDLGetIemeTexture(sdl,0),
                                BonusGetPositionX(unBonus),BonusGetPositionY(unBonus));
        }
        if(BonusGetEffetBonus(unBonus)==BOOST){
            SDLAppliqueSurface(SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+1),SDLGetIemeTexture(sdl,0),
                                BonusGetPositionX(unBonus),BonusGetPositionY(unBonus));
        }
    }
}

void SDLAfficheJeu(SDL *sdl){
    SDLAfficheMurs(sdl);
    SDLAfficheMotos(sdl);
    SDLAfficheBonus(sdl);
    SDL_Flip(SDLGetIemeTexture(sdl,0));

}



void SDLTestRegression(){
    /*SDL sdl;
    SDLJeuInit2(&sdl);
    SDLAfficheJeu(&sdl);
    bougeMoto(SDLGetJeu(&sdl));
    SDLDestructeur(&sdl);
    printf("pointeur de l'image chargée après kdestruction : %p   %p \n",SDLGetIemeTexture(&sdl,5),SDLGetIemeTexture(&sdl,7));*/
}

