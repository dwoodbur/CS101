# Makefile
#

#heapDriver : heapDriver.o heap.o
#	gcc -ansi -Wall -Wextra -pedantic -o heapDriver heapDriver.o heap.o

GCC = gcc -g -Wall -Wextra -std=gnu99

OBJECTS = sortComp.o sortPrint.o heapDriver.o heapSort.o insertionSort.o heap.o

all: sortComp sortPrint heapDriver

sortComp : sortComp.o heapSort.o insertionSort.o heap.o
	${GCC} -o sortComp sortComp.o heapSort.o insertionSort.o heap.o

sortPrint : sortPrint.o heapSort.o insertionSort.o heap.o
	${GCC} -o sortPrint sortPrint.o heapSort.o insertionSort.o heap.o

heapDriver : heapDriver.o heap.o
	${GCC} -o heapDriver heapDriver.o heap.o

sortComp.o : sortComp.c insertionSort.h heapSort.h
	${GCC} -c sortComp.c

sortPrint.o : sortPrint.c insertionSort.h heapSort.h
	${GCC} -c sortPrint.c

heapDriver.o : heapDriver.c heap.h
	${GCC} -c heapDriver.c

heapSort.o : heapSort.c heapSort.h heap.c heap.h
	${GCC} -c heapSort.c

insertionSort.o : insertionSort.c insertionSort.h
	${GCC} -c insertionSort.c

heap.o : heap.c heap.h
	${GCC} -c heap.c

clean :
	rm ${OBJECTS}
