#ifndef MUSIQUE_H_INCLUDED
#define MUSIQUE_H_INCLUDED
#include "../lib/FMOD/inc/fmod.h"

#define _Nombre_De_Musique 3
#define _Nombre_De_Bruitages 2

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
    FMOD_SOUND **musiqueDuJeu;
}Musique;

/**assesseur de BaseDuSon*/
FMOD_SYSTEM* MusiqueGetBaseDuSon(Musique *musique);
/**assesseur du ieme Son Court*/
FMOD_SOUND* MusiqueGetIemeSonCourt(Musique *musique,int i);
/**assesseur de la ieme musique du jeu*/
FMOD_SOUND* MusiqueGetIemeMusiqueDuJeu(Musique *musique,int i);

/**mutateur de BaseDuSon*/
void MusiqueSetBaseDuSon(Musique *musique,FMOD_SYSTEM *baseDuSon);
/**mutateur du ieme SonCourt*/
void MusiqueSetIemeSonCourt(Musique *musique,FMOD_SOUND* unSon,int i);
/**mutateur de la ieme musique du Jeu*/
void MusiqueSetIemeMusiqueDuJeu(Musique *musique,FMOD_SOUND* unSon,int i);

/**fonction qui affecte une tableau de sonsCourt au champs sonCourt de la structure musique*/
void MusiqueSetSonCourt(Musique *musique,FMOD_SOUND **SonCourt);
/**fonction qui affecte une tablau de musique au champs musique de jeu*/
void MusiqueSetMusiqueDuJeu(Musique *musique,FMOD_SOUND **musiqueDuJeu);

/**constructeur du Musique*/
void MusiqueConstructeur(Musique *musique);

/**Destructeur de Musique*/
void MusiqueDestructeur(Musique *musique);

/** fonction qui joue le Ieme son Court*/
void JouerIemeSonCourt(Musique *musique,int i);
/** fonction qui joue la Ieme Musique*/
void JouerIemeMusique(Musique *musique,int i,int repetition);

/**fonction qui teste le module*/
void MusiqueTestRegression();


#endif
