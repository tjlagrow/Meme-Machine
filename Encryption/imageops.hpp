/*
 * An implementation of the Game of Livestock.
 */

#ifndef IMAGEOPS_HPP_
#define IMAGEOPS_HPP_

#include <gd.h>
#include <iostream>

void shiftrow(gdImagePtr &img, int row);
void shiftcol(gdImagePtr &img, int col);
void modpixel(gdImagePtr &pix, char r, char g, char b);

#endif
