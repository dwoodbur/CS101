/* LibraryList.h
 *
 * Purpose:
 * 	Header file for LibraryList ADT.
 * 	See .c file for contents.
 *
 * Author:
 * 	Dylan Woodbury
 */

#include <stdio.h>

/* Defines LibraryList off of ListStruct. */
typedef struct ListStruct* LibraryList;
/* Defines NodePtr off of NodeStruct. */
typedef struct NodeStruct* NodePtr;

/* Constructors */

/* LibraryList newLibraryList()
 * Returns new LibraryList.
 * Pre: n/a
 * Post: n/a
 */
LibraryList newLibraryList();

/* Access Functions */

/* int getCurrentLibrary(LibraryList libList)
 * Returns the current library.
 * Pre: current != null
 * Post: n/a
 */
int getCurrentLibrary(LibraryList libList);
/* int getLibraryLength(LibraryList libList)
 * Returns the length of the list.
 * Pre: n/a
 * Post: n/a
 */
int getLibraryLength(LibraryList libList);

/* Manipulation Functions */

/* void moveFirstLibrary(LibraryList libList)
 * Move current to the first library.
 * Pre: libList != empty
 * Post: n/a
 */
void moveFirstLibrary(LibraryList libList);
/* void MoveNextLibrary(LibraryList libList)
 * Moves current to the next library.
 * Pre: current != null
 * Post: n/a
 */
void moveNextLibrary(LibraryList libList);
/* void insertLibrary(LibraryList libList, int data)
 * Inserts a library into a certain list.
 * Pre: n/a
 * Post: n/a
 */
void insertLibrary(LibraryList libList, int data);

/* Display Functions */

/* void printLibraryList()
 * Prints the list of libraries.
 * Pre: n/a
 * Post: n/a
 */
void printLibraryList(LibraryList libList);
