#ifndef JOYSTICK_H_INCLUDED
#define JOYSTICK_H_INCLUDED
#include <SDL/SDL.h>

/**
*\file [Joystick.h]
*\brief Module des vecteurs
*\author {Antoine.C,Matthieu.B}
*\version 0.1
*\date 11 avril 2013
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
void updateEvent(Manette *manette);
/**fonction qui teste le module*/
void JoystickTestRegression();

#endif
