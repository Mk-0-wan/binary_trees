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

	if (tree->left)
	{
		/*Adding one due to the root node pointer  aka tree->left */
		lsubtree +=  1 + binary_tree_height(tree->left);
	}
	if (tree->right)
	{
		/*Adding one due to the root node pointer  aka tree->right */
		rsubtree +=  1 + binary_tree_height(tree->right);
	}

	/*Adding one due to the root node pointer  aka tree */
	return (fmax(lsubtree, rsubtree) + 1);
}
