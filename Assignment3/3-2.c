/*
 *
 *
 */
#include <stdio.h>

long f(long a, long b, long c) {
	b = b - c;    // subq %rdx, %rsi
	a = a * b;    // imulq %rsi, %rdi
	b = b << 63;  // salq $63, %rsi
	b = b >> 63;  // sarq $63, %rsi
	long ret = a; // movq %rsi, %rax
	return ret ^ b;// xorq %rsi, %rax
}

int main() {
	long x = f(10, 20, 30);
	printf("%d\n", x);
	return 0;
}
