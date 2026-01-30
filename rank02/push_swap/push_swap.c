/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:20:07 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 17:34:43 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if (size == 3)
		sort_3(a);
	else if (size <= 5)
		sort_5(a, b);
	else
	{
		assign_index(*a);
		turk_sort(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!parse_input(argc, argv, &a))
		return (1);
	if (is_sorted(a))
		return (free_t_stack(&a), 0);
	sort_stack(&a, &b, get_stack_size(a));
	free_t_stack(&a);
	return (0);
}
