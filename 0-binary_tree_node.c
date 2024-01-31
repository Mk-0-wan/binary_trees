#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to parent node of the node to create
 * @value: value to put in the new node
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_tree_node = malloc(sizeof(binary_tree_t));
	/*TODO: check edge case on the parent node pointer*/

	if (!new_tree_node)
		return (NULL);

	new_tree_node->left = NULL;
	new_tree_node->right = NULL;
	new_tree_node->parent = parent;
	new_tree_node->n = value;

	return (new_tree_node);
}
