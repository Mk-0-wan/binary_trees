#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to root of the tree
 * Return: number of leaves, 0 if null root was provided
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	/* Add the left subtree leaf nodes to the right subtree leaf nodes*/
	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
