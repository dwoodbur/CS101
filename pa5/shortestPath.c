/*
 * shortestPath.c
 *
 * by Dylan Woodbury
 * 
 * Assignment #5
 * This program reads in a file describing a graph, and
 * then queries are input and run using the BFS algorithm
 * on the graph. The parent list is also read from start
 * to destination.
 */

#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"

int main(int argc, char* argv[])
	{
	int c, i, v;
	int numVerts;
	int numQueries;
	int vertex, adj;
	int from, to;

	List path=NULL;

	FILE *inputFile;

	inputFile = fopen(argv[1], "r");
	fscanf(inputFile, "%d %d", &numVerts, &numQueries);
	Graph G = newGraph(numVerts);

	for(v=0; v < numVerts; v++)
		{
		fscanf(inputFile, "%d", &vertex);
		c = getc(inputFile);
		if(c != '\n')
		do
			{
			fscanf(inputFile, "%d", &vertex);
			addEdge(G, v, vertex);
			c = getc(inputFile);
			} while(c != '\n');
		}

	for(i=0; i < numQueries; i++)
		{
		fscanf(inputFile, "%d %d", &from, &to);
		doBFS(G, from);
		if(getDistance(G, to) > 0)
			{
			printf("To get from %d to %d requires %d edges, follow the path ", from, to, getDistance(G, to));
			path = getPathTo(G, to);
			printList(path);
			}
		else
			printf("I am sorry, there is no way to get from %d to %d in this graph.", from, to);
		printf("\n");
		}

	fclose(inputFile);

	freeList(path);
	freeGraph(G);

	return 0;
	}
