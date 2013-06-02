/**
\file [main.c]
	\brief main.c
	\author {Antoine.C,Matthieu.B}
\version 1.0
\date 13 mars 2013
*/
#include<stdlib.h>
#include<stdio.h>
#include <assert.h>
#include "Mur.h"
#include "Moto.h"
#include "Controle.h"
#include "Joueur.h"
#include "Grid.h"
#include "Jeu.h"
#include "SDL.h"
#include "Bonus.h"
#include "Constantes.h"
#include "Musique.h"
#include <time.h>


int main(){
#if 0
    /*MurTestRegression();
    ControleTestRegression();
    MotoTestRegression();
    JoueurTestRegression();
    GridTestRegression();*/
    JeuTestRegression();
    /*SDLTestRegression();
    BonusTestRegression();
   JoystickTestRegression();
   MusiqueTestRegression();*/
#else
    SDL sdl;
    short int jeuReInit=1;
    int scores[_Nombre_de_Joueur]={0};

    Musique uneMusique;
    assert(   SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK )!= -1 );
    srand(time(NULL));
    TTF_Init();
    SDL_WM_SetCaption( "TRON-The Grid v2.6", NULL );
    SDL_Surface* ecran=SDL_SetVideoMode(1295,710,32,SDL_HWSURFACE);
    SDLIntro(&jeuReInit,ecran);
    MusiqueConstructeur(&uneMusique);
    while(jeuReInit==1){
        SDLJeuInitN(&sdl,scores,ecran,&uneMusique);
        SDLDecompte(&sdl);
        SDLBoucleJeu(&sdl,&jeuReInit);
        SDLDestructeur(&sdl);
    }
    MusiqueDestructeur(&uneMusique);
    TTF_Quit();
    SDL_Quit();
#endif
return 0;
}
