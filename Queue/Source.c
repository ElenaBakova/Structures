#include "Queue.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
	Queue* queue = initQueue();
	if (queue == NULL)
	{
		return 0;
	}
	enqueue(queue, 5);
	enqueue(queue, 51);
	enqueue(queue, 5213);
	for (int i = 0; i < 10; i++)
	{
		printf("%i\n", dequeue(queue));
	}
	deleteQueue(&queue);

	return 0;
}