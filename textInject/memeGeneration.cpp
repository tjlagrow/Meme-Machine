#include "memeGeneration.hpp"
// #include "imageops.hpp"

#include "gd.h"
#include "gdfontg.h"
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int Meme::getexten(string path){
    int result;
    string exten = path.substr(path.find_last_of(".")+1);
    
    transform(exten.begin(),exten.end(), exten.begin(), ::tolower);

    if(exten== "jpg"||exten=="jpeg"){
        return 0;
    } else if(exten=="png"){
        return 1;
    } else {return 2;}
}

string Meme::getFileName(const string& s){
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

void Meme::generateMeme(string t, string inPath, string outPath){


        gdImagePtr im;
    int black;
    int white;
    int x, y, x1, y1, fileExt;
    char *err;
    char *err1;
    char *err2;
    FILE* out;
    FILE* in;
    double sz = 20.;
    int brect[8];


    string v = "/home/users/igarrett/Meme-Machine/textInject/impact.ttf";  /* User supplied font PLEASE WORK*/

    string fileName;

    fileName = getFileName(inPath);

    if (fileName.length()==0){
        fileName = inPath;
    }

    fileExt = getexten(fileName);


    char* s = const_cast <char*>(t.c_str());
    char* f = const_cast <char*>(v.c_str());

    const char* strFinalInPath = inPath.c_str();
    const char* strFinalOutPath = outPath.c_str();

    in = fopen(strFinalInPath, "rb");
    
    //Check extension
    if (fileExt==0){
        im = gdImageCreateFromJpeg(in);
    }

    else if (fileExt==1){
        im = gdImageCreateFromPng(in);
    }

    /* Background color (first allocated) */
    white = gdImageColorResolve(im, 255, 255, 255);
    black = gdImageColorResolve(im, 0, 0, 0);



    in = fopen(strFinalInPath, "rb");
    
    //Check extension
    if (fileExt==0){
        im = gdImageCreateFromJpeg(in);
    }

    else if (fileExt==1){
        im = gdImageCreateFromPng(in);
    }

    out = fopen(strFinalOutPath, "wb");


       //Split string if need be
    int memeLength = t.length();
    if (memeLength*12 > gdImageSX(im)){
        int brect1[8];
        int brect2[8];

        int i;
        int whiteSpace;
        for (i=0; i < memeLength/2; i++){
            if (t[i]==' '){
                whiteSpace = i;
            }
        }

        string SubStr1 = t.substr(0,whiteSpace);
        string SubStr2 = t.substr(whiteSpace,memeLength-1);
        char *subIn1 = const_cast <char*>(SubStr1.c_str());
        char *subIn2 = const_cast <char*>(SubStr2.c_str());

        /* obtain brect1 so that we can size the image */
        err1 = gdImageStringFT(NULL,&brect1[0],0,f,sz,0.,0,0,subIn1);
        if (err1) {fprintf(stderr,"%s",err1); return;}

        /* obtain brect1 so that we can size the image */
        err2 = gdImageStringFT(NULL,&brect2[0],0,f,sz,0.,0,0,subIn2);
        if (err2) {fprintf(stderr,"%s",err2); return;}

        //top text
        x = (gdImageSX(im)-(brect1[2]-brect1[0]))/2;
        y = 5 - brect1[7];

        //bottom text
        x1 = (gdImageSX(im)-(brect2[2]-brect2[0]))/2;
        y1 = gdImageSY(im)-(brect2[1]-brect2[6])-5;

        err1 = gdImageStringFT(im,&brect1[0],black,f,sz,0.0,x,y,subIn1);
        err2 = gdImageStringFT(im,&brect1[0],black,f,sz,0.0,x1,y1,subIn2);

        if (err1) {fprintf(stderr,"%s",err1); return;}
        if (err2) {fprintf(stderr,"%s",err2); return;}

    }

    else {
        err = gdImageStringFT(NULL,&brect[0],0,f,sz,0.,0,0,s);
        if (err) {fprintf(stderr,"%s",err); return;}


        x = (gdImageSX(im)-(brect[2]-brect[0]))/2;
        y = 5 - brect[7];

        err = gdImageStringFT(im,&brect[0],black,f,sz,0.0,x,y,s);
        if (err) {fprintf(stderr,"%s",err); return;}
    }


    /* Write img to stdout */
    if (fileExt==0){
        gdImageJpeg(im, out, -1);
    }

    else if (fileExt==1){
        gdImagePng(im, out);
    }

    /* Destroy it */
    gdImageDestroy(im);
}

int main (int argc, char *argv[]){
    Meme meme;

    string memeText = "This is a dank meme";
    // string inPath = "inTestFilePath/internetKid.png";
    string inPath = "mypicture.png";
    string outPath = "testFilePath/mypicture.png";
    // string outPath = "internetKid.png";
  meme.generateMeme(memeText, inPath, outPath);


}