
#ifndef _TAB_DYN
#define _TAB_DYN

#include "Mur.h"
#include <stdio.h>
#include <stdlib.h>



typedef struct{
  unsigned int capacite;
  unsigned int taille_utilisee;
  Mur* ad;}TableauDynamique;

/**assesseur de capacite*/
unsigned int TabDynGetCapacite(const TableauDynamique* tabDyn);
/**assesseur de taille_utilisee*/
unsigned int TabDynGetTaille_utilisee(const TableauDynamique* tabDyn);
/**assesseur de ad*/
Mur* TabDynGetAd(const TableauDynamique* tabDyn);

/**mutateur de capacite*/
void TabDynSetCapacite(TableauDynamique* tabDyn, unsigned int capacite);
/**mutateur de taille_utilisee*/
void TabDynSetTaille_utilisee(TableauDynamique* tabDyn,unsigned int taille);
/**mutateur de ad*/
void TabDynSetAd(TableauDynamique* tabDyn,Mur* ad);

/** Precondition : t non prealablement initialise
 Postcondition : t initialise a une alveole vide (taille utilisee nulle) */
void initialiserTabDyn(TableauDynamique * t);

/** Precondition : t prealablement initialise
Postcondition : t pret a disparaitre. La memoire allouee dynamiquement
   est liberee. On ne pourra plus appeler les sous-programmes qui
   necessitent que t soit initialise. */
void testamentTabDyn(TableauDynamique *t);


/** Precondition : t1 et t2 initialises
		 Postcondition : l'ancien contenu de t1 est perdu. t1 et t2 contiennent
   des sequences d'ElementTD identiques t1 correspond a une copie de t2,
   les 2 tableaux ont meme capacite, meme taille utilisee, mais sont
   independants) */
void affecterTabDyn(TableauDynamique *t1, const TableauDynamique *t2);


/** Precondition : t prealablement initialise
		 Resultat : nombre d'ElementTDs stockes dans t */
unsigned int tailleUtiliseeTabDyn(const TableauDynamique *t);


/** Precondition : t prealablement initialise, 0 <= i < tailleUtilisee(t)
 Resultat : retourne le i+1eme ElementTD de t */
Mur valeurIemeElementTabDyn(const TableauDynamique *t, unsigned int i);

/** Precondition : t prealablement initialise, 0 <= i < tailleUtilisee(t)
 Resultat : retourne l'adresse du i+1eme ElementTD de t */
Mur* adresseIemeElementTabDyn(const TableauDynamique *t, unsigned int i);

/** Precondition : t prealablement initialise
 Postcondition : L'element e est ajoute dans la premiere alveole inutilisee
   du tableau, la taille utilisee est incrementee de 1. Doublement de la
   capacite de t, si necessaire. */
void ajouterElementTabDyn(TableauDynamique *t, Mur e);


/** Precondition : t prealablement initialise et non vide
   Postcondition : la taille utilisee du tableau est decrementee de 1. Si
   tailleUtilisee < capacite/3, alors on divise la capacité par 2. */
void supprimerElementTabDyn( TableauDynamique *t, int position );


/** Precondition : t prealablement initialise et 0 <= i < tailleUtilisee(t)
   Postcondition : le i+1eme ElementTD de t vaut e */
void modifierValeurIemeElementTabDyn(TableauDynamique *t, Mur e, unsigned int i);


/** Precondition : t prealablement initialise et 0 <= i < tailleUtilisee(t)
   Postcondition : e est insere en i+1eme position et tailleUtilisee est incrementee de 1 */
void insererElementTabDyn(TableauDynamique *t, Mur e, unsigned int i);







#endif
