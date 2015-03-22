/*
 * store.c
 * Author: Dylan Woodbury (dwoodbur)
 *
 * Gets a file from the user and inputs the IDs of purchases
 * of a given number of customers. The IDs are put in ascending
 * order, by customer, and the results can be displayed
 * back to the user.
 */

#include <stdlib.h>
#include <stdio.h>
#include "List.c"

/*
 * main()
 *
 * Runs the store purchase/customer history procedures (see class description).
 */
int main(int argc, char* argv[])
	{
	int i, numCustomers=0, numPurchases=0, custID, purchID;
	char filename[100];
	FILE *file;

	printf("Enter data file name:\n");
	scanf("%s", filename);

	/* Inputs basic data */
	file = fopen(filename, "r");
	fscanf(file, "%d", &numCustomers);
	fscanf(file, "%d", &numPurchases);

	/* Set up array of lists */
	ListHndl custArray[numCustomers];
	for(i=0; i < numCustomers; i++)
		{
		custArray[i] = newList();
		}

	/* Fills up lists by customer, in order */
	for(i=0; i < numPurchases; i++)
		{
		fscanf(file, "%d%d", &custID, &purchID);
		ListHndl list = custArray[custID-1];
		if(isEmpty(list) == 1)
			insertAtBack(list, purchID);
		else if(getLast(list) <= purchID)
			insertAtBack(list, purchID);
		else if(getFirst(list) >= purchID)
			insertAtFront(list, purchID);
		else
			{
			moveFirst(list);
			while(getCurrent(list) < purchID)
				moveNext(list);
			insertBeforeCurrent(list, purchID);
			}
		}

	/* Output lists of customer purchases */
	printf("customer#   books purchased\n");
	for(i=0; i < numCustomers; i++)
		{
		printf("%d", i+1);
		printList(stdout, custArray[i]);
		}

	fclose(file);

	return 0;
	}
