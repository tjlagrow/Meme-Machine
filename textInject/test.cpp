#include <stdio.h>
#include <gd.h>

int main (int argc, char *argv[])
{
        FILE *in;
        FILE *out;
        gdImagePtr im;
        int radius;
        /* Create an image of text on a circle, with an
                alpha channel so that we can copy it onto a
                background */
        in = fopen("mypicture.jpg", "rb");
        if (!in) {
                im = gdImageCreateTrueColor(300, 300);
        } else {
                im = gdImageCreateFromJpeg(in);
                fclose(in);
        }
        if (gdImageSX(im) < gdImageSY(im)) {
                radius = gdImageSX(im) / 2;
        } else {
                radius = gdImageSY(im) / 2;
        }
        gdImageStringFTCircle(
                im,
                gdImageSX(im) / 2,
                gdImageSY(im) / 2,
                radius,
                radius / 2,
                0.8,
                "arial",
                24,
                "that look when",
                "you look",
                gdTrueColorAlpha(240, 240, 255, 32));
        out = fopen("gdfx.png", "wb");
        if (!out) {
                fprintf(stderr, "Can't create gdfx.png\n");
                return 1;
        }
        gdImagePng(im, out);
        fclose(out);
        gdImageDestroy(im);
        return 0;
}
