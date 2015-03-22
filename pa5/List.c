/* List.c
 *
 * Note: Used on Assignment 4, but written by self.
 *
 * Contains:
 * 	typedef ListNodeStruct ListNode
 *	struct ListNodeStruct
 *		int data
 *		ListNode next
 *	ListNode newListNode()
 *	struct ListStruct
 *		int length
 *		Node first
 *		Node last
 *		Node current
 *	List newList()
 *	int getLength(List list)
 *	int getCurrent(List list)
 *	void moveFirst(List list)
 *	void moveNext(List list)
 *	void append(List list, int data)
 *	void printList(List list)
 *
 * Purpose:
 * 	Defines the data and functions for an
 * 	integer ADT.
 *
 * Author:
 * 	Dylan Woodbury
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"

/* Node Information */

typedef struct ListNodeStruct *ListNode;
/* struct NodeStruct
 * Defines the Node struct.
 */
typedef struct ListNodeStruct
	{
	int data;
	ListNode next;
	} ListNodeStruct;
/* Node newLibraryNode()
 * Builds and returns a new node.
 */
ListNode newListNode()
	{
	ListNode tempNode;
	tempNode = malloc( sizeof(ListNodeStruct) );
	tempNode->next = NULL;

	return (tempNode);
	}

/* List Information */
/* struct ListStruct
 * Defines the List struct.
 */
typedef struct ListStruct
	{
	int length;
	ListNode first;
	ListNode last;
	ListNode current;
	} ListStruct;
/* LibraryList newLibraryList()
 * Defines and returns a new List.
 */
List newList()
	{
	List tempList;
	tempList = malloc( sizeof(ListStruct) );
	tempList->length = 0;
	tempList->first = NULL;
	tempList->last = NULL;
	tempList->current = NULL;

	return (tempList);
	}

void freeList(List list)
	{
	int i;
	ListNode start = list->first;
	ListNode node = NULL;
	for(i=0; i < list->length; i++)
		{
		node = start->next;
		free(start);
		start = node;
		}
	free(list);
	}

/* Access Functions */

/* int getLibraryLength(LibraryList libList)
 * Returns the length of the list.
 */
int getLength(List list)
	{
	return list->length;
	}
/* int getCurrentLibrary(LibraryList libList)
 * Returns the current library.
 */
int getCurrent(List list)
	{
	if(list->current == NULL)
		return -1;
	return(list->current->data);
	}

int getSizeOfList()
	{
	return( sizeof(ListStruct) );
	}

/* Manipulation Functions */

/* void moveFirstLibrary(LibraryList libList)
 * Moves the current library to the 
 * first library.
 */
void moveFirst(List list)
	{
	/*assert(libList->length != 0);*/
	list->current = list->first;
	}
/* void moveNextLibrary(LibraryList libList)
 * Moves the current library to the
 * next library.
 */
void moveNext(List list)
	{
	list->current = list->current->next;
	}
/* void insertLibrary(LibraryList libList, int data)
 * Inserts the library into the back of
 * the list.
 */
void append(List list, int data)
	{
	ListNode node;
	node = newListNode();
	node->data = data;
	if(getLength(list) == 0)
		list->first = node;
	else
		list->last->next = node;
	list->last = node;
	list->length++;
	}

void prepend(List list, int data)
	{
	ListNode node;
	node = newListNode();
	node->data = data;
	if(getLength(list) == 0)
		list->last = node;
	else
		node->next = list->first;
	list->first = node;
	list->length++;
	}

void deleteFirst(List list)
	{
	ListNode node = list->first->next;
	free(list->first);
	list->first = node;
	list->length--;
	}

void empty(List list)
	{
	list->first = NULL;
	list->last = NULL;
	list->current = NULL;
	list->length = 0;
	}

/* Display Functions */

/* void printLibraryList(LibraryList libList)
 * Prints the list of libraries.
 */
void printList(List list)
	{
	int i; /* counting variable */
	moveFirst(list);
	for(i=0; i < getLength(list); i++)
		{
		printf("%d", getCurrent(list));
		if(i != getLength(list)-1)
			{
			printf(", ");
			moveNext(list);
			}
		}
	printf(".\n");
	}
