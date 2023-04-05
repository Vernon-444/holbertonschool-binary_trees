#include "binary_trees.h"
#include <stddef.h>
#include <limits.h>

/**
 * is_bst_helper - Helper function to check if the tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 * @min: Minimum allowed value for the current node
 * @max: Maximum allowed value for the current node
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n - 1) &&
		is_bst_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}
