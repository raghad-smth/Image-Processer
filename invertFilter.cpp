#include "image_io.h"
#include "bmplib.h"

extern unsigned char imagGS[SIZE][SIZE];

void invertFilter() {
    loadImage();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            imagGS[i][j] = 255 - imagGS[i][j];
        }
    }
}
