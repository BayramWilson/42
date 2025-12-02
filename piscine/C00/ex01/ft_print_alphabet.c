/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 04:19:21 by bwilson           #+#    #+#             */
/*   Updated: 2025/10/24 04:23:52 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	start;
	char	end;

	start = 'a';
	end = 'z';
	while (start <= end)
	{
		write(1, &start, 1);
		start++;
	}
}
/*
int	main(void)
{
	ft_print_alphabet();
}
*/