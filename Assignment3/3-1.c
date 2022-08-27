/*
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

struct IntArray {
	int length;
	int *dataPtr;
};

struct IntArray *mallocIntArray(int length) {
	struct IntArray *array = (struct IntArray *)malloc(sizeof(struct IntArray));
	int *dataPtr = (int *)malloc(length * sizeof(int));
	array->dataPtr = dataPtr;
	array->length = length;
	return array;
}

void freeIntArray(struct IntArray *array) {
	free(array->dataPtr);
	free(array);
	return;
}

void readIntArray(struct IntArray *array) {
	for (int i = 0; i < array->length; i ++) {
		int y = 0;
		while ( y == 0) {
			char input[1024];
			char *p = NULL;
			printf("Enter int: ");
			fgets(input, 1024, stdin);
			y = strtol(input, &p, 10);
			if (y == 0) {
				printf("Invalid input\n");
			}
			else {	
				array->dataPtr[i] = y;
			}
		}
	}
	return;
}

void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
	return;
}

void sortIntArray(struct IntArray *array) {
	// geeksforgeeks.org/bubble-sort/
	for (int i = 0; i < (array->length - 1); i++) {
		for (int j = 0; j < (array->length-i-1); j ++) {
			if (array->dataPtr[j] > array->dataPtr[j + 1]) {
			int *xp = &array->dataPtr[j];
			int *yp = &array->dataPtr[j+1];
			swap(xp, yp);
			}
		}
	}
	return;
}

void printIntArray(struct IntArray *array) {
	for (int i = 0; i < array->length; i++) {
		printf("%i ", array->dataPtr[i]);
	}
	printf("\n");
	return;
}

int main() {
	int len = 0;
	while (len == 0) {
		char input[1024];
		char *p = NULL;
		printf("Enter Length: ");
		fgets(input, 1024, stdin);
		len = strtol(input, &p, 10);
		if (len == 0) {
			printf("Invalid Input \n");
		}
	}
	
	struct IntArray *myarray = mallocIntArray(len);
	readIntArray(myarray);
	sortIntArray(myarray);
	printIntArray(myarray);
	freeIntArray(myarray);
	return 0;
}
