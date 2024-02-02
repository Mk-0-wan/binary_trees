#include "binary_trees.h"
/**
 * binary_tree_nodes - how many nodes on a tree
 * @root: root node of tree
 * Return: number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *root)
{

	size_t nodes_right, nodes_left;

	if (root == NULL)
		return (0);

	nodes_left = binary_tree_nodes(root->left) + 1;
	nodes_right = binary_tree_nodes(root->right) + 1;
	return (nodes_right + nodes_left - 1);

}
/**
 * is_complete - is binary tree complete using index & num nodes
 * @root: root node
 * @index: index of node
 * @nodes: num of nodes
 * Return: 0 or 1
 */
int is_complete(const binary_tree_t *root, int index, int nodes)
{
	if (root == NULL)
		return (1);

	if (index >= nodes)
		return (0);

	return (is_complete(root->left, 2 * index + 1, nodes) &&
		is_complete(root->right, 2 * index + 2, nodes));
}
/**
 * binary_tree_is_complete - is binary tree complete (all to left)
 * @tree: root node
 * Return: 1 if true 0 if false
 *
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int index = 0;
	size_t nodes = binary_tree_nodes(tree);

	if (tree == NULL)
		return (0);

	return (is_complete(tree, index, (int)nodes));
}
