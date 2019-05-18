# image-transformers
An image processing project in C++. Filters altering (pgm fomat) images.

6 working filters :

rotation.cpp rotates an image. Usage: image-in.pgm angle-value image-out.pgm

pixel.ccp pixelates and image. Usage: image-in.pgm size-of-ploc image-out.pgm

sphere.cpp has a fish-eye effect on the image. Usage: image-in.pgm image-out.pgm

timewarp.ccp makes the center look like it is disappearing in distance. Usage: image-in.pgm image-out.pgm

swirl.cpp has a swirl effect on the image. Usage: image-in.pgm angle-value image-out.pgm
> The angle you enter should be very small, as the effect starts from the center and grows iteratively.

wave.cpp transforms the image to make it look wavy. Usage: image-in.pgm image-out.pgm
