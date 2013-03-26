#include "Jeu.h"
#include "SDL.h"
#include <assert.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

Jeu* SDLGetJeu(const SDL* sdl){
    return sdl->jeu;
}
SDL_Surface * SDLGetIemeTexture(const SDL* sdl,unsigned int i){
    return sdl->textures[i];
}
SDL_Surface * SDLGetTextures(const SDL* sdl){
    return sdl->textures[0];
}

void SDLSetJeu(SDL * sdl,Jeu* jeu){
    sdl->jeu=jeu;
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

void SDLAppliqueSurface(SDL_Surface * surfaceA, SDL_Surface * surfaceB,const float positionX,const float positionY){
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
    SDLSetIemeTexture(sdl,0,SDL_SetVideoMode(1005,1005,32,SDL_HWSURFACE));
    SDLSetIemeTexture(sdl,1,SDLChargeImage("data/grid.bmp"));
    SDLSetIemeTexture(sdl,2,SDLChargeImage("data/moto1H.bmp"));
    SDLSetIemeTexture(sdl,3,SDLChargeImage("data/moto1B.bmp"));
    SDLSetIemeTexture(sdl,4,SDLChargeImage("data/moto1G.bmp"));
    SDLSetIemeTexture(sdl,5,SDLChargeImage("data/moto1D.bmp"));
    SDLSetIemeTexture(sdl,6,SDLChargeImage("data/moto2H.bmp"));
    SDLSetIemeTexture(sdl,7,SDLChargeImage("data/moto2B.bmp"));
    SDLSetIemeTexture(sdl,8,SDLChargeImage("data/moto2G.bmp"));
    SDLSetIemeTexture(sdl,9,SDLChargeImage("data/moto2D.bmp"));

}

void SDLDestructeur(SDL *sdl){
    int i;
    for(i=0;i<10;i++){
        SDL_FreeSurface(SDLGetIemeTexture(sdl,i));
        SDLSetIemeTexture(sdl,i,NULL);
    }
    JeuDestructeur(SDLGetJeu(sdl));
    SDLSetJeu(sdl,NULL);
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
void SDLJeuInit(SDL *sdl){
    Jeu jeu;
    Grid grille;
    Joueur joueur1;
    Joueur joueur2;
    Moto moto1;
    Moto moto2;
    Controle controle1;
    Controle controle2;
    TableauDynamique tabDynMurs;
    Joueur mesJoueurs[2]={joueur1,joueur2};
    SDL_Surface* ecran;

    assert(   SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO |SDL_INIT_TIMER)!= -1 );
    JeuConstructeur(&jeu,&grille,(Joueur*)&mesJoueurs);
    GridConstructeur(&grille,5,5,1000,1000,&tabDynMurs);
    JoueurConstructeur(&joueur1,&moto1,&controle1,ORANGE);
    MotoConstructeur(&moto1,333,500,5,10,1,HAUT);
    ControleConstructeur(&controle1,'z','s','q','d');
    JoueurConstructeur(&joueur2,&moto2,&controle2,BLEU);
    ControleConstructeur(&controle1,'o','l','k','m');
    MotoConstructeur(&moto2,500,500,5,10,1,BAS);
    SDL_WM_SetCaption( "TRON-The Grid v0.1", NULL );

    SDLConstructeur(sdl,&jeu);
    ecran=SDLGetIemeTexture(sdl,0);
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
    SDLAfficheJeu(sdl);
    SDL_Flip(ecran);

    pause();

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
        SDLAppliqueSurface(surfaceMur,SDLGetIemeTexture(sdl,0),MurGetPositionX(mur),MurGetPositionY(mur));
    }
    for(i=0;i<2;i++){
        moto=JoueurGetMoto((Joueur*)&(JeuGetMesJoueurs(SDLGetJeu(sdl))[i]));
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

void SDLTestRegression(){
    SDL sdl;
    SDLJeuInit(&sdl);
  /*  bougeMoto(SDLGetJeu(&sdl));
    bougeMoto(SDLGetJeu(&sdl));
    bougeMoto(SDLGetJeu(&sdl));
    SDLAfficheJeu(&sdl);
    SDL_Flip(ecran);
    SDLConstructeur(&sdl,&jeu);
    printf("pointeur de l'image chargée : %p %p \n",SDLGetIemeTexture(&sdl,5),SDLGetIemeTexture(&sdl,7));
    SDLDestructeur(&sdl);
    printf("pointeur de l'image chargée après destruction : %p %p \n",SDLGetIemeTexture(&sdl,5),SDLGetIemeTexture(&sdl,7));
    atexit(MurTestRegression());*/
    SDL_Quit();
}

