/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:19:15 by bwilson           #+#    #+#             */
/*   Updated: 2026/01/26 14:52:56 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	parse_error(t_stack **a, char **tokens)
{
	if (tokens)
		free_inputs(tokens);
	free_t_stack(a);
	write(2, "Error\n", 6);
	return (0);
}
