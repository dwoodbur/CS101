/* BookLibraryList.h
 *
 * Purpose:
 * 	Header file for BookLibraryList ADT.
 * 	Contents listed in .c file.
 *
 * Author:
 * 	Dylan Woodbury
 */

#include <stdio.h>
/* Defines List off ListStruct. */
typedef struct ListStruct* List;
/* Defines type bool of true/false domain. */
typedef enum {false=0, true=1} bool;


/* Constructors */

/* List newList()
 * Returns new list.
 * Pre: n/a
 * Post: n/a
 */
List newList();

/* Access Functions */

/* int sizeOfListStruct()
 * Returns the size of the struct.
 * Pre: n/a
 * Post: n/a
 */
int sizeOfListStruct();
/* bool isEmpty(List list)
 * Returns true if the list is empty.
 * Pre: n/a (want method to run even if list is null)
 * Post: n/a
 */
bool isEmpty(List list);
/* char* getCurrentBook(List list)
 * Returns string book key.
 * Pre: n/a
 * Post: n/a
 */
char* getCurrentBook(List list);
/* int getLength(List list)
 * Returns the length of the list.
 * Pre: !isEmpty(list)
 * Post: n/a
 */
int getLength(List list);

/* Manipulation Functions */

/* void moveFirst(List list)
 * Moves current to the front.
 * Pre: n/a
 * Post: n/a
 */
void moveFirst(List list);
/* void moveNext(List list)
 * Moves current to the next node.
 * Pre: n/a (method accounts for if at last node)
 * Post: n/a
 */
void moveNext(List list);
/* void insert(List list, char* data)
 * Inserts book into the list.
 * Pre: n/a
 * Post: n/a
 */
void insert(List list, char* data);
/* bool insertLibraryToBook(List list, char* data, int library)
 * Inserts a library number into a book's 
 * list, and make a new node for the book 
 * if one does not exist.
 * Pre: n/a
 * Post: n/a
 */
bool insertLibraryToBook(List list, char* data, int library);

/* Display Functions */

/* void printList(List list)
 * Prints the list. Used for Driver.
 * Pre: n/a
 * Post: n/a
 */
void printList(List list);
/* int printSpecificList(List list, char *data)
 * Prints the list with the specific book title.
 * Pre: n/a
 * Post: n/a
 */
int printSpecificList(List list, char *data);
