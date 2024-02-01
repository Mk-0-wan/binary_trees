#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lsubtree = 0, rsubtree = 0;

	if (!tree)
		return (0);

	lsubtree = height_of_lsubtree(tree->left);
	rsubtree = height_of_rsubtree(tree->right);

	return (lsubtree - rsubtree);
}
