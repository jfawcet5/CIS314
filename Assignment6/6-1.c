#include <stdio.h>

int f1(int a, int b, int c, int d, int n) {
	int result = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			result += a * b + i * c * d + j;
		}
	}
	return result;
}

int f(int a, int b, int c, int d, int n) {
	/* Pulling a*b out of the loop is easy beacuse it is a constant value and doesnt change, so it can 
	 * be calculated once outside of the loop and stored in a variable for use inside the loop. However, i*c*d
	 * is not as easy because i changes every time the inner for loop is executed n times. I can pull out c*d
	 * because it does not change, and I can use a variable 'x' to find the value that needs to be multiplied 
	 * with 'cd' after the loop terminates in order to get the right result. */
	int result = 0;
	int ab = a * b;  // pulled out of for loop
	int cd = c * d;  // pulled out of for loop
	int x = 0;       // used to calculate i*c*d
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			result += ab + j;
			x += i;
		}
	}
	result += cd * x;
	return result;
}
	

int main() {
	printf("\nTesting function: f(1, 2, 3, 4, 5)\nExpected: %i\nActual: %i\n\n", f1(1, 2, 3, 4, 5), f(1, 2, 3, 4, 5));
	printf("Testing function: f(2, 3, 4, 5, 6)\nExpected: %i\nActual: %i\n\n", f1(2, 3, 4, 5, 6), f(2, 3, 4, 5, 6));
	printf("Testing function: f(6, 5, 4, 3, 2)\nExpected: %i\nActual: %i\n\n", f1(6, 5, 4, 3, 2), f(6, 5, 4, 3, 2));
	printf("Testing function: f(5, 4, 3, 2, 1)\nExpected: %i\nActual: %i\n\n", f1(5, 4, 3, 2, 1), f(5, 4, 3, 2, 1));
	printf("Testing function: f(10, 3, 8, 9, 3)\nExpected: %i\nActual: %i\n\n", f1(10, 3, 8, 9, 5), f(10, 3, 8, 9, 5));
	return 0;
}
