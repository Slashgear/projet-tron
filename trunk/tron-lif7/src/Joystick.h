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
}Input;

void initialiserInput(Input *input,int numeroJoystick);
void detruireInput(Input *input);
void updateEvent(Input *input);

#endif
