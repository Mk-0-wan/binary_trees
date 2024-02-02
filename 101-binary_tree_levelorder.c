#include "binary_trees.h"

size_t tree_height(binary_tree_t *root);
void modded_preorder(const binary_tree_t *root,
		void (*func)(int), size_t level);

/**
 * tree_height - calculates the height of the tree_height
 * @root: root node pointer of the binary_tree
 * Return: height of the tree, 0 otherwise
 */
size_t tree_height(binary_tree_t *root)
{
	size_t l_h = 0, r_h = 0;

	if (!root)
		return (0);

	l_h = tree_height(root->left);
	r_h = tree_height(root->right);

	if (l_h > r_h)
		return (l_h + 1);
	else
		return (r_h + 1);

	return (0);
}

/**
 * modded_preorder - going through the node using pre-order traversal
 * @root: pointer to the root node
 * @func: a function pointer to call each node
 * @level: limits printing only to the current level
 * Return: Fail if tree or func is null, otherwise printtree
 */
void modded_preorder(const binary_tree_t *root,
		void (*func)(int), size_t level)
{
	if (!root || !func)
		return;

	if (level == 1)
	{
		func(root->n);
	}
	else if (level > 1)
	{
		modded_preorder(root->left, func, level - 1);
		modded_preorder(root->right, func, level - 1);
	}
}

/**
 * binary_tree_levelorder - function that goes through the tree in a
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: function that calls the value of each node it passes through
 * the tree. Value of the node must be passed as a parameter to the func
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = 0, i = 1;

	if (!tree || !func)
		return;

	height = tree_height((binary_tree_t *)tree);

	for (; i <= height; i++)
		modded_preorder(tree, func, i);
}
