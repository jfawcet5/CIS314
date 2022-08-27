/*
 *
 *
 */
#include <stdio.h>

unsigned int replace(unsigned int x, int i, unsigned char b) {
	/* This function replaces the byte at index i with the unsigned char b.
	 * It does this by making a mask of the form 0xFF00FFFF by shifting 0xFF
	 * to the left (i<<3) positions which basically means that we are multiplying
	 * the index i by 8 in order to shift 0xFF by the correct amount of bits. Then
	 * the mask is negated so that we have 0x00 in the position that we want to replace.
	 * I used a bitwise AND operator on x with the mask to keep everything the same 
	 * except for the byte at position i. 
	 */
	x = x & ~(0xff << (i << 3));
	return x | (b << (i << 3)); // I shift the char b over to the ith byte and use OR to insert b into x
}

int main() {
	printf("%X\n", replace(0x12345677, 3, 0xAB));
	printf("%X\n", replace(0x12345678, 0, 0xAB));
	printf("%X\n", replace(0xAAAAAAAA, 2, 0xBB));
	return 0;
}
