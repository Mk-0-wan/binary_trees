#include "binary_trees.h"

binary_tree_t *find_ancestor_recursive(
		const binary_tree_t *first, const binary_tree_t *second);
size_t find_depth(const binary_tree_t *node);
/**
 * find_depth - Calculate the depth of a node in a binary tree.
 * @node: Pointer to the node.
 * Return: Depth of the node.
 */
size_t find_depth(const binary_tree_t *node)
{
	size_t depth = 0;

	if (!node || !node->parent)
		return (0);

	depth = find_depth(node->parent);
	depth++;

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
	size_t depth_first = 0, depth_second = 0;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	depth_first = find_depth(first);
	depth_second = find_depth(second);

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
	if (!first || !second)
		return (NULL);

	return (find_ancestor_recursive(first, second));
}
