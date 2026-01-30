/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:37:01 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 15:00:12 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

// For each node: count how many values are smaller = its rank
void	assign_index(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*cmp;
	int		rank;

	cur = stack;
	while (cur)
	{
		rank = 0;
		cmp = stack;
		while (cmp)
		{
			if (cmp->value < cur->value)
				rank++;
			cmp = cmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}

// Find position in A where B element should be inserted
int	get_target_pos(t_stack *a, int b_index)
{
	t_stack	*tmp;
	int		target_idx;
	int		target_pos;

	target_idx = 2147483647;
	target_pos = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index > b_index && tmp->index < target_idx)
		{
			target_idx = tmp->index;
			target_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (target_idx == 2147483647)
		target_pos = find_min_index(a);
	return (target_pos);
}

void	calculate_cost(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	int		a_size;
	int		b_size;

	a_size = get_stack_size(a);
	b_size = get_stack_size(b);
	tmp = b;
	while (tmp)
	{
		tmp->cost_b = tmp->pos;
		if (tmp->pos > b_size / 2)
			tmp->cost_b = -(b_size - tmp->pos);
		tmp->cost_a = tmp->target_pos;
		if (tmp->target_pos > a_size / 2)
			tmp->cost_a = -(a_size - tmp->target_pos);
		tmp = tmp->next;
	}
}

// Returns pointer to B node with lowest total cost
t_stack	*find_cheapest(t_stack *b)
{
	t_stack	*cheapest;
	int		min_cost;
	int		cost;

	cheapest = b;
	min_cost = 2147483647;
	while (b)
	{
		cost = abs(b->cost_a) + abs(b->cost_b);
		if (cost < min_cost)
		{
			min_cost = cost;
			cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}
