#include "binary_trees.h"
#include <limits.h>
#include <math.h>

/**
 * left_hieght - calculate the length of the nodes in the right subtree
 * @lsub_tree: pointer to the root of the right subtree
 * Return: number of nodes present int the subtree
 */
size_t left_hieght(binary_tree_t *lsub_tree)
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
 * right_hieght - calculate the length of the nodes in the right subtree
 * @rsub_tree: pointer to the root of the right subtree
 * Return: number of nodes present int the subtree
 */
size_t right_hieght(binary_tree_t *rsub_tree)
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
 * tree_height - measures the height of the binary_trees
 * @tree: pointer to the root node of the tree
 * Return: height of the node
 */
size_t tree_height(const binary_tree_t *tree)
{
	size_t leftheight = 0, rightheight = 0;

	if (!tree)
		return (0);

	leftheight = left_hieght(tree->left);
	rightheight = right_hieght(tree->right);

	return (fmax(leftheight, rightheight) + 1);
}

/**
 * custom_height - measures the height of the binary_trees
 * @tree: pointer to the root node of the tree
 * Return: height of the node
 */
int custom_height(const binary_tree_t *tree)
{
	int lsub_tree = 0, rsub_tree = 0;

	if (!tree)
		return (0);

	lsub_tree += (tree->left) ? 1 + custom_height(tree->left) : 0;
	rsub_tree += (tree->right) ? 1 + custom_height(tree->right) : 0;

	return (1 + fmax(lsub_tree, rsub_tree));
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree
 * Return: balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return (left_height - right_height);
}
