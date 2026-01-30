/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:20:01 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 14:52:56 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/*
** push
**
** Moves the first element from the t_stack pointed to by `from`
** to the top of the t_stack pointed to by `to`.
**
** The operation removes the head node of the source t_stack,
** re-links it as the new head of the destination t_stack,
** and updates both t_stack pointers accordingly.
**
** If the source t_stack is empty, the function does nothing.
**
** Parameters:
**  - from: address of the source t_stack head pointer
**  - to:   address of the destination t_stack head pointer
*/
void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (!from || !to || *from == NULL)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
}

void	pa(t_stack **lista, t_stack **listb)
{
	push(listb, lista);
	write(1, "pa\n", 3);
}

void	pb(t_stack **lista, t_stack **listb)
{
	push(lista, listb);
	write(1, "pb\n", 3);
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
//     push(&a, &b);
//     print_list(a);
//     print_list(b);

// }
