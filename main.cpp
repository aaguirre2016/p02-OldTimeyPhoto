#include <iostream>
#include <string>
#include <vector>
#include "bitmap.h"

using namespace std;

int main ()
{
        Bitmap image;
        vector <vector <Pixel> > bmp;
        Pixel rgb;
        string file;
        bool validBmp;
        do{
                cout << "enter filename: " << endl;
                cin >> file; 
                image.open(file);
                validBmp = image.isImage();
        }

        while (validBmp!=true);

        if (validBmp == true )
        {
                // matrix that changes pixels
                bmp = image.toPixelMatrix();
                for (int i=0; i < bmp.size() ; i++)
                { 
                        for (int j=0; j < bmp[0].size(); j++) 
                        {
                                // takes out color, turning it greyscale
                                rgb = bmp [i][j];
                                int grey = rgb.red + rgb.blue + rgb.green;
                                grey = grey/3;
                                rgb.red = grey;
                                rgb.blue = grey;
                                rgb.green = grey;
                                // put changed image back into matrix
                                bmp [i][j] = rgb;
                        }
                }
                // saves picture as new file, as picture.bmp
                image.fromPixelMatrix(bmp);
                image.save("picture.bmp");

        }



        return 0;
}

