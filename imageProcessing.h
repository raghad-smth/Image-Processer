#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

// Function declarations for image processing
void loadImage(unsigned char imagGS[SIZE][SIZE]);
void loadImage2(unsigned char imagGS2[SIZE][SIZE]);
void saveImage(unsigned char imagGS[SIZE][SIZE]);
void blackAndWhiteFilter(unsigned char imagGS[SIZE][SIZE]);
void invertFilter(unsigned char imagGS[SIZE][SIZE]);
void mergeFilter(unsigned char imagGS[SIZE][SIZE], unsigned char imagGS2[SIZE][SIZE]);
void flipFilter(unsigned char imagGS
