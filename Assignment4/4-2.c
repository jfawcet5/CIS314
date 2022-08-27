#include <stdio.h>
/*
int sum(int from, int to) {
	int result = 0;
	do {
		result += from;
		++from;
	} while (from <= to) ;
	return result;
}
*/
long sum(long from, long to) {
	// Declar and initialize result var - *do not modify*.
	long result = 0;

	// Ensure that argument *from* is in %rdi,
	// argument *to* is in %rsi, *result* is in %rax - *do not
	// modify*
	__asm__("movq %0, %%rdi # from in rdi;" :: "r" (from));
	__asm__("movq %0, %%rsi # to in rsi;" :: "r" (to));
	__asm__("movq %0, %%rax # result in rax;" :: "r" (result));

	// Your x86-64 code goes below - comment each instruction...
	__asm__(
	        "movq $0, %rax;"  // result = 0;
	     ".L2:"
	        "addq %rdi, %rax;"  // result += from 
		"addq $1, %rdi;"    // ++from
		"cmpq %rsi, %rdi;"  // (from - to) -- while *from* <= *to* sets SF = 1 or ZF = 1 
		"jle .L2;"          // if either SF or ZF are set, jumps to the top of the loop
	);

	// Ensure that *result* is in %rax for return - *do not modify*.
	__asm__ ("movq %%rax, %0 #result in rax;" : "=r" (result));
	return result;
}

int main() {
	printf("sum(1, 6): %i -- should be 21\n", sum(1, 6));
	printf("sum(3, 5): %i -- should be 12\n", sum(3, 5));
	printf("sum(5, 3): %i -- should be 5\n", sum(5, 3));
	return 0;
}
