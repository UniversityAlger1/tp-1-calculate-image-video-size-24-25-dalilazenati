#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in second of movie (colored image)
//   durationCredits: duration in second of credit (image Black/White)
//   unit: Unit of the output value. It could be 'bt' byte, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored video size (based on the unit passed parametter)
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Calculate the size of the color section in bytes
    long color_section_size = w * h * 3 * durationMovie * fps;  // 3 bytes per pixel for color
    
    // Calculate the size of the black and white section in bytes
    long credits_section_size = w * h * durationCredits * fps;  // 1 byte per pixel for B/W

    // Total size in bytes
    long total_size_bytes = color_section_size + credits_section_size;

    // Convert to the required unit
    if (strcmp(unit, "bt") == 0) {
        // Return size in bytes
        return total_size_bytes;
    } else if (strcmp(unit, "ko") == 0) {
        // Convert bytes to kilobits (1 byte = 8 bits, 1 kilobit = 1000 bits)
        return (total_size_bytes * 8) / 1000.0;
    } else if (strcmp(unit, "mo") == 0) {
        // Convert bytes to megabits (1 megabit = 1000 kilobits)
        return (total_size_bytes * 8) / 1000000.0;
    } else if (strcmp(unit, "go") == 0) {
        // Convert bytes to gigabits (1 gigabit = 1000 megabits)
        return (total_size_bytes * 8) / 1000000000.0;
    } else {
        // Unknown unit, return 0 by default
        return 0;
    }
}