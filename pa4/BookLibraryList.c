/* BookLibraryList.c
 *
 * Contains:
 * 	typdef struct NodeStruct *Node
 * 	struct NodeStruct
 * 		char *data
 * 		Node next
 * 		LibraryList libList
 * 	Node newNode(char *data)
 * 	struct ListStruct
 * 		int length
 * 		Node first
 * 		Node last
 * 		Node current
 * 	List newList()
 *	int sizeOfListStruct()
 *	int getLength(List list)
 *	bool isEmpty(List list)
 *	char* getCurrentBook(List list)
 *	void moveFirst(List list)
 *	void moveNext(List list)
 *	void insert(List list, char *data
 *	void insertLibraryToBook(List list, char* data, int library)
 *	void printSpecificList(List list, char* data)
 *	void printList(List list)
 *
 * Purpose:
 * 	This ADT defines the data and methods for a List holding a
 * 	string key and list of integers.
 *
 * Author:
 * 	Dylan Woodbury
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "BookLibraryList.h"
#include "LibraryList.h"

/* Node Information */

typedef struct NodeStruct *Node;

typedef struct NodeStruct
	{
	char *data;
	Node next;
	LibraryList libList;
	} NodeStruct;

Node newNode(char *data)
	{
	Node tempNode = malloc( sizeof(NodeStruct) );
	tempNode->data = strdup(data);
	tempNode->next = NULL;
	tempNode->libList = newLibraryList();

	return (tempNode);
	}

typedef struct ListStruct
	{
	int length;
	Node first;
	Node last;
	Node current;
	} ListStruct;

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


/*---ACCESS FUNCTIONS---*/

/* int sizeOfListStruct()
 * Returns size of the struct ListStruct.
 */
int sizeOfListStruct()
	{
	return(sizeof(ListStruct));
	}
/* int getLength(List list)
 * Returns the length of the list.
 */
int getLength(List list)
	{
	return list->length;
	}
/* bool isEmpty(List list)
 * Returns true if the list is empty.
 */
bool isEmpty(List list)
	{
	if(list->length == 0)
		return true;
	else
		return false;
	}
/* char* getCurrentBook(List list)
 * Returns the current node's key.
 */
char* getCurrentBook(List list)
	{
	assert(!isEmpty(list));
	return(list->current->data);
	}

/* Manipulation Functions */

/* void moveFirst(List list)
 * Move the current node to the beginning
 * of the list.
 */
void moveFirst(List list)
	{
	list->current = list->first;
	}
/* void mvoeNext(List list)
 * Move the cursor node to the next
 * position.
 */
void moveNext(List list)
	{
	list->current = list->current->next;
	}
/* void insert(List list, char *data)
 * Inserts a new node into the list.
 */
void insert(List list, char* data)
	{
	Node node;
	node = newNode(data);
	/*node->data = data;*/
	if(isEmpty(list))
		{
		list->first = node;
		list->last = node;
		}
	else
		{
		list->last->next = node;
		list->last = node;
		}
	list->length++;
	}
/* bool insertLibraryToBook(List list, char* data, int library)
 * Inserts a library into the correct book's list, or
 * if it's a new book, it will make a new node with that
 * book/library pair.
 */
bool insertLibraryToBook(List list, char* data, int library)
	{
	bool bookFound = false;
	int i;

	if(getLength(list) == 0)
		{
		insert(list, data);
		LibraryList libList = list->last->libList;
		insertLibrary(libList, library);
		bookFound = true;
		}
	moveFirst(list);

	for(i=0; i < getLength(list) && bookFound == false; i++)
		{
		if(strcmp(getCurrentBook(list),data) == 0)
			{
			Node node = list->current;
			LibraryList libList = node->libList;
			insertLibrary(libList, library);
			bookFound = true;
			}
		else if(i == getLength(list)-1)
			{
			insert(list, data);
			LibraryList libList = list->last->libList;
			insertLibrary(libList, library);
			bookFound = true;
			}
		else
			moveNext(list);
		}
	return(bookFound);
	}

/* Display Functions */

/* int printSpecificList(List list, char *data)
 * Displays the correct list according to the key.
 */
int printSpecificList(List list, char *data)
	{
	bool bookFound = false;
	int i;
	moveFirst(list);
	for(i=0; i < getLength(list) && bookFound == false; i++)
		{
		if(strcmp(getCurrentBook(list),data) == 0)
			{
			Node node = list->current;
			LibraryList libList = node->libList;
			printLibraryList(libList);
			bookFound = true;
			}
		else if(i != getLength(list)-1)
			moveNext(list);
		}
	if(!bookFound)
		return 0;
	return 1;
	}
/* void printList(List list)
 * Displays the list, used for the Driver.
 */
void printList(List list)
	{
	int i; /* counting variable */
	moveFirst(list);
	for(i=0; i < getLength(list); i++)
		{
		printf("Book: %s\n", getCurrentBook(list));
		printf("Libraries: ");
		LibraryList libList = list->current->libList;
		printLibraryList(libList);
		moveNext(list);
		}
	printf("\n");
	}
