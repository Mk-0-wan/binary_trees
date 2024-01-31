#include "binary_trees.h"

/**
 * binary_tree_postorder - going through the node using pre-order traversal
 * @tree: pointer to the root node
 * @func: a function pointer to call each node
 * Return: Fail if tree or func is null, otherwise printtree
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
	/* During recursion root is changed to the current node */
}
