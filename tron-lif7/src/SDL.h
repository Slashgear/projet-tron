#ifndef SDL_H_INCLUDED
#define SDL_H_INCLUDED
#include "Jeu.h"
#include <SDL/SDL.h>

/**
*\file [SDL.h]
*\brief Module des vecteurs
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 19 mars 2013
*/

typedef struct{
    Jeu *jeu;
    SDL_Surface * textures[9];
}SDL;
/** La 0ieme texture est le fond, les textures 1 à 4 sont celles du joueur 1, les quatre suivantes celles du joueur 2, etc..*/

/**assesseur de jeu*/
Jeu * SDLGetJeu(const SDL* sdl);
/** assesseur de ieme texture*/
SDL_Surface * SDLGetIemeTexture(const SDL* sdl,unsigned int i);
/** assesseur de textures*/
SDL_Surface * SDLGetTextures(const SDL* sdl);


/**mutateur de jeu*/
void SDLSetJeu(SDL * sdl,Jeu* jeu);
/**mutateur de ieme texture*/
void SDLSetIemeTexture(SDL *sdl,unsigned int i,SDL_Surface * texture);


/** Pocédure qui teste le Module*/
void SDLTestRegression();

#endif /* SDL_H_INCLUDED */
