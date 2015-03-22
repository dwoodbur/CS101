/* HashTable.c
 *
 * Contains:
 * 	struct HashTableStruct
 * 	HashTable newHashTable(int size)
 * 	unsigned long hash(char *str)
 *	int getSizeOfTable(HashTable table)
 *	void insertHash(HashTable table, char* book, int library)
 *	void printBookLibraryList(HashTable, char* book)
 *	void printHashTable(HashTable table)
 *
 * Purpose:
 * 	Defines the HashTable ADT, its data and methods.
 *
 * Author:
 * 	Dylan Woodbury
 * 	Also received djb2 algorithm from site pointed to
 * 	in assignment prompt.
 */

#include <stdlib.h>
#include "HashTable.h"
#include "BookLibraryList.h"
#include "LibraryList.h"

/*
 * struct HashTableStruct
 * 	int size
 * 	List array
 * Holds data for a HashTable
 */
typedef struct HashTableStruct
	{
	int size;
	List array[100];
	} HashTableStruct;
/*
 * HashTable newHashTable(int size)
 *	Makes and returns a new HashTable.
 */
HashTable newHashTable(int size)
	{
	int i;
	HashTable tempHashTable;
	tempHashTable = malloc(sizeof(HashTableStruct));
	tempHashTable->size = size;
	/*tempHashTable->array = malloc(32 * size);*/ /* 32 is sizeof(LibraryListStruct) */
	for(i=0; i < size; i++)
		{
		tempHashTable->array[i] = malloc(sizeOfListStruct());
		}
	return (tempHashTable);
	}
/*
 * unsigned long hash(char *str)
 * 	djb2 hash algorithm, taken from
 * 		http://www.cse.yorku.ca/~oz/hash.html
 * 	as recommended from the prompt.
 */
unsigned long hash(char *str)
	{
	unsigned long hash = 5381;
	int c;

	while(c = *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

	return hash;
	}
/*
 * int getSizeOfTable(HashTable table)
 * 	Returns the size of the table.
 */
int getSizeOfTable(HashTable table)
	{
	return (table->size);
	}
/*
 * insertHash(HashTable table, char *book, int library)
 * 	Inserts a book/library combo into the HashTable.
 */
void insertHash(HashTable table, char *book, int library)
	{
	int h = hash(book)%table->size;
	bool b = insertLibraryToBook(table->array[h], book, library);
	}
/*
 * printBookLibraryList(HashTable table, char *book)
 *	Inserts a book/library into a list based on the hash.
 */
int printBookLibraryList(HashTable table, char *book)
	{
	int h = hash(book)%table->size;
	int success = printSpecificList(table->array[h], book);
	return success;
	}
/*
 * printHashTable(HashTable table)
 * 	Prints the HashTable by element.
 */
void printHashTable(HashTable table)
	{
	int i;

	for(i=0; i < table->size; i++)
		{
		printf("Hash: %d:\n", i);
		if(getLength(table->array[i]) == 0)
			printf("  none\n");
		printList(table->array[i]);
		}
	}
