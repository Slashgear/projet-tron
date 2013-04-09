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
    Moto moto;
    Controle controle;
    Couleur couleur;
    char enJeu;
}Joueur;

/** assesseur de moto*/
Moto* JoueurGetMoto(Joueur* joueur);
/** assesseur de controle*/
Controle* JoueurGetControle(Joueur* joueur);
/** assesseur de couleur*/
Couleur JoueurGetCouleur(const Joueur* joueur);
/** assesseur de enJeu*/
char JoueurGetEnJeu(const Joueur* joueur);

/** mutateur de moto*/
void JoueurSetMoto(Joueur* joueur, Moto* moto);
/** mutateur de controle*/
void JoueurSetControle(Joueur* joueur, Controle* controle);
/** mutateur de couleur*/
void JoueurSetCouleur(Joueur* joueur, Couleur couleur);
/** mutateur de enJeu*/
void JoueurSetEnJeu(Joueur* joueur, char enJeu);

/** Constructeur de Joueur*/
void JoueurConstructeur(Joueur* joueur, Moto* moto, Controle* controle, Couleur couleur, char enJeu);
/** Destructeur de Joueur*/
void JoueurDestructeur(Joueur* joueur);

/** Procedure qui teste le module Joueur*/
 void JoueurTestRegression();


#endif /* JOUEUR_H_INCLUDED */
