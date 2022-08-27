/*
 *
 *
 */
#include <stdio.h>

int le(float x, float y) {
	unsigned int ux = *((unsigned int*) &x); // convert x raw bits
	unsigned int uy = *((unsigned int*) &y); // convert y raw bits
	unsigned int sx = ux >> 31; // extract sign bit of ux
	unsigned int sy = uy >> 31; // extract sign bit of uy
	ux <<= 1; // drop sign bit of ux
	uy <<= 1; // drop sign bit of uy
	// Case one: (ux <= uy) && (sx >= sy)
	// the bits in ux are less than the bits in uy and the sign bit of
	// x is either greater than or equal to the sign bit of y -> x is negative 
	// and y is positive OR x is a smaller positive number 
	// Case two: (ux >= uy) && (sx == 1)
	// The bits in ux are larger than uy and x is negative -> x is a smaller negative
	return ((ux <= uy) && (sx >= sy)) || ((ux >= uy) && (sx == 1));
}

int main() {
	printf("le(0.0f, 0.0f): %i\n", le(0.0f, 0.0f));
	printf("le(-0.0f, 0.0f): %i\n", le(-0.0f, 0.0f));
	printf("le(-1.0f, -1.0f): %i\n", le(-1.0f, -1.0f));
	printf("le(1.0f, 1.0f): %i\n", le(1.0f, 1.0f));
	printf("le(-1.0f, 0.0f): %i\n", le(-1.0f, 0.0f));
	printf("le(0.0f, 1.0f): %i\n", le(0.0f, 1.0f));
	printf("le(1.0f, 0.0f): %i\n", le(1.0f, 0.0f));
	printf("le(0.0f, -1.0f): %i\n", le(0.0f, -1.0f));
	//printf("le(5.0f, 23.0f): %i\n", le(5.0f, 23.0f));
	//printf("le(-23.0f, -5.0f): %i\n", le(-23.0f, -5.0f));
	//printf("le(5.0f, -23.0f): %i\n", le(5.0f, -23.0f));
	return 0;
}
