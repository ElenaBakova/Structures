#pragma once
#include <stdbool.h>

typedef struct StackElement {
	int value;
	struct StackElement* next;
} StackElement;

// Pushes new element
struct StackElement* push(StackElement* head, int value);

// Removes top elment from stack. Returns its value
int pop(StackElement** head);

// Returns top element value
int top(StackElement* head);

// Returns 'true' if stack is emty
bool isEmpty(StackElement* head);

// Removes all stack
void freeStack(StackElement** head);