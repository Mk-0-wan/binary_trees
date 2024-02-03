#include "binary_trees.h"

/**
 * bst_insert - inserts a valud in a BST
 * @tree: double pointer to the root node of the BST
 * @value: value to store in the node to be inserted
 * Return: pointer the new node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!(*tree))
		return (binary_tree_node(NULL, value));
	if ((*tree)->n == value)
		return (NULL);

	(*tree)->right = ((*tree)->n > value) ?
		bst_insert(&((*tree)->right), value) : NULL;
	(*tree)->left = ((*tree)->n < value) ?
		bst_insert(&((*tree)->left), value) : NULL;

	return ((*tree));
}
