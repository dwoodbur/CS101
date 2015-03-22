/*
 * insertionSort.c
 * Author: Dylan Woodbury
 *
 * Runs the insertion sort on the keys.
 *
 * Functions:
 * 	-void insertionSort(int keys[], int numKeys)
 */

#include "insertionSort.h" /* Main header file */

/*
 * void insertionSort(int keys[], int numKeys)
 * Runs insertion sort algorithm on the values
 */
void insertionSort(int keys[], int numKeys)
	{
	int i, j;	/* counter variables */
	int key; 	/* holds value of current element */

	for(i=1; i < numKeys; i++)
		{
		key = keys[i];
		j = i - 1;
		while(j >= 0 && keys[j] > key)
			{
			keys[j+1] = keys[j];
			j--;
			}
		keys[j+1] = key;
		}
	}
