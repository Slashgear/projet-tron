/**
	\file [SDL.c]
	 Module qui gère les affichage du jeu,ainsi que les manettes
	\author {Antoine.C,Matthieu.B}
	\version 0.1
	\date 19 mars 2013
*/
#include "Jeu.h"
#include "SDL.h"
#include <assert.h>
#include <SDL/SDL.h>
#include <time.h>
#include "Joystick.h"
#include <SDL/SDL_ttf.h>
#include <string.h>


Jeu* SDLGetJeu(SDL* sdl){
    return &(sdl->jeu);
}
SDL_Surface * SDLGetIemeTexture(const SDL* sdl,unsigned int i){
    return sdl->textures[i];
}
Manette* SDLGetIemeManette(const SDL* sdl,unsigned int i){
    return (sdl->mesManettes)+i;
}
SDL_Surface * SDLGetTextures(const SDL* sdl){
    return sdl->textures[0];
}

void SDLSetJeu(SDL * sdl,Jeu* jeu){
    sdl->jeu= *jeu;
}
void SDLSetIemeTexture(SDL *sdl,unsigned int i,SDL_Surface * texture){
    sdl->textures[i]=texture;
}




SDL_Surface* SDLChargeImage(const char* nomfichier){
	/**!< Temporary storage for the image that's loaded */
	SDL_Surface* loadedImage = NULL;

	/**!< Load the image */
	loadedImage = SDL_LoadBMP( nomfichier );

	/**!< If nothing went wrong in loading the image */
	if ( loadedImage == NULL ) printf("image non chargée ! %s \n",nomfichier);


	/**!< Return the optimized image */
	return loadedImage;
}

void SDLAppliqueSurface(SDL_Surface * surfaceA, SDL_Surface * surfaceB,const int positionX,const int positionY){
	/**!< Make a temporary rectangle to hold the offsets */
	SDL_Rect offset;

	/**!< Give the offsets to the rectangle */
	offset.x = positionX;
	offset.y = positionY;

	/**!< Blit the surface */
	SDL_BlitSurface( surfaceA, NULL, surfaceB, &offset );
}



void SDLConstructeur(SDL *sdl,SDL_Surface* ecran,Jeu* jeu,Manette *manettes){
    SDLSetJeu(sdl,jeu);
    SDLSetIemeTexture(sdl,0,ecran);
    SDLSetIemeTexture(sdl,1,SDLChargeImage("data/images/grid.bmp"));
    SDLSetIemeTexture(sdl,2,SDLChargeImage("data/images/moto1H.bmp"));
    SDLSetIemeTexture(sdl,3,SDLChargeImage("data/images/moto1B.bmp"));
    SDLSetIemeTexture(sdl,4,SDLChargeImage("data/images/moto1G.bmp"));
    SDLSetIemeTexture(sdl,5,SDLChargeImage("data/images/moto1D.bmp"));
    SDLSetIemeTexture(sdl,6,SDLChargeImage("data/images/moto2H.bmp"));
    SDLSetIemeTexture(sdl,7,SDLChargeImage("data/images/moto2B.bmp"));
    SDLSetIemeTexture(sdl,8,SDLChargeImage("data/images/moto2G.bmp"));
    SDLSetIemeTexture(sdl,9,SDLChargeImage("data/images/moto2D.bmp"));
    if(_Nombre_de_Joueur>=3){
        SDLSetIemeTexture(sdl,10,SDLChargeImage("data/images/moto3H.bmp"));
        SDLSetIemeTexture(sdl,11,SDLChargeImage("data/images/moto3B.bmp"));
        SDLSetIemeTexture(sdl,12,SDLChargeImage("data/images/moto3G.bmp"));
        SDLSetIemeTexture(sdl,13,SDLChargeImage("data/images/moto3D.bmp"));
    }
    if(_Nombre_de_Joueur>=4){
        SDLSetIemeTexture(sdl,14,SDLChargeImage("data/images/moto4H.bmp"));
        SDLSetIemeTexture(sdl,15,SDLChargeImage("data/images/moto4B.bmp"));
        SDLSetIemeTexture(sdl,16,SDLChargeImage("data/images/moto4G.bmp"));
        SDLSetIemeTexture(sdl,17,SDLChargeImage("data/images/moto4D.bmp"));
    }
    if(_Nombre_de_Joueur>=5){
        SDLSetIemeTexture(sdl,18,SDLChargeImage("data/images/moto5H.bmp"));
        SDLSetIemeTexture(sdl,19,SDLChargeImage("data/images/moto5B.bmp"));
        SDLSetIemeTexture(sdl,20,SDLChargeImage("data/images/moto5G.bmp"));
        SDLSetIemeTexture(sdl,21,SDLChargeImage("data/images/moto5D.bmp"));
    }
    if(_Nombre_de_Joueur>=6){
        SDLSetIemeTexture(sdl,22,SDLChargeImage("data/images/moto6H.bmp"));
        SDLSetIemeTexture(sdl,23,SDLChargeImage("data/images/moto6B.bmp"));
        SDLSetIemeTexture(sdl,24,SDLChargeImage("data/images/moto6G.bmp"));
        SDLSetIemeTexture(sdl,25,SDLChargeImage("data/images/moto6D.bmp"));
    }
    if(_Nombre_de_Joueur>=7){
        SDLSetIemeTexture(sdl,26,SDLChargeImage("data/images/moto7H.bmp"));
        SDLSetIemeTexture(sdl,27,SDLChargeImage("data/images/moto7B.bmp"));
        SDLSetIemeTexture(sdl,28,SDLChargeImage("data/images/moto7G.bmp"));
        SDLSetIemeTexture(sdl,29,SDLChargeImage("data/images/moto7D.bmp"));
    }
    if(_Nombre_de_Joueur>=8){
        SDLSetIemeTexture(sdl,30,SDLChargeImage("data/images/moto8H.bmp"));
        SDLSetIemeTexture(sdl,31,SDLChargeImage("data/images/moto8B.bmp"));
        SDLSetIemeTexture(sdl,32,SDLChargeImage("data/images/moto8G.bmp"));
        SDLSetIemeTexture(sdl,33,SDLChargeImage("data/images/moto8D.bmp"));
    }
    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4,SDLChargeImage("data/images/BonusNettoyage.bmp"));
    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+1,SDLChargeImage("data/images/BonusBoost.bmp"));
    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+2,SDLChargeImage("data/images/BonusSaut.bmp"));
    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus,SDLChargeImage("data/images/Tron.bmp"));
    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+1,SDLChargeImage("data/images/Interface.bmp"));
    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface,NULL);
    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+1,NULL);
    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+2,NULL);
    sdl->mesManettes=manettes;
    sdl->police=TTF_OpenFont("data/Font/Downlink.ttf",18);
    sdl->policeGrandsMessages=TTF_OpenFont("data/Font/Downlink.ttf",50);

}

