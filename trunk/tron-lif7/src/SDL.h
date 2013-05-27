/**
*\file [SDL.h]
*\brief Module qui gère les affichage du jeu,ainsi que les manettes
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 19 mars 2013
*/
#ifndef SDL_H_INCLUDED
#define SDL_H_INCLUDED
#include "Jeu.h"
#include <SDL/SDL.h>
#include "Joystick.h"
#include <SDL/SDL_ttf.h>
/**
 * \struct SDL
 * \brief Structure de l'affichage
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
 * \fn SDLGetJeu
 * \brief assesseur du Jeu
 * \param SDL* sdl
 * \return Jeu
 */
Jeu * SDLGetJeu(SDL* sdl);
/**
 * \fn SDLGetIemeTexture
 * \brief assesseur de ieme texture
 * \param SDL* sdl,unsigned int i
 * \return SDL_Surface *
 */
SDL_Surface * SDLGetIemeTexture(const SDL* sdl,unsigned int i);
/**
 * \fn SDLGetIemeManette
 * \brief assesseur de ieme manette
 * \param SDL* sdl,unsigned int i
 * \return Manette*
 */
Manette* SDLGetIemeManette(const SDL* sdl,unsigned int i);
/**
 * \fn SDLGetTextures
 * \brief assesseur de textures
 * \param SDL* sdl
 * \return Manette*
 */
SDL_Surface * SDLGetTextures(const SDL* sdl);


/**
 * \fn SDLSetJeu
 * \brief mutateur de jeu
 * \param SDL * sdl,Jeu* jeu
 */
void SDLSetJeu(SDL * sdl,Jeu* jeu);
/**
 * \fn SDLSetIemeTexture
 * \brief mutateur de ieme texture
 * \param SDL *sdl,unsigned int i,SDL_Surface * texture
 */
void SDLSetIemeTexture(SDL *sdl,unsigned int i,SDL_Surface * texture);


/**
 * \fn SDLSetJeu
 * \brief Procedure qui met le jeu en pause jusqu'à ce qu'on quitte le jeu
 */
void pause();

/**
 * \fn SDLConstructeur
 * \brief Constructeur de SDL, initialise les différents champs
 * \param SDL *sdl,Jeu* jeu,Manette *mesManettes
 */
void SDLConstructeur(SDL *sdl,Jeu* jeu,Manette *mesManettes);
/**
 * \fn SDLDestructeur
 * \brief Destructeur de SDl,remise à zero des champs de SDL et free des allocations
 * \param SDL *sdl
 */
void SDLDestructeur(SDL *sdl);
/**
 * \fn SDLAppliqueSurface
 * \brief Procédure qui applique la surface A sur la B
 * \param SDL_Surface * surfaceA, SDL_Surface * surfaceB,int positionX,int positionY
 */
void SDLAppliqueSurface(SDL_Surface * surfaceA, SDL_Surface * surfaceB,int positionX,int positionY);
/**
 * \fn SDLAfficheJeu
 * \brief Procédure d'affichage du jeu
 * \param SDL *sdl,int *scores
 */
void SDLAfficheJeu(SDL *sdl,int *scores);
/**
 * \fn SDLAfficheMotos
 * \brief Procédure d'affichage des Motos
 * \param SDL *sdl
 */
void SDLAfficheMotos(SDL *sdl);
/**
 * \fn SDLAfficheMurs
 * \brief Procédure d'affichage des Murs
 * \param SDL *sdl
 */
void SDLAfficheMurs(SDL *sdl);
/**
 * \fn SDLAfficheInterface
 * \brief Procédure qui affiche l'interface
 * \param SDL *sdl
 */
void SDLAfficheInterface(SDL *sdl);
/**
 * \fn SDLAfficheBonus
 * \brief Procédure qui affiche les Bonus
 * \param SDL *sdl
 */
void SDLAfficheBonus(SDL*sdl);
/**
 * \fn SDLJeuInitN
 * \brief Procédure Init à N=_Nombre_De_Joueur joueurs
 * \param SDL *sdl, int *scores
 */
void SDLJeuInitN(SDL *sdl, int *scores);
/**
 * \fn SDLAfficheTextes
 * \brief procédure qui affiche les textes de l'actualité du jeu
 * \param SDL *sdl,char *chaineDeCaractere,Couleur uneCouleur
 */
void SDLAfficheTextes(SDL *sdl,char *chaineDeCaractere,Couleur uneCouleur);
/**
 * \fn SDLAfficheScores
 * \brief procédure que affiche les scores, sous forme de graphique en barres
 * \param SDL *sdl,int *scores
 */
void SDLAfficheScores(SDL *sdl,int *scores);

/**
 * \fn SDLBoucleJeu
 * \brief  Boucle principale du Jeu
 * \param SDL* sdl, short int *jeuReInit, int* scores
 */
void SDLBoucleJeu(SDL* sdl, short int *jeuReInit, int* scores);
/**
 * \fn SDLChargeImage
 * \brief  Procédure de chargement des images
 * \param const char *nomfichier
 * \return SDL_Surface *
 */
SDL_Surface* SDLChargeImage(const char *nomfichier);
/**
 * \fn SDLActionManette
 * \brief procédure qui gère les actions des motos en fonction des touches saisies sur une Manette
 * \param Joueur* joueur, Direction direction,Grid* grille
 */
void SDLActionManette(Joueur* joueur, Direction direction,Grid* grille);

/**
 * \fn SDLTestRegression
 * \brief procédure qui teste le Module
 */
void SDLTestRegression();

#endif
