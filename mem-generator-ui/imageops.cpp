#include "imageops.hpp"
#include <algorithm>

void shiftrow(gdImagePtr img, int row, int shamt){
    int width = gdImageSX(img);
    int rowvals[width];
    
    for(int i=0;i<width;i++){
        rowvals[(i+shamt)%width] = gdImageGetPixel(img,i,row); // shifted row
    }
    
    for(int j=0;j<width;j++){
        gdImageSetPixel(img,j,row,rowvals[j]); // copy onto image
    }
}


void shiftcol(gdImagePtr img, int col, int shamt){
    int height = gdImageSY(img);
    int colvals[height];
    
    for(int i=0;i<height;i++){
        colvals[(i+shamt)%height] = gdImageGetPixel(img,col,i); // shifted row
    }
    
    for(int j=0;j<height;j++){
        gdImageSetPixel(img,col,j,colvals[j]); // copy onto image
    }
}

void fliphoriz(gdImagePtr img){
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int tempcolor;

    for(int i = 0; i<height; i++){
        for(int j = 0;j<width/2;j++){
            tempcolor = gdImageGetPixel(img, j,i);
            gdImageSetPixel(img,j,i,gdImageGetPixel(img,width-1-j,i));
            gdImageSetPixel(img,width-1-j,i,tempcolor);
        }
    }
}


void flipvert(gdImagePtr img){
    int width = gdImageSX(img);
    int height = gdImageSY(img);
    int tempcolor;

    for(int i = 0; i<width; i++){
        for(int j = 0;j<height/2;j++){
            tempcolor = gdImageGetPixel(img,i,j);
            gdImageSetPixel(img,i,j,gdImageGetPixel(img,i,height-1-j));
            gdImageSetPixel(img,i,height-1-j,tempcolor);
        }
    }
}

int getexten(std::string path){
    std::string exten = path.substr(path.find_last_of(".")+1);
    
    std::transform(exten.begin(),exten.end(), exten.begin(), ::tolower);

    if(exten== "jpg"||exten=="jpeg"){
        return 0;
    } else if(exten=="png"){
        return 1;
    } else {return 2;}
}
