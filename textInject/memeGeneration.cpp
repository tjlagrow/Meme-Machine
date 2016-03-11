#include "memeGeneration.hpp"

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

void Meme::generateMeme(string memeText, string inPath, string outPath){

     gdImagePtr im;
    FILE* out;
    FILE* in;
    int black, white, len, fileExt;
    string fileName;

    fileName = getFileName(inPath);

    if (fileName.length()==0){
        fileName = inPath;
    }

    fileExt = getexten(fileName);

    // string finalOutPath = outPath+fileName; in case path is given without file name

    const char* strFinalOutPath = outPath.c_str();
    const char* strFinalInPath = inPath.c_str();

    in = fopen(strFinalInPath, "rb");
    len = memeText.length();
    unsigned char *val=new unsigned char[len+1];
    strcpy((char *)val,memeText.c_str());

    if (fileExt==0){
        im = gdImageCreateFromJpeg(in);
    }

    else if (fileExt==1){
        im = gdImageCreateFromPng(in);
    }
    // im = gdImageCreateFromPng(in);
    black = gdImageColorAllocate(im, 0, 0, 0);  
    white = gdImageColorAllocate(im, 255, 255, 255);  
    gdImageString(im, gdFontGetGiant(),
      im->sx / 2 - (len * gdFontGetGiant()->w / 2),
      im->sy / 12 - gdFontGetGiant()->h / 2,
      val, black);
    out = fopen(strFinalOutPath, "wb");
    if (!out) {
            fprintf(stderr, "Can't create your meme. Serious bummer.\n");
    }

    if (fileExt==0){
        gdImageJpeg(im, out, -1);
    }

    else if (fileExt==1){
        gdImagePng(im, out);
    }
    // gdImagePng(im, out);
    fclose(out);
    gdImageDestroy(im);
}

int main (int argc, char *argv[]){
    string memeText = "This is a dank meme";
    // string inPath = "inTestFilePath/internetKid.png";
    string inPath = "mypicture.png";
    string outPath = "testFilePath/mypicture.png";
    // string outPath = "internetKid.png";
  generateMeme(memeText, inPath, outPath);


}