/*
 *  %rax contains a pointer to the ith column
 *  %rdx contains a pointer to the ith row 
 *
 *
 *  .L3:
 *       movq (%rax), %rcx  - Put the contents of the memory location pointed to by %rax into %rcx
 *       movq (%rdx), %rsi  - Put the contents of the memory location pointed to by %rdx into %rsi
 *       movq %rsi, (%rax)  - Put %rsi into the memory location pointed to by %rax
 *       movq %rcx, (%rdx)  - Put %rcx into the memory location pointed to by %rdx
 *       addq $8, %rax      - Increment %rax by 8 to point to the next column
 *       addq $32, %rdx     - Increment %rdx by 32 to point to the next row
 *       cmp %r9, %rax      - Check if %rax is pointing to the end of the array
 *       jne .L3            - Jump if previous instruction did not set the zero flag
 *
 */

#include <stdio.h>
#define N 4

typedef long array_t[N][N];

void printMatrix(array_t a) {
	// Prints nested array as N x N matrix
	// Used in main for testing
	for (long i = 0; i < N; i++) {
		for (long j = 0; j < N; j++) {
			printf("%3i ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return;
}

void transpose(array_t a) {
	for (long i = 0; i < N; i++) {
		long *t1;
		long *t2;
		for (long j = 0; j < i; j++) {
			t1 = *a + (i * N) + (j);
			t2 = *a + (j * N) + (i);	
			long temp = *t1;
			*t1 = *t2;
			*t2 = temp;
		}
	}	
}

int main() {
	array_t a = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
	printMatrix(a);
	transpose(a);
	printMatrix(a);
	return 0;
}
