#include "Jeu.h"
#include "SDL.h"
#include <assert.h>
#include <SDL/SDL.h>

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

	/* The optimized image that will be used */
	SDL_Surface* optimizedImage = NULL;

	/* Load the image */
	loadedImage = SDL_LoadBMP( nomfichier );

	/* If nothing went wrong in loading the image */
	if ( loadedImage != NULL )
	{
		/* Create an optimized image */
		optimizedImage = SDL_DisplayFormat( loadedImage );

		/* Free the old image */
		SDL_FreeSurface( loadedImage );

	}
    else printf("image non chargée ! \n");


	/* Return the optimized image */
	return optimizedImage;
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
    SDLSetIemeTexture(sdl,0,SDLChargeImage("/data/fond.bmp"));
    SDLSetIemeTexture(sdl,1,SDLChargeImage("/data/moto1H.bmp"));
    SDLSetIemeTexture(sdl,2,SDLChargeImage("/data/moto1B.bmp"));
    SDLSetIemeTexture(sdl,3,SDLChargeImage("/data/moto1G.bmp"));
    SDLSetIemeTexture(sdl,4,SDLChargeImage("/data/moto1D.bmp"));
    SDLSetIemeTexture(sdl,5,SDLChargeImage("/data/moto2H.bmp"));
    SDLSetIemeTexture(sdl,6,SDLChargeImage("/data/moto2B.bmp"));
    SDLSetIemeTexture(sdl,7,SDLChargeImage("/data/moto2G.bmp"));
    SDLSetIemeTexture(sdl,8,SDLChargeImage("/data/moto2D.bmp"));

}

void SDLTestRegression(){
    assert(   SDL_Init( SDL_INIT_EVERYTHING )!= -1 );
    SDL sdl;
    SDL_Surface* uneSurface = SDLChargeImage("data/fond.bmp");
    SDLSetIemeTexture(&sdl,0,uneSurface);
    printf("pointeur de l'image chargée : %p %p \n",SDLGetIemeTexture(&sdl,0),uneSurface);
    SDL_Quit();
}

