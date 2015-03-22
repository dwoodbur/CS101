/*
 * Graph.h
 * Graph ADT Header File
 * by Dylan Woodbury
 * Contains exported functions and types of the
 * Graph ADT.
 */
#include "List.h"

typedef struct GraphStruct *Graph;
typedef enum {white=0, grey=1, black=2} state;

Graph newGraph(int n);
void addEdge(Graph G, int from, int to);
void freeGraph(Graph G);
void doBFS(Graph G, int source);
int getDistance(Graph G, int destination);
List getPathTo(Graph G, int destination);
List getAdjacencyList(Graph G, int vertex);
void printGraph(Graph G);
