#include "Jeu.h"
#include "SDL.h"
#include <assert.h>
#include <SDL/SDL.h>
#include <time.h>

Jeu* SDLGetJeu(SDL* sdl){
    return &(sdl->jeu);
}
SDL_Surface * SDLGetIemeTexture(const SDL* sdl,unsigned int i){
    return sdl->textures[i];
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
	if ( loadedImage == NULL ) printf("image non chargée ! \n");


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



void SDLConstructeur(SDL *sdl,Jeu* jeu){
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
}

void SDLDestructeur(SDL *sdl){
    int i;
    for(i=0;i<(2+4*_Nombre_de_Joueur);i++){
        SDL_FreeSurface(SDLGetIemeTexture(sdl,i));
        SDLSetIemeTexture(sdl,i,NULL);
    }
    JeuDestructeur(SDLGetJeu(sdl));
    SDL_Quit();
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

void SDLJeuInit4(SDL *sdl){
    Jeu jeu;
    Grid grille;
    Joueur joueur1;
    Joueur joueur2;
    Joueur joueur3;
    Joueur joueur4;
    Moto moto1;
    Moto moto2;
    Moto moto3;
    Moto moto4;
    Controle controle1;
    Controle controle2;
    Controle controle3;
    Controle controle4;
    TableauDynamique tabDynMurs;
    Joueur* mesJoueurs[4]={&joueur1,&joueur2,&joueur3,&joueur4};
    SDL_Surface* ecran;

    assert(   SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO )!= -1 );
    ControleConstructeur(&controle1,'z','s','q','d','a');
    MotoConstructeur(&moto1,498,50,5,10,_Vitesse_Initiale,BAS);
    JoueurConstructeur(&joueur1,&moto1,&controle1,ORANGE,1,AUCUN);

    ControleConstructeur(&controle2,'o','l','k','m','i');
    MotoConstructeur(&moto2,503,650,5,10,_Vitesse_Initiale,HAUT);
    JoueurConstructeur(&joueur2,&moto2,&controle2,BLEU,1,AUCUN);

    ControleConstructeur(&controle3,SDLK_UP,SDLK_DOWN,SDLK_LEFT,SDLK_RIGHT,SDLK_END);
    MotoConstructeur(&moto3,200,355,10,5,_Vitesse_Initiale,DROITE);
    JoueurConstructeur(&joueur3,&moto3,&controle3,ROUGE,1,AUCUN);

    ControleConstructeur(&controle4,SDLK_t,SDLK_g,SDLK_f,SDLK_h,SDLK_r);
    MotoConstructeur(&moto4,800,350,10,5,_Vitesse_Initiale,GAUCHE);
    JoueurConstructeur(&joueur4,&moto4,&controle4,VERT,1,AUCUN);

    GridConstructeur(&grille,5,5,1000,700,&tabDynMurs);

    JeuConstructeur(&jeu,&grille,mesJoueurs);

    SDL_WM_SetCaption( "TRON-The Grid v0.1", NULL );

    SDLConstructeur(sdl,&jeu);
    ecran=SDLGetIemeTexture(sdl,0);
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDLSetIemeTexture(sdl,0,ecran);
}



void SDLJeuInit2(SDL *sdl){
    Jeu jeu;
    Grid grille;
    Joueur joueur1;
    Joueur joueur2;
    Moto moto1;
    Moto moto2;
    Controle controle1;
    Controle controle2;
    TableauDynamique tabDynMurs;
    Joueur* mesJoueurs[2]={&joueur1,&joueur2};
    SDL_Surface* ecran;

    assert(   SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO )!= -1 );
    ControleConstructeur(&controle1,'z','s','q','d','a');
    MotoConstructeur(&moto1,498,50,5,10,_Vitesse_Initiale,BAS);
    JoueurConstructeur(&joueur1,&moto1,&controle1,ORANGE,1,AUCUN);

    ControleConstructeur(&controle2,'o','l','k','m','i');
    MotoConstructeur(&moto2,503,650,5,10,_Vitesse_Initiale,HAUT);
    JoueurConstructeur(&joueur2,&moto2,&controle2,BLEU,1,AUCUN);

    GridConstructeur(&grille,5,5,1000,700,&tabDynMurs);

    JeuConstructeur(&jeu,&grille,mesJoueurs);

    SDL_WM_SetCaption( "TRON-The Grid v1.1", NULL );

    SDLConstructeur(sdl,&jeu);
    ecran=SDLGetIemeTexture(sdl,0);
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDLSetIemeTexture(sdl,0,ecran);
}

/** Boucle principale du Jeu */
void SDLBoucleJeu(SDL* sdl){
    short int jeuFini = 0;
    int i;
    SDL_Event evenement;
    float horloge_courante, horloge_precedente;
    float intervalle_horloge=0.05f;
    int affAJour;
    Controle* unControle;

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
                for(i=0;(i<_Nombre_de_Joueur);i++){
                    if(JoueurGetEnJeu(JeuGetIemeJoueurs(SDLGetJeu(sdl),i))==1){
                        unControle=JoueurGetControle(JeuGetIemeJoueurs(SDLGetJeu(sdl),i));
                        if(evenement.key.keysym.sym==ControleGetHaut(unControle)){
                            JeuActionClavier(JeuGetIemeJoueurs(SDLGetJeu(sdl),i),
                                                ControleGetHaut(unControle),JeuGetGrille(SDLGetJeu(sdl)));
                            affAJour = 1;
                        }
                        else  if(evenement.key.keysym.sym==ControleGetBas(unControle)){
                                JeuActionClavier( JeuGetIemeJoueurs(SDLGetJeu(sdl),i),
                                                ControleGetBas(unControle),JeuGetGrille(SDLGetJeu(sdl)));
                                affAJour = 1;
                            }
                            else if(evenement.key.keysym.sym==ControleGetGauche(unControle)){
                                    JeuActionClavier( JeuGetIemeJoueurs(SDLGetJeu(sdl),i),
                                                        ControleGetGauche(unControle),JeuGetGrille(SDLGetJeu(sdl)));
                                    affAJour = 1;
                                    }
                                    else if(evenement.key.keysym.sym==ControleGetDroite(unControle)){
                                            JeuActionClavier( JeuGetIemeJoueurs(SDLGetJeu(sdl),i),
                                                             ControleGetDroite(unControle),JeuGetGrille(SDLGetJeu(sdl)));
                                            affAJour = 1;
                                        }
                    }
				}

            }
        }
        if(!affAJour){
            SDLAfficheJeu(sdl);
        }
    }
}

void SDLAfficheJeu(SDL *sdl){
    SDL_Surface * surfaceMur;
    SDL_Surface * surfaceMoto;
    Mur* mur;
    Moto* moto;
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
        SDLAppliqueSurface(surfaceMur,SDLGetIemeTexture(sdl,0),(int)(MurGetPositionX(mur)/1),(int)(MurGetPositionY(mur)/1));
        SDL_FreeSurface(surfaceMur);
    }
    for(i=0;(i<_Nombre_de_Joueur);i++){
        if(JoueurGetEnJeu(JeuGetIemeJoueurs(SDLGetJeu(sdl),i))==1){
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

    SDL_Flip(SDLGetIemeTexture(sdl,0));

}

void SDLTestRegression(){
    SDL sdl;
    SDLJeuInit2(&sdl);
    SDLAfficheJeu(&sdl);
    bougeMoto(SDLGetJeu(&sdl));
    SDLDestructeur(&sdl);
    printf("pointeur de l'image chargée après kdestruction : %p   %p \n",SDLGetIemeTexture(&sdl,5),SDLGetIemeTexture(&sdl,7));
}

