#include "binary_trees.h"
#include <stdlib.h>

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
	binary_tree_t *new_left_child =  NULL;

	if (!parent)
		return (NULL);

	new_left_child = malloc(sizeof(binary_tree_t));
	if (!new_left_child)
		return (NULL);

	new_left_child->left = NULL;
	new_left_child->right = NULL;
	new_left_child->parent = parent;
	new_left_child->n = value;

	if (parent->left)
	{
		new_left_child->left = parent->left;
		parent->left->parent = new_left_child;
	}
	parent->left = new_left_child;

	return (new_left_child);
}
