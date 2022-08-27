#include <stdio.h>

 unsigned int getOffset(unsigned int address) {
	// Return byte offset of address in cache block
	unsigned int offset = 0xFF;
	offset = address & offset;
	return offset;
}

 unsigned int getSet(unsigned int address) {
	// Return cache set for the address
	unsigned int set = 0xF;
	return set & (address >> 8); 
}

unsigned int getTag(unsigned int address)  {
	// Return cache tag for address
	return address >> 12;
}

int main() {
	unsigned int address1 = 0x12345678;
	unsigned int address2 = 0x87654321;
	unsigned int offset1 = getOffset(address1);
	unsigned int tag1 = getTag(address1);
	unsigned int set1 = getSet(address1);
	unsigned int offset2 = getOffset(address2);
	unsigned int tag2 = getTag(address2);
	unsigned int set2 = getSet(address2);
	printf("%0X: Offset: %0X - tag: %0x - set: %0x\n", address1, offset1, tag1, set1);
	printf("%0X: Offset: %0X - tag: %0x - set: %0x\n", address2, offset2, tag2, set2);
	return 0;
}
