/* findBooks.c
 *
 * Contains:
 * 	int main(int argc, char *argv[])
 *
 * This main program reads through the first input file
 * of library/book pairs and fills them into a hash table.
 * Then the program prints the list of libraries each book
 * in the second finput file belongs to.
 *
 * Author:
 * 	Dylan Woodbury
 */

#include <stdlib.h>
#include <stdio.h>
#include "HashTable.h"

/*
 * int main(int argc, char *argv[])
 *
 * Main program - see above description for
 * 	more detail.
 */
int main(int argc, char* argv[])
	{
	/*---DATA---*/

	int i=0; /*counter*/
	int lines=0;/*lines in file*/
	int space=0;/*space in hash table*/

	int libraryID=0;/*library number*/
	char book[40];/*title of book*/
	char ch;/*holds character during input*/

	FILE *libraryFile;/*library input file*/
	FILE *bookReqFile;/*request input file*/

	/*---END DATA---*/

	/* Part 1
 	 * Load a Hash Table with 
 	 * booklibrary pairs from 
 	 * the first input file. 
 	 */

	libraryFile = fopen(argv[1], "r");
	fscanf(libraryFile, "%d %d", &lines, &space);
	HashTable table = newHashTable(10);
	for(i=0; i < lines; i++)
		{
		fscanf(libraryFile, "%d%c %[^\n]%*c", &libraryID, &ch, book);
		insertHash(table, book, libraryID);
		}
	fclose(libraryFile);

	/* Part 2
 	 * Go through the second
 	 * input file and print
 	 * the books' list of
 	 * libraries.
 	 */

	bookReqFile = fopen(argv[2], "r");
	fscanf(bookReqFile, "%d\n", &lines);
	for(i=0; i < lines; i++)
		{
		fscanf(bookReqFile, "%[^\n]%*c", book);
		int success = printBookLibraryList(table, book);
		if(success == 0)
			printf("  (%s belongs to no library)\n", book);
		}
	}
