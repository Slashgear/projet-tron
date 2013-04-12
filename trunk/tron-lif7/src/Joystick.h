#ifndef JOYSTICK_H_INCLUDED
#define JOYSTICK_H_INCLUDED
#include <SDL/SDL.h>


typedef struct
{
    SDL_Joystick *joystick;
    char *boutons;
    int *axes;
    int *chapeaux;
    int numero;
}Manette;

void initialiserInput(Manette *manette,int numeroJoystick);
void detruireInput(Manette *manette);
void updateEvent(Manette *manette);

#endif
