#include "binary_trees.h"

/**
 * h_rsubtree - function that calculates the height of the right
 * subtree
 * @root: pointer of the first node in the tree
 * Return: height of the lsubtree, otherwise 0 if fails
 */
size_t h_rsubtree(const binary_tree_t *root)
{
	size_t l = 0, r = 0;

	if (root == NULL)
		return (0);

	l = h_rsubtree(root->left);
	r = h_rsubtree(root->right);

	return (1 + max(l, r));
}
/**
 * h_lsubtree - function that calculates the height of the left subtree
 * @root: pointer of the first node in the tree
 * Return: height of the lsubtree, otherwise 0 if fails
 */
size_t h_lsubtree(const binary_tree_t *root)
{
	size_t l = 0, r = 0;

	if (root == NULL)
		return (0);

	l = h_lsubtree(root->left);
	r = h_lsubtree(root->right);

	return (1 + max(l, r));
}

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

	if (!tree->parent)
		return (0);

	lsubtree = h_lsubtree(tree->left);
	rsubtree = h_rsubtree(tree->right);

	return ((lsubtree == rsubtree) ? 1 : 0);
}
