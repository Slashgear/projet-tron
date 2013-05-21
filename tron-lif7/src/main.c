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
    assert(   SDL_Init( SDL_INIT_VIDEO | SDL_INIT_JOYSTICK )!= -1 );
    while(jeuReInit==1){
        SDLJeuInitN(&sdl,scores);
        SDLBoucleJeu(&sdl,&jeuReInit,scores);
        SDLDestructeur(&sdl);
    }
    SDL_Quit();
#endif
return 0;
}
