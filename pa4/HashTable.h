/* HashTable.h
 *
 * Purpose:
 * 	Header file for HashTable ADT.
 *	See .c file for contents.
 *
 * Author:
 *	Dylan Woodbury
 */

#include <stdlib.h>
#include <stdio.h>

/* Defines HashTable off of HashTableStruct. */
typedef struct HashTableStruct* HashTable;
/* HashTable newHashTable(int size)
 * Makes/returns a new HashTable.
 * Pre: n/a
 * Post: n/a
 */
HashTable newHashTable(int size);
/* unsigned long hash(char *str)
 * Returns the djb2 hash value associated
 * with a string; the algorithm was
 * taken from the website linked on
 * the assignment sheet.
 * Pre: n/a
 * Post: n/a
 */
unsigned long hash(char *str);
/* int getSizeOfTable(HashTable table)
 * Returns the size of the table.
 * Pre: n/a
 * Post: n/a
 */
int getSizeOfTable(HashTable table);
/* void insertHash(HashTable table, char *book, int library)
 * Inserts a book with an associated library
 * into the hash table.
 * Pre: n/a
 * Post: n/a
 */
void insertHash(HashTable table, char *book, int library);
/* int printBookLibraryList(HashTable table, char *data)
 * Prints the Library List for the book.
 * Pre: n/a
 * Post: n/a
 */
int printBookLibraryList(HashTable table, char *data);
/* void printHashTable(HashTable table, char *data)
 * Prints the hash table fully (used in the Driver).
 * Pre: n/a
 * Post: n/a
 */
void printHashTable(HashTable table);
