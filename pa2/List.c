/*
 * List.c
 * Author: Dylan Woodbury (dwoodbur)
 * Aid: Only aid received was by studying intstack module posted on site.
 *
 * This list module has many functions that define the doubly-linked list,
 * manipulate its contents, access its contents, and display its contents.
 */

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

/*
 * The file List.h contains the following:
 *
 *
 *
 *
 */

/* Node information */
typedef struct NodeStruct * Node;

typedef struct NodeStruct
	{
	long data;
	Node next;
	Node prev;
	} NodeStruct;

/* List information */
typedef struct ListStruct
	{
	Node first;
	Node last;
	Node current;
	int size;
	} ListStruct;



/*Node freeListHolder;
*/


Node newNode();

void freeNode(Node node);

void freeFreeList();




/* Constructors-Destructors */

/*
 * ListHndl newList()
 * Pre:
 * Post:
 *
 * Creates new list.
 */
ListHndl newList()
	{
	ListHndl tempList;
	tempList = malloc( sizeof(ListStruct) );
	tempList->size = 0;
	tempList->first = NULL;
	tempList->last = NULL;
	tempList->current = NULL;

	return (tempList);
	}
/*
 * void freeList(LstHndl* L)
 * Pre: L has been created with newList.
 * Post:
 *
 * Frees the memory of a list, thus deleting it.
 */
void freeList(ListHndl *L)
	{
	/*makeEmpty(L);*/
	free( (*L) );
	(*L) = NULL;
	}

/*** Access functions ***/

/*
 * int isEmpty(LsntHndl L)
 * Pre:
 * Post:
 *
 * Returns true if list is empty, or returns false.
 */
int isEmpty(ListHndl L)
	{
	if(L->size == 0)
		return 1;
	return 0;
	}

/*
 * int offEnd(ListHndl L)
 * Pre:
 * Post:
 *
 * Returns true if current == NULL.
 */
int offEnd(ListHndl L)
	{
	if(L->current == NULL)
		return 1;
	return 0;
	}
/*
 * int atFirst(ListHndl L)
 * Pre:
 * Post:
 *
 * Returns true if current == false and !offEnd()
 */
int atFirst(ListHndl L)
	{
	if( L->current == L->first && !offEnd(L) )
		return 1;
	return 0;
	}
/*
 * int atLast(ListHndl L)
 * Pre:
 * Post:
 *
 * Returns true if current == last and !offEnd()
 */
int atLast(ListHndl L)
	{
	if( L->current == L->last && !offEnd(L) )
		return 1;
	return 0;
	}
/*
 * long getFirst(ListHndl L)
 * Pre: !isEmpty()
 * Post:
 *
 * Returns the first element.
 */
long getFirst(ListHndl L)
	{
	if( isEmpty(L) )
		{
		}
	return(L->first->data);
	}
/*
 * long getLast(ListHndl)
 * Pre: !isEmpty()
 * Post:
 *
 * Returns the last element.
 */
long getLast(ListHndl L)
	{
	if( isEmpty(L) )
		{
		}
	return(L->last->data);
	}
/*
 * long getCurrent(ListHndl L)
 * Pre: !offEnd()
 * Post:
 *
 * Returns the current element.
 */
long getCurrent(ListHndl L)
	{
	if( offEnd(L) )
		{
		}
	return(L->current->data);
	}


/*** Manipulation procedures ***/


/*
 * void makeEmpty(ListHndl L)
 * Pre:
 * Post: isEmpty(), offEnd() both true
 *
 * Deletes all elements from list, making it empty.
 */
void makeEmpty(ListHndl L)
	{
	int i;

	L->size = 0;
	L->first = NULL;
	L->last = NULL;
	L->current = NULL;
	}
/*
 * void moveFirst(ListHndl L)
 * Pre: !isEmpty()
 * Post: !offEnd()
 *
 * Without changing the list order, makes the
 * first element the current one.
 */
void moveFirst(ListHndl L)
	{
	L->current = L->first;
	}
/*
 * void moveLast(ListHndl L)
 * Pre: !isEmpty
 * Post: !offEnd()
 *
 * Without changing the list order, makes the
 * last element the current one.
 */
void moveLast(ListHndl L)
	{
	L->current = L->last;
	}
/*
 * void movePrev(ListHndl L)
 * Pre: !offEnd()
 * Post: offEnd() only if atFirst() is true
 *
 * Moves the current marker one element earlier in
 * the list.
 */
void movePrev(ListHndl L)
	{
	L->current = L->current->prev;
	}
