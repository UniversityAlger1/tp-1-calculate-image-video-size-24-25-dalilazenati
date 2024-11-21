#include "config/grayScaleImage.h"
// Parameters:
//   w: width of the image
//   h: height of the image
// Return value
//   grayScale size of the image Bitmap (in byte)
float grayScaleImage(int w, int h) {
   int rowSize = ((w + 3) / 4) * 4;
   
    int imageSize = rowSize * h;
    
    return imageSize;
}