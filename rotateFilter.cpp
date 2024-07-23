#include "image_io.h"
#include "bmplib.h"
#include <iostream>

extern unsigned char imagGS[SIZE][SIZE];

void rotateFilter() {
    loadImage();
    int choice;
    std::cout << "Rotate (90), (180) or (270) degrees?" << std::endl;
    std::cin >> choice;

    unsigned char imagOr[SIZE][SIZE];
    memcpy(imagOr, imagGS, sizeof(imagOr));

    switch (choice) {
        case 90: {
            int preColum = 255;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imagGS[j][preColum] = imagOr[i][j];
                }
                preColum--;
            }
            break;
        }
        case 180: {
            int preRow = 255;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imagGS[preRow][j] = imagOr[i][j];
                }
                preRow--;
            }
            break;
        }
        case 270: {
            int nextRow = 255;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    imagGS[i][j] = imagOr[j][nextRow];
                }
                nextRow--;
            }
            break;
        }
    }
}
