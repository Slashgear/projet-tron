#ifndef MUSIQUE_H_INCLUDED
#define MUSIQUE_H_INCLUDED
#include "../lib/FMOD/inc/fmod.h"

/**
\file [Musique.h]
\brief Module des Musiques du jeu
\author {Antoine.C,Matthieu.B}
\version 1.4
\date 19 avril 2013
*/

typedef struct{
    FMOD_SYSTEM *baseDuSon;
    FMOD_SOUND **sonCourt;
}Musique;

/**assesseur de BaseDuSon*/
FMOD_SYSTEM* MusiqueGetBaseDuSon(Musique *musique);
/**assesseur du ieme Son Court*/
FMOD_SOUND* MusiqueGetIemeSonCourt(Musique *musique,int i);

/**mutateur de BaseDuSon*/
void MusiqueSetBaseDuSon(Musique *musique,FMOD_SYSTEM *baseDuSon);
/**mutateur du ieme SonCourt*/
void MusiqueSetIemeSonCourt(Musique *musique,FMOD_SOUND* unSon,int i);

/**fonction qui affect une tableau de sonsCourt au champs sonCourt de la structure musique*/
void MusiqueSetSonCourt(Musique *musique,FMOD_SOUND **SonCourt);

/**constructeur du Musique*/
void MusiqueConstructeur(Musique *musique);

/**Destructeur de Musique*/
void MusiqueDestructeur(Musique *musique);

/** fonction qui joue le Ieme son Court*/
void JouerIemeSonCourt(Musique *musique,int i);

/**fonction qui teste le module*/
void MusiqueTestRegression();


#endif