void SDLDestructeur(SDL *sdl){
    int i;
    for(i=0;i<(2+4*_Nombre_de_Joueur+_Nombre_Type_Bonus+_Nombre_Images_Interface+_Nombre_de_Textes);i++){
        SDL_FreeSurface(SDLGetIemeTexture(sdl,i));
        SDLSetIemeTexture(sdl,i,NULL);
    }
    JeuDestructeur(SDLGetJeu(sdl));
    for(i=0;i<_Nombre_de_Manette;i++){
        detruireManette(SDLGetIemeManette(sdl,i));
    }
    free(sdl->mesManettes);
    sdl->mesManettes=NULL;
    TTF_CloseFont(sdl->police);
    TTF_CloseFont(sdl->policeGrandsMessages);
}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}

void SDLIntro(short int *jeuReInit,SDL_Surface* ecran){
    SDL_Event evenement;
    SDL_Surface* pageAccueil=SDLChargeImage("data/images/TitreAcceuilTron.bmp");
    SDLAppliqueSurface(pageAccueil,ecran,0,0);
    SDL_free(pageAccueil);
    SDL_Flip(ecran);
    do{
        SDL_WaitEvent(&evenement);
    }while(!((evenement.type==SDL_MOUSEBUTTONDOWN)&&(evenement.button.button==SDL_BUTTON_LEFT)&&
           (((evenement.button.x>=447)&&(evenement.button.x<=447+360)&&
             (evenement.button.y>=341)&&(evenement.button.y<=341+90))||
            ((evenement.button.x>=449)&&(evenement.button.x<=449+360)&&
             (evenement.button.y>=461)&&(evenement.button.y<=461+90)))));
    if((evenement.button.x>=449)&&(evenement.button.x<=449+360)&&
             (evenement.button.y>=461)&&(evenement.button.y<=461+90)){
        *jeuReInit=0;
    }
}

void SDLDecompte(SDL *sdl){
	int i=3;
	char decompte[10];
	SDL_Color couleur;
    couleur.r=255;
    couleur.g=255;
    couleur.b=255;
    Uint32 uneSeconde=1000;
    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+3,NULL);
	while(i>0){
        SDLAfficheJeu(sdl);
		sprintf(decompte,"%d",i);
		SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+3,
                        TTF_RenderText_Blended(sdl->policeGrandsMessages,decompte
                        ,couleur));
        SDLAppliqueSurface(SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+3),
                            SDLGetIemeTexture(sdl,0),
                            500,350);
        SDL_Flip(SDLGetIemeTexture(sdl,0));
        SDL_Delay(uneSeconde);
        i--;
	}
}

