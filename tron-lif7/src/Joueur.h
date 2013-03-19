#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

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
    enum{ORANGE, BLEU} couleur;
}Joueur;

/** assesseur de moto*/
Moto JoueurGetMoto(const Joueur* joueur);
/** assesseur de controle*/
Controle JoueurGetControle(const Joueur* joueur);
/** assesseur de couleur*/
Couleur JoueurGetCouleur(const Joueur* joueur);

/** mutateur de moto*/
void JoueurSetMoto(Joueur* joueur, Moto moto);
/** mutateur de controle*/
void JoueurSetMoto(Joueur* joueur, Controle controle);
/** mutateur de couleur*/
void JoueurSetMoto(Joueur* joueur, enum{ORANGE, BLEU} moto);

/** Constructeur de Joueur*/
void JoueurConstructeur(Joueur* joueur);
/** Destructeur de Joueur*/
void JoueurDestructeur(Joueur* joueur);

/** Procedure qui teste le module Joueur*/
 void JoueurTestRegression();


#endif /* JOUEUR_H_INCLUDED */