/*
 * void moveNext(ListHndl L)
 * Pre: !offEnd()
 * Post: offEnd() only if atLast() is true
 *
 * Moves the current marker one elment later in
 * the list.
 */
void moveNext(ListHndl L)
	{
	L->current = L->current->next;
	}
/*
 * void insertAtFront(ListHndl L, long data)
 * Pre:
 * Post: !isEmpty(), doesn't change current element
 *
 * Inserts new element before first.
 */
void insertAtFront(ListHndl L, long data)
	{
	Node node;

	node = newNode();
	node->data = data;
	if( isEmpty(L) == 1 )
		L->last = node;
	else
		{
		L->first->prev = node;
		node->next = L->first;
		}
	L->first = node;
	L->size = L->size + 1;
	}
/*
 * void insertAtBack(ListHndl L, long data)
 * Pre:
 * Post: !isEmpty(), doesn't change current element.
 *
 * Inserts new element after last.
 */
void insertAtBack(ListHndl L, long data)
	{
	Node node;

	node = newNode();
	node->data = data;
	if( isEmpty(L) == 1 )
		L->first = node;
	else
		{
		L->last->next = node;
		node->prev = L->last;
		}
	L->last = node;
	L->size = L->size + 1;
	}
/*
 * void insertBeforeCurrent(List Hndl L, long data)
 * Pre: !offEnd()
 * Post: !isEmpty(), !offEnd(), !atFirst()
 *
 * Inserts new element before current one.
 */
void insertBeforeCurrent(ListHndl L, long data)
	{
	Node node;

	node = newNode();
	node->data = data;

	node->next = L->current;
	L->current->prev->next = node;
	L->current->prev = node;
	}
/*
 * void deleteFirst(ListHndl L)
 * Pre: !isEmpty()
 * Post:
 *
 * Deletes first element.
 */
void deleteFirst(ListHndl L)
	{
	if(L->size == 1)
		L->last = NULL;
	L->first = L->first->next;
	L->first->prev = NULL;
	}
/*
 * void deleteLast(ListHndl L)
 * Pre: !isEmpty()
 * Post:
 *
 * Deletes last element.
 */
void deleteLast(ListHndl L)
	{
	if(L->size == 1 )
		L->first = NULL;
	L->last = L->last->prev;
	L->last->next = NULL;
	}
/*
 * void deleteCurrent(ListHndl L)
 * Pre: !isEmpty, !offEnd()
 * Post: offEnd()
 *
 * Deletes current element.
 */
void deleteCurrent(ListHndl L)
	{
	if(L->size == 1)
		makeEmpty(L);
	else if(atLast(L) == 1)
		{
		deleteLast(L);
		L->current = L->current->prev;
		}
	else if(atFirst(L) == 1)
		{
		deleteFirst(L);
		L->current = L->current->next;
		}
	else
		{
		L->current->prev->next = L->current->next;
		L->current->next->prev = L->current->prev;
		L->current = L->current->next;
		}


	}



/*** Other operations ***/


/*
 * Node newNode()
 *
 * Creates new node.
 */
Node newNode()
	{
	Node tempNode;

/*	if(freeListHolder == NULL)
		{*/
		tempNode = malloc( sizeof(NodeStruct) );
/*		}
	else
		{
		tempNode = freeListHolder;
		freeListHolder = freeListHolder->prev;
		}*/
	tempNode->data = -999;
	tempNode->prev = NULL;

	return(tempNode);
	}


/*
 * void freeNode(Node node)
 *
 * Frees the memory of a node.
 */
void freeNode(Node node)
	{
	node->data = -888;
/*	node->prev = freeListHolder;
	freeListHolder = node;*/
	}


/*
 * void freeFreeList()
 * Edited from intstack.c posted method.
 * Unused.
 *
 * Frees free list variable.
 */
void freeFreeList()
	{
	Node tempNode;

/*	while(freeListHolder != NULL)
		{
		tempNode = freeListHolder;
		freeListHolder = freeListHolder->prev;
		free(tempNode);
		}
*/	}






/* OTHER OPERATIONS */



/*
 * void printList(FILE* out, ListHndl L)
 * Pre:
 * Post:
 *
 * Prints out the list with the current
 * element marked, helpful for debugging.
 */
void printList(FILE* out, ListHndl L)
	{
	Node tempNode;

	tempNode = L->first;

	while(tempNode != NULL)
		{
		printf("%*d ", 7, tempNode->data);
		tempNode = tempNode->next;
		}
	printf("\n");
	}




















