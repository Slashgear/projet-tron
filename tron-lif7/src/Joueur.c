#include<stdlib.h>
#include<stdio.h>
#include "Joueur.h"
#include "Moto.h"
#include "Controle.h"
#include "Couleur.h"


Moto* JoueurGetMoto(Joueur* joueur){
    return &(joueur->moto);
}
Controle* JoueurGetControle(Joueur* joueur){
    return &(joueur->controle);
}
Couleur JoueurGetCouleur(const Joueur* joueur){
    return joueur->couleur;
}
EnJeu JoueurGetEnJeu(const Joueur* joueur){
    return joueur->enJeu;
}
EffetBonus JoueurGetEffetBonus(const Joueur* joueur){
    return joueur->effetActuel;
}
short int JoueurGetNumeroManette(const Joueur *joueur){
    return joueur->numeroManette;
}
int JoueurGetTempsBonus(const Joueur *joueur){
    return joueur->tempsBonus;
}
Mur* JoueurGetDernierMur(Joueur *joueur){
    return joueur->dernierMur;
}
short int JoueurGetBooltourne(Joueur *joueur){
    return joueur->boolTourne;
}
short int JoueurGetNumeroJoueur(Joueur *joueur){
    return joueur->numeroJoueur;
}
short int JoueurGetBoolIA(Joueur *joueur){
    return joueur->boolIA;
}
short int JoueurGetJoueurCible(Joueur *joueur){
    return joueur->joueurCible;
}
short int JoueurGetScore(Joueur *joueur){
    return joueur->score;
}

void JoueurSetMoto(Joueur* joueur, Moto* moto){
    joueur->moto= *moto;
}
void JoueurSetControle(Joueur* joueur, Controle* controle){
    joueur->controle= *controle;
}
void JoueurSetCouleur(Joueur* joueur, Couleur couleur){
    joueur->couleur=couleur;
}
void JoueurSetEnJeu(Joueur* joueur, EnJeu enJeu){
    joueur->enJeu=enJeu;
}
void JoueurSetEffetBonus(Joueur* joueur,EffetBonus effet){
    joueur->effetActuel=effet;
}
void JoueurSetNumeroManette(Joueur* joueur,short int numero){
    joueur->numeroManette=numero;
}
void JoueurSetTempsBonus(Joueur* joueur, int tempsBonus){
    joueur->tempsBonus=tempsBonus;
}
void JoueurSetDernierMur(Joueur* joueur,Mur* unMur){
    joueur->dernierMur=unMur;
}
void JoueurSetBooltourne(Joueur *joueur,short int boolTourne){
    joueur->boolTourne=boolTourne;
}
void JoueurSetNumeroJoueur(Joueur *joueur,short int numero){
    joueur->numeroJoueur=numero;
}
void JoueurSetBoolIA(Joueur *joueur,short int boolIA){
    joueur->boolIA=boolIA;
}
void JoueurSetJoueurCible(Joueur *joueur,short int numero){
    joueur->joueurCible=numero;
}
void JoueurSetScore(Joueur *joueur,short int score){
    joueur->score=score;
}


void JoueurConstructeur(Joueur* joueur, Moto* moto, Controle* controle, Couleur couleur, EnJeu enJeu,
                        EffetBonus effetActuel,short int numeroManette,short int numeroJoueur,short int boolIA){
    JoueurSetMoto(joueur,moto);
    JoueurSetControle(joueur,controle);
    JoueurSetCouleur(joueur,couleur);
    JoueurSetEnJeu(joueur,enJeu);
    JoueurSetEffetBonus(joueur,effetActuel);
    JoueurSetNumeroManette(joueur,numeroManette);
    JoueurSetTempsBonus(joueur,0);
    JoueurSetDernierMur(joueur,NULL);
    JoueurSetBooltourne(joueur,0);
    JoueurSetNumeroJoueur(joueur,numeroJoueur);
    JoueurSetBoolIA(joueur,boolIA);
    JoueurSetJoueurCible(joueur,0);
}
void JoueurDestructeur(Joueur* joueur){
    MotoDestructeur(JoueurGetMoto(joueur));
    ControleDestructeur(JoueurGetControle(joueur));
    JoueurSetCouleur(joueur,NOIR);
    JoueurSetEnJeu(joueur,MORT);
    JoueurSetEffetBonus(joueur,AUCUN);
    JoueurSetNumeroManette(joueur,-1);
    JoueurSetTempsBonus(joueur,0);
    JoueurSetDernierMur(joueur,NULL);
    JoueurSetBooltourne(joueur,0);
    JoueurSetNumeroJoueur(joueur,0);
    JoueurSetBoolIA(joueur,0);
    JoueurSetJoueurCible(joueur,0);
}


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
    char touchebonus='a';

    MotoConstructeur(&moto,posX,posY,tailleX,tailleY,vitesse,direction);

    ControleConstructeur(&controle,touchehaut,touchebas,touchegauche,touchedroite,touchebonus);

    JoueurConstructeur(&joueur,&moto,&controle,couleur,VIVANT,AUCUN,-1,1,0);
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
