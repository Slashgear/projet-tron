#include<stdlib.h>
#include<stdio.h>
#include "Joueur.h"
#include "Moto.h"
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

void JoueurSetMoto(Joueur* joueur, Moto moto){
    joueur->moto=&moto;
}
void JoueurSetControle(Joueur* joueur, Controle controle){
    joueur->controle=&controle;
}
void JoueurSetCouleur(Joueur* joueur, Couleur couleur){
    joueur->couleur=couleur;
}

/** Constructeur de Joueur*/
void JoueurConstructeur(Joueur* joueur,const Moto* moto,const Controle* controle, Couleur couleur){
    JoueurSetMoto(joueur,*moto);
    JoueurSetControle(joueur,*controle);
    JoueurSetCouleur(joueur,couleur);
}
/** Destructeur de Joueur*/
void JoueurDestructeur(Joueur* joueur){

}

/** Procedure qui teste le module Joueur*/
 void JoueurTestRegression(){

 }
