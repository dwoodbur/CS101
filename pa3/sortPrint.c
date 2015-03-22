/*
 * sortPrint.c
 * Author: Dylan Woodbury
 *
 * Runs insertions sort and heap sort on given file of keys, checking
 * the accuracy of these algorithms and printing the resulting sorted
 * arrays.
 *
 * Functions:
 * 	-int main(int argc, char *argv[])
 */

#include "heapSort.h"		/* Heap sort header */
#include "insertionSort.h"	/* Insertion sort header */
#include <assert.h>		/* Allows use of asser */
#include <stdio.h>		/* Allows standard input/output functions */
#include <stdlib.h>		/* Allows standard c functions */
#include <string.h>		/* Allows copying of array (not used, but kept to be safe) */

/*
 * int main(int argc, char *argv[])
 * Runs program (see file description).
 * Pre: 2 arguments
 */
int main(int argc, char *argv[])
	{
	int numKeys;			/* number of keys */
	int i;				/* counter variable */
	int correctOrder = 0;		/* used as boolean, to make sure post order is correct */
	int *keys;			/* holds array of the keys */
	int *heapSortKeys;		/* array of keys for heap sort algorithm */
	int *insertionSortKeys;		/* array of keys for insertion sort algorithm */
	char *filename;			/* name of file */
	FILE *fp;			/* file containing keys */

	assert(argc == 2);

	/* Gets filename/file */
	filename = argv[1];
	printf("FILENAME: %s\n", filename);
	fp = fopen(filename, "r");
	if(fp == NULL)
		{
		fprintf(stderr, "Can't open input file %s.\n", filename);
		exit(1);
		}

	/* Gets data, sets up arrays, and loads with keys */
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

	/* Runs sorting algorithms */
	heapSort(heapSortKeys, numKeys);
	insertionSort(insertionSortKeys, numKeys);

	/* Checks correctedness of heap sort algorithm */
	for(i=0; i < numKeys-1 && correctOrder == 0; i++)
		{
		if(heapSortKeys[i] > heapSortKeys[i+1])
			correctOrder = 1;
		}
	if(correctOrder == 1)
		printf("\nHeapSort Failed!\nFirst error:\nElement %d: %d\nElement %d: %d\n", i, heapSortKeys[i], i+1, heapSortKeys[i+1]);
	else
		printf("\nHeapSort Succeeded!\n");

	/* Checks correctedness of insertion sort algorithm */
	correctOrder = 0;
	for(i=0; i < numKeys-1 && correctOrder == 0; i++)
		{
		if(insertionSortKeys[i] > insertionSortKeys[i+1])
			correctOrder = 1;
		}
	if(correctOrder == 1)
		printf("InsertionSort Failed!\nFirst error:\n Element %d: %d\nElement %d: %d\n", i, insertionSortKeys[i], i+1, insertionSortKeys[i+1]);
	else
		printf("InsertionSort Succeeded!\n");

	/* Prints sorted arrays */
	printf("\nSORTED ARRAYS:\n   HeapSort  InsertionSort\n");
	for(i=0; i < numKeys; i++)
		{
		printf("%d) %7d %7d\n", i+1, heapSortKeys[i], insertionSortKeys[i]);
		} 

	return 0;
	}
