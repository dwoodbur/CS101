/*
 * List.h
 * Author: Dylan Woodbury (dwoodbur)
 *
 * Header file for main List.c, defines/prototypes elements
 * for program use.
 */

#include <stdio.h>

typedef struct ListStruct* ListHndl;

typedef struct NodeStruct* NodePtr;

/* Constructors-Destructors */


ListHndl newStack();


void freeList(ListHndl *L);


/* Access Functions */


int isEmpty(ListHndl L);

int offEnd(ListHndl L);

int atFirst(ListHndl L);

int atLast(ListHndl L);

long getFirst(ListHndl L);

long getLast(ListHndl L);

long getCurrent(ListHndl L);


/* Manipulation Procedures */


void makeEmpty(ListHndl L);


void moveFirst(ListHndl L);


void moveLast(ListHndl L);


void movePrev(ListHndl L);


void moveNext(ListHndl L);


void insertAtFront(ListHndl L, long data);


void insertAtback(ListHndl L, long data);


void insertBeforeCurrent(ListHndl L, long data);


void delteFirst(ListHndl L);


void deleteLast(ListHndl L);


void deleteCurrent(ListHndl L);


/* Other Operations */

void printList(FILE* out, ListHndl L);
