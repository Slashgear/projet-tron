#include <stdlib.h>
#include <SDL/SDL.h>
#include "Joystick.h"

void initialiserManette(Manette *manette,int numeroJoystick)
{
    if(numeroJoystick < SDL_NumJoysticks())
    {
        manette->joystick = SDL_JoystickOpen(numeroJoystick);
        manette->numero = numeroJoystick;
        int i;


        manette->boutons = (char*) malloc(SDL_JoystickNumButtons(manette->joystick) * sizeof(char));
        manette->axes = (int*) malloc(SDL_JoystickNumAxes(manette->joystick) * sizeof(int));
        manette->chapeaux = (int*) malloc(SDL_JoystickNumHats(manette->joystick) * sizeof(int));

        for(i=0;i<SDL_JoystickNumButtons(manette->joystick);i++)
            manette->boutons[i] = 0;
        for(i=0;i<SDL_JoystickNumAxes(manette->joystick);i++)
            manette->axes[i] = 0;
        for(i=0;i<SDL_JoystickNumHats(manette->joystick);i++)
            manette->chapeaux[i] = SDL_HAT_CENTERED;
           }

    else
    {

        manette->joystick = NULL;
        manette->boutons = NULL;
        manette->axes = NULL;
        manette->chapeaux = NULL;

    }
}

void detruireManette(Manette *manette)
{
    if(manette->joystick != NULL){
        manette->numero = 0;

        free(manette->boutons);
        free(manette->axes);
        free(manette->chapeaux);

        SDL_JoystickClose(manette->joystick);
    }
}

void updateEvent(Manette *manette, SDL_Event evenements)
{
    if(manette->joystick != NULL
    &&(evenements.jbutton.which == manette->numero
    || evenements.jaxis.which == manette->numero
    || evenements.jhat.which == manette->numero
    || evenements.jball.which == manette->numero))
    {
        switch(evenements.type)
        {
            case SDL_JOYBUTTONDOWN:
                manette->boutons[evenements.jbutton.button] = 1;
                break;

            case SDL_JOYBUTTONUP:
                manette->boutons[evenements.jbutton.button] = 0;
                break;

            case SDL_JOYAXISMOTION:
                manette->axes[evenements.jaxis.axis] = evenements.jaxis.value;
                break;

            case SDL_JOYHATMOTION:
                manette->chapeaux[evenements.jhat.hat] = evenements.jhat.value;
                break;

            default:
                break;
        }
    }
}

void JoystickTestRegression(){

SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);

    Manette manette;
    int i;
    int j;
    SDL_Event evenement;
    SDL_JoystickEventState(SDL_ENABLE);
    initialiserManette(&manette,0);
    int quitter = 0;
    printf("Nombre de Joystick :%d\n",SDL_NumJoysticks());
    for(i=0;i<SDL_NumJoysticks();i++){
    printf("Nom du joystick numero %d : %s\n",i,SDL_JoystickName(i));
    printf("nombre boutons %d\n ",SDL_JoystickNumButtons(manette.joystick));
    printf("nombre de chapeaux %d\n",SDL_JoystickGetHat(manette.joystick,0));
    }
    while(!quitter)
    {
        updateEvent(&manette,evenement);
        for(j=0;j<15;j++){
        if(manette.boutons[j])
        {
            printf("Le bouton %d est appuyé\n",j);
        }
        }
        if(manette.boutons[6]){quitter=1;}

    }


    detruireManette(&manette);
    SDL_Quit();

}

