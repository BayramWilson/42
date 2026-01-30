/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:14:59 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 14:52:56 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	free_inputs(char **inputs)
{
	int	i;

	if (inputs == NULL)
		return ;
	i = 0;
	while (inputs[i] != NULL)
	{
		free(inputs[i]);
		i++;
	}
	free(inputs);
}

char	**handle_input(char *argv)
{
	char	**inputs;

	if (argv == NULL || argv[0] == '\0')
		return (NULL);
	inputs = ft_split(argv, ' ');
	if (inputs == NULL)
		return (NULL);
	if (inputs[0] == NULL)
	{
		free_inputs(inputs);
		return (NULL);
	}
	return (inputs);
}

int	is_int(const char *argv)
{
	int	i;

	if (argv == NULL)
		return (0);
	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (!argv[i])
		return (0);
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

// int	is_double(char **argv)
// {
// 	int	i;
// 	int	j;
// 	int	len;

// 	i = 0;
// 	len = count_arg(argv);
// 	while (argv[i])
// 		i++;
// 	len = i;
// 	i = 0;
// 	while (i < len)
// 	{
// 		j = i + 1;
// 		while (j < len)
// 		{
// 			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
// 				return (1);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	parse_input(int argc, char **argv, t_stack **a)
{
	int		i;
	int		j;
	int		value;
	char	**tokens;

	i = 1;
	while (i < argc)
	{
		tokens = handle_input(argv[i]);
		if (!tokens)
			return (parse_error(a, NULL));
		j = 0;
		while (tokens[j])
		{
			if (!is_int(tokens[j]) || !safe_atoi(tokens[j], &value)
				|| contains_value(*a, value))
				return (parse_error(a, tokens));
			*a = insert_at_end(*a, value);
			j++;
		}
		free_inputs(tokens);
		i++;
	}
	return (1);
}
