
#include "binary_trees.h"

/**
 * find_min_value_node - Finds the node with the minimum value in a BST.
 * @node: Pointer to the root node of the BST.
 * Return: A pointer to the node with the minimum value.
 */
bst_t *find_min_value_node(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left)
		current = current->left;

	return (current);
}

/**
 * bst_remove - Removes a node with the specified value from a BST.
 * @root: Pointer to the root node of the BST.
 * @value: Value to remove from the tree.
 * Return: A pointer to the new root node of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			temp = root->right;

			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;

			free(root);
			return (temp);
		}

		temp = find_min_value_node(root->right);

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
