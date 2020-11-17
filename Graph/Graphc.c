#include "Graph.h"
#include "Queue.h"
#include <stdio.h>

typedef struct Graph
{
	int **matrix;
	int vertices;
} Graph;

Graph* makeGraph(const char* filename)
{
	Graph* newGraph = calloc(1, sizeof(Graph));
	FILE* input = fopen(filename, "r");
	if (input == NULL || newGraph == NULL) {
		return NULL;
	}
	int countVertices = 0;
	fscanf(input, "%i", &countVertices);
	newGraph->matrix = calloc(countVertices, sizeof(int*));
	for (int i = 0; i < countVertices; i++)
	{
		newGraph->matrix[i] = calloc(countVertices, sizeof(int));
		for (int j = 0; j < countVertices; j++)
		{
			fscanf(input, "%i", &(newGraph->matrix[i][j]));
		}
	}
	newGraph->vertices = countVertices;
	fclose(input);
	return newGraph;
}

void printGraph(const Graph* graph)
{
	const int size = graph->vertices;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			/*if (graph->matrix[i][j] == 1) {
				printf("%i -- %i\n", i, j);
			}*/
			printf("%i ", graph->matrix[i][j]);
		}
		printf("\n");
	}
}

void deleteGraph(Graph** graph)
{
	for (int i = 0; i < (*graph)->vertices; i++)
	{
		free((*graph)->matrix[i]);
	}
	free((*graph)->matrix);
	free(*graph);
	*graph = NULL;
}

Queue* bfs(Graph* graph, int start)
{
	Queue* queue = initQueue();
	Queue* pathQueue = initQueue();
	enqueue(queue, start);
	bool* used = calloc(graph->vertices, sizeof(bool));
	while (!empty(queue))
	{
		int v = dequeue(queue);
		if (used[v]) {
			continue;
		}
		used[v] = true;
		enqueue(pathQueue, v);
		for (int j = 0; j < graph->vertices; j++)
		{
			if (graph->matrix[v][j] == 1 && !used[j])
			{
				enqueue(queue, j);
			}
		}
	}
	free(used);
	deleteQueue(&queue);
	return pathQueue;
}

void dfsRecursive(Graph* graph, int current, bool *used, Queue *pathQueue)
{
	int v = current;
	if (used[v]) {
		return;
	}
	used[v] = true;
	enqueue(pathQueue, v);
	for (int j = 0; j < graph->vertices; j++)
	{
		if (graph->matrix[v][j] == 1 && !used[j])
		{
			dfsRecursive(graph, j, used, pathQueue);
		}
	}
}

Queue* dfs(Graph* graph, int start)
{
	bool* used = calloc(graph->vertices, sizeof(bool));
	Queue* pathQueue = initQueue();
	dfsRecursive(graph, start, used, pathQueue);
	free(used);
	return pathQueue;
}
