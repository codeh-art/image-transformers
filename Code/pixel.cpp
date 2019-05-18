#include <stdio.h>
#include <iostream>
#include "image_ppm.h"

using namespace std;

int main(int argc, char* argv[]) {
	char cNomImgLue[250], cNomImgEcrite[250];
	int nH, nW, nTaille, n;
  
	if (argc != 4) {
       printf("Usage: ImageIn.pgm taille_carre ImageOut.pgm \n"); 
       exit (1) ;
   	}
   
   	sscanf (argv[1],"%s",cNomImgLue);
    sscanf (argv[2],"%d",&n);
    sscanf (argv[3],"%s",cNomImgEcrite);

   	OCTET *ImgIn, *ImgOut;
   
   	lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   	nTaille = nH * nW;
  
   	allocation_tableau(ImgIn, OCTET, nTaille);
   	lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   	allocation_tableau(ImgOut, OCTET, nTaille);

    double total; int aie;
   	for (int i = 0; i < nH; i+=n) {
		  for (int j = 0; j < nW; j+=n) {
        total = 0; aie = 0;
        for(int a = 0; a < n; a++) {
          for(int b = 0; b < n; b++) {
            if((i+a)*nW+j+b > nTaille) {
              aie++;
            }
            else {
              total+= ImgIn[(i+a)*nW+j+b];
            }
          }
        }
        total = total/((n*n)-aie);
        for(int a = 0; a < n; a++) {
          for(int b = 0; b < n; b++) {
            if((i+a)*nW+j+b < nTaille) {
              ImgOut[(i+a)*nW+j+b] = total;
            }
            
          }
        }
   		}
   	}

  ecrire_image_pgm(cNomImgEcrite, ImgOut,  nH, nW);
  free(ImgIn);
  return 1;
}