void SDLJeuInitN(SDL *sdl, int* scores,SDL_Surface* ecran){
    int i;
    short int nbJoueurClavier=_Nombre_de_Joueur-_Nombre_de_Manette-_Nombre_IA;
    Jeu jeu;
    Grid grille;
    TableauDynamiqueMur TabDynMurMurs;
    Controle unControle;
    Moto uneMoto;
    Joueur unJoueur;
    Manette uneManette;
    Joueur *mesJoueurs=(Joueur*)malloc(_Nombre_de_Joueur*sizeof(Joueur));
    Manette *mesManettes=(Manette*)malloc(_Nombre_de_Manette*sizeof(Manette));

    SDL_JoystickEventState(SDL_ENABLE);
    assert((_Nombre_de_Joueur<=8)&&(_Nombre_de_Joueur>0)&&(_Nombre_de_Manette<=4)&&(_Nombre_de_Manette>=0)&&
           (nbJoueurClavier<=4)&&(nbJoueurClavier>=0)&&(SDL_NumJoysticks()>=_Nombre_de_Manette)&&
           (_Duree_Vie_Mur>=0)&&(_Acceleration>=0)&&(_Vitesse_Initiale>=0)&&(_Nombre_de_Bonus>=0)&&
           (_Nombre_IA>=0)&&(_Nombre_IA<_Nombre_de_Joueur));

    for(i=0;i<nbJoueurClavier;i++){
        if(_Nombre_de_Joueur<=4){
            if(i==0){
                ControleConstructeur(&unControle,'z','s','q','d','a');
                MotoConstructeur(&uneMoto,498,50,5,10,_Vitesse_Initiale,BAS);
                JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ORANGE,VIVANT,AUCUN,-1,i+1,0);
            }
            else if(i==1){
                    ControleConstructeur(&unControle,'o','l','k','m','i');
                    MotoConstructeur(&uneMoto,503,650,5,10,_Vitesse_Initiale,HAUT);
                    JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLEU,VIVANT,AUCUN,-1,i+1,0);
                }
                else if(i==2){
                        ControleConstructeur(&unControle,SDLK_t,SDLK_g,SDLK_f,SDLK_h,SDLK_r);
                        MotoConstructeur(&uneMoto,200,355,10,5,_Vitesse_Initiale,DROITE);
                        JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ROUGE,VIVANT,AUCUN,-1,i+1,0);
                    }
                    else if(i==3){
                            ControleConstructeur(&unControle,SDLK_UP,SDLK_DOWN,SDLK_LEFT,SDLK_RIGHT,SDLK_END);
                            MotoConstructeur(&uneMoto,800,350,10,5,_Vitesse_Initiale,GAUCHE);
                            JoueurConstructeur(&unJoueur,&uneMoto,&unControle,VERT,VIVANT,AUCUN,-1,i+1,0);
                        }
        }
        else{
            if(i==0){
                ControleConstructeur(&unControle,'z','s','q','d','a');
                MotoConstructeur(&uneMoto,403,50,5,10,_Vitesse_Initiale,BAS);
                JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ORANGE,VIVANT,AUCUN,-1,i+1,0);
            }
            else if(i==1){
                    ControleConstructeur(&unControle,'o','l','k','m','i');
                    MotoConstructeur(&uneMoto,809,253,10,5,_Vitesse_Initiale,GAUCHE);
                    JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLEU,VIVANT,AUCUN,-1,i+1,0);
                }
                else if(i==2){
                        ControleConstructeur(&unControle,SDLK_t,SDLK_g,SDLK_f,SDLK_h,SDLK_r);
                        MotoConstructeur(&uneMoto,603,660,5,10,_Vitesse_Initiale,HAUT);
                        JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ROUGE,VIVANT,AUCUN,-1,i+1,0);
                    }
                    else if(i==3){
                            ControleConstructeur(&unControle,SDLK_UP,SDLK_DOWN,SDLK_LEFT,SDLK_RIGHT,SDLK_END);
                            MotoConstructeur(&uneMoto,200,456,10,5,_Vitesse_Initiale,DROITE);
                            JoueurConstructeur(&unJoueur,&uneMoto,&unControle,VERT,VIVANT,AUCUN,-1,i+1,0);
                        }
        }
        mesJoueurs[i]=unJoueur;
    }
    for(i=nbJoueurClavier;i<_Nombre_de_Joueur-_Nombre_IA;i++){
        if(_Nombre_de_Joueur<=4){
            if(i==0){
                ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                MotoConstructeur(&uneMoto,498,50,5,10,_Vitesse_Initiale,BAS);
                initialiserManette(&uneManette,i-nbJoueurClavier);
                JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ORANGE,VIVANT,AUCUN,i-nbJoueurClavier,i+1,0);
            }
            else if(i==1){
                    ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                    MotoConstructeur(&uneMoto,503,650,5,10,_Vitesse_Initiale,HAUT);
                    initialiserManette(&uneManette,i-nbJoueurClavier);
                    JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLEU,VIVANT,AUCUN,i-nbJoueurClavier,i+1,0);
                }
                else if(i==2){
                        ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                        MotoConstructeur(&uneMoto,200,355,10,5,_Vitesse_Initiale,DROITE);
                        initialiserManette(&uneManette,i-nbJoueurClavier);
                        JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ROUGE,VIVANT,AUCUN,i-nbJoueurClavier,i+1,0);
                    }
                    else if(i==3){
                            ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                            MotoConstructeur(&uneMoto,800,350,10,5,_Vitesse_Initiale,GAUCHE);
                            initialiserManette(&uneManette,i-nbJoueurClavier);
                            JoueurConstructeur(&unJoueur,&uneMoto,&unControle,VERT,VIVANT,AUCUN,i-nbJoueurClavier,i+1,0);
                        }
        }
        else {
            if(i==0){
                ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                MotoConstructeur(&uneMoto,403,50,5,10,_Vitesse_Initiale,BAS);
                initialiserManette(&uneManette,i-nbJoueurClavier);
                JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ORANGE,VIVANT,AUCUN,i-nbJoueurClavier,i+1,0);
            }
            else if(i==1){
                    ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                    MotoConstructeur(&uneMoto,809,253,10,5,_Vitesse_Initiale,GAUCHE);
                    initialiserManette(&uneManette,i-nbJoueurClavier);
                    JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLEU,VIVANT,AUCUN,i-nbJoueurClavier,i+1,0);
                }
                else if(i==2){
                        ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                        MotoConstructeur(&uneMoto,603,660,5,10,_Vitesse_Initiale,HAUT);
                        initialiserManette(&uneManette,i-nbJoueurClavier);
                        JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ROUGE,VIVANT,AUCUN,i-nbJoueurClavier,i+1,0);
                    }
                    else if(i==3){
                            ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                            MotoConstructeur(&uneMoto,200,456,10,5,_Vitesse_Initiale,DROITE);
                            initialiserManette(&uneManette,i-nbJoueurClavier);
                            JoueurConstructeur(&unJoueur,&uneMoto,&unControle,VERT,VIVANT,AUCUN,i-nbJoueurClavier,i+1,0);
                        }
                        else if(i==4){
                                ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                                MotoConstructeur(&uneMoto,606,50,5,10,_Vitesse_Initiale,BAS);
                                initialiserManette(&uneManette,i-nbJoueurClavier);
                                JoueurConstructeur(&unJoueur,&uneMoto,&unControle,VIOLET,VIVANT,AUCUN,i-nbJoueurClavier,i+1,0);
                            }
                            else if(i==5){
                                    ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                                    MotoConstructeur(&uneMoto,403,660,5,10,_Vitesse_Initiale,HAUT);
                                    initialiserManette(&uneManette,i-nbJoueurClavier);
                                    JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLEUF,VIVANT,AUCUN,
                                                       i-nbJoueurClavier,i+1,0);
                                }
                                else if(i==6){
                                        ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                                        MotoConstructeur(&uneMoto,200,253,10,5,_Vitesse_Initiale,DROITE);
                                        initialiserManette(&uneManette,i-nbJoueurClavier);
                                        JoueurConstructeur(&unJoueur,&uneMoto,&unControle,JAUNE,VIVANT,AUCUN,
                                                           i-nbJoueurClavier,i+1,0);
                                    }
                                    else if(i==7){
                                            ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                                            MotoConstructeur(&uneMoto,809,456,10,5,_Vitesse_Initiale,GAUCHE);
                                            initialiserManette(&uneManette,i-nbJoueurClavier);
                                            JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLANC,VIVANT,AUCUN,
                                                               i-nbJoueurClavier,i+1,0);
                                        }
        }
        mesManettes[i-nbJoueurClavier]=uneManette;
        mesJoueurs[i]=unJoueur;
    }
    for(i=_Nombre_de_Joueur-_Nombre_IA;i<_Nombre_de_Joueur;i++){
        if(_Nombre_de_Joueur<=4){
            if(i==0){
                ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                MotoConstructeur(&uneMoto,498,50,5,10,_Vitesse_Initiale,BAS);
                JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ORANGE,VIVANT,AUCUN,-1,i+1,1);
            }
            else if(i==1){
                    ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                    MotoConstructeur(&uneMoto,503,650,5,10,_Vitesse_Initiale,HAUT);
                    JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLEU,VIVANT,AUCUN,-1,i+1,1);
                }
                else if(i==2){
                        ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                        MotoConstructeur(&uneMoto,200,355,10,5,_Vitesse_Initiale,DROITE);
                        JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ROUGE,VIVANT,AUCUN,-1,i+1,1);
                    }
                    else if(i==3){
                            ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                            MotoConstructeur(&uneMoto,800,350,10,5,_Vitesse_Initiale,GAUCHE);
                            JoueurConstructeur(&unJoueur,&uneMoto,&unControle,VERT,VIVANT,AUCUN,-1,i+1,1);
                        }
        }
        else{
            if(i==1){
                ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                MotoConstructeur(&uneMoto,809,253,10,5,_Vitesse_Initiale,GAUCHE);
                JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLEU,VIVANT,AUCUN,-1,i+1,1);
            }
            else if(i==2){
                    ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                    MotoConstructeur(&uneMoto,603,660,5,10,_Vitesse_Initiale,HAUT);
                    JoueurConstructeur(&unJoueur,&uneMoto,&unControle,ROUGE,VIVANT,AUCUN,-1,i+1,1);
                }
                else if(i==3){
                        ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                        MotoConstructeur(&uneMoto,200,456,10,5,_Vitesse_Initiale,DROITE);
                        JoueurConstructeur(&unJoueur,&uneMoto,&unControle,VERT,VIVANT,AUCUN,-1,i+1,1);
                    }
                    else if(i==4){
                            ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                            MotoConstructeur(&uneMoto,606,50,5,10,_Vitesse_Initiale,BAS);
                            JoueurConstructeur(&unJoueur,&uneMoto,&unControle,VIOLET,VIVANT,AUCUN,-1,i+1,1);
                        }
                        else if(i==5){
                                ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                                MotoConstructeur(&uneMoto,403,660,5,10,_Vitesse_Initiale,HAUT);
                                JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLEUF,VIVANT,AUCUN,
                                                   -1,i+1,1);
                            }
                            else if(i==6){
                                    ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                                    MotoConstructeur(&uneMoto,200,253,10,5,_Vitesse_Initiale,DROITE);
                                    JoueurConstructeur(&unJoueur,&uneMoto,&unControle,JAUNE,VIVANT,AUCUN,
                                                       -1,i+1,1);
                                }
                                else if(i==7){
                                        ControleConstructeur(&unControle,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7,SDLK_F7);
                                        MotoConstructeur(&uneMoto,809,456,10,5,_Vitesse_Initiale,GAUCHE);
                                        JoueurConstructeur(&unJoueur,&uneMoto,&unControle,BLANC,VIVANT,AUCUN,
                                                           -1,i+1,1);
                                    }
        }
        mesJoueurs[i]=unJoueur;
    }

    GridConstructeur(&grille,5,5,1000,700,&TabDynMurMurs);
    JeuConstructeur(&jeu,&grille,mesJoueurs,scores);
    SDLConstructeur(sdl,ecran,&jeu,mesManettes);
    ecran=SDLGetIemeTexture(sdl,0);
    SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,0,0,0));
    SDLSetIemeTexture(sdl,0,ecran);
}

