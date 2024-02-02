#include "binary_trees.h"

binary_tree_t *find_uncle_recursive(binary_tree_t *root);

/**
 * find_uncle_recursive - Recursive helper function to find sibling.
 * @root: Current node being checked.
 * Return: Sibling node or NULL.
 */
binary_tree_t *find_uncle_recursive(binary_tree_t *root)
{
	if (!root->parent)
		return (NULL);

	if (!root->parent->left || !root->parent->right)
		return (NULL);

	if (root->parent->left && root->parent->left == root)
		return (root->parent->right);

	if (root->parent->right && root->parent->right == root)
		return (root->parent->left);

	return (find_uncle_recursive(root->parent));
}
/**
 * binary_tree_uncle -  a function that finds the uncle of a node
 * @node: pointer to the node to find the sibling
 * Return: sibling of the node or NULL on failure
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	return (find_uncle_recursive(node->parent));
}
