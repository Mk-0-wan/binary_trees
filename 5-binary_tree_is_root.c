#include "binary_trees.h"

/**
 * binary_tree_is_root - function that checks if a node is a root
 * @node: pointer to the node to check
 * Return: 1 if node is root, 0 if false
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if ((node->left || node->right) && !node->parent)
		return (1);

	return (0);
}