void SDLBoucleJeu(SDL* sdl, short int *jeuReInit){
    short int jeuFini = 0;
    int i;
    SDL_Event evenement;
    float horloge_courante, horloge_precedente;
    float intervalle_horloge=0.05f;
    int affAJour;
    Controle* unControle;
    Manette* uneManette;
    int nbJoueurClavier=_Nombre_de_Joueur-_Nombre_de_Manette-_Nombre_IA;
    int indiceGagnant=-1;
    int scoreGagnant=0;
    short int boolGagnant=0;
    int *scores=JeuGetScores(SDLGetJeu(sdl));

    char commentaire[50]={0};
    char commentaireNull[50]={0};
    Couleur uneCouleur=NOIR;
    SDL_Color couleur;

    couleur.r=255;
    couleur.g=255;
    couleur.b=255;
    SDLAfficheJeu(sdl);
    assert(SDL_Flip(SDLGetIemeTexture(sdl,0)) != -1);
    horloge_precedente = (float)clock()/(float) CLOCKS_PER_SEC;

    while(jeuFini==0){
        affAJour = 1;
        horloge_courante = (float)clock()/(float) CLOCKS_PER_SEC;
        if(horloge_courante-horloge_precedente >= intervalle_horloge){
            strcpy(commentaire,commentaireNull);
            JeuEvolue(SDLGetJeu(sdl),&jeuFini,commentaire,&uneCouleur);
            if(strcmp(commentaire,commentaireNull)!=0)/**!<Si le jeu a renvoyé un nouveau commentaire*/
            {SDLAfficheTextes(sdl,commentaire,uneCouleur);}
            affAJour = 0;
            horloge_precedente = horloge_courante;
        }
        while ( SDL_PollEvent( &evenement ) ){
            if ( evenement.type == SDL_QUIT ){
				affAJour = 0;
            }
            if (evenement.type == SDL_KEYDOWN){
                if(evenement.key.keysym.sym==SDLK_ESCAPE){
                    jeuFini=1;
                    *jeuReInit=0;
                }
                for(i=0;(i<nbJoueurClavier);i++){
                    if(JoueurGetEnJeu(JeuGetIemeJoueurs(SDLGetJeu(sdl),i))==1){
                        unControle=JoueurGetControle(JeuGetIemeJoueurs(SDLGetJeu(sdl),i));
                        if(evenement.key.keysym.sym==ControleGetHaut(unControle)){
                            JeuActionClavier(JeuGetIemeJoueurs(SDLGetJeu(sdl),i),
                                                HAUT,JeuGetGrille(SDLGetJeu(sdl)));
                            affAJour = 0;
                        }
                        else  if(evenement.key.keysym.sym==ControleGetBas(unControle)){
                                JeuActionClavier( JeuGetIemeJoueurs(SDLGetJeu(sdl),i),
                                                BAS,JeuGetGrille(SDLGetJeu(sdl)));
                                affAJour = 0;
                            }
                            else if(evenement.key.keysym.sym==ControleGetGauche(unControle)){
                                    JeuActionClavier( JeuGetIemeJoueurs(SDLGetJeu(sdl),i),
                                                        GAUCHE,JeuGetGrille(SDLGetJeu(sdl)));
                                    affAJour = 0;
                                    }
                                    else if(evenement.key.keysym.sym==ControleGetDroite(unControle)){
                                            JeuActionClavier( JeuGetIemeJoueurs(SDLGetJeu(sdl),i),
                                                             DROITE,JeuGetGrille(SDLGetJeu(sdl)));
                                            affAJour = 0;
                                        }
                                        else if(evenement.key.keysym.sym==ControleGetBonus(unControle)){
                                                JeuActionneBonus(JeuGetIemeJoueurs(SDLGetJeu(sdl),i));
                                                affAJour=0;
                                        }
                    }
                }

            }

            for(i=0;i<_Nombre_de_Manette;i++){
                uneManette=SDLGetIemeManette(sdl,i);
                updateEvent(uneManette,evenement);
                if(uneManette->boutons[3]){
                    SDLActionManette(JeuGetIemeJoueurs(SDLGetJeu(sdl),nbJoueurClavier+i),HAUT,JeuGetGrille(SDLGetJeu(sdl)));
                    uneManette->boutons[3]=0;
                    affAJour = 0;
                }
                if(uneManette->boutons[0]){
                    SDLActionManette(JeuGetIemeJoueurs(SDLGetJeu(sdl),nbJoueurClavier+i),BAS,JeuGetGrille(SDLGetJeu(sdl)));
                    uneManette->boutons[0]=0;
                    affAJour = 0;
                }
                if((uneManette->boutons[2])){
                    SDLActionManette(JeuGetIemeJoueurs(SDLGetJeu(sdl),nbJoueurClavier+i),GAUCHE,JeuGetGrille(SDLGetJeu(sdl)));
                    uneManette->boutons[2]=0;
                    affAJour = 0;
                }
                if(uneManette->boutons[1]){
                    SDLActionManette(JeuGetIemeJoueurs(SDLGetJeu(sdl),nbJoueurClavier+i),DROITE,JeuGetGrille(SDLGetJeu(sdl)));
                    uneManette->boutons[1]=0;
                    affAJour = 0;
                }
                if(uneManette->boutons[5]){
                    JeuActionneBonus(JeuGetIemeJoueurs(SDLGetJeu(sdl),nbJoueurClavier+i));
                    uneManette->boutons[5]=0;
                    affAJour = 0;
                }
            }
        }
        if(!affAJour){
            SDLAfficheJeu(sdl);
        }
    }
    for(i=0;i<_Nombre_de_Joueur;i++){
        if(scores[i]>=_Score_de_Victoire){
            if(indiceGagnant==-1){
                indiceGagnant=i;
                scoreGagnant=scores[i];
                boolGagnant=1;
            }
            else{
                if(scoreGagnant<scores[i]){
                    indiceGagnant=i;
                    scoreGagnant=scores[i];
                    boolGagnant=1;
                }
                else if(scoreGagnant==scores[i]){
                        boolGagnant=0;
                    }
            }
        }
    }
    if(boolGagnant==0){
        SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+3,
                        TTF_RenderText_Blended(sdl->policeGrandsMessages,
                        "Manche terminee !"
                        ,couleur));
        SDLAppliqueSurface(SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+3),
                            SDLGetIemeTexture(sdl,0),
                            200,300);
        SDL_Flip(SDLGetIemeTexture(sdl,0));
        while((evenement.key.keysym.sym!=SDLK_ESCAPE)&&(evenement.key.keysym.sym!=SDLK_F1)
              &&(evenement.key.keysym.sym!=SDLK_TAB)){
            SDL_WaitEvent(&evenement);
        }
        if(evenement.key.keysym.sym==SDLK_ESCAPE){
            *jeuReInit=0;
        }
        if(evenement.key.keysym.sym==SDLK_F1){
            *jeuReInit=1;
        }
        if(evenement.key.keysym.sym==SDLK_TAB){
            for(i=0;i<_Nombre_de_Joueur;i++){
                scores[i]=0;
            }
            *jeuReInit=1;
        }
    }
    else{
        sprintf(commentaire,"Partie terminee ! Le joueur %d a gagne !",indiceGagnant+1);
        SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+3,
                        TTF_RenderText_Blended(sdl->policeGrandsMessages,
                        commentaire,couleur));
        SDLAppliqueSurface(SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+3),
                            SDLGetIemeTexture(sdl,0),
                            50,300);
        SDL_Flip(SDLGetIemeTexture(sdl,0));
        while((evenement.key.keysym.sym!=SDLK_ESCAPE)&&(evenement.key.keysym.sym!=SDLK_F1)){
            SDL_WaitEvent(&evenement);
        }
        if(evenement.key.keysym.sym==SDLK_ESCAPE){
            *jeuReInit=0;
        }
        if(evenement.key.keysym.sym==SDLK_F1){
            for(i=0;i<_Nombre_de_Joueur;i++){
                scores[i]=0;
            }
            *jeuReInit=1;
        }
    }
}

