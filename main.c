/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szona <szona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:49:37 by szona             #+#    #+#             */
/*   Updated: 2021/03/20 21:14:49 by szona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//-----------------------LIBRARY--------------------------

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

//-----------------------STRUCTS--------------------------

typedef struct  discharges
{
	int					value;
	struct discharges	*next;
} dis_t;

typedef struct  discharges_tree
{
	char					*value;
	struct discharges_tree	*left;
	struct discharges_tree	*right;
} dis_tree_t;

//--------------------DECLARATIONS------------------------

dis_t		*new_list_node(int value);
dis_t		*parse_digit(char *str);
int			add_list_tail(dis_t *head, dis_t *new_node);
void		print_list(dis_t *head);
dis_tree_t	*new_tree_node(char *value);

//--------------------------------------------------------

int	main(int argc, char **argv)
{
	dis_t	*head;

//------------------------TEST---------------------------
	
	head = parse_digit("1234");
	print_list(head);

//-------------------------------------------------------
}

//------------------------LIST----------------------------

dis_t	*new_list_node(int value)
{
	dis_t	*node;

	node = NULL;
	node = (dis_t*)malloc(sizeof(dis_t*));
	if (node == NULL)
	{
		write(2, "Can't create list-node.", 23);
		return (node);
	}
	node->next = NULL;
	node->value = value;
	return (node);
}

int		add_list_tail(dis_t *head, dis_t *new_node)
{
	dis_t	*copy;

	copy = head;
	while (copy->next != NULL)
		copy = copy->next;
	copy->next = new_node;
	return (0);
}

void	print_list(dis_t *head)
{
	dis_t	*copy;

	copy = head;
	while (copy != NULL)
	{
		printf("%d\n", copy->value);
		copy = copy->next;
	}
}

//-----------------------PARSE---------------------------

dis_t	*parse_digit(char *str)
{
	int		i;
	int		digit;
	int		count;
	dis_t	*p_digit;

	i = 0;
	while (str[i] != '\0')
		i++;
	p_digit = new_list_node(str[i - 1] - '0');
	count = 10;
	i--;
	while (i > 0)
	{
		digit = (str[i - 1] - '0') * count;
		add_list_tail(p_digit, new_list_node(digit));
		count *= 10;
		i--;
	}
	return (p_digit);
}

//------------------------TREE-------------------------

dis_tree_t	*new_tree_node(char *value)
{
	dis_tree_t	*tree;

	tree = NULL;
	tree = (dis_tree_t*)malloc(sizeof(dis_tree_t));
	if (tree == NULL)
	{
		write(2, "Can't create tree-node.", 23);
		return (tree);
	}
	tree->left = NULL;
	tree->right = NULL;
	tree->value = value;
}

int	add_tree_tail(dis_tree_t *tree_head, dis_tree_t *tree_node)
{
	if ()
	return (0);
}