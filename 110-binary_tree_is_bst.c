#include "binary_trees.h"
/**
 * inorder - Perform an inorder traversal of a binary tree and
 * validate if it is a BST.
 * @root: Pointer to the root node of the binary tree.
 * @prev: Double pointer to the previously visited node during traversal.
 * @valid: Pointer to an integer flag indicating the validity of the BST.
 * Return: void
 */
void inorder(binary_tree_t *root, binary_tree_t **prev, int *valid);

void inorder(binary_tree_t *root, binary_tree_t **prev, int *valid)
{
	if (root)
	{
		inorder(root->left, prev, valid);

		if  (*prev && (*prev)->n >= root->n)
		{
			*valid = 0;
			return;
		}

		*prev = root;
		inorder(root->right, prev, valid);
	}
}
/**
 * binary_tree_is_bst -  function that checks if a binary tree
 * is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if true, otherwise 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int valid = 1;
	binary_tree_t *prev = NULL;

	if (!tree)
		return (0);

	inorder((binary_tree_t *)tree, &prev, &valid);

	return (valid);
}
