#include "binary_trees.h"

/**
 * binary_tree_insert_left - a binary tree that insert node as
 * the left-child of another node
 * @parent: pointer to the node to insert the left-child
 * @value: insert value to insert to a new node
 * Return: pointer to the inserted node in the tree, NULL either
 * parent is NULL or NULL during node creation
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{

	binary_tree_t *new_left_child = binary_tree_node(parent, value);

	if (!parent || !new_left_child)
		return (NULL);

	if (parent)
	{
		if (parent->left)
		{
			new_left_child->left = parent->left;
			parent->left->parent = new_left_child;
			new_left_child->left = parent->left;
		}
		parent->left = new_left_child;
	}

	return (new_left_child);
}
