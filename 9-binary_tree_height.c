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

	return (max(lsubtree, rsubtree));
}
