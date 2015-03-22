# Makefile
#

#heapDriver : heapDriver.o heap.o
#	gcc -ansi -Wall -Wextra -pedantic -o heapDriver heapDriver.o heap.o

GCC = gcc -g -Wall -Wextra -std=gnu99

OBJECTS = LibraryList.o BookLibraryList.o HashTable.o findBooks.o LibraryListDriver.o BookLibraryListDriver.o HashTableDriver.o

all: LibraryListDriver BookLibraryListDriver HashTableDriver findBooks

LibraryListDriver : LibraryListDriver.o LibraryList.o
	${GCC} -o LibraryListDriver LibraryListDriver.o LibraryList.o

BookLibraryListDriver : BookLibraryListDriver.o BookLibraryList.o LibraryList.o
	${GCC} -o BookLibraryListDriver BookLibraryListDriver.o BookLibraryList.o LibraryList.o

HashTableDriver : HashTableDriver.o HashTable.o LibraryList.o BookLibraryList.o
	${GCC} -o HashTableDriver HashTableDriver.o HashTable.o LibraryList.o BookLibraryList.o

findBooks : findBooks.o HashTable.o BookLibraryList.o LibraryList.o
	${GCC} -o findBooks findBooks.o HashTable.o BookLibraryList.o LibraryList.o

LibraryList.o : LibraryList.c LibraryList.h
	${GCC} -c LibraryList.c

BookLibraryList.o : BookLibraryList.c BookLibraryList.h LibraryList.h
	${GCC} -c BookLibraryList.c

HashTable.o : HashTable.c HashTable.h BookLibraryList.h LibraryList.h
	${GCC} -c HashTable.c

LibraryListDriver.o : LibraryListDriver.c LibraryList.h
	${GCC} -c LibraryListDriver.c

BookLibraryListDriver.o : BookLibraryListDriver.c BookLibraryList.h LibraryList.h
	${GCC} -c BookLibraryListDriver.c

HashTableDriver.o : HashTableDriver.c HashTable.h
	${GCC} -c HashTableDriver.c

findBooks.o : findBooks.c HashTable.h BookLibraryList.h LibraryList.h
	${GCC} -c findBooks.c

clean :
	rm ${OBJECTS}
