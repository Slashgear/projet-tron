#ifndef SDL_H_INCLUDED
#define SDL_H_INCLUDED
#include "Jeu.h"
#include <SDL/SDL.h>
#include "Joystick.h"

/**
*\file [SDL.h]
*\brief Module des vecteurs
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 19 mars 2013
*/

typedef struct{
    Jeu jeu;
    SDL_Surface * textures[2+4*_Nombre_de_Joueur];
    Manette* manettes;
}SDL;
/** La texture 0 est le fond(ecran), la texture 1 est la grille, les textures 2 à 5 sont celles du joueur 1, les quatre suivantes celles du joueur 2, etc..*/

/**assesseur de jeu*/
Jeu * SDLGetJeu(SDL* sdl);
/** assesseur de ieme texture*/
SDL_Surface * SDLGetIemeTexture(const SDL* sdl,unsigned int i);
/** assesseur de textures*/
SDL_Surface * SDLGetTextures(const SDL* sdl);


/**mutateur de jeu*/
void SDLSetJeu(SDL * sdl,Jeu* jeu);
/**mutateur de ieme texture*/
void SDLSetIemeTexture(SDL *sdl,unsigned int i,SDL_Surface * texture);

/**Procedure qui met le jeu en pause jusqu'à ce qu'on quitte le jeu */
void pause();
/** Constructeur de SDL, initialise les différents champs*/
void SDLConstructeur(SDL *sdl,Jeu* jeu);
/**Destructeur de SDl,remise à zero des champs de SDL et free des allocations*/
void SDLDestructeur(SDL *sdl);
/**Procédure qui applique la surface A sur la B*/
void SDLAppliqueSurface(SDL_Surface * surfaceA, SDL_Surface * surfaceB,int positionX,int positionY);
/** Procédure d'affichage du jeu*/
void SDLAfficheJeu(SDL *sdl);
/**Procédure d'affichage des motos*/
void SDLAfficheMotos(SDL *sdl);
/**Procédure d'affichage des Murs*/
void SDLAfficheMurs(SDL *sdl);
/**Procédure Init à 2 joueurs*/
void SDLJeuInit2(SDL *sdl);
/**Procédure Init à 4 joueurs*/
void SDLJeuInit4(SDL *sdl);
/**Procédure Init à N=_Nombre_De_Joueur joueurs*/
void SDLJeuInitN(SDL *sdl);
/** Boucle principale du Jeu */
void SDLBoucleJeu(SDL* sdl);
/** Procédure de chargement des images*/
SDL_Surface* SDLChargeImage(const char *nomfichier);


/** Pocédure qui teste le Module*/
void SDLTestRegression();

#endif /* SDL_H_INCLUDED */
