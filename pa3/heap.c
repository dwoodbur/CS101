/*
 * heap.c
 * Author: Dylan Woodbury (dwoodbur)
 *
 * Contains the implementations of the functions described in heap.h,
 * functions which build, access data of, insert into, and delete from
 * the heap.
 *
 * FUNCTIONS:
 * (prototyped in heap.h)
 * 	-heapHndl newHwap(int maxSize)
 * 	-Boolean isFull(heapHndl H)
 * 	-Boolean isEmpty(heapHndl H)
 *	-int maxValue(heapHndl H)
 *	-void deleteMax(heapHndl H)
 *	-void insert(heapHndl H)
 */

#include "heap.h"	/* The ADT header file */
#include <assert.h>	/* This allows us to use the "assert" */
#include <stdlib.h>	/* Contains standard c functions */

/*
 * Imported types from heap.h:
 * 	-type heapHndl
 * 	-enum Boolean (TRUE/FALSE)
 */

	/*
 	 * heapHndl newHeap(int maxSize)
 	 * Creates new heap, building necessary memory
 	 * and assigning initial values.
 	 * Pre: n/a
 	 * Post: n/a
 	 */
	heapHndl newHeap(int maxSize)
		{
		heapHndl tempHeap;
		tempHeap = malloc( sizeof(HeapHndlStruct) );
		tempHeap->maxValue = 0;
		tempHeap->size = maxSize;
		tempHeap->curSize = 0;

		return (tempHeap);
		}

	/*
 	 * Boolean isFull(heapHndl H)
 	 * Returns true if the heap is full,
 	 * otherwise false.
 	 * Pre: n/a
 	 * Post: n/a
 	 */ 
	Boolean isFull(heapHndl H)
		{
		if(H->curSize == H->size)
			return TRUE;
		return FALSE;
		}

	/*
 	 * Boolean isEmpty(heapHndl H)
 	 * Returns true if the heap is empty,
 	 * otherwise false.
 	 * Pre: n/a
 	 * Post: n/a
 	 */
	Boolean isEmpty(heapHndl H)
		{
		return H->curSize == 0;
		}

	/*
 	 * int maxValue(heapHndl H)
 	 * Returns the maximum element of the heap,
 	 * important for priority queues.
 	 * Pre: !isEmpty()
 	 * Post: n/a
 	 */
	int maxValue(heapHndl H)
		{
		assert( !isEmpty(H) );

		return H->maxValue;
		}

	/*
 	 * void deleteMax(heapHndl H)
 	 * Deletes the maximum element of the heap,
 	 * important for priority queues.
 	 * Pre: !isEmpty()
 	 * Post: Size before deletion (int sizePre) is
 	 * 	one more than the size after.
 	 */
	void deleteMax(heapHndl H)
		{
		int i, j; /* Counting variables */
		int newMax = -9999; /* Holds working maximum value */
		int sizePre = H->curSize;
		Boolean done = FALSE;

		assert( !isEmpty(H) );
		/* Go through array until hitting max value, delete */
		for(i=0; i < H->curSize && done == FALSE; i++)
			{
			if(H->array[i] == maxValue(H) )
				{
				H->array[i] = 0;
				for(j=i; j < H->curSize - 1; j++)
					{
					H->array[j] = H->array[j+1];
					}
				H->array[j] = 0;
				H->curSize--;
				done = TRUE;
				}
			}
		/* Get new max value */
		for(i=0; i < H->curSize; i++)
			{
			if(H->array[i] > newMax)
				newMax = H->array[i];
			}
		if(newMax == -9999)
			newMax = 0;
		/* Update max value */
		H->maxValue = newMax;

		assert(sizePre == H->curSize+1);
		}

	/*
 	 * void insert(heapHndl H, int priority)
 	 * Inserts new element into the heap.
 	 * Pre: !isFull()
 	 * Post: Size before insertion (int sizePre) is
 	 * 	one less than the size after.
 	 */
	void insert(heapHndl H, int priority)
		{
		int sizePre = H->curSize;

		assert( !isFull(H) );

		H->array[H->curSize] = priority;
		H->curSize++;
		if(priority > H->maxValue)
			H->maxValue = priority;

		assert(sizePre == H->curSize-1);
		}
