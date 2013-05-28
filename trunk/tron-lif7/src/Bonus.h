/**
\file [Bonus.h]
 Module des Bonus du jeu
\author {Antoine.C,Matthieu.B}
\version 1.1
\date 10 avril 2013
*/
#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED
#include "EffetBonus.h"

/**
 	\struct Bonus
 Structure d'un Bonus
 */
typedef struct{
    float positionX; /*!< Position en X du Bonus. */
    float positionY; /*!< Position en Y du Bonus. */
    unsigned int tailleX; /*!< Taille en X du Bonus. */
    unsigned int tailleY; /*!< Taille en Y du Bonus. */
    EffetBonus effet; /*!< Effet du Bonus. */
} Bonus;


/**
 	\fn BonusGetPositionX
 Assesseur de la positionX
 	\param un Bonus
 	\return position du bonus
 */
float BonusGetPositionX(const Bonus* bonus);
/**
 	\fn BonusGetPositionY
 Assesseur de la positionY
 	\param un Bonus
 	\return position du bonus
 */
float BonusGetPositionY(const Bonus* bonus);
/**
 	\fn BonusGetTailleX
 Assesseur de la tailleX
 	\param un Bonus
 	\return taille du bonus
 */
unsigned int BonusGetTailleX(const Bonus* bonus);
/**
 	\fn BonusGetTailleY
 Assesseur de la tailleY
 	\param un Bonus
 	\return taille du bonus
 */
unsigned int BonusGetTailleY(const Bonus* bonus);
/**
 	\fn BonusGetEffetBonus)
 Assesseur de l'effet bonus
 	\param un Bonus
 	\return EffetBonus
 */
EffetBonus BonusGetEffetBonus(const Bonus* effet);

/**
 	\fn BonusSetPositionX
 Mutateur de la position X
 	\param un Bonus, une position
 */
void BonusSetPositionX(Bonus* bonus,float positionX);
/**
 	\fn BonusSetPositionY
 Mutateur de la position Y
 	\param un Bonus, une position
 */
void BonusSetPositionY(Bonus* bonus,float positionY);
/**
 	\fn BonusSetTailleX(
 Mutateur de la taille X
 	\param un Bonus, une taille
 */
void BonusSetTailleX(Bonus* bonus,unsigned int tailleX);
/**
 	\fn BonusSetTailleY
 Mutateur de la taille Y
 	\param un Bonus, une taille
 */
void BonusSetTailleY(Bonus* bonus,unsigned int tailleY);
/**
 	\fn BonusSetEffetBonus
 Mutateur de l'effet bonus
 	\param un Bonus, un effet
 */
void BonusSetEffetBonus(Bonus* bonus,EffetBonus effet);
/**
 	\fn BonusConstructeur
 Constructeur du Bonus
 	\param Bonus *bonus, float positionX,float positionY,unsigned int tailleX,unsigned int tailleY,EffetBonus effet
 */
void BonusConstructeur(Bonus *bonus, float positionX,float positionY,unsigned int tailleX,unsigned int tailleY,EffetBonus effet);
/**
 	\fn BonusDestructeur
 Destructeur du Bonus
 	\param Bonus *bonus
 */
void BonusDestructeur(Bonus *bonus);

/**
 	\fn BonusTestRegression
 Test du Module
 */
void BonusTestRegression();
#endif
