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
    SDL_Surface * textures[10];
}SDL;
/** La texture 0 est le fond, la texture 1 est la grille, les textures 2 à 5 sont celles du joueur 1, les quatre suivantes celles du joueur 2, etc..*/

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



/** Constructeur de SDL, initialise les différents champs*/
void SDLConstructeur(SDL *sdl,Jeu* jeu);
/**Destructeur de SDl,remise à zero des champs de SDL et free des allocations*/
void SDLDestructeur(SDL *sdl);
/**Procédure qui applique la surface A sur la B*/
void SDLAppliqueSurface(SDL_Surface * surfaceA, SDL_Surface * surfaceB,const float positionX,const float positionY);
/** Procédure d'affichage du jeu*/
void SDLAfficheJeu(SDL *sdl);
/**Procédure Init*/
void SDLJeuInit(SDL *sdl);
/**Procédure d'affichage de la grille*/
void SDLAfficheGrid(SDL *sdl);
/** Boucle d'affichage du Jeu */
void SDLBoucleJeu(SDL* sdl);
/** Procédure de chargement des images*/
SDL_Surface* SDLChargeImage(const char *nomfichier);


/** Pocédure qui teste le Module*/
void SDLTestRegression();

#endif /* SDL_H_INCLUDED */
