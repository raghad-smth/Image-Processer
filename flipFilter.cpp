#include "image_io.h"
#include <iostream>
#include "bmplib.h"

extern unsigned char imagGS[SIZE][SIZE];

void flipFilter() {
    loadImage();
    std::cout << "for the horizontally flipping enter (1)\n";
    std::cout << "for the vertically flipping enter (2)\n";
    int ch;
    std::cin >> ch;
    if (ch == 1) {
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                std::swap(imagGS[i][j], imagGS[SIZE - i][j]);
            }
        }
    } else if (ch == 2) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                std::swap(imagGS[i][j], imagGS[i][SIZE - j]);
            }
        }
    }
}
