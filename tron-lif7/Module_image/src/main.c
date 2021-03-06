#include<stdlib.h>
#include<stdio.h>
#include"image.h"
#include"pixel.h"

#define TailleX 1000
#define TailleY 700
#define precision 10

int main()
{
    FILE* fichier;
    fichier=fopen("grilleAnalyse.txt","r");
    Image *image;
    int i,j;
    int nombre;
    Pixel pixel;
    FILE* fichier2;

    Image *image2;
    image=imCreer(TailleX/precision,TailleY/precision);
    for(j=0;j<(TailleY/precision);j++){
        for(i=0;i<TailleX/precision;i++){
                if(fscanf(fichier,"%d ",&nombre)>0){
                    if(nombre>=0){
                        pixel.r=250-((unsigned char)nombre/1.5);
                        pixel.b=250-((unsigned char)nombre/1.5);
                        pixel.g=250-((unsigned char)nombre/1.5);
                        setPix(image,i,j,&pixel);
                    }
                    else{
                        pixel.r=0;
                        pixel.b=128;
                        pixel.g=255;
                        setPix(image,i,j,&pixel);
                    }
                }
        }
    }
    fclose(fichier);
    imSauver( image, "Analyse.ppm");
    imOuvrir( image, "Analyse.ppm");
    imDetruire(&image);

    fichier2=fopen("grilleDistances.txt","r");
    image2=imCreer(TailleX/precision,TailleY/precision);
    for(j=0;j<(TailleY/precision);j++){
        for(i=0;i<TailleX/precision;i++){
                if(fscanf(fichier,"%d ",&nombre)>0){
                    if(nombre>=0){
                        pixel.r=255-(nombre);
                        pixel.b=255-(nombre);
                        pixel.g=255-(nombre);
                        setPix(image,i,j,&pixel);
                    }
                    else{
                        pixel.r=0;
                        pixel.b=128;
                        pixel.g=255;
                        setPix(image,i,j,&pixel);
                    }
                }
        }
    }
    imSauver( image2, "Distances.ppm");
    imOuvrir( image2, "Distances.ppm");
    fclose(fichier2);
    imDetruire(&image2);



    return 0;
}

