#include <stddef.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * inorder_successor - finds the inorder successor of a given node
 * @node: pointer to the node whose inorder successor is to be found
 *
 * Return: pointer to the inorder successor node
 */
bst_t *inorder_successor(bst_t *node)
{
	while (node->left)
		node = node->left;
	return (node);
}

/**
 * remove_node - removes a node from the BST
 * @root: pointer to the root node of the BST
 * @node: pointer to the node to remove
 *
 * Return: pointer to the new root node after removal
 */
bst_t *remove_node(bst_t *root, bst_t *node)
{
	bst_t *temp;

	if (!node->left)
	{
		temp = node->right;
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = temp;
			else
				node->parent->right = temp;
		}
		if (temp)
			temp->parent = node->parent;
		free(node);
		return (temp);
	}
	else if (!node->right)
	{
		temp = node->left;
		if (node->parent)
		{
			if (node->parent->left == node)
				node->parent->left = temp;
			else
				node->parent->right = temp;
		}
		if (temp)
			temp->parent = node->parent;
		free(node);
		return (temp);
	}
	else
	{
		temp = inorder_successor(node->right);
		node->n = temp->n;
		node->right = remove_node(node->right, temp);
	}
	return (root);
}

/**
 * bst_remove - removes a node with a value equal to value from the BST
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: the value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (!root)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
		root = remove_node(root, root);

	return (root);
}
