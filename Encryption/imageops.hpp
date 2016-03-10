/*
 * Image modification helper functions for encrypting
 */

#ifndef IMAGEOPS_HPP_
#define IMAGEOPS_HPP_

#include <string>
#include <gd.h>
#include <cstdio>

void shiftrow(gdImagePtr img, int row, int shamt);
void shiftcol(gdImagePtr img, int col, int shamt);

void fliphoriz(gdImagePtr img);
void flipvert(gdImagePtr img);

int getexten(std::string);

#endif
