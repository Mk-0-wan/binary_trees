#include "binary_trees.h"

/**
 * height_of_rsubtree - function that calculates the height of the right
 * subtree
 * @root: pointer of the first node in the tree
 * Return: height of the lsubtree, otherwise 0 if fails
 */
size_t height_of_rsubtree(const binary_tree_t *root)
{
	size_t l = 0, r = 0;

	if (root == NULL)
		return (0);

	l = height_of_rsubtree(root->left);
	r = height_of_rsubtree(root->right);

	return (1 + max(l, r));
}
/**
 * height_of_lsubtree - function that calculates the height of the left subtree
 * @root: pointer of the first node in the tree
 * Return: height of the lsubtree, otherwise 0 if fails
 */
size_t height_of_lsubtree(const binary_tree_t *root)
{
	size_t l = 0, r = 0;

	if (root == NULL)
		return (0);

	l = height_of_lsubtree(root->left);
	r = height_of_lsubtree(root->right);

	return (1 + max(l, r));
}
