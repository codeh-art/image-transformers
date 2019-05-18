#include <stdio.h>
#include <iostream>
#include "image_ppm.h"
#include <math.h>

using namespace std;

int main(int argc, char* argv[]) {
	char cNomImgLue[250], cNomImgEcrite[250];
	int nH, nW, nTaille, distx, disty, resx, resy;
	double pi = 3.1415; double angle = 0.025;
  
	if (argc != 3) {
       printf("Usage: ImageIn.pgm ImageOut.pgm \n"); 
       exit (1) ;
   	}
   
   	sscanf (argv[1],"%s",cNomImgLue) ;
   	sscanf (argv[2],"%s",cNomImgEcrite);

   	OCTET *ImgIn, *ImgOut;
   
   	lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   	nTaille = nH * nW;
   	int cx = nW / 2;
   	int cy = nH / 2;

    int nWave = 25;

  
   	allocation_tableau(ImgIn, OCTET, nTaille);
   	lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   	allocation_tableau(ImgOut, OCTET, nTaille);


    double newX, newY;

    double xo, yo;

    int factor = 20;

    for (int i = 0; i < nH; i++) {
      for (int j = 0; j < nW; j++) {
        ImgOut[i*nW+j] = ImgIn[i*nW+j];
      }
    }

    for (int i = 0; i < nW; i++) {
  	  for (int j = 0; j < nH; j++) { 
  			
  			xo = ((double)nWave * sin(2.0 * 3.1415 * (float)j / 128.0));
        yo = ((double)nWave * cos(2.0 * 3.1415 * (float)i / 128.0));


        newX = (i + xo);
        newY = (j + yo);


        if ((newY*nW+newX) < nTaille){
          ImgOut[j*nW+i] = ImgIn[(int)newY*nW+(int)newX];
        }

   		}
    }
    for (int i = 0; i < nH; i++) {
      for (int j = 0; j < nW; j++) {
        ImgIn[i*nW+j] = 0;
      }
    }

  ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
  free(ImgIn);
  return 1;
}