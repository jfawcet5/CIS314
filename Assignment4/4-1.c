/*  loop:
 *  	 movq %rsi, %rcx
 *  	 movl $1, %eax
 *  	 movl $0, %edx
 *  .L2:
 *       testq %rax, %rax
 *       je    .L4
 *       movq %rax, %r8
 *       andq %rdi, %r8
 *       orq  %r8, %rdx
 *       salq %cl, %rax
 *       jmp  .L2
 *  .L4:
 *       movq %rdx, %rax
 *       ret
 */
#include <stdio.h>

long loop(long a, long b) {
	long result = 0;
	// %rcx = b, %rdi = a, %rdx = result, %rax = mask/result 
	//
	// movl $1, eax         =>  long mask = 0x1
	// 
	// testq %rax, %rax 
	// je .L4               =>  execute loop while mask != 0, if mask == 0 jump to .L4
	//
	// salq %cl, %rax       =>  mask <<= b
	//
	// andq %rdi, %r8
	// orq %r8, %rdx        => result = result | (a & mask) 
	//
	// movq %rdx, %rax
	// ret                  => put result in %rax and return result 
	for (long mask = 0x1; mask != 0; mask <<= b) {
		result |= (a & mask);  
	}
	return result;
}

int main() {
	/* Example output
	 *
	 * loop(1, 5): 1
	 * loop(2, 4): 0
	 * loop(3, 3): 1
	 * loop(4, 2): 4
	 * loop(5, 1): 5
	 */
	printf("loop(1, 5): %i  -- should be 1\n", loop(1, 5));
	printf("loop(2, 4): %i  -- should be 0\n", loop(2, 4));
	printf("loop(3, 3): %i  -- should be 1\n", loop(3, 3));
	printf("loop(4, 2): %i  -- should be 4\n", loop(4, 2));
	printf("loop(5, 1): %i  -- should be 5\n", loop(5, 1));
	return 0;
}
