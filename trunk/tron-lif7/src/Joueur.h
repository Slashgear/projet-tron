#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "Controle.h"
#include "Moto.h"
#include "Couleur.h"
/**
\file [Moto.h]
\brief Module des Motos du jeu
\author {Antoine.C,Matthieu.B}
\version 0.1
\date 19 mars 2013
*/

typedef struct {
    Moto* moto;
    Controle* controle;
    Couleur couleur;
}Joueur;

/** assesseur de moto*/
Moto* JoueurGetMoto(const Joueur* joueur);
/** assesseur de controle*/
Controle* JoueurGetControle(const Joueur* joueur);
/** assesseur de couleur*/JoueurConstructeur
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


#endif /* JOUEUR_H_INCLUDED */
