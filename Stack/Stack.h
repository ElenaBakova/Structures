#pragma once
#include <stdbool.h>

typedef struct Stack Stack;

Stack* createStack(void);

int pop(Stack* stack);

void push(Stack* stack, int value);

bool isEmpty(Stack* stack);

void freeStack(Stack** stack);
