#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with atleast 1 child
 * @tree: pointer to the root node of the binary tree
 * Return: count of nodes, 0 failure
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t lsub_tree = 0, rsub_tree = 0;

	if (!tree)
		return (0);

	lsub_tree = binary_tree_nodes(tree->left);
	rsub_tree = binary_tree_nodes(tree->right);

	return (lsub_tree + rsub_tree + (tree->left || tree->right));
}
