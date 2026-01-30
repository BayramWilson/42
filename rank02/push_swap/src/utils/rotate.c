/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:19:56 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 14:52:56 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rotate(t_stack **head)
{
	t_stack	*old_head;
	t_stack	*tail;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	tail = *head;
	old_head = *head;
	while (tail->next != NULL)
		tail = tail->next;
	*head = old_head->next;
	tail->next = old_head;
	old_head->next = NULL;
}

void	ra(t_stack **head)
{
	rotate(head);
	write(1, "ra\n", 3);
}

void	rb(t_stack **head)
{
	rotate(head);
	write(1, "rb\n", 3);
}

void	rr(t_stack **t_stack_a, t_stack **t_stack_b)
{
	rotate(t_stack_a);
	rotate(t_stack_b);
	write(1, "rr\n", 3);
}
// int main(void)
// {
//     t_stack *a;

//     a = NULL;
//     a = insert_ordered(a, 1);
//     a = insert_ordered(a, 2);
//     a = insert_ordered(a, 3);
//     a = insert_ordered(a, 4);
//     rotate(&a);
//     print_list(a);
//     /* code */
//     return (0);
// }
