#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that performs a
 * right-rotation on a binary_tree
 * @tree : pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the rotated node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right_child_node = NULL;

	if (!tree || !tree->right)
		return (NULL);

	right_child_node = tree->right;
	tree->right = right_child_node->left;

	if (right_child_node->left)
		right_child_node->left->parent = tree;

	right_child_node->left = tree;
	right_child_node->parent = tree->parent;
	tree->parent = right_child_node;

	if (right_child_node->parent)
	{
		if (right_child_node->parent->right == tree)
			right_child_node->parent->right = right_child_node;
		else
			right_child_node->parent->left = right_child_node;
	}
	return (right_child_node);
}
