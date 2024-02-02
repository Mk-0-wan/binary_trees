#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs a
 * right-rotation on a binary_tree
 * @tree : pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the rotated node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left_child_node = NULL;

	if (!tree || !tree->left)
		return (NULL);

	left_child_node = tree->left;
	tree->left = left_child_node->right;

	if (left_child_node->right)
		left_child_node->right->parent = tree;

	left_child_node->right = tree;
	left_child_node->parent = tree->parent;
	tree->parent = left_child_node;

	if (left_child_node->parent)
	{
		if (left_child_node->parent->left == tree)
			left_child_node->parent->left = left_child_node;
		else
			left_child_node->parent->right = left_child_node;
	}
	return (left_child_node);
}
