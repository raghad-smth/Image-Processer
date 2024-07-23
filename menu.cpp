#include "blackAndWhiteFilter.h"
#include "flipFilter.h"
#include "imageIo.h"
#include "invertFilter.h"
#include "lightenDarkenFilter.h"
#include "mergeFilter.h"
#include "rotateFilter.h"
#include <iostream>

void menu() {
    std::cout << "1- Black & White Filter" << std::endl;
    std::cout << "2- Invert Filter" << std::endl;
    std::cout << "3- Merge Filter" << std::endl;
    std::cout << "4- Flip Image" << std::endl;
    std::cout << "5- Rotate Image" << std::endl;
    std::cout << "6- Darken and Lighten Image" << std::endl;
    std::cout << "7- Detect Image Edges" << std::endl;
    std::cout << "8- Enlarge Image" << std::endl;
    std::cout << "9- Shrink Image" << std::endl;
    std::cout << "a- Mirror 1/2 Image" << std::endl;
    std::cout << "b- Shuffle Image" << std::endl;
    std::cout << "c- Blur Image" << std::endl;
    std::cout << "d- Crop Image" << std::endl;
    std::cout << "e- Skew Image Right" << std::endl;
    std::cout << "f- Skew Image Up" << std::endl;
    std::cout << "s- Save the image to a file" << std::endl;
    std::cout << "0- Exit" << std::endl;
    char choice = ' ';
    while (choice != '0') {
        std::cout << "Enter the number of the wanted operation : " << std::endl;
        std::cin >> choice;
        switch (choice) {
            case '0':
                break;
            case '1':
                blackAndWhiteFilter();
                break;
            case '2':
                invertFilter();
                break;
            case '3':
                mergeFilter();
                break;
            case '4':
                flipFilter();
                break;
            case '5':
                rotateFilter();
                break;
            case '6':
                lightenDarkenFilter();
                break;
            case '7':
                break;
            case '8':
                break;
            case '9':
                break;
            case 'a':
                break;
            case 'b':
                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e':
                break;
            case 'f':
                break;
            case 's':
                saveImage();
                break;
        }
    }
}
