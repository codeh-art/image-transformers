#include <stdio.h>
#include <iostream>
#include "image_ppm.h"

using namespace std;

int main(int argc, char* argv[]) {
	char cNomImgLue[250], cNomImgEcrite[250];
	int nH, nW, nTaille, distx, disty, resx, resy;
	float pi = 3.1415; float angle;
  
	if (argc != 4) {
       printf("Usage: ImageIn.pgm rotation ImageOut.pgm \n"); 
       exit (1) ;
   	}
   
   	sscanf (argv[1],"%s",cNomImgLue);
    sscanf (argv[2],"%f",&angle);
    sscanf (argv[3],"%s",cNomImgEcrite);

   	OCTET *ImgIn, *ImgOut;
   
   	lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   	nTaille = nH * nW;
   	int cx = nW / 2;
   	int cy = nH / 2;
  
   	allocation_tableau(ImgIn, OCTET, nTaille);
   	lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   	allocation_tableau(ImgOut, OCTET, nTaille);

   	float c = cos(angle * pi / 180);
   	float s = sin(angle * pi / 180);

   	for (int i = 1; i < nW; i++) {
   		distx = i - cx;
		for (int j = 0; j < nH; j++) { 
			disty = j - cy;
			resx = distx * c - disty * s + cx;
			resy = distx * s + disty * c + cy;
   			if((resy*nW+resx) < nTaille) {
   				ImgOut[j*nW+i] = ImgIn[resy*nW+resx];
   			}
   			else {
   				ImgOut[j*nW+i] = 0;
   			}
   		}
   	}

  ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
  free(ImgIn);
  return 1;
}