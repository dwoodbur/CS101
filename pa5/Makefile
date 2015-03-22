# Makefile
# by Dylan Woodbury

#heapDriver : heapDriver.o heap.o
#	gcc -ansi -Wall -Wextra -pedantic -o heapDriver heapDriver.o heap.o

GCC = gcc -g -Wall -Wextra -std=gnu99

OBJECTS = List.o ListDriver.o Graph.o GraphDriver.o shortestPath.o

all: ListDriver GraphDriver shortestPath

ListDriver : ListDriver.o List.o
	${GCC} -o ListDriver ListDriver.o List.o

List.o : List.c List.h
	${GCC} -c List.c

ListDriver.o : ListDriver.c List.h
	${GCC} -c ListDriver.c

GraphDriver : GraphDriver.o Graph.o List.o
	${GCC} -o GraphDriver GraphDriver.o Graph.o List.o

Graph.o : Graph.c Graph.h List.h
	${GCC} -c Graph.c

GraphDriver.o : GraphDriver.c Graph.h
	${GCC} -c GraphDriver.c

shortestPath : shortestPath.o Graph.o List.o
	${GCC} -o shortestPath shortestPath.o Graph.o List.o

shortestPath.o : shortestPath.c Graph.h List.h
	${GCC} -c shortestPath.c

clean :
	rm ${OBJECTS}
