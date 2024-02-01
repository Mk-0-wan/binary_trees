#include "binary_trees.h"
#include <stddef.h>

/**
 * height_of_rsubtree - function that calculates the height of the right
 * subtree
 * @root: pointer of the first node in the tree
 * Return: height of the lsubtree, otherwise 0 if fails
 */
size_t height_of_rsubtree(binary_tree_t *root)
{
	size_t ht = 0;

	if (root == NULL)
		return (0);

	while (root->right)
	{
		ht++;
		root = root->right;
	}
	return (ht);
}
/**
 * height_of_lsubtree - function that calculates the height of the left subtree
 * @root: pointer of the first node in the tree
 * Return: height of the lsubtree, otherwise 0 if fails
 */
size_t height_of_lsubtree(binary_tree_t *root)
{
	size_t ht = 0;

	if (root == NULL)
		return (0);

	while (root->left)
	{
		ht++;
		root = root->left;
	}
	return (ht);
}
/**
 * binary_tree_height - measures the height of the binary_trees
 * @tree: pointer to the root node of the tree
 * Return: height of the node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lsubtree = 0, rsubtree = 0;

	if (!tree)
		return (0);
	lsubtree = height_of_lsubtree(tree->left);
	rsubtree = height_of_rsubtree(tree->right);

	return (fmax(lsubtree, rsubtree) + 1);
}
