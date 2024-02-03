
#include "binary_trees.h"

/**
 * find_min_value_node - Finds the node with the minimum value in a BST.
 * @node: Pointer to the root node of the BST.
 * Return: A pointer to the node with the minimum value.
 */
bst_t *find_min_value_node(bst_t *node)
{
	bst_t *current = node;

	while (current && current->left)
		current = current->left;

	return (current);
}

/**
 * bst_remove - Removes a node with the specified value from a BST.
 * @root: Pointer to the root node of the BST.
 * @value: Value to remove from the tree.
 * Return: A pointer to the new root node of the tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			temp = root->right;

			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;

			free(root);
			return (temp);
		}

		temp = find_min_value_node(root->right);

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	bst_t *tree;
	int array[] = {
		79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
		20, 22, 98, 1, 62, 95
	};
	size_t n = sizeof(array) / sizeof(array[0]);

	tree = array_to_bst(array, n);
	if (!tree)
		return (1);
	binary_tree_print(tree);

	tree = bst_remove(tree, 79);
	printf("Removed 79...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 21);
	printf("Removed 21...\n");
	binary_tree_print(tree);

	tree = bst_remove(tree, 68);
	printf("Removed 68...\n");
	binary_tree_print(tree);
	binary_tree_delete(tree);
	return (0);
}
