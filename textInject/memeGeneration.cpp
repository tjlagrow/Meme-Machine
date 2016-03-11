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

void generateMeme(string memeText, string inPath, string outPath){

     gdImagePtr im;
    FILE* out;
    FILE* in;
    int black, white, len;
    string fileName, fileExt, postMemeName;

    fileName = getFileName(inPath);

    if (fileName.length()==0){
        cout << "no path for input";
        fileName = inPath;
    }

    fileExt = getexten(fileName);

    string finalOutPath = outPath+fileName;

    const char* strFinalOutPath = finalOutPath.c_str();
    const char* strFinalInPath = inPath.c_str();

    in = fopen(strFinalInPath, "rb");
    len = memeText.length();
    unsigned char *val=new unsigned char[len+1];
    strcpy((char *)val,memeText.c_str());

    im = gdImageCreateFromPng(in);
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
    gdImagePng(im, out);
    fclose(out);
    gdImageDestroy(im);
}

int main (int argc, char *argv[]){
    string memeText = "This is a dank meme";
    // string inPath = "inTestFilePath/internetKid.jpg";
    string inPath = "mypicture.png";
    // string outPath = "testFilePath/";
    string outPath = "";
  generateMeme(memeText, inPath, outPath);


}