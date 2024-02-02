#include "binary_trees.h"

int depth_match(const binary_tree_t *root,
		int (*depth)(const binary_tree_t *));
int depth_from_lsubtree(const binary_tree_t *root);

/**
 * depth_from_lsubtree - function that checks for the depth of the left
 * subtree
 * @root: pointer to the root node of the binary tree
 * Return: the depth or sometimes called the max depth of the left subtree
 */
int depth_from_lsubtree(const binary_tree_t *root)
{
	return (root ? 1 + depth_from_lsubtree(root->left) : 0);
}

/**
 * depth_match - function that checks if the lsubtree depth is the
 * same as the rsubtree depth
 * @root: pointer to the root node in the tree
 * @depth: a function pointer to calculate the depth of a tree
 * Return: 1 if both depths match, 0 otherwise
 */
int depth_match(const binary_tree_t *root, int (*depth)(const binary_tree_t *))
{
	if (!root)
		return (1);

	int left_depth = depth(root->left);
	int right_depth = depth(root->right);

	return ((left_depth == right_depth) &&
		depth_match(root->left, depth) &&
		depth_match(root->right, depth));
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 * Return: 1 if true, 0 if false
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (depth_match(tree, depth_from_lsubtree));
}
