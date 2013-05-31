/**
	\file [SDL.h]
	 Module qui gère les affichage du jeu,ainsi que les manettes
	\author {Antoine.C,Matthieu.B}
	\version 0.1
	\date 19 mars 2013
*/
#ifndef SDL_H_INCLUDED
#define SDL_H_INCLUDED
#include "Jeu.h"
#include <SDL/SDL.h>
#include "Joystick.h"
#include <SDL/SDL_ttf.h>
/**
 	\struct SDL
 Structure de l'affichage
 */
typedef struct{
    Jeu jeu;
    SDL_Surface * textures[2+4*_Nombre_de_Joueur+_Nombre_de_Bonus+_Nombre_de_Textes+_Nombre_Images_Interface];
    /*!< La texture 0 est le fond(ecran), la texture 1 est la grille, les textures 2 à 5 sont celles du joueur 1,
    les quatre suivantes celles du joueur 2, etc..
    Viennent ensuite les texture des Bonus, celles des textures d'interfaces puis enfin les textes */
    Manette* mesManettes;
    TTF_Font *police;
    TTF_Font *policeGrandsMessages;
}SDL;


/**
 	\fn SDLGetJeu
 assesseur du Jeu
 	\param SDL* sdl
 	\return Jeu
 */
Jeu * SDLGetJeu(SDL* sdl);
/**
 	\fn SDLGetIemeTexture
 assesseur de ieme texture
 	\param SDL* sdl,unsigned int i
 	\return SDL_Surface *
 */
SDL_Surface * SDLGetIemeTexture(const SDL* sdl,unsigned int i);
/**
 	\fn SDLGetIemeManette
 assesseur de ieme manette
 	\param SDL* sdl,unsigned int i
 	\return Manette*
 */
Manette* SDLGetIemeManette(const SDL* sdl,unsigned int i);
/**
 	\fn SDLGetTextures
 assesseur de textures
 	\param SDL* sdl
 	\return Manette*
 */
SDL_Surface * SDLGetTextures(const SDL* sdl);


/**
 	\fn SDLSetJeu
 mutateur de jeu
 	\param SDL * sdl,Jeu* jeu
 */
void SDLSetJeu(SDL * sdl,Jeu* jeu);
/**
 	\fn SDLSetIemeTexture
 mutateur de ieme texture
 	\param SDL *sdl,unsigned int i,SDL_Surface * texture
 */
void SDLSetIemeTexture(SDL *sdl,unsigned int i,SDL_Surface * texture);


/**
 	\fn SDLSetJeu
 Procedure qui met le jeu en pause jusqu'à ce qu'on quitte le jeu
 */
void pause();

/**
 	\fn SDLConstructeur
 Constructeur de SDL, initialise les différents champs
 	\param SDL *sdl,SDL_Surface* ecran,Jeu* jeu,Manette *mesManettes
 */
void SDLConstructeur(SDL *sdl,SDL_Surface* ecran,Jeu* jeu,Manette *mesManettes);
/**
 	\fn SDLDestructeur
 Destructeur de SDl,remise à zero des champs de SDL et free des allocations
 	\param SDL *sdl
 */
void SDLDestructeur(SDL *sdl);
/**
 	\fn SDLAppliqueSurface
 Procédure qui applique la surface A sur la B
 	\param SDL_Surface * surfaceA, SDL_Surface * surfaceB,int positionX,int positionY
 */
void SDLAppliqueSurface(SDL_Surface * surfaceA, SDL_Surface * surfaceB,int positionX,int positionY);
/**
 	\fn SDLAfficheJeu
 Procédure d'affichage du jeu
 	\param SDL *sdl
 */
void SDLAfficheJeu(SDL *sdl);
/**
 	\fn SDLAfficheMotos
 Procédure d'affichage des Motos
 	\param SDL *sdl
 */
void SDLAfficheMotos(SDL *sdl);
/**
 	\fn SDLAfficheMurs
 Procédure d'affichage des Murs
 	\param SDL *sdl
 */
void SDLAfficheMurs(SDL *sdl);
/**
 	\fn SDLAfficheInterface
 Procédure qui affiche l'interface
 	\param SDL *sdl
 */
void SDLAfficheInterface(SDL *sdl);
/**
 	\fn SDLAfficheBonus
 Procédure qui affiche les Bonus
 	\param SDL *sdl
 */
void SDLAfficheBonus(SDL*sdl);
/**
 	\fn SDLIntro
 Procédure qui affiche l'écran d'accueil
 	\param short int *jeuReInit,SDL_Surface* ecran
 */
void SDLIntro(short int *jeuReInit,SDL_Surface* ecran);
/**
 	\fn SDLJeuInitN
 Procédure Init à N=_Nombre_De_Joueur joueurs
 	\param SDL *sdl, int *scores,SDL_Surface* ecran
 */
void SDLJeuInitN(SDL *sdl, int *scores,SDL_Surface* ecran);
/**
 	\fn SDLAfficheTextes
 procédure qui affiche les textes de l'actualité du jeu
 	\param SDL *sdl,char *chaineDeCaractere,Couleur uneCouleur
 */
void SDLAfficheTextes(SDL *sdl,char *chaineDeCaractere,Couleur uneCouleur);
/**
 	\fn SDLAfficheScores
 procédure que affiche les scores, sous forme de graphique en barres
 	\param SDL *sdl
 */
void SDLAfficheScores(SDL *sdl);

/**
 	\fn SDLBoucleJeu
  Boucle principale du Jeu
 	\param SDL* sdl, short int *jeuReInit
 */
void SDLBoucleJeu(SDL* sdl, short int *jeuReInit);
/**
 	\fn SDLChargeImage
  Procédure de chargement des images
 	\param const char *nomfichier
 	\return SDL_Surface *
 */
SDL_Surface* SDLChargeImage(const char *nomfichier);
/**
 	\fn SDLActionManette
 procédure qui gère les actions des motos en fonction des touches saisies sur une Manette
 	\param Joueur* joueur, Direction direction,Grid* grille
 */
void SDLActionManette(Joueur* joueur, Direction direction,Grid* grille);

/**
 	\fn SDLTestRegression
 procédure qui teste le Module
 */
void SDLTestRegression();

#endif
