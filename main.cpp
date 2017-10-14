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
    cout<<"enter filename:"<<endl;
    cin>>file; 
    image.open(file);
    validBmp=image.isImage();
    }

while(validBmp!=true);

 if (validBmp == true )
 { 
  bmp = image.toPixelMatrix();
  for (int i=0; i < bmp.size() ; i++)
  { 
    for (int j=0; j < bmp[0].size(); j++) 
    {
  // take all the redness out of the top-left pixel
        rgb = bmp [i][j];
        int grey = rgb.red + rgb.blue + rgb.green;
        grey = grey/3;
        rgb.red = grey;
        rgb.blue = grey;
        rgb.green = grey;
  // put changed image back into matrix, update the bitmap and save it
        bmp [i][j] = rgb;
    }
  }
 
  image.fromPixelMatrix(bmp);
  image.save("picture.bmp");

 }



   return 0;
}