void SDLActionManette(Joueur* joueur, Direction direction,Grid* grille){
    Moto* uneMoto=JoueurGetMoto(joueur);
    unsigned int tailleTemp=MotoGetTailleX(uneMoto);
    Mur unMur;
    float dureeVieMur=_Duree_Vie_Mur;
    char directionChange=0;
    if(JoueurGetEnJeu(joueur)==VIVANT){
        if(MotoGetDirection(uneMoto)==HAUT){
            MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                                MotoGetTailleX(uneMoto),(float)MotoGetTailleY(uneMoto),
                                JoueurGetCouleur(joueur),dureeVieMur);
            if(direction==GAUCHE){
                MotoSetDirection(uneMoto,GAUCHE);
                MotoSetPositionX(uneMoto,(MotoGetPositionX(uneMoto)+(float)MotoGetTailleX(uneMoto)-(float)MotoGetTailleY(uneMoto)));
                directionChange=1;
                }
            else if(direction==DROITE){
                MotoSetDirection(uneMoto,DROITE);
                directionChange=1;
                }
            }
        else if(MotoGetDirection(uneMoto)==BAS){
                MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                                MotoGetTailleX(uneMoto),(float)MotoGetTailleY(uneMoto),
                                JoueurGetCouleur(joueur),dureeVieMur);
                if(direction==GAUCHE){
                    MotoSetDirection(uneMoto,GAUCHE);
                    MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+(float)MotoGetTailleX(uneMoto)-(float)MotoGetTailleY(uneMoto));
                    MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)MotoGetTailleY(uneMoto)-(float)MotoGetTailleX(uneMoto));
                    directionChange=1;
                }
                else if(direction==DROITE){
                    MotoSetDirection(uneMoto,DROITE);
                    MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)MotoGetTailleY(uneMoto)-(float)MotoGetTailleX(uneMoto));
                    directionChange=1;
                    }
            }
            else if(MotoGetDirection(uneMoto)==GAUCHE){
                MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                                MotoGetTailleX(uneMoto),MotoGetTailleY(uneMoto),
                                JoueurGetCouleur(joueur),dureeVieMur);
                    if(direction==HAUT){
                        MotoSetDirection(uneMoto,HAUT);
                        MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)MotoGetTailleY(uneMoto)-(float)MotoGetTailleX(uneMoto));
                        directionChange=1;
                    }
                    else if(direction==BAS){
                            MotoSetDirection(uneMoto,BAS);
                            directionChange=1;
                        }
                }
                else if(MotoGetDirection(uneMoto)==DROITE){
                        MurConstructeur(&unMur,MotoGetPositionX(uneMoto),MotoGetPositionY(uneMoto),
                                MotoGetTailleX(uneMoto),MotoGetTailleY(uneMoto),
                                JoueurGetCouleur(joueur),dureeVieMur);
                        if(direction==HAUT){
                            MotoSetDirection(uneMoto,HAUT);
                            MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+(float)MotoGetTailleX(uneMoto)-(float)MotoGetTailleY(uneMoto));
                            MotoSetPositionY(uneMoto,MotoGetPositionY(uneMoto)+(float)MotoGetTailleY(uneMoto)-(float)MotoGetTailleX(uneMoto));
                            directionChange=1;
                        }
                        else if(direction==BAS){
                                MotoSetDirection(uneMoto,BAS);
                                MotoSetPositionX(uneMoto,MotoGetPositionX(uneMoto)+(float)MotoGetTailleX(uneMoto)-(float)MotoGetTailleY(uneMoto));
                                directionChange=1;
                        }
                    }
        if(directionChange){
            MotoSetTailleX(uneMoto,MotoGetTailleY(uneMoto));
            MotoSetTailleY(uneMoto,tailleTemp);
            ajouteMur(GridGetMesMurs(grille),unMur);
            JoueurSetDernierMur(joueur,adresseIemeElementTabDynMur(GridGetMesMurs(grille),TabDynMurGetTaille_utilisee(GridGetMesMurs(grille))-1));
        }
    }
}

