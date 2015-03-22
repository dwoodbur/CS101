/* LibraryList.c
 *
 * Contains:
 * 	typedef NodeStruct Node
 *	struct NodeStruct
 *		int data
 *		Node next
 *	Node newLibraryNode()
 *	struct ListStruct
 *		int length
 *		Node first
 *		Node last
 *		Node current
 *	LibraryList newLibraryList()
 *	int getLibraryLength(LibraryList libList)
 *	int getCurrentLibrary(LibraryList libList)
 *	void moveFirstLibrary(LibraryList libList)
 *	void moveNextLibrary(LibraryList libList)
 *	void insertLibrary(LibraryList libList, int data)
 *	void printLibraryList(LibraryList libList)
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
#include "LibraryList.h"

/* Node Information */

typedef struct NodeStruct *Node;
/* struct NodeStruct
 * Defines the Node struct.
 */
typedef struct NodeStruct
	{
	int data;
	Node next;
	} NodeStruct;
/* Node newLibraryNode()
 * Builds and returns a new node.
 */
Node newLibraryNode()
	{
	Node tempNode;
	tempNode = malloc( sizeof(NodeStruct) );
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
	Node first;
	Node last;
	Node current;
	} ListStruct;
/* LibraryList newLibraryList()
 * Defines and returns a new List.
 */
LibraryList newLibraryList()
	{
	LibraryList tempList;
	tempList = malloc( sizeof(ListStruct) );
	tempList->length = 0;
	tempList->first = NULL;
	tempList->last = NULL;
	tempList->current = NULL;

	return (tempList);
	}

/* Access Functions */

/* int getLibraryLength(LibraryList libList)
 * Returns the length of the list.
 */
int getLibraryLength(LibraryList libList)
	{
	return libList->length;
	}
/* int getCurrentLibrary(LibraryList libList)
 * Returns the current library.
 */
int getCurrentLibrary(LibraryList libList)
	{
	return(libList->current->data);
	}

/* Manipulation Functions */

/* void moveFirstLibrary(LibraryList libList)
 * Moves the current library to the 
 * first library.
 */
void moveFirstLibrary(LibraryList libList)
	{
	/*assert(libList->length != 0);*/
	libList->current = libList->first;
	}
/* void moveNextLibrary(LibraryList libList)
 * Moves the current library to the
 * next library.
 */
void moveNextLibrary(LibraryList libList)
	{
	libList->current = libList->current->next;
	}
/* void insertLibrary(LibraryList libList, int data)
 * Inserts the library into the back of
 * the list.
 */
void insertLibrary(LibraryList libList, int data)
	{
	Node node;
	node = newLibraryNode();
	node->data = data;
	if(getLibraryLength(libList) == 0)
		{
		libList->first = node;
		libList->last = node;
		}
	else
		{
		libList->last->next = node;
		libList->last = node;
		}
	libList->length++;
	}

/* Display Functions */

/* void printLibraryList(LibraryList libList)
 * Prints the list of libraries.
 */
void printLibraryList(LibraryList libList)
	{
	int i; /* counting variable */
	moveFirstLibrary(libList);
	for(i=0; i < getLibraryLength(libList); i++)
		{
		printf("%d", getCurrentLibrary(libList));
		if(i != getLibraryLength(libList)-1)
			{
			printf(" ");
			moveNextLibrary(libList);
			}
		}
	printf("\n");
	}
