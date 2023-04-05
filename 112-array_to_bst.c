#include "binary_trees.h"

/**
 * array_to_bst - converts an array into a binary search tree
 * @array: pointer to the first element of the array
 * @size: the number of elements in the array
 *
 * Return: pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}

	return (root);
}
