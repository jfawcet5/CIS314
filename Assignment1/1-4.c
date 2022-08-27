/*
 *
 *
 */

#include <stdio.h>


void printBytes(unsigned char *start, int len) {
    for (int i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void printInt(int x) {
    printBytes((unsigned char *) &x, sizeof(int));
}

void printFloat(float x) {
    printBytes((unsigned char *) &x, sizeof(float));
}

void printShort(short x) {
    printBytes((unsigned char *) &x, sizeof(short));
}

void printLong(long x) {
    printBytes((unsigned char *) &x, sizeof(long));
}

void printDouble(double x) {
    printBytes((unsigned char *) &x, sizeof(double));
}

int main() {
    printInt(5); //prints the hex representation of the int 5. prints 4 bytes 
    printFloat(5.0); //prints the same number of bytes as printInt(5) but the hex representation is different because floating point numbers are represented in a different way. 
    printShort(5); //only prints 2 bytes 
    printLong(5); //prints the same thing as printInt(5) except it is 8 bytes instead of 4 so there are a lot of leading zeroes
    printDouble(5.0); //prints 8 bytes but has a different hex representation because, like printFloat, it has a different way of representing numbers
    return 0;
}
