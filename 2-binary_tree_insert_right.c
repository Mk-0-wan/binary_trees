#include "binary_trees.h"

/**
 * binary_tree_insert_right - a binary tree that insert node as
 * the right-child of another node
 * @parent: pointer to the node to insert the right-child
 * @value: insert value to insert to a new node
 * Return: pointer to the inserted node in the tree, NULL either
 * parent is NULL or NULL during node creation
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{

	binary_tree_t *new_right_child = binary_tree_node(parent, value);

	if (!parent || !new_right_child)
		return (NULL);

	if (parent->right)
	{
		new_right_child->right = parent->right;
		parent->right->parent = new_right_child;
	}
	parent->right = new_right_child;

	return (new_right_child);
}
