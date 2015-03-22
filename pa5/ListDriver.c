/* ListDriver.c
 *
 * Purpose:
 * 	Driver program implementing the List ADT.
 *
 * Author:
 *	Dylan Woodbury
 */

#include <stdlib.h>
#include "List.h"

/* void printTest(List list)
 * Prints the list.
 */
void printTest(List list)
	{
	printf("List contents: ");
	printList(list);
	}
/* void lengthTest(LibraryList libList)
 * Prints the length of the list.
 */
void lengthTest(List list)
	{
	printf("Length of list: %d\n", getLength(list));
	}
/* int main(int argc, char* argv[])
 * Runs the experiments implementing
 * LibraryList features.
 */
int main(int argc, char* argv[])
	{
	int i; /* counting variable */

	printf("INITIAL LIST TESTING\n");
	List list = newList();
	lengthTest(list);

	printf("\nINSERTING ELEMENT TESTING\n");
	append(list, 1);
	printTest(list);
	lengthTest(list);

	printf("\nINSERTING MULTIPLE ELEMENTS TESTING\n");
	for(i=2; i < 11; i++)
		append(list, i);
	printTest(list);
	lengthTest(list);

	freeList(list);
	}
