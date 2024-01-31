#include "binary_trees.h"

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
 * binary_tree_nodes - counts the nodes with atleast 1 child
 * @tree: pointer to the root node of the binary tree
 * Return: count of nodes, 0 failure
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t lsub_tree = 0, rsub_tree = 0;

	if (!tree)
		return (0);

	lsub_tree = left_hieght((binary_tree_t *)tree);
	rsub_tree = right_hieght((binary_tree_t *)tree);

	if (lsub_tree == rsub_tree)
		return ((1 << lsub_tree) - 1);

	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
