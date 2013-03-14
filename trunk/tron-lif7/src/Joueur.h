#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED
#include "src/Controle.h"
#include "src/Moto.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct{
    Moto uneMoto;
    Controle unControle;
}Joueur;

/** assesseur de moto*/
Moto setMotoJoueur(Joueur joueur);
/** assesseur de controle*/
Controle setControleJoueur(Joueur joueur);

/**mutateur de Moto*/
void getMotoJoueur(Joueur joueur,Moto uneMoto);
/**mutateur de Control*/
void getMotoJoueur(Joueur joueur,Controle unControle);

#endif // JOUEUR_H_INCLUDED
