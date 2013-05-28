/**
\file [Musique.h]
@brief Module des Musiques du jeu
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
 * \struct Musique
 * @brief Structure d'une musique
 */
typedef struct{
    FMOD_SYSTEM *baseDuSon;
    FMOD_SOUND **sonCourt;
    FMOD_SOUND **musiqueDuJeu;
}Musique;
/**
 * \fn MusiqueGetBaseDuSon
 * @brief assesseur de BaseDuSon
 * @param Musique *musique
 * \return FMOD_SYSTEM*
 */
FMOD_SYSTEM* MusiqueGetBaseDuSon(Musique *musique);
/**
 * \fn MusiqueGetIemeSonCourt
 * @brief assesseur de BaseDuSon
 * @param Musique *musique,int i
 * \return FMOD_SOUND*
 */
FMOD_SOUND* MusiqueGetIemeSonCourt(Musique *musique,int i);
/**
 * \fn MusiqueGetIemeMusiqueDuJeu
 * @brief assesseur de la ieme musique du jeu
 * @param Musique *musique,int i
 * \return FMOD_SOUND*
 */
FMOD_SOUND* MusiqueGetIemeMusiqueDuJeu(Musique *musique,int i);
/**
 * \fn MusiqueSetBaseDuSon
 * @brief mutateur de BaseDuSon
 * @param Musique *musique,FMOD_SYSTEM *baseDuSon
 */
void MusiqueSetBaseDuSon(Musique *musique,FMOD_SYSTEM *baseDuSon);
/**
 * \fn MusiqueSetIemeSonCourt
 * @brief mutateur du ieme SonCourt
 * @param Musique *musique,FMOD_SOUND* unSon,int i
 */
void MusiqueSetIemeSonCourt(Musique *musique,FMOD_SOUND* unSon,int i);
/**
 * \fn MusiqueSetIemeMusiqueDuJeu
 * @brief mutateur de la ieme musique du Jeu
 * @param Musique *musique,FMOD_SOUND* unSon,int i
 */
void MusiqueSetIemeMusiqueDuJeu(Musique *musique,FMOD_SOUND* unSon,int i);

/**
 * \fn MusiqueSetSonCourt
 * @brief fonction qui affecte une tableau de sonsCourt au champs sonCourt de la structure musique
 * @param Musique *musique,FMOD_SOUND **SonCourt
 */
void MusiqueSetSonCourt(Musique *musique,FMOD_SOUND **SonCourt);
/**
 * \fn MusiqueSetMusiqueDuJeu
 * @brief fonction qui affecte une tablau de musique au champs musique de jeu
 * @param Musique *musique,FMOD_SOUND **musiqueDuJeu
 */
void MusiqueSetMusiqueDuJeu(Musique *musique,FMOD_SOUND **musiqueDuJeu);
/**
 * \fn MusiqueConstructeur
 * @brief constructeur du Musique
 * @param Musique *musique
 */
void MusiqueConstructeur(Musique *musique);
/**
 * \fn MusiqueDestructeur
 * @brief Destructeur du Musique
 * @param Musique *musique
 */
void MusiqueDestructeur(Musique *musique);
/**
 * \fn JouerIemeSonCourt
 * @brief fonction qui joue le Ieme son Court
 * @param Musique *musique,int i
 */
void JouerIemeSonCourt(Musique *musique,int i);
/**
 * \fn JouerIemeSonCourt
 * @brief fonction qui joue la Ieme Musique
 * @param Musique *musique,int i,int repetition
 */
void JouerIemeMusique(Musique *musique,int i,int repetition);
/**
 * \fn MusiqueTestRegression
 * @brief fonction qui teste le Module
 */
void MusiqueTestRegression();


#endif
