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
    MurTestRegression();
    ControleTestRegression();
    MotoTestRegression();
    JoueurTestRegression();
    GridTestRegression();
    JeuTestRegression();
    SDLTestRegression();
return 0;
}
