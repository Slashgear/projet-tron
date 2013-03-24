#include "Jeu.h"
#include "Joueur.h"
#include "Grid.h"
#include <stdio.h>
#include <stdlib.h>

Grid* JeuGetGrille(const Jeu* jeu){
    return jeu->grille;
}
Joueur* JeuGetMesJoueurs(const Jeu* jeu){
    return jeu->mesJoueurs;
}
void JeuSetGrille(Jeu* jeu,Grid* grille){
    jeu->grille=grille;
}
void JeuSetMesJoueurs(Jeu* jeu,Joueur* mesJoueurs){
    jeu->mesJoueurs=mesJoueurs;
}

void JeuConstructeur(Jeu* jeu, Grid* grille, Joueur* mesJoueurs){
    JeuSetGrille(jeu,grille);
    JeuSetMesJoueurs(jeu,mesJoueurs);
}
void JeuDestructeur(Jeu* jeu){
    int i;
    GridDestructeur(JeuGetGrille(jeu));
    for(i=0;i<2;i++){
    JoueurDestructeur(&(JeuGetMesJoueurs(jeu)[i]));
    }
    JeuSetGrille(jeu,NULL);
    JeuSetMesJoueurs(jeu,NULL);
}

/**procédure de test*/
void JeuTestRegression(){
    Grid grille;
    float posXg=10;
    float posYg=5;
    unsigned int tailleXg=3;
    unsigned int tailleYg=4;
    TableauDynamique mesMurs;
    Mur unMur;

    Joueur joueur1;
    Moto moto1;
    Controle controle1;
    Couleur couleur1=ORANGE;
    float posX1=1;
    float posY1=1;
    unsigned int tailleX1=10;
    unsigned int tailleY1=10;
    float vitesse1=20;
    Direction direction1=HAUT;
    char touchedroite1='d';
    char touchegauche1='q';
    char touchehaut1='z';
    char touchebas1='s';

    Joueur joueur2;
    Moto moto2;
    Controle controle2;
    Couleur couleur2=BLEU;
    float posX2=2;
    float posY2=2;
    unsigned int tailleX2=20;
    unsigned int tailleY2=20;
    float vitesse2=30;
    Direction direction2=BAS;
    char touchedroite2='m';
    char touchegauche2='k';
    char touchehaut2='o';
    char touchebas2='l';

    Jeu jeu;
    Joueur mesJoueurs[2];

    MurSetDureeVie(&unMur,0);
    GridConstructeur(&grille,posXg,posYg,tailleXg,tailleYg,&mesMurs);

    MotoConstructeur(&moto1,posX1,posY1,tailleX1,tailleY1,vitesse1,direction1);
    ControleConstructeur(&controle1,touchedroite1,touchegauche1,touchehaut1,touchebas1);
    JoueurConstructeur(&joueur1,&moto1,&controle1,couleur1);
    mesJoueurs[0] = joueur1;
    printf("La valeur posX1 est %f et dans la Moto1 du joueur1 est de %f \n",posX1,MotoGetPositionX(JoueurGetMoto(&mesJoueurs[0])));

    MotoConstructeur(&moto2,posX2,posY2,tailleX2,tailleY2,vitesse2,direction2);
    ControleConstructeur(&controle2,touchedroite2,touchegauche2,touchehaut2,touchebas2);
    JoueurConstructeur(&joueur2,&moto2,&controle2,couleur2);
    mesJoueurs[1] = joueur2;
    printf("La valeur posX2 est %f et dans la Moto2 du joueur2 est de %f \n",posX2,MotoGetPositionX(JoueurGetMoto(&mesJoueurs[1])));

    JeuConstructeur(&jeu,&grille,(Joueur*)&mesJoueurs);
    printf("La valeur vitesse2 est %f et dans la vitesse de la moto2 du joueur2 du jeu est de %f \n",vitesse2,MotoGetVitesse(JoueurGetMoto(&JeuGetMesJoueurs(&jeu)[1])));

    JeuDestructeur(&jeu);
    printf("Après destruction, le pointeur de grille du jeu est %p \n",JeuGetGrille(&jeu));
    printf("Après destruction, le pointeur de mesJoueurs du jeu est %p \n \n",JeuGetMesJoueurs(&jeu));
}


