/*
 ============================================================================
 Name        : SieveOfE.c
 Author      : Wessley
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

	// Size of table array.
	int max = 1000000000;
	int maxSqrt = (int) sqrt(max);

	// Array with chars acting as bools.
	// Each index will contain 1/true if it is prime, 0/false if not.
	char *table = (char *) malloc(max * sizeof(table));

	table[0] = 0;
	table[1] = 1;
	table[2] = 1;

	// From 3 to max, set even numbers false and odd numbers true.
	for (int i = 3; i < max; i++) {
		table[i] = i % 2;
	}

	// For every odd number above three that is true in table...
	for (int i = 3; table[i] && i < maxSqrt; i = i + 2) {
		// ... set every odd multiple of that number from i to max to false.
		for (int j = i * i; j < max; j = j + (i * 2)) {
			table[j] = 0;
		}
	}

	free(table);

	return 0;
}
