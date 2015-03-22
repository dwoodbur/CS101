/* LibraryListDriver.c
 *
 * Purpose:
 * 	Driver program implementing the LibraryList ADT.
 *
 * Author:
 *	Dylan Woodbury
 */

#include <stdlib.h>
#include "LibraryList.h"

/* void printTest(LibraryList libList)
 * Prints the list.
 */
void printTest(LibraryList libList)
	{
	printf("List contents: ");
	printLibraryList(libList);
	}
/* void lengthTest(LibraryList libList)
 * Prints the length of the list.
 */
void lengthTest(LibraryList libList)
	{
	printf("Length of list: %d\n", getLibraryLength(libList));
	}
/* int main(int argc, char* argv[])
 * Runs the experiments implementing
 * LibraryList features.
 */
int main(int argc, char* argv[])
	{
	int i; /* counting variable */

	printf("INITIAL LIST TESTING\n");
	LibraryList libList = newLibraryList();
	lengthTest(libList);

	printf("\nINSERTING ELEMENT TESTING\n");
	insertLibrary(libList, 1);
	printTest(libList);
	lengthTest(libList);

	printf("\nINSERTING MULTIPLE ELEMENTS TESTING\n");
	for(i=2; i < 11; i++)
		insertLibrary(libList, i);
	printTest(libList);
	lengthTest(libList);
	}
