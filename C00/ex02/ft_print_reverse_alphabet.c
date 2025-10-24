/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 04:26:54 by bwilson           #+#    #+#             */
/*   Updated: 2025/10/24 04:26:55 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	start;
	char	end;

	start = 'z';
	end = 'a';
	while (start >= end)
	{
		write(1, &start, 1);
		start--;
	}
}
/*
int	main(void)
{
	ft_print_reverse_alphabet();
}
*/