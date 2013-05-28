/**
\file [Musique.h]
 Module des Musiques du jeu
\author {Antoine.C,Matthieu.B}
\version 1.4
\date 19 avril 2013
*/
#ifndef MUSIQUE_H_INCLUDED
#define MUSIQUE_H_INCLUDED
#include "../lib/FMOD/inc/fmod.h"

#define _Nombre_De_Musique 3
#define _Nombre_De_Bruitages 2
/**
 	\struct Musique
 Structure d'une musique
 */
typedef struct{
    FMOD_SYSTEM *baseDuSon;
    FMOD_SOUND **sonCourt;
    FMOD_SOUND **musiqueDuJeu;
}Musique;
/**
 	\fn MusiqueGetBaseDuSon
 assesseur de BaseDuSon
 	\param Musique *musique
 	\return FMOD_SYSTEM*
 */
FMOD_SYSTEM* MusiqueGetBaseDuSon(Musique *musique);
/**
 	\fn MusiqueGetIemeSonCourt
 assesseur de BaseDuSon
 	\param Musique *musique,int i
 	\return FMOD_SOUND*
 */
FMOD_SOUND* MusiqueGetIemeSonCourt(Musique *musique,int i);
/**
 	\fn MusiqueGetIemeMusiqueDuJeu
 assesseur de la ieme musique du jeu
 	\param Musique *musique,int i
 	\return FMOD_SOUND*
 */
FMOD_SOUND* MusiqueGetIemeMusiqueDuJeu(Musique *musique,int i);
/**
 	\fn MusiqueSetBaseDuSon
 mutateur de BaseDuSon
 	\param Musique *musique,FMOD_SYSTEM *baseDuSon
 */
void MusiqueSetBaseDuSon(Musique *musique,FMOD_SYSTEM *baseDuSon);
/**
 	\fn MusiqueSetIemeSonCourt
 mutateur du ieme SonCourt
 	\param Musique *musique,FMOD_SOUND* unSon,int i
 */
void MusiqueSetIemeSonCourt(Musique *musique,FMOD_SOUND* unSon,int i);
/**
 	\fn MusiqueSetIemeMusiqueDuJeu
 mutateur de la ieme musique du Jeu
 	\param Musique *musique,FMOD_SOUND* unSon,int i
 */
void MusiqueSetIemeMusiqueDuJeu(Musique *musique,FMOD_SOUND* unSon,int i);

/**
 	\fn MusiqueSetSonCourt
 fonction qui affecte une tableau de sonsCourt au champs sonCourt de la structure musique
 	\param Musique *musique,FMOD_SOUND **SonCourt
 */
void MusiqueSetSonCourt(Musique *musique,FMOD_SOUND **SonCourt);
/**
 	\fn MusiqueSetMusiqueDuJeu
 fonction qui affecte une tablau de musique au champs musique de jeu
 	\param Musique *musique,FMOD_SOUND **musiqueDuJeu
 */
void MusiqueSetMusiqueDuJeu(Musique *musique,FMOD_SOUND **musiqueDuJeu);
/**
 	\fn MusiqueConstructeur
 constructeur du Musique
 	\param Musique *musique
 */
void MusiqueConstructeur(Musique *musique);
/**
 	\fn MusiqueDestructeur
 Destructeur du Musique
 	\param Musique *musique
 */
void MusiqueDestructeur(Musique *musique);
/**
 	\fn JouerIemeSonCourt
 fonction qui joue le Ieme son Court
 	\param Musique *musique,int i
 */
void JouerIemeSonCourt(Musique *musique,int i);
/**
 	\fn JouerIemeSonCourt
 fonction qui joue la Ieme Musique
 	\param Musique *musique,int i,int repetition
 */
void JouerIemeMusique(Musique *musique,int i,int repetition);
/**
 	\fn MusiqueTestRegression
 fonction qui teste le Module
 */
void MusiqueTestRegression();


#endif
