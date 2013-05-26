/**
*\file [Controle.h]
*\brief Module qui défini les Controles
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 13 mars 2013
*/
#ifndef CONTROLE_H_INCLUDED
#define CONTROLE_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>
#include <SDL/SDL.h>


/**
 * \struct Controle
 * \brief Structure d'un Controle
 */
typedef struct{
    SDLKey droite; /*!< Touche droite. */
    SDLKey haut; /*!< Touche haute. */
    SDLKey bas; /*!< Touche basse. */
    SDLKey gauche; /*!< Touche gauche. */
    SDLKey bonus; /*!< Touche bonus. */
}Controle;

/**
 * \fn ControleGetDroite(const Controle* controle)
 * \brief Assesseur de la Touche droite
 * \param un Controle
 * \return SDLKey
 */
SDLKey ControleGetDroite(const Controle* controle);
/**
 * \fn ControleGetHaut(const Controle* controle)
 * \brief Assesseur de la Touche Haute
 * \param un Controle
 * \return SDLKey
 */
SDLKey ControleGetHaut(const Controle* controle);
/**
 * \fn ControleGetBas(const Controle* controle)
 * \brief Assesseur de la Touche Bas
 * \param un Controle
 * \return SDLKey
 */
SDLKey ControleGetBas(const Controle* controle);
/**
 * \fn ControleGetGauche(const Controle* controle)
 * \brief Assesseur de la Touche Gauche
 * \param un Controle
 * \return SDLKey
 */
SDLKey ControleGetGauche(const Controle* controle);
/**
 * \fn ControleGetBonus(const Controle* controle)
 * \brief Assesseur de la Touche Bonus
 * \param un Controle
 * \return SDLKey
 */
SDLKey ControleGetBonus(const Controle* controle);
/**
 * \fn ControleSetDroite(Controle* controle,SDLKey x)
 * \brief Mutateur de la Touche droite
 * \param Controle* controle,SDLKey x
 */
void ControleSetDroite(Controle* controle,SDLKey x);
/**
 * \fn ControleSetHaut(Controle* controle,SDLKey x)
 * \brief Mutateur de la Touche haute
 * \param Controle* controle,SDLKey x
 */
void ControleSetHaut(Controle* controle,SDLKey x);
/**
 * \fn ControleSetBas(Controle* controle,SDLKey x)
 * \brief Mutateur de la Touche bas
 * \param Controle* controle,SDLKey x
 */
void ControleSetBas(Controle* controle,SDLKey x);
/**
 * \fn ControleSetGauche(Controle* controle,SDLKey x)
 * \brief Mutateur de la Touche Gauche
 * \param Controle* controle,SDLKey x
 */
void ControleSetGauche(Controle* controle,SDLKey x);
/**
 * \fn ControleSetBonus(Controle* controle,SDLKey x)
 * \brief Mutateur de la Touche Bonus
 * \param Controle* controle,SDLKey x
 */
void ControleSetBonus(Controle* controle,SDLKey x);
/**
 * \fn ControleConstructeur
 * \brief Constructeur de Controle
 * \param Controle* controle, SDLKey haut,SDLKey bas,SDLKey gauche,SDLKey droite,SDLKey bonus
 */
void ControleConstructeur(Controle* controle, SDLKey haut,SDLKey bas,SDLKey gauche,SDLKey droite,SDLKey bonus);
/**
 * \fn ControleDestructeur
 * \brief Destructeur de Controle
 * \param Controle* controle
 */
void ControleDestructeur(Controle* controle);
/**
 * \fn ControleDestructeur
 * \brief Test du module
 */
 void ControleTestRegression();
#endif
