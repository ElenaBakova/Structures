#include "Queue.h"
#include "Graph.h"
#include <stdio.h>

int main()
{
	Graph* graph = makeGraph("input.txt");
	printGraph(graph);
	Queue* queue = bfs(graph, 0);
	while (!empty(queue))
	{
		printf("%i ", dequeue(queue) + 1);
	}
	printf("\n");
	Queue* dfsQueue = dfs(graph, 0);
	while (!empty(dfsQueue))
	{
		printf("%i ", dequeue(dfsQueue) + 1);
	}
	deleteQueue(&queue);
	deleteQueue(&dfsQueue);
	deleteGraph(&graph);

	return 0;
}