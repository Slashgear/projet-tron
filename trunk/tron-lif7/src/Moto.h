/**
\file [Moto.h]
 Module des Motos du jeu
\author {Antoine.C,Matthieu.B}
\version 0.1
\date 13 mars 2013
*/
#ifndef MOTOS_H_INCLUDED
#define MOTOS_H_INCLUDED
#include<stdlib.h>
/**
	\enum Direction
*/
typedef enum{NON_DIRIGE=0,HAUT=1,BAS=2,GAUCHE=3,DROITE=4} Direction;
/**
 	\struct Moto
 Structure d'une Moto
 */
typedef struct{
        float positionX;
        float positionY;
        unsigned int tailleX;
        unsigned int tailleY;
        float vitesse;
        Direction direction;
} Moto;
/**
 	\fn MotoGetPositionX
 assesseur position X moto
 	\param const Moto* moto
 	\return positionX
 */
float MotoGetPositionX(const Moto* moto);
/**
 	\fn MotoGetPositionY
 assesseur position Y moto
 	\param const Moto* moto
 	\return positionY
 */
float MotoGetPositionY(const Moto* moto);
/**
 	\fn MotoGetTailleX
 assesseur tailleX moto
 	\param const Moto* moto
 	\return tailleX
 */
unsigned int MotoGetTailleX(const Moto* moto);
/**
 	\fn MotoGetTailleY
 assesseur tailleY moto
 	\param const Moto* moto
 	\return tailleY
 */
unsigned int MotoGetTailleY(const Moto* moto);
/**
 	\fn MotoGetVitesse
 assesseur vitesse moto
 	\param const Moto* moto
 	\return vitesse (float)
 */
float MotoGetVitesse(const Moto* moto);
/**
 	\fn MotoGetDirection
 assesseur direction moto
 	\param const Moto* moto
 	\return Direction
 */
Direction MotoGetDirection(const Moto* moto);


/**
 	\fn MotoSetPositionX
 mutateur de positionX de moto
 	\param Moto* m,float posX
 */
void MotoSetPositionX(Moto* m,float posX);
/**
 	\fn MotoSetPositionY
 mutateur de positionY de moto
 	\param Moto* m,float posY
 */
void MotoSetPositionY(Moto* m,float posY);
/**
 	\fn MotoSetTailleX
 mutateur de dimX moto
 	\param Moto* m,unsigned int tailleX
 */
void MotoSetTailleX(Moto* m,unsigned int tailleX);
/**
 	\fn MotoSetTailleY
 mutateur de dimY moto
 	\param Moto* m,unsigned int tailleY
 */
void MotoSetTailleY(Moto* m,unsigned int tailleY);
/**
 	\fn MotoSetVitesse
 mutateur de vitesse
 	\param Moto* m,float vitesse
 */
void MotoSetVitesse(Moto* m,float vitesse);
/**
 	\fn MotoSetDirection
 mutateur de direction
 	\param Moto* m, Direction direction
 */
void MotoSetDirection(Moto* m, Direction direction);

/**
 	\fn MotoConstructeur
 Constructeur de Moto
 	\param Moto* moto,float posX,float posY,unsigned int tailleX, unsigned int tailleY,float vitesse,Direction direction
 */
void MotoConstructeur(Moto* moto,float posX,float posY,unsigned int tailleX, unsigned int tailleY,float vitesse,Direction direction);
/**
 	\fn MotoDestructeur
 Destructeur de Moto
 	\param Moto* moto
 */
void MotoDestructeur(Moto* moto);
/**
 	\fn MotoDestructeur
  Procedure qui teste le module Moto
 */
 void MotoTestRegression();


#endif /* MOTOS_H_INCLUDED */
