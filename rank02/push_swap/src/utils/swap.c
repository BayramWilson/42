/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:19:53 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 14:52:49 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_stack **head)
{
	t_stack	*tmp;

	if (!head || !*head || !((*head)->next))
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	sa(t_stack **head)
{
	swap(head);
	write(1, "sa\n", 3);
}

void	sb(t_stack **head)
{
	swap(head);
	write(1, "sb\n", 3);
}

void	ss(t_stack **t_stack_a, t_stack **t_stack_b)
{
	swap(t_stack_a);
	swap(t_stack_b);
	write(1, "ss\n", 3);
}

// int main(void)
// {
//     t_stack *a;
//     t_stack *b;

//     a = NULL;
//     b = NULL;

//     a = insert_ordered(a,1);
//     a = insert_ordered(a,2);
//     a = insert_ordered(a,3);
//     print_list(a);
//     swap(&a);
//     print_list(a);
// }