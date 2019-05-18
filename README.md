# image-transformers
An image processing project in C++. Filters altering (pgm fomat) images.

6 working filters :

#rotation.cpp
Rotates an image. Usage: image-in.pgm angle-value image-out.pgm

#pixel.ccp 
Pixelates and image. Usage: image-in.pgm size-of-ploc image-out.pgm

#sphere.cpp
Has a fish-eye effect on the image. Usage: image-in.pgm image-out.pgm

#timewarp.ccp 
Makes the center look like it is disappearing in distance. Usage: image-in.pgm image-out.pgm

#swirl.cpp
Has a swirl effect on the image. Usage: image-in.pgm angle-value image-out.pgm
> The angle you enter should be very small, as the effect starts from the center and grows iteratively.

#wave.cpp
Transforms the image to make it look wavy. Usage: image-in.pgm image-out.pgm
