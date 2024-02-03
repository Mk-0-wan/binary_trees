#include "binary_trees.h"

/**
 * bst_insert - inserts a valud in a BST
 * @tree: double pointer to the root node of the BST
 * @value: value to store in the node to be inserted
 * Return: pointer the new node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr = *tree;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	while (curr)
	{
		if (curr->n == value)
			return (NULL);

		if (value < curr->n)
		{
			if (curr->left == NULL)
			{
				curr->left = (bst_t *)binary_tree_node(curr, value);
				return (curr->left);
			}
			curr = curr->left;
		}
		if (value > curr->n)
		{
			if (curr->right == NULL)
			{
				curr->right = (bst_t *)binary_tree_node(curr, value);
				return (curr->right);
			}
			curr = curr->right;
		}
	}
	return (NULL);
}
