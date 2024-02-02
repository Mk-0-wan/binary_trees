#include "binary_trees.h"

binary_tree_t *find_ancestor_recursive(
		const binary_tree_t *first, const binary_tree_t *second);
size_t binary_tree_depth(const binary_tree_t *node);
/**
 * binary_tree_depth - Calculate the depth of a node in a binary tree.
 * @node: Pointer to the node.
 * Return: Depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	while (node && node->parent)
	{
		depth++;
		node = node->parent;
	}

	return (depth);
}

/**
 * find_ancestor_recursive - Recursive helper function to find common ancestor.
 * @first: First node.
 * @second: Second node.
 * Return: Common ancestor node or NULL.
 */
binary_tree_t *find_ancestor_recursive(
		const binary_tree_t *first, const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	size_t depth_first = binary_tree_depth(first);
	size_t depth_second = binary_tree_depth(second);

	while (depth_first > depth_second)
	{
		first = first->parent;
		depth_first--;
	}

	while (depth_second > depth_first)
	{
		second = second->parent;
		depth_second--;
	}

	while (first && second && first != second)
	{
		first = first->parent;
		second = second->parent;
	}

	return ((binary_tree_t *)first);
}

/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to the lowest common ancestor or NULL if not found.
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *ancestor = NULL;

	if (!first || !second)
		return (NULL);

	ancestor = find_ancestor_recursive(first, second);

	return (ancestor);
}
