// random_color.c
#include <stdlib.h>
#include <time.h>

// Helper function to convert an integer to a hex string
char* intToHex(int num) {
    static char hexStr[3]; // Store the hex string (2 characters + null terminator)
    const char hexDigits[] = "0123456789ABCDEF";

    hexStr[0] = hexDigits[(num >> 4) & 0xF]; // High nibble
    hexStr[1] = hexDigits[num & 0xF];         // Low nibble
    hexStr[2] = '\0';                         // Null terminator

    return hexStr;
}

char* generateRandomHexColor() {
    static char color[8]; // Store the color as a string (e.g., "#A3B2C7")

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random color in hexadecimal format
    color[0] = '#'; // Start with '#' for the hex color code

    // Generate random values for red, green, and blue
    char* r = intToHex(rand() % 256);
    color[1] = r[0];
    color[2] = r[1];

    char* g = intToHex(rand() % 256);
    color[3] = g[0];
    color[4] = g[1];

    char* b = intToHex(rand() % 256);
    color[5] = b[0];
    color[6] = b[1];

    color[7] = '\0'; // Null terminator to make it a valid string

    return color;
}