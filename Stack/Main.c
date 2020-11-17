#include "Stack.h"
#include <stdio.h>

int main()
{
	struct Stack* stack = createStack();
	push(stack, 45);
	push(stack, 2425);
	push(stack, 55);
	push(stack, 13);
	while (!isEmpty(stack))
	{
		printf("%i\n", pop(stack));
	}
	freeStack(&stack);

	return 0;
}