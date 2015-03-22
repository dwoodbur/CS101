/*
 * sortComp.c
 * Author: Dylan Woodbury
 *
 * Runs insertion sort and heap sort on given file of keys, running
 * a clock analysis to compare the efficiencies of the two algorithms.
 *
 * Functions:
 * 	-int main(int argc, char *argv[])
 */

#include "heapSort.h"		/* Contains heap sort algorithm prototype */
#include "insertionSort.h"	/* Contains insertion sort algoritm prototype */
#include <assert.h>		/* Allows use of insert */
#include <stdio.h>		/* Contains standard input/output functions */
#include <stdlib.h>		/* Contains standard c functions */
#include <string.h>		/* Allows copying of arrays, not used currently (but I am paranoid, so whatever) */
#include <time.h>		/* Allows use of clock() function and clock_t type */

/*
 * int main(int argc, char *argv[])
 * Runs program (see file description).
 * Pre: must be 2 arguments
 * Post: keys must be sorted (program not quit on failure however)
 */
int main(int argc, char *argv[])
	{
	int numKeys; 			   /* number of keys in file */
	int i;				   /* counter variable */
	int *keys;			   /* holds array of keys */
	int *heapSortKeys;		   /* holds array of keys for heap sort algorithm */
	int *insertionSortKeys;		   /* holds array of keys for insertion sort algorithm */
	char *filename;			   /* holds filename of keys' source */
	FILE *fp;			   /* file containing keys */
	clock_t startTime_t, duration_t;   /* variables for marking/measuring time elapsed */

	assert(argc == 2);

	/* Gets filename */
	filename = argv[1];
	fp = fopen(filename, "r");
	if(fp == NULL)
		{
		fprintf(stderr, "Can't open input file %s.\n", filename);
		exit(1);
		}

	/* Inputs data, sets up arrays, and stores unsorted keys */
	fscanf(fp, "%d", &numKeys);
	keys = malloc(numKeys * sizeof(int));
	heapSortKeys = malloc(numKeys * sizeof(int));
	insertionSortKeys = malloc(numKeys * sizeof(int));
	for(i=0; i < numKeys; i++)
		{
		fscanf(fp, "%d", &keys[i]);
		heapSortKeys[i] = keys[i];
		insertionSortKeys[i] = keys[i];
		}

	/* Times heap sort algorithm */
	startTime_t = clock();
	heapSort(heapSortKeys, numKeys);
	duration_t = clock() - startTime_t;
	printf("Heapsort algorithm took %f seconds to sort %d elements.\n", ((float) duration_t) / CLOCKS_PER_SEC, numKeys);

	/* Times insertion sort algorithm */
	startTime_t = clock();
	insertionSort(insertionSortKeys, numKeys);
	duration_t = clock() - startTime_t;
	printf("Insertion sort algorithm took %f seconds to sort %d elements.\n", ((float) duration_t) / CLOCKS_PER_SEC, numKeys);

	return 0;
	}
