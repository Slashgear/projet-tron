
#ifndef _TAB_DYN
#define _TAB_DYN
/**
	\file [TableauDynamiqueMur.h]
	 Module qui gère les tableaux dynamiques des Murs
	\author {Antoine.C,Matthieu.B}
	\version 1.0
	\date 19 mars 2013
*/
#include "Mur.h"
#include <stdio.h>
#include <stdlib.h>
/**
 	\struct TableauDynamiqueMur
 Structure d'un TableauDynamiqueMur
 */
typedef struct{
  unsigned int capacite;
  unsigned int taille_utilisee;
  Mur* ad;}TableauDynamiqueMur;

/**assesseur de capacite*/
unsigned int TabDynMurGetCapacite(const TableauDynamiqueMur* TabDynMur);
/**assesseur de taille_utilisee*/
unsigned int TabDynMurGetTaille_utilisee(const TableauDynamiqueMur* TabDynMur);
/**assesseur de ad*/
Mur* TabDynMurGetAd(const TableauDynamiqueMur* TabDynMur);

/**mutateur de capacite*/
void TabDynMurSetCapacite(TableauDynamiqueMur* TabDynMur, unsigned int capacite);
/**mutateur de taille_utilisee*/
void TabDynMurSetTaille_utilisee(TableauDynamiqueMur* TabDynMur,unsigned int taille);
/**mutateur de ad*/
void TabDynMurSetAd(TableauDynamiqueMur* TabDynMur,Mur* ad);

/** Precondition : t non prealablement initialise
 Postcondition : t initialise a une alveole vide (taille utilisee nulle) */
void initialiserTabDynMur(TableauDynamiqueMur * t);

/** Precondition : t prealablement initialise
Postcondition : t pret a disparaitre. La memoire allouee dynamiquement
   est liberee. On ne pourra plus appeler les sous-programmes qui
   necessitent que t soit initialise. */
void testamentTabDynMur(TableauDynamiqueMur *t);


/** Precondition : t1 et t2 initialises
		 Postcondition : l'ancien contenu de t1 est perdu. t1 et t2 contiennent
   des sequences d'ElementTD identiques t1 correspond a une copie de t2,
   les 2 tableaux ont meme capacite, meme taille utilisee, mais sont
   independants) */
void affecterTabDynMur(TableauDynamiqueMur *t1, const TableauDynamiqueMur *t2);


/** Precondition : t prealablement initialise
		 Resultat : nombre d'ElementTDs stockes dans t */
unsigned int tailleUtiliseeTabDynMur(const TableauDynamiqueMur *t);


/** Precondition : t prealablement initialise, 0 <= i < tailleUtilisee(t)
 Resultat : retourne le i+1eme ElementTD de t */
Mur valeurIemeElementTabDynMur(const TableauDynamiqueMur *t, unsigned int i);

/** Precondition : t prealablement initialise, 0 <= i < tailleUtilisee(t)
 Resultat : retourne l'adresse du i+1eme ElementTD de t */
Mur* adresseIemeElementTabDynMur(const TableauDynamiqueMur *t, unsigned int i);

/** Precondition : t prealablement initialise
 Postcondition : L'element e est ajoute dans la premiere alveole inutilisee
   du tableau, la taille utilisee est incrementee de 1. Doublement de la
   capacite de t, si necessaire. */
void ajouterElementTabDynMur(TableauDynamiqueMur *t, Mur e);


/** Precondition : t prealablement initialise et non vide
   Postcondition : la taille utilisee du tableau est decrementee de 1. Si
   tailleUtilisee < capacite/3, alors on divise la capacité par 2. */
void supprimerElementTabDynMur( TableauDynamiqueMur *t, int position );


/** Precondition : t prealablement initialise et 0 <= i < tailleUtilisee(t)
   Postcondition : le i+1eme ElementTD de t vaut e */
void modifierValeurIemeElementTabDynMur(TableauDynamiqueMur *t, Mur e, unsigned int i);


/** Precondition : t prealablement initialise et 0 <= i < tailleUtilisee(t)
   Postcondition : e est insere en i+1eme position et tailleUtilisee est incrementee de 1 */
void insererElementTabDynMur(TableauDynamiqueMur *t, Mur e, unsigned int i);







#endif
