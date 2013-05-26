#ifndef TABLEAUDYNAMIQUEENTIER_H_INCLUDED
#define TABLEAUDYNAMIQUEENTIER_H_INCLUDED
/**
*\file [TableauDynamiqueEntier.h]
*\brief Module qui gère les tableaux dynamiques d'entier
*\author {Antoine.C,Matthieu.B}
*\version 1.0
*\date 19 mars 2013
*/
/**
 * \struct TableauDynamiqueEntier
 * \brief Structure d'un TableauDynamiqueEntier
 */
typedef struct{
  unsigned int capacite;
  unsigned int taille_utilisee;
  int* ad;}TableauDynamiqueEntier;

/**assesseur de capacite*/
unsigned int TabDynEntierGetCapacite(const TableauDynamiqueEntier* TabDynEntier);
/**assesseur de taille_utilisee*/
unsigned int TabDynEntierGetTaille_utilisee(const TableauDynamiqueEntier* TabDynEntier);
/**assesseur de ad*/
int* TabDynEntierGetAd(const TableauDynamiqueEntier* TabDynEntier);

/**mutateur de capacite*/
void TabDynEntierSetCapacite(TableauDynamiqueEntier* TabDynEntier, unsigned int capacite);
/**mutateur de taille_utilisee*/
void TabDynEntierSetTaille_utilisee(TableauDynamiqueEntier* TabDynEntier,unsigned int taille);
/**mutateur de ad*/
void TabDynEntierSetAd(TableauDynamiqueEntier* TabDynEntier,int* ad);

/** Precondition : t non prealablement initialise
 Postcondition : t initialise a une alveole vide (taille utilisee nulle) */
void initialiserTabDynEntier(TableauDynamiqueEntier * t);

/** Precondition : t prealablement initialise
Postcondition : t pret a disparaitre. La memoire allouee dynamiquement
   est liberee. On ne pourra plus appeler les sous-programmes qui
   necessitent que t soit initialise. */
void testamentTabDynEntier(TableauDynamiqueEntier *t);


/** Precondition : t1 et t2 initialises
		 Postcondition : l'ancien contenu de t1 est perdu. t1 et t2 contiennent
   des sequences d'ElementTD identiques t1 correspond a une copie de t2,
   les 2 tableaux ont meme capacite, meme taille utilisee, mais sont
   independants) */
void affecterTabDynEntier(TableauDynamiqueEntier *t1, const TableauDynamiqueEntier *t2);


/** Precondition : t prealablement initialise
		 Resultat : nombre d'ElementTDs stockes dans t */
unsigned int tailleUtiliseeTabDynEntier(const TableauDynamiqueEntier *t);


/** Precondition : t prealablement initialise, 0 <= i < tailleUtilisee(t)
 Resultat : retourne le i+1eme ElementTD de t */
int valeurIemeElementTabDynEntier(const TableauDynamiqueEntier *t, unsigned int i);

/** Precondition : t prealablement initialise, 0 <= i < tailleUtilisee(t)
 Resultat : retourne l'adresse du i+1eme ElementTD de t */
int* adresseIemeElementTabDynEntier(const TableauDynamiqueEntier *t, unsigned int i);

/** Precondition : t prealablement initialise
 Postcondition : L'element e est ajoute dans la premiere alveole inutilisee
   du tableau, la taille utilisee est incrementee de 1. Doublement de la
   capacite de t, si necessaire. */
void ajouterElementTabDynEntier(TableauDynamiqueEntier *t, int e);


/** Precondition : t prealablement initialise et non vide
   Postcondition : la taille utilisee du tableau est decrementee de 1. Si
   tailleUtilisee < capacite/3, alors on divise la capacité par 2. */
void supprimerElementTabDynEntier( TableauDynamiqueEntier *t, int position );


/** Precondition : t prealablement initialise et 0 <= i < tailleUtilisee(t)
   Postcondition : le i+1eme ElementTD de t vaut e */
void modifierValeurIemeElementTabDynEntier(TableauDynamiqueEntier *t,int e, unsigned int i);


/** Precondition : t prealablement initialise et 0 <= i < tailleUtilisee(t)
   Postcondition : e est insere en i+1eme position et tailleUtilisee est incrementee de 1 */
void insererElementTabDynEntier(TableauDynamiqueEntier *t, int e, unsigned int i);



#endif
