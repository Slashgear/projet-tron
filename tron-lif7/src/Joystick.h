/**
*\file [Joystick.h]
*\brief Module des manettes
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 11 avril 2013
*/
#ifndef JOYSTICK_H_INCLUDED
#define JOYSTICK_H_INCLUDED
#include <SDL/SDL.h>


/**
 * \struct Manette
 * \brief Structure d'une manette
 */
typedef struct
{
    SDL_Joystick *joystick;
    char *boutons;
    int *axes;
    int *chapeaux;
    int numero;
}Manette;
/**
 * \fn initialiserManette
 * \brief  fonction qui initialise  une manette
 * \param Manette *manette,int numeroJoystick
 */
void initialiserManette(Manette *manette,int numeroJoystick);
/**
 * \fn detruireManette
 * \brief  fonction qui détruit une manette
 * \param Manette *manette
 */
void detruireManette(Manette *manette);
/**
 * \fn updateEvent
 * \brief  fonction qui renvoit les inputs d'une manette passé en paramèrtre
 * \param Manette *manette, SDL_Event evenement
 */
void updateEvent(Manette *manette, SDL_Event evenement);
/**
 * \fn JoystickTestRegression
 * \brief  fonction qui teste le module
 */
void JoystickTestRegression();

#endif
