#pragma once

typedef struct Node {
	int frequency;
	char symbol;
	struct Node* left;
	struct Node* right;
} Node;

typedef struct {
	int size;
	Node** nodes;
} Forest;

Forest* createForest(char string[]);

Node* createNode(Node* left, Node* right, int freq, char symbol);

Node* buildTree(Forest* forest);