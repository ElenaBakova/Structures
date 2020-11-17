#pragma once
#include <stdbool.h>

typedef struct Queue Queue;

// Returns 'true' if queue is empty
bool isEmpty(Queue* queue);

void enqueue(Queue* queue, int value);

int dequeue(Queue* queue);

void deleteQueue(Queue** queue);

Queue* initQueue(void);