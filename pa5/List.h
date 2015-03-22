/* List.h
 *
 * Purpose:
 * 	Header file for List ADT.
 * 	See .c file for contents.
 *
 * Author:
 * 	Dylan Woodbury
 */

#include <stdio.h>

/* Defines LibraryList off of ListStruct. */
typedef struct ListStruct* List;
/* Defines NodePtr off of NodeStruct. */
typedef struct NodeStruct* NodePtr;

/* Constructors */

/* List newList()
 * Returns new LibraryList.
 * Pre: n/a
 * Post: n/a
 */
List newList();
/* void freeList()
 * Frees space allocated by the list, including
 * the list itself and its listnodes.
 */
void freeList();

/* Access Functions */

/* int getCurrentLibrary(LibraryList libList)
 * Returns the current library.
 * Pre: current != null
 * Post: n/a
 */

int getCurrent(List list);
/* int getLength(List list)
 * Returns the length of the list.
 * Pre: n/a
 * Post: n/a
 */
int getLength(List list);


int getSizeOfList();
/* Manipulation Functions */

/* void moveFirst(List list)
 * Move current to the first library.
 * Pre: list != empty
 * Post: n/a
 */
void moveFirst(List list);
/* void MoveNext(List list)
 * Moves current to the next library.
 * Pre: current != null
 * Post: n/a
 */
void moveNext(List list);
/* void append(List list, int data)
 * Inserts a library into a certain list.
 * Pre: n/a
 * Post: n/a
 */
void append(List list, int data);

void prepend(List list, int data);

void empty(List list);

/* Display Functions */

/* void printList()
 * Prints the list of libraries.
 * Pre: n/a
 * Post: n/a
 */
void deleteFirst(List list);
void printList(List list);
