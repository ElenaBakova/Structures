#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void preorder(Node *root, char *path, int length, char *table[256])
{
	if (root->symbol != '\0')
	{
		char* copy = calloc(strlen(path) + 1, sizeof(char));
		strcpy(copy, path);
		table[(unsigned)root->symbol] = copy;
		return;
	}
	path[length] = '0';
	path[length + 1] = '\0';
	preorder(root->left, path, length + 1, table);
	path[length] = '1';
	path[length + 1] = '\0';
	preorder(root->right, path, length + 1, table);

}

int main()
{
	char string[1000] = "Elena 3.(4 points) Prove that the entropy of a coin is maximum for a fair coin. Bakova";
	Forest* forest = createForest(string);

	for (int i = 0; i < forest->size; i++)
	{
		Node* node = forest->nodes[i];
		printf("%c - %i\n", node->symbol, node->frequency);
	}
	printf("-----------------------\n");
	Node *root = buildTree(forest);
	char* table[256] = { 0 };
	printf("%i\n", root->frequency);
	char path[256] = { 0 };
	preorder(root, path, 0, table);
	for (int i = 0; i < 256; i++)
	{
		if (table[i] != NULL)
		{
			printf("%c = %s\n", i, table[i]);
		}
	}

	free(forest->nodes);
	free(forest);
	return 0;
}