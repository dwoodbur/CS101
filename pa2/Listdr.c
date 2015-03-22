/*
 * Listdr.c
 * Author: Dylan Woodbury (dwoodbur)
 *
 * Tests features of the List ADT made in List.c.
 */

#include <stdlib.h>
#include "List.c"


/*
 * Look at print statements for program description.
 */
int main(int argc, char* argv[])
	{
	int i;

	printf("* Creating list. *\n");
	ListHndl list = newList();

	if( isEmpty(list) )
		printf("\nThe list is empty.\n");
	else printf("\nThe list is not empty.\n");

	printf("\n* Adding element 123 to back of list. *\n");
	insertAtBack(list, 123);

	if( isEmpty(list) )
		printf("\nThe list is empty.\n");
	else printf("\nThe list is not empty.\n");

	printf("\n* Printing list... *\n\n");
	printList(stdout, list);

	printf("\n\n* Adding the element 45 to the front of the list. *\n");
	insertAtFront(list, 45);
	printf("* Adding the element 221 to the back of the list. *\n");
	insertAtBack(list, 221);
	printf("* Adding the element 12 to the front of the list. *\n");
	insertAtFront(list, 12);
	printf("* Printing the list (should be in order if correct). *\n\n");
	printList(stdout, list);

	printf("\n\n* Deleting first element *\n");
	deleteFirst(list);
	printf("* Deleting last element *\n");
	deleteLast(list);
	printf("* Printing list... *\n\n");
	printList(stdout, list);

	printf( "\n\n* First element: %d\n", getFirst(list) );
	printf( "* Last element: %d\n", getLast(list) );

	printf("* Making list empty. *\n");
	makeEmpty(list);
	if( isEmpty(list) )
		printf("The list is empty.\n");
	else printf("The list is not empty.\n");
	
	printf("\n* Adding numbers 1-10 to list. *\n");
	for(i=1; i <= 10; i++)
		insertAtBack(list, i);
	printList(stdout, list);

	printf("\n\n* Moving cursor to the last element. *\n");
	moveLast(list);
	printf("* Deleting cursor element. *\n");
	deleteCurrent(list);
	printList(stdout, list);
	printf("* Moving cursor to the first element. *\n");
	moveFirst(list);
	printf("* Deleting cursor element. *\n");
	deleteCurrent(list);
	printList(stdout, list);
	printf("* Deleting cursor element again. *\n");
	deleteCurrent(list);
	printList(stdout, list);

	printf("\n* Element at cursor: %d*\n", getCurrent(list) );
	printf("\n* Moving ahead 5 spaces, and back 1 *\n");
	for(i=0; i<5; i++)
		moveNext(list);
	movePrev(list);
	printf("* Deleting element (should be 7). *\n");
	deleteCurrent(list);
	printList(stdout, list);

	printf("\n\n* Moving the cursor forward 2 elements (after the 9). *\n");
	for(i=0; i<2; i++)
		moveNext(list);
	printf("* Is the cursor off the list? : ");
	if(offEnd(list) == 1)
		printf("yes\n");
	else printf("no\n");

	printf("\n* Moving the cursor to the 8. *\n");
	moveLast(list);
	movePrev(list);
	printf("* Inserting a 7 before the cursor. *\n");
	insertBeforeCurrent(list, 7);
	printList(stdout, list);

	printf("\nEnd of Drive\n");
	return 0;
	} 
