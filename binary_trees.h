#ifndef __BTREE__
#define __BTREE__
/* headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Macros */
#define max(a, b) ((a) > (b) ? (a) : (b))
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
        int n;
        struct binary_tree_s *parent;
        struct binary_tree_s *left;
        struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Dependent fucntions */
size_t binary_tree_height(const binary_tree_t *tree);
size_t height_of_rsubtree(const binary_tree_t *root);
size_t height_of_lsubtree(const binary_tree_t *root);

int depth_match(const binary_tree_t *root, int (*depth)(const binary_tree_t *));
int binary_tree_is_perfect(const binary_tree_t *tree);
int depth_from_lsubtree(const binary_tree_t *root);

/* fucntions */
size_t theight(const binary_tree_t *root);
void binary_tree_delete(binary_tree_t *tree);
void binary_tree_print(const binary_tree_t *);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
#endif
