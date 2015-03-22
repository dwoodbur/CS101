/* Graph.c
 * ADT main file
 * by Dylan Woodbury
 * Contains definitions/manipulation procedures for
 * a graph ADT.
 */

#include <stdlib.h>
#include <stdio.h>
#include "Graph.h"



typedef struct GraphStruct
	{
	int size;
	List adjacencyList[100000];
	state color[100000];
	int distance[100000];
	int parent[100000];

	} GraphStruct;
/* Graph newGraph(int n)
 *
 * Builds a new graph, setting the size,
 * creating empty lists for each vertex,
 * setting each color to white, and setting
 * each distance to -1 (infinity).
 */
Graph newGraph(int n)
	{
	int v;

	Graph G = malloc( sizeof(GraphStruct) );
/*	G->color = malloc(sizeof(state)*n);
	G->distance = malloc(sizeof(int)*n);
	G->parent = malloc(sizeof(int)*n);
*/
	G->size = n;

	for(v=0; v < n; v++)
		{
/*		G->color[v] = malloc(sizeof(state));
		G->distance[v] = malloc(sizeof(int));
		G->parent = malloc(sizeof(int));
*/		G->adjacencyList[v] = newList();
		G->color[v] = white;
		G->distance[v] = -1;
		G->parent[v] = -1;
		}

	return G;
	}
/* void addEdge(Graph G, int from, int to)
 *
 * Adds an edge to the specified vertex list.
 */
void addEdge(Graph G, int from, int to)
	{
	append(G->adjacencyList[from], to);
	}
/* void freeGraph(Graph G)
 *
 *
 */
void freeGraph(Graph G)
	{
	int v;
	for(v=0; v < G->size; v++)
		{
		freeList(G->adjacencyList[v]);
		}
	free(G);
	}
/* void doBFS(Graph G, int source)
 *
 *
 */
void doBFS(Graph G, int source)
	{
	int i, u, v;

	for(v=0; v < G->size; v++)
		{
	//	empty(G->adjacencyList[v]);
		G->color[v] = white;
		G->distance[v] = -1;
		G->parent[v] = -1;
		}
	List queue = newList();
	append(queue, source);
	G->color[source] = grey;
	G->distance[source] = 0;
	G->parent[source] = -1;
	moveFirst(queue);
	while(getCurrent(queue) != -1)
		{
		u = getCurrent(queue);
		moveFirst(G->adjacencyList[u]);
		for(i=0; i < getLength(G->adjacencyList[u]); i++)
			{
			v = getCurrent(G->adjacencyList[u]);
			if(G->color[v] == white)
				{
				G->color[v] = grey;
				G->distance[v] = G->distance[u] + 1;
				G->parent[v] = u;
				append(queue, v);
				}
			if(i != getLength(G->adjacencyList[u])-1)
				moveNext(G->adjacencyList[u]);
			}
		moveNext(queue);
		G->color[u] = black;
		}
	freeList(queue);
	}
/* int getDistance(Graph G, int destination)
 *
 *
 */
int getDistance(Graph G, int destination)
	{
	return G->distance[destination];
	}
/* List getPathTo(Graph G, int destination)
 *
 *
 */
List getPathTo(Graph G, int destination)
	{
	int v = destination;
	List path = newList();

	if(G->distance[destination] == -1)
		return path;
	while(G->parent[v] != -1)
		{
		prepend(path, G->parent[v]);
		v = G->parent[v];
		//prepend(path, G->parent[v]);
		}
	append(path, destination);

	return path;
	}
/* List getAdjacencyList(Graph G, int vertex)
 * 
 * Returns the adjacency list for the
 * specified vertex.
 */
List getAdjacencyList(Graph G, int vertex)
	{
	List list = G->adjacencyList[vertex];

	return list;
	}
/* void printGraph(Graph G)
 *
 * Prints the graph, listing the adjacent
 * vertices each vertex directs to.
 */
void printGraph(Graph G)
	{
	int v;

	for(v=0; v < G->size; v++)
		{
		printf("%d) ", v);
		printList(G->adjacencyList[v]);
		}
	}
