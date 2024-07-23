#include "image_io.h"
#include "bmplib.h"
#include <iostream>

extern unsigned char imagGS[SIZE][SIZE];

void lightenDarkenFilter() {
    loadImage();
    char BlackImage[SIZE][SIZE];
    int x;
    std::cout << "Enter 1 to lighten or 0 to darken the image: ";
    std::cin >> x;
    if (x == 1) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imagGS[i][j] = (((255 - imagGS[i][j]) / 2) + imagGS[i][j]);
            }
        }
    } else if (x == 0) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                BlackImage[i][j] = 0;
                imagGS[i][j] = (imagGS[i][j] + BlackImage[i][j]) / 4;
            }
        }
    }
}
