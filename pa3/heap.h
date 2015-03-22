/*
 * heap.h
 * Author: Dylan Woodbury
 *
 * Contains structs, types, function prototypes for heap ADT.
 *
 * Structs:
 * 	-HeapHndlStruct
 * 		int maxValue
 * 		int size
 * 		int curSize
 * 		int array[]
 *
 * Types:
 * 	-HeapHndl
 * 	-Boolean
 *
 * Functions:
 * 	-heapHndl newHeap(int maxSize)
 * 	-Boolean isFull(heapHndl H)
 * 	-Boolean isEmpty(heapHndl H)
 * 	-int maxValue(heapHndl H)
 * 	-void deleteMax(heapHndl H)
 * 	-void insert(heapHndl H, int priority)
 */


typedef struct HeapHndlStruct * heapHndl;

enum {MAXSIZE = 100000};

typedef struct HeapHndlStruct
	{
	int maxValue;		/* maximum element in heap */
	int size;		/* size of heap, defined when newHeap is called */
	int curSize;		/* current size of heap */
	int array[MAXSIZE];	/* array for holding elements of heap */
	} HeapHndlStruct;

typedef enum Boolean
	{
	FALSE,
	TRUE
	} Boolean;

heapHndl newHeap(int maxSize);

Boolean isFull(heapHndl H);

Boolean isEmpty(heapHndl H);

int maxValue(heapHndl H);

void deleteMax(heapHndl H);

void insert(heapHndl H, int priority);
