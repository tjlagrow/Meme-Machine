#include "encrypt.hpp"
#include <random>	

#define ITER_COUNT  1000
#define FLIP_CHANCE 1000
#define MAX_SHIFT   3    // proportion of the image that can be shifted

MessageEncryption::MessageEncryption(){this->key = 1;}
MessageEncryption::MessageEncryption(int key){this->key = key;}
MessageEncryption::~MessageEncryption(){}
    
    
gdImagePtr
MessageEncryption::encrypt(gdImagePtr img){
    std::default_random_engine rand (this->key);
    int currand; int i; int j;
    int width = gdImageSX(img); int height = gdImageSY(img);

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
    return img;
}

std::string
MessageEncryption::encrypt(std::string &str){return NULL;}
    

gdImagePtr
MessageEncryption::decrypt(gdImagePtr img){
    std::default_random_engine rand (this->key);
    int currand; int i; int j;
    int width = gdImageSX(img); int height = gdImageSY(img);
    int randli[ITER_COUNT];

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
    return img;
}

std::string
MessageEncryption::decrypt(std::string &str){return NULL;}

int main(){
    gdImagePtr im;
    std::FILE *in, *out1, *out2;
    MessageEncryption me (10);
    
    printf("a\n");

    in = fopen("yoshistuff.png","rb");
    im = gdImageCreateFromPng(in);
    
    printf("%d %d \n",gdImageSX(im),gdImageSY(im));
    
    me.encrypt(im);
    
    out1 = fopen("yonew.png","wb");
    out2 = fopen("yoold.png","wb");

    gdImagePng(im, out1);

    me.decrypt(im);

    gdImagePng(im,out2);
    
    fclose(in); fclose(out1); fclose(out2);
    
    gdImageDestroy(im);
}
