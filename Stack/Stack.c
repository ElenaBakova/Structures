#include "Stack.h"
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackElement {
	int value;
	struct StackElement* next;
}StackElement;

typedef struct Stack {
	struct StackElement* head;
}Stack;

Stack* createStack(void)
{
	return calloc(1, sizeof(Stack));
}

void push(Stack *stack, int value)
{
	StackElement *newElement = malloc(sizeof(StackElement));
	if (newElement == NULL)
	{
		return;
	}
	newElement->value = value;
	newElement->next = stack->head;
	stack->head = newElement;
}

int pop(Stack* stack)
{
	if (stack->head == NULL)
	{
		return 0;
	}
	int value = stack->head->value;
	StackElement *oldElement = stack->head;
	stack->head = stack->head->next;
	free(oldElement);
	return value;
}

bool isEmpty(Stack* stack)
{
	return stack->head == NULL;
}

void freeStack(Stack** stack)
{
	while (!isEmpty(*stack))
	{
		pop(*stack);
	}
	free(*stack);
	*stack = NULL;
}