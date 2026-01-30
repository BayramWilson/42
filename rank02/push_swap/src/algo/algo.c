/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 19:48:06 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 15:05:39 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	leave_3_in(t_stack **a, t_stack **b)
{
	int	size;

	if (a == NULL || (*a) == NULL || b == NULL)
		return ;
	size = get_stack_size(*a);
	while (size > 3)
	{
		pb(a, b);
		size = size - 1;
	}
}

void	turk_sort(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	while (get_stack_size(*a) > 3)
		pb(a, b);
	sort_3(a);
	while (*b)
	{
		set_position(*a);
		set_position(*b);
		assign_target_pos(*a, *b);
		calculate_cost(*a, *b);
		cheapest = find_cheapest(*b);
		execute_move(a, b, cheapest->cost_a, cheapest->cost_b);
	}
	set_position(*a);
	final_rotate(a);
}

// int main(void)
// {
//     /* code */
//     t_stack *a;
//     t_stack *b;

//     a = NULL;
//     b = NULL;

//     a = insert_ordered(a, 1);
//     a = insert_ordered(a, 2);
//     a = insert_ordered(a, 3);
//     a = insert_ordered(a, 4);
//     a = insert_ordered(a, 5);
//     a = insert_ordered(a, 6);
//     a = insert_ordered(a, 7);
//     a = insert_ordered(a, 8);
//     a = insert_ordered(a, 9);
//     a = insert_ordered(a, 10);
//     a = insert_ordered(a, 130);
//     a = insert_ordered(a, 17);
//     a = insert_ordered(a, 165);
//     a = insert_ordered(a, 15);
//     a = insert_ordered(a, 55);
//     a = insert_ordered(a, 44);
//     a = insert_ordered(a, 99);
//     a = insert_ordered(a, 77);
//     a = insert_ordered(a, 88);
//     a = insert_ordered(a, 66);
//     print_list(a);
//     assign_index(a);
//     turk_sort(&a, &b);
//     print_list(a);
//     print_list(b);
//     free_t_stack(&a);
//     free_t_stack(&b);
//     return (0);
// }
