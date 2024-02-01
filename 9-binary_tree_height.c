#include "binary_trees.h"
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

	/*Adding one due to the root node pointer  aka tree->left */
	lsubtree += (tree->left) ? binary_tree_height(tree->left) + 1 : 0;

	/*Adding one due to the root node pointer  aka tree->right */
	rsubtree += (tree->right) ? binary_tree_height(tree->right) + 1 : 0;

	/*Adding one due to the root node pointer  aka tree */
	return (fmax(lsubtree, rsubtree) + 1);
}
