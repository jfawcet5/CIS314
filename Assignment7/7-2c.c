#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ColorPoint {
	long a;
	long r;
	long g;
	long b;
};

long f(struct ColorPoint **points, int n) {
	long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += points[j][i].a;
			sum += points[j][i].r;
			sum += points[j][i].g;
			sum += points[j][i].b;
		}
	}
	return sum;
}

long g(struct ColorPoint **points, int n) {
	long sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += points[i][j].a;
			sum += points[i][j].r;
			sum += points[i][j].g;
			sum += points[i][j].b;
		}
	}
	return sum;
}

struct ColorPoint **create2DArray(int n) {
 	// Array to hold a pointer to the beginning of each row
	struct ColorPoint **points =
	(struct ColorPoint **)malloc(n * sizeof(struct ColorPoint *));
	for (int i = 0; i < n; ++i) {
 		// Array to hold each row
 		points[i] =
 		(struct ColorPoint *)malloc(n * sizeof(struct ColorPoint));
 		for (int j = 0; j < n; ++j) {
 			// Init the ColorPoint struct
 			points[i][j].a = rand();
 			points[i][j].r = rand();
 			points[i][j].g = rand();
 			points[i][j].b = rand();
 		}
 	}
	return points;
}

void free2DArray(struct ColorPoint** points, int n) {
 	for (int i = 0; i < n; ++i) {
 		free(points[i]);
 	}
 	free(points);
}

int main() {
	// Code for timing from Trevor Bergstrom
	//
	// Function g is about 3 times faster than function f. I think this is because 
	// of the difference between accessing the array in column major vs row major
	// which causes one of the functions (function g) to have better spatial locality
	// than the other (function f). This means that in function g, the cache doesnt 
	// have to load data as often as function f, which causes function g to be faster
	// because loading data into the cache is much slower than already having the 
	// value in the cache

	struct ColorPoint** p = create2DArray(2048);
	clock_t start;
	clock_t end;
	double total_time;
	
	// Time function f with n = 2048
	start = clock();
	f(p, 2048);
	end = clock();
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("TIME f: %f seconds. \n", total_time);
	
	// Time function g with n = 2048
	start = clock();
	g(p, 2048);
	end = clock();
	total_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("TIME g: %f seconds. \n", total_time);	

	free2DArray(p, 2048);
	return 0;
}
