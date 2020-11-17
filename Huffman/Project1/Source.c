#include "Node.h"
#include <stdio.h>

typedef struct {
	int size; 
	Node** nodes;
} Forest;

Forest* createForest(char string[])
{
	int table[256] = { 0 };
	for (int i = 0; string[i] != '\0'; i++)
	{
		unsigned char charCode = (unsigned char)string[i];
		table[charCode]++;
	}

	int size = 0;
	for (int i = 0; i < 256; i++)
	{
		if (table[i] != 0) {
			size++;
		}
	}
	Forest* forest = calloc(1, sizeof(Forest));
	if (forest == NULL)
	{
		return NULL;
	}
	forest->size = size;
	forest->nodes = malloc(sizeof(Node*) * size);
	if (forest->nodes == NULL)
	{
		return NULL;
	}

	int index = 0;
	for (int i = 0; i < 256; i++)
	{
		if (table[i] != 0)
		{
			forest->nodes[index] = createNode(NULL, NULL, table[i], i);
			index++;
		}
	}
	return forest;
}

int main()
{
	char string[50] = "This is an example of Haffman tree";
	Forest* forest = createForest(string);

	for (int i = 0; i < forest->size; i++)
	{
		Node* node = forest->nodes[i];
		printf("%c - %i\n", node->symbol, node->frequency);
	}

	free(forest->nodes);
	free(forest);
	return 0;
}