#include<stdlib.h>
#include<stdio.h>
#include "Mur.h"
#include "Moto.h"
#include "Controle.h"
#include "Joueur.h"
#include "Grid.h"
#include "Jeu.h"
#include "SDL.h"
#include "Bonus.h"

int main(){
#if 0
    /*MurTestRegression();
    ControleTestRegression();
    MotoTestRegression();
    JoueurTestRegression();
    GridTestRegression();
    JeuTestRegression();
    SDLTestRegression();*/

    BonusTestRegression();
   /* JoystickTestRegression();*/
#else
    SDL sdl;
    SDLJeuInitN(&sdl);
    SDLBoucleJeu(&sdl);
    SDLDestructeur(&sdl);
#endif
return 0;
}
