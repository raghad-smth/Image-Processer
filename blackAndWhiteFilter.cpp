#include "imageIo.h"
#include "bmplib.h"

extern unsigned char imagGS[SIZE][SIZE];

void blackAndWhiteFilter() {
    loadImage();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (imagGS[i][j] > 120)
                imagGS[i][j] = 255;
            else
                imagGS[i][j] = 0;
        }
    }
}
