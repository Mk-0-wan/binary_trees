#include "binary_trees.h"

/**
 * ht- measures the height of the binary_trees
 * @tree: pointer to the root node of the tree
 * Return: height of the node
 */
size_t ht(const binary_tree_t *tree)
{
	if (tree == NULL || tree->parent == NULL)
		return (-1);


	return (1 + ht(tree->parent));
}
