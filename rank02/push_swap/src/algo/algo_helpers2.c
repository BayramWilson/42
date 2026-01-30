/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:04:48 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 15:06:01 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	set_position(t_stack *stack)
{
	int		i;
	t_stack	*cur;

	i = 0;
	cur = stack;
	while (cur)
	{
		cur->pos = i;
		i++;
		cur = cur->next;
	}
}

void	final_rotate(t_stack **a)
{
	int	min_pos;
	int	size;

	size = get_stack_size(*a);
	min_pos = find_min_index(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		while (min_pos++ < size)
			rra(a);
	}
}

void	assign_target_pos(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		a_size;

	a_size = get_stack_size(a);
	tmp = b;
	while (tmp)
	{
		tmp->target_pos = get_target_pos(a, tmp->index);
		tmp = tmp->next;
	}
}

void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	execute_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	rotate_both(a, b, &cost_a, &cost_b);
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
	pa(a, b);
}
