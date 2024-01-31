#include "binary_trees.h"

/**
 * binary_tree_inorder - inorder traversing in a binary_trees
 * @tree: pointer to the root node to traverse
 * @func: function pointer to call each node
 * Return: void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
	/* do not start at the root node */
}
