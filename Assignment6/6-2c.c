#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000 //input size

void inner(float *u, float *v, int length, float *dest) {
	int i;
	float sum = 0.0f;
	for (i = 0; i < length; i++) {
		sum += u[i] * v[i];
	}
	*dest = sum;
}

void inner2(float *u, float *v, int length, float *dest) {
	float sum1 = 0.0f;
	float sum2 = 0.0f;
	float sum3 = 0.0f;
	float sum4 = 0.0f;
	int i;
	int limit = length - 4;
	// Four way loop unrolling with 4 parallel accumulators
	for (i = 0; i < limit; i+=4) {
		sum1 += u[i] * v[i];
		sum2 += u[i+1] * v[i+1];
		sum3 += u[i+2] * v[i+2];
		sum4 += u[i+3] * v[i+3];
	}
	for (; i < length; i++) {
		sum1 += u[i] * v[i];
	}
	*dest = sum1 + sum2 + sum3 + sum4;
}

int main() {
	// Test inner and inner2. Inner2 seems to be about 2x faster than inner. This makes sense to me because
	// with loop unrolling, the for loop in inner2 will run a lot less than inner which means that the cost of
	// loop overhead will be a lot less in inner2 because it wont have to increment i and do the conditional 
	// check as much as inner. 
	// One thing I also noticed is that the value of dest2 is slightly different than dest1. The difference depends
	// on the length of the array, but I think it is caused because of the order in which the floating point numbers
	// are added together. 
	clock_t start;
	clock_t end;
	clock_t start2;
	clock_t end2;
	double time1;
	double time2;
	float u[N];
	float v[N];
	float x = (float)rand()/(float)(RAND_MAX/1.45); //random float value
	for (int i = 0; i < N; i++) {
		u[i] = x;
	}
	for (int i = 0; i < N; i++) {
		v[i] = x * 1.1;
	}
	float dest1;
	float dest2;
	
	// Test inner
	start = clock();
	inner(u, v, N, &dest1);
	end = clock();
	
	// Test inner2
	start2 = clock();
	inner2(u, v, N, &dest2);
	end2 = clock();
	
	time1 = ((double) (end - start)) / CLOCKS_PER_SEC;
	time2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
	printf("TIME inner: %f seconds.\nTIME inner2: %f seconds.\n", time1, time2);
	return 0;
}
