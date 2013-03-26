#include "Jeu.h"
#include "SDL.h"
#include <SDL/SDL.h>

Jeu* SDLGetJeu(const SDL* sdl){
    return sdl->jeu;
}
SDL_Surface * SDLGetFond(const SDL* sdl){
    return sdl->fond;
}
SDL_Surface * SDLGetMoto1H(const SDL* sdl){
    return sdl->moto1H;
}
SDL_Surface * SDLGetMoto1B(const SDL* sdl){
    return sdl->moto1B;
}
SDL_Surface * SDLGetMoto1G(const SDL* sdl){
    return sdl->moto1G;
}
SDL_Surface * SDLGetMoto1D(const SDL* sdl){
    return sdl->moto1D;
}
SDL_Surface * SDLGetMoto2H(const SDL* sdl){
    return sdl->moto2H;
}
SDL_Surface * SDLGetMoto2B(const SDL* sdl){
    return sdl->moto2B;
}
SDL_Surface * SDLGetMoto2G(const SDL* sdl){
    return sdl->moto2G;
}
SDL_Surface * SDLGetMoto2D(const SDL* sdl){
    return sdl->moto2D;
}


void SDLSetJeu(SDL * sdl,Jeu* jeu){
    sdl->jeu=jeu;
}
void SDLSetMotoFond(SDL* sdl,SDL_Surface * fond){
    sdl->fond=fond;
}
void SDLSetMoto1H(SDL* sdl,SDL_Surface * moto){
    sdl->moto1H=moto;
}
void SDLSetMoto1B(SDL* sdl,SDL_Surface * moto){
    sdl->moto1B=moto;
}
void SDLSetMoto1G(SDL* sdl,SDL_Surface * moto){
    sdl->moto1G=moto;
}
void SDLSetMoto1D(SDL* sdl,SDL_Surface * moto){
    sdl->moto1D=moto;
}
void SDLSetMoto2H(SDL* sdl,SDL_Surface * moto){
    sdl->moto2H=moto;
}
void SDLSetMoto2B(SDL* sdl,SDL_Surface * moto){
    sdl->moto2B=moto;
}
void SDLSetMoto2G(SDL* sdl,SDL_Surface * moto){
    sdl->moto2G=moto;
}
void SDLSetMoto2D(SDL* sdl,SDL_Surface * moto){
    sdl->moto2D=moto;
}
/*
void SDLConstructeur(SDL *sdl, const Jeu* jeu){

}
*/
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
       /*SDLSetFond(sdl,fond);
       SDLChargeImage();*/
}


