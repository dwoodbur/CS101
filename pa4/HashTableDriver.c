/* HashTableDriver.c
 *
 * Purpose:
 * 	Fills the HashTable up with books
 * 	and libraries, and prints it.
 *
 * Author:
 * 	Dylan Woodbury
 */

#include <stdlib.h>
#include <stdio.h>
#include "HashTable.h"

/* int main(int argc, char* argv[])
 * Fills up HashTable and prints, testing
 * the HashTable ADT.
 */
int main(int argc, char* argv[])
	{
	char* book = "Harry Potter";
	HashTable table = newHashTable(8);
	printf("Size of table: %d\n", getSizeOfTable(table));
	insertHash(table, "Harry Potter", 200023);
	insertHash(table, "Ethics", 171238);
	insertHash(table, "Harry Potter", 483421);
	insertHash(table, "Ethics", 102934);
	insertHash(table, "Harry Potter", 12385);
	insertHash(table, "Holy Bible", 39429);
	insertHash(table, "The Lion, the Witch, and the Wardrobe", 203930);
	insertHash(table, "The Stand", 293094);
	insertHash(table, "Dummy's Guide to Cinematography", 292039);
	insertHash(table, "Biography of John Muir", 813020);
	insertHash(table, "Slaughterhouse Five", 120290);
	insertHash(table, "Zen and the Art of Motorcycle Maitenance", 938302);
	insertHash(table, "The Final Day of Socrates", 590294);
	insertHash(table, "C Programming of Java Programmers", 293049);
	insertHash(table, "Infinite Jest", 302934);

	printHashTable(table);
	}
