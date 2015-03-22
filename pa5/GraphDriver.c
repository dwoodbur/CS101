#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

void addEdgesTest(Graph G)
	{
	addEdge(G, 1, 2);
	addEdge(G, 1, 3);
	addEdge(G, 2, 3);
	addEdge(G, 2, 4);
	addEdge(G, 3, 1);
	addEdge(G, 3, 2);
	addEdge(G, 4, 2);
	addEdge(G, 4, 5);
	addEdge(G, 5, 1);
	addEdge(G, 5, 2);
	addEdge(G, 5, 4);
	addEdge(G, 5, 6);
	addEdge(G, 6, 1);
	addEdge(G, 6, 2);
	addEdge(G, 6, 3);
	}
void printGraphTest(Graph G)
	{
	printf("GRAPH:\n");
	printGraph(G);
	}
void getAdjListTest(Graph G, int v)
	{
	List adjList = getAdjacencyList(G, v);
	printf("ADJACENCY LIST: ");
	printList(adjList);
	}
void distanceTest(Graph G, int v)
	{
	printf("DISTANCE: %d\n", getDistance(G, v));
	}
void pathTest(Graph G, int v)
	{
	List path = getPathTo(G, v);
	printf("PATH: ");
	printList(path);
	freeList(path);
	}
int main(int argc, char* argv[])
	{
	printf("Creating new graph of size 7...\n");
	Graph G = newGraph(7);
	printf("Adding edges to graph...\n");
	addEdgesTest(G);
	printf("Printing graph...\n");
	printGraphTest(G);

	printf("Getting adjacency list for vertex 1...\n");
	getAdjListTest(G, 1);
	printf("Getting adjacency list for vertex 0 (empty)...\n");
	getAdjListTest(G, 0);

	printf("Running BFS on graph with source of 1...\n");
	doBFS(G, 1);

	printf("Getting distance from source to 6...\n");
	distanceTest(G, 6);
	printf("Getting distance from source to 0...\n");
	distanceTest(G, 0);

	printf("Getting path from source to 6...\n");
	pathTest(G, 6);
	printf("Getting path from source to 0...\n");
	pathTest(G, 0);

	printf("Freeing graph...\n");
	freeGraph(G);
	}
