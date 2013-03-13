#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>
#include"src/Grid.h"
#include "src/Moto.h"

typedef struct
{
	Grid grille;
	Moto *tab_Motos;
	Joueur *mesJoueur;
	int nb_motos;
} Jeu;

void jeuInit(Jeu *);
void jeuLibere(Jeu *);
Grid *jeuGetTerrainPtr(Jeu *);

#endif // JEU_H_INCLUDED
