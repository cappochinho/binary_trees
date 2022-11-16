#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: pointer to the created node or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_child = NULL;
	left_child = malloc(sizeof(binary_tree_t));
	left_child->n = value;
	left_child->left = NULL;
	left_child->right = NULL;

	if (parent == NULL || left_child == NULL)
		return (NULL);

	binary_tree_t *new_parent = parent;

	if (new_parent->left == NULL)
		new_parent->left = left_child;
	else
	{
		binary_tree_t *old_left_child = new_parent->left;
		new_parent->left = left_child;
		new_parent->left->left = old_left_child;
	}

	new_parent = new_parent->left;

	if (new_parent == NULL)
		return (NULL);

	return (new_parent);
}
