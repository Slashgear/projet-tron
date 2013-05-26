/**
*\file [TableauDynamiqueEntier.c]
*\brief Module qui gère les tableaux dynamiques d'entier
*\author {Antoine.C,Matthieu.B}
*\version 1.0
*\date 19 mars 2013
*/
#include "TableauDynamiqueEntier.h"
#include <stdlib.h>


unsigned int TabDynEntierGetCapacite(const TableauDynamiqueEntier* TabDynEntier){
    return TabDynEntier->capacite;
}
unsigned int TabDynEntierGetTaille_utilisee(const TableauDynamiqueEntier* TabDynEntier){
    return TabDynEntier->taille_utilisee;
}
int* TabDynEntierGetAd(const TableauDynamiqueEntier* TabDynEntier){
    return TabDynEntier->ad;
}

void TabDynEntierSetCapacite(TableauDynamiqueEntier* TabDynEntier, unsigned int capacite){
    TabDynEntier->capacite=capacite;
}
void TabDynEntierSetTaille_utilisee(TableauDynamiqueEntier* TabDynEntier,unsigned int taille){
    TabDynEntier->taille_utilisee=taille;
}
void TabDynEntierSetAd(TableauDynamiqueEntier* TabDynEntier,int* ad){
    TabDynEntier->ad=ad;
}




void initialiserTabDynEntier (TableauDynamiqueEntier* t)
{
	t -> ad = (int *)malloc(sizeof(int));
	t -> capacite = 1;
	t -> taille_utilisee = 0;
}


void testamentTabDynEntier (TableauDynamiqueEntier*t)
{
	if(t -> ad != 0)
	{
		free(t -> ad);
		t -> capacite = 0;
		t -> taille_utilisee = 0;
	}
}



void ajouterElementTabDynEntier(TableauDynamiqueEntier* t, int e)
{
	if((t-> taille_utilisee) == (t-> capacite))
	{
		int i;
		int * temp = t-> ad;
		(t->ad) = (int*) malloc(2*(t->capacite)*sizeof(int));
		for(i=0;i<(t-> capacite);i++)
		{
			(t-> ad) [i] = temp[i];
		}
		t-> capacite *= 2;
		free(temp);
	}
		(t-> ad) [t-> taille_utilisee] = e;
		(t->taille_utilisee) ++;
}



int valeurIemeElementTabDynEntier (const TableauDynamiqueEntier* t, unsigned int i)
{
	return (t-> ad)[i];
}

int* adresseIemeElementTabDynEntier (const TableauDynamiqueEntier* t, unsigned int i)
{
	return &((t-> ad)[i]);
}



void modifierValeurIemeElementTabDynEntier(TableauDynamiqueEntier* t, int e, unsigned int i)
{
	(t-> ad)[i] = e;
}






void supprimerElementTabDynEntier( TableauDynamiqueEntier* t, int position )
{
	int i;
	int* temp;
	if((t-> capacite)/3 > (t-> taille_utilisee))
	{
		(t-> capacite) = (t-> capacite)/2;
		temp = (t-> ad);
		(t-> ad) = (int*) malloc((t-> capacite) * sizeof(int));
		for(i=0;i<position;i++)
		{
			(t-> ad)[i] = temp [i];
		}
		for(i=position+1;i<(t->taille_utilisee);i++)
		{
			(t-> ad)[i-1] = temp [i];
		}
		(t-> taille_utilisee) --;
		free(temp);
	}
	else
	{
		for(i=position+1;i<(t->taille_utilisee);i++)
		{
			(t-> ad)[i-1] = (t-> ad) [i];
		}
		(t-> taille_utilisee) --;
	}
}
