#ifndef IMAGEFUNCTIONS_H
#define IMAGEFUNCTIONS_H


#include "bmplib.h"

void flip90 (unsigned char in[SIZE][SIZE][RGB],unsigned char out[SIZE][SIZE][RGB]);
void flip180 (unsigned char in[SIZE][SIZE][RGB],unsigned char out[SIZE][SIZE][RGB]);
void mirror (unsigned char in[SIZE][SIZE][RGB],unsigned char out[SIZE][SIZE][RGB]);
void grey_scale (unsigned char in[SIZE][SIZE][RGB],unsigned char out[SIZE][SIZE]);
void color_inversion (unsigned char in[SIZE][SIZE][RGB],unsigned char out[SIZE][SIZE][RGB]);
void zoom_in (unsigned char in[SIZE][SIZE][RGB],unsigned char out[SIZE][SIZE][RGB]);

#endif