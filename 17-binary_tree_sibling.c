#include "binary_trees.h"

binary_tree_t *find_sibling_recursive(binary_tree_t *root, int value);

/**
 * find_sibling_recursive - Recursive helper function to find sibling.
 * @root: Current node being checked.
 * @value: Value to compare.
 * Return: Sibling node or NULL.
 */
binary_tree_t *find_sibling_recursive(binary_tree_t *root, int value)
{

	if (!root || !root->parent)
		return (NULL);

	if (root->parent->left->n == value)
		return (root->parent->right);

	if (root->parent->right->n == value)
		return (root->parent->left);

	return (find_sibling_recursive(root->parent, value));
}
/**
 * binary_tree_sibling -  a function that finds the sibling of a node
 * @node: pointer to the node to find the sibling
 * Return: sibling of the node or NULL on failure
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (find_sibling_recursive(node, node->n));
}