void SDLAfficheMotos(SDL* sdl){
    Moto *moto;
    Joueur *joueur;
    SDL_Surface * surface;
    int i;
    for(i=0;(i<_Nombre_de_Joueur);i++){
        joueur=JeuGetIemeJoueurs(SDLGetJeu(sdl),i);
        if(JoueurGetEnJeu(joueur)==VIVANT){
            moto=JoueurGetMoto(joueur);
            if((JoueurGetEffetBonus(joueur)==SAUT)&&(JoueurGetTempsBonus(joueur)<_Temps_Bonus_Saut)){
                surface=SDL_CreateRGBSurface(SDL_HWSURFACE,MotoGetTailleX(moto)+2,MotoGetTailleY(moto)+2,32,0,0,0,0);
                SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format,255,255,255));
                SDLAppliqueSurface(surface,SDLGetIemeTexture(sdl,0),MotoGetPositionX(moto)-1,MotoGetPositionY(moto)-1);
                SDL_FreeSurface(surface);
            }
            else if((JoueurGetEffetBonus(joueur)==BOOST)&&(JoueurGetTempsBonus(joueur)<_Temps_Bonus_Boost)){
                    surface=SDL_CreateRGBSurface(SDL_HWSURFACE,MotoGetTailleX(moto)+2,MotoGetTailleY(moto)+2,32,0,0,0,0);
                    SDL_FillRect(surface,NULL,SDL_MapRGB(surface->format,51,204,255));
                    SDLAppliqueSurface(surface,SDLGetIemeTexture(sdl,0),MotoGetPositionX(moto)-1,MotoGetPositionY(moto)-1);
                    SDL_FreeSurface(surface);
                }
            if(MotoGetDirection(moto)==HAUT){
                surface=SDLGetIemeTexture(sdl,2+(i*4));
            }
            else if(MotoGetDirection(moto)==BAS){
                    surface=SDLGetIemeTexture(sdl,2+(i*4)+1);
                }
                else if(MotoGetDirection(moto)==GAUCHE){
                        surface=SDLGetIemeTexture(sdl,2+(i*4)+2);
                    }
                    else if(MotoGetDirection(moto)==DROITE){
                            surface=SDLGetIemeTexture(sdl,2+(i*4)+3);
                        }

            SDLAppliqueSurface(surface,SDLGetIemeTexture(sdl,0),MotoGetPositionX(moto),MotoGetPositionY(moto));
        }
    }

}
void SDLAfficheMurs(SDL *sdl){
    SDL_Surface * surfaceMur;
    Mur* mur;
    int i;
    SDLAppliqueSurface(SDLGetIemeTexture(sdl,1),SDLGetIemeTexture(sdl,0),GridGetPositionX(JeuGetGrille(SDLGetJeu(sdl))),GridGetPositionY(JeuGetGrille(SDLGetJeu(sdl))));
    for(i=0;i<TabDynMurGetTaille_utilisee(GridGetMesMurs(JeuGetGrille(SDLGetJeu(sdl))));i++){
        mur= adresseIemeElementTabDynMur(GridGetMesMurs(JeuGetGrille(SDLGetJeu(sdl))),i);
        surfaceMur=SDL_CreateRGBSurface(SDL_HWSURFACE,MurGetTailleX(mur),MurGetTailleY(mur),32,0,0,0,0);
        if(MurGetCouleur(mur)==ORANGE){
            SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,255,204,51));
        }
        else if(MurGetCouleur(mur)==BLEU){
            SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,51,204,255));
            }
            else if(MurGetCouleur(mur)==ROUGE){
            SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,232,33,5));
            }
                else if(MurGetCouleur(mur)==VERT){
                SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,33,198,33));
                }
                    else if(MurGetCouleur(mur)==VIOLET){
                    SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,204,51,255));
                    }
                        else if(MurGetCouleur(mur)==BLEUF){
                        SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,13,24,179));
                        }
                            else if(MurGetCouleur(mur)==JAUNE){
                            SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,231,239,11));
                            }
                                else if(MurGetCouleur(mur)==BLANC){
                                SDL_FillRect(surfaceMur,NULL,SDL_MapRGB(surfaceMur->format,255,255,255));
                                }
        SDLAppliqueSurface(surfaceMur,SDLGetIemeTexture(sdl,0),(int)(MurGetPositionX(mur)/1),(int)(MurGetPositionY(mur)/1));
        SDL_FreeSurface(surfaceMur);
    }
}
void SDLAfficheBonus(SDL*sdl){
    int i;
    Bonus *unBonus;
    for(i=0;i<_Nombre_de_Bonus;i++){
        unBonus=JeuGetIemeBonus(SDLGetJeu(sdl),i);
        if(BonusGetEffetBonus(unBonus)==NETTOYAGE){
             SDLAppliqueSurface(SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4),SDLGetIemeTexture(sdl,0),
                                BonusGetPositionX(unBonus),BonusGetPositionY(unBonus));
        }
        if(BonusGetEffetBonus(unBonus)==BOOST){
            SDLAppliqueSurface(SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+1),SDLGetIemeTexture(sdl,0),
                                BonusGetPositionX(unBonus),BonusGetPositionY(unBonus));
        }
        if(BonusGetEffetBonus(unBonus)==SAUT){
            SDLAppliqueSurface(SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+2),SDLGetIemeTexture(sdl,0),
                                BonusGetPositionX(unBonus),BonusGetPositionY(unBonus));
        }
    }
}

