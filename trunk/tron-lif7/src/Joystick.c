#include <stdlib.h>
#include <SDL/SDL.h>
#include "Joystick.h"

void initialiserInput(Input *input,int numeroJoystick)
{
    if(numeroJoystick < SDL_NumJoysticks())
    {
        input->joystick = SDL_JoystickOpen(numeroJoystick);
        input->numero = numeroJoystick;
        int i;


        input->boutons = (char*) malloc(SDL_JoystickNumButtons(input->joystick) * sizeof(char));
        input->axes = (int*) malloc(SDL_JoystickNumAxes(input->joystick) * sizeof(int));
        input->chapeaux = (int*) malloc(SDL_JoystickNumHats(input->joystick) * sizeof(int));

        for(i=0;i<SDL_JoystickNumButtons(input->joystick);i++)
            input->boutons[i] = 0;
        for(i=0;i<SDL_JoystickNumAxes(input->joystick);i++)
            input->axes[i] = 0;
        for(i=0;i<SDL_JoystickNumHats(input->joystick);i++)
            input->chapeaux[i] = SDL_HAT_CENTERED;
           }

    else
    {

        input->joystick = NULL;
        input->boutons = NULL;
        input->axes = NULL;
        input->chapeaux = NULL;

    }
}

void detruireInput(Input *input)
{
    if(input->joystick != NULL){
        input->numero = 0;

        free(input->boutons);
        free(input->axes);
        free(input->chapeaux);

        SDL_JoystickClose(input->joystick);
    }
}

void updateEvent(Input *input)
{
    static SDL_Event evenements;
    while(SDL_PollEvent(&evenements))
    {
        if(input->joystick != NULL
        &&(evenements.jbutton.which == input->numero
        || evenements.jaxis.which == input->numero
        || evenements.jhat.which == input->numero
        || evenements.jball.which == input->numero))
        {
            switch(evenements.type)
            {
                case SDL_JOYBUTTONDOWN:
                    input->boutons[evenements.jbutton.button] = 1;
                    break;

                case SDL_JOYBUTTONUP:
                    input->boutons[evenements.jbutton.button] = 0;
                    break;

                case SDL_JOYAXISMOTION:
                    input->axes[evenements.jaxis.axis] = evenements.jaxis.value;
                    break;

                case SDL_JOYHATMOTION:
                    input->chapeaux[evenements.jhat.hat] = evenements.jhat.value;
                    break;

                default:
                    break;
            }
        }
    }
}
