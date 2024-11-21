#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
    // Calculate the size in bits
    int totalBits = w * h * 24; // 24 bits per pixel for RGB color
    
    float size;
    if (strcmp(unit, "bt") == 0) {
        size = totalBits; // size in bits
    } else if (strcmp(unit, "ko") == 0) {
        size = totalBits / 1024.0; // size in kilobits
    } else if (strcmp(unit, "mo") == 0) {
        size = totalBits / (1024.0 * 1024.0); // size in megabits
    } else if (strcmp(unit, "go") == 0) {
        size = totalBits / (1024.0 * 1024.0 * 1024.0); // size in gigabits
    } else {
        // Invalid unit, returning 0 size
        return 0;
    }

    return size;
}