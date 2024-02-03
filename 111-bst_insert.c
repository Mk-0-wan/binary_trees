#include "binary_trees.h"

/**
 * bst_insert - inserts a valud in a BST
 * @tree: double pointer to the root node of the BST
 * @value: value to store in the node to be inserted
 * Return: pointer the new node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *curr = (*tree);

	if (!(*tree))
		return (binary_tree_node(NULL, value));

	while (curr)
	{
		if (curr->n == value)
			return (NULL);

		if (curr->n > value)
		{
			if (!curr->left)
			{
				curr->left = (bst_t *)binary_tree_node(curr, value);
				return (curr->left);
			}
			curr = curr->left;
		}
		if (curr->n < value)
		{
			if (!curr->right)
			{
				curr->right = (bst_t *)binary_tree_node(curr, value);
				return (curr->right);
			}
			curr = curr->right;
		}
	}
	return (NULL);
}
