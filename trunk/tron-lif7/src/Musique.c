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
void MusiqueSetBaseDuSon(Musique *musique,FMOD_SYSTEM *baseDuSon){
    musique->baseDuSon=baseDuSon;
}

void MusiqueSetIemeSonCourt(Musique *musique,FMOD_SOUND* unSon,int i){
    (musique->sonCourt)[i]=unSon;
}
void MusiqueSetSonCourt(Musique *musique,FMOD_SOUND **SonCourt){
    musique->sonCourt=SonCourt;
}

void MusiqueConstructeur(Musique *musique){
    FMOD_SYSTEM *baseDuSon;
    FMOD_SOUND** sonCourt=(FMOD_SOUND **)malloc(_Nombre_De_Musique*sizeof(FMOD_SOUND *));
    FMOD_System_Create(&baseDuSon);
    FMOD_System_Init(baseDuSon, 2, FMOD_INIT_NORMAL, NULL);
    MusiqueSetBaseDuSon(musique,baseDuSon);
    MusiqueSetSonCourt(musique,sonCourt);
    FMOD_System_CreateSound(MusiqueGetBaseDuSon(musique), "/data/sonDestruction.wav", FMOD_CREATESAMPLE, 0,musique->sonCourt);
}

void MusiqueDestructeur(Musique *musique){
    FMOD_Sound_Release(*(musique->sonCourt));
    FMOD_System_Close(MusiqueGetBaseDuSon(musique));
    FMOD_System_Release(MusiqueGetBaseDuSon(musique));
}

void JouerIemeSonCourt(Musique *musique,int i){
    FMOD_System_PlaySound(MusiqueGetBaseDuSon(musique), FMOD_CHANNEL_FREE,MusiqueGetIemeSonCourt(musique,i), 0, NULL);
}

void MusiqueTestRegression(){
    Musique uneMusique;
    MusiqueConstructeur(&uneMusique);
    JouerIemeSonCourt(&uneMusique,0);
    MusiqueDestructeur(&uneMusique);
}
