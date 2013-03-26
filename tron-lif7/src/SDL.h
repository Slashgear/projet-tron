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
    SDL_Surface * fond;
    SDL_Surface * moto1H;
    SDL_Surface * moto1B;
    SDL_Surface * moto1G;
    SDL_Surface * moto1D;
    SDL_Surface * moto2H;
    SDL_Surface * moto2B;
    SDL_Surface * moto2G;
    SDL_Surface * moto2D;
}SDL;

/**assesseur de jeu*/
Jeu * SDLGetJeu(const SDL* sdl);
/** assesseur de fond*/
SDL_Surface * SDLGetFond(const SDL* sdl);
/** assesseur de moto1H*/
SDL_Surface * SDLGetMoto1H(const SDL* sdl);
/** assesseur de moto1B*/
SDL_Surface * SDLGetMoto1B(const SDL* sdl);
/**assesseur de moto1G*/
SDL_Surface * SDLGetMoto1G(const SDL* sdl);
/**assesseur de moto1D*/
SDL_Surface * SDLGetMoto1D(const SDL* sdl);
/** assesseur de moto2H*/
SDL_Surface * SDLGetMoto2H(const SDL* sdl);
/** assesseur de moto2B*/
SDL_Surface * SDLGetMoto2B(const SDL* sdl);
/**assesseur de moto2G*/
SDL_Surface * SDLGetMoto2G(const SDL* sdl);
/**assesseur de moto2D*/
SDL_Surface * SDLGetMoto2D(const SDL* sdl);

/**mutateur de jeu*/
void SDLSetJeu(SDL * sdl,Jeu* jeu);
/**mutateur de fond*/
void SDLSetFond(SDL* sdl,SDL_Surface * fond);
/**mutateur de moto1H*/
void SDLSetMoto1H(SDL* sdl,SDL_Surface * moto);
/**mutateur de moto1B*/
void SDLSetMoto1B(SDL* sdl,SDL_Surface * moto);
/**mutateur de moto1G*/
void SDLSetMoto1G(SDL* sdl,SDL_Surface * moto);
/**mutateur de moto1D*/
void SDLSetMoto1D(SDL* sdl,SDL_Surface * moto);
/**mutateur de moto2H*/
void SDLSetMoto2H(SDL* sdl,SDL_Surface * moto);
/**mutateur de moto2B*/
void SDLSetMoto2B(SDL* sdl,SDL_Surface * moto);
/**mutateur de moto2G*/
void SDLSetMoto2G(SDL* sdl,SDL_Surface * moto);
/**mutateur de moto1D*/
void SDLSetMoto2D(SDL* sdl,SDL_Surface * moto);

/** Constructeur de SDL, initialise les différents champs*/
void SDLConstructeur(SDL *sdl,Jeu* jeu);
/**Destructeur de SDl,remise à zero des champs de SDL et free des allocations*/
void SDLDestructeur(SDL *sdl);
/** Procédure d'affichage du jeu*/
void SDLAfficheJeu(SDL *sdl);
/**Procédure d'affichage de la grille*/
void SDLAfficheGrid(SDL *sdl);
/** Boucle d'affichage du Jeu */
void SDLBoucleJeu(SDL* sdl);
/** Procédure de chargement des images*/
SDL_Surface* SDLChargeImage(const char *nomfichier);
/**Procédure qui applique la surface A sur la B*/
void SDLAppliqueSurface(SDL_Surface * surfaceA, SDL_Surface * surfaceB,const float positionX,const float positionY);

/** Pocédure qui teste le Module*/
void SDLTestRegression(SDL* sdl);

#endif /* SDL_H_INCLUDED */
