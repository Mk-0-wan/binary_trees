#include "binary_trees.h"

/**
 * binary_tree_preorder - going through the node using pre-order traversal
 * @tree: pointer to the root node
 * @func: a function pointer to call each node
 * Return: Fail if tree or func is null, otherwise printtree
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
	/* During recursion root is changed to the current node */
}
