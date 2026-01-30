/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:20:23 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 14:52:56 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

struct t_stack	*create_node(int x, int index)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = x;
	new_node->index = index;
	new_node->pos = 0;
	new_node->next = NULL;
	return (new_node);
}

struct t_stack	*insert_at_front(t_stack *head, int x)
{
	t_stack	*new_node;

	new_node = create_node(x, 0);
	new_node->next = head;
	return (new_node);
}

struct t_stack	*insert_at_end(t_stack *head, int x)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = create_node(x, 0);
	if (!head)
		return (new_node);
	last = head;
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return (head);
}

void	print_list(t_stack *node)
{
	while (node != NULL)
	{
		ft_printf("%d ", node->value);
		node = node->next;
	}
	ft_printf("\n");
}

struct t_stack	*insert_ordered(t_stack *head, int x)
{
	if (head == NULL)
		return (insert_at_front(head, x));
	else
		return (insert_at_end(head, x));
	return (head);
}

// int main(void)
// {
//     t_stack *head;

//     head = NULL;

//     head = insert_ordered(head, 1);
//     head = insert_ordered(head, 200);
//     head = insert_ordered(head, 3);
//     head = insert_ordered(head, 4);

//     print_list(head);
// }
