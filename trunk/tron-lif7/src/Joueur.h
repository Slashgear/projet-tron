/**
\file [Joueur.h]
@brief Module des Joueurs
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
 * @brief Structure d'un Joueur
 */
typedef struct {
    Moto moto;
    Couleur couleur;
    Controle controle;
    short int numeroManette;
    short int numeroJoueur;
    Mur dernierMur;
    short int boolTourne;
    EnJeu enJeu;
    EffetBonus effetActuel;
    int tempsBonus;
    short int boolIA;/**!< Defini si le joueur est un controlé par l'ordinateur ou non*/
    short int joueurCible;
}Joueur;

/**
 * \fn JoueurGetMoto
 * @brief assesseur de moto
 * @param Joueur* joueur
 * \return Moto*
 */
Moto* JoueurGetMoto(Joueur* joueur);
/**
 * \fn JoueurGetControle
 * @brief assesseur de controle
 * @param Joueur* joueur
 * \return Controle*
 */
Controle* JoueurGetControle(Joueur* joueur);
/**
 * \fn JoueurGetCouleur
 * @brief assesseur de couleur
 * @param Joueur* joueur
 * \return Couleur
 */
Couleur JoueurGetCouleur(const Joueur* joueur);
/**
 * \fn JoueurGetEnJeu
 * @brief assesseur de enJeu
 * @param Joueur* joueur
 * \return EnJeu
 */
EnJeu JoueurGetEnJeu(const Joueur* joueur);
/**
 * \fn JoueurGetEffetBonus
 * @brief assesseur du bonus en cours
 * @param const Joueur* joueur
 * \return EffetBonus
 */
EffetBonus JoueurGetEffetBonus(const Joueur *Joueur);
/**
 * \fn JoueurGetNumeroManette
 * @brief assesseur du numero de la Manette
 * @param const Joueur* joueur
 * \return numero
 */
short int JoueurGetNumeroManette(const Joueur *joueur);
/**
 * \fn JoueurGetTempsBonus
 * @brief assesseur du tempsBonus
 * @param const Joueur* joueur
 * \return temps d'action du Bonus
 */
int JoueurGetTempsBonus(const Joueur *joueur);
/**
 * \fn JoueurGetDernierMur
 * @brief assesseur du dernierMur
 * @param Joueur* joueur
 * \return Mur*
 */
Mur* JoueurGetDernierMur(Joueur *joueur);
/**
 * \fn JoueurGetBooltourne
 * @brief assesseur de boolTourne
 * @param Joueur* joueur
 * \return booltourne
 */
short int JoueurGetBooltourne(Joueur *joueur);
/**
 * \fn JoueurGetNumeroJoueur
 * @brief assesseur du numero de joueur
 * @param Joueur* joueur
 * \return numeroJoueur
 */
short int JoueurGetNumeroJoueur(Joueur *joueur);
/**
 * \fn JoueurGetBoolIA
 * @brief assesseur de BoolIA
 * @param Joueur* joueur
 * \return boolIA
 */
short int JoueurGetBoolIA(Joueur *joueur);
/**
 * \fn JoueurGetJoueurCible
 * @brief assesseur du numero du joueur ciblé
 * @param Joueur* joueur
 * \return numero Joueur Cible
 */
short int JoueurGetJoueurCible(Joueur *joueur);



/**
 * \fn JoueurSetMoto
 * @brief mutateur de moto
 * @param Joueur* joueur, Moto* moto
 */
void JoueurSetMoto(Joueur* joueur, Moto* moto);
/**
 * \fn JoueurSetControle
 * @brief mutateur de controle
 * @param Joueur* joueur, Controle* controle
 */
void JoueurSetControle(Joueur* joueur, Controle* controle);
/**
 * \fn JoueurSetCouleur
 * @brief mutateur de couleur
 * @param Joueur* joueur, Couleur couleur
 */
void JoueurSetCouleur(Joueur* joueur, Couleur couleur);
/**
 * \fn JoueurSetEnJeu
 * @brief mutateur de enJeu
 * @param Joueur* joueur, EnJeu enJeu
 */
void JoueurSetEnJeu(Joueur* joueur, EnJeu enJeu);
/**
 * \fn JoueurSetEffetBonus
 * @brief mutateur du Bonus en cours
 * @param Joueur* joueur,EffetBonus effet
 */
void JoueurSetEffetBonus(Joueur* joueur,EffetBonus effet);
/**
 * \fn JoueurSetNumeroManette
 * @brief mutateur du numero de manette
 * @param Joueur* joueur,short int numero
 */
void JoueurSetNumeroManette(Joueur* joueur,short int numero);
/**
 * \fn JoueurSetTempsBonus
 * @brief mutateur du Temps Bonus
 * @param Joueur* joueur, int tempsBonus
 */
void JoueurSetTempsBonus(Joueur* joueur, int tempsBonus);
/**
 * \fn JoueurSetDernierMur
 * @brief mutateur du dernierMur
 * @param Joueur* joueur,Mur* unMur
 */
void JoueurSetDernierMur(Joueur* joueur,Mur* unMur);
/**
 * \fn JoueurSetBooltourne
 * @brief mutateur de boolTourne
 * @param Joueur *joueur,short int boolTourne
 */
void JoueurSetBooltourne(Joueur *joueur,short int boolTourne);
/**
 * \fn JoueurSetNumeroJoueur
 * @brief mutateur de boolTourne
 * @param Joueur *joueur,short int boolTourne
 */
void JoueurSetNumeroJoueur(Joueur *joueur,short int numero);
/**
 * \fn JoueurSetBoolIA
 * @brief mutateur de boolIA
 * @param Joueur *joueur,short int boolIA
 */
void JoueurSetBoolIA(Joueur *joueur,short int boolIA);
/**
 * \fn JoueurSetJoueurCible
 * @brief mutateur du numero du joueur ciblé
 * @param Joueur *joueur,short int numero
 */
void JoueurSetJoueurCible(Joueur *joueur,short int numero);
/**
 * \fn JoueurConstructeur
 * @brief Constructeur de Joueur
 * @param Joueur* joueur, Moto* moto, Controle* controle, Couleur couleur, EnJeu enJeu,
        EffetBonus effetActuel,short int numeroManette,short int numeroJoueur,short int boolIA
 */
void JoueurConstructeur(Joueur* joueur, Moto* moto, Controle* controle, Couleur couleur, EnJeu enJeu,
                        EffetBonus effetActuel,short int numeroManette,short int numeroJoueur,short int boolIA);
/**
 * \fn JoueurDestructeur
 * @brief Destructeur de Joueur
 * @param Joueur* joueur
 */
void JoueurDestructeur(Joueur* joueur);
/**
 * \fn JoueurTestRegression
 * @brief Procedure qui teste le module Joueur
 */
 void JoueurTestRegression();


#endif /* JOUEUR_H_INCLUDED */
