/*
 *
 *
 *
 */
#include <stdio.h>

int oddBit(unsigned int x) {
	/* Uses the mask 0xAAAAAAAA because the binary representation of 0xA is 1010, which 
	 * has a one in each odd position. Using the bitwise & operation with this mask will 
	 * isolate all of the odd bits.
	 */
	unsigned int mask = 0xAAAAAAAA;
	return (x & mask) || 0; // Logical || operation only returns 0 if (x & mask) is 0x00000000
}

int main() {
	printf("%0x\n", oddBit(0x1));
	printf("%0x\n", oddBit(0x2));
	printf("%0x\n", oddBit(0x3));
	printf("%0x\n", oddBit(0x4));
	printf("%0x\n", oddBit(0xFFFFFFFF));
	printf("%0x\n", oddBit(0xAAAAAAAA));
	printf("%0x\n", oddBit(0x55555555));
	return 0;
}
