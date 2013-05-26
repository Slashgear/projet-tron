/**
\file [Joueur.h]
\brief Module des Joueurs
\author {Antoine.C,Matthieu.B}
\version 1.1
\date 19 mars 2013
*/
#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "Controle.h"
#include "Moto.h"
#include "Couleur.h"
#include "EffetBonus.h"
#include "Mur.h"



/**
*\enum EnJeu
*/
typedef enum{MORT=0,VIVANT=1,MOURANT=2,DOUTE=3} EnJeu;
/**
 * \struct Joueur
 * \brief Structure d'un Joueur
 */
typedef struct {
    Moto moto;
    Couleur couleur;
    Controle controle;
    short int numeroManette;
    short int numeroJoueur;
    Mur* dernierMur;
    short int boolTourne;
    EnJeu enJeu;
    EffetBonus effetActuel;
    int tempsBonus;
    short int boolIA;
    short int joueurCible;
}Joueur;

/** assesseur de moto*/
Moto* JoueurGetMoto(Joueur* joueur);
/** assesseur de controle*/
Controle* JoueurGetControle(Joueur* joueur);
/** assesseur de couleur*/
Couleur JoueurGetCouleur(const Joueur* joueur);
/** assesseur de enJeu*/
EnJeu JoueurGetEnJeu(const Joueur* joueur);
/**assesseur du bonus en cours*/
EffetBonus JoueurGetEffetBonus(const Joueur *Joueur);
/**assesseur du numero de la Manette */
short int JoueurGetNumeroManette(const Joueur *joueur);
/**assesseur du tempsBonus */
int JoueurGetTempsBonus(const Joueur *joueur);
/**assesseur du dernierMur*/
Mur* JoueurGetDernierMur(Joueur *joueur);
/**assesseur de boolTourne*/
short int JoueurGetBooltourne(Joueur *joueur);
/**assesseur du numero de joueur*/
short int JoueurGetNumeroJoueur(Joueur *joueur);
/**assesseur de boolIA*/
short int JoueurGetBoolIA(Joueur *joueur);
/**assesseur du numero du joueur ciblé*/
short int JoueurGetJoueurCible(Joueur *joueur);




/** mutateur de moto*/
void JoueurSetMoto(Joueur* joueur, Moto* moto);
/** mutateur de controle*/
void JoueurSetControle(Joueur* joueur, Controle* controle);
/** mutateur de couleur*/
void JoueurSetCouleur(Joueur* joueur, Couleur couleur);
/** mutateur de enJeu*/
void JoueurSetEnJeu(Joueur* joueur, EnJeu enJeu);
/** mutateur du Bonus en cours*/
void JoueurSetEffetBonus(Joueur* joueur,EffetBonus effet);
/** mutateur du numero de manette*/
void JoueurSetNumeroManette(Joueur* joueur,short int numero);
/** mutateur du tempsBonus*/
void JoueurSetTempsBonus(Joueur* joueur, int tempsBonus);
/** mutateur du dernierMur*/
void JoueurSetDernierMur(Joueur* joueur,Mur* unMur);
/** mutateur de boolTourne*/
void JoueurSetBooltourne(Joueur *joueur,short int boolTourne);
/** mutateur du numero de joueur*/
void JoueurSetNumeroJoueur(Joueur *joueur,short int numero);
/** mutateur de boolIA*/
void JoueurSetBoolIA(Joueur *joueur,short int boolIA);
/** mutateur du numero du joueur ciblé*/
void JoueurSetJoueurCible(Joueur *joueur,short int numero);




/** Constructeur de Joueur*/
void JoueurConstructeur(Joueur* joueur, Moto* moto, Controle* controle, Couleur couleur, EnJeu enJeu,
                        EffetBonus effetActuel,short int numeroManette,short int numeroJoueur,short int boolIA);
/** Destructeur de Joueur*/
void JoueurDestructeur(Joueur* joueur);

/** Procedure qui teste le module Joueur*/
 void JoueurTestRegression();


#endif /* JOUEUR_H_INCLUDED */
