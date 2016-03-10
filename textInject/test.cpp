#include "gd.h"
#include "gdfontl.h"
#include <cstring>
#include <cstdlib>
#include <string>

int main (int argc, char *argv[])
{
        // FILE *in;
        // FILE *out;
        // gdImagePtr im;
        // int black;
        // int white;

        // /* String to draw. */
        // // unsigned char *s = {'h','e','l','l','o',0};
        // std::string s = "abc";

        // in = fopen("mypicture.jpg", "rb");

        // im = gdImageCreateFromJpeg(in);
        // /* Background color (first allocated) */
        // black = gdImageColorAllocate(im, 0, 0, 0);  
        // /* Allocate the color white (red, green and blue all maximum). */
        // white = gdImageColorAllocate(im, 255, 255, 255);  
        // /* Draw a centered string. */
        // gdImageString(im, gdFontGetLarge(), 0, 0, s, white);

        // /* ... Do something with the image, such as 
        //   saving it to a file... */
        // out = fopen("gdfx.png", "wb");
        // if (!out) {
        //         fprintf(stderr, "Can't create gdfx.png\n");
        //         return 1;
        // }
        // gdImagePng(im, out);
        // fclose(out);


        // /* Destroy it */
        // gdImageDestroy(im);

        gdImagePtr im;
        FILE* out;
        FILE* in;
        int black;
        int white;
        int len;
        /* String to draw. */
        in = fopen("mypicture.jpg", "rb");
        std::string temp = "That look when you meming hard";
        len = temp.length();
        unsigned char *val=new unsigned char[len+1];
        strcpy((char *)val,temp.c_str());

        im = gdImageCreateFromJpeg(in);
        /* Background color (first allocated) */
        black = gdImageColorAllocate(im, 0, 0, 0);  
        /* Allocate the color white (red, green and blue all maximum). */
        white = gdImageColorAllocate(im, 255, 255, 255);  
        /* Draw a centered string. */
        gdImageString(im, gdFontGetLarge(),
          im->sx / 2 - (len * gdFontGetLarge()->w / 2),
          im->sy / 2 - gdFontGetLarge()->h / 2,
          val, white);
        out = fopen("gdfx.png", "wb");
        if (!out) {
                fprintf(stderr, "Can't create gdfx.png\n");
                return 1;
        }
        gdImagePng(im, out);
        fclose(out);
        /* ... Do something with the image, such as 
          saving it to a file... */
        /* Destroy it */
        gdImageDestroy(im);
}