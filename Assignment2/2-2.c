/*
 *
 *
 */
#include <stdio.h>

unsigned int extract(unsigned int x, int i) {
	x = x << ((3 - i) << 3); //shift the byte at position i to the left to position 3
	int z = (0XFF000000 & x); //isolate the byte that was just shifted 
	z = z >> 24; //shift signed number so that byte 3 is now byte 0, filling high order bits with 0 or 1
	printf("%0X\n", z);
	return 0;
}

int main() {
	extract(0x12345678, 0);
	extract(0xABCDEF00, 2);
	return 0;
}
