#include "encrypt.hpp"
#include <random>	

#define ITER_COUNT  50
#define FLIP_CHANCE 1000
#define MAX_SHIFT   3    // proportion of the image that can be shifted

MessageEncryption::MessageEncryption(){this->key = 1;}
MessageEncryption::MessageEncryption(int key){this->key = key;}
MessageEncryption::~MessageEncryption(){}
    
    
void
MessageEncryption::encrypt(std::string imgpath,std::string outpath){
    std::default_random_engine rand (this->key);
    int currand; int i, j;
    int width, height;
    FILE* in, *out; gdImagePtr img;
    int ext = getexten(imgpath);
    
    in = fopen(imgpath.c_str(),"rb");
    if(ext==0){
        img=gdImageCreateFromJpeg(in);
    } else if(ext==1){
        img=gdImageCreateFromPng(in);
    } else{
        exit(1);
    }
    fclose(in);

    width = gdImageSX(img); height = gdImageSY(img);
    
    for(i=0;i<ITER_COUNT;i++){
        currand = rand()%FLIP_CHANCE;
        if(currand==0){ // flip horizontally
            fliphoriz(img);
        } else if(currand==1){ // flip vertically
            flipvert(img);
        } else if(currand<=1+FLIP_CHANCE/2){ // shift some rows
            for(j=0;j<=(currand%(width/3));j++){
                shiftcol(img,(3*i+j)%width,(7*currand+4*i)%height);
            }
        } else{  // shift some columns
            for(j=0;j<=(currand%(height/3));j++){
                shiftrow(img,(3*i+j)%height,(7*currand+4*i)%width);
            }
        }
    }

    ext = getexten(outpath);
    out = fopen(outpath.c_str(),"wb");
    if(ext==0){
        gdImageJpeg(img,out,-1);
    } else if(ext==1){
        gdImagePng(img,out);
    } else{
        exit(1);
    }
    fclose(out); gdImageDestroy(img);
}

std::string
MessageEncryption::encrypt(std::string str){return str;}
    

void
MessageEncryption::decrypt(std::string imgpath,std::string outpath){
    std::default_random_engine rand (this->key);
    int currand; int i, j;
    int width, height;
    int randli[ITER_COUNT];
    FILE* in, *out; gdImagePtr img;
    int ext = getexten(imgpath);
    
    in = fopen(imgpath.c_str(),"rb");
    if(ext==0){
        img=gdImageCreateFromJpeg(in);
    } else if(ext==1){
        img=gdImageCreateFromPng(in);
    } else{
        exit(1);
    }
    fclose(in);

    width = gdImageSX(img); height = gdImageSY(img);
    for(i=0;i<ITER_COUNT;i++){
        randli[i] = rand()%FLIP_CHANCE;
    }

    for(i=ITER_COUNT-1;i>=0;i--){
        currand = randli[i];
        if(currand==0){ // flip horizontally
            fliphoriz(img);
        } else if(currand==1){ // flip vertically
            flipvert(img);
        } else if(currand<=1+FLIP_CHANCE/2){ // shift some rows
            for(j=0;j<=(currand%(width/3));j++){
                shiftcol(img,(3*i+j)%width,(-7*currand-4*i)%height+height);
            }
        } else{  // shift some columns
            for(j=0;j<=(currand%(height/3));j++){
                shiftrow(img,(3*i+j)%height,(-7*currand-4*i)%width+width);
            }
        }
    }
    out = fopen(outpath.c_str(),"wb");
    
    ext = getexten(outpath);
    if(ext==0){
        gdImageJpeg(img,out,-1);
    } else if(ext==1){
        gdImagePng(img,out);
    } else{
        exit(1);
    }
    fclose(out); gdImageDestroy(img);
}

std::string
MessageEncryption::decrypt(std::string str){return str;}
