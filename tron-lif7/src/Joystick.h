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

/**fonction qui initialise  une manette*/
void initialiserManette(Manette *manette,int numeroJoystick);
/**fonction qui détruit une manette*/
void detruireManette(Manette *manette);
/**fonction qui renvoit les inputs d'une manette passé en paramèrtre*/
void updateEvent(Manette *manette, SDL_Event evenement);
/**fonction qui teste le module*/
void JoystickTestRegression();

#endif
