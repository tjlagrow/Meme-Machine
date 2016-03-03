#include "imageops.hpp"

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

int main(){
    gdImagePtr im;
    std::FILE *in, *out;
    
    in = fopen("rs2ktotal.png","rb");
    
    im = gdImageCreateFromPng(in);
    
    printf("%d %d \n",gdImageSX(im),gdImageSY(im));

    for(int i = 0; i<100;i++){
        printf("x");
        shiftcol(im,i,100);
    }
    printf("\n");
    out = fopen("newrs.png","wb");
    
    gdImagePng(im, out);
    
    fclose(in); fclose(out);
    
    gdImageDestroy(im);
}
