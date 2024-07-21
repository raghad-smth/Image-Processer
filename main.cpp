//FCA  OOP Programming – 2023 - Assignment 1
//Program Name: main.cpp
//Last Modification Date: 9.10.2023
//Purpose:  Different functions that process 256x256 bitmap images read into a 2D array
/*
 * Name  : Raghad Mohammed Suliman Mohammed
 * ID    : 20220704
 * Email : raghaduni1004@gmail.com
 *

 * Name  : Aseel Mutasim Mohammed
 * ID    : 20220754
 * Email : aseelmutasim9204@gmail.com
 *
 * Name  :  Ruba Awadallah Mohammed
 * ID    :  20220843
 * Email :  rubaawadalla88@gmail.com
*/



#include <iostream>
#include <unistd.h>
#include "bmplib.h"

unsigned char imagGS[SIZE][SIZE];
unsigned char imagGS2[SIZE][SIZE];

using namespace std;

void loadImage () {
    string imagFileName, path = "\\imgs\\";
    cout << "Enter the source image file name: ";
    cin >> imagFileName;

    imagFileName+=".bmp";
    path += imagFileName;

    char cwd[PATH_MAX];
    readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()),imagGS);
};

void loadImage2 () {
    string imagFileName, path = "\\imgs\\";
    cout << "Enter the source image 2 file name: ";
    cin >> imagFileName;

    imagFileName+=".bmp";
    path += imagFileName;

    char cwd[PATH_MAX];
    readGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()),imagGS2);
};


void saveImage () {
    string imageFileName, path = "\\imgs\\";
    cout << "Enter the target image file name: ";
    cin >> imageFileName;

    imageFileName += ".bmp";
    path += imageFileName;
    char cwd[PATH_MAX];
    writeGSBMP(strcat(getcwd(cwd, sizeof(cwd)), path.c_str()), imagGS);

};

void blackAndWhiteFilter(){
    loadImage ();
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {

/* a code to convert to Black and White the image
   A better version should NOt use 127 but the
      average of the pixels */

            if (imagGS[i][j] > 120)
                imagGS[i][j] = 255;
            else
                imagGS[i][j] = 0;
        }
    }

};

void invertFilter() {
    /* it will call the loading function so the user doesn't have to do it manualey hence for all the
     function to work the picture must be loaded first
     */
    loadImage();

    /* subtracting the value of the pixle form 255 will result into the opposite level of brightness
     * for example : if the pixle is Black then its value will be = 0
     * 255 - 0 = 255 -> making it white (it's opposite level of brightness)
    */
    for (int i=0; i<SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            imagGS[i][j]= 255 - imagGS[i][j];
        }
    }

};

void mergeFilter() {
    loadImage ();
    loadImage2 ();
    //load image 1 and 2 after taking the file name from the user
    for(int i=0; i<SIZE; i++)
    {for(int j=0;j<SIZE;j++)
        {//to merge 2 pictures we add rows and columns of both pictures and get the average
            imagGS[i][j]=(imagGS[i][j]+imagGS2[i][j])/2;
        }
    }

};

void flipFilter(){
    loadImage ();
    /* this function flip the image horizontally and virtically you chosse the one you want */
    cout << "for the horizontally flipping enter (1)\n";
    cout << "for the virtically flipping enter (2)\n";
    int ch;
    cin >> ch;
    if (ch == 1) {
        /*for the horizontally flip i swapped each row with the row opposite it */
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                swap(imagGS[i][j], imagGS[SIZE - i][j]);
            }

        }
    }
    else if(ch==2){
/*for the virtically flip i swapped each column with the column opposite it */
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE/2; j++){
                swap(  imagGS[i][j],imagGS[i][SIZE-j]);
            }
        }


    }

};

void rotateFilter(){
    loadImage();
    int choice;
    cout << "Rotate (90), (180) or (270) degrees?" << endl;
    cin >> choice;

    // Creating a copy from the imagGS array to adjust the elements from it since imagGS will be changed
    char imagOr[SIZE][SIZE];
    memcpy(imagOr,imagGS, sizeof(imagOr));

    switch (choice) {

        case 90:{
            /*It works by making the first row as the last colum in the 2D array , then
             * second row as the one before the last colum and so on.
             * And after each row is completed "nextColum--" to start filling the previous colum
             * */
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
            /* For (180) rotaion the first row must be in the place of the last row and the second row
             * in the place of the one before the last one and so on.
             * */
            int preRow = 255;
            for(int i=0; i<SIZE; i++){
                for (int j=0; j<SIZE; j++){
                    imagGS[preRow][j] = imagOr[i][j];
                }
                preRow--;
            }
            break;
        }
        case 270: {
            /* it works by simply inverting the 90 degree case
             * By making the first row as the first colum, the second raw as the second colum and so on
             */
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

void lightenDarkenFilter() {
    loadImage ();
    char BlackImage[SIZE][SIZE];
    int x;
    cout << "enter 1 to lighten or 0 to darken the image";
    cin >> x;
    if (x == 1)
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                imagGS[i][j]=(((255-(imagGS[i][j]))/2)+imagGS[i][j]);
                //we subtract the nu of pixels from 255 so that it doesnt exceed the max
                // then divide by 2 because we want to lighen it by 50%
                //then add it to orignal pixels to not lose the form of the image
            }
        }
    else if (x==0)
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                BlackImage[i][j] = 0;
                //created a black image
                imagGS[i][j] = ((imagGS[i][j]) + BlackImage[i][j]) / 4;
                //to darken merge with a image photo and divide by 4 to make bits/pixel number smaller hence darker
            }
        }

};



void menu() {
    cout << "1- Black & White Filter" << endl;
    cout << "2- Invert Filter" << endl;
    cout << "3- Merge Filter" << endl;
    cout << "4- Flip Image" << endl;
    cout << "5- Rotate Image" << endl;
    cout << "6- Darken and Lighten Image" << endl;
    cout << "7- Detect Image Edges" << endl;
    cout << "8- Enlarge Image" << endl;
    cout << "9- Shrink Image" << endl;
    cout << "a- Mirror 1/2 Image" << endl;
    cout << "b- Shuffle Image" << endl;
    cout << "c- Blur Image" << endl;
    cout << "d- Crop Image" << endl;
    cout << "e- Skew Image Right" << endl;
    cout << "f- Skew Image Up" << endl;
    cout << "s- Save the image to a file" << endl;
    cout << "0- Exit" << endl;
    char choice = ' ';
    while (choice != '0') {
        cout << "Enter the number of the wanted operation : " << endl;
        cin >> choice;
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
            case 'f':
                break;
            case 's':
                saveImage();
                break;


        }
    }
};


int main() {


   menu();

    return 0;
}