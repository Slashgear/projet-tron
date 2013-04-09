#include<stdlib.h>
#include<stdio.h>
#include "Mur.h"
#include "Moto.h"
#include "Controle.h"
#include "Joueur.h"
#include "Grid.h"
#include "Jeu.h"
#include "SDL.h"

int main(){
#if 0
    MurTestRegression();
    ControleTestRegression();
    MotoTestRegression();
    JoueurTestRegression();
    GridTestRegression();
    JeuTestRegression();
    SDLTestRegression();
#else
    SDL sdl;
    if(_Nombre_de_Joueur==2){
        SDLJeuInit2(&sdl);
    }
    else if(_Nombre_de_Joueur==4){
        SDLJeuInit4(&sdl);
    }
    SDLBoucleJeu(&sdl);
    SDLDestructeur(&sdl);
#endif
return 0;
}
