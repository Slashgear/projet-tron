#include "TableauDynamique.h"
#include <stdio.h>
#include "Mur.h"
#include <stdlib.h>

unsigned int TabDynGetCapacite(const TableauDynamique* tabDyn){
    return tabDyn->capacite;
}
unsigned int TabDynGetTaille_utilisee(const TableauDynamique* tabDyn){
    return tabDyn->taille_utilisee;
}
Mur* TabDynGetAd(const TableauDynamique* tabDyn){
    return tabDyn->ad;
}

void TabDynSetCapacite(TableauDynamique* tabDyn, unsigned int capacite){
    tabDyn->capacite=capacite;
}
void TabDynSetTaille_utilisee(TableauDynamique* tabDyn,unsigned int taille){
    tabDyn->taille_utilisee=taille;
}
void TabDynSetAd(TableauDynamique* tabDyn,Mur* ad){
    tabDyn->ad=ad;
}




void initialiserTabDyn (TableauDynamique * t)
{
	t -> ad = (Mur *)malloc(sizeof(Mur));
	t -> capacite = 1;
	t -> taille_utilisee = 0;
}


void testamentTabDyn (TableauDynamique *t)
{
	if(t -> ad != 0)
	{
		free(t -> ad);
		t -> capacite = 0;
		t -> taille_utilisee = 0;
	}
}



void ajouterElementTabDyn(TableauDynamique *t, Mur e)
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



Mur valeurIemeElementTabDyn (const TableauDynamique *t, unsigned int i)
{
	return (t-> ad)[i];
}

Mur* adresseIemeElementTabDyn (const TableauDynamique *t, unsigned int i)
{
	return &((t-> ad)[i]);
}



void modifierValeurIemeElementTabDyn(TableauDynamique *t, Mur e, unsigned int i)
{
	(t-> ad)[i] = e;
}






void supprimerElementTabDyn( TableauDynamique *t, int position )
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



