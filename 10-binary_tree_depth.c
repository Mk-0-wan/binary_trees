#include "binary_trees.h"

/**
 * binary_tree_depth - measures the height of the binary_trees
 * @tree: pointer to the root node of the tree
 * Return: height of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t leftheight = 0, rightheight = 0;

	if (!tree)
		return (0);

	leftheight = binary_tree_depth(tree->left);
	rightheight = binary_tree_depth(tree->right);

	return (max(leftheight, rightheight) + 1);
}
