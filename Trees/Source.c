#include <stdio.h>
#include <stdlib.h>

typedef struct TreeElement {
	int value;
	struct TreeElement* left;
	struct TreeElement* right;
} TreeElement;

TreeElement* initNode(const int value)
{
	TreeElement* newNode = calloc(1, sizeof(TreeElement));
	if (newNode == NULL)
	{
		return NULL;
	}
	newNode->value = value;
	return newNode;
}

TreeElement* add(TreeElement *root, const int value)
{
	if (root == NULL)
	{
		return initNode(value);
	}
	if (value == root->value) {
		return root;
	}
	TreeElement* newNode = initNode(value);
	if (value > root->value)
	{
		if (root->right != NULL) {
			return add(root, value);
		}
		root->right = newNode;
	}
	if (value < root->value)
	{
		if (root->left != NULL) {
			return add(root, value);
		}
		root->left = newNode;
	}
	return root;
}

int main()
{
	TreeElement* root = NULL;
	root = add(root, 2);
	root = add(root, 1);
	root = add(root, 3);

	free(root);
	return 0;
}