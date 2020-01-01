#include "imagefunctions.h"
#include "bmplib.h"

using namespace std;


void flip90 (unsigned char in[SIZE][SIZE][RGB],unsigned char out[SIZE][SIZE][RGB]) {

 
 int temp[SIZE][SIZE][RGB];   

for (int i = 0; i < SIZE; i++){
      for (int j = 0; j < SIZE; j++){
         for (int k = 0; k < RGB; k++) {
      
         temp[i][j][k] = in[j][i][k];
         //out[i][j][k] = temp[i][SIZE-j][k];
         }
      }
   }

 for (int i = 0; i < SIZE; i++){
      for (int j = 0; j < SIZE; j++){
         for (int k = 0; k < RGB; k++) {
      
         out[i][j][k] = temp[i][SIZE-j][k];
         }
      }
   } 

}

void flip180 (unsigned char in[SIZE][SIZE][RGB],unsigned char out[SIZE][SIZE][RGB]) {



for (int i = 0; i < SIZE; i++){
      for (int j = 0; j < SIZE; j++){
         for (int k = 0; k < RGB; k++) {
      
         out[i][j][k] = in[SIZE-i][j][k];
         }
      }
   } 
}


void mirror (unsigned char in[SIZE][SIZE][RGB],unsigned char out[SIZE][SIZE][RGB]) {

   for (int i = 0; i < SIZE; i++){
      for (int j = 0; j < SIZE; j++){
         for (int k = 0; k < RGB; k++) {
      
         out[i][j][k] = in[i][SIZE-j][k];
         }
      }
   } 

}


void grey_scale (unsigned char in[SIZE][SIZE][RGB],unsigned char out[SIZE][SIZE]) {

	 for (int i=0; i<SIZE; i++) {
      for (int j=0; j<SIZE; j++) {
         unsigned char r = in[i][j][0];
         unsigned char g = in[i][j][1];
         unsigned char b = in[i][j][2];
         out[i][j] = (unsigned char)(.299*r + .587*g + .114*b);
      }
   }
}


void color_inversion (unsigned char in[SIZE][SIZE][RGB],unsigned char out[SIZE][SIZE][RGB]) {
	for (int i=0; i<SIZE; i++) {
      for (int j=0; j<SIZE; j++) {
         for (int c=0; c<3; c++) {
            out[i][j][c] = 255-in[i][j][c];
         }
      }
   }

}


void zoom_in (unsigned char in[SIZE][SIZE][RGB],unsigned char out[SIZE][SIZE][RGB]) {

   for(int i=0; i < SIZE; i++){
    for(int j=0; j < SIZE; j++){
      for(int k = 0; k< RGB; k++) {
      out[i][j][k] = in[SIZE/4 + i/2][SIZE/4 + j/2][k];
    }
  }
}

}