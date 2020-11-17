#include "Queue.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct QueueElement 
{
	int value;
	struct QueueElement* next;
} QueueElement;

typedef struct Queue 
{
	struct QueueElement* head;
	struct QueueElement* tail;
} Queue;

bool isEmpty(Queue* queue)
{
	return queue->head == NULL || queue->tail == NULL;
}

void enqueue(Queue* queue, int value)
{
	QueueElement* newItem = malloc(sizeof(QueueElement));
	if (newItem == NULL)
	{
		return;
	}
	newItem->value = value;
	newItem->next = NULL;
	if (isEmpty(queue))
	{
		queue->head = newItem;
		queue->tail = newItem;
	}
	else
	{
		queue->tail->next = newItem;
		queue->tail = newItem;
	}
}

int dequeue(Queue* queue)
{
	if (queue->tail == NULL)
	{
		return 0;
	}
	int value = queue->head->value;
	QueueElement* oldHead = queue->head;
	queue->head = queue->head->next;
	if (isEmpty(queue))
	{
		queue->tail = NULL;
	}
	free(oldHead);
	return value;
}

void deleteQueue(Queue** queue)
{
	while (!isEmpty(*queue))
	{
		dequeue(*queue);
	}
	free(*queue);
	*queue = NULL;
}

Queue* initQueue(void)
{
	Queue* queue = malloc(sizeof(Queue));
	if (queue == NULL)
	{
		return NULL;
	}
	queue->head = NULL;
	queue->tail = NULL;
	return queue;
}