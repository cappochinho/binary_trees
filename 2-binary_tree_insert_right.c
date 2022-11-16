#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: a pointer to the node created, or NULL on failure or parent == NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_parent = parent;

	if (parent == NULL)
		return (NULL);

	binary_tree_t *new_right = NULL;
	new_right->n = value;
	new_right->left = NULL;
	new_right->right = NULL;

	if (new_right == NULL)
		return (NULL);

	if (new_parent->right == NULL)
		new_parent->right = new_right;
	else
	{
		binary_tree_t *old_right = new_parent->right;
		new_parent->right = new_right;
		new_parent->right->right = old_right;
	}

	new_parent = new_parent->right;

	if (new_parent == NULL)
		return (NULL);

	return (new_parent);
}
