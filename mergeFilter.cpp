#include "image_io.h"
#include "bmplib.h"

extern unsigned char imagGS[SIZE][SIZE];
extern unsigned char imagGS2[SIZE][SIZE];

void mergeFilter() {
    loadImage();
    loadImage2();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            imagGS[i][j] = (imagGS[i][j] + imagGS2[i][j]) / 2;
        }
    }
}
