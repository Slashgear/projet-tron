#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"image.h"
#include"pixel.h"

void imInit(Image* Im,int dimx, int dimy )
{
    if((dimx > 0)&&(dimy > 0))
    {
        Im->dimx = dimx;
        Im->dimy = dimy;
        Im->tab = (Pixel*)malloc(dimx*dimy*sizeof(Pixel));
    }
    else{printf("erreur, dimensions <= 0");}
}


void imLibere(Image * Im)
{
    free(Im->tab);
    Im->dimx = 0;
    Im->dimy = 0;
}


Image* imCreer(int dimx, int dimy)
{
    Image* im;
    im = (Image*)malloc(sizeof(Image));
    imInit(im, dimx, dimy);

    return im;
}


void imDetruire(Image ** pim)
{
    imLibere(*pim);
    free(*pim);
}


Pixel getPix(const Image* Im, int x, int y )
{		
				Pixel pi = Im->tab[y*(Im->dimx)+x];
    assert((x >= 0)&&(y >= 0)&&(x <= Im->dimx)&&(y <= Im->dimy));
    return pi;
}


void setPix(Image* Im, int x,int y , const Pixel* couleur)
{
    assert((x >= 0)&&(y >= 0)&&(x <= Im->dimx)&&(y <= Im->dimy));
    Im->tab[y*(Im->dimx)+x].r = couleur->r;
    Im->tab[y*(Im->dimx)+x].g = couleur->g;
    Im->tab[y*(Im->dimx)+x].b = couleur->b;
}




void  imDessineRectangle(Image * Im, int  Xmin,int Ymin,int Xmax,int Ymax ,const Pixel * couleur)
{
				int i, j;
    assert((Xmin >= 0)&&(Ymin >= 0)&&(Xmin <= Im->dimx)&&(Ymin <= Im->dimy)&&(Xmax >= 0)&&(Ymax >= 0)&&(Xmax <= Im->dimx)&&(Ymax <= Im->dimy));
    
    for(i=Xmin;i<Xmax;i++)
    {
        for(j=Ymin;j<Ymax;j++)
        {
            setPix(Im, i, j, couleur);
        }
    }
}


void  imEffacer(Image * Im, const Pixel * couleur)
{
  imDessineRectangle(Im,0,0,Im->dimx,Im->dimy,couleur);
}


void imSauver(const Image *pIm, const char filename[])
{
    FILE* f;
	Pixel pix;
	int x,y;

    f = fopen(filename, "w");
    if (f==NULL)
    {
        printf("Erreur lors de l'ouverture de %s\n", filename);
        assert( f );
    }
    fprintf( f , "P3\n");                           /* P3 = ascii avec 3 composantes RVB*/
    fprintf( f , "%d %d\n", pIm->dimx, pIm->dimy);      /*dimension de l'image*/
    fprintf( f , "255\n");                          /*chaque composante est comprise entre 0 et 255*/

    for(y=0;y<pIm->dimy;++y)
        for(x=0;x<pIm->dimx;++x)
        {
            pix = getPix(pIm,x,y);
            fprintf(f, "%d %d %d  ", pix.r, pix.g, pix.b);
        }
    printf("Sauvegarde de l'image %s ...OK\n", filename);
    fclose(f);
}

void imOuvrir(Image *pIm, const char filename[])
{
    FILE* f;
	Pixel pix;
	int x, y, dimx, dimy;

    f = fopen(filename, "r");
    if (f==NULL)
    {
        printf("Erreur lors de l'ouverture de %s\n", filename);
        assert( f );
    }

    assert( fscanf( f , "P3 \n %d %d \n 255 \n", &dimx, &dimy) ==2 );
    imInit( pIm, dimx, dimy);

    for(y=0;y<pIm->dimy;++y)
        for(x=0;x<pIm->dimx;++x)
        {
            assert( fscanf(f, "%d %d %d  ", (int *)&pix.r, (int *)&pix.g, (int *)&pix.b)==3 );
			setPix(pIm,x,y,&pix);
        }
    fclose(f);
    printf("Lecture de l'image %s ...OK\n", filename);
}

void imPrintf(const Image *pIm)
{
	int x,y;
	Pixel pix;

    printf( "%d %d\n", pIm->dimx, pIm->dimy);      /* dimension de l'image*/

    for(y=0;y<pIm->dimy;++y)
    {
        for(x=0;x<pIm->dimx;++x)
        {
            pix = getPix(pIm,x,y);
            printf("%d %d %d  ", pix.r, pix.g, pix.b);
        }
        printf("\n");
    }
}

void  imTestRegression()
{
    Pixel couleur={ 0, 128, 255 };
    Pixel couleur2;
    Image image1;
    Image *image2;

    imInit(&image1,1,1);
    printf("Après imInit Dimx %d Dimy %d et addresse du tableau %p\n",image1.dimx, image1.dimy,(void *)image1.tab);
    imLibere(&image1);
    printf("Après imlibère Dimx %d Dimy %d et addresse du tableau %p\n",image1.dimx, image1.dimy,(void *)image1.tab);
    image2=imCreer(10,10);
    printf("Après imCreer Dimx %d Dimy %d et addresse du tableau %p\n",image2->dimx, image2->dimy,(void *)image2->tab);
    setPix(image2,1,1,&couleur);
    couleur=getPix(image2,1,1);
    printf("Après setPix et getPix on obtient %d de rouge, %d de bleu,%d de vert \n",couleur.r,couleur.b,couleur.g);
    imDessineRectangle( image2, 0, 0, 10, 10,&couleur2);
    imSauver( image2, "data/testregression.ppm");
    imOuvrir( image2, "data/testregression.ppm");
    imDetruire(&image2);
}
