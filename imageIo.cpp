#include "imageIo.h"
#include "bmplib.h"
#include <iostream>
#include <unistd.h>

extern unsigned char imagGS[SIZE][SIZE];
extern unsigned char imagGS2[SIZE][SIZE];

void loadImage() {
    std::string imagFileName, path = "\\imgs\\";
    std::cout << "Enter the source image file name: ";
    std::cin >> imagFileName;

    imagFileName += ".bmp";
    path += imagFileName;

    char cwd[PATH_MAX];
    readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imagGS);
}

void loadImage2() {
    std::string imagFileName, path = "\\imgs\\";
    std::cout << "Enter the source image 2 file name: ";
    std::cin >> imagFileName;

    imagFileName += ".bmp";
    path += imagFileName;

    char cwd[PATH_MAX];
    readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imagGS2);
}

void saveImage() {
    std::string imageFileName, path = "\\imgs\\";
    std::cout << "Enter the target image file name: ";
    std::cin >> imageFileName;

    imageFileName += ".bmp";
    path += imageFileName;
    char cwd[PATH_MAX];
    writeGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imagGS);
}
