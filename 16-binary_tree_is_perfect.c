#include "binary_trees.h"

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * Return: 1 if true, 0 if false
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int ht = 0, nodes = 0;

	if (!tree)
		return (0);

	ht = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	/* No.nodes = 2^h + 1 */
	return (pow(2, ht + 1) - 1 == nodes);
}
