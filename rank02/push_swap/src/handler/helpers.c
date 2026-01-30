/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:20:16 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 14:52:56 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	overflow_next(long acc, int digit, long limit)
{
	if (acc > limit / 10 || (acc == limit / 10 && digit > limit % 10))
		return (1);
	return (0);
}

int	parse_sign(const char *s, int *i, int *sign, long *limit)
{
	if (s[*i] == '-')
	{
		*sign = -1;
		*limit = 2147483648;
		(*i)++;
	}
	if (s[*i] == '+')
		(*i)++;
	if (s[*i] == '\0')
		return (0);
	return (1);
}

int	safe_atoi(const char *s, int *out)
{
	long	acc;
	long	limit;
	int		sign;
	int		i;
	int		digit;

	i = 0;
	acc = 0;
	sign = 1;
	limit = 2147483647;
	if (!s || !out)
		return (0);
	if (!parse_sign(s, &i, &sign, &limit))
		return (0);
	while (s[i])
	{
		digit = s[i] - '0';
		if (overflow_next(acc, digit, limit))
			return (0);
		acc = acc * 10 + digit;
		i++;
	}
	*out = (int)(sign * acc);
	return (1);
}

void	free_t_stack(t_stack **s)
{
	t_stack	*tmp;

	if (!s)
		return ;
	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
}

int	contains_value(t_stack *a, int v)
{
	while (a)
	{
		if (a->value == v)
			return (1);
		a = a->next;
	}
	return (0);
}
