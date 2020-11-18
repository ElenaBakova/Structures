#include "Node.h"
#include <stdlib.h>
#include <ctype.h>

Node* createNode(Node* left, Node* right, int freq, char symbol)
{
	Node *newNode = malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->frequency = freq;
	newNode->symbol = symbol;
	newNode->left = left;
	newNode->right = right;
	return newNode;
}

Forest* createForest(char string[])
{
	int table[256] = { 0 };
	for (int i = 0; string[i] != '\0'; i++)
	{
		unsigned char charCode = (unsigned char)string[i];
		if (charCode >= 65 && charCode <= 90) {
			charCode += ' ';
		}
		if (charCode >= 97 && charCode <= 122) {
			table[charCode]++;
		}
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

Node* buildTree(Forest* forest)
{
	for (; forest->size > 1; forest->size--)
	{
		int min = 0;
		int minIdx = 0;
		int secondMin = 0;
		int seconndMinIdx = 0;
		if (forest->nodes[0]->frequency <= forest->nodes[1]->frequency)
		{
			min = forest->nodes[0]->frequency;
			secondMin = forest->nodes[1]->frequency;
			seconndMinIdx = 1;
		}
		else 
		{
			min = forest->nodes[1]->frequency;
			minIdx = 1;
			secondMin = forest->nodes[0]->frequency;
		}
		for (int i = 2; i < forest->size; i++)
		{
			if (forest->nodes[i]->frequency < min)
			{
				secondMin = min;
				seconndMinIdx = minIdx;
				min = forest->nodes[i]->frequency;
				minIdx = i;
			}
			else if (forest->nodes[i]->frequency < secondMin)
			{
				secondMin = forest->nodes[i]->frequency;
				seconndMinIdx = i;
			}
		}

		int freq = forest->nodes[minIdx]->frequency + forest->nodes[seconndMinIdx]->frequency;
		Node* newRoot = createNode(forest->nodes[minIdx], forest->nodes[seconndMinIdx], freq, '\0');
		if (newRoot == NULL) {
			return NULL;
		}
		forest->nodes[minIdx] = newRoot;
		for (int i = seconndMinIdx; i < forest->size - 1; i++) {
			forest->nodes[i] = forest->nodes[i + 1];
		}
	}
	return forest->nodes[0];
}