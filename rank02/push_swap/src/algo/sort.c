/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:56:42 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 15:06:40 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_3(t_stack **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x < y && y < z)
		return ;
	else if (x > y && y < z && x < z)
		sa(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x > z)
		rra(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
}

static void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	min_index;
	int	size;
	int	i;

	size = get_stack_size(*a);
	min_index = find_min_index(*a);
	if (min_index <= size / 2)
	{
		i = 0;
		while (i < min_index)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		i = size - min_index;
		while (i > 0)
		{
			rra(a);
			i--;
		}
	}
	pb(a, b);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int		size;

	size = get_stack_size(*a);
	if (size == 4)
	{
		push_min_to_b(a, b);
		sort_3(a);
		pa(a, b);
	}
	else if (size == 5)
	{
		push_min_to_b(a, b);
		push_min_to_b(a, b);
		sort_3(a);
		pa(a, b);
		pa(a, b);
	}
}
