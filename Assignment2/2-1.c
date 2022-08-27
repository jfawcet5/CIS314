/*
 *
 *
 */
#include <stdio.h>

int mask(int n) {
	/* my signed integer x in binary is a 1 followed by 31 zeroes. I shift
	 * x (31 - n) bits to the right in order to isolate the 31 to n most significant
	 * bits with ones because of the way signed numbers are shifted to the right, which 
	 * will leave the n-1 to 0 least significant bits as 0s, so i negate 
	 * it to make the high order bits 0s and the low order bits 1s.
	 * */ 
	int x = 0x80000000;
	printf("%0X\n", ~(x >> (31 - n)));
	return 0;
}

int main() {
	mask(1);
	mask(2);
	mask(3);
	mask(5);
	mask(8);
	mask(16);
	mask(31);
	return 0;
}
