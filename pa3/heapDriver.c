/*
 * heapDriver.c
 * Author: Dylan Woodbury
 *
 * Driver program for heap ADT described in heap.c, prototyped in
 * heap.h. This program contains a series of tests that builds a
 * heap, inserts elements, deletes elements, and accesses its data.
 * The program should not fail on one of the assert preconditions,
 * crash from a data mismanagement issue, and all of the notes in
 * parentheses that describe any expected conditions should be true.
 *
 * FUNCTIONS:
 * 	-void fullTest(heapHndl heap)
 * 	-void emptyTest(heapHndl heap)
 * 	-void printMaxValue(heapHndl heap)
 * 	-void printHeap(heapHndl heap)
 * 	-int main()
 */

#include "heap.h"	/* The ADT header file */
#include <stdio.h>	/* Contains standard input/output functions */
#include <stdlib.h>	/* Contains standard c functions */

/*
 * void fullTest(heapHndl heap)
 * Tests is heap is full, displays results.
 */
void fullTest(heapHndl heap)
	{
	if(isFull(heap) == TRUE)
		printf("  Heap is full.\n");
	else
		printf("  Heap is not full.\n");
	}

/*
 * void emptyTest(heapHndl heap)
 * Tests if heap is empty, displays results.
 */
void emptyTest(heapHndl heap)
	{
	if(isEmpty(heap) == TRUE)
		printf("  Heap is empty.\n");
	else
		printf("  Heap is not empty.\n");
	}

/*
 * void printMaxValue(heapHndl heap)
 * Displays the maximum value of the heap.
 */
void printMaxValue(heapHndl heap)
	{
	printf("  Max Value: %d\n", maxValue(heap) );
	}

/*
 * void printHeap(heapHndl heap)
 * Displays the contents of the heap.
 */
void printHeap(heapHndl heap)
	{
	int i;

	printf("  Heap printout:\n");
	for(i=0; i < heap->curSize; i++)
		{
		printf("    %d\n", heap->array[i]);
		}
	}

/*
 * int main()
 * Goes through the process of building a heap, adding elements
 * to it, deleting elements, and freeing the memory, displaying
 * access values of the heap throughout to ensure its proper
 * functioning.
 */
int main()
	{
	int i; /* Counting variable */
	/* Build heap */
	heapHndl heap;
	printf("Building new heap of size 13...\n");
	printf("(should be empty)\n");
	heap = newHeap(13);
	fullTest(heap);
	emptyTest(heap);

	/* Inserts element into heap */
	printf("Inserting element 42...\n");
	insert(heap, 42);
	fullTest(heap);
	emptyTest(heap);
	printMaxValue(heap);
	printHeap(heap);

	/* Deletes max elment of heap */
	printf("Deleting max element...\n");
	printf("(should be empty)\n");
	deleteMax(heap);
	fullTest(heap);
	emptyTest(heap);

	/* Inserts enough elements into heap to make it full */
	printf("Inserting 13 numbers...\n");
	printf("(should be full)\n");
	insert(heap, 21);
	for(i=1; i<6; i++)
		insert(heap, i);
	insert(heap, 99);
	for(i=6; i<11; i++)
		insert(heap, i);
	insert(heap, 66);
	printMaxValue(heap);
	fullTest(heap);
	printHeap(heap);

	/* 
 	 * Deletes max element of heap 3 times, which sit in the middle,
 	 * at the end, and at the beginnging of the heap.
 	 */
	printf("Deleting max element thrice...\n");
	printf("(each case: middle, ending, starting element)\n");
	deleteMax(heap);
	deleteMax(heap);
	deleteMax(heap);
	printMaxValue(heap);
	printHeap(heap);

	return 0;
	}
