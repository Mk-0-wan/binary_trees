#include "binary_trees.h"

/**
 * binary_tree_depth - measures the height of the binary_trees
 * @tree: pointer to the root node of the tree
 * Return: height of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dp = 0;

	if (tree == NULL || tree->parent == NULL)
		return (0);

	dp = binary_tree_depth(tree->parent);
	dp++;

	return (dp);
}
