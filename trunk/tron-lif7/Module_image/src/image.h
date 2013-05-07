#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED
#include<stdlib.h>
#include"pixel.h"
#include<stdio.h>


typedef struct {
               Pixel * tab;
               unsigned int dimx;
               unsigned int dimy;
             }Image;

/** imInit initialise dimx et dimy (après vérification) de la structure Image
puis alloue le tableau de pixel dans le tas*/
void imInit(Image* Im,int dimx, int dimy );

/**Libère la mémoire du tableau de pixels et met les
 champs dimx et dimy de la structure à 0*/
void imLibere(Image * Im);

/**imCreer alloue dans le tas une structure Image puis l'initialise
avec imInit => 2 lignes*/
Image* imCreer(int dimx, int dimy);

/** Libere le tableau de pixel en appelant imLibere puis détruit
la structure image*/
void imDetruire(Image ** pim);

/** getPix récupère le pixel de coordonnée (x,y) en vérifiant leur validité
la formule pour passer de 2D à un tab 1D est  pix[y*dimx+x]*/
Pixel getPix(const Image* Im, int x,int y ) ;

/** setPix modifie le pixel de coord (x,y)*/
void setPix(Image* Im, int x,int y , const Pixel* couleur);

/** dessine un rectangle de couleur dans l'image en utilisant setPix*/
void  imDessineRectangle(Image * Im, int  Xmin,int Ymin,int Xmax,int Ymax ,const Pixel * couleur);
/**efface l'image en appelant imDessineRectangle avec le bon rectangle*/
void  imEffacer(Image * Im, const Pixel * couleur);

void imSauver(const Image *pIm, const char filename[]);
void imOuvrir(Image *pIm, const char filename[]);
void imPrintf(const Image *pIm);

/** Effectue tout une série de test vérifiant que le module fonctionne et que les
champ de la structure sont conformes*/
void  imTestRegression();



#endif
