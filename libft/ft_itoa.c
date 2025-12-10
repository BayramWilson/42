/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilson <bwilson@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:13:30 by bwilson           #+#    #+#             */
/*   Updated: 2025/12/10 20:11:37 by bwilson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_itoa(int n)
{
	long nb;
	int is_negative;
	size_t i;
	char *result;
	long temp;

	nb = (long)n;
	temp = nb;
	is_negative = 0;
	i = 1;
	if (nb < 0)
	{
		nb = nb * (-1);
		temp = temp * (-1);
		is_negative = 1;
		i++;
	}
	while ((temp / 10) > 0)
	{
		temp = temp / 10;
		i++;
	}
	result = malloc(i + 1);
	if (n == 0)
		result[0] = '0';
	result[i] = '\0';
	while (nb > 0)
	{
		result[i - 1] = '0' + (nb % 10);
		nb = nb / 10;
		i--;
	}
	if (is_negative)
		result[0] = '-';

	return (result);
}