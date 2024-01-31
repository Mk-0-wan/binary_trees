#include "binary_trees.h"

/**
 * binary_tree_is_leaf - function that checks if a binary tree node is a leaf
 * @node: pointer to the node to checks
 * Return: 1 if node is a leaf, 0 if its not a leaf
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->left && !node->right)
		return (1);
	return (0);
}
