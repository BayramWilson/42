/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:19:58 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 14:52:56 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	reverse_rotate(t_stack **head)
{
	t_stack	*prev;
	t_stack	*last;

	if (!head || !*head || !((*head)->next))
		return ;
	prev = NULL;
	last = *head;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *head;
	*head = last;
}

void	rra(t_stack **head)
{
	reverse_rotate(head);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **head)
{
	reverse_rotate(head);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **list_a, t_stack **list_b)
{
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	write(1, "rrr\n", 4);
}
