/*
** EPITECH PROJECT, 2018
** pool
** File description:
**        simple_btree.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "simple_btree.h"

bool_t btree_is_empty(tree_t tree)
{
	if (tree == NULL)
		return (FALSE);
	return (TRUE);
}

unsigned int btree_get_size (tree_t tree)
{
	if (tree) {
		return (btree_get_size(tree->left)
		+ btree_get_size(tree->right) + 1);
	}
	return (0);
}

unsigned int btree_get_depth(tree_t tree)
{
	unsigned int left;
	unsigned int right;

	if (tree == NULL)
		return (0);
	left = btree_get_depth(tree->left);
	right = btree_get_depth(tree->right);
	return (left > right ? left + 1 : right + 1);
}

bool_t btree_create_node(tree_t *node_ptr, double value)
{
	*node_ptr = malloc(sizeof(tree_t));
	if (*node_ptr == NULL)
		return (FALSE);
	(*node_ptr)->value = value;
	(*node_ptr)->left = NULL;
	(*node_ptr)->right = NULL;
	return (TRUE);
}

bool_t btree_delete(tree_t *root_ptr)
{
	if (!*root_ptr)
		return (FALSE);
	if (*root_ptr) {
		btree_delete(&(*root_ptr)->right);
		btree_delete(&(*root_ptr)->left);
		*root_ptr = NULL;
		free(root_ptr);
		return (TRUE);
	}
	return (FALSE);
}

double btree_get_max_value(tree_t tree)
{
	double	me = 0;
	double l = 0;
	double r = 0;

	if (tree == NULL){
		return (0);
	}
	me = tree->value;
	if (tree->left)
		l = btree_get_max_value(tree->left);
	if (tree->right)
		r = btree_get_max_value(tree->right);
	if (me >= l && me >= r)
		return (me);
	else if (l >= me && l >= r)
		return (l);
	else
		return (r);
}

double btree_get_min_value(tree_t tree)
{
	double	me = 0;
	double l = 0;
	double r = 0;

	if (tree == NULL)
		return (0);
	l = tree->value;
	r = tree->value;
	me = tree->value;
	if (tree->left)
		l = btree_get_min_value(tree->left);
	if (tree->right)
		r = btree_get_min_value(tree->right);
	if (me <= l && me <= r)
		return (me);
	else if (l <= me && l <= r)
		return (l);
	else
		return (r);
}
