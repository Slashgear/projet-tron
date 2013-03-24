#include<stdlib.h>
#include<stdio.h>
#include "Joueur.h"
#include "Moto.h"
#include "Controle.h"
#include "Couleur.h"


Moto* JoueurGetMoto(const Joueur* joueur){
    return joueur->moto;
}
Controle* JoueurGetControle(const Joueur* joueur){
    return joueur->controle;
}
Couleur JoueurGetCouleur(const Joueur* joueur){
    return joueur->couleur;
}

void JoueurSetMoto(Joueur* joueur, Moto* moto){
    joueur->moto=moto;
}
void JoueurSetControle(Joueur* joueur, Controle* controle){
    joueur->controle=controle;
}
void JoueurSetCouleur(Joueur* joueur, Couleur couleur){
    joueur->couleur=couleur;
}

void JoueurConstructeur(Joueur* joueur, Moto* moto, Controle* controle, Couleur couleur){
    JoueurSetMoto(joueur,moto);
    JoueurSetControle(joueur,controle);
    JoueurSetCouleur(joueur,couleur);
}
/** Destructeur de Joueur*/
void JoueurDestructeur(Joueur* joueur){
    MotoDestructeur(JoueurGetMoto(joueur));
    ControleDestructeur(JoueurGetControle(joueur));
    JoueurSetMoto(joueur,NULL);
    JoueurSetControle(joueur,NULL);
    JoueurSetCouleur(joueur,NOIR);
}

/** Procedure qui teste le module Joueur*/
 void JoueurTestRegression(){
    Joueur joueur;
    Moto moto;
    Controle controle;
    Couleur couleur=ORANGE;
    float posX=1;
    float posY=1;
    unsigned int tailleX=10;
    unsigned int tailleY=10;
    float vitesse=20;
    Direction direction=HAUT;

    char touchedroite='d';
    char touchegauche='g';
    char touchehaut='h';
    char touchebas='b';

    MotoConstructeur(&moto,posX,posY,tailleX,tailleY,vitesse,direction);

    ControleConstructeur(&controle,touchedroite,touchegauche,touchehaut,touchebas);

    JoueurConstructeur(&joueur,&moto,&controle,couleur);
    printf("La valeur posX est %f et dans la Moto du joueur est de %f \n",posX,MotoGetPositionX(JoueurGetMoto(&joueur)));
    printf("La valeur posY est %f et dans la Moto du joueur est de %f \n",posY,MotoGetPositionY(JoueurGetMoto(&joueur)));
    printf("La valeur tailleX est %u et dans la Moto du joueur est de %u \n",tailleX,MotoGetTailleX(JoueurGetMoto(&joueur)));
    printf("La valeur tailleY est %u et dans la Moto du joueur est de %u \n",tailleY,MotoGetTailleY(JoueurGetMoto(&joueur)));
    printf("La valeur vitesse est %f et dans la Moto du joueur est de %f \n",vitesse,MotoGetVitesse(JoueurGetMoto(&joueur)));
    printf("La valeur de direction est de %d et dans la Moto du joueur est de %d \n",direction,MotoGetDirection(JoueurGetMoto(&joueur)));

    printf("Le caractere de la touche droite est %c ,et dans le Controle du joueur est %c\n",touchedroite,ControleGetDroite(JoueurGetControle(&joueur)));
    printf("Le caractere de la touche gauche est %c ,et dans le Controle du joueur est %c\n",touchegauche,ControleGetGauche(JoueurGetControle(&joueur)));
    printf("Le caractere de la touche haut est %c ,et dans le Controle du joueur est %c\n",touchehaut,ControleGetHaut(JoueurGetControle(&joueur)));
    printf("Le caractere de la touche bas est %c ,et dans le Controle du joueur est %c\n",touchebas,ControleGetBas(JoueurGetControle(&joueur)));

    JoueurDestructeur(&joueur);

    printf("Après destruction le pointeur de moto du joueur est %p \n", JoueurGetMoto(&joueur));
    printf("Après destruction le pointeur de controle du joueur est %p \n \n", JoueurGetControle(&joueur));

 }