void SDLAfficheInterface(SDL *sdl){
    SDL_Surface* surfaceTexte;
    SDLAppliqueSurface(SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus),
                       SDLGetIemeTexture(sdl,0),1010,5);
    SDLAppliqueSurface(SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+1),
                       SDLGetIemeTexture(sdl,0),1010,150);
    surfaceTexte=SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface);
    if(surfaceTexte!=NULL){
        SDLAppliqueSurface(surfaceTexte,SDLGetIemeTexture(sdl,0),1015,152);
    }
    surfaceTexte=SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+1);
    if(surfaceTexte!=NULL){
        SDLAppliqueSurface(surfaceTexte,SDLGetIemeTexture(sdl,0),1015,179);
    }
    surfaceTexte=SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+2);
    if(surfaceTexte!=NULL){
        SDLAppliqueSurface(surfaceTexte,SDLGetIemeTexture(sdl,0),1015,206);
    }
}

void SDLAfficheTextes(SDL *sdl,char *chaineDeCaractere,Couleur uneCouleur){
    SDL_Color couleur;
    switch(uneCouleur){
        case NOIR:
            couleur.r=255;
            couleur.g=255;
            couleur.b=255;
            break;
        case BLEU:
            couleur.r=51;
            couleur.g=204;
            couleur.b=255;
            break;
        case ORANGE:
            couleur.r=255;
            couleur.g=204;
            couleur.b=51;
            break;
        case ROUGE:
            couleur.r=232;
            couleur.g=33;
            couleur.b=5;
            break;
        case VERT:
            couleur.r=33;
            couleur.g=198;
            couleur.b=33;
            break;
        case VIOLET:
            couleur.r=204;
            couleur.g=51;
            couleur.b=255;
            break;
        case BLEUF:
            couleur.r=13;
            couleur.g=24;
            couleur.b=179;
            break;
        case JAUNE:
            couleur.r=231;
            couleur.g=239;
            couleur.b=11;
            break;
        case BLANC:
            couleur.r=255;
            couleur.g=255;
            couleur.b=255;
            break;
        default:
            break;
    }
    if(SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface)==NULL){
        SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface,
            TTF_RenderText_Blended(sdl->police,chaineDeCaractere,couleur));
    }else if(SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+1)==NULL){
            SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+1,
                TTF_RenderText_Blended(sdl->police,chaineDeCaractere,couleur));
            }else{
                if(SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+2)==NULL){
                    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+2,
                        TTF_RenderText_Blended(sdl->police,chaineDeCaractere,couleur));
                }
                else{
                    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface,
                        SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+1));
                    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+1,
                        SDLGetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+2));
                    SDLSetIemeTexture(sdl,2+_Nombre_de_Joueur*4+_Nombre_Type_Bonus+_Nombre_Images_Interface+2,
                        TTF_RenderText_Blended(sdl->police,chaineDeCaractere,couleur));
                }
            }
}

