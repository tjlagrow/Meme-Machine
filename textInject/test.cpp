#include "gd.h"
#include "gdfontl.h"
#include <string.h>

int main (int argc, char *argv[])
{
        FILE *in;
        FILE *out;
        gdImagePtr im;
        int black;
        int white;

        /* String to draw. */
        // unsigned char *s = {'h','e','l','l','o',0};
        char *s = reinterpret_cast<unsigned char*>"hello.";

        in = fopen("mypicture.jpg", "rb");

        im = gdImageCreateFromJpeg(in);
        /* Background color (first allocated) */
        black = gdImageColorAllocate(im, 0, 0, 0);  
        /* Allocate the color white (red, green and blue all maximum). */
        white = gdImageColorAllocate(im, 255, 255, 255);  
        /* Draw a centered string. */
        gdImageString(im, gdFontGetLarge(), 0, 0, s, white);

        /* ... Do something with the image, such as 
          saving it to a file... */
        out = fopen("gdfx.png", "wb");
        if (!out) {
                fprintf(stderr, "Can't create gdfx.png\n");
                return 1;
        }
        gdImagePng(im, out);
        fclose(out);


        /* Destroy it */
        gdImageDestroy(im);
}