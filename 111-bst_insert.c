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
	if (curr->n == value)
		return (NULL);


	if (!curr->right)
	{
		curr->right = (curr->n > value) ?
			bst_insert(&(curr->right), value) : NULL;
		return (curr->right);

	}
	if (!curr->left)
	{
		curr->left = ((curr)->n < value) ?
			bst_insert(&(curr->left), value) : NULL;
		return (curr->left);

	}
	return (NULL);
}
