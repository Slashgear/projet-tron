/**
	\file [TableauDynamiqueMur.c]
	 Module qui gère les tableaux dynamiques des Murs
	\author {Antoine.C,Matthieu.B}
	\version 1.0
	\date 19 mars 2013
*/
#include "TableauDynamiqueMur.h"
#include <stdio.h>
#include "Mur.h"
#include <stdlib.h>


unsigned int TabDynMurGetCapacite(const TableauDynamiqueMur* TabDynMur){
    return TabDynMur->capacite;
}
unsigned int TabDynMurGetTaille_utilisee(const TableauDynamiqueMur* TabDynMur){
    return TabDynMur->taille_utilisee;
}
Mur* TabDynMurGetAd(const TableauDynamiqueMur* TabDynMur){
    return TabDynMur->ad;
}

void TabDynMurSetCapacite(TableauDynamiqueMur* TabDynMur, unsigned int capacite){
    TabDynMur->capacite=capacite;
}
void TabDynMurSetTaille_utilisee(TableauDynamiqueMur* TabDynMur,unsigned int taille){
    TabDynMur->taille_utilisee=taille;
}
void TabDynMurSetAd(TableauDynamiqueMur* TabDynMur,Mur* ad){
    TabDynMur->ad=ad;
}




void initialiserTabDynMur (TableauDynamiqueMur * t)
{
	t -> ad = (Mur *)malloc(sizeof(Mur));
	t -> capacite = 1;
	t -> taille_utilisee = 0;
}


void testamentTabDynMur (TableauDynamiqueMur *t)
{
	if(t -> ad != 0)
	{
		free(t -> ad);
		t -> capacite = 0;
		t -> taille_utilisee = 0;
	}
}



void ajouterElementTabDynMur(TableauDynamiqueMur *t, Mur e)
{
	if((t-> taille_utilisee) == (t-> capacite))
	{
		int i;
		Mur * temp = t-> ad;
		(t->ad) = (Mur*) malloc(2*(t->capacite)*sizeof(Mur));
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



Mur valeurIemeElementTabDynMur (const TableauDynamiqueMur *t, unsigned int i)
{
	return (t-> ad)[i];
}

Mur* adresseIemeElementTabDynMur (const TableauDynamiqueMur *t, unsigned int i)
{
	return &((t-> ad)[i]);
}



void modifierValeurIemeElementTabDynMur(TableauDynamiqueMur *t, Mur e, unsigned int i)
{
	(t-> ad)[i] = e;
}






void supprimerElementTabDynMur( TableauDynamiqueMur *t, int position )
{
	int i;
	Mur* temp;
	if((t-> capacite)/3 > (t-> taille_utilisee))
	{
		(t-> capacite) = (t-> capacite)/2;
		temp = (t-> ad);
		(t-> ad) = (Mur*) malloc((t-> capacite) * sizeof(Mur));
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



