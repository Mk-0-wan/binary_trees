#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if binary_tree is full
 * @tree: pointer to the root node of the tree
 * Return: 1 true, 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int lsubtree = 0, rsubtree = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	lsubtree = binary_tree_is_full(tree->left) ? 1 : 0;
	rsubtree = binary_tree_is_full(tree->right) ? 1 : 0;

	return ((lsubtree && rsubtree));
}