void SDLAfficheScores(SDL *sdl){
    SDL_Surface * uneSurface;
    short int i,largeurBarre,positionXBarre;
    float pourcentage,positionYBarre,hauteur;
    Couleur uneCouleur;
    int *scores=JeuGetScores(SDLGetJeu(sdl));
    uneSurface=SDL_CreateRGBSurface(SDL_HWSURFACE,270,3,32,0,0,0,0);
    SDL_FillRect(uneSurface,NULL,SDL_MapRGB(uneSurface->format,255,255,255));
    /**<affichage de la ligne supérieure*/
    SDLAppliqueSurface(uneSurface,SDLGetIemeTexture(sdl,0),1015,367);
    /**<affichage de la ligne inférieure*/
    SDLAppliqueSurface(uneSurface,SDLGetIemeTexture(sdl,0),1015,670);
    largeurBarre=(270-20-((_Nombre_de_Joueur-1)*5))/_Nombre_de_Joueur;
    positionXBarre=1025;
    SDL_FreeSurface(uneSurface);

    for(i=0;i<_Nombre_de_Joueur;i++){
        pourcentage=((float)scores[i])/(float)_Score_de_Victoire;
        if(scores[i]>_Score_de_Victoire){pourcentage=1;}
        hauteur=pourcentage*(570-270);
        positionYBarre=370+(300-hauteur);
        uneSurface=SDL_CreateRGBSurface(SDL_HWSURFACE,largeurBarre,hauteur,32,0,0,0,0);
        uneCouleur=JoueurGetCouleur(JeuGetIemeJoueurs(SDLGetJeu(sdl),i));
        if(uneCouleur==ORANGE){
            SDL_FillRect(uneSurface,NULL,SDL_MapRGB(uneSurface->format,255,204,51));
        }
        else if(uneCouleur==BLEU){
            SDL_FillRect(uneSurface,NULL,SDL_MapRGB(uneSurface->format,51,204,255));
            }
            else if(uneCouleur==ROUGE){
            SDL_FillRect(uneSurface,NULL,SDL_MapRGB(uneSurface->format,232,33,5));
            }
                else if(uneCouleur==VERT){
                SDL_FillRect(uneSurface,NULL,SDL_MapRGB(uneSurface->format,33,198,33));
                }
                    else if(uneCouleur==VIOLET){
                    SDL_FillRect(uneSurface,NULL,SDL_MapRGB(uneSurface->format,204,51,255));
                    }
                        else if(uneCouleur==BLEUF){
                        SDL_FillRect(uneSurface,NULL,SDL_MapRGB(uneSurface->format,13,24,179));
                        }
                            else if(uneCouleur==JAUNE){
                            SDL_FillRect(uneSurface,NULL,SDL_MapRGB(uneSurface->format,231,239,11));
                            }
                                else if(uneCouleur==BLANC){
                                SDL_FillRect(uneSurface,NULL,SDL_MapRGB(uneSurface->format,255,255,255));
                                }
        SDLAppliqueSurface(uneSurface,SDLGetIemeTexture(sdl,0),positionXBarre,positionYBarre);
        positionXBarre+=5+largeurBarre;
        SDL_FreeSurface(uneSurface);
    }
}


void SDLAfficheJeu(SDL *sdl){
    SDLAfficheMurs(sdl);
    SDLAfficheMotos(sdl);
    SDLAfficheBonus(sdl);
    SDLAfficheInterface(sdl);
    SDLAfficheScores(sdl);
    SDL_Flip(SDLGetIemeTexture(sdl,0));
}



void SDLTestRegression(){
    /*SDL sdl;
    SDLJeuInit2(&sdl);
    SDLAfficheJeu(&sdl);
    bougeMoto(SDLGetJeu(&sdl));
    SDLDestructeur(&sdl);
    printf("pointeur de l'image chargée après kdestruction : %p   %p \n",SDLGetIemeTexture(&sdl,5),SDLGetIemeTexture(&sdl,7));*/
}

