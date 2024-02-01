#include "binary_trees.h"

/**
 * h_of_rsbtree - function that calculates the height of the right
 * subtree
 * @root: pointer of the first node in the tree
 * Return: height of the lsubtree, otherwise 0 if fails
 */
size_t h_of_rsbtree(const binary_tree_t *root)
{
	size_t l = 0, r = 0;

	if (root == NULL)
		return (0);

	l = h_of_rsbtree(root->left);
	r = h_of_rsbtree(root->right);

	return (1 + max(l, r));
}
/**
 * h_of_lsubtree - function that calculates the height of the left subtree
 * @root: pointer of the first node in the tree
 * Return: height of the lsubtree, otherwise 0 if fails
 */
size_t h_of_lsubtree(const binary_tree_t *root)
{
	size_t l = 0, r = 0;

	if (root == NULL)
		return (0);

	l = h_of_lsubtree(root->left);
	r = h_of_lsubtree(root->right);

	return (1 + max(l, r));
}
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

	lsubtree = h_of_lsubtree(tree->left);
	rsubtree = h_of_rsbtree(tree->right);

	return (lsubtree - rsubtree);
}
