#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED
#include "EffetBonus.h"

/**
\file [Bonus.h]
\brief Module des Motos du jeu
\author {Antoine.C,Matthieu.B}
\version 1.1
\date 10 avril 2013
*/

typedef struct{
    float positionX;
    float positionY;
    unsigned int tailleX;
    unsigned int tailleY;
    EffetBonus effet;
} Bonus;


/**assesseur de Bonus*/
float BonusGetPositionX(const Bonus* bonus);
float BonusGetPositionY(const Bonus* bonus);
unsigned int BonusGetTailleX(const Bonus* bonus);
unsigned int BonusGetTailleY(const Bonus* bonus);
EffetBonus BonusGetEffetBonus(const Bonus* effet);

/**mutateur de Bonus*/
void BonusSetPositionX(Bonus* bonus,float positionX);
void BonusSetPositionY(Bonus* bonus,float positionY);
void BonusSetTailleX(Bonus* bonus,unsigned int tailleX);
void BonusSetTailleY(Bonus* bonus,unsigned int tailleY);
void BonusSetEffetBonus(Bonus* bonus,EffetBonus effet);

/**Constructeur du Bonus*/
void BonusConstructeur(Bonus *bonus, float positionX,float positionY,unsigned int tailleX,unsigned int tailleY,EffetBonus effet);
/**Destructeur du Bonus*/
void BonusDestructeur(Bonus *bonus);

/**fonction qui teste le module*/
void BonusTestRegression();

#endif
