/* BookLibraryDriver.c
 *
 * Purpose:
 * 	Driver program implementing the
 * 	BookLibraryList ADT.
 *
 * Author:
 * 	Dylan Woodbury
 */

#include <stdlib.h>
#include "BookLibraryList.h"

/* void printTest(List list)
 * Prints the contents of the list.
 */
void printTest(List list)
	{
	printf("List contents:\n");
	printList(list);
	}
/* void lengthTest(List list)
 * Prints the length of the list.
 */
void lengthTest(List list)
	{
	printf("Length of list: %d\n", getLength(list));
	}
/* void emptyTest(List list)
 * Prints whether the list is
 * empty or not.
 */
void emptyTest(List list)
	{
	printf("Is list empty: ");
	if(isEmpty(list) == true)
		printf("yes\n");
	else
		printf("no\n");
	}
/* int main(int argc, char* argv[])
 * Runs the experiments which test the
 * BookLibraryList ADT features.
 */
int main(int argc, char* argv[])
	{

	printf("INITIAL LIST TESTING\n");
	List list = newList();
	lengthTest(list);
	emptyTest(list);

	printf("\nINSERTING ELEMENT TESTING\n");
	insert(list, "To Kill A Mockingbird");
	insertLibraryToBook(list, "To Kill A Mockingbird", 72);
	printTest(list);
	lengthTest(list);
	emptyTest(list);

	printf("\nINSERTING MULTIPLE ELEMENTS TESTING\n");
	insert(list, "Walden");
	insertLibraryToBook(list, "Walden", 13);
	insertLibraryToBook(list, "Walden", 14567);
	insert(list, "Beowulf");
	insertLibraryToBook(list, "Beowulf", 937192);
	insertLibraryToBook(list, "Beowulf", 1039);
	insertLibraryToBook(list, "Beowulf", 3829);
	insertLibraryToBook(list, "Beowulf", 1492);
	insert(list, "Collected Stories of Flannery O'Connor");
	insert(list, "And Then There Were None");
	insertLibraryToBook(list, "And Then There Were None", 10);
	insertLibraryToBook(list, "And Then There Were None", 68);
	printTest(list);
	lengthTest(list);
	emptyTest(list);
	}
