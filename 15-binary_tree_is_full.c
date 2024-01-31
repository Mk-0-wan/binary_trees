#include "binary_trees.h"
/**
 * theight - another way to calculate the height of binary tree
 * using tenary operators
 * @root: pointer to the root of the node
 * Return: height of the binary tree
 */
size_t theight(const binary_tree_t *root)
{
	size_t r_side = 0, l_side = 0;

	if (!root)
		return (0);

	l_side += (root->left) ? 1 + theight(root->left) : 0;
	r_side += (root->right) ? 1 + theight(root->right) : 0;

	return (fmax(l_side, r_side) + 1);
}
/**
 * binary_tree_is_full - checks if binary_tree is full
 * @tree: pointer to the root node of the tree
 * Return: 1 true, 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int lsubtree = 0, rsubtree = 0;

	if (!tree || !tree->parent)
		return (0);

	lsubtree = theight(tree->left);
	rsubtree = theight(tree->right);

	return ((lsubtree == rsubtree) ? 1 : 0);
}
