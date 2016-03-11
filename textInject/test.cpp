#include "gd.h"
#include "gdfontg.h"
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int getexten(string path){
    int result;
    string exten = path.substr(path.find_last_of(".")+1);
    
    transform(exten.begin(),exten.end(), exten.begin(), ::tolower);

    if(exten== "jpg"||exten=="jpeg"){
        return 0;
    } else if(exten=="png"){
        return 1;
    } else {return 2;}
}

string getFileName(const string& s){
    char sep = '/';

    #ifdef _WIN32
       sep = '\\';
    #endif

       size_t i = s.rfind(sep, s.length());
       if (i != string::npos) {
          return(s.substr(i+1, s.length() - i));
       }

       return("");
}
// void generateMeme(string memeText, string inPath, string outPath){

// }

int main (int argc, char *argv[])
{

        gdImagePtr im;
        FILE* out;
        FILE* in;
        int black, white, len;

        string testPath = "test/hello/bro/blaze/internetKid.jpg";
        string inPath, outPath, fileName, fileExt, postMemeName;

        inPath = "mypicture.jpg";
        outPath = "testFilePath/";
        fileName = getFileName(inPath);
        fileExt = getexten(fileName);
        // postMemeName =  fileName.insert(fileName.length()-4,"MEME");

        // string testFinalName = outPath+postMemeName;
        string testFinalName = outPath+inPath;
        // if (getexten())

        const char* stuff = testFinalName.c_str();

        /* String to draw. */
        in = fopen("mypicture.jpg", "rb");
        string memeText = "When you meme too hard but have no intention of stopping";
        len = memeText.length();
        unsigned char *val=new unsigned char[len+1];
        strcpy((char *)val,memeText.c_str());

        im = gdImageCreateFromJpeg(in);
        /* Background color (first allocated) */
        black = gdImageColorAllocate(im, 0, 0, 0);  
        /* Allocate the color white (red, green and blue all maximum). */
        white = gdImageColorAllocate(im, 255, 255, 255);  
        /* Draw a centered string. */
        gdImageString(im, gdFontGetGiant(),
          im->sx / 2 - (len * gdFontGetGiant()->w / 2),
          im->sy / 12 - gdFontGetGiant()->h / 2,
          val, black);
        out = fopen("dankShit.jpg", "wb");
        if (!out) {
                fprintf(stderr, "Can't create dankShit.png\n");
                return 1;
        }
        gdImagePng(im, out);
        fclose(out);
        /* ... Do something with the image, such as 
          saving it to a file... */
        /* Destroy it */
        gdImageDestroy(im);
}