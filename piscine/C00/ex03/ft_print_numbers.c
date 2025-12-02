/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 04:32:30 by bwilson           #+#    #+#             */
/*   Updated: 2025/10/24 04:32:36 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	char	start;
	char	end;

	start = '0';
	end = '9';
	while (start <= end)
	{
		write(1, &start, 1);
		start++;
	}
}
/*
int	main(void)
{
	ft_print_numbers();
	return (0);
}
*/
