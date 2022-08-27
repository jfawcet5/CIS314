#include <stdio.h>

unsigned int combine(unsigned int x, unsigned int y) {
	/* Combines x and y by masking x with 0xffff0000 to isolate bytes 2 and 3, and 
	 * masking y with 0x0000ffff to isolate bytes 0 and 1. The results of those operations
	 * are combined with eachother using a bitwise or operation. 
	 */
	return (x & 0xffff0000) | (y & 0x0000ffff);
}

int main(char *argv[]) {
	printf("%X\n", combine(0x12345678, 0xABCDEF00));
	printf("%X\n", combine(0xABCDEF00, 0x12345678));
	printf("%X\n", combine(0x11110000, 0x00001111));
	return 0;
}
