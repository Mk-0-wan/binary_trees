#include "binary_trees.h"

/**
 * array_to_bst - builds a BST from an array
 * @array: points to the first element in the array
 * @size: number of elements in the array
 * Return: pointer to the root node of the created BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t iter = 0;

	for (; iter < size; iter++)
		bst_insert(&root, array[iter]);

	return (root);
}
