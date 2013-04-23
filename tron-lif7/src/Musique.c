#include <stdio.h>
#include <stdlib.h>
#include "Musique.h"
#include "../lib/FMOD/inc/fmod.h"
#include "Constantes.h"


FMOD_SYSTEM* MusiqueGetBaseDuSon(Musique *musique){
    return musique->baseDuSon;
}
FMOD_SOUND* MusiqueGetIemeSonCourt(Musique *musique,int i){
    return (musique->sonCourt)[i];
}
FMOD_SOUND* MusiqueGetIemeMusiqueDuJeu(Musique *musique,int i){
    return (musique->musiqueDuJeu)[i];
}


void MusiqueSetBaseDuSon(Musique *musique,FMOD_SYSTEM *baseDuSon){
    musique->baseDuSon=baseDuSon;
}
void MusiqueSetIemeSonCourt(Musique *musique,FMOD_SOUND* unSon,int i){
    (musique->sonCourt)[i]=unSon;
}
void MusiqueSetSonCourt(Musique *musique,FMOD_SOUND **SonCourt){
    musique->sonCourt=SonCourt;
}
void MusiqueSetIemeMusiqueDuJeu(Musique *musique,FMOD_SOUND* unSon,int i){
    (musique->musiqueDuJeu)[i]=unSon;
}
void MusiqueSetMusiqueDuJeu(Musique *musique,FMOD_SOUND **musiqueDuJeu){
    musique->musiqueDuJeu=musiqueDuJeu;
}


void MusiqueConstructeur(Musique*musique){
    FMOD_RESULT resultat;
    FMOD_SYSTEM *baseDuSon;
    FMOD_SOUND** sonCourt=(FMOD_SOUND **)malloc(_Nombre_De_Bruitages*sizeof(FMOD_SOUND *));
    FMOD_SOUND** musiqueDuJeu=(FMOD_SOUND**)malloc(_Nombre_De_Musique*sizeof(FMOD_SOUND *));

    FMOD_System_Create(&baseDuSon);
    FMOD_System_Init(baseDuSon, 5, FMOD_INIT_NORMAL, NULL);
    resultat=FMOD_System_CreateSound(baseDuSon, "data/Sons/sonDestruction.wav", FMOD_CREATESAMPLE, 0,sonCourt+0);
    if(resultat!=FMOD_OK){
        printf("Erreur chargement fichier du son court\n");
    }
    FMOD_System_CreateSound(baseDuSon, "data/Sons/Get_Lucky", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM,
                             0, musiqueDuJeu+0);
    resultat=FMOD_System_CreateSound(baseDuSon, "data/Sons/TGHC", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM,
                             0, musiqueDuJeu+1);
    if(resultat!=FMOD_OK){
        printf("Erreur chargement fichier du son court\n");
    }
    FMOD_System_CreateSound(baseDuSon, "data/Sons/Derezzed", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM,
                             0, musiqueDuJeu+2);

    MusiqueSetBaseDuSon(musique,baseDuSon);
    MusiqueSetSonCourt(musique,sonCourt);
    MusiqueSetMusiqueDuJeu(musique,musiqueDuJeu);
}

void MusiqueDestructeur(Musique *musique){
    int i;
    for(i=0;i<_Nombre_De_Bruitages;i++){
        FMOD_Sound_Release(MusiqueGetIemeSonCourt(musique,i));
    }
    free(musique->sonCourt);
    for(i=0;i<_Nombre_De_Musique;i++){
        FMOD_Sound_Release(MusiqueGetIemeMusiqueDuJeu(musique,i));
    }
    free(musique->musiqueDuJeu);
    FMOD_System_Close(MusiqueGetBaseDuSon(musique));
    FMOD_System_Release(MusiqueGetBaseDuSon(musique));
}

void JouerIemeSonCourt(Musique *musique,int i){
    FMOD_System_PlaySound(MusiqueGetBaseDuSon(musique), FMOD_CHANNEL_FREE,MusiqueGetIemeSonCourt(musique,i), 0, NULL);
}
void JouerIemeMusique(Musique *musique,int i,int repetition){
    FMOD_System_PlaySound(MusiqueGetBaseDuSon(musique), FMOD_CHANNEL_FREE,MusiqueGetIemeMusiqueDuJeu(musique,i), 0, NULL);
    FMOD_Sound_SetLoopCount(MusiqueGetIemeMusiqueDuJeu(musique,i), repetition);
}


void MusiqueTestRegression(){
    Musique uneMusique;
    MusiqueConstructeur(&uneMusique);
    JouerIemeSonCourt(&uneMusique,0);
    MusiqueDestructeur(&uneMusique);
}
