#include<stdlib.h>
#include<stdio.h>
#include "Joueur.h"
#include "Moto.h"

/** assesseur de moto*/
Moto* JoueurGetMoto(const Joueur* joueur);
/** assesseur de controle*/
Controle* JoueurGetControle(const Joueur* joueur);
/** assesseur de couleur*/
Couleur JoueurGetCouleur(const Joueur* joueur);

/** mutateur de moto*/
void JoueurSetMoto(Joueur* joueur, Moto moto);
/** mutateur de controle*/
void JoueurSetControle(Joueur* joueur, Controle controle);
/** mutateur de couleur*/
void JoueurSetCouleur(Joueur* joueur, Couleur couleur);

/** Constructeur de Joueur*/
void JoueurConstructeur(Joueur* joueur,const Moto* moto,const Controle* controle, Couleur couleur);
/** Destructeur de Joueur*/
void JoueurDestructeur(Joueur* joueur);

/** Procedure qui teste le module Joueur*/
 void JoueurTestRegression();
