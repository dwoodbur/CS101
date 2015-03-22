/*
 * heapSort.c
 * Author: Dylan Woodbury
 *
 * Runs the Heap Sort algorithm on the values.
 *
 * Functions:
 * 	-void heapSort(int keys[], int numKeys)
 */

#include "heapSort.h"	/* Main header file */
#include "heap.h"	/* Heap ADT */
#include <stdlib.h>	/* Contains common c functions */
#include <stdio.h>	/* Contains standard input/output functions */

/*
 * void heapSort(int keys[], int numKeys)
 * Runs heap sort algorithm
 */
void heapSort(int keys[], int numKeys)
	{
	int i; /* counter variable */

	heapHndl heap = newHeap(numKeys);

	/* Fills up heap with values */
	for(i=0; i < numKeys; i++)
		insert(heap, keys[i]);

	/* Gets the maximum value, one by one, and 
	 * over-writes into array */
	for(i = numKeys-1; i >= 0; i--)
		{
		keys[i] = maxValue(heap);
		deleteMax(heap);
		}
	}
