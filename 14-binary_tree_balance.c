#include "binary_trees.h"

/**
 * l_height - calculate the length of the nodes in the right subtree
 * @lsub_tree: pointer to the root of the right subtree
 * Return: number of nodes present int the subtree
 */
size_t l_height(binary_tree_t *lsub_tree)
{
	size_t ht = 0;

	while (lsub_tree)
	{
		ht++;
		lsub_tree = lsub_tree->left;
	}
	return (ht);
}
/**
 * r_height - calculate the length of the nodes in the right subtree
 * @rsub_tree: pointer to the root of the right subtree
 * Return: number of nodes present int the subtree
 */
size_t r_height(binary_tree_t *rsub_tree)
{
	size_t ht = 0;

	while (rsub_tree)
	{
		ht++;
		rsub_tree = rsub_tree->right;
	}
	return (ht);
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

	lsubtree = l_height(tree->left);
	rsubtree = r_height(tree->right);

	return (lsubtree - rsubtree);
}
