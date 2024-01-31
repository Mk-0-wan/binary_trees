#include "binary_trees.h"

/**
 * binary_tree_delete - function that the entire binary_tree
 * @tree: pointer to the root of the binary tree
 * Return: do nothing if fail, nor succeed
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	free(tree);
	tree = NULL;
}
