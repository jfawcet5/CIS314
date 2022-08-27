// I got the code for timing from Trevor Bergstrom in CIS 314 lab

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000

float f(float *a, int n) {
	float prod = 1.0f;
	for (int i = 0; i < n; ++i) {
		if (a[i] != 0.0f) {
			prod *= a[i];
		}
	}
	return prod;
}

float g(float *a, int n) {
	// Equivalent to f() but does not have zero check
	float prod = 1.0f;
	for (int i = 0; i < n; ++i) {
		prod *= a[i];
	}
	return prod;
}

float *createArray(int size) {
	float *a = (float *)malloc(size * sizeof(float));
	for (int i = 0; i < size; ++i) {
		// 50% chance that a[i] is 0.0f, random value on the range
		// [0.76, 1.26] otherwise
		float r = rand() / (float)RAND_MAX;
		a[i] = r < 0.5f ? 0.0f : r + 0.26f;
	}
	return a;
}

int main() {
	// Part A: Measure time taken for f(a) with 10000 elements in 'a'
	clock_t start;
	clock_t end;
	float *a = createArray(N);
	start = clock();
	f(a, N);
	end = clock();
	printf("TIME f(a): %f seconds.\n", ((double)(end-start))/CLOCKS_PER_SEC);
	

	// Part B: Copy 'a' into 'b' and replace all 0.0f with 1.0f then measure time taken for g(b)
	float *b = (float *)malloc(N * sizeof(float *));
	for (int i = 0; i < N; i++) {
		if (a[i] == 0.0f) {
			b[i] = 1.0f;
		}
		else {
			b[i] = a[i];
		}
	}
	start = clock();
	g(b, N);
	end = clock();
	printf("TIME g(b): %f seconds.\n", ((double)(end-start))/CLOCKS_PER_SEC);
	// running g(b) is faster than running f(a) because function 'f' has to check if 
	// a[i] is 0.0 every iteration through the for loop while function 'g' doesnt have a
	// conditional check inside the for loop since the 0.0s are replaced with 1.0s in 'b'. This means
	// that 'g' gets to do no-ops on the 1.0s while 'f' still has to do a conditional check to 
	// see if the current value is 0.0


	// Part C: Copy only non-zero values from 'a' to 'c' then measure time taken for g(c)
	int j = 0; // This will be size of c
	for (int i = 0; i < N; i++) {
		if (a[i] != 0.0f) {
			j++;
		}
	}
	float *c = (float *)malloc(j * sizeof(float *));
	int k = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] != 0.0f) {
			c[k++] = a[i];
		}
	}
	start = clock();
	g(c, j);
	end = clock();
	printf("TIME g(c): %f seconds.\n", ((double) (end - start)) / CLOCKS_PER_SEC);
	// g(c) is faster than f(a) and g(b) because it doesnt have to do a conditional check to see if the 
	// current value is 0.0, and the for loop in g(c) has to run fewer times than f(a) and g(b) because 
	// there are fewer elements in the array 'c'. 

	// Free 'a' 'b' and 'c'
	free(a);
	free(b);
	free(c);
	return 0;
}
