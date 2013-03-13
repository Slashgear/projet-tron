
#ifndef _JEU_H
#define _JEU_H

#include "Moto.h"
#include "Grid.h"



typedef struct
{
	Grid grille;
	Fantome *tab_motos;
} Jeu;

void jeuInit(Jeu *);
void jeuLibere(Jeu *);
Terrain *jeuGetTerrainPtr(Jeu *);
Pacman *jeuGetPacmanPtr(Jeu *);
const Terrain *jeuGetConstTerrainPtr(const Jeu *);
const Pacman *jeuGetConstPacmanPtr(const Jeu *);


void jeuActionClavier(Jeu *j, const char);
void jeuEvolue(Jeu *pJeu);

#endif